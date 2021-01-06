#include <bits/stdc++.h>
using namespace std;

//queue / 요세푸스
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    queue<int> queue;

    int N, K;
    cin >> N >> K;

    cout << "<";
    //초기데이터 입력
    for (int i = 1; i <= N; i++)
    {
        queue.push(i);
    }

    while (!queue.empty())
    {
        int count = 1;
        while (count != K)
        { //K번째 전까지는 빼서 뒤로 넣으며 pass
            int temp = queue.front();
            queue.pop();
            queue.push(temp);
            count++;
        }
        //count == K pop해서 버려야함
        if (queue.size() != 1)
            cout << queue.front() << ", ";
        else //size 1일 때 쉼표 안 넣음
            cout << queue.front();
        queue.pop();
    }

    cout << ">";

    return 0;
}