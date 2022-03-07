#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct pos_t
{
    int c;
    int r;
    int id;
};

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

int matrix[50 + 10][50 + 10] = {1};

void MapInit(int m, int n, int min_x, int min_y, int max_x, int max_y, vector<Edge> &edges)
{
    for (int r = min_y; r <= max_y; r++)
    {
        for (int c = min_x; c <= max_x; c++)
        {
            int pos1 = r * m + c;
            int pos2 = (r + 1) * m + c;

            if ((c + 1) < m && matrix[r][c] == 0 && matrix[r][c + 1] == 0)
            {
                Edge e0 = {{r, c, pos1}, {r, c + 1, pos1 + 1}, 1};
                Edge e1 = {{r, c + 1, pos1 + 1}, {r, c, pos1}, 1};

                edges.push_back(e0);
                edges.push_back(e1);
            }

            if ((r + 1) < n && matrix[r][c] == 0 && matrix[r + 1][c] == 0)
            {
                Edge e2 = {{r, c, pos1}, {r + 1, c, pos2}, 1};
                Edge e3 = {{r + 1, c, pos2}, {r, c, pos1}, 1};

                edges.push_back(e2);
                edges.push_back(e3);
            }
        }
    }
}

int bellmanFord(int n, int s, vector<Edge> &e, vector<int> &D, vector<int> &trace)
{
    D[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto E : e)
        {
            auto u = E.u;
            auto v = E.v;
            int w = E.w;
            // printf("u:%d, v:%d, w:%d\n", u.id, v.id, w);

            if (D[u.id] != INT_MAX && D[v.id] > D[u.id] + w)
            {
                D[v.id] = D[u.id] + w;
                trace[v.id] = u.id;

                // printf("D[%d] = %d, trace[%d] = %d\n", v.id, D[v.id], v.id, trace[v.id]);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("D[%d] = %d, trace[%d] = %d\n", i, D[i], i, trace[i]);
    // }

    return D[s];
}

vector<pos_t> findSuround(int N, int M, int val, pos_t &p)
{
    vector<pos_t> ret;
    if ((p.c + 1) <= (M - 1))
        if (matrix[p.r][p.c + 1] == val)
            ret.push_back({p.c + 1, p.r, p.c + 1 + M * p.r});
    if ((p.r + 1) <= (N - 1))
        if (matrix[p.r + 1][p.c] == val)
            ret.push_back({p.c, p.r + 1, p.c + M * (p.r + 1)});

    if ((p.c - 1) >= 0)
        if (matrix[p.r][p.c - 1] == val)
            ret.push_back({p.c - 1, p.r, p.c - 1 + M * p.r});

    if ((p.r - 1) >= 0)
        if (matrix[p.r - 1][p.c] == val)
            ret.push_back({p.c, p.r - 1, p.c + M * (p.r - 1)});
    return ret;
}

map<int, pos_t> skip;

void BoardMask(int N, int M, int s, pos_t p, map<int, pos_t> &b)
{
    vector<pos_t> pos = findSuround(N, M, 1, p);

    if (pos.size() <= 3)
    {
        if (b.find(p.id) == b.end())
            b[p.id] = p;
        else
            return;

        for (auto next : pos)
        {
            BoardMask(N, M, s, next, b);
        }
    }
    else
    {
        for (auto next : pos)
        {
            vector<pos_t> pos_2 = findSuround(N, M, 0, next);
            if (pos_2.size() > 0)
            {
                BoardMask(N, M, s, next, b);
            }
        }
    }
}

int solve()
{
    int N, M;
    int max_x = INT_MIN, max_y = INT_MIN;
    int min_x = INT_MAX, min_y = INT_MAX;

    cin >> N >> M;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            cin >> matrix[r][c];

            // determind the space of 2 buildings
            // get the max and min position
            if (matrix[r][c] == 1)
            {
                if (r < min_y)
                    min_y = r;
                if (c < min_x)
                    min_x = c;
                if (max_x < c)
                    max_x = c;
                if (max_y < r)
                    max_y = r;
            }
        }
    }

    map<int, pos_t> line1, line2;
    for (int r = min_y; r <= max_y; r++)
    {
        for (int c = min_x; c <= max_x; c++)
        {
            if (matrix[r][c] == 1)
            {
                pos_t p = {c, r, r * M + c};
                BoardMask(N, M, p.id, p, line1);
                break;
            }
        }
        break;
    }

    for (int r = max_y; r >= min_y; r--)
    {
        for (int c = max_x; c >= min_x; c--)
        {
            if (matrix[r][c] == 1)
            {
                pos_t p = {c, r, r * M + c};
                if (line1.find(p.id) == line1.end())
                {
                    BoardMask(N, M, p.id, p, line2);
                }
                break;
            }
        }
        break;
    }

    pos_t min1 = {INT_MAX, INT_MAX}, max1 = {INT_MIN, INT_MIN};
    pos_t min2 = {INT_MAX, INT_MAX}, max2 = {INT_MIN, INT_MIN};
    for (auto i = line1.begin(); i != line1.end(); i++)
    {
        printf("%d(%d %d), ", *i, i->second.c, i->second.r);
        if (i->second.r > max1.r)
            max1.r = i->second.r;
        if (i->second.c > max1.c)
            max1.c = i->second.c;

        if (min1.r > i->second.r)
            min1.r = i->second.r;
        if (min1.c > i->second.c)
            min1.c = i->second.c;
    }
    printf("\n");
    for (auto i = line2.begin(); i != line2.end(); i++)
    {
        printf("%d(%d %d), ", *i, i->second.c, i->second.r);
        if (i->second.r > max2.r)
            max2.r = i->second.r;
        if (i->second.c > max2.c)
            max2.c = i->second.c;

        if (min2.r > i->second.r)
            min2.r = i->second.r;
        if (min2.c > i->second.c)
            min2.c = i->second.c;
    }
    printf("\n");

    int a = max2.c -  max1.c;
    int b = max2.r - max1.r;
    int c = min2.r - max1.r;
    int d = min2.c - max1.c;

    printf("%d %d %d %d\n", a, b, c, d);

    int result = INT_MAX;
    int n = (max_x + 1) * (max_y + 1);
    vector<Edge> edges;
    vector<int> D(N * M, INT_MAX);
    vector<int> T(N * M, INT_MIN);
    MapInit(M, N, min_x, min_y, max_x, max_y, edges);

    for (auto i = line1.begin(); i != line1.end(); i++)
    {
        D.resize(n, INT_MAX);
        T.resize(n, INT_MIN);
        vector<pos_t> sur = findSuround(N, M, 0, i->second);
        for (int s = 0; s < sur.size(); s++)
        {
            // printf("from %d (%d %d)\n", sur[s].id, sur[s].c, sur[s].r);
            bellmanFord(n, sur[s].id, edges, D, T);
            for (auto j = line2.begin(); j != line2.end(); j++)
            {
                vector<pos_t> des = findSuround(N, M, 0, j->second);
                for (int p = 0; p < des.size(); p++)
                {
                    // printf("to %d (%d %d)\n", des[p].id, des[p].c, des[p].r);
                    if (result > D[des[p].id])
                    {
                        result = D[des[p].id];
                    }
                }
            }
        }
    }
    if(result == INT_MAX)
        return 0;
    return result + 1;
}

int main()
{
    cout << solve() << endl;

    return 0;
}