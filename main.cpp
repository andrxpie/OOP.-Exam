#include "std.h"

template<typename T>
void print(const T& element, const string& text) {
	cout << text << "\n";
	for (auto& e : element) {
		cout << " " << e;
	} cout << "\n\n";
}

string toUpStr(string& element) {
	transform(begin(element), end(element), begin(element), toupper);
	return element;
}

int main()
{
	list<string> list1{ "Andrew", "Yevhenii", "Max", "Yehor" };
	string deleteWord; cout << " word: "; cin >> deleteWord;
	list1.remove_if([deleteWord](string i) { if (i == deleteWord) return true; return false; });
	print(list1, " >>> list1 remove_if <<<");

	// <---CAPS--->
	transform(begin(list1), end(list1), begin(list1), toUpStr);
	print(list1, " >>> list1 upper <<<");

	// <---write-file--->
	ofstream file("saved.txt");
	ostream_iterator<string> fileIt(file, "\n");
	copy(begin(list1), end(list1), fileIt);

	return 0;
}