#include <iostream>
using namespace std;

int N;              // Number of mushrooms
int P[150000 + 10]; // Mushroom value

void InputData()
{
	cin >> N;
	P[0] = -1;
	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
	}
	P[N + 1] = -1;
}

int find_max(int i)
{
	if (P[i + 1] >= P[i] && P[i + 1] >= P[i + 2])
		return P[i + 1];
	else
		return -1;
}

int find_min(int i)
{
	if (P[i + 1] <= P[i] && P[i + 1] <= P[i + 2])
		return P[i + 1];
	else
		return -1;
}

int GetMushroom()
{
	int max_val = 0;
	int pos = 0;
	for (int i = 0; i < N; i++)
	{
		if (pos % 2 == 0)
		{
			int max = find_max(i);
			if (max == -1)
				continue;
			max_val += max;
			pos++;
		}
		else
		{
			int min = find_min(i);
			if (min == -1)
				continue;
			max_val -= min;
			pos++;
		}
	}
	return max_val;
}

int main()
{
	int ans = -1;

	InputData(); //	Input function

	//	Write the code

	ans = GetMushroom();

	cout << ans << endl; //	Output answer
	return 0;
}
