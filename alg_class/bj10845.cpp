#include <bits/stdc++.h>
using namespace std;

//queue
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    int queue[10000];
    int begin = 0;
    int end = 0;
    while (N--)
    {
        string ins;
        cin >> ins;

        if (ins == "push")
        {
            int X;
            cin >> X;
            queue[end++] = X;
        }
        else if (ins == "pop")
        {
            if (begin == end)
            {
                cout << "-1\n";
            }
            else
            {
                cout << queue[begin++] << "\n";
            }
        }
        else if (ins == "size")
        {
            cout << end - begin << "\n";
        }
        else if (ins == "empty")
        {
            if (begin == end)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (ins == "front")
        {
            if (begin == end)
                cout << "-1\n";
            else
                cout << queue[begin] << "\n";
        }
        else if (ins == "back")
        {
            if (begin == end)
                cout << "-1\n";
            else
                cout << queue[end - 1] << "\n";
        }
    }
    return 0;
}