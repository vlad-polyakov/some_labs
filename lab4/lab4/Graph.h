#ifndef Graph_H
#define Graph_H
#include <vector>
#include <iterator>
#include <iostream>
#include <conio.h>
#include "string"
using namespace std;

template<class T>
class Graph
{
public:
	Graph() {};
	Graph(Graph<T> *a) {
		this = &a;
	};
	~Graph() {};
	bool isEmpty() {
		if (Node.size() == 0)
			return true;
		return false;
	}
	int getNode() {
		return Node.size();
	}
	int getArc() {
		return Arc.size();
	}
	void addNode(T add) {
		if (findNode(add) == false)
			Node.push_back(add);
	}
	bool findNode(T findit) {
		for (int i = 0; i < Node.size(); i++)
			if (Node[i] == findit)
				return true;
		return false;
	}
	bool findArc(vector<T> arc) {
		for (int i = 0; i < Arc.size(); i++) {
			if (Arc[i] == arc)
				return true;
		}
		return false;
	}
	bool findArc(T start, T end) {
		vector<T> arc;
		arc.push_back(start);
		arc.push_back(end);
		return findArc(arc);
	}
	void addArc(T start, T end) {
		try {
			if (findNode(start) == true && findNode(end) == true) {
				vector<T> arc;
				arc.push_back(start);
				arc.push_back(end);
				if (findArc(arc) == false)
					Arc.push_back(arc);
			}
			else
				throw 111;
		}
		catch (int i) {
			cout << "Нельзя создать дугу, принадлежащую несуществующим узлам" << endl;
		}
	}
	void clear() {
		Arc.clear();
		Node.clear();
	}
	void view() {
		if (this->isEmpty())
			cout << "Граф пустой\n";
		else
		{
			cout << "Node: ";
			for (int i = 0; i < Node.size(); i++) {
				cout << Node[i] << " ";
			}
			cout << endl;
			cout << "Arc:\n";
			for (int i = 0; i < Arc.size(); i++) {
				for (int j = 0; j < Arc[i].size(); j++) {
					cout << Arc[i][j];
					if (j == 0)
						cout << "->";
				}
				cout << endl;
			}
		}
	}
	void dellArc(T start, T end) {
		vector<T> arc;
		arc.push_back(start);
		arc.push_back(end);
		dellArc(arc);
	}
	void dellArc(vector<T> arc) {
		for (int i = 0; i < Arc.size(); i++)
			if (Arc[i] == arc) {
				Arc.erase(Arc.begin() + i);
				break;
			}
	}
	void dellNode(T dellit) {
		while (DellIndexArc(dellit) == true);
		for (int i = 0; i<Node.size(); i++)
			if (Node[i] == dellit) {
				Node.erase(Node.begin() + i);
				break;
			}
	}
	int powerNode(T vertex) {
		try {
			if (findNode(vertex) == false)
				throw 111;
			else
			{
				int power = IndexinArc(vertex).size();
				if (findArc(1, 1)) power++;
				return power;
			}
		}
		catch (int i) {
			cout << "Нельзя найти мощность вершины, которая не существует";
			return NULL;
		}
	}
	friend bool operator==(const Graph<T>& left, const Graph<T>& right);
	bool operator==(Graph<T>& right) {
		if (this->getArc() == right.getArc() && this->getNode() == right.getNode()) {
			int shet = 0;
			for (int i = 0; i < this->getNode(); i++)
				for (int j = 0; j < this->getNode(); j++)
					if (this->Node[i] == right.Node[j]) {
						shet++;
						break;
					}
			if (shet == this->getNode()) {
				shet = 0;
				for (int i = 0; i < this->getArc(); i++)
					for (int j = 0; j < this->getArc(); j++)
						if (this->Arc[i] == right.Arc[j]) {
							shet++;
							break;
						}
				if (shet == this->getArc()) return true;
			}
		}
		return false;
	}
	friend bool operator!=(const Graph<T>& left, const Graph<T>& right);
	bool operator!=(Graph<T>& right) {
		return !operator==(right);
	}
	friend bool operator<(const Graph<T>& left, const Graph<T>& right);
	bool operator<(Graph<T>& right) {
		if (this->getNode() < right.getNode())
			return true;
		return false;
	}
	friend bool operator>(const Graph<T>& left, const Graph<T>& right);
	bool operator>(Graph<T>& right) {
		if (this->getNode() > right.getNode())
			return true;
		return false;
	}
	friend bool operator>=(const Graph<T>& left, const Graph<T>& right);
	bool operator>=(Graph<T>& right) {
		if (this->getNode() >= right.getNode())
			return true;
		return false;
	}
	friend bool operator<=(const Graph<T>& left, const Graph<T>& right);
	bool operator<=(Graph<T>& right)
	{
		if (this->getNode() <= right.getNode())
			return true;
		return false;
	}
	Graph<T>& operator=(const Graph<T>& right) {
		if (this == &right) {
			return *this;
		}
		Node = right.Node;
		Arc = right.Arc;
		return *this;
	}
private:
	vector<T> Node;
	vector<vector<T>> Arc;
	vector <int> IndexinArc(T find) {
		vector<int> Index;
		for (int i = 0; i < Arc.size(); i++)
			for (int j = 0; j < Arc[i].size(); j++) {
				if (Arc[i][j] == find) {
					Index.push_back(i);
					break;
				}
			}
		return Index;
	}
	bool DellIndexArc(T find) {
		for (int i = 0; i < Arc.size(); i++)
			for (int j = 0; j < Arc[i].size(); j++) {
				if (Arc[i][j] == find) {
					Arc.erase(Arc.begin() + i);
					return true;
				}
			}
		return false;
	}
public:
	class node_iterator {
	private:
		Graph<T> *graph;
		int index;
	public:
		node_iterator(Graph<T> &gr) {
			graph = &gr;
			index = 0;
		}

