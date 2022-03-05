#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct point_t
{
    int x;
    int y;
} max, min;
struct space_t
{
    int color;
    int w;
    int h;
    vector<point_t> points;
    point_t max, min;
    map<int, int> overby;

    void updateMaxMin()
    {
        max = {-1, -1};
        min = {100, 100};
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i].x < min.x)
                min.x = points[i].x;
            if (points[i].y < min.y)
                min.y = points[i].y;

            if (points[i].x >= max.x)
                max.x = points[i].x;
            if (points[i].y >= max.y)
                max.y = points[i].y;
        }

        h = max.y - min.y;
        w = max.x - min.x;
    }
};

int M[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
map<int, space_t> spaces;
int Matrix[10 + 1][10 + 1];

int checkAround(int r, int c, int N)
{
    for (int i = 0; i < 4; i++)
    {
        if (M[i][0] + r >= 0 && M[i][0] + r <= N)
        {
        }
    }
}

int getMaxUnOverlayColor(int N)
{
    int result = -1;
    space_t *s = NULL;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            int col = Matrix[y][x];
            if (col == 0)
                continue;
            spaces[col].color = col;
            spaces[col].points.push_back({x, y});
        }
    }

    for (auto i = spaces.begin(); i != spaces.end(); i++)
    {
        s = &i->second;
        s->updateMaxMin();

        for (int r = s->min.y; r <= s->max.y; r++)
        {
            for (int c = s->min.x; c <= s->max.x; c++)
            {
                if (s->color != -1 && s->color != Matrix[r][c])
                {
                    s->overby[M[r][c]]++;
                }
            }
        }
    }

    for (auto i = spaces.begin(); i != spaces.end(); i++)
    {
        s = &i->second;
        if(s->w == s->h)
        {
            
        }
    }

    return result;
}

int main()
{
    char input[100];
    int N = 0, n = 0;
    cin >> N;
    while (n < N)
    {
        cin >> input;
        for (int i = 0; i < N; i++)
        {
            Matrix[n][i] = input[i] - '0';
        }
        n++;
    }

    cout << getMaxUnOverlayColor(N) << endl;

    return 0;
}