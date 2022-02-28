/* Enter your macros here */
#define io(x) cin >> v
#define INF 10000000
#define toStr(...) (#__VA_ARGS__)
#define foreach(vector, i) for (int i = 0; i < vector.size(); i++)

#define FUNCTION(f_name, _opt)                     \
    void(f_name)(int &max_min, int &val)           \
    {                                              \
        printf("mm: %d, val: %d\n", max_min, val); \
        if ((val)_opt(max_min))                    \
            max_min = val;                         \
    }

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    foreach (v, i)
    {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach (v, i)
    {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
        cout << v[i] << " " << mn << " " << mx << endl;
    }
    int ans = mx - mn;
    cout << toStr(Result =) << ' ' << ans;
    return 0;
}