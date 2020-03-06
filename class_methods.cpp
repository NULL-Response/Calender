#include"class_definition.h"
#include"headers_and_prototypes.h"

extern int language;

long long int Time::Day_to_2020_1_1(const long long int &d,const int &m,const int &y) const//calculate the days to 2020.1.1, but y.m.d should have been trimmed
{//to transform y year. m month. d day to the form of 2020. 1. t day
	long long int t=0;
	if(y>=2020){
		for(int i=2020;i<y;i++){//to count 2020 to (y-1) year, each year into 365 or 366 days
			if(Is_Leap_Year(i)) t+=366;
			else t+=365;
		}
		t+=year_month(1,y,m,d);//for y. m. d, calculate days to y. 1. 1
	}
	else{//if y<2020, return a negative value
		for(int i=2019;i>y;i--){
			if(Is_Leap_Year(i)) t-=366;
			else t-=365;
		}
		t+=year_month(0,y,m,d);//for y. m. d, calculate days to y+1. 1. 1
	}
	return t;
}

void Time::day_mon_year(long long int &day,int &mon,int &year)//trim the excessive part of days and months
{
	long long int d=day;int m=mon,y=year;
	y+=m/12;m=m%12;if(m<=0) {m+=12;y--;}//first trim month into 1~12
	if(d>0){//if d>0,subtract from days and  add into years
		for(;d>366;){//when d is greater than 366, minus 365/366 each time for efficiency
			if((Is_Leap_Year(y)&&m<3)||(Is_Leap_Year(y+1)&&m>2)) d-=366;//only under these 2 conditions will it go through Feb. 29: when the next year is leap year and go through next year February, or this year is leap year and start from Jan of Feb
			else d-=365;
			y++;
		}
		for(;d>31;){//get the right d
			switch(m){
			case 2:if(Is_Leap_Year(y)) d-=29;else d-=28;m++;break;
			case 4:case 6:case 9:case 11:d-=30;m++;break;
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:d-=31;m++;break;
			}
			if(m>12) {m-=12;y++;}
		}
		//when d is 29, 30, or 30, discuss the situations
		if(d==29&&m==2&&!Is_Leap_Year(y)) {d-=28;m++;}
		else if(d==30&&m==2){
			if(Is_Leap_Year(y)) {d-=29;m++;}
			else {d-=28;m++;}
		}
		else if(d==31){
			if(m==2){
				if(Is_Leap_Year(y)) {d-=29;m++;}
				else {d-=28;m++;}
			}
			else if(m==4||m==6||m==9||m==11) {d-=30;m++;}
		}
	}
	else{//if d<=0,subtract from years and  add into days
		for(;d<-366;){
			if((Is_Leap_Year(y)&&m>2)||(Is_Leap_Year(y-1)&&m<3)) d+=366;//if this year is leap year and go through Feb, or last year is leap year and pass through last year Feb
			else d+=365;
			y--;
		}
		for(;d<1;){
			switch(m-1){
			case 2:if(Is_Leap_Year(y)) d+=29;else d+=28;m--;break;
			case 4:case 6:case 9:case 11:d+=30;m--;break;
			case 0:case 1:case 3:case 5:case 7:case 8:case 10:d+=31;m--;break;
			}
			if(m<1) {m+=12;y--;}
		}
	}
	day=d;mon=m;year=y;
}

long long int Time::year_month(const int &mode,const int &y,const int &month,const long long int &d) const//if mode!=0, return the days to y year January 1; if mode== 0, return the days to y+1 year January 1 (in negative form)
{
	int t=0,m=month;//t is the returned value
	//first, get the days from y. m. d to y. 1. 1
	for(m--;m>0;m--){//get the days from y. m. 1 to y. 1. 1
		switch(m){
			case 2:if(Is_Leap_Year(y)) t+=29;else t+=28;break;
			case 4:case 6:case 9:case 11:t+=30;break;
			case 1:case 3:case 5:case 7:case 8:case 10:t+=31;break;
		}
	}
	t+=d;t--;//minus 1 because of Jan 1
	//at this point, t is equivalent to the days from y. m. d to y. 1. 1
	if(mode==0){//if mode==0, calculate the days from y. m. d to y+1. 1. 1, in negative form
		if(Is_Leap_Year(y)) t-=366;
		else t-=365;
	}
	return t;
}

