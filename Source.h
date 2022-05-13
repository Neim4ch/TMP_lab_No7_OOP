#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class film {
public:
	static film* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0;
	virtual void Out(ofstream& ofst) = 0;
	

	virtual void MultiMethod(film* f2, ofstream &ofst) = 0;
	virtual void MMFeat(ofstream &ofst) = 0;
	virtual void MMAnim(ofstream& ofst) = 0;
};
class Node {
public:
	film* pic;
	Node* next;
	Node(film* newfigure);
	Node() {}
	~Node() {}
};
class feature : public film {
	string director;
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);

	void MultiMethod(film* f2, ofstream& ofst);
	void MMFeat(ofstream& ofst);
	void MMAnim(ofstream& ofst);

	feature() {}
};
class animation : public film {
	enum way { DRAWN, DOLL, STOP_MOTION };
	way woc;
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);

	void MultiMethod(film* f2, ofstream& ofst);
	void MMFeat(ofstream& ofst);
	void MMAnim(ofstream& ofst);

	animation() {}
};
class container {

public:
	Node* head;
	Node* curr;
	int size;

	void In(ifstream& ifst);
	void Out(ofstream& ofst);
	void Clear();

	void MultiMethod(ofstream& ofst);

	container(); 
	~container() { Clear(); }
};