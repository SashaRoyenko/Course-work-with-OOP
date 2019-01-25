#include "Teacher.h"

Teacher::Teacher()
{
	size = 0;
	DisciplineList = new Discipline[0];
}

Teacher::Teacher(string nm, string sm, int bd, int bm, int by, position pos, Discipline ds[], int sz)
: Person(nm, sm, bd, bm, by), Position(pos)
{
	size = sz > 0 ? sz : 0;
	DisciplineList = new Discipline[size];
	for (int i(0); i < size; i++) {
		DisciplineList[i] = ds[i];
	}
}

Teacher::Teacher(Teacher & T)
{
	*this = T;
	DisciplineList = new Discipline[size];
	for (int i = 0; i < size; i++)
	{
		DisciplineList[i] = T.DisciplineList[i];
	}
}

void Teacher::setTeacherData(Discipline Ds[], int size) {
	DisciplineList = new Discipline[size];
	for (int i = 0; i < size; i++)
	{
		DisciplineList[i] = Ds[i];
	}
}

void Teacher::setTeacherData() {
	setPersonData();
	setposition();
	int res;
	do {
		size++;
		Discipline *temp = new Discipline[size + 1];
		for (int i(0); i < size - 1; i++) {
			temp[i] = DisciplineList[i];
		}
		temp[size - 1].setDisciplineData();
		DisciplineList = temp;
	
		do {
			while (getchar() != '\n');
			cout << "\nContinue enter discipline? (1 - yes, 0 - no): ";
		} while (scanf("%d", &res) != 1 || res < 0 || res > 1);

	} while (res != 0);
}

void Teacher::writeInBinary(ostream & stream)
{
	stream.write((char *)this, sizeof(Teacher));
	for (int i(0); i < size; i++) {
		DisciplineList[i].writeInBinary(stream);
	}
}

void Teacher::readFromBinary(istream & stream)
{
	stream.read((char *)this, sizeof(Teacher));
	DisciplineList = new Discipline[size];
	for (int i(0); i < size; i++) {
		DisciplineList[i].readFromBinary(stream);
	}
}

void Teacher::setsize(int sz)
{
	size = sz > 0 ? sz : 0;
}

int Teacher::getsize()
{
	return size;
}

Discipline * Teacher::getTeacherDisciplines()
{
	return DisciplineList;
}

void Teacher::setTeacherDisciplines(Discipline *ds, int sz)
{
	size = sz > 0 ? sz : 0;
	DisciplineList = new Discipline[size];
	for (int i(0); i < size; i++) {
		DisciplineList[i] = ds[i];
	}
}

void Teacher::Show()
{	
	cout << char(0xC9);
	for (int i(0); i < 58; i++) {
		cout << char(0xCD);
	}
	cout << char(0xBB) << endl;
	cout << char(0xBA) << setw(31) << "Teacher" << setw(28) << char(0xBA);
	cout << endl << char(0xCC);
	for (int i(0); i < 58; i++) {
		if (i == 12 || i == 24 || i == 40) {
			cout << char(0xCB);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xB9) << endl;
	cout << char(0xBA) << setw(7) << "Name" << setw(6) << char(0xBA)
		<< setw(9) << "Surname" << setw(3) << char(0xBA)
		<< setw(14) << "Date of birth" << setw(2) << char(0xBA)
		<< setw(14) << "Position" << setw(4) << char(0xBA);
	

	cout << endl << char(0xCC);
	for (int i(0); i < 58; i++) {
		if (i == 12 || i == 24 || i == 40) {
			cout << char(0xCE);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xB9) << endl;
	cout << char(0xBA) << setw(7) << getPersonName() << setw(6) << char(0xBA)
		<< setw(9) << getPersonSurname() << setw(3) << char(0xBA)
		<< setw(5) << getday() << "." << getmonth() << "." << getyear() << setw(4) << char(0xBA)
		<< setw(16);
				switch (getposition()) {
				case 1:
					cout << "Assistant";
					break;
				case 2:
					cout << "Lecturer";
					break;
				case 3:
					cout << "Senior Lecturer";
					break;
				case 4:
					cout << "Docent";
					break;
				case 5:
					cout << "Professor";
					break;
				}
			cout << setw(2) << char(0xBA);
			
	cout << endl << char(0xC8);
	for (int i(0); i < 58; i++) {
		if (i == 12 || i == 24 || i == 40) {
			cout << char(0xCA);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xBC) << endl;

	cout << endl << char(0xC9);
	for (int i(0); i < 58; i++) {
		cout << char(0xCD);
	}
	cout << char(0xBB) << endl;
	
	cout << char(0xBA) << setw(40) << "Teacher Disciplines" << setw(19) << char(0xBA);

	cout << endl << char(0xC8);
	for (int i(0); i < 58; i++) {
		cout << char(0xCD);
	}
	cout << char(0xBC) << endl;
	for (int i(0); i < size; i++) {
		DisciplineList[i].Show();
	}
}

Teacher::~Teacher()
{
	delete[] DisciplineList;
}

ostream & operator<<(ostream & stream, Teacher & t)
{
		int size = t.getsize();
		stream << "Teacher" << endl;
		stream << t.getPersonName() << endl;
		stream << t.getPersonSurname() << endl;
		stream << t.getday() << "\n" << t.getmonth() << "\n" << t.getyear() << endl;
		stream << t.getposition() << endl<<endl;
		for (int i(0); i < size; i++) {
			stream << t.getTeacherDisciplines()[i];
			if (i < size - 1) {
				stream << endl;
			}
		}
		return stream;
}

istream & operator>>(istream & stream, Teacher &t)
{
	string res;
	getline(stream, res);
	t.setName(res);
	getline(stream, res);
	t.setSurname(res);
	getline(stream, res);
	t.setDay(atoi(res.c_str()));
	getline(stream, res);
	t.setMonth(atoi(res.c_str()));
	getline(stream, res);
	t.SetYear(atoi(res.c_str()));
	getline(stream, res);
	t.setposition(atoi(res.c_str()));
	getline(stream, res);
	int size = 0;
	while(true){
		size++;
		Discipline *temp = new Discipline[size + 1];
		for (int i(0); i < size - 1; i++) {
			temp[i] = t.getTeacherDisciplines()[i];
		}
		stream >> temp[size - 1];
		t.setTeacherDisciplines(temp, size);
		getline(stream, res);
		if (res == "Teacher" || res == "Cathedra Discipline" || res == "*****") {
			break;
		}
	}
	t.setsize(size);
	return stream;
}
