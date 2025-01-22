
#ifndef CMSIS_OS2_H
#define CMSIS_OS2_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "esp_cpu.h"


#define osDelay(ms) vTaskDelay(pdMS_TO_TICKS(ms))
#define osWaitForever portMAX_DELAY

#define TIME_CHK() \
if (timeout==0){ \
    static volatile uint32_t ssss = 0; \
    esp_cpu_set_watchpoint(0, (void *)&ssss, 4, ESP_CPU_WATCHPOINT_ACCESS); \
    ssss = 1; \
}

typedef struct {
  const char                   *name;   ///< name of the message queue
  uint32_t                 attr_bits;   ///< attribute bits
  void                      *cb_mem;    ///< memory for control block
  uint32_t                   cb_size;   ///< size of provided memory for control block
  void                      *mq_mem;    ///< memory for data storage
  uint32_t                   mq_size;   ///< size of provided memory for data storage 
} osMessageQueueAttr_t;

typedef struct {
  const char                   *name;   ///< name of the mutex
  uint32_t                 attr_bits;   ///< attribute bits
  void                      *cb_mem;    ///< memory for control block
  uint32_t                   cb_size;   ///< size of provided memory for control block
} osMutexAttr_t;

typedef enum {
  osOK                    =  0,         ///< Operation completed successfully.
  osError                 = -1,         ///< Unspecified RTOS error: run-time error but no other error message fits.
  osErrorTimeout          = -2,         ///< Operation not completed within the timeout period.
  osErrorResource         = -3,         ///< Resource not available.
  osErrorParameter        = -4,         ///< Parameter error.
  osErrorNoMemory         = -5,         ///< System is out of memory: it was impossible to allocate or reserve memory for the operation.
  osErrorISR              = -6,         ///< Not allowed in ISR context: the function cannot be called from interrupt service routines.
  osErrorSafetyClass      = -7,         ///< Operation denied because of safety class violation.
  osStatusReserved        = 0x7FFFFFFF  ///< Prevents enum down-size compiler optimization.
} osStatus_t;

typedef QueueHandle_t osMessageQueueId_t;
typedef SemaphoreHandle_t osMutexId_t;

static inline osStatus_t osMessageQueueDelete (osMessageQueueId_t mq_id)
{
    vQueueDelete(mq_id);
    return osOK;
}

static inline osMessageQueueId_t osMessageQueueNew (uint32_t msg_count, uint32_t msg_size, const osMessageQueueAttr_t *attr)
{
    return xQueueCreate(msg_count, msg_size);
}

static inline osStatus_t osMessageQueuePut (osMessageQueueId_t mq_id, const void *msg_ptr, uint8_t msg_prio, uint32_t timeout)
{
    if (xQueueSend(mq_id, msg_ptr, timeout) == pdPASS) {
        return osOK;
    }
    return osErrorResource;
}

static inline osStatus_t osMessageQueueGet (osMessageQueueId_t mq_id, void *msg_ptr, uint8_t *msg_prio, uint32_t timeout)
{
    if (xQueueReceive(mq_id, msg_ptr, timeout) == pdPASS) {
        return osOK;
    }
    return osErrorResource;
}

static inline uint32_t osMessageQueueGetCount (osMessageQueueId_t mq_id)
{
    return uxQueueMessagesWaiting(mq_id);
}



static inline osMutexId_t osMutexNew(const osMutexAttr_t *attr)
{
    return xSemaphoreCreateRecursiveMutex();
}


static inline osStatus_t osMutexDelete(osMutexId_t mutex_id)
{
    vSemaphoreDelete(mutex_id);
    return osOK;
}

static inline osStatus_t osMutexAcquire (osMutexId_t mutex_id, uint32_t timeout)
{
    if (xSemaphoreTakeRecursive(mutex_id, timeout) == pdPASS) {
        return osOK;
    }
    return osErrorResource;
}

static inline osStatus_t osMutexRelease (osMutexId_t mutex_id)
{
    xSemaphoreGiveRecursive(mutex_id);
    return osOK;
}


#endif // CMSIS_OS2_H
