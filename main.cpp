#include <iostream>
#include <list>
#include <algorithm>
#include <deque>
using namespace std;

bool num(const string& str)
{
    return str.size() > 5;
}

string MakeEmrtyLetter(string a)
{
    a[a.size() - 1] = ' ';
    return a;
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
}
