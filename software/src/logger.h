/**
 * Logging header to log messages with different severity to console.
 */

#ifndef LOGGER_H // Header guard
#define LOGGER_H 

#define CURRENT_LOG_LEVEL DEBUG // CHANGE THIS TO CHANGE LOGGING LEVEL

enum LogLevel {
	DEBUG = 0,
	WARNING = 1,
	INFO = 2,
	ERROR = 3
};

void logMsg(const char *format, const char *source, LogLevel logLevel, ...);

#endif