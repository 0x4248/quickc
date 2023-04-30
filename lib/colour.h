/* Console_colour
 * A simple header file to add colour to your console output.
 * GitHub: https://www.github.com/awesomelewis2007/cpp_console_colour
 * Licence: GPL-3.0
 * By: Lewis Evans
 */

#ifndef COLOUR
#define COLOUR
#include <iostream>
#include <string>

namespace ascii_colours {
class normal {
  public:
    std::string red = "\033[31m";
    std::string green = "\033[32m";
    std::string yellow = "\033[33m";
    std::string blue = "\033[34m";
    std::string magenta = "\033[35m";
    std::string cyan = "\033[36m";
    std::string white = "\033[37m";
    std::string black = "\033[30m";
    std::string reset = "\033[0m";
};
class bold {
  public:
    std::string red = "\033[1;31m";
    std::string green = "\033[1;32m";
    std::string yellow = "\033[1;33m";
    std::string blue = "\033[1;34m";
    std::string magenta = "\033[1;35m";
    std::string cyan = "\033[1;36m";
    std::string white = "\033[1;37m";
    std::string black = "\033[1;30m";
    std::string reset = "\033[0m";
};
class underline {
  public:
    std::string red = "\033[4;31m";
    std::string green = "\033[4;32m";
    std::string yellow = "\033[4;33m";
    std::string blue = "\033[4;34m";
    std::string magenta = "\033[4;35m";
    std::string cyan = "\033[4;36m";
    std::string white = "\033[4;37m";
    std::string black = "\033[4;30m";
    std::string reset = "\033[0m";
};
class italic {
  public:
    std::string red = "\033[3;31m";
    std::string green = "\033[3;32m";
    std::string yellow = "\033[3;33m";
    std::string blue = "\033[3;34m";
    std::string magenta = "\033[3;35m";
    std::string cyan = "\033[3;36m";
    std::string white = "\033[3;37m";
    std::string black = "\033[3;30m";
    std::string reset = "\033[0m";
};
class bold_underline {
  public:
    std::string red = "\033[1;4;31m";
    std::string green = "\033[1;4;32m";
    std::string yellow = "\033[1;4;33m";
    std::string blue = "\033[1;4;34m";
    std::string magenta = "\033[1;4;35m";
    std::string cyan = "\033[1;4;36m";
    std::string white = "\033[1;4;37m";
    std::string black = "\033[1;4;30m";
    std::string reset = "\033[0m";
};
class bold_italic {
  public:
    std::string red = "\033[1;3;31m";
    std::string green = "\033[1;3;32m";
    std::string yellow = "\033[1;3;33m";
    std::string blue = "\033[1;3;34m";
    std::string magenta = "\033[1;3;35m";
    std::string cyan = "\033[1;3;36m";
    std::string white = "\033[1;3;37m";
    std::string black = "\033[1;3;30m";
    std::string reset = "\033[0m";
};
class bold_underline_italic {
  public:
    std::string red = "\033[1;4;3;31m";
    std::string green = "\033[1;4;3;32m";
    std::string yellow = "\033[1;4;3;33m";
    std::string blue = "\033[1;4;3;34m";
    std::string magenta = "\033[1;4;3;35m";
    std::string cyan = "\033[1;4;3;36m";
    std::string white = "\033[1;4;3;37m";
    std::string black = "\033[1;4;3;30m";
    std::string reset = "\033[0m";
};
class underline_italic {
  public:
    std::string red = "\033[4;3;31m";
    std::string green = "\033[4;3;32m";
    std::string yellow = "\033[4;3;33m";
    std::string blue = "\033[4;3;34m";
    std::string magenta = "\033[4;3;35m";
    std::string cyan = "\033[4;3;36m";
    std::string white = "\033[4;3;37m";
    std::string black = "\033[4;3;30m";
    std::string reset = "\033[0m";
};

} // namespace ascii_colours

#endif // COLOUR