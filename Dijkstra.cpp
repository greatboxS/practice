#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    struct apex_t
    {
        int x;
        int y;
        int id;
    } u, v;
    int w;
};

void Dijkstra(int s, int n, vector<vector<Edge>> &edges, vector<int> &D, vector<int> &T)
{
    // Init
    D.resize(n * n, INT_MAX);
    T.resize(n * n, INT_MIN);
    D[s] = 0; // start apex

    vector<bool> P(n, false);

    int max = INT_MAX;
    int apex = -1;
    // We have N * N apex of matrix
    // Loop all the apexs and find the min val of each apex
    for (int i = 0; i < n * n; i++)
    {
        int max = INT_MAX;
        int u = 0;
        for (int j = 0; j < n * n; j++)
        {
            // P[j] == true : the apex is selected,
            if (D[j] < max && P[j] == false)
            {
                u = j;
                max = D[j];
            }
        }

        P[u] = true;
        // Loop for all point from v - > u
        for (auto e : edges[u])
        {
            // Compare D[v] > D[u] + W(u->v)
            // Update new D[v] value
            if (D[e.v.id] > (D[e.u.id] + e.w))
            {
                D[e.v.id] = D[e.u.id] + e.w;
                // Update trance T[v] = e.u
                T[e.v.id] = e.u.id;
            }
        }
    }
}

vector<int> Trace(int s, int u, vector<int> &D, vector<int> &T)
{
    vector<int> path;
    if (u != s && T[u] == INT_MIN)
        goto exit;
    if (s < 0 || u < 0)
        goto exit;   

    while (u >= 0 && s != u)
    {
        path.push_back(u);
        u = T[u];
    }
    reverse(path.begin(), path.end());
exit:
    return path;
}

void MapInit(int n, vector<vector<int>> &Matrix, vector<vector<Edge>> &edges)
{
    for (int i = 0; i < (n * n); i++)
    {
        vector<Edge> e;
        edges.push_back(e);
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int pos1 = r * n + c;
            int pos2 = (r + 1) * n + c;

            if (c + 1 <= n - 1)
            {
                Edge e0 = {{r, c, pos1}, {r, c + 1, pos1 + 1}, Matrix[r][c + 1]};
                Edge e1 = {{r, c + 1, pos1 + 1}, {r, c, pos1}, Matrix[r][c]};

                edges[pos1].push_back(e0);
                edges[pos1 + 1].push_back(e1);
            }
            if (r + 1 <= n - 1)
            {
                Edge e2 = {{r, c, pos1}, {r + 1, c, pos2}, Matrix[r + 1][c]};
                Edge e3 = {{r + 1, c, pos2}, {r, c, pos1}, Matrix[r][c]};

                edges[pos1].push_back(e2);
                edges[pos2].push_back(e3);
            }
        }
    }
}

int N;
char input[110];
vector<vector<int>> Matrix;

void Input_Data()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;

        Matrix.push_back(vector<int>(N));
        for (int j = 0; j < N; j++)
        {
            Matrix[i][j] = input[j] - '0';
        }
    }
}

int main(int argc, char const *argv[])
{
    Input_Data();

    vector<int> D;
    vector<int> T;
    vector<vector<Edge>> edges;

    MapInit(N, Matrix, edges);

    int s = 2;
    Dijkstra(s, N, edges, D, T);

    vector<int> path = Trace(s, 6, D, T);

    for (int i = 0; i < D.size(); i++)
    {
        printf("D[%d]: %d T[%d]: %d\n", i, D[i], i, T[i]);
    }

    for (int i = 0; i < path.size(); i++)
    {
        printf("[%d] ", path[i]);
    }

    return 0;
}
