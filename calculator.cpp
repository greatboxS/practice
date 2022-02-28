#include <iostream>
#include <istream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll GetNum(int digit, string &s);
void GetNums(int digit, char nums[], ll &out);
char GetChar(ll n);
void OutNum(int digit, ll num);

int N;       // the number of test cases
int B;       // number system
char S[110]; // first integer
char D[110]; // second integer

ll S_NUM = 0;
ll D_NUM = 0;

void InputData()
{
    memset(D, 0, 110);
    memset(S, 0, 110);
    cin >> B >> S >> D;
}
int main()
{
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        InputData(); // input function
        GetNums(B, S, S_NUM);
        GetNums(B, D, D_NUM);
        cout << B << " " << S_NUM << " " << D_NUM << " " << endl;
        // printf("%d %ld %ld\n", B, S_NUM, D_NUM);
        OutNum(B,S_NUM * D_NUM);
    }
    return 0;
}

ll GetNum(int digit, string &s)
{
    ll result = 0;
    ll negative = 1;
    vector<int> vt;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        if (*i >= 'A' && *i <= 'Z')
            vt.push_back(10 + (*i - (int)'A'));
        else if (*i >= '0' && *i <= '9')
        {
            vt.push_back(*i - '0');
        }
        else if (*i == '-')
            negative = -1;
        else
            continue;
    }

    int index = 0;
    for (auto i = vt.rbegin(); i != vt.rend(); i++)
    {
        if (*i == 0)
            continue;
        result += pow(digit, index) * (ll)(*i);
        index++;
    }

    return (result * negative);
}

void GetNums(int digit, char nums[], ll &out)
{
    string s = string(nums, nums + 110);
    out = GetNum(digit, s);
}

char GetChar(ll n)
{
    if (n >= 10 && n <= 36)
        return (char)((n - 10) + 'A');
    else if (n >= 0)
        return (char)(n + '0');
    else
        return 0;
}
void Calculator(int digit, char *s1, char *s2)
{
    vector<char> result;
    for(int i = strlen(s1); i >= 0; i--)
    {
        for(int j = strlen(s2); j >= 0; j--)
        {

        }
    }
}