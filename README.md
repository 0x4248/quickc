# <img src="https://raw.githubusercontent.com/awesomelewis2007/quickc/master/logo.png" width=25> Quick C
A C/C++ quick runner for testing small snippets of C/C++ code.

## ❓ Usage
```bash
quickc <file> <flags_file> <args_sent_to_program>
```

## 📚 Example
```bash
quickc hello.c . -opt1 -opt2
```

## 📝 Flags file
The flags file is a file that contains the flags that will be passed to the compiler. If left with `.` then the default flags will be used which are `-Wall -std=C++17 -O2`.

## 📖 Test files
The test files are located in the `tests` folder. There are C and C++ test files.

### Test using make
To test using make, run the following command:
```bash
make test
```

## 📚 Source code file structure
The source code file structure is as follows:
- `lib/`: Contains the library's needed for the program to run.
- `src/`: Contains the source code of the program.
- `src/main.cpp`: Contains the main function of the program.
- `src/include/`: Contains the header files of the program.
- `tests/`: Contains the test files for the program.
- `Makefile`: Contains the make commands for the program.
