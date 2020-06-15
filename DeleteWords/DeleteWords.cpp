// lab3.cpp: определяет точку входа для консольного приложения.
//

#include <string>
#include <iostream>

using namespace std;

string deleteWords(string words, size_t length) {
	int pos = 0;
	string word;
	while (true) {
		int i = words.find(" ", pos);
		if (i == string::npos) {
			break;
		}

		word = words.substr(pos, i - pos);
		if (word.size() == length) {
			words.erase(pos, length + 1);
		}
		else {
			pos = i + 1;
		}
	}

	word = words.substr(pos);
	if (word.size() == length) {
		words.erase(pos, length);
	}

	return words;
}

int main()
{
	string words;
	size_t length;

	cout << "Input words: " << endl;
	getline(cin, words);
	cout << "Input word length: ";
	cin >> length;

	words = deleteWords(words, length);

	cout << "Result string: " << endl;
	cout << words;

	return 0;
}


