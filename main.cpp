#include "std.h"


template<typename T>
void printCont(const T& d, const string& title = "")
{
	cout << title << endl;
	for (auto& tmp : d)
	{
		cout << "\t" << tmp;
	}
	cout << endl;
}
bool cmp(const string& a, const string& b)
{
	if (a.size() == b.size())
	{
		return a > b;
	}
	return a.size() > b.size();
}
int main()



{
	//task 5
	deque<string>tmp{ "Tolik","Anna","Max","Andre"};
	sort(begin(tmp), end(tmp));

	printCont(tmp);
	//task 6
	sort(rbegin(tmp), rend(tmp));

	printCont(tmp);
	//task 7
	sort(begin(tmp), end(tmp), cmp);
	printCont(tmp);
}

	















































// MAX IS GAY