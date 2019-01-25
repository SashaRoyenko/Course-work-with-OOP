#pragma once
#include"Teacher.h"
#include"Discipline.h"
#include<fstream>
class TeachingLoad
{
private:
	Teacher* TchList;
	Discipline* DspList;
	int Tsize, Dsize;
public:
	TeachingLoad();
	TeachingLoad(Teacher[], int, Discipline[], int);
	TeachingLoad(TeachingLoad&);
	void setDisciplines(Discipline[], int);
	void setTeachers(Teacher[], int);
	void setData();
	string getFileRoot();
	int getDisciplineSize();
	int getTeacherSize();
	void ShowDisciplineTable();
	void ShowTeacherTable();
	void writeInFile();
	void readFromFile();
	void writeInBinary();
	void ReadFromBinary();
	void getByTeacherName();
	void getByTeacherSurname();
	void getByTeacherDate();
	void getByDisciplineName();
	void Show();
	double operator[](int);
	double  GetAvarageLectureToTotal();
	Discipline *getDiscipline();
	~TeachingLoad();
};

