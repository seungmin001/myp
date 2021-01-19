#include <bits/stdc++.h>
using namespace std;

// find prime number

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int count = 0;
    int N;
    cin >> N;

    while (N--)
    {
        int temp;
        cin >> temp;
        bool isnotprime = false;

        for (int i = 2; i * i <= temp; i++)
        { //2~N^(1/2) 까지 나눠지는 수가 있는 지 검사
            if (temp % i == 0)
            {
                isnotprime = true;
                break;
            }
        }

        if (temp == 1)
            isnotprime = true;

        if (!isnotprime)
            count++;
    }

    cout << count;

    return 0;
}