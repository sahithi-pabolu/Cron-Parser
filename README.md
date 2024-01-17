
# Cron Praser

This command line application, written in C++, is a simple cron expression parser that converts a cron expression into a human-readable table format. It takes a standard cron string as input and expands each field to display the times at which it will run. The input should be in the standard cron format with five time fields (minute, hour, day of month, month, and day of week), plus a command. The output is formatted as a table, with the field name in the first 14 columns and the corresponding times in a space-separated list.

## Table of Contents
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
  - [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)
- [License](#license)

## Prerequisites

GNU Compiler Collection (g++):

Ensure that the GNU Compiler Collection is installed on your system. 

On macOS, you can use Homebrew:

1. Install Homebrew

    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

2. Install compiler

    brew install gcc

3. You can check if the compiler is present on your system by using the following steps

    a. Check GCC Version:

        gcc --version

    b. Check for g++:

        g++ --version

## Getting Started

To use this program, follow these steps:

1. Clone the repository to your local machine.

    git clone https://github.com/sahithi-pabolu/Cron-Parser.git

### Usage

1. Open a terminal or command prompt in the root folder.

    cd Cron-Parser

2. Compile the project

    g++ -o CronParserCLI *.cpp

3. Now you have access to cron-parser binary. Run the program with a cron expression as an argument. For example:

    ./CronParserCLI "*/10 8-18/2 * * 1-5 /usr/bin/find"

You can replace "*/10 8-18/2 * * 1-5 /usr/bin/find" with any cron expression.

4. The program will output the formatted cron expression as a table:

    minute        0 10 20 30 40 50 
    hour          8 10 12 14 16 18 
    day of month  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 
    month         1 2 3 4 5 6 7 8 9 10 11 12 
    day of week   1 2 3 4 5 
    command       /usr/bin/find

5. You can run the tests to see if the code works correctly:

## Features

1. Provides human readable table to understand the cron expression with each filed name and corresponding time values

2. Application can handle range values, list values, increment values or any value for each cron field

## Contributing
If you would like to contribute to this project, please feel free to submit issues or pull requests on the GitHub repository.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
