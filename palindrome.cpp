
#include <bits/stdc++.h>
#include <map>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &, const string);

// 2 8 => 2 -> 7/2 + 2 > 8
// 2 -> 5, 2 3 4
//
inline int longestPalindrome(string &s, int i, int j)
{
    int count = 0;
    int l = j - i + 1;
    for (int x = i; x < l / 2 + i; x++)
    {
        if (s.at(x) != s.at(j - x + i))
            return -1;
        else
            count++;
    }
    return l;
}
// abbaad //
int check(int mid, string &s)
{
    int r = mid, l = mid - 1;
    int r2 = mid, l2 = mid - 1;
    while (r < s.size() && l >= 0)
    {
        if (s.at(r) == s.at(l))
        {
            r++;
            l--;
        }
        else
            break;
    }

    while (r2 < s.size() && l2 >= 0)
    {
        if (s.at(r2 + 1) == s.at(l2))
        {
            r2++;
            l2--;
        }
        else
            break;
    }

    return max(r - l - 1, r2 - l2);
}
void solve(int n)
{
    string s;
    string out = "";
    cin >> s;
    int len = 1;
    int mid = 0;

    for (int i = 1; i < s.size() - 1; i++)
    {
        int max = check(i, s);
        if (max > len)
        {
            mid = i;
            len = max;
            cout << mid << " " << len << endl;
        }
    }

    out = s.substr(mid - len / 2, len);
    cout << out << endl;
}
// void solve(int n)
// {
//     string s;
//     cin >> s;
//     string max_s = "";
//     int max = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         for (int j = s.size() - 1; j > i; j--)
//         {
//             if (s.at(i) == s.at(j))
//             {
//                 int l = longestPalindrome(s, i, j);
//                 if(max < l)
//                 {
//                     max = l;
//                     max_s = s.substr(i, max);
//                 }
//             }
//         }
//     }

//     cout << max_s << endl;
// }

int main()
{
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n, N, D;
    string str;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        solve(i);
    }

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str, const string match_token)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(match_token, start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
