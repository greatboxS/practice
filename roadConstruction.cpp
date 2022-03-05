#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    struct pos_t
    {
        int r;
        int c;
        int id;
    } u, v;
    int w;
    int type;
};

int N;
char input[110];
int Matrix[110][110];
vector<struct Edge> edges;

void Input_Data()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;

        for (int j = 0; j < N; j++)
        {
            Matrix[i][j] = input[j] - '0';
        }
    }
}

int bellmanFord(int n, int s, vector<Edge> &e, vector<int> &D, vector<int> &trace)
{
    // e: danh sách cạnh
    // n: số đỉnh
    // s: đỉnh bắt đầu
    // D: độ dài đường đi ngắn nhất
    // trace: mảng truy vết đường đi
    // INF nếu không có đường đi
    // -INF nếu có đường đi âm vô tận
    D.resize(n * n + 10, 1000000);
    trace.resize(n * n + 10, -1);

    D[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto E : e)
        {
            auto u = E.u;
            auto v = E.v;
            int w = E.w;

            printf("u:%d, v:%d, w:%d\n", u.id, v.id, w);

            if (D[u.id] != -1 && D[v.id] > D[u.id] + w)
            {
                D[v.id] = D[u.id] + w;
                trace[v.id] = u.id;

                printf("D[%d] = %d, trace[%d] = %d\n",v.id, D[v.id], v.id, trace[v.id]);
            }
        }
    }

    for (int i = 0; i < n * n; i++)
    {
        printf("D[%d] = %d, trace[%d] = %d\n", i, D[i], i, trace[i]);
    }

    return D[n * n - 1];
}

vector<int> trace_path(vector<int> &trace, int S, int u)
{
    if (u != S && trace[u] == -1)
        return vector<int>(0); // không có đường đi

    vector<int> path;
    while (u != -1)
    { // truy vết ngược từ u về S
        path.push_back(u);
        u = trace[u];
    }
    reverse(path.begin(), path.end()); // cần reverse vì đường đi lúc này là từ u về S

    for (int i = 0; i < path.size(); i++)
    {
        cout << "u: " << path[i] << endl;
    }

    return path;
}

void MapInit(int n)
{
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			int pos1 = r * N + c;
			int pos2 = (r + 1) * N + c;
			if (c + 1 <= N - 1)
			{
				Edge e0 = {{r, c, pos1}, {r, c + 1, pos1 + 1}, Matrix[r][c + 1], -1};
				Edge e1 = {{r, c + 1, pos1 + 1}, {r, c, pos1}, Matrix[r][c], -1};
				if (r == 0 && c == 0)
					e1.type = 1;
				else if (r == n - 1 && c == n - 1)
					e1.type = 2;
				else
					e1.type = 3;
				edges.push_back(e0);
				edges.push_back(e1);
				
			}
			if (r + 1 <= N - 1)
			{
				Edge e2 = {{r, c, pos1}, {r + 1, c, pos2}, Matrix[r + 1][c], -1};
				Edge e3 = {{r + 1, c, pos2},{r, c, pos1}, Matrix[r][c], -1};
				
				if (r == 0 && c == 0)
					e2.type = 1;
				else if (r == n - 1 && c == n - 1)
					e2.type = 2;
				else
					e2.type = 3;
				edges.push_back(e2);
				edges.push_back(e3);
				
			}
		}
	}
}

int main()
{
    int ans = -1;
    Input_Data(); //	Input function

    //	Write the code
    MapInit(N);

    vector<int> D;
    vector<int> T;

    ans = bellmanFord(N, 0, edges, D, T);
    trace_path(T, 0, 8);

    cout << ans << endl; //	Output answer

    return 0;
}
