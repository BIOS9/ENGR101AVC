/**
 * Logging header to log messages with different severity to console.
 */

#ifndef LOGGER_H // Header guard
#define LOGGER_H 

#define CURRENT_LOG_LEVEL DEBUG // CHANGE THIS TO CHANGE LOGGING LEVEL

#include <stdio.h>

enum LogLevel {
    DEBUG = 0,
    WARNING = 1,
    INFO = 2,
    ERROR = 3
};

const char * LogPrefixes[] = { "DEBUG", "WARNING", "INFO", "ERROR" };

void logMsg(const char * message, LogLevel logLevel) {
    
    // If the message priority is less than the current priority, discard the message
    if(CURRENT_LOG_LEVEL > logLevel)
        return;
    
    printf("[%s] %s\n", LogPrefixes[logLevel], message);
}

#endif