# cbuild

CBuild is a build system developed for beginners in the C programming language. It is easy to use and suitable for those who are starting to learn C.

# Requirements

To compile your C programs with CBuild, you need to have gcc installed on your system as a prerequisite. If you already have gcc installed, make sure it is added to the system PATH. If it is not installed, you can obtain it from https://www.mingw-w64.org/.
# Building CBuild

To build CBuild, you need cmake. Download and install cmake from https://cmake.org/, and then add cmake to your system PATH. Next, clone CBuild using git. If you don't have git, you can directly download the source code. After downloading, open the Windows Terminal and navigate to the location of CBuild using the command cd _cbuild_. Then, enter the command cmake -B build && cmake --build build. If the build process completes successfully, an executable file will be created in the bin folder.<br/>
In short:
1. cmake -B build -G "MinGW Makefiles"
2. cmake --build build --config Release

# Using CBuild

To use CBuild, you need to provide the source files and the desired command using the -b command. For example, let's assume we have a main.c and sum.c file. To compile this project, our command would be CBuild -b main.c sum.c -exe. This command will generate the necessary build files. Then, you can execute the compilation and execution processes by running the .\BUILD\build-e.bat file. To only run the program, you can use the command .\BUILD\run.bat.

# Commands
1. -b:        Required to create object files.
2. -exe:      To create the executable file.
3. -lstatic:  not yet in use
4. -lshared:  not yet in use
5. -link:     not yet in use
