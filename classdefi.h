#ifndef CLASSDEFI_H_INCLUDED
#define CLASSDEFI_H_INCLUDED

//class definition
class Time
{
		long long int sec,min,hou,day;
		int week,mon,year;
	public:
		Time(){}
		void Set_time(long long int sec,long long int min,long long int hou,long long int day,int mon,int year)
		{//录入数据前先标准化数据，并求出星期几
			min+=sec/60;sec=sec%60;if(sec<0) {sec+=60;min--;}Set_sec(sec);
			hou+=min/60;min=min%60;if(min<0) {min+=60;hou--;}Set_min(min);
			day+=hou/24;hou=hou%24;if(hou<0) {hou+=24;day--;}Set_hou(hou);
			day_mon_year(&day,&mon,&year);//将day，mon超出界限的部分转换
			Set_day(day);Set_mon(mon);Set_year(year);Set_week();
		}
		long long int Day_to_2020_1_1(long long int d,int m,int y);
		void day_mon_year(long long int *day,int *mon,int *year);
		long long int year_month(int mode,int y,int m,long long int d);
		void Set_sec(long long int sec){this->sec=sec;}long long int Get_sec(){return sec;}
		void Set_min(long long int min){this->min=min;}long long int Get_min(){return min;}
		void Set_hou(long long int hou){this->hou=hou;}long long int Get_hou(){return hou;}
		void Set_day(long long int day){this->day=day;}long long int Get_day(){return day;}
		void Set_mon(int mon){this->mon=mon;}int Get_mon(){return mon;}
		void Set_year(int year){this->year=year;}int Get_year(){return year;}
		void Set_week();int Get_week(){return week;}
		void Show(int mode);void Show_week();
		~Time(){}
};

#endif // CLASSDEFI_H_INCLUDED