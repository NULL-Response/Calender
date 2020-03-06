# Calender

#### Description
mutiple-function Calender

#### Software Architecture
2 header files: "headers_and_prototypes.h" and "class_definition.h"
4 source code files: class_methods.cpp , main.cpp , main_functions.cpp , non_class_functions.cpp

#### Instructions
guidence:
Functions: 1. print the monthly calender of a month in a year.
           2. input 2 times and minus the later from the former.
           3. input 2 times and add them.
           4. calculate the exact weekday of a specific day.
           5. input a year, judge whether it's a leap year or not.
           6. input a time that is out of range, trim it.
Input a time which is out of range, the program will transform it into the right form automatically.
If precision is in your demand, choose 6 rather than 2 or 3.
To perform a specific function, input the number before it. Input other numbers or non-blank characters to quit.

more details:
The program works as follows: first convert the input time into a correct form, and figure out the weekday by calculating the day to 2020. 1. 1 Wed.
As for function 2, it first calculates the seconds to 2020-1-1 00:00:00 of the 2 times, separately, then minus the later from the former, then convert the result;
As for function 3, it first calculates the seconds to 2020-1-1 00:00:00 of the 2 times separately, add them together, and add 2 times the seconds from 0-1-1 00:00:00 to 2020-1-1 00:00:00, then convert the result;
As for leap years, they equal n times 400, or n times 4 but with a non-zero modulus with 100. 
The program uses long long int to store seconds, minutes, hours and days, int for months and years.
For a greater range, use long long double as substitution.
You can download the source code at: https://github.com/NULL-Response/Calender. 
Besides, encoding in GBK or WINDOWS-936 to support Chinese and English at the same time.