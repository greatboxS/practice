#include <iostream>
#include <climits>
using namespace std;

int N;                    // Number of buildings
int H[80010] = {INT_MAX}; // Height of buildings

void Input_Data(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
}

long long Solve(int n, int *h)
{
    long long ans = 0;
    int c[n + 10] = {0};
    int prev = 0;
    for (int i = 1; i < n; i++)
    {
        if (h[i] < h[i - 1])
        {
            c[i] = c[i - 1] + 1;
        }
        else
        {
            if (h[i] >= h[prev])
            {
                prev = i;
                c[prev] = 0;
            }
            else
            {
                for (int k = i - 1; k >= prev; k++)
                {
                    if (c[k] > c[i])
                    {
                        c[i] = c[k] + 1;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        ans += h[i];
    }
}

long long Solve2(int n, int *H)
{
    long long ans = 0;
    int prev = 0;
    int h[n + 10] = {0};
    for (int i = 0; i < N - 1; i++)
    {
        if (H[i + 1] < H[i])
        {
            h[i + 1] = h[i] + 1;
        }
        else
        {
            if (H[i + 1] >= H[prev])
            {
                prev = i + 1;
                h[prev] = 0;
            }
            else
            {
                for (int j = i; j >= prev; j--)
                {
                    if (H[j] > H[i + 1])
                    {
                        h[i + 1] = h[j] + 1;
                        prev = j;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        ans += h[i];
    }
    return ans;
}

int main()
{
    long long ans = 0;
    Input_Data(); //	Input function
    ans = Solve(N, H);
    cout << ans << endl; //	Output right answer
    return 0;
}
