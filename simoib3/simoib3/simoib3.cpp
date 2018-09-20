// simoib3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

long double Pow(int a, int x) {
	long double res = 1;
	for (int i = 0; i<x; i++) {
		res = res*a;
	}
	return res;
}

long double getMod(int a, int x, int p) {
	long double c = 1;
	int x0 = 0;
	while (x0<x) {
		c = (unsigned long long int)(Pow(a, x0)) % p;
		c = (unsigned long long int)(a*c) % p;
		x0++;
	}
	return c;
}

bool isPrimit(unsigned long long int a, unsigned long long int p) {
	unsigned long long int array[1123];
	for (unsigned long long int i = 0; i<p; i++) {
		array[i] = i + 1;
	}

	for (int x = 1; x < p; x++) {
		unsigned long long int index = (unsigned long long int) Pow(a, x) % p - 1;
		if (array[index] != 0) {
			array[index] = 0;
		}
		else {
			return false;

		}
	}
	return true;
}

int getRandom(int number) {
	srand(time(0));
	return (rand() % number) / 30;
}
unsigned long long int getPrimit(unsigned long long int p) {
	unsigned long long int a;
	for (a = 1; a<p + 1; a++) {
		if (isPrimit(a, p) == true)
			return a;
	}
	return 0;
}

long double getY(int a, int p, int X) {
	long double Y = (unsigned long long int)(getMod(a, X, p));
	return Y;
}

int main(int argc, char *argv[])
{
	int p = 1123;
	int a = getPrimit(p);
	cout << a<<"xaxa"<<endl;
	int Xi = getRandom(p);
	cout << Xi << "xaxa" << endl;
	int Yi = getY(a, p, Xi);
	cout << Yi << "xaxa" << endl;
	int Xj = getRandom(p);
	cout << Xj << "xaxa" << endl;
	int Yj = getY(a, p, Xj);
	long double Zij = Pow(Yj, Xi);
	long double Zji = Pow(Yi, Xj);
	cout << Zij << endl << Zji << endl;
	if (Zij == Zji) {
		cout << "KEYS ARE CORRECT" << endl;
	}
	else {
		cout << "KEYS ARE WRONG!" << endl;
	}
	system("pause");
}

