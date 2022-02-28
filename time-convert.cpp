#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
    if(s == "12:00:00AM") return string("00:00:00");
    if(s == "12:00:00PM") return string("12:00:00");
    
    string format = s.substr(s.size() - 2, 2);
    int h = stoi(s.substr(0,2));
    if(format == "PM")
        h+=12;
    else
        return s.substr(0, 8);
        
    std::ostringstream ostr;
    ostr << setfill('0') << setw(2) << h << s.substr(2,6);
    return ostr.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";

    fout.close();

    return 0;
}
