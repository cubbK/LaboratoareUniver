// Laborator1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //vs headers
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>  
using namespace std;

int minValue(vector<int> vals) {
	int minVal = vals[0];
	for (int i : vals) {
		if (minVal > i) {
			minVal = i;
		}
	}
	return minVal;
}
int maxValue(vector<int> vals) {
	int maxVal = vals[0];
	for (int i : vals) {
		if (maxVal < i) {
			maxVal = i;
		}
	}
	
	return maxVal;
}
int difference(int num1, int num2) {
	return abs(num1 - num2);
}
float average(vector<int> vals) {
	int total = 0;
	for (int i : vals) {
		total += i;
	}
	return (float)total / vals.size();
}
map <char, int> categorize(vector<int> vals, int controlPoint) {
	map <char, int> categories;
	categories['>'] = 0;
	categories['<'] = 0;
	categories['='] = 0;
	for (int i : vals) {
		if (i == controlPoint) {
			categories['='] += 1;
		}
		else if (i < controlPoint) {
			categories['<'] += 1;
		}
		else {
			categories['>'] += 1;
		}
	}
	return categories;
}
void showCategories(vector<int> values) {
	int controlPoint;
	cout << "introduceti punctul de control" << endl;
	cin >> controlPoint;
	map<char, int> categories = categorize(values, controlPoint);
	cout << "Sunt " << categories['<'] << " numere mai mici ca " << controlPoint << ", " << categories['>'] << " mai mari si " << categories['='] << " egale" << endl;
}
int option() {
	cout << "alegeti optiunea dorita" << endl;
	cout << "(0) Afisarea celei mai mici valori" << endl;
	cout << "(1) Afisarea celei mai mari valori" << endl;
	cout << "(2) Afisarea diferentei dintre celei mai mari si celei mai mici valori" << endl;
	cout << "(3) Afisarea mediei valorilor" << endl;
	cout << "(4) Categorizarea numerelor" << endl;
	int option;
	cin >> option;
	return option;
}
void execute(int option, vector<int> values) {
	switch (option){
	case 0 :
		cout << "Valoarea minima e " << minValue(values) << endl;
		break;
	case 1 :
		cout << "Valoarea maxima e " << maxValue(values) << endl;
		break;
	case 2 : 
		cout << "Decalajul dintre valoarea maxima si minima e " << difference(minValue(values), maxValue(values)) << endl;
		break;
	case 3 :
		cout << "Valoarea medie a numerelor e " << average(values) << endl;
		break;
	case 4 :
		showCategories(values);
		break;
	default:
		cout << "optiune gresita" << endl;
		break;
	}
	
}
int main()
{	
	// introducerea datelor initiale
	vector<int> values;
	int nrVals;
	cout << "Introduceti nr de valori" << endl;
	cin >> nrVals;
	cout << "Introduceti valorile" << endl;
	for (int i = 0; i < nrVals; i++) {
		int val;
		cin >> val;
		values.push_back(val);
	}

	execute(option(),values);
	
	
	
	
	
	
	
	
    return 0;
}

