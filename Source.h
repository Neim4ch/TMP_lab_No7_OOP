#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class film {
	string name;
public:
	string country;


	static film* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; 
	virtual void Out(ofstream& ofst) = 0; 
	int countVowels(); 
	void OutName(ofstream& ofst);
	bool cmp(film& f);
	virtual void OutFeature(ofstream& ofst);

	virtual void MultiMethod(film* f2, ofstream& ofst) = 0;
	virtual void MMFeat(ofstream& ofst) = 0;
	virtual void MMAnim(ofstream& ofst) = 0;
	virtual void MMDoc(ofstream& ofst) = 0;

};
class Node {
public:
	film* pic;
	Node* next;
	Node(film* newfigure);
	Node() {};
};
class feature : public film {
	string director; 
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	void OutFeature(ofstream& ofst);

	void MultiMethod(film* f2, ofstream& ofst);
	void MMFeat(ofstream& ofst);
	void MMAnim(ofstream& ofst);
	void MMDoc(ofstream& ofst);

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
	void MMDoc(ofstream& ofst);

	animation() {}
};

class documentary : public film {
	int year;
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);

	void MultiMethod(film* f2, ofstream& ofst);
	void MMFeat(ofstream& ofst);
	void MMAnim(ofstream& ofst);
	void MMDoc(ofstream& ofst);

	documentary() {}
};

class container {
public:
	Node* head;
	Node* curr;
	int size;

	void In(ifstream& ifst);
	void Out(ofstream& ofst);
	void OutFeature(ofstream& ofst);
	void OutCntVowels(ofstream& ofst);
	void Clear();
	void Sort();

	void MultiMethod(ofstream& ofst);

	container();
	~container() { Clear(); }
};






