#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;//The number of candidates
int A[100000 + 10];//Temperament value

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

void GetPair()
{
	int l = 0, r = N - 1;
	int min = 1000;
	int sub = 0;
	int first = 0, snd = 0;
	while(l < r)
	{
		sub = abs(A[r] + A[l]);
        cout << l << "  " << r << endl;
		if(sub < min)
		{
			min = sub;
			first = l;
			snd = r;

            if(sub == 0)
                break;
		}

        if(abs(A[l]) > A[r])
            l++;
        else r--;
	}

	cout << first << " " << snd << endl;
}

int main(){
	InputData();//	Input function

	//	Create the code
	GetPair();

	return 0;
}
