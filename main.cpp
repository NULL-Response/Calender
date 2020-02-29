#include "funcpro.h"
#include "classdefi.h"
using namespace std;

int main()
{
	instruction();
	for(int mode=1;mode>=1&&mode<=6;)
	{
		cout<<endl<<"请输入数字:";
		cin>>mode;
		switch(mode)
		{
			case 1:func1();break;
			case 2:func2();break;
			case 3:func3();break;
			case 4:func4();break;
			case 5:func5();break;
			case 6:func6();break;
			default:return 0;
		}
	}
	return 0;
}

//class functions
void Time::Show_week()//输出星期几对应的汉字
{
	switch(week)
	{
		case 1:cout<<"一";break;
		case 2:cout<<"二";break;
		case 3:cout<<"三";break;
		case 4:cout<<"四";break;
		case 5:cout<<"五";break;
		case 6:cout<<"六";break;
		case 7:cout<<"七";break;
	}
}
void Time::Show(int mode)
{
	if(mode==1)
	{
		cout<<"\n一\t二\t三\t四\t五\t六\t七\n";
	}
	else if(mode==2)
	{
		cout<<"若输入的时间超出范围，程序将先转换为规范格式再二者相减，结果与先相减再转换可能不同。"<<endl;
		cout<<"显示格式为前者-后者，负代表前者时间小于后者。若需更准确的结果，请使用功能6；"<<endl;
		cout<<"请按年、月、日、时、分、秒的顺序输入前一个时间：";
	}
	else if(mode==3)
	{
		cout<<"若输入的时间超出范围，程序将先转换为规范格式再二者相加，结果与先相加再转换可能不同。"<<endl;
		cout<<"此处的1年=365天，1月=30天。若需更准确的结果，请使用功能6；"<<endl;
		cout<<"请按年、月、日、时、分、秒的顺序输入前一个时间：";
	}
	else if(mode==4)
	{
		cout<<year<<"年"<<mon<<"月"<<day<<"日 是星期";
		Show_week();cout<<"。";
	}
	else if(mode==5)
	{
		//
	}
	else if(mode==6)
	{
		cout<<Get_year()<<"年"<<Get_mon()<<"月"
		<<Get_day()<<"日"<<Get_hou()<<"时"
		<<Get_min()<<"分"<<Get_sec()<<"秒\t星期";
		Show_week();
	}
}
void Time::Set_week()
{
	long long int d=Get_day();
	int m=Get_mon(),y=Get_year();
	long long int D=Day_to_2020_1_1(d,m,y)%7;
	if(D<0) D+=7;
	week=(3+D)%7;
	if(week==0) week+=7;
}
/*调用此函数前应先将年-月-日转换为标准格式*/
long long int Time::Day_to_2020_1_1(long long int d,int m,int y)//求y年m月d日距离2020年1月1日有多远,单位为天
{//将y年m月d日转化为2020年1月x日的形式即可
	long long int t=0;
	if(y>=2020)
	{
		for(int i=2020;i<y;i++)//先将2020~y-1年中所有年份转换为天。365或366天
		{
			if(Is_Leap_Year(i)) t+=366;
			else t+=365;
		}
		t+=year_month(1,y,m,d);//对于y年m月d日，求其距离y年1月1日的天数
	}
	else
	{
		for(int i=2019;i>y;i--)//先将2019~y+1年中所有年份转换为天。365或366天
		{
			if(Is_Leap_Year(i)) t-=366;
			else t-=365;
		}
		t+=year_month(0,y,m,d);//对于y年m月d日，求其距离y+1年1月1日的天数
	}
	return t;
}
long long int Time::year_month(int mode,int y,int m,long long int d)
{
	int t=0;
	/*先求出y年m月d日距离当年1月1日的天数*/
	for(m--;m>0;m--)//对于y年m月，求y年m月第一天距离y年1月1日的天数
	{
		switch(m)
		{
			case 2:if(Is_Leap_Year(y)) t+=29;else t+=28;break;
			case 4:case 6:case 9:case 11:t+=30;break;
			case 1:case 3:case 5:case 7:case 8:case 10:t+=31;break;
		}
	}
	t+=d;t--;//1月减一天
	/*此时t=y年m月d日距离当年1月1日的天数*/
	if(mode==0)//求距离下一年1月1日的天数，符号为负
	{
		if(Is_Leap_Year(y)) t=t-366;
		else t=t-365;
	}
	return t;
}
void Time::day_mon_year(long long int *day,int *mon,int *year)//将day，mon超出界限的部分转换
{
	long long int d=*day;int m=*mon,y=*year;
	y+=m/12;m=m%12;if(m<=0) {m+=12;y--;}//先将m转换到1-12间
	if(d>0)//若d>0
	{
		for(;d>366;)//d较大时，一年一年减，提高运行效率
		{
			if((Is_Leap_Year(y)&&m<3)||(Is_Leap_Year(y+1)&&m>2)) d-=366;//下一年闰且经过下一年2月或当年闰且初始1/2月时才会经过2月29日
			else d-=365;
			y++;
		}
		for(;d>31;)//将d降低到1-31内
		{
			switch(m)
			{
			case 2:if(Is_Leap_Year(y)) d-=29;else d-=28;m++;break;
			case 4:case 6:case 9:case 11:d-=30;m++;break;
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:d-=31;m++;break;
			}
			if(m>12) {m-=12;y++;}
		}
		//d为29，30，31时可能有问题，再分类讨论
		if(d==29&&m==2&&!Is_Leap_Year(y)) {d-=28;m++;}
		else if(d==30&&m==2)
		{
			if(Is_Leap_Year(y)) {d-=29;m++;}
			else {d-=28;m++;}
		}
		else if(d==31)
		{
			if(m==2)
			{
				if(Is_Leap_Year(y)) {d-=29;m++;}
				else {d-=28;m++;}
			}
			else if(m==4||m==6||m==9||m==11) {d-=30;m++;}
		}
	}
	else//若d<=0
	{
		for(;d<-366;)
		{
			if((Is_Leap_Year(y)&&m>2)||(Is_Leap_Year(y-1)&&m<3)) d+=366;//当年是闰且经过2月或去年是闰且经过去年的2月
			else d+=365;
			y--;
		}
		for(;d<1;)
		{
			switch(m-1)
			{
			case 2:if(Is_Leap_Year(y)) d+=29;else d+=28;m--;break;
			case 4:case 6:case 9:case 11:d+=30;m--;break;
			case 0:case 1:case 3:case 5:case 7:case 8:case 10:d+=31;m--;break;
			}
			if(m<1) {m+=12;y--;}
		}
	}
	*day=d;*mon=m;*year=y;
}

