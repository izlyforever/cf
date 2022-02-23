#include <os/log.h>

int main(void)
{
    os_log_fault(OS_LOG_DEFAULT, "Hello os_log_fault");
    os_log_error(OS_LOG_DEFAULT, "Hello os_log_error");
    os_log_info(OS_LOG_DEFAULT, "Hello os_log_info");   // Not shown on console
    os_log_debug(OS_LOG_DEFAULT, "Hello os_log_debug"); // Not shown on console

    os_log(OS_LOG_DEFAULT, "Hello os_log");
    os_log(OS_LOG_DEFAULT, "Hello os_log %d", 5);
    os_log_with_type(OS_LOG_DEFAULT, OS_LOG_TYPE_DEFAULT, "Hello os_log_with_type");
    const char* msg = "Hello os_log_with_type dynamic";
    os_log_with_type(OS_LOG_DEFAULT, OS_LOG_TYPE_DEFAULT, "%s %d", msg, 5);

    return 0;
}