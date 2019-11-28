#include <iostream>

using namespace std;

void replaceCharsFunc(char *word, char searchChar, char replaceChar) {
	int i = 0;
	for (; *(word + i) != '\0'; i++);
	for (int j = 0; j <= i; j++) {
		if (*(word + j) == searchChar) {
			*(word + j) = replaceChar;
		}
	}
}

void main() {
	char word[] = "hello, this is word.";
	char searchChar;
	char replaceChar;
	cin >> searchChar;
	cin >> replaceChar;

	cout << "The original string is: " << word << endl;

	replaceCharsFunc(word, searchChar, replaceChar);

	cout << "The new string is: " << word << endl;
	system("pause");
}