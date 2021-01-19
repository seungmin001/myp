#include <bits/stdc++.h>
using namespace std;

//GCD & LCM
int GCD(int x, int y)
{
    while (y != 0)
    {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int LCM(int x, int y)
//LCM= (X*Y)/GCD
{
    int gcd = GCD(x, y);
    return (x * y) / gcd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    cout << GCD(x, y) << "\n";
    cout << LCM(x, y) << "\n";

    return 0;
}