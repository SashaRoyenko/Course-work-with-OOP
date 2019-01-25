#pragma once
#include<string>
#include<string.h>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class Discipline
{
private:
	string discipline_name;
	int total_hours, lecture_hours, practice_hours, self_hours;
public:
	Discipline();
	Discipline(string, int, int, int);// discipline_name total_hours, lecture_hours, practice_hours, self_hours;
	Discipline(const Discipline &);
	void settotal(int);
	void setlecture(int);
	void setpractice(int);
	void setself(int);
	void setDisciplineData();
	void setdisciplinename(string);
	void Show();
	string getdisciplinename();
	int gettotal();
	int getlecture();
	int getpractice();
	int getself();
	void writeInBinary(ostream &);
	void readFromBinary(istream &);
	friend ostream &operator << (ostream &, Discipline &);
	friend istream &operator >> (istream &, Discipline &);
	double operator[](int);
	int operator+(const Discipline& d);
	~Discipline();
};

