#pragma once
#include<iostream>
using namespace std;
class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(int,int,int);
	Date(const Date&);
	void setDay(int d);
	void setMonth(int m);
	void SetYear(int y);
	void setDate();
	void Show();
	int getday();
	int getmonth();
	int getyear();
	~Date();
};
