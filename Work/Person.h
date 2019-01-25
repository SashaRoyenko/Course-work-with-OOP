#pragma once
#include<string>
#include<iostream>
#include"Date.h"
using namespace std;
class Person
{
private:
	string person_name, person_surname;
	Date Birth;
public:
	Person();
	Person(string, string, int, int, int);
	Person(Person &);
	void setName(string);
	void setSurname(string);
	void setPersonData();
	void setDay(int d);
	void setMonth(int m);
	void SetYear(int y);
	int getday();
	int getmonth();
	int getyear();
	string getPersonName();
	string getPersonSurname();
	virtual void Show();
	~Person();
};

