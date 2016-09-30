# robotc-openlib

## What is Openlib?
Openlib is a collection of libraries for use in VEX Robotics, each library is thouroughly tested and anyone is open to contribute.

## Library structure
Each library is organized into their own folder which includes all source files plus `info.txt` describing its usage, authors, and license (if any).
If no license is specified it will fall under CC0 (Public Domain) https://creativecommons.org/publicdomain/zero/1.0/

## Code quality requirements (RobotC)
* Use comments unless the code's functionality is obvious.
* Describe all your API functions in the project's `info.txt`.
* Clean variable namespace, prefix all the functions and variables in your lib with it's name to avoid conflicts.
* Use standard robotc formatting (tabs, not spaces).
* camelCase for functions, CamelCase for classes.
* Use allman-style for brackets https://en.wikipedia.org/wiki/Indent_style#Allman_style
* Restrict each line of code to no more then 100 characters long.
* Declare objects at smallest possible scope.  Avoid using global variables. 
* Future proof. Avoid having to deprecate functions in the future.
* Put some examples in an `examples` sub folder if possible.
* TEST YOUR CODE BEFORE PUSHING!

## Issue tracker
The issue tracker is not a support forum, only post if you are certain it is a bug in the library's code or if you are requesting a feature

Please put the name of the library in the title of the issue, for example `[PID] Robot spinning in circles` and share code that can reproduce the issue.
