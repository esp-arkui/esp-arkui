#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "./kal.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct {
    TimerHandle_t timerHandle;
    KalTimerType type;
    KalTimerProc func;
    union sigval arg;
    unsigned int millisec;
    int isRunning;
} KalTimer;

static void KalTimerCallback(TimerHandle_t xTimer)
{
    KalTimer* kalTimer = (KalTimer*)pvTimerGetTimerID(xTimer);
    if (kalTimer->type == KAL_TIMER_ONCE) {
        kalTimer->isRunning = 0;
    }
    if (kalTimer->func) {
        kalTimer->func(kalTimer->arg);
    }
}

KalTimerId KalTimerCreate(KalTimerProc func, KalTimerType type, void* arg, unsigned int millisec)
{
    if (func == NULL || (type != KAL_TIMER_ONCE && type != KAL_TIMER_PERIODIC)) {
        return NULL;
    }

    KalTimer* kalTimer = (KalTimer*)malloc(sizeof(KalTimer));
    if (kalTimer == NULL) {
        return NULL;
    }

    kalTimer->func = func;
    kalTimer->arg.sival_ptr = arg;
    kalTimer->type = type;
    kalTimer->millisec = millisec;
    kalTimer->isRunning = 0;

    kalTimer->timerHandle = xTimerCreate(
        "KalTimer",
        pdMS_TO_TICKS(millisec),
        (type == KAL_TIMER_PERIODIC) ? pdTRUE : pdFALSE,
        kalTimer,
        KalTimerCallback);

    if (kalTimer->timerHandle == NULL) {
        free(kalTimer);
        return NULL;
    }

    return (KalTimerId)kalTimer;
}

KalErrCode KalTimerStart(KalTimerId timerId)
{
    if (timerId == NULL) {
        return KAL_ERR_PARA;
    }

    KalTimer* kalTimer = (KalTimer*)timerId;

    if (xTimerStart(kalTimer->timerHandle, 0) != pdPASS) {
        return KAL_ERR_INNER;
    }

    kalTimer->isRunning = 1;
    return KAL_OK;
}

KalErrCode KalTimerChange(KalTimerId timerId, unsigned int millisec)
{
    if (timerId == NULL) {
        return KAL_ERR_PARA;
    }

    KalTimer* kalTimer = (KalTimer*)timerId;

    kalTimer->millisec = millisec;

    if (kalTimer->isRunning) {
        if (xTimerChangePeriod(kalTimer->timerHandle, pdMS_TO_TICKS(millisec), 0) != pdPASS) {
            return KAL_ERR_INNER;
        }
    }

    return KAL_OK;
}

KalErrCode KalTimerStop(KalTimerId timerId)
{
    if (timerId == NULL) {
        return KAL_ERR_PARA;
    }

    KalTimer* kalTimer = (KalTimer*)timerId;

    if (xTimerStop(kalTimer->timerHandle, 0) != pdPASS) {
        return KAL_ERR_INNER;
    }

    kalTimer->isRunning = 0;
    return KAL_OK;
}

KalErrCode KalTimerDelete(KalTimerId timerId)
{
    if (timerId == NULL) {
        return KAL_ERR_PARA;
    }

    KalTimer* kalTimer = (KalTimer*)timerId;

    if (xTimerDelete(kalTimer->timerHandle, 0) != pdPASS) {
        return KAL_ERR_INNER;
    }

    free(kalTimer);
    return KAL_OK;
}

unsigned int KalTimerIsRunning(KalTimerId timerId)
{
    if (timerId == NULL) {
        return 0;
    }

    KalTimer* kalTimer = (KalTimer*)timerId;
    return kalTimer->isRunning;
}
