// Laborator1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int minValue(vector<int> vals) {
	int minVal = vals[0];
	for (int i = 1; i < vals.size(); i++) {
		if (minVal > vals[i]) {
			minVal = vals[i];
		}
	}
	return minVal;
}
int maxValue(vector<int> vals) {
	int maxVal = vals[0];
	for (int i = 1; i < vals.size(); i++) {
		if (maxVal < vals[i]) {
			maxVal = vals[i];
		}
	}
	return maxVal;
}
int main()
{
	vector<int> values = { 100,200,500,43,87,75 };
	cout << minValue(values) << " "  << maxValue(values) <<  endl;

    return 0;
}

