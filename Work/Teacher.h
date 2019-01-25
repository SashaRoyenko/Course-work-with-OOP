#pragma once
#include"Position.h"
#include"Person.h"
#include"Discipline.h"
class Teacher : public Person, public Position
{
private:
	int size;
	Discipline * DisciplineList;
public:
	Teacher();
	Teacher(string, string, int, int, int, position, Discipline[], int);
	Teacher(Teacher &);
	void Show();
	void setTeacherData(Discipline[], int);
	void setTeacherData();
	void setTeacherDisciplines(Discipline*, int);
	void setsize(int);
	void writeInBinary(ostream&);
	void readFromBinary(istream&);
	int getsize();
	Discipline* getTeacherDisciplines();
	friend ostream &operator << (ostream &, Teacher &);
	friend istream &operator >> (istream &, Teacher &);
	~Teacher();
};

