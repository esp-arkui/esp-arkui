#ifndef ABILITY_LITE_LOG_H
#define ABILITY_LITE_LOG_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

void HILOG_FATAL(const char *mod, const char *msg, ...);
void HILOG_ERROR(const char *mod, const char *msg, ...);
void HILOG_INFO(const char *mod, const char *msg, ...);
void HILOG_WARN(const char *mod, const char *msg, ...);
void HILOG_DEBUG(const char *mod, const char *msg, ...);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif

