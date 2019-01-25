#include "Person.h"
Person::Person()
{
	person_name = "Name";
	person_surname = "Surname";
}

Person::Person(string n, string s, int d, int m, int y)
{
	person_name = n;
	person_surname = s;
	Birth.setDay(d);
	Birth.setMonth(m);
	Birth.SetYear(y);
}

Person::Person(Person & p)
{
	person_name = p.person_name;
	person_surname = p.person_surname;
	Birth = p.Birth;
}

void Person::setName(string nam) {
	person_name = nam;
}

void Person::setSurname(string snam) {
	person_surname = snam;
}

void Person::setPersonData() {
	do {
		printf("Enter person name (to 20 symbols): ");
		cin.ignore();
		getline(cin, person_name);
	} while (person_name.length() > 20);

	do {
		printf("Enter person surname (to 20 symbols): ");
		getline(cin, person_surname);
	} while (person_surname.length() > 20);
	Birth.setDate();
}

void Person::setDay(int d)
{
	Birth.setDay(d);
}

void Person::setMonth(int m)
{
	Birth.setMonth(m);
}

void Person::SetYear(int y)
{
	Birth.SetYear(y);
}

int Person::getday()
{
	return Birth.getday();
}

int Person::getmonth()
{
	return Birth.getmonth();
}

int Person::getyear()
{
	return Birth.getyear();;
}

string Person::getPersonName() {
	return person_name;
}

string Person::getPersonSurname() {
	return person_surname;
}

void Person::Show()
{
	cout << "Name: " << getPersonName() << endl;
	cout << "Surname: " << getPersonSurname() << endl;
	cout << "Date of birth: ";
	Birth.Show();
}

Person::~Person()
{
}
