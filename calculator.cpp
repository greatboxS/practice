#include <iostream>
#include <istream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define BUFF_SIZE (110 * 2)
int GetNum(int digit, char c);
char GetChar(int n);
void Calculator(int digit, char *s1, char *s2);

int N;       // the number of test cases
int B;       // number system
char S[110]; // first integer
char D[110]; // second integer

void InputData()
{
    memset(D, 0, 110);
    memset(S, 0, 110);
    cin >> B >> S >> D;
}
int main()
{
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        InputData(); // input function
        Calculator(B, S, D);
    }
    return 0;
}

int GetNum(int digit, char c)
{
    int result = 0;
    if (c >= 'A' && c <= 'Z')
        result = 10 + (c - (int)'A');
    else if (c >= '0' && c <= '9')
    {
        result = c - '0';
    }
    else
        result = 0;
    return result;
}

char GetChar(int n)
{
    if (n >= 10 && n <= 36)
        return (char)((n - 10) + 'A');
    else if (n >= 0)
        return (char)(n + '0');
    else
        return 0;
}

void Calculator(int digit, char *s1, char *s2)
{
    bool negative = false;
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int num1 = 0, num2 = 0;
    int index = 0, div = 0, k = 0;
    int result[BUFF_SIZE + 1] = {0};
    char s3[BUFF_SIZE + 1] = {0};

    if ((s1[0] == '-' && s2[0] != '-') || (s1[0] != '-' && s2[0] == '-'))
        negative = true;

    for (int i = n1 - 1; i >= 0; i--)
    {
        if (s1[i] == '-')
            continue;
        num1 = GetNum(digit, s1[i]);

        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s2[i] == '-')
                continue;
            num2 = GetNum(digit, s2[j]);
            k = (BUFF_SIZE - index) - (n2 - 1 - j);
            result[k] += num1 * num2;
            div = result[k] / digit;
            result[k] = result[k] % digit;
            result[k - 1] += div;
            s3[k] = GetChar(result[k]);
            s3[k - 1] = GetChar(result[k - 1]);
        }
        index++;
    }

    string s = string(&s3[k - 1], s3 + BUFF_SIZE + 1);

    int r = 0;
    for(auto i = s.begin(); i != s.end(); i++)
    {
        if(*i != '0')
            break;
        *i = 0;
        r++;
    }
    s = s.substr(r, s.length() - r);
    if(s == "")
        cout << 0 << endl;
    else
    {
        if(negative)
            cout << "-" ;
        cout << s << endl;
    }
}