void Time::Set_week()//set the weekday of the object
{
	long long int d=Get_day();
	int m=Get_mon(),y=Get_year();
	long long int D=Day_to_2020_1_1(d,m,y)%7;//2020. 1. 1 is Wednesday
	if(D<0) D+=7;
	week=(3+D)%7;
	if(week==0) week+=7;
}

void Time::Show(const int &mode) const//show the content of the object, according to the mode
{//the number of mode is linked to the functions of the program
    using std::cout;
    using std::endl;
	if(mode==1){
		if(language==0) cout<<"\n一\t二\t三\t四\t五\t六\t七\n";
		else if(language==1) cout<<"\nMon\tTue\tWed\tThur\tFri\tSat\tSun\n";
	}
	else if(mode==2){
		if(language==0)  cout<<"若输入的时间超出范围，程序将先转换为规范格式再二者相减，结果与先相减再转换可能不同。"<<endl
                                            <<"显示格式为前者-后者，负代表前者时间小于后者。若需更准确的结果，请使用功能6；"<<endl
                                            <<"请按年、月、日、时、分、秒的顺序输入前一个时间：";
        else if(language==1)   cout<<"if the input time is out of range, it will first be trimmed. The result may differ from that first subtracts."<<endl
                                                    <<"The result is the former minus the later, negative numbers indicate the later is greater. For precision, use function 6 instead."<<endl
                                                    <<"Input the former time in the sequence of year, month, date, hour, minute, second:";
	}
	else if(mode==3)
	{
		if(language==0)  cout<<"若输入的时间超出范围，程序将先转换为规范格式再二者相加，结果与先相加再转换可能不同。"<<endl
                                            <<"此处的1年=365天，1月=30天。若需更准确的结果，请使用功能6；"<<endl
                                            <<"请按年、月、日、时、分、秒的顺序输入前一个时间：";
        else if(language==1)   cout<<"if the input time is out of range, it will first be trimmed. The result may differ from that first added."<<endl
                                                    <<"Here 1 year equals 365 days, and 1 month equals 30 days. For precision, use function 6 instead."<<endl
                                                    <<"Input the former time in the sequence of year, month, date, hour, minute, second:";
	}
	else if(mode==4)
	{
		if(language==0) {cout<<year<<"年"<<mon<<"月"<<day<<"日 是星期";Show_week();cout<<"。";}
		else if(language==1) {cout<<year<<" year "<<mon<<" month "<<day<<" date  is ";Show_week();cout<<".";}
	}
	else if(mode==5)
	{
		//no function needed
	}
	else if(mode==6)
	{
		if(language==0) {cout<<year<<"年"<<mon<<"月"<<day<<"日"<<hou<<"时"<<min<<"分"<<sec<<"秒\t星期";Show_week();}
		else if(language==1) {cout<<year<<" year "<<mon<<" month "<<day<<" date "<<hou<<" : "<<min<<" : "<<sec<<"\t";Show_week();}
	}
}

void Time::Show_week() const//show the single Chinese character of the weekday
{
    using std::cout;
    if(language==0){
        switch(week){
            case 1:cout<<"一";break;
            case 2:cout<<"二";break;
            case 3:cout<<"三";break;
            case 4:cout<<"四";break;
            case 5:cout<<"五";break;
            case 6:cout<<"六";break;
            case 7:cout<<"七";break;
        }
    }
    else if(language==1){
        switch(week){
            case 1:cout<<"Monday";break;
            case 2:cout<<"Tuesday";break;
            case 3:cout<<"Wednesday";break;
            case 4:cout<<"Thursday";break;
            case 5:cout<<"Friday";break;
            case 6:cout<<"Saturday";break;
            case 7:cout<<"Sunday";break;
        }
    }
}
