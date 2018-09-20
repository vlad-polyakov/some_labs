// simoib2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	int KEY = 4;
	int Column;
	char **table;
	string Line;
	getline(cin, Line);
	if (Line.length() % KEY == 0) Column = Line.length() / KEY;
	else Column = (int)(Line.length() / KEY) + 1;
	table = new char*[KEY];
	for (int i = 0; i<KEY; i++)
		table[i] = new char[Column];
	int num = 0;
	for (int k = 0; k<Column; k++) {
		for (int i = 0; i<KEY; i++) {
			if (num<Line.length()) {
				table[i][k] = Line[num];
				num++;
			}
			else table[i][k] = ' ';
		}
	}
	for (int i = 0; i<KEY; i++) {
		for (int k = 0; k < Column; k++) {
			cout << table[i][k];
		}
		cout << endl;
	}
	cout << endl;
	string Answer = "";
	for (int i = 0; i<KEY; i++) {
		for (int k = 0; k < Column; k++) {
			Answer += table[i][k];
		}
	}
	cout << Answer << endl;
	int DecryptorKey = 1;
	for (DecryptorKey; DecryptorKey<Answer.length(); DecryptorKey++) {
		char **DecryptorTable;
		int DecryptorColumn;
		if (Answer.length() % DecryptorKey == 0) DecryptorColumn = Answer.length() / DecryptorKey;
		else DecryptorColumn = (int)(Answer.length() / DecryptorKey) + 1;
		DecryptorTable = new char *[DecryptorKey];
		for (int i = 0; i < DecryptorKey; i++)
			DecryptorTable[i] = new char[DecryptorColumn];
		int DecryptNum = 0;
		for (int k = 0; k < DecryptorColumn; k++) {
			for (int i = 0; i < DecryptorKey; i++) {
				if (DecryptNum < Answer.length()) {
					DecryptorTable[i][k] = Answer[DecryptNum];
					DecryptNum++;
				}
				else DecryptorTable[i][k] = ' ';
			}
		}
		string DecryptAnswer = "";
		for (int i = 0; i<DecryptorKey; i++) {
			for (int k = 0; k < DecryptorColumn; k++) {
				DecryptAnswer += DecryptorTable[i][k];
			}
		}
		cout << DecryptorKey<<","<< DecryptAnswer << endl;
	}
	system("pause");
	return 0;
}



