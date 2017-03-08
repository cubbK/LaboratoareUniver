// Laborator2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
//Numere Pandigitale
// Laborator 2

bool isPandigital(long nr) {
	int allNr[10] = { 0 };
	while (nr > 0) {
		int singleNr = (int)(nr % 10);
		nr = nr / 10;
		allNr[singleNr] += 1;
	}
	bool isZero = false;
	int posArr = 0;
	while (!isZero && posArr<10) {
		if (allNr[posArr] == 0) {
			isZero = true;
		}
		else
			posArr += 1;
	}
	if (isZero) {
		return false;
	}
	else {
		return true;
	}
}
void showIfPandigital() {
	long nr;
	cout << "introdu nr " << endl;
	cin >> nr;
	if (isPandigital(nr)) {
		cout << "Numarul e pandigital" << endl;
	}
	else {
		cout << "Numarul nu e pandigital" << endl;
	}
}

vector<long> allPanFromInterval(long a, long b) {
	vector<long> numbers;
	for (int i = a; i <= b; i++) {
		if (isPandigital(i)) {
			numbers.push_back(i);
		}
	}
	return numbers;
}
void showAllPanFromInterval() {
	long a, b;
	cout << "introduceti a " << endl;
	cin >> a;
	cout << "introduceti b" << endl;
	cin >> b;
	vector<long> numbers = allPanFromInterval(a, b);
	if (numbers.size() == 0) {
		cout << "nu sunt numere pandigitale in intervalul dat" << endl;
	}
	else {
		cout << "Numerele pan sunt: ";
		for (int i = 0; i < numbers.size(); i++) {
			cout << numbers[i] << " ";
		}
		cout << endl;
	}
}
void showFirstN() {
	int n;
	cout << "Introduceti N" << endl;
	cin >> n;
	long checkNum = 1023456789;
	while (n > 0) {
		if (isPandigital(checkNum)) {
			cout << checkNum << endl;
			n -= 1;
			
		}
		checkNum += 1;
	}
}

int main() {
	cout << "Introduceti cifra pt operatia dorita" << endl;
	cout << "(0)Daca nr e pandigital" << endl;
	cout << "(1)Care numere din intervalul [a,b] sunt pandigitale" << endl;
	cout << "(2)primele n numere, care sunt pandigitale" << endl;
	cout << "(3)Care numere din intervalul [a,b] sunt pandigitale prime" << endl;
	cout << "(4)cel mai mare numar pandigital" << endl;
	cout << "(5)Exit" << endl;
	int operation;
	cin >> operation;
	switch (operation) {
	case 0:
		showIfPandigital();
		break;
	case 1:
		showAllPanFromInterval();
		break;
	case 2: 
		showFirstN();
		break;
	case 3: 

		break;
	case 5:
		return 0;
	default:
		cout << "optiune gresita";
	}
	main();
	
}

