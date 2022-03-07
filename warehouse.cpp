#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Edge
{
    int u;
    int v;
    int w;
};

int N, M;

vector<Edge> edges;

int shortestPath(int s)
{
    int result = INT_MIN;
    vector<int> D(N + 10, 10000);
    vector<int> P(N + 10, 0);

    D[s] = 0;

    for (int i = 1; i <= N; i++)
    {
        int u = 0;
        int max = INT_MAX;
        for (int j = 1; j <= N; j++)
        {
            if (P[j] == 0 && D[j] < max)
            {
                u = j;
                max = D[j];
                break;
            }
        }

        P[u] = 1;

        for (auto e : edges)
        {
            if (D[e.v] > (D[e.u] + e.w))
            {
                D[e.v] = D[e.u] + e.w;
            }
        }
    }

    for (int j = 1; j <= N; j++)
    {
        if (D[j] > result)
        {
            result = D[j];
        }
    }

    return result;
}

int main()
{

    cin >> N >> M;

    int n = N;
    int m = M;
    while (m-- > 0)
    {
        Edge e1, e2;
        cin >> e1.u >> e1.v >> e1.w;
        e2 = {e1.v, e1.u, e1.w};

        edges.push_back(e1);
        edges.push_back(e2);
    }

    int min = INT_MAX;
    for (int i = 1; i <= N; i++)
    {
        int val = shortestPath(i);
        if (min > val)
            min = val;
    }
    cout << min << endl;
    return 0;
}