#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


// ������� � �������� ������� ���������. 
int binarySystem(int n) {
	int bin = 0;
	for (int i = 0; n > 0; i++) {
		bin += (n % 2) * pow(10, i);
		n /= 2;

	}
	return bin;
}

// ������ 1. ���������� � ������� � ������� �������� ������
int power(int n, int m = 2) {
	if (n < 0)
		throw invalid_argument("������� �������� ����������� ����� � ������������� ����� ������");
	else
		if (n == 0)
			return 1;
		else {
			for (int i = 1; i < n; i++)
				m = m << 1;
			return m;
		}
}


// ������ 2. ������� ����������� ������.
int number_of_units(int bin) {
	int count = 0;
	string str = to_string(bin);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1')
			count++;
		
	}
	return count;
}

// ������ 3. ���������� ������.
char numberIndex(int bin, int ind) {
	string newStr;          
	string str = to_string(bin);
	if (ind > str.size() || ind < 0)
		throw invalid_argument("������������ ����� �������");
	for (int i = str.size(); i >= 0; i--) 
			newStr += str[i];
	return newStr[ind + 1];
}

int main() {
	setlocale(LC_ALL, "ru");
	int a, index;
	bool exit = false;

	// ������ 1.
	do {
		cout << "\t������ 1.\n";
		try {
			cout << "� ����� ������� �������� 2? ������� ����� : ";
			cin >> a;
			cout << "2^" << a << " = " << power(a) << "\n\n";
			exit = true;
		}
		catch (const invalid_argument& ex) {
			cout << "������: " << ex.what() << ".\n\n";
		}
		system("pause");
		system("cls");
	} while (exit == false);


	// ������ 2.
	cout << "\t������ 2.\n������� �����: ";
	cin >> a;
	cout << "����������� ������ ����� " << a << " � ��� �������� �������������� = " << number_of_units(binarySystem(a)) << ".\n\n";
	system("pause");
	system("cls");

	// ������ 3.
	try {
		cout << "\t������ 3.\n������� �����: ";
		cin >> a;
		cout << "������� ������: ";
		cin >> index;
		cout << "������ " << index << " ����� " << a << " � �������� ��� ������������� = " << numberIndex(binarySystem(a), index) << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "������: " << ex.what() << ".\n\n";
	}

	return 0;
}