#include "std.h"


template<typename T>
void printCont(const T& d, const string& title = "")
{
	cout << title << endl;
	for (auto& e : d)
	{
		cout << "\t" << e;
	}
	cout << endl;
}


bool cmp(const string& a, const string& b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	return a.size() > b.size();
}
int main()



{
	//task 5
	deque<string>bob{ "Tolik","Anna","Max","Andre"};
	sort(begin(bob), end(bob));

	printCont(bob);
	//task 6
	sort(rbegin(bob), rend(bob));

	printCont(bob);
	//task 7
	sort(begin(bob), end(bob), cmp);
	printCont(bob);

	//task 8

	list<string>padlo{ "Pablo","Bogdan","Vlad" };
	padlo.sort();
	printCont(padlo);

}

	















































// MAX IS GAY