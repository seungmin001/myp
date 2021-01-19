#include <bits/stdc++.h>
using namespace std;

//print prime number
//sieve of eratosthenes
bool check[1000000];

void sieve(vector<int> &num, const int m, const int n)
{
    for (int i = 2; i <= n; i++) //2의배수부터 검사
    {

        for (int j = i * 2; j <= n; j += i) //2*2 2*3 ..
        {
            check[j - 1] = true; // not prime
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (i == 1)
            continue;
            
        if (!check[i - 1]) //check 되지 않았으니 prime
            num.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<int> prime;

    sieve(prime, M, N);

    for (int i = 0; i < prime.size(); i++)
    {
        cout << prime[i] << "\n";
    }

    return 0;
}