#include "std.h"

bool AreSame(string a, string b) {
	return a == b;
}

bool num(const string& str) {
    return str.size() > 5;
}

string MakeEmrtyLetter(string a) {
    a[a.size() - 1] = ' ';
    return a;
}

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
    list <string> list1{ "Andrew", "Yehor", "Max", "Artem", "Oleg", "Yevhenii" };
    print(list1, " >>> list1 <<<");

    // <---find-first-char-in-list--->
    char findCh; cout << " find first char: "; cin >> findCh;
    auto it = find_if(begin(list1), end(list1), [findCh](const string& str) { return str[0] == findCh; });
    if (it != end(list1))
        cout << " finded in word: " << distance(begin(list1), it) + 1 << "\n\n";
    else
        cout << " not finded\n\n";

    // <---count-words-by-size--->
    int num; cout << " count words.size() > "; cin >> num;
    cout << " count: " << count_if(begin(list1), end(list1), [num](const string& str) { return str.size() > num; }) << "\n\n";

    // <---max-&-min-elements--->
    it = max_element(begin(list1), end(list1), [](const string& str1, const string& str2) { return str1.size() < str2.size(); });
    cout << " max: " << *it << endl;
    it = min_element(begin(list1), end(list1), [](const string& str1, const string& str2) { return str1.size() < str2.size(); });
    cout << " min: " << *it << "\n\n";

    // <---make-empty-last-letter--->
    deque<string> deque1{ "Andrew", "Yehor", "Max", "Artem", "Oleg", "Yevhenii" };
    transform(begin(deque1), end(deque1), begin(deque1), MakeEmrtyLetter);
    print(deque1, " >>> empty last letter <<<");
  
    // <---remove-key-word--->
    print(list1, " >>> list1 remove_if <<<");
    string deleteWord; cout << " word to delete: "; cin >> deleteWord;
    list1.remove_if([deleteWord](string i) { if (i == deleteWord) return true; return false; });
    print(list1, " >>> list1 removed <<<");

    // <---CAPS-WORDS--->
    transform(begin(list1), end(list1), begin(list1), toUpStr);
    print(list1, " >>> list1 upper <<<");

    // <---write-list-in-file--->
    ofstream file("saved.txt");
    ostream_iterator<string> fileIt(file, "\n");
    copy(begin(list1), end(list1), fileIt);
    file.close();

    // <---write-data-from-file--->
	list<string> list2;
	ifstream inFile ("saved.txt");
	string tmp;
	while (inFile >> tmp) {
		list2.push_back(tmp);
	} inFile.close();
	print(list2, " >>> loaded data from list");
	
	// <---delete-same-words--->
	list<string> list3{"Yehor", "Andriy", "Jenya", "Jenya", "Max"};
 	unique(begin(list3),end(list3), AreSame);
	cout << "list unique"<<endl;
	print(list3, " >>> list3 unique <<<");

    return 0;
}
