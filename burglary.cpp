#include <bits/stdc++.h>
#include <map>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &, const string);
vector<bool> bool_arr;

int sum = 0;
int counter = 0;
int max_arr = 0;
int A[30] = {0};
void out(int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void combination(vector<int> &arr, int start, int end, int index, int r, int d)
{
    if (index == r)
    {
        sum = 0;
        for (int j = 0; j < r; j++)
        {
            sum += arr[j];
            if (sum == d)
                counter++;
            if (max_arr < j)
            {
                max_arr = j;
            }

            cout << sum << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        A[index] == arr[i];
        combination(arr, i + 1, end, index + 1, r, d);
    }
}

void solve(vector<int> arr, int d)
{
    bool_arr = vector<bool>(arr.size(), false);
    sort(arr.begin(), arr.end());
    auto l_bound = lower_bound(arr.begin(), arr.end(), d + 1);
    if (l_bound != arr.end())
        arr.erase(l_bound, arr.end());

    int sum = 0;
    int window = 0;
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        sum += *i;
        if (sum < d)
            window++;
    }

    if (sum < d)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    max_arr = 0;
    sum = 0;
    counter = 0;

    int ans = bur(arr.size(), arr, d);

    if (ans == -1)
        cout << "IMPOSSIBLE" << endl;
    else if (ans > 0)
        cout << ans << endl;
    else
        cout << "AMBIGIOUS" << endl;
}

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
        cin >> N >> D;
        vector<int> arr(N);
        int index = 0;
        while (N-- > 0)
        {
            cin >> arr[index++];
        }

        solve(arr, D);
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
