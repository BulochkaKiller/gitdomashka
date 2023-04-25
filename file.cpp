#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
using namespace std;

HANDLE hConsole;

class Butterfly {
public:
	int days;
	string lifestage;

	Butterfly(int a) {
		days = a;
	}

	void SetLifeStage() { //��� ���������� ���������� ������ �����
		if (days >= 0 && days < 8) {
			lifestage = "��������";
		}
		if (days >= 8 && days <= 15)
			lifestage = "�������";
		if (days >= 16 && days < 24)
			lifestage = "�������";
		if (days < 0 || days >= 24)
			cout << "������" << endl;
	}

	void AddingDays() { //��������� 1 ���� � ������ ������ ���� �����
		days = days + 1;
		if (days == 8)
			lifestage = "�������";
		if (days == 16)
			lifestage = "�������";
		if (days == 24) {
			lifestage = "��������";
			days = 0;
		}
	}

	void print() {//�������, ����� ����
		if (lifestage == "��������")
			SetConsoleTextAttribute(hConsole, 2);
		if (lifestage == "�������")
			SetConsoleTextAttribute(hConsole, 4);
		if (lifestage == "�������")
			SetConsoleTextAttribute(hConsole, 5);
		cout << lifestage << "     " << '\t' << "����: " << days << "    ";
		SetConsoleTextAttribute(hConsole, 7);
	}
};

int main() {
	system("chcp 1251 > nul");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Butterfly a(23), b(3), c(21), d(15), e(7), f(5), g(18), h(19), i(0), j(7); //���� �������
	vector <Butterfly> v1 = { a, b, c, d, e, f, g, h, i, j };//������ ����������
	for (int i = 0; i < 10; i++) {//���� ��� ������ ���� �������
		v1[i].SetLifeStage();
		v1[i].print();
		cout << '\t' << "->" << '\t';
		v1[i].AddingDays();
		v1[i].print();
		cout << endl;
	}
	system("pause");
	return 0;
}