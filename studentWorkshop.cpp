#include <bits/stdc++.h>

using namespace std;

// Define the structs Workshops and Available_Workshops.
// Implement the functions initialize and CalculateMaxWorkshops
struct workshop
{
    int s;
    int d;
    int e;
    workshop(int ss, int dd)
    {
        s = ss;
        d = dd;
        e = dd + ss;
    }
    bool operator<(const workshop &ws)
    {
        return (this->e < ws.e);
    }
};

struct Available_Workshops
{
    vector<workshop> nodes;
    int n;
};

Available_Workshops *initialize(int *s_time, int *duration, int n)
{
    Available_Workshops *ws = new Available_Workshops[1];
    ws->n = n;
    for (int i = 0; i < n; i++)
    {
        ws->nodes.push_back(workshop(s_time[i], duration[i]));
    }
    sort(ws->nodes.begin(), ws->nodes.end());
    return ws;
}

int CalculateMaxWorkshops(Available_Workshops *ws)
{
    int ret = 1;
    int e_smallest = ws->nodes[0].e;
    for (int i = 1; i < ws->n; i++)
    {
        if (ws->nodes[i].s >= e_smallest)
        {
            ret++;
            e_smallest = ws->nodes[i].e;
        }
    }

    return ret;
}

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
