/* Quick C (main.c)
 * A quick C and C++ runner
 * Github: https://www.github.com/awesomelewis2007/quickc
 *
 * Main entry point for the program
*/

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "include/help.h"
#include "include/logger.h"

int main(int argc, char *argv[]) {
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
        flags = "-Wall -O2";
    } else {
        std::ifstream flags_file_stream(flags_file);
        std::getline(flags_file_stream, flags);
        if (flags.find("-quickv") != std::string::npos) {
            verbose = true;
            flags.erase(flags.find("-quickv"), 7);
            log("Verbose mode enabled", verbose, log_to_file);
        }
        if(flags.find("-quickl") != std::string::npos) {
            log_to_file = true;
            flags.erase(flags.find("-quickl"), 7);
            log("Logging to file enabled", verbose, log_to_file);
        }
        if(flags.find("-quickh") != std::string::npos) {
            log("Help flag raised running help", verbose, log_to_file);
            help();
            return 0;
        }
    }
    std::string type = "";
    std::string extension = file.substr(file.find_last_of(".") + 1);
    if (extension == "c"){
        log("File type is C", verbose, log_to_file);
        type = "c";
    } else if (extension == "cpp" || extension == "cc" || extension == "cxx" || extension == "c++") {
        log("File type is C++", verbose, log_to_file);
        type = "cpp";
    } else {
        error("Cannot determine what the file type is", verbose, log_to_file);
        std::cout << "Invalid file type" << std::endl;
        return 1;
    }
    int code;
    if (type == "c"){
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
    if (type == "cpp"){
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