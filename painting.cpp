#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct space_t
{
	struct point_t
	{
		int x;
		int y;
	} max, min;
	
	int exit;
	vector<int> overby;
};

int Matrix[10 + 1][10 + 1];

int getMaxUnOverlayColor(int N)
{
	map<int, space_t> color_map;
	space_t *s;

	for (int i = 0; i < 10; i++)
	{
		color_map[i] = {{-1, -1}, {-1, -1}, -1};
	}

	set<int> max_col;

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			int col = Matrix[r][c];
			if (col == 0)
				continue;

			s = &color_map[col];
			s->exit = col;
			max_col.insert(col);
			s->max.y = r;
			s->max.x = c;

			if (s->min.x == -1)
				s->min.x = c;
			if (s->min.y == -1)
				s->min.y = r;
		}
	}

	for (auto i = max_col.begin(); i != max_col.end(); i++)
	{
		s = &color_map[*i];
		if (*i == 0)
			continue;

		for (auto j = max_col.rbegin(); j != max_col.rend(); j++)
		{
			if (*j == *i)
				continue;

			for (int c = s->min.x; c <= s->max.x; c++)
			{
				for (int r = s->min.y; r <= s->max.y; r++)
				{
					if (Matrix[r][c] == *j)
					{
						space_t *ov = &color_map[*j];
						if (find(ov->overby.begin(), ov->overby.end(), *i) == ov->overby.end())
						{
							s->overby.push_back(*j);
							printf("[%d] overlay by [%d]\n", *i, *j);
						}
					}
				}
			}
		}
		if (s->max.x - s->min.x == s->max.y - s->min.y)
		{
			// j already overlay i so check other
			printf("[%d] is square (%d,%d), (%d, %d)\n", s->exit, s->max.x, s->max.y, s->min.x, s->min.y);
			int col = -1;
			int max = -1;
			for (auto k = max_col.rbegin(); k != max_col.rend(); k++)
			{
				if (*k == *i)
					continue;
				space_t *s3 = &color_map[*k];
				auto f = find(s3->overby.begin(), s3->overby.end(), *i);
				if (f != s3->overby.end())
					continue;

				for (int c = s3->min.x; c <= s3->max.x; c++)
				{
					for (int r = s3->min.y; r <= s3->max.y; r++)
					{
						if (s->max.x + 1 == c && s->min.y <= r && s->max.y >= r ||
							s->min.x - 1 == c && s->min.y <= r && s->max.y >= r ||
							s->max.y + 1 == r && s->min.x <= c && s->max.x >= c ||
							s->max.y - 1 == r && s->min.y <= c && s->max.y >= c)
						{
							if (col == -1)
							{
								col = *k;
								max = s3->overby.size();
							}
							else
							{
								if (s3->overby.size() > max)
								{
									max = s3->overby.size();
									col = *k;
								}
							}

							printf("find other overlay %d, (%d,%d), (%d, %d)\n", s3->exit, s3->max.x, s3->max.y, s3->min.x, s3->min.y);
						}
						// break;
					}
				}
			}

			s->overby.push_back(col);
		}
	}

	for (int i = 0; i < color_map.size(); i++)
	{
		s = &color_map[i];
		if (s->exit == -1)
			continue;

		if (s->overby.size() == 0)
			continue;

		for (int c = 0; c < s->overby.size(); c++)
		{
			max_col.erase(s->overby[c]);
		}
	}

	return max_col.size();
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