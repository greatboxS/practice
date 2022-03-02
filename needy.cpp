#include <iostream>
using namespace std;

int N;       // The number of goods to send
int C[10];   // The number of BOXes(in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10]; // The number of boxes to send
int Cap[10] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};

void InputData()
{
    int i;
    cin >> N;
    for (i = 0; i < 10; i++)
    {
        cin >> C[i];
    }
}
void OutputData(int ans)
{
    int i;
    cout << ans << endl;
    for (i = 0; i < 10; i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;
}

int GetMaxBox(int &num, int index, int nIndex)
{
    if (index > 9 || index < 0)
        return -1;
    int count = 0;
    int cur = C[index];
    int next = Cap[nIndex];
    int temp = 0;

    if (index == 9)
    {
        count = num / Cap[index];
        sol[index] = count;
        return count;
    }

    while (cur > 0)
    {
        if (num - cur * Cap[index] <= 0)
        {
            while (num < cur * Cap[index])
                cur--;
        }
        temp = (num - cur * Cap[index]) % next;

        if (temp == 0)
        {
            num -= cur * Cap[index];
            break;
        }
        cur--;
    }
    count = cur;
    sol[index] = count;
    return count;
}

int main()
{
    int ans = 0;

    InputData(); //	Input function

    //	Create the code
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (C[j] == 0)
                continue;
            else
            {
                if (N > 0)
                    ans += GetMaxBox(N, i, j);
                break;
            }
        }
    }

    if (N > 0)
        ans += GetMaxBox(N, 9, 0);

    OutputData(ans); //	Output function

    return 0;
}