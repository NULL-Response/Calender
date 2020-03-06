#ifndef CLASS_DEFINITION_H_INCLUDED
#define CLASS_DEFINITION_H_INCLUDED

class Time
{
		long long int sec,min,hou,day;
		int week,mon,year;
	public:
		Time(){}
		void Set_time(long long int sec,long long int min,long long int hou,long long int day,int mon,int year)
		{//before statistics writing, trim and figure out weekday
			min+=sec/60;sec=sec%60;if(sec<0) {sec+=60;min--;}Set_sec(sec);
			hou+=min/60;min=min%60;if(min<0) {min+=60;hou--;}Set_min(min);
			day+=hou/24;hou=hou%24;if(hou<0) {hou+=24;day--;}Set_hou(hou);
			day_mon_year(day,mon,year);//trim the excessive part of days and month
			Set_day(day);Set_mon(mon);Set_year(year);
			Set_week();//figure out weekday
		}
		long long int Day_to_2020_1_1(const long long int &d,const int &m,const int &y) const;//calculate the days to 2020.1.1, but y.m.d should have been trimmed
		void day_mon_year(long long int &day,int &mon,int &year);//trim the excessive part of days and months
		long long int year_month(const int &mode,const int &y,const int &month,const long long int &d) const;//if mode!=0, return the days to y year January 1; if mode== 0, return the days to y+1 year January 1 (in negative form)
		void Set_sec(const long long int &sec){this->sec=sec;}long long int Get_sec(){return sec;}
		void Set_min(const long long int &min){this->min=min;}long long int Get_min(){return min;}
		void Set_hou(const long long int &hou){this->hou=hou;}long long int Get_hou(){return hou;}
		void Set_day(const long long int &day){this->day=day;}long long int Get_day(){return day;}
		void Set_mon(const int &mon){this->mon=mon;}int Get_mon(){return mon;}
		void Set_year(const int &year){this->year=year;}int Get_year(){return year;}
		void Set_week();//set the weekday of the object
		int Get_week(){return week;}
		void Show(const int &mode) const;//show the content of the object, according to the mode
		void Show_week() const;//show the single Chinese character of the weekday
		~Time(){}
};

#endif // CLASS_DEFINITION_H_INCLUDED
