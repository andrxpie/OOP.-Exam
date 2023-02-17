#include "std.h"

bool num(const string& str)
{
    return str.size() > 5;
}

string MakeEmrtyLetter(string a)
{
    a[a.size() - 1] = ' ';
    return a;

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
    //TASK 1
    list <string> a{ "Andrii", "Egor", "Maxim", "Artem", "Oleg", "Zhenya" };
    char tmp2;
    cin >> tmp2;

    auto it = find_if(begin(a), end(a), [tmp2](const string& str) {

        return str[0] == tmp2;

        });

    cout << distance(begin(a), it);

    //task 2
    cout << "number of word which has more than 5 letters " << count_if(begin(a), end(a), num);



    // task 3
    auto it = max_element(begin(a), end(a), [](const string& str1, const string& str2) {
        return str1.size() < str2.size();
        });

    cout << *it << endl;

    it = min_element(begin(a), end(a), [](const string& str1, const string& str2) {
        return str1.size() < str2.size();
        });


    cout << *it;

    deque<string> b{ "Andrii", "Egor", "Maxim", "Artem", "Oleg", "Zhenya" };

    transform(begin(b), end(b), begin(b), MakeEmrtyLetter);

    for (auto& i : b)
    {
        cout << i << endl;
    }
  
  // <---remove-key-word--->
	list<string> list1{ "Andrew", "Yevhenii", "Max", "Yehor" };
	string deleteWord; cout << " word: "; cin >> deleteWord;
	list1.remove_if([deleteWord](string i) { if (i == deleteWord) return true; return false; });
	print(list1, " >>> list1 remove_if <<<");

	// <---CAPS-WORDS--->
	transform(begin(list1), end(list1), begin(list1), toUpStr);
	print(list1, " >>> list1 upper <<<");

	// <---write-list-in-file--->
	ofstream file("saved.txt");
	ostream_iterator<string> fileIt(file, "\n");
	copy(begin(list1), end(list1), fileIt);

	return 0;
}
