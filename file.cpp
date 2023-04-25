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

	void SetLifeStage() { //для начального заполнения стадии жизни
		if (days >= 0 && days < 8) {
			lifestage = "Гусеница";
		}
		if (days >= 8 && days <= 15)
			lifestage = "Куколка";
		if (days >= 16 && days < 24)
			lifestage = "Бабочка";
		if (days < 0 || days >= 24)
			cout << "ОШИБКА" << endl;
	}

	void AddingDays() { //добавляем 1 день и меняем стадию если нужно
		days = days + 1;
		if (days == 8)
			lifestage = "Куколка";
		if (days == 16)
			lifestage = "Бабочка";
		if (days == 24) {
			lifestage = "Гусеница";
			days = 0;
		}
	}

	void print() {//выводим, меняя цвет
		if (lifestage == "Гусеница")
			SetConsoleTextAttribute(hConsole, 2);
		if (lifestage == "Куколка")
			SetConsoleTextAttribute(hConsole, 4);
		if (lifestage == "Бабочка")
			SetConsoleTextAttribute(hConsole, 5);
		cout << lifestage << "     " << '\t' << "Дней: " << days << "    ";
		SetConsoleTextAttribute(hConsole, 7);
	}
};

int main() {
	system("chcp 1251 > nul");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Butterfly a(23), b(3), c(21), d(15), e(7), f(5), g(18), h(19), i(0), j(7); //сами объекты
	vector <Butterfly> v1 = { a, b, c, d, e, f, g, h, i, j };//вектор указателей
	for (int i = 0; i < 10; i++) {//цикл для вызова всех функций
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