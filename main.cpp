#include "std.h"
template<typename T>

void print(const T& str)
{
	for (auto& i : str)
	{
		cout << i << " ";
	}cout << endl;

}

bool AreSame(string a, string b)
{
	return a == b;
}

int main()
{
	// <--write-data-from-file-->
	list<string> list2;
	ifstream inFile ("list.txt");
	string tmp;
	while (inFile >> tmp)
	{
		list2.push_back(tmp);
	}
	print(list2);
	
	list<string> list3{"Yehor", "Andriy", "Jenya", "Jenya", "Max"};
	// <--merge-->
	//list<string> list(list2.size() + list3.size());
	//merge(begin(list2),end(list2),begin(list3),end(list3), list.begin());
	//cout << "Two lists" << endl;
	//print(list);
	
	// <--delete-same-words-->
 	unique(begin(list3),end(list3), AreSame);
	cout << "list unique"<<endl;
	print(list3);
}
