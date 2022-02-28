#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    string name;
    string value;
} Property;

int getProperties(string &s, vector<Property> &props)
{
    int ret = 0;
    if (s.find("</", 0) != string::npos)
        return -1;

    if (s.find("<", 0) != string::npos)
    {
        Property prop;
        int start = s.find(" ", 0);
        int end = s.find("=");
        while (end != -1)
        {
            start += 1;
            prop.name = s.substr(start, end - start - 1);
            int start_val = s.find("\"", start);
            if (start_val == string::npos)
                return -1;

            start_val++;

            int end_val = s.find("\"", start_val);
            prop.value = s.substr(start_val, end_val - start_val);
            props.push_back(prop);
            ret++;

            start = end_val + 1;
            end = s.find("=", start);
        }
    }
    return ret;
}

vector<string> vt;
int N, Q;

int main()
{
    scanf("%d %d\n", &N, &Q);
    string parent = "";
    while (N-- > 0)
    {
        string r;
        getline(cin, r);

        int e = r.find("</", 0);
        if (e != string::npos)
        {
            int last = parent.find_last_of(".", parent.length());
            if (last != string::npos)
                parent = parent.erase(last, parent.length() - last);
        }
        else
        {
            e = r.find("<", 0) + 1;
            int endP = r.find(" ", 0);
            if (endP == string::npos)
                endP = r.find(">", 0);
            parent += "." + r.substr(e, endP - e);
        }

        vector<Property> props;
        int ret = getProperties(r, props);

        if (ret > -1)
        {
            for (size_t i = 0; i < props.size(); i++)
            {
                string element = parent + "~" + props[i].name;
                element.erase(element.begin());
                vt.push_back(element);
                vt.push_back(props[i].value);
            }
        }
    }

    while (Q-- > 0)
    {
        string q;
        cin >> q;
        bool found = false;
        for (size_t i = 0; i < vt.size(); i += 2)
        {
            if (vt.at(i) == q)
            {
                cout << vt.at(i + 1) << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Not Found!\n";
    }

    return 0;
}
