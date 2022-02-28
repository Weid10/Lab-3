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
	head = new PolyNode(-1, 0, NULL); // ???
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

	if (c == 0) {

		PolyNode* next;
		while (head->next != NULL) {
			next = head->next;
			delete head;
			head = next;
		}
		return;
	}

	PolyNode* ref = head;
	ref = ref->next;

	while (ref != NULL) {
		ref->deg += i;
		ref->coeff *= c;

		ref = ref->next;
	}

}

void Poly::multiplyPoly(const Poly& p)
{


}

void Poly::duplicate(Poly& outputPoly)
{                                          //why can't I create a function with NULL

    PolyNode* ref_this;
    ref_this = head;



    PolyNode* ref_out;
    ref_out = outputPoly.head;


	// clean up outputPoly
	PolyNode* next;
	while (ref_out->next != NULL) {
		next = ref_out->next;
		delete ref_out;
		head = next;
	}

	

    if(ref_this->next == NULL){  // create zero list
        ref_out->next = NULL;
        return;
    }
    ref_out->next = new PolyNode(-1, 0, NULL); //create the next node in advance
    ref_out = ref_out->next;
    ref_this = ref_this->next;

    while(ref_this!= NULL){
        ref_out->deg = ref_this->deg;
        ref_out->coeff = ref_this->coeff;
        ref_out->next = new PolyNode(-1, 0, NULL);

        if(ref_this->next == NULL){
            ref_out->next = NULL;
            return;
        }

        ref_out = ref_out->next;
        ref_this = ref_this->next;

    }


	/*
	
	while (ref_this->next != NULL) {

		ref_out->next = new PolyNode(ref_this->deg, ref_this->coeff, NULL);

		ref_this = ref_this->next;
		ref_out = ref_out->next;
	}

	*/
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