		bool next() {
			if (graph->getNode() <= index + 1)
				return false;
			index++;
			return true;
		}

		bool prev() {
			if (index == 0)
				return false;
			index--;
			return true;
		}
		void begin() {
			index = 0;
		}
		void end() {
			index = graph->getNode() - 1;
		}
		T get() {
			return graph->Node[index];
		}
	};
public:
	class arc_iterator {
	private:
		Graph<T> *graph;
		int index;
	public:
		arc_iterator(Graph<T> &gr) {
			graph = &gr;
			index = 0;
		}
		bool next() {
			if (graph->getArc() <= index + 1)
				return false;
			index++;
			return true;
		}
		bool prev() {
			if (index == 0)
				return false;
			index--;
			return true;
		}
		void begin() {
			index = 0;
		}
		void end() {
			index = graph->getArc() - 1;
		}
		string get() {
			string str = "";
			for (int i = 0; i < graph->getArc(); i++) {
				if (index < graph->getArc()) {
					T *pointer = graph->Arc[index].data();
					str += to_string(pointer[0]);
					str += "->";
					str += to_string(pointer[1]);
					str += '\n';
					next();
				}
				else {
					end();
					T *pointer = graph->Arc[index].data();
					str += to_string(pointer[0]);
					str += "->";
					str += to_string(pointer[1]);
					str += '\n';

				}
			}
			return str;
		}
	};
public:
	class arc_iterator_incident_vertex {
	private:
		Graph<T> *graph;
		vector<vector<T>> spis;
		int index;
		T vertex;
	public:
		arc_iterator_incident_vertex(Graph<T> &gr, T ver) {
			graph = &gr;
			index = -1;
			vertex = ver;
			for (int i = 0; i < graph->getArc(); i++)
				if (graph->Arc[i][0] == ver) {
					spis.push_back(graph->Arc[i]);
					index = 0;
				}
		}
		bool next() {
			if (spis.size() <= index + 1)
				return false;
			index++;
			return true;
		}
		bool prev() {
			if (index == 0)
				return false;
			index--;
			return true;
		}
		void begin() {
			index = 0;
		}
		void end() {
			index = spis.size() - 1;
		}
		string get() {
			string str = "";
			if (index != -1) {
				if (index < spis.size()) {
					str += to_string(spis[index][0]);
					str += "->";
					str += to_string(spis[index][1]);
					str += '\n';
				}
				else {
					end();
					str += to_string(spis[index][0]);
					str += "->";
					str += to_string(spis[index][0]);
					str += '\n';
				}
			}
			return str;
		}

	};
};
#endif
