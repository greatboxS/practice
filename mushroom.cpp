#include <iostream>
using namespace std;

int N;//Number of mushrooms
int P[150000 + 10];//Mushroom value

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

int D1[150000 + 10] = {0};
int D2[150000 + 10] = {0};
void GetMushroom(int select, int start, int &h, int D[])
{
    // select
    if(select)
    {
        if(h % 2 == 0)
            D[2*h] = P[start];
        else
            D[2*h + 1] -= P[start];
        GetMushroom(0, start + 1, ++h, D);
    }
    else
    {
        GetMushroom(1, start, h, D);
    }
}

int main(){
	int ans = -1;

	InputData();			//	Input function

	//	Write the code
	int h1 = 0, h2 = 0;
    for(int i = 0; i < N; i++)
    {
        GetMushroom(0, i, h1, D1);
        GetMushroom(1, i, h2, D2);
    }
	
	cout << h1 << endl;
	cout << h2 << endl;

    for(int i = 0; i < N; i++)
    {
        cout << D1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < N*2 + 1; i++)
    {
        cout << D2[i] << " ";
    }
    cout << endl;
	
	cout << ans << endl;	//	Output answer
	return 0;
}
