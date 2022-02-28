#ifndef __COMMON_H__
#define __COMMON_H__

#include <bits/stdc++.h>

// Time Complexity: O(n^2)
void combination(int arr[], int data[],int start, int end,int index, int r);
void combination(vector<int> &arr, vector<int> &data, int start, int end, int index, int r);

void permutation(vector<int> &arr, int index, int k, vector<bool> &picked);

string ltrim(const string &str);
string rtrim(const string &str);
vector<string> split(const string &str, const string token);
#endif // __COMMON_H__