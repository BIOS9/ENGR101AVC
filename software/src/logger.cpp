#include <stdio.h>
#include <stdarg.h>
#include "logger.h"

const char * LogPrefixes[] = { "DEBUG", "WARNING", "INFO", "ERROR" };

/**
 * Logs messages and errors to console.
 * 
 * Supports variable argument formatting
 */
void logMsg(const char *format, const char *source, LogLevel logLevel, ...) {
    // If the message priority is less than the current priority, discard the message
	if (CURRENT_LOG_LEVEL > logLevel)
		return;
	
	FILE *stream = (logLevel == ERROR) ? stderr : stdout; // If it's an error, print to stderr

	printf("[%s][%s] ", LogPrefixes[logLevel], source); // Print the log level and log source

	va_list argptr;

	va_start(argptr, logLevel); // Get the argument list pointer
	
	vfprintf(stream, format, argptr); // Pass arguments to vprintf to print messages
	va_end(argptr);

	printf("\n"); // End the line
}