#include"class_definition.h"
#include"headers_and_prototypes.h"

extern int language;

void func0()
{
    using std::cout;
    if(language==0)  cout<<"本程序的主要原理如下：先将时间转换为正常形式，再根据其距离2020年1月1日（星期三）多少天求出星期。\n"
                                        <<"对于功能2，先求出二者距离2020年1月1日0时0分0秒有多少秒，再将两者相减，再转换成正常形式；\n"
                                        <<"对于功能3，则先求出二者距离2020年1月1日0时0分0秒有多少秒，再将两者相加，再加上2倍0年1月1日0时0分0秒到2020年1月1日0时0分0秒的秒数，再转换成正常形式；\n"
                                        <<"对于闰年的定义，是可以整除400，或者能整除4但不能整除100。"
                                        <<"程序内部使用long long int来储存秒、分、时、天，用int来储存月、年。"
                                        <<"\n前者范围为-2^63~2^63-1，即-9223372036854775808~9223372036854775807；后者范围为-2^15~2^15-1，即-2147483648～2147483647。若需要更大范围，可使用long long double等类型。"
                                        <<"\n本程序在Github上有源码可供下载或学习：https://github.com/NULL-Response/Calender。"
                                        <<"另外，请换成GBK编码或WINDOWS-936以同时支持中英文。";
    else if(language==1)   cout<<"The program works as follows: first convert the input time into a correct form, and figure out the weekday by calculating the day to 2020. 1. 1 Wed. \n"
                                                <<"As for function 2, it first calculates the seconds to 2020-1-1 00:00:00 of the 2 times, separately, then minus the later from the former, then convert the result; \n"
                                                <<"As for function 3, it first calculates the seconds to 2020-1-1 00:00:00 of the 2 times separately, add them together, and add 2 times the seconds from 0-1-1 00:00:00 to 2020-1-1 00:00:00, then convert the result;\n"
                                                <<"As for leap years, they equal n times 400, or n times 4 but with a non-zero modulus with 100. "
                                                <<"The program uses long long int to store seconds, minutes, hours and days, int for months and years. "
                                                <<"\nLong long int has a range of -2^63~2^63-1, which is -9223372036854775808~9223372036854775807; int has a range of -2^15~2^15-1, which is -2147483648～2147483647. For a greater range, use long long double as substitution. "
                                                <<"\nYou can download the source code at: https://github.com/NULL-Response/Calender. "
                                                <<"Besides, encoding in GBK or WINDOWS-936 to support Chinese and English at the same time. ";
}

void func1()
{
    using std::cout;
    using std::cin;
    using std::endl;
	int m,y,i,j;
	if(language==0) cout<<"请依次输入年份、月份：";
	else if(language==1) cout<<"input year and month in sequence: ";
	cin>>y>>m;
	switch(m)
	{
		case 2:if(Is_Leap_Year(y)) i=29;else i=28;break;
		case 4:case 6:case 9:case 11:i=30;break;
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:i=31;break;
	}
	Time *t=new Time[i];
	for(j=0;j<i;j++) t[j].Set_time(0,0,0,j+1,m,y);
	if(language==0) cout<<y<<"年"<<m<<"月的月历如下：";
	else if(language==1) cout<<y<<"year"<<m<<"month monthly calender output as follows: ";
	t[0].Show(1);
	for(j=t[0].Get_week();j>1;j--) cout<<"\t";
	for(j=0;j<i;j++)
	{
		cout<<j+1;
		if(t[j].Get_week()==7) cout<<endl;
		else cout<<"\t";
	}
	delete t;
}

void func2()
{
    using std::cout;
    using std::cin;
    using std::endl;
	long long int sec,min,hou,day,sec1,sec2;
	int mon,year;
	Time t1;
	t1.Show(2);
	cin>>year>>mon>>day>>hou>>min>>sec;
	t1.Set_time(sec,min,hou,day,mon,year);
	sec=t1.Get_sec();min=t1.Get_min();hou=t1.Get_hou();day=t1.Get_day();mon=t1.Get_mon();year=t1.Get_year();
	sec1=(t1.Day_to_2020_1_1(day,mon,year))*86400+hou*3600+min*60+sec;//sec1 is the seconds to 2020.1.1.0.0.0
	if(language==0) cout<<"请按年、月、日、时、分、秒的顺序输入后一个时间：";
	else if(language==1) cout<<"input the later time in the same sequence: ";
	cin>>year>>mon>>day>>hou>>min>>sec;
	t1.Set_time(sec,min,hou,day,mon,year);
	sec=t1.Get_sec();min=t1.Get_min();hou=t1.Get_hou();day=t1.Get_day();mon=t1.Get_mon();year=t1.Get_year();
	sec2=(t1.Day_to_2020_1_1(day,mon,year))*24*60*60+hou*3600+min*60+sec;
	sec=sec1-sec2;min=sec/60;hou=sec/3600;day=sec/86400;mon=sec/2592000;year=sec/31536000;
	if(language==0)  cout<<"两者相差"<<sec<<"秒/"<<min<<"分/"<<hou<<"时/"<<day<<"天/"<<mon<<"月/"<<year<<"年"
                                        <<endl<<"（按30天=1月、365天=1年的进制计算，不足1的部分舍去）"
                                        <<endl<<"从0年1月1日0时0分0秒开始计算，这些时间可累计至（考虑闰年）：";
    else if(language==1)   cout<<"the subtraction is "<<sec<<"seconds/"<<min<<"minutes/"<<hou<<"hours/"<<day<<"days/"<<mon<<"months/"<<year<<"years"
                                                <<endl<<"(1 month = 30 days and 1 year = 365 days.Numbers are rounded)"
                                                <<endl<<"Count from 0-1-1 00:00:00, the subtraction adds up to (leap years counted) : ";
	t1.Set_time(sec,0,0,1,1,0);
	t1.Show(6);
}

