// Laborator1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
int main()
{	
	//numarul total de valori 
	
	vector<int> values = { 1,100,500,7658,5 };
	cout << "Valoarea minima e " << minValue(values) << endl;
	cout << "Valoarea maxima e " << maxValue(values) << endl;
	cout << "Decalajul dintre valoarea maxima si minima e " << difference(minValue(values),maxValue(values)) << endl;
	cout << "Valoarea medie a numerelor e " << average(values) << endl;
	int controlPoint = 5;
	map<char, int> categories = categorize(values, controlPoint);
	cout << "Sunt " << categories['<'] << " numere mai mici ca " << controlPoint << ", " << categories['>'] << " mai mari si " << categories['='] << " egale" << endl;
    return 0;
}

