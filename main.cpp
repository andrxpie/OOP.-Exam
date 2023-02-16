#include "std.h"

template<typename T>
void print(const T& element, const string& text) {
	cout << text << "\n";
	for (auto& e : element) {
		cout << " " << e;
	} cout << "\n\n";
}

int main()
{
	list<string> list1{ "Andrew", "Yevhenii", "Max", "Yehor" };
	list1.remove_if([](string i) { if (i == "Andrew") return true; return false; });
	print(list1, " >>> list1 remove_if <<<");

	return 0;
}