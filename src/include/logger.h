/* Quick C (logger.c)
 * A quick C and C++ runner
 * Github: https://www.github.com/0x4248/quickc
 * License: GNU General Public License v3.0
 * By: 0x4248
 *
 * Logging functions
 */

#include <fstream>
#include <iostream>
#include <string>

#include "../lib/nice_verbose.h"

/**
 * Log a message to the console and/or to a log file
 * @param message The message to log
 * @param verbose Whether to log to the console
 * @param log_to_file Whether to log to a file
 * @returns void
 */
void log(std::string message, bool verbose, bool log_to_file) {
    if (verbose) {
        nice_verbose::log(message);
    }
    if (log_to_file) {
        std::ofstream log_file("quickc.log", std::ios::app);
        log_file << " [LOG]   " << message << std::endl;
    }
}

/**
 * Log an error to the console and/or to a log file
 * @param message The message to log
 * @param verbose Whether to log to the console
 * @param log_to_file Whether to log to a file
 * @returns void
 */
void error(std::string message, bool verbose, bool log_to_file) {
    if (verbose) {
        nice_verbose::error(message);
    }
    if (log_to_file) {
        std::ofstream log_file("quickc.log", std::ios::app);
        log_file << " [ERROR] " << message << std::endl;
    }
}