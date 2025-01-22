
#ifndef LOS_TASK_H
#define LOS_TASK_H


#include "./cmsis_os2.h"
#include "esp_log.h"

#define LOS_OK             0
#define LOS_NOK       (uint32_t)(-1)

#define LOS_TaskLock() 
#define LOS_TaskUnlock() 

#define OS_TASK_PRIORITY_LOWEST 31


typedef uint32_t UINT32;
typedef void (*TSK_ENTRY_FUNC)(void * arg);

typedef struct tagTskInitParam {
    TSK_ENTRY_FUNC       pfnTaskEntry;              /**< Task entrance function                 */
    uint16_t               usTaskPrio;                /**< Task priority                          */
    uint32_t               uwArg;                     /**< Task parameters                        */
    uint32_t              stackAddr;                 /**< Task stack memory                      */
    uint32_t               uwStackSize;               /**< Task stack size                        */
    char                 *pcName;                   /**< Task name                              */
    uint32_t               uwResved;                  /**< Reserved                               */
} TSK_INIT_PARAM_S;


static inline UINT32 LOS_CurTaskIDGet(void)
{
    return (UINT32)xTaskGetCurrentTaskHandle();
}

static inline uint32_t LOS_TaskDelete(UINT32 taskID)
{
    vTaskDelete((TaskHandle_t)taskID);
    return LOS_OK;
}

static inline uint32_t LOS_TaskCreate(UINT32 *taskID, TSK_INIT_PARAM_S *taskInitParam)
{
    ESP_LOGI("porting", "taskInitParam->pcName: %s", taskInitParam->pcName);
    BaseType_t ret = xTaskCreate(
        taskInitParam->pfnTaskEntry, 
        taskInitParam->pcName, 
        taskInitParam->uwStackSize, 
        (void*)taskInitParam->uwArg, 
        taskInitParam->usTaskPrio, 
        (TaskHandle_t*)taskID);

    ESP_LOGI("porting", "taskInitParam->pcName: %s, ret: %d, %p", taskInitParam->pcName, ret, *taskID);
    return (ret == pdPASS) ? LOS_OK : LOS_NOK;
}


#endif
