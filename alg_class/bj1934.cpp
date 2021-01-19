#include <bits/stdc++.h>
using namespace std;

//LCM

int GCD(int x, int y)
//euclidean
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

    int T;
    cin >> T;

    while (T--)
    {
        int A, B;
        cin >> A >> B;

        //LCM은 GCD를 구한 후, 그것을 이용하여 구한다.
        cout << LCM(A, B) << "\n";
    }

    return 0;
}