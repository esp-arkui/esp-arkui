
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "esp_log.h"

#define PUBLIC_FLAG "{public}"
#define PRIVATE_FLAG "{private}"

static char log_buf[256] = {0};

static char *__removeSubstring(const char *_str, const char *sub) {
    strncpy(log_buf, _str, sizeof(log_buf)-1);
    char *match;
    size_t len = strlen(sub);

    // 循环查找并移除所有的子串
    while ((match = strstr(log_buf, sub)) != NULL) {
        memmove(match, match + len, strlen(match + len) + 1);
    }
    return log_buf;
}

void HILOG_FATAL(const char *mod, const char *msg, ...)
{
    va_list args;
    va_start(args, msg);
    char buffer[512];
    vsnprintf(buffer, sizeof(buffer), __removeSubstring(msg, PUBLIC_FLAG), args);
    ESP_LOGE(mod, "%s", buffer);
    va_end(args);
}

void HILOG_ERROR(const char *mod, const char *msg, ...)
{
    va_list args;
    va_start(args, msg);
    char buffer[512];
    vsnprintf(buffer, sizeof(buffer), __removeSubstring(msg, PUBLIC_FLAG), args);
    ESP_LOGE(mod, "%s", buffer);
    va_end(args);
}

void HILOG_INFO(const char *mod, const char *msg, ...)
{
    va_list args;
    va_start(args, msg);
    char buffer[512];
    vsnprintf(buffer, sizeof(buffer), __removeSubstring(msg, PUBLIC_FLAG), args);
    ESP_LOGI(mod, "%s", buffer);
    va_end(args);
}

void HILOG_WARN(const char *mod, const char *msg, ...)
{
    va_list args;
    va_start(args, msg);
    char buffer[512];
    vsnprintf(buffer, sizeof(buffer), __removeSubstring(msg, PUBLIC_FLAG), args);
    ESP_LOGW(mod, "%s", buffer);
    va_end(args);
}

void HILOG_DEBUG(const char *mod, const char *msg, ...)
{
    va_list args;
    va_start(args, msg);
    char buffer[512];
    vsnprintf(buffer, sizeof(buffer), __removeSubstring(msg, PUBLIC_FLAG), args);
    ESP_LOGI(mod, "%s", buffer);
    va_end(args);
}
