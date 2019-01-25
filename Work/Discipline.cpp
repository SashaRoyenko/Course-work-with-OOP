#include "Discipline.h"
#include<string>
Discipline::Discipline()
{
	discipline_name = "Discipline";
	total_hours = 100;
	lecture_hours = 60;
	practice_hours = 20;
	self_hours = total_hours - lecture_hours - practice_hours;
}

Discipline::Discipline(string dn, int th, int lh, int ph)
{
	discipline_name = dn;
	total_hours = th > 0 ? th : 0;
	lecture_hours = lh > 0 && lh < th ? lh : 0;
	practice_hours = ph > 0 && ph < th - lh ? ph : 0;
}

Discipline::Discipline(const Discipline & ds)
{
	discipline_name = ds.discipline_name;
	total_hours = ds.total_hours;
	lecture_hours = ds.lecture_hours;
	practice_hours = ds.practice_hours;
	self_hours = ds.total_hours - ds.lecture_hours - ds.practice_hours;
}

void Discipline::settotal(int th) {
	total_hours = th > 0 ? th : 0;
}

void Discipline::setlecture(int lh) {
	lecture_hours = lh > 0 && lh < total_hours ? lh : 0;
}

void Discipline::setpractice(int ph) {
	practice_hours = ph > 0 && ph < total_hours - lecture_hours ? ph : 0;
}

void Discipline::setself(int self)
{
	self_hours = self > 0 && self < total_hours - practice_hours - lecture_hours ? self : 0;
}

void Discipline::setDisciplineData() {
	do {
		printf("\nEnter discipline name (to 20 symbols): ");
		cin >> discipline_name;
	} while (discipline_name.length() > 20);
	do {
		while (getchar() != '\n');
		printf("Enter total hours: ");
	} while (scanf("%d", &total_hours) != 1 || total_hours < 0 || total_hours > 300);
	do {
		while (getchar() != '\n');
		printf("Enter lecture hours: ");
	} while (scanf("%d", &lecture_hours) != 1 || lecture_hours < 0 || lecture_hours > 300 || lecture_hours > total_hours);
	do {
		while (getchar() != '\n');
		printf("Enter practice hours: ");
	} while (scanf("%d", &practice_hours) != 1 || practice_hours < 0 || practice_hours > 300 || practice_hours > total_hours - lecture_hours);
	self_hours = getself();
}

void Discipline::setdisciplinename(string s)
{
	discipline_name = s;
}

string  Discipline::getdisciplinename() {
	return discipline_name;
}

int Discipline::gettotal() {
	return total_hours;
}

int  Discipline::getlecture() {
	return lecture_hours;
}

int  Discipline::getpractice() {
	return practice_hours;
}

int  Discipline::getself() {
	self_hours = total_hours - lecture_hours - practice_hours;
	return self_hours;
}

void Discipline::writeInBinary(ostream & stream)
{
	stream.write((char *)this, sizeof(Discipline));
}

void Discipline::readFromBinary(istream & stream)
{
	stream.read((char *)this, sizeof(Discipline));
}

void Discipline::Show()
{
	cout << char(0xC9);
	for (int i(0); i < 62; i++) {
		cout << char(0xCD);
	}
	cout << char(0xBB) << endl;
	cout << char(0xBA);
	cout << setw(36) << "Discipline" << setw(27);
	cout << char(0xBA);
	cout << endl << char(0xCC);
	for (int i(0); i < 62; i++) {
		if (i == 19 || i == 31 || i == 44 || i == 53) {
			cout << char(0xCB);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xB9) << endl;

	cout << char(0xBA) << setw(17) << "Name of subject" << setw(3) << char(0xBA)
		<< setw(9) << "Lecture" << setw(3) << char(0xBA)
		<< setw(11) << "Practice" << setw(2) << char(0xBA)
		<< setw(6) << "Self" << setw(3) << char(0xBA)
		<< setw(6) << "Total" << setw(3) << char(0xBA);

	cout << endl << char(0xCC);
	for (int i(0); i < 62; i++) {
		if (i == 19 || i == 31 || i == 44 || i == 53) {
			cout << char(0xCE);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xB9) << endl;

	cout << char(0xBA) << setw(17) << getdisciplinename() << setw(3) << char(0xBA)
		<< setw(9) << getlecture() << setw(3) << char(0xBA)
		<< setw(11) << getpractice() << setw(2) << char(0xBA)
		<< setw(6) << getself() << setw(3) << char(0xBA)
		<< setw(6) << gettotal() << setw(3) << char(0xBA);

	cout << endl << char(0xC8);
	for (int i(0); i < 62; i++) {
		if (i == 19 || i == 31 || i == 44 || i == 53) {
			cout << char(0xCA);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xBC) << endl;
}

double Discipline::operator[](int)
{
		return total_hours;
}

int Discipline::operator+(const Discipline & d)
{
	return total_hours + d.total_hours;
}

Discipline::~Discipline()
{
}

ostream & operator<<(ostream & stream, Discipline & d)
{
		stream << d.getdisciplinename() << endl;
		stream << d.gettotal() << endl;
		stream << d.getlecture() << endl;
		stream << d.getpractice() << endl;
		stream << d.getself() << endl;
		return stream;
}

istream & operator>>(istream & stream, Discipline & d)
{
	string res;
	getline(stream, res);
	d.setdisciplinename(res);
	getline(stream, res);
	d.settotal(atoi(res.c_str()));
	getline(stream, res);
	d.setlecture(atoi(res.c_str()));
	getline(stream, res);
	d.setpractice(atoi(res.c_str()));
	getline(stream, res);
	return stream;
}