// lab4.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "Graph.h"
#include "iostream"
#include "string"
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Graph<int> a;
	a.addNode(1);
	a.addNode(2);
	a.addNode(3);
	a.addNode(4);
	a.addArc(1, 3);
	a.addArc(1, 2);
	a.view();
	Graph<int> b = a;
	
	//a.dellArc(1, 2);
	//a.dellNode(1);
	/*b.addArc(1, 4);
    b.addArc(1, 1);
	a.addArc(2, 3);*/
	//cout<<a.powerNode(1);
	//a.dellNode(1);
	Graph<int>::arc_iterator iter(a);
	
		
		//iter.next();
	if (a==b) cout << "Doing something"<<endl;
	//a.view();
	Graph<int>::arc_iterator_incident_vertex iter1(a, 1);
	cout << iter1.get();
	iter1.next();
	iter1.next();
	cout<<iter1.get();
	system("pause");
    return 0;
}


