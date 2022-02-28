#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'beautifulStrings' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING s as parameter.
 */


long beautifulStrings(string s) {
    char same_char[3] = {0};
    int counter = 0;
    for(int r =0; r <= s.size() - 2; r++)
    {
        for(int c = r + 1; c < s.size(); c ++)
        {
            if(c < s.size() - 1)
            {
                if(s.at(c) == s.at(c+1))
                {
                    counter ++;
                    c ++;
                }
                else counter ++;
            }
            else counter ++;
            
        }
    }
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long result = beautifulStrings(s);

    cout << result << "\n";

    fout.close();

    return 0;
}
