#include <bits/stdc++.h>
using namespace std;

//스택 수열
//output : push + pop - impossible NO

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<int> s;
    int N; //test case
    cin >> N;
    string ans = ""; // +- 기록
    int count = 0;   //+1 next number to push
    bool isno=false;
    // 1~N 까지 오름차순으로 넣음
    while (N--)
    {
        int num;
        cin >> num;

        //first num
        if (s.empty())
        {
            //push until num is top
            while (count != num)
            {
                s.push(count + 1);
                ans += "+\n";
                count += 1;
            }
            s.pop();
            ans += "-\n";
        }
        else
        {
            //현재 top보다 같거나 큰 수면 ok
            if (num > s.top())
            { //크면 그때까지 push한 후 pop
                while (num != s.top())
                {
                    s.push(count + 1);
                    count += 1;
                    ans += "+\n";
                }
                s.pop();
                ans += "-\n";
            }
            else if (num == s.top())
            { //같으면 바로 pop
                s.pop();
                ans += "-\n";
            }
            else
            { // impossible
                isno=1;
            }
        }
    }
    //print answer
    if(isno)
        cout<<"NO\n";
    else
        cout << ans;

    return 0;
}