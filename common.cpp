#include "common.h"
using namespace std;

void combination(int arr[], int data[], int start, int end, int index, int r)
{
    // Current combination is ready
    // to be printed, print it
    if (index == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }

    // replace index with all possible
    // elements. The condition "end-i+1 >= r-index"
    // makes sure that including one element
    // at index will make a combination with
    // remaining elements at remaining positions
    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combination(arr, data, i + 1, end, index + 1, r);
    }
}

void combination(vector<int> &arr, vector<int> &data, int start, int end, int index, int r)
{
    combination(arr.data(), data.data(), start, end, index, r);
}

void out(vector<int> &arr, int index)
{
    for(int i = 0; i< index; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void permutation(vector<int> &arr, int index, int k, vector<bool> &picked)
{
    for(int i = 0; i < arr.size(); i ++)
    {
        if(!picked[i])
        {
            if(index == k)
                out(arr, k);
            else
            {
                picked[i] = true;
                permutation(arr, index + 1, k, picked);
                picked[i] = false;
            }
        }
    }
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str, const string token) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(token, start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
