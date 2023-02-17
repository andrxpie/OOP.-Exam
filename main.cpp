#include "std.h"

bool sortCopy(const string& a, const string& b) {
	if (a.size() == b.size()) {
		return a < b;
	} return a.size() < b.size();
}

bool areSame(string a, string b) {
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

    // <---find-first-char-in-list---> - Yevhenii
    char findCh; cout << " find first char: "; cin >> findCh;
    auto it = find_if(begin(list1), end(list1), [findCh](const string& str) { return str[0] == findCh; });
    if (it != end(list1))
        cout << " finded in word: " << distance(begin(list1), it) + 1 << "\n\n";
    else
        cout << " not finded\n\n";

    // <---count-words-by-size---> - Yevhenii
    int num; cout << " count words.size() > "; cin >> num;
    cout << " count: " << count_if(begin(list1), end(list1), [num](const string& str) { return str.size() > num; }) << "\n\n";

    // <---max-&-min-elements---> - Yevhenii
    it = max_element(begin(list1), end(list1), [](const string& str1, const string& str2) { return str1.size() < str2.size(); });
    cout << " max: " << *it << endl;
    it = min_element(begin(list1), end(list1), [](const string& str1, const string& str2) { return str1.size() < str2.size(); });
    cout << " min: " << *it << "\n\n";

    // <---make-empty-last-letter---> - Yevhenii
    deque<string> deque1{ "Andrew", "Yehor", "Max", "Artem", "Oleg", "Yevhenii" };
    transform(begin(deque1), end(deque1), begin(deque1), MakeEmrtyLetter);
    print(deque1, " >>> empty last letter <<<");
  
    // <---sort-deque---> - Yehor
	deque<string>deque2{ "Anatolii", "Anna", "Max", "Andrew" };
	sort(begin(deque2), end(deque2));
	print(deque2, " >>> deque2 sorted <<<");
  
    // <---rsort-deque---> - Yehor
	sort(rbegin(deque2), rend(deque2));
	print(deque2, " >>> deque2 rsort <<<");
	  
	// <---sort-by-size---> - Yehor
	sort(begin(deque2), end(deque2), sortCopy);
	print(deque2, " >>> deque2 sorted by str.size() <<<");
  
	// <---sort-list---> - Yehor
	list<string>list5{ "Pablo", "Bogdan", "Vlad" };
	list5.sort();
	print(list5, " >>> list5 sort <<<");
  
    // <---remove-key-word---> - Andrew
    print(list1, " >>> list1 remove_if <<<");
    string deleteWord; cout << " word to delete: "; cin >> deleteWord;
    list1.remove_if([deleteWord](string i) { if (i == deleteWord) return true; return false; });
    print(list1, " >>> list1 removed <<<");

    // <---CAPS-WORDS---> - Andrew
    transform(begin(list1), end(list1), begin(list1), toUpStr);
    print(list1, " >>> list1 upper <<<");

    // <---write-list-in-file---> - Andrew
    ofstream file("saved.txt");
    ostream_iterator<string> fileIt(file, "\n");
    copy(begin(list1), end(list1), fileIt);
    file.close();

    // <---write-data-from-file---> - Max
	list<string> list2;
	ifstream inFile ("saved.txt");
	string tmp;
	while (inFile >> tmp) {
	    list2.push_back(tmp);
	} inFile.close();
	print(list2, " >>> loaded data from list");
	  
	// <---delete-same-words---> - Max
	list<string> list3{ "Yehor", "Andriy", "Jenya", "Jenya", "Max" };
 	unique(begin(list3), end(list3), areSame);
	print(list3, " >>> list3 unique <<<");

    return 0;
}