//function definition
void instruction()
{
	cout<<"程序：万年历"<<endl
		<<"功能：1.输出某年某月的月历；"<<endl
		<<"      2.输入两个时间，求差值（仅以年、月、日、时、分、秒为单位，和以年/月/日/时/分/秒为单位）；"<<endl
		<<"      3.输入两个时间，求相加值（同上）；"<<endl
		<<"      4.求某一天是星期几；"<<endl
		<<"      5.输入年份，判断是否闰年；"<<endl
		<<"      6.输入任意时间，给出转换后的标准时间；"<<endl
		<<"若输入的时间超出范围，程序可自动转换为标准时间。"<<endl
		<<"若希望求某一时间XXX时间前/后的具体时间，建议使用功能6，或先用2/3后用6验算。"
		<<"如求2020年1月1日0时0分0秒后-10000日具体为何时，可输入2020 1 -9999 0 0 0，功能2、3对年、月有舍去。"
		<<"\n若欲使用某一项功能，请输入对应的序号（输入其他数字可退出程序）。"<<endl;
}

bool Is_Leap_Year(int y)
{
	if(y%400==0||(y%4==0&&y%100!=0)) return 1;
	else return 0;
}

void func1()
{
	int m,y,i,j;
	cout<<"请依次输入年份、月份：";
	cin>>y>>m;
	switch(m)
	{
		case 2:if(Is_Leap_Year(y)) i=29;else i=28;break;
		case 4:case 6:case 9:case 11:i=30;break;
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:i=31;break;
	}
	Time *t=new Time[i];
	for(j=0;j<i;j++) t[j].Set_time(0,0,0,j+1,m,y);
	cout<<y<<"年"<<m<<"月的月历如下：";t[0].Show(1);
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
	long long int sec,min,hou,day,sec1,sec2;
	int mon,year;
	Time t1;
	t1.Show(2);
	cin>>year>>mon>>day>>hou>>min>>sec;
	t1.Set_time(sec,min,hou,day,mon,year);
	sec=t1.Get_sec();min=t1.Get_min();hou=t1.Get_hou();day=t1.Get_day();mon=t1.Get_mon();year=t1.Get_year();
	sec1=(t1.Day_to_2020_1_1(day,mon,year))*86400+hou*3600+min*60+sec;//sec1为距离2020.1.1.0.0.0的秒数
	cout<<"请按年、月、日、时、分、秒的顺序输入后一个时间：";
	cin>>year>>mon>>day>>hou>>min>>sec;
	t1.Set_time(sec,min,hou,day,mon,year);
	sec=t1.Get_sec();min=t1.Get_min();hou=t1.Get_hou();day=t1.Get_day();mon=t1.Get_mon();year=t1.Get_year();
	sec2=(t1.Day_to_2020_1_1(day,mon,year))*24*60*60+hou*3600+min*60+sec;
	sec=sec1-sec2;min=sec/60;hou=sec/3600;day=sec/86400;mon=sec/2592000;year=sec/31536000;
	cout<<"两者相差"<<sec<<"秒/"<<min<<"分/"<<hou<<"时/"<<day<<"天/"<<mon<<"月/"<<year<<"年"
		<<endl<<"（按30天=1月、365天=1年的进制计算，不足1的部分舍去）"
		<<endl<<"从0年1月1日0时0分0秒开始计算，这些时间可累计至（考虑闰年）：";
	t1.Set_time(sec,0,0,1,1,0);
	t1.Show(6);
}
void func3()
{
	long long int sec,min,hou,day,s;
	int mon,year;
	Time t1;
	t1.Show(3);
	cin>>year>>mon>>day>>hou>>min>>sec;
	t1.Set_time(sec,min,hou,day,mon,year);
	sec=t1.Get_sec();min=t1.Get_min();hou=t1.Get_hou();day=t1.Get_day();mon=t1.Get_mon();year=t1.Get_year();
	s=sec+min*60+hou*3600+(t1.Day_to_2020_1_1(day,mon,year))*86400;
	cout<<"请按年、月、日、时、分、秒的顺序输入后一个时间：";
	cin>>year>>mon>>day>>hou>>min>>sec;
	t1.Set_time(sec,min,hou,day,mon,year);
	sec=t1.Get_sec();min=t1.Get_min();hou=t1.Get_hou();day=t1.Get_day();mon=t1.Get_mon();year=t1.Get_year();
	s+=sec+min*60+hou*3600+(t1.Day_to_2020_1_1(day,mon,year))*86400+63745056000+63745056000;//63745056000为0年1月1日0:0:0至2020年1月1日0:0:0的秒数
	sec=s;min=s/60;hou=s/3600;day=s/86400;mon=s/2592000;year=s/31536000;
	cout<<"两者和为"<<sec<<"秒/"<<min<<"分/"<<hou<<"时/"<<day<<"天/"<<mon<<"月/"<<year<<"年"
		<<endl<<"（按30天=1月、365天=1年的进制计算，不足1的部分舍去）"
		<<endl<<"从0年1月1日0时0分0秒开始计算，这些时间可累计至（考虑闰年）：";
	t1.Set_time(sec,0,0,1,1,0);
	t1.Show(6);
}
void func4()
{
	int m,y;
	long long int d;
	cout<<"请按年、月、日的顺序输入需判断的日期：";
	cin>>y>>m>>d;
	Time T;
	T.Set_time(0,0,0,d,m,y);
	T.Show(4);
}
void func5()
{
	int y;
	cout<<"请输入需判断的年份：";
	cin>>y;
	if(Is_Leap_Year(y)) cout<<y<<"年是闰年。";
	else cout<<y<<"年不是闰年。";
}
void func6()
{
	long long int sec,min,hou,day;
	int mon,year;
	cout<<"请按年、月、日、时、分、秒的顺序输入时间：";
	cin>>year>>mon>>day>>hou>>min>>sec;
	Time t;
	t.Set_time(sec,min,hou,day,mon,year);
	t.Show(6);
}