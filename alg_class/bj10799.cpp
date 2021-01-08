#include <bits/stdc++.h>
using namespace std;

//쇠막대기
//laser 나올 때마다 +stack size,
// 쇠막대기 하나마다 +1(stick end때마다 +1)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    stack<char> s;         // ( 괄호 넣는 stack
    int total_stick = 0;   //전체 막대기 개수
    bool before_p = false; //바로 전에 ( 였냐 : laser 구분 위함

    for (char ch : str)
    {
        if (ch == '(')
        {
            s.push(ch);
            before_p = true;
        }
        else if (ch == ')')
        {
            s.pop();
            if (before_p)
            {
                //laser입니다.
                //total += stack size
                total_stick += s.size();
            }
            else
            {
                //stick end
                //하나의 쇠막대기 존재했음 -> total +=1;
                total_stick += 1;
            }
            before_p = false;
        }
    }

    cout << total_stick << "\n";

    return 0;
}