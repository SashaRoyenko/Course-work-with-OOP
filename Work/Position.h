#pragma once
#include <stdio.h>
#include <windows.h>
#include<iostream>
using namespace std;
enum position { assistant = 1, teacher, senior_lecturer, docent, professor };
class Position
{
private:
	position pos;
public:
	Position();
	Position(position);
	Position(Position&);
	void setposition(position);
	void setposition(int);
	void setposition();
	virtual void Show();
	position getposition();
	~Position();
};