void func3()
{
    using std::cout;
    using std::cin;
    using std::endl;
	long long int sec,min,hou,day,s;
	int mon,year;
	Time t1;
	t1.Show(3);
	cin>>year>>mon>>day>>hou>>min>>sec;
	t1.Set_time(sec,min,hou,day,mon,year);
	sec=t1.Get_sec();min=t1.Get_min();hou=t1.Get_hou();day=t1.Get_day();mon=t1.Get_mon();year=t1.Get_year();
	s=sec+min*60+hou*3600+(t1.Day_to_2020_1_1(day,mon,year))*86400;
	if(language==0) cout<<"请按年、月、日、时、分、秒的顺序输入后一个时间：";
	else if(language==1) cout<<"input the later time in the same sequence: ";
	cin>>year>>mon>>day>>hou>>min>>sec;
	t1.Set_time(sec,min,hou,day,mon,year);
	sec=t1.Get_sec();min=t1.Get_min();hou=t1.Get_hou();day=t1.Get_day();mon=t1.Get_mon();year=t1.Get_year();
	s+=sec+min*60+hou*3600+(t1.Day_to_2020_1_1(day,mon,year))*86400+63745056000+63745056000;//63745056000 is the seconds from 0. 1. 1, 0:0:0 to 2020. 1. 1, 0:0:0
	sec=s;min=s/60;hou=s/3600;day=s/86400;mon=s/2592000;year=s/31536000;
	if(language==0)  cout<<"两者和为"<<sec<<"秒/"<<min<<"分/"<<hou<<"时/"<<day<<"天/"<<mon<<"月/"<<year<<"年"
                                        <<endl<<"（按30天=1月、365天=1年的进制计算，不足1的部分舍去）"
                                        <<endl<<"从0年1月1日0时0分0秒开始计算，这些时间可累计至（考虑闰年）：";
    else if(language==1)   cout<<"the addition is "<<sec<<"seconds/"<<min<<"minutes/"<<hou<<"hours/"<<day<<"days/"<<mon<<"months/"<<year<<"years"
                                                <<endl<<"(1 month = 30 days and 1 year = 365 days.Numbers are rounded)"
                                                <<endl<<"Count from 0-1-1 00:00:00, the subtraction adds up to (leap years counted) : ";
	t1.Set_time(sec,0,0,1,1,0);
	t1.Show(6);
}

void func4()
{
    using std::cout;
    using std::cin;
	int m,y;
	long long int d;
	if(language==0) cout<<"请按年、月、日的顺序输入需判断的日期：";
	else if(language==1) cout<<"input in the sequence of year, month, date: ";
	cin>>y>>m>>d;
	Time T;
	T.Set_time(0,0,0,d,m,y);
	T.Show(4);
}

void func5()
{
    using std::cout;
    using std::cin;
	int y;
	if(language==0) cout<<"请输入需判断的年份：";
	else if(language==1) cout<<"input the year: ";
	cin>>y;
	if(Is_Leap_Year(y)){
        if(language==0) cout<<y<<"年是闰年。";
        else if(language==1) cout<<y<<" year is a leap year.";
	}
	else{
         if(language==0) cout<<y<<"年不是闰年。";
         else if(language==1) cout<<y<<" year is not a leap year.";
	}
}

void func6()
{
    using std::cout;
    using std::cin;
	long long int sec,min,hou,day;
	int mon,year;
	if(language==0) cout<<"请按年、月、日、时、分、秒的顺序输入时间：";
	else if(language==1) cout<<"input the time in the sequence of year, month, date, hour, minute, second: ";
	cin>>year>>mon>>day>>hou>>min>>sec;
	Time t;
	t.Set_time(sec,min,hou,day,mon,year);
	t.Show(6);
}

