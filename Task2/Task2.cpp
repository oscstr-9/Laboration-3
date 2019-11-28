#include <iostream>

using namespace std;


float avrageSalary(const int WORKERS, const float *PTR_SAL) {
	float averageSal;
	float totSal = 0;
	for (int i = 0; i < WORKERS; i++) {
		totSal += *(PTR_SAL+i);
	}
	
	return totSal / WORKERS;
}

void main() {
	int workers;
	cout << "How many workers are there?" << endl;
	cin >> workers;
	float *salaries = new float[workers];
	float *ptrSal = salaries;
	

	cout << "What are their salaries?" << endl;
	for (int i = 0; i < workers; i++) {
		cin >> *(ptrSal+i);
	}

	cout << "Their avrage salary is " << avrageSalary(workers, ptrSal) << "coins." << endl;
	system("pause");
}