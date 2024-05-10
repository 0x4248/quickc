/* Quick C (help.h)
 * A quick C and C++ runner
 * Github: https://www.github.com/0x4248/quickc
 * License: GNU General Public License v3.0
 * By: 0x4248
 *
 * Help function
 */

#include <iostream>
#include <string>

/**
 * Help message
 * @returns void
 */
void help() {
    std::cout << "Usage: quickc <File> <Flags file> <args>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -quickv  Verbose output" << std::endl;
    std::cout << "  -quickl  Log output to file" << std::endl;
    std::cout << "  -quickh  Shows this help message" << std::endl;
    std::cout << "Other flags:" << std::endl;
    std::cout << "  Any other flags will be passed to gcc or g++" << std::endl;
}