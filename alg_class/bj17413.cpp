#include <bits/stdc++.h>
using namespace std;

//단어 뒤집기2 : 단어만 뒤집기, 뒤집기 -> stack
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    getline(cin, S);
    S += " ";

    stack<char> word_stack;
    bool istag = false;
    for (char ch : S)
    {
        if (ch == ' ')
        {
            //공백 : 단어는 공백으로 구분, 단어 거꾸로 출력
            if (!istag) //단어 구분 공백 일때
            {
                while (!word_stack.empty())
                {
                    cout << word_stack.top();
                    word_stack.pop();
                }
            }
            //태그 안에서는 그냥 출력
            cout << " ";
        }
        else if (ch == '<')
        {
            //tag start, 그 전에 push되었던 단어 출력 후 진행
            while (!word_stack.empty())
            {
                cout << word_stack.top();
                word_stack.pop();
            }

            cout << "<";
            istag = true;
        }
        else if (ch == '>')
        {
            //tag end
            cout << ">";
            istag = false;
        }
        else
        {
            if (!istag) //단어
                word_stack.push(ch);
            else //태그
                cout << ch;
        }
    }

    return 0;
}

//출력해주는 함수 이용해도됨
//void print(stack<char> &s){
//     while(!s.empty()){
//         cout<<s.top();
//         s.pop();
//     }
// }