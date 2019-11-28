#include <iostream>

using namespace std;

void sort_swap(int **a, int **b, int **c, bool order) {
	int temp;

	if (order == false) { // sorts descending order
		temp = **a;
		if (**a < **b && **b > **c) {
			temp = **a;
			**a = **b;
			**b = temp;
		}
		else if (**a < **c) {
			temp = **a;
			**a = **c;
			**c = temp;
		}
		if (**b < **c) {
			temp = **b;
			**b = **c;
			**c = temp;
		}
	}

	else { // sorts ascending order
		if (**a > **b && **b < **c) {
			temp = **a;
			**a = **b;
			**b = temp;
		}
		else if (**a > **c) {
			temp = **a;
			**a = **c;
			**c = temp;
		}
		if (**b > **c) {
			temp = **b;
			**b = **c;
			**c = temp;
		}
	}
}

void main() {
	int inA, inB, inC;
	int *a = &inA, *b = &inB, *c = &inC;
	bool order;
	while (true) {
		cout << "Enter 3 numbers:" << endl;
		cout << "press 0 to quit" << endl;
		cin >> inA;
		if (inA == 0) {
			break;
		}
		cin >> inB;
		cin >> inC;

		cout << endl << "press 1 to sort in ascending order or 0 for descending:" << endl;
		cout << endl;
		cin >> order;
		cout << endl;

		sort_swap(&a, &b, &c, order);
		cout << *a << " " << *b << " " << *c << endl;
		cout << endl;
	}
}