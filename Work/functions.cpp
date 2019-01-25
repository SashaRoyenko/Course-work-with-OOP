#include"functions.h"

template<typename T, typename K/*, typename L*/>
double GetAvarageLecture(T &arr, K n)
{
	double res = 0;
	for (K i(0); i < n; i++) {
		res += arr[i];
	}
	return res / n;
}

void ShowAvarageData(TeachingLoad &t)
{
	cout << endl << char(0xC9);
	for (int i(0); i < 45; i++) {
			cout << char(0xCD);
	}
	cout << char(0xBB) << endl;
	cout << char(0xBA) << setw(26) << "Avarage Data" << setw(20) << char(0xBA) << endl;

	cout << char(0xCC);
	for (int i(0); i < 45; i++) {
		if (i == 20) {
			cout << char(0xCB);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xB9) << endl;

	cout << char(0xBA) << setw(15) << "Lecture / N" << setw(6) << char(0xBA)
		<< setw(22) << "(Lecture / Total) / N" << setw(3) << char(0xBA) << endl;

	cout << char(0xCC);
	for (int i(0); i < 45; i++) {
		if (i == 20) {
			cout << char(0xCE);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xB9) << endl;

	cout << char(0xBA) << setw(10) << GetAvarageLecture(t, t.getDisciplineSize()) << setw(11) << char(0xBA)
		<< setw(15) << t.GetAvarageLectureToTotal() << setw(10) << char(0xBA) << endl;

	cout << char(0xC8);
	for (int i(0); i < 45; i++) {
		if (i == 20) {
			cout << char(0xCA);
		}
		else {
			cout << char(0xCD);
		}
	}
	cout << char(0xBC) << endl;
}

void Menu(TeachingLoad &Cathedra)
{
	int answ = 0, c;
	do {
		do {
			cout << "\n1) Create objects\n"
				"2) Show Table\n"
				"3) Write in text file\n"
				"4) Write in binary file\n"
				"5) Read from text file\n"
				"6) Read from binary file\n"
				"7) Search data\n"
				"0) Quit\n";
			cout << "\nEnter answer: ";
			c = scanf("%d", &answ);
			while (getchar() != '\n');
		} while (c != 1 || answ < 0 || answ > 7);
		system("cls");
		switch (answ) {
		case 1:
			Cathedra.setData();
			break;
		case 2:
			Cathedra.ShowDisciplineTable();
			ShowAvarageData(Cathedra);
			Cathedra.ShowTeacherTable();
			break;
		case 3:
			Cathedra.writeInFile();
			break;
		case 4:
			Cathedra.writeInBinary();
			break;
		case 5:
			Cathedra.readFromFile();
			break;
		case 6:
			Cathedra.ReadFromBinary();
			break;
		case 7:
			do {
				system("cls");
				cout << "\n1) Search by Teacher name\n"
					"2) Search by Teacher surname\n"
					"3) Search by Teacher date of birth\n"
					"4) Search by Discipline name\n"
					"0) Quit\n";
				cout << "\nEnter answer: ";
				c = scanf("%d", &answ);
				while (getchar() != '\n');
			} while (c != 1 || answ < 0 || answ > 4);
			switch (answ) {
			case 1:
				Cathedra.getByTeacherName();
				break;
			case 2:
				Cathedra.getByTeacherSurname();
				break;
			case 3:
				Cathedra.getByTeacherDate();
				break;
			case 4:
				Cathedra.getByDisciplineName();
				break;
			case 0:
				break;
			}
			break;
		case 0:
			exit;
			break;
		}

	} while (answ != 0);

}
