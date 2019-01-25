#include "TeachingLoad.h"
#include <iomanip>

TeachingLoad::TeachingLoad()
{
	Tsize = 0;
	Dsize = 0;
	TchList = new Teacher[0];
	DspList = new Discipline[0];
}
TeachingLoad::TeachingLoad(Teacher tch[], int szt, Discipline ds[], int szd)
{
	Tsize = szt;
	Dsize = szd;
	DspList = new Discipline[Dsize];
	TchList = new Teacher[Tsize];
	for (int i(0); i < Dsize; i++) {
		DspList[i] = ds[i];
	}
	for (int i(0); i < Tsize; i++) {
		TchList[i] = tch[i];
	}
}
TeachingLoad::TeachingLoad(TeachingLoad & TL)
{
	*this = TL;
	DspList = new Discipline[Dsize];
	for (int i = 0; i < Dsize; i++)
	{
		DspList[i] = TL.DspList[i];
	}

	TchList = new Teacher[Tsize];
	for (int i(0); i < Tsize; i++) {
		TchList[i] = TL.TchList[i];
	}
}
void TeachingLoad::setDisciplines(Discipline Ds[], int Dsize) {
	DspList = new Discipline[Dsize];
	for (int i(0); i < Dsize; i++) {
		DspList[i] = Ds[i];
	}
}
void TeachingLoad::setTeachers(Teacher Tch[], int Tsize) {
	TchList = new Teacher[Tsize];
	for (int i(0); i < Tsize; i++) {
		TchList[i] = Tch[i];
	}
}
string TeachingLoad::getFileRoot()
{
	string file_name;
	cout << "Enter file root: ";
	fflush(stdin);
	cin >> file_name;
	return file_name;
}
void TeachingLoad::ShowDisciplineTable()
{
	cout << char(0xC9);
	for (int i(0); i < 53; i++) {
		cout << char(0xCD);
	}
	cout << char(0xBB) <<endl;
	cout << char(0xBA);
	cout << setw(37) << "Cathedra Disciplines" << setw(17);
	cout << char(0xBA);
	cout << endl << char(0xCC);
	for (int i(0); i < 53; i++) {
		if (i == 19 || i == 31 || i == 44) {
			cout << char(0xCB);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xB9) << endl;
	cout << char(0xBA);
	for (int i(0); i < 8; i++) {
		cout << "  ";
		if (i == 0) {
			cout << "Name of subject";
		}
		if (i == 1 || i == 3 || i == 5 || i == 7) {
			cout << char(0xBA);
		}
		if (i == 2) {
			cout << "Lecture";
		}
		if (i == 4) {
			cout << "Practice";
		}
		if (i == 6) {
			cout << "Self";
		}
	}

	cout << endl << char(0xCC);
	for (int i(0); i < 53; i++) {
		if (i == 19 || i == 31 || i == 44) {
			cout << char(0xCE);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xB9) << endl;

	for (int k(0); k < Dsize; k++) {
		cout << char(0xBA);
		for (int i(0); i < 8; i++) {
			cout << "  ";
			if (i == 0) {
				cout << setw(15) << DspList[k].getdisciplinename();
			}
			if (i == 1 || i == 3 || i == 5 || i == 7) {
				cout << char(0xBA);
			}
			if (i == 2) {
				cout << setw(7) << DspList[k].getlecture();
			}
			if (i == 4) {
				cout << setw(8) << DspList[k].getpractice();
			}
			if (i == 6) {
				cout << setw(4) << DspList[k].getself();
			}
			if (i == 7 && k < Dsize - 1) {
				cout << endl << char(0xCC);
				for (int i(0); i < 53; i++) {
					if (i == 19 || i == 31 || i == 44) {
						cout << char(0xCE);
					}
					else {
						cout << char(0xCD);
					}
				}
				cout << char(0xB9) << endl;
			}
		}
	}
	if (Dsize != 0) {
		cout << endl << char(0xC8);
	}
	else {
		cout << char(0xC8);
	}
	for (int i(0); i < 53; i++) {
		if (i == 19 || i == 31 || i == 44) {
			cout << char(0xCA);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xBC) << endl;
}
void TeachingLoad::ShowTeacherTable() 
{
	cout << char(0xC9);
	for (int i(0); i < 70; i++) {
			cout << char(0xCD);
	}
	cout << char(0xBB) << endl;
	cout << char(0xBA);
	cout << setw(35) << "Teachers" << setw(36);
	cout << char(0xBA);
	cout << endl << char(0xCC);
	for (int i(0); i < 70; i++) {
		if (i == 12 || i == 24 || i == 40) {
			cout << char(0xCB);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xBA) << endl;
	cout << char(0xBA);
	for (int i(0); i < 8; i++) {
		if (i == 0) {
			cout << setw(12) << "Name";
		}
		if (i == 1 || i == 3 || i == 5 || i == 7) {
			cout << char(0xBA);
		}
		if (i == 2) {
			cout << setw(11) << "Surname";
		}
		if (i == 4) {
			cout << setw(15) << "Position";
		}
		if (i == 6) {
			cout << setw(29) << "Disciplines";
		}
	}

	cout << endl << char(0xCC);
	for (int i(0); i < 70; i++) {
		if (i == 12 || i == 24 || i == 40) {
			cout << char(0xCE);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xB9) << endl;

	for (int k(0); k < Tsize; k++) {
		cout << char(0xBA);
		for (int i(0); i < 8; i++) {
			if (i == 0) {
				cout << setw(7) << TchList[k].getPersonName() << setw(6);
			}
			if (i == 1 || i == 3 || i == 5 || i == 7) {
				cout << char(0xBA);
			}
			if (i == 2) {
				cout << setw(11) << TchList[k].getPersonSurname();
			}
			if (i == 4) {
				switch (TchList[k].getposition()) {
				case 1:
					cout << setw(15) << "Assistant";
					break;
				case 2:
					cout << setw(15) << "Lecturer";
					break;
				case 3:
					cout << setw(15) << "Senior Lecturer";
					break;
				case 4:
					cout << setw(15) << "Docent";
					break;
				case 5:
					cout << setw(15) << "Professor";
					break;
				}
			}
			if (i == 6) {
				if (TchList[k].getsize() == 0) {
					cout << setw(30);
				}
				else {
					for (int l(0); l < TchList[k].getsize(); l++) {
						
						cout << setw(20 / TchList[k].getsize()) << TchList[k].getTeacherDisciplines()[l].getdisciplinename() << setw(10);
					}
				}
			}

			if (i == 7 && k < Tsize - 1) {
				cout << endl << char(0xCC);
				for (int i(0); i < 70; i++) {
					if (i == 12 || i == 24 || i == 40) {
						cout << char(0xCE);
					}
					else {
						cout << char(0xCD);
					}
				}
				cout << char(0xB9) << endl;
			}
		}
	}

	if (Tsize != 0) {
		cout << endl << char(0xC8);
	}
	else {
		cout << char(0xC8);
	}

	for (int i(0); i < 70; i++) {
		if (i == 12 || i == 24 || i == 40) {
			cout << char(0xCA);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xBC) << endl;
}
void TeachingLoad::writeInFile()
{
	fstream file;
	string name;
	do {
		name = getFileRoot() + ".txt";
		file.open(name, ios::out | ios::in | ios::app);
		if (!file) {
			cout << "File can't be open, try again!\n";
			cout << "Enter '-1' to return to menu\n";
		}
		else {
			break;
		}
	} while (name != "-1.bin");
	try {
		for (int i(0); i < Dsize; i++) {
			file << "Cathedra Discipline\n";
			file << DspList[i];
			file << endl;
		}
		for (int i(0); i < Tsize; i++) {
			file << TchList[i];
			file << "*****\n";
		}
	}
	catch(...) {
		cout << "Error!\n";
	}
	file.close();
}
void TeachingLoad::readFromFile()
{
	fstream file;
	string name, res;
	do {
		name = getFileRoot() + ".txt";
		file.open(name, ios::in);
		if (!file) {
			cout << "File can't be open, try again!\n";
			cout << "Enter '-1' to return to menu\n";
		}
		else {
			break;
		}
	} while (name != "-1.bin");
	Dsize = Tsize = 0;
	while(!file.eof()) {
		getline(file, res);
		if (res == "Cathedra Discipline") {
			Dsize++;
			Discipline *temp = new Discipline[Dsize + 1];
			for (int i(0); i < Dsize - 1; i++) {
				temp[i] = DspList[i];
			}
			file >> temp[Dsize - 1];
			DspList = temp;
		}
		if (res == "Teacher") {
			Tsize++;
			Teacher *temp = new Teacher[Tsize + 1];
			for (int i(0); i < Tsize - 1; i++) {
				temp[i] = TchList[i];
			}
			file >> temp[Tsize - 1];
			TchList = temp;
		}
	}
}
void TeachingLoad::writeInBinary()
{
	fstream file;
	string name;
	do {
		name = getFileRoot() + ".bin";
		file.open(name, ios::out | ios::binary);
		if (!file) {
			cout << "File can't be open, try again!\n";
			cout << "Enter '-1' to return to menu\n";
		}
		else {
			break;
		}
	} while (name != "-1.bin");
	try {
		file.write((char*)&Dsize, sizeof(Dsize));
		for (int i(0); i < Dsize; i++) {
			DspList[i].writeInBinary(file);
		}
		file.write((char*)&Tsize, sizeof(Tsize));
		for (int i(0); i < Tsize; i++) {
			TchList[i].writeInBinary(file);
		}
	}
	catch (...) {
		cout << "Error!\n";
	}
	file.close();
}
void TeachingLoad::ReadFromBinary()
{
	fstream file;
	string name;
	do {
		name = getFileRoot() + ".bin";
		file.open(name, ios::in | ios::binary);
		if (!file) {
			cout << "File can't be open, try again!\n";
			cout << "Enter '-1' to return to menu\n";
		}
		else {
			break;
		}
	} while (name != "-1.bin");
	try {
		Dsize = 0;
		file.read((char *)&Dsize, sizeof(Dsize));
		DspList = new Discipline[Dsize];
		for (int i(0); i < Dsize; i++) {
			DspList[i].readFromBinary(file);
		}
		Tsize = 0;
		file.read((char *)&Tsize, sizeof(Tsize));
		TchList = new Teacher[Tsize];
		for (int i(0); i < Tsize; i++) {
			TchList[i].readFromBinary(file);
		}
	}
	catch (...) {
		cout << "Error!\n";
	}
	file.close();
}
void TeachingLoad::getByTeacherName()
{
	string search_name;
	bool flag = false;
	cout << "Enter Teacher name: ";
	fflush(stdin);
	cin >> search_name;
	for (int i(0); i < Tsize; i++) {
		if (TchList[i].getPersonName() == search_name) {
			TchList[i].Show();
			flag = true;
		}
	}
	if (!flag) {
		cout << "There is no such Teacher" << endl;
	}
}
void TeachingLoad::getByTeacherSurname()
{
	string search_surname;
	bool flag = false;
	cout << "Enter Teacher surname: ";
	fflush(stdin);
	cin >> search_surname;
	for (int i(0); i < Tsize; i++) {
		if (TchList[i].getPersonSurname() == search_surname) {
			TchList[i].Show();
			flag = true;
		}
	}
	if (!flag) {
		cout << "There is no such Teacher" << endl;
	}
}
void TeachingLoad::getByTeacherDate()
{
	Date temp;
	temp.setDate();
	bool flag = false;
	for (int i(0); i < Tsize; i++) {
		if (TchList[i].getday() == temp.getday() &&
			TchList[i].getmonth() == temp.getmonth() && 
			TchList[i].getyear() == temp.getyear())
		{
			TchList[i].Show();
			flag = true;
		}
	}
	if (!flag) {
		cout << "There is no such Teacher" << endl;
	}
}
void TeachingLoad::getByDisciplineName()
{
	string search_name;
	bool flag = false;
	cout << "Enter Cathedra Discipline name: ";
	fflush(stdin);
	cin >> search_name;
	for (int i(0); i < Dsize; i++) {
		if (DspList[i].getdisciplinename() == search_name) {
			DspList[i].Show();
			flag = true;
		}
	}
	if (!flag) {
		cout << "There is no such Discipline" << endl;
	}
}
int TeachingLoad::getDisciplineSize()
{
	return Dsize;
}
int TeachingLoad::getTeacherSize()
{
	return Tsize;
}
void TeachingLoad::setData()
{
	int res;
	do {
		Dsize++;
		Discipline *temp = new Discipline[Dsize + 1];
		for (int i(0); i < Dsize - 1; i++) {
			temp[i] = DspList[i];
		}
		temp[Dsize - 1].setDisciplineData();
		DspList = temp;
		do {
			while (getchar() != '\n');
			cout << "\nContinue enter cathedra discipline? (1 - yes, 0 - no): ";
		} while (scanf("%d", &res) != 1 || res < 0 || res > 1);
	} while (res != 0);
	cout << endl;
	do {
		Tsize++;
		Teacher *temp = new Teacher[Tsize + 1];
		for (int i(0); i < Tsize - 1; i++) {
			temp[i] = TchList[i];
		}
		temp[Tsize - 1].setTeacherData();
		TchList = temp;
		do {
			while (getchar() != '\n');
			cout << "\nContinue enter teachers? (1 - yes, 0 - no): ";
		} while (scanf("%d", &res) != 1 || res < 0 || res > 1);
	} while (res != 0);
}
void TeachingLoad::Show()
{
	for (int i(0); i < Dsize; i++) {
		cout << endl;
		DspList[i].Show();
	}
	for (int i(0); i < Tsize; i++) {
		cout << endl;
		TchList[i].Show();
	}
}
double TeachingLoad::operator[](int i)
{
	try {
		if (i > Dsize - 1) {
			throw "Array out of range";
		}
		else if (i < 0) {
			throw "Index can't be < 0";
		}
		else {
			return DspList[i].gettotal();
		}
	}
	catch (const std::exception &e) {
		cout << "Error: " << e.what() << endl;
	}
	
}
double TeachingLoad::GetAvarageLectureToTotal()
{
	double res = 0;
	for (long i(0); i < Dsize; i++) {
		res += DspList[i].getlecture() / DspList[i].gettotal();
	}
	return res / Dsize;
}
Discipline * TeachingLoad::getDiscipline()
{
	return DspList;
}
TeachingLoad::~TeachingLoad()
{
	delete[] TchList;
	delete[] DspList;
}
