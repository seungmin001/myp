#include<bits/stdc++.h>
using namespace std;

//editor . string function 사용 시 시간초과(연산 과다) >> so use stack
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string mainstream; //초기 문자열
    cin >> mainstream;
    stack<char> s1; //mainstream 들어가는 stack
    stack<char> s2; //cursor 뒤의 문자들 stack
    for(char ch: mainstream){ //top -> current cursor
        s1.push(ch);
    } 

    int M; //명령어 개수
    cin >> M;
    cin.ignore(); //getline을 위한

    while (M--)
    {
        char ins;
        cin >> ins;

        if (ins == 'L')
        { //cursor 왼쪽으로 1
            //맨 앞일 경우 무시
            if(!s1.empty()){
            s2.push(s1.top()); //s2에 cursor 우측 문자 넣음
            s1.pop(); //s1에는 cursor 왼쪽
            }
        }
        else if (ins == 'D')
        { //cursor 오른쪽 1
            //맨 뒤일 경우 무시
            if(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
            }
        }
        else if (ins == 'B')
        { // backspace
            //맨 앞일 경우 무시
            if(!s1.empty())
                s1.pop();
        }
        //else if (ins[0] == 'P')
        else if (ins == 'P')
        { //insert
            char temp;
            cin >> temp;
            //s1.push(ins[2]);
            s1.push(temp);
        }
    }
    //print answer
    // string 자체를 사용하면 오바됨. 추가/삭제 연산이 O(N)이기 때문.
    //s1은 원래 문장 상 맨 뒤부터 pop이 되어 거꾸로 넣음
    //따라서 왼쪽 stack모두 오른쪽 stack으로 이동시키고 모두 출력.
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    //s2는 앞부터  순서대로 pop되어서 그냥 출력.
    while(!s2.empty()){
        cout<<s2.top();
        s2.pop();
    }
    cout <<"\n";
    return 0;
}