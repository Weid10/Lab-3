#include "Poly.h"
#include <iostream>

Poly::Poly()
{
	head = new PolyNode(-1,0,NULL);
}

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff)
{
	PolyNode* curr = new PolyNode(-1, 0, NULL);
	head = curr;

	for (int index = 0; index < deg.size(); index++) {
		curr->next = new PolyNode(deg[index], coeff[index], NULL);
		curr = curr->next;
	}
}

Poly::~Poly()
{
	PolyNode* curr = head;
	PolyNode* next;
	while (curr != NULL) {
		next = curr->next;
		delete curr;
		curr = next;
	}
}

void Poly::addMono(int i, double c)
{
	if (c == 0) return;

	PolyNode* curr = head->next;
	PolyNode* prev = head;

	while (curr != NULL) {

		if (curr->deg == i) { // existing node
			curr->coeff += c;
			if (!(curr->coeff)) { // delete node if 0
				prev->next = curr->next;
				delete curr;
			}
			return;
		}
		else if (curr->deg < i) { // new node
			prev->next = new PolyNode(i,c,curr);
			return;
		}

		prev = curr;
		curr = curr->next;
	}

	// new end node
	prev->next = new PolyNode(i, c, NULL);
}

void Poly::addPoly(const Poly& p)
{
	PolyNode* p_curr = p.head->next;

	while (p_curr != NULL) {

		addMono(p_curr->deg, p_curr->coeff);
		p_curr = p_curr->next;
	}

}

void Poly::multiplyMono(int i, double c)
{
	PolyNode* curr = head->next;
	PolyNode* prev = head;

	while (curr != NULL) {

		

		curr = curr->next;
	}
}

void Poly::multiplyPoly(const Poly& p)
{
	// TODO
}

void Poly::duplicate(Poly& outputPoly)
{
	// TODO
}

int Poly::getDegree()
{
	PolyNode* curr = head->next;
	if (curr->deg == -1) return -1;
	else return curr->deg;
}

int Poly::getTermsNo()
{
	// TODO
	return -1;//change this after completing this function
}

double Poly::evaluate(double x)
{
	// TODO
	return -1;//change this after completing this function
}

std::string Poly::toString()
{
	PolyNode* curr = head->next;
	std::string str;
	while (curr != NULL) {
		std::cout << curr->coeff << "X^" << curr->deg << std::endl;
		curr = curr->next;
	}
	return str;
}
