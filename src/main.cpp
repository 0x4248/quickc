/* Quick C (main.c)
 * A quick C and C++ runner
 * Github: https://www.github.com/0x4248/quickc
 * License: GNU General Public License v3.0
 * By: 0x4248
 *
 * Main entry point for the program
 */

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "include/help.h"
#include "include/logger.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        /**
         * Usage message
         * If the user does not provide enough arguments
         * then print the usage message and exit with code 1
         * to indicate an error has occurred on the program
         */
        std::cout << "Usage: quickc <file> <flags file> [args]" << std::endl;
        std::cout << "For help run quickc -quickh" << std::endl;
        return 1;
    }
    bool verbose = false;
    bool log_to_file = false;

    std::string file = argv[1];
    std::string flags_file;
    if (argc > 2) {
        flags_file = argv[2];
    } else {
        flags_file = ".";
    }

    std::string args = "";
    for (int i = 3; i < argc; i++) {
        args += argv[i];
        args += " ";
    }
    std::string flags = "";
    if (flags_file == ".") {
        flags = "-Wall";
    } else {
        std::ifstream flags_file_stream(flags_file);
        std::getline(flags_file_stream, flags);
        if (flags.find("-quickv") != std::string::npos) {
            /* Verbose mode */
            verbose = true;
            flags.erase(flags.find("-quickv"), 7);
            log("Verbose mode enabled", verbose, log_to_file);
        }
        if (flags.find("-quickl") != std::string::npos) {
            /* Log to file */
            log_to_file = true;
            flags.erase(flags.find("-quickl"), 7);
            log("Logging to file enabled", verbose, log_to_file);
        }
        if (flags.find("-quickh") != std::string::npos) {
            /* Help flag */
            log("Help flag raised running help", verbose, log_to_file);
            help();
            return 0;
        }
    }
    std::string type = "";
    std::string extension = file.substr(file.find_last_of(".") + 1);
    if (extension == "c") {
        log("File type is C", verbose, log_to_file);
        type = "c";
    } else if (extension == "cpp" || extension == "cc" || extension == "cxx" ||
               extension == "c++") {
        log("File type is C++", verbose, log_to_file);
        type = "cpp";
    } else {
        error("Cannot determine what the file type is", verbose, log_to_file);
        std::cout << "Invalid file type" << std::endl;
        return 1;
    }
    int code;
    if (type == "c") {
        log("Compiling C file", verbose, log_to_file);
        std::string compile_command = "gcc " + file + " -o quickc.tmp " + flags;
        std::string run_command = "./quickc.tmp " + args;
        code = system(compile_command.c_str());
        if (code != 0) {
            error("Command exited with non-zero code", verbose, log_to_file);
            exit(1);
        }
        log("Running C file", verbose, log_to_file);
        code = system(run_command.c_str());
        if (code != 0) {
            error("Command exited with non-zero code", verbose, log_to_file);
        }

        log("Removing temporary file", verbose, log_to_file);
        std::filesystem::remove("quickc.tmp");
    }
    if (type == "cpp") {
        log("Compiling C++ file", verbose, log_to_file);
        std::string compile_command = "g++ " + file + " -o quickc.tmp " + flags;
        std::string run_command = "./quickc.tmp " + args;
        code = system(compile_command.c_str());
        if (code != 0) {
            error("Command exited with non-zero code", verbose, log_to_file);
            exit(1);
        }
        log("Running C++ file", verbose, log_to_file);
        code = system(run_command.c_str());
        if (code != 0) {
            error("Command exited with non-zero code", verbose, log_to_file);
        }
        log("Removing temporary file", verbose, log_to_file);
        std::filesystem::remove("quickc.tmp");
    }
}