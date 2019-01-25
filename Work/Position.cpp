#include "Position.h"

Position::Position()
{
	pos = teacher;
}

Position::Position(position p)
{
	pos = (int)p > 0 && (int)p <= 5 ? p : assistant;
}

Position::Position(Position & p)
{
	pos = p.getposition();
}

void Position::setposition(position p) {
	pos = (int)p > 0 && (int)p <= 5 ? p : assistant;
}

void Position::setposition(int p) {
	switch (p) {
	case 1:
		pos = assistant;
		break;
	case 2:
		pos = teacher;
		break;
	case 3:
		pos = senior_lecturer;
		break;
	case 4:
		pos = docent;
		break;
	case 5:
		pos = professor;
		break;
	}
}

void Position::setposition() {
	int res, answ;
	do {
		printf("\n\tEnter 1 to choose Assistant\n");
		printf("\tEnter 2 to choose Lecture\n");
		printf("\tEnter 3 to choose Senior Lecture\n");
		printf("\tEnter 4 to choose Docent\n");
		printf("\tEnter 5 to choose Professor\n");
		printf("\t\nEnter answer: ");
		res = scanf("%d", &answ);
		while (getchar() != '\n');
	} while (res != 1 || answ < 1 || answ > 5);
	switch(answ) {
		case 1:
			pos = assistant;
			break;
		case 2:
			pos = teacher;
			break;
		case 3:
			pos = senior_lecturer;
			break;
		case 4:
			pos = docent;
			break;
		case 5:
			pos = professor;
			break;
	}
}

void Position::Show()
{
	cout << "Position: ";
	switch (pos) {
	case 1:
		cout << "Assistant";
		break;
	case 2:
		cout << "Lecture";
		break;
	case 3:
		cout << "Senior Lecture";
		break;
	case 4:
		cout << "Docent";
		break;
	case 5:
		cout << "Professor";
		break;
	}
}

position Position::getposition(){
	return pos;
}

Position::~Position()
{
}
