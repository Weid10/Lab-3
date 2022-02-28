#include "TestPoly.h"
#include <iostream>
using namespace std;

int main()
{
    // test
    std::vector<int> deg = {1,0};
    std::vector<double> co = {1,1};


    Poly hey(deg,co), aaa;

    hey.toString();
    hey.duplicate(aaa);
    aaa.toString();



	int max_degree = 1000;
	double max_coeff = 100;
	int max_eval_degree = 20;
	double max_eval_coeff = 10;
	int max_run = 50;
	vector<int> max_size_array = { 1, 5, 10 };

    double fullMark = 0;
    double totalMark = 0;

	TestPoly tp(max_degree, max_coeff, max_eval_degree, max_eval_coeff, max_run, max_size_array);


    /*
    tp.testConstructorDefault(totalMark, fullMark);
    tp.testConstructorParameters(totalMark, fullMark);
    tp.testAddMono(totalMark, fullMark);
    tp.testAddPoly(totalMark, fullMark);
    tp.testMultiplyMono(totalMark, fullMark);
    tp.testMultiplyPoly(totalMark, fullMark);
    tp.testDuplicate(totalMark, fullMark);
    tp.testEvaluate(totalMark, fullMark);
    */

    cout << "********************************" << endl;
    cout << "*** FINAL TOTAL MARK IS " << totalMark << "/" << fullMark << " ***" << endl;
    cout << "********************************" << endl;
}
