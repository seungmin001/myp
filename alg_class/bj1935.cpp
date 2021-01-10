#include <bits/stdc++.h>
using namespace std;

//후위 표기식 2 postfix notation2
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 피연산자 개수 N
    int N;
    cin >> N;
    cin.ignore();

    stack<double> notation;
    string str;
    cin >> str;

    vector<int> alphabet(N); //N개 짜리 A-Z 저장하는 vector생성

    for (int i = 0; i < N; i++)
    { //피연산자 입력
        cin >> alphabet[i];
    }

    for (char ch : str)
    {
        if (ch >= 'A' && ch <= 'A' + N - 1)
        {
            //operand push to stack
            // stack은 계산 결과도 push해줘야 하므로 push할 때는 피연산자 값을 넣어야한다.
            // A~Z 의 알파벳 >> 피연산자 배열 index : ch-'A'
            notation.push((double)alphabet[ch - 'A']);
        }
        else
        {
            //operator pop twice and operate
            //num1이 num2보다 뒤에 있음 : num2num1/
            double num1 = notation.top();
            notation.pop();
            double num2 = notation.top();
            notation.pop();

            double result;
            switch (ch)
            {
            case '+':
                result = num2 + num1;
                break;
            case '-':
                result = num2 - num1;
                break;
            case '*':
                result = num2 * num1;
                break;
            case '/':
                result = num2 / num1;
                break;
            }
            notation.push(result);
        }
    }

    cout << fixed << setprecision(2) << notation.top() << "\n";

    return 0;
}