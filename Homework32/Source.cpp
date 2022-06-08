#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


// Перевод в двоичную систему счисления. 
int binarySystem(int n) {
	int bin = 0;
	for (int i = 0; n > 0; i++) {
		bin += (n % 2) * pow(10, i);
		n /= 2;

	}
	return bin;
}

// Задача 1. Возведение в степень с помощью битового сдвига
int power(int n, int m = 2) {
	if (n < 0)
		throw invalid_argument("битовые операции выполняются толко с целочисленным типом данным");
	else
		if (n == 0)
			return 1;
		else {
			for (int i = 1; i < n; i++)
				m = m << 1;
			return m;
		}
}


// Задача 2. Возврат колличества едениц.
int number_of_units(int bin) {
	int count = 0;
	string str = to_string(bin);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1')
			count++;
		
	}
	return count;
}

// Задача 3. Возвращает индекс.
char numberIndex(int bin, int ind) {
	string newStr;          
	string str = to_string(bin);
	if (ind > str.size() || ind < 0)
		throw invalid_argument("недопустимое число индекса");
	for (int i = str.size(); i >= 0; i--) 
			newStr += str[i];
	return newStr[ind + 1];
}

int main() {
	setlocale(LC_ALL, "ru");
	int a, index;
	bool exit = false;

	// Задача 1.
	do {
		cout << "\tЗадача 1.\n";
		try {
			cout << "В какую степень возвести 2? Введите число : ";
			cin >> a;
			cout << "2^" << a << " = " << power(a) << "\n\n";
			exit = true;
		}
		catch (const invalid_argument& ex) {
			cout << "ОШИБКА: " << ex.what() << ".\n\n";
		}
		system("pause");
		system("cls");
	} while (exit == false);


	// Задача 2.
	cout << "\tЗадача 2.\nВведите число: ";
	cin >> a;
	cout << "Колличество едениц числа " << a << " в его двоичном передставлении = " << number_of_units(binarySystem(a)) << ".\n\n";
	system("pause");
	system("cls");

	// Задача 3.
	try {
		cout << "\tЗадача 3.\nВведите число: ";
		cin >> a;
		cout << "Введите индекс: ";
		cin >> index;
		cout << "Индекс " << index << " числа " << a << " в двоичном его представлении = " << numberIndex(binarySystem(a), index) << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "ОШИБКА: " << ex.what() << ".\n\n";
	}

	return 0;
}