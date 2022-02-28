#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N;             // Number of executable code data
int M;             // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10];    // Virus data

int sol; // Correct answer

int D[10] = {0};
int max_B = INT_MIN;

void InputData(void)
{
    int i;

    cin >> N >> M;

    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (i = 0; i < M; i++)
    {
        cin >> B[i];
    }
}

void OutputData(void)
{
    cout << sol;
}

int Find(int start)
{
    int count = 0;
    int max = INT_MIN;
    int data[M] = {0};
    for (int i = 0; i < M; i++)
    {
        if (A[i + start] > max)
            max = A[i + start];
        data[i] = A[i + start];
    }

    for (int i = 0; i < M; i++)
    {
        data[i] = max - data[i];
    }
    sort(data, data + M);

    for(int i = 0; i< M; i++)
    {
        if(data[i] != D[i])
            return 0;
    }
    return 1;
}

void Solve(void)
{
    int i;

    for (int i = 0; i < M; i++)
    {
        if (B[i] > max_B)
            max_B = B[i];
    }

    for (i = 0; i < M; i++)
    {
        D[i] = max_B - B[i];
    }

    sort(D, D + M);

    for (i = 0; i <= N - M; i++)
    {
        sol += Find(i);
    }
}

int main(void)
{
    InputData(); // Input

    Solve(); // Problem solving

    OutputData(); // Output

    return 0;
}
