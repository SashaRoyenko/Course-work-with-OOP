#include"Date.h"
#include<conio.h>
#include <stdio.h>
Date::Date()
{
	day = 1;
	month = 1;
	year = 2018;
}

Date::Date(int d, int m, int y)
{
	day = (d > 0 && d <= 31) ? d : 1;
	month =(m <= 12 && m > 0) ? m : 1;
	year = (y < 1920 && y > 2019 ) ? y : 2000;
}

Date::Date(const Date &d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}

void Date::setDay(int d)
{
	day = (d > 0 && d <= 31) ? d : 1;
}

void Date::setMonth(int m)
{
	month = (m <= 12 && m > 0) ? m : 1;
}

void Date::SetYear(int y)
{
	year = (y < 1920 && y > 2019) ? y : 2000;
}

void Date::setDate() {
	int res;
	do {
		printf("Enter day: ");
		res = scanf("%d", &day);
		while (getchar() != '\n');
	} while (res != 1 || day < 1 || day > 31);

	do {
		printf("Enter month: ");
		res = scanf("%d", &month);
		while (getchar() != '\n');
	} while (res != 1 || month < 1 || month > 12);

	do {
		printf("Enter year (from 1920 to 2018): ");
		res = scanf("%d", &year);
		while (getchar() != '\n');
	} while (res != 1 || year < 1920 || year > 2019);
}
void Date::Show()
{
	cout << day << "." << month << "." << year << endl;
}
int Date::getday() {
	return day;
}
int Date::getmonth() {
	return month;
}
int Date::getyear() {
	return year;
}
Date::~Date()
{
}
