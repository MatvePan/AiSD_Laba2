#include "iostream"
#include "string"
#include "vector"
using namespace std;
// Вариант 15: дополнение кода программы двумя вариантами сортировки: Шелла и быстрая

struct Tovar { // Структура товара
	string name;
	int price;
	int code;
};

void AddTovar(vector<Tovar>& place) { // Функция добавления товара в массив
	Tovar thing;
	cout << "Введите название товара:\n";
	cin >> thing.name;
	cout << "Введите стоимость товара:\n";
	cin >> thing.price;
	cout << "Введите код товара:\n";
	if (place.size() == 0) {
		cin >> thing.code;
	}
	else {
		while (true) {
			int ind;
			bool uniq = true;
			cin >> ind;
			for (int i = 0; i < place.size(); i++) {
				if (place[i].code == ind) {
					cout << "Код занят\n";
					cout << "Введите новый код\n";
					uniq = false;
				}
			}
			if (uniq) {
				thing.code = ind;
				break;
			}
		}
	}
	place.push_back(thing);
}

void ShowTovar(vector<Tovar>& place) { // Функция просмотра всех товаров
	cout << "Название | Цена | Код\n";
	for (int i = 0; i < place.size(); i++) {
		cout << place[i].name << " | " << place[i].price << " | " << place[i].code << "\n";
	}
}

void Choose(vector<Tovar>& place) { // Функция сортировки выбором
	int minimum;
	for (int i = 0; i < place.size() - 1; i++) {
		minimum = i;
		for (int j = i + 1; j < place.size(); j++) {
			if (place[j].code < place[minimum].code)
				minimum = j;
		}
		swap(place[minimum], place[i]);
	}
}

void Paste(vector<Tovar>& place) { // Функция сортировки вставками
	int j, key;
	for (int i = 1; i < place.size(); i++) {
		key = place[i].code;
		j = i - 1;
		while (j >= 0 and place[j].code > key) {
			place[j + 1].code = place[j].code;
			j = j - 1;
		}
		place[j + 1].code = key;
	}
	cout << "Отсортировано\n";
}

void Shell(vector<Tovar>& place) {

}

void Fast(vector<Tovar>& place) {
	int middle = (place[0].code + place[place.size()-1].code) / 2;
	cout << "\n";
	cout << middle;
}

int main() {
	setlocale(LC_ALL, "RUS");
	vector<Tovar> thing;
	int mode;
	while (true) {
		cout << "\n";
		cout << "1. Ввод данных товара (только на английском)\n";
		cout << "2. Вывод списка товаров\n";
		cout << "3. Сортировка выбором\n";
		cout << "4. Сортировка вставками\n";
		cout << "5. Сортировка Шелла\n";
		cout << "6. Быстрая сортировка\n";
		cout << "0. Выход\n";
		cout << "\n";
		cin >> mode;
		switch (mode) {
		case 1:
			AddTovar(thing);
			break;
		case 2:
			ShowTovar(thing);
			break;
		case 3:
			Choose(thing);
			break;
		case 4:
			Paste(thing);
			break;
		case 5:
			Shell(thing);
			break;
		case 6:
			Fast(thing);
			break;
		case 0:
			return 0;
		default:
			cout << "Ввод неверный!\n";
		}
	}
}