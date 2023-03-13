/* Quick C (logger.c)
 * A quick C and C++ runner
 * Github: https://www.github.com/awesomelewis2007/quickc
 *
 * Logging functions
*/

#include <iostream>
#include <string>
#include <fstream>

#include "../lib/nice_verbose.h"

void log(std::string message, bool verbose, bool log_to_file) {
    if (verbose) {
        nice_verbose::log(message);
    }
    if (log_to_file) {
        std::ofstream log_file("quickc.log", std::ios::app);
        log_file <<" [LOG]   " <<message << std::endl;
    }

}

void error(std::string message, bool verbose, bool log_to_file) {
    if (verbose) {
        nice_verbose::error(message);
    }
    if (log_to_file) {
        std::ofstream log_file("quickc.log", std::ios::app);
        log_file <<" [ERROR] " <<message << std::endl;
    }
}