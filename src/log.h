#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

// Enable/disable logs
#define PLUGIN_DEBUG 1

static inline void plugin_log(const char* fmt, ...) {
#if PLUGIN_DEBUG
    // Get local time
    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t);

    char time_str[20];
    strftime(time_str, sizeof(time_str), "%H:%M:%S", tm_info);

    // Prefix [hh:mm:ss] [PLUGIN]
    fprintf(stderr, "[%s] [PLUGIN] ", time_str);

    // Variable arguments
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    // End of line
    fprintf(stderr, "\n");
    fflush(stderr);
#endif
}

#endif // LOG_H
