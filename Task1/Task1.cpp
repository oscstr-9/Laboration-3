#include <iostream>

using namespace std;

void main() {
	char word[] = "This is a string";
	char *ptrArr = word;
	int i = 0;
	for (; *(ptrArr+i) != '\0'; i++);
	cout << "The word is " << i << " letters long." << endl;
	system("pause");
}