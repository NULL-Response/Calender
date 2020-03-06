#include"class_definition.h"
#include"headers_and_prototypes.h"

extern int language;

bool Is_Leap_Year(const int &y)//if y is leap year, return true; else return false
{
	if(y%400==0||(y%4==0&&y%100!=0)) return 1;
	else return 0;
}

void instruction()//perform instructions or guidelines of the program
{
    using std::cout;
    using std::endl;
	if(language==0)
	cout<<"程序：万年历"<<endl
            <<"功能：1.输出某年某月的月历；"<<endl
            <<"      2.输入两个时间，求差值（仅以年、月、日、时、分、秒为单位，和以年-月-日-时:分:秒为单位）；"<<endl
            <<"      3.输入两个时间，求相加值（同上）；"<<endl
            <<"      4.求某一天是星期几；"<<endl
            <<"      5.输入年份，判断是否闰年；"<<endl
            <<"      6.输入任意时间，给出转换后的标准时间；"<<endl
            <<"若输入的时间超出范围，程序可自动转换为标准时间。"<<endl
            <<"若希望求某一时间XXX时间前/后的具体时间，建议使用功能6。"
            <<"如求2020年1月1日0时0分0秒后-10000日具体为何时，可输入2020 1 -9999 0 0 0。功能2、3可能有理解上的差异。"
            <<"\n若欲使用某一项功能，请输入对应的序号（输入其他数字或非空白字符可退出程序）。"<<endl
            <<"若需更多细节，输入0。"<<endl;
    else if(language==1)
    cout<<"Program: Calender"<<endl
            <<"Functions: 1. print the monthly calender of a month in a year. "<<endl
            <<"                  2. input 2 times and minus the later from the former. "<<endl
            <<"                  3. input 2 times and add them. "<<endl
            <<"                  4. calculate the exact weekday of a specific day. "<<endl
            <<"                  5. input a year, judge whether it's a leap year or not. "<<endl
            <<"                  6. input a time that is out of range, trim it. "<<endl
            <<"Input a time which is out of range, the program will transform it into the right form automatically. "<<endl
            <<"If precision is in your demand, choose 6 rather than 2 or 3."
            <<"\nTo perform a specific function, input the number before it. Input other numbers or non-blank characters to quit. "<<endl
            <<"For more details, input 0."<<endl;
}

