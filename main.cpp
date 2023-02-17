#include "std.h"
template<typename T>
void printCont(const T& str)
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
	list<string> list2;
	ifstream ifile ("list.txt");
	string tmp;
	while (ifile >> tmp)
	{
		list2.push_back(tmp);
	}
	printCont(list2);
	list<string> list3{"Yehor", "Andriy", "Jenya", "Jenya", "Max"};
	list<string> list(list2.size() + list3.size());
	//merge(begin(list2),end(list2),begin(list3),end(list3), list.begin());
	//cout << "Two lists" << endl;
	//printCont(list);
 	unique(begin(list3),end(list3), AreSame);
	cout << "list unique"<<endl;
	printCont(list3);
}