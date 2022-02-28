#include <bits/stdc++.h>

using namespace std;
// Implement the class Box
// l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

class Box
{
private:
    long long l, b, h;
    long long cal;

public:
    Box(int _l, int _b, int _h)
    {
        l = _l;
        b = _b;
        h = _h;
        cal = l * b * h;
    }
    Box() : l(0), b(0), h(0), cal(0)
    {
    }

    int getLength() { return l; }
    int getBreadth() { return b; }
    int getHeight() { return h; }
    long long CalculateVolume() { return cal; }
    bool operator<(Box &b)
    {
        if (this->l < b.l)
            return true;
        else if (this->b < b.b && this->l == b.l)
            return true;
        else if (this->h < b.h && this->b == b.b && this->l == b.l)
            return true;

        return false;
    }

    friend ostream &operator<<(ostream &out, Box &B);
};

ostream &operator<<(ostream &out, Box &B)
{
    out << B.l << " " << B.b << " " << B.h;
    return out;
}

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}