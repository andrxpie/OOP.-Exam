#include "std.h"

bool sortCopy(const string& a, const string& b) {
	if (a.size() == b.size()) {
		return a < b;
	} return a.size() > b.size();
}

int main()
{
	// <---sort-deque--->
	deque<string>deque2{ "Anatolii", "Anna", "Max", "Andrew" };
	sort(begin(deque2), end(deque2));
	print(deque2, " >>> deque2 sorted <<<");

	// <---rsort-deque--->
	sort(rbegin(deque2), rend(deque2));
	print(deque2);
	
	// <---sort-by-size--->
	sort(begin(deque2), end(deque2), sortCopy);
	print(deque2, " >>> deque2 sorted by str.size() <<<");

	// <---sort-list--->
	list<string>list5{ "Pablo", "Bogdan", "Vlad" };
	list5.sort();
	print(list5, " >>> list5 sort <<<");
}