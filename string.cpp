#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
    // Complete this function
    vector<int> vt;
    int num;
    int s = 0;
    int e = str.find(",", s);
    while (e > -1)
    {
        string sub = str.substr(s, e - s);
        num = atoi(sub.c_str());
        vt.push_back(num);
        s = e + 1;
        e = str.find(",", s);
    }
    num = atoi(str.substr(s, str.length()).c_str());
    vt.push_back(num);
    return vt;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}