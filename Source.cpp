#include "Source.h"
using namespace std;
void feature::InData(ifstream& ifst) {
	ifst >> director;
}
void feature::Out(ofstream& ofst) {
	ofst << "It is feature film. Director is " << director << endl;
}
void animation::InData(ifstream& ifst) {
	int t;
	ifst >> t;
	switch (t)
	{
	case 1:
		woc = DRAWN;
		break;
	case 2:
		woc = DOLL;
		break;
	case 3:
		woc = STOP_MOTION;
		break;
	}
}
void animation::Out(ofstream& ofst) {
	switch (woc)
	{
	case 0:
		//woc = DRAWN;
		ofst << "It is animation film. It's way of creation is drawing." << endl;
		break;
	case 1:
		//woc = DOLL;
		ofst << "It is animation film. It's way of creation is using dolls" << endl;
		break;
	case 2:
		//woc = STOP_MOTION;
		ofst << "It is animation film. It's way of creation is stop motion" << endl;
		break;
	}
}
film* film::In(ifstream& ifst) {
	film* fl;
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		fl = new feature;
		break;
	case 2:
		fl = new animation;
		break;
	default:
		return 0;
	}
	fl->InData(ifst);
	return fl;
}
Node::Node(film* newpic)
{
	pic = newpic;
	next = NULL;
}
container::container()
{
	head = NULL;
	head = NULL;
	size = 0;
}
void container::Clear() {
	head = NULL;
	curr = NULL;
	size = 0;
}
void container::In(ifstream& ifst) {
	while (!ifst.eof()) {
		Node* newNode;
		newNode = new Node((film::In(ifst)));
		if (head == NULL)
		{
			head = newNode;
			size = 1;
		}
		else
		{
			curr = head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = newNode;
			size++;
		}
	}
}
void container::Out(ofstream& ofst) {
	ofst << "Container contents " << size
		<< " elements." << endl;
	int i = 0;
	curr = head;
	while (curr != NULL)
	{
		ofst << i << ": ";
		curr->pic->Out(ofst);
		curr = curr->next;
		i++;
	}
}

void feature::MultiMethod(film* f2, ofstream& ofst)
{
	f2->MMFeat(ofst);
}
void animation::MultiMethod(film* f2, ofstream& ofst)
{
	f2->MMAnim(ofst);
}

void feature::MMFeat(ofstream& ofst)
{
	ofst << "Feature and feature" << endl;
}
void feature::MMAnim(ofstream& ofst)
{
	ofst << "Animation N' feature" << endl;
}
void animation::MMFeat(ofstream& ofst)
{
	ofst << "Feature && animation" << endl;
}
void animation::MMAnim(ofstream& ofst)
{
	ofst << "Animation + animation" << endl;
}

void container::MultiMethod(ofstream& ofst) 
{
	ofst << "Multimethod." << endl;

	int i = 0, j = 1;
	curr = head;
	Node* currj = new Node;
	while (curr->next != NULL)
	{
		currj = curr->next;
		j = i + 1;
		while (currj != NULL)
		{
			curr->pic->MultiMethod(currj->pic, ofst);
			ofst << i << ": ";  curr->pic->Out(ofst);
			ofst << j << ": ";  currj->pic->Out(ofst);
			ofst << endl;
			currj = currj->next;
			j++;
		}
		curr = curr->next;
		i++;
	}
}
