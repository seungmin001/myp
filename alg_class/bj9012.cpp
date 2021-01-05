#include<bits/stdc++.h>
using namespace std;
//vps 판단
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore();
    while(T--){
        stack<char> s;
        bool isvps=true; // is vps
        //input paranthesis string
        string str;
        cin >> str;

        // ( : push, ) : pop해서 (와 matching
        for(char ch: str){
            if(ch=='('){
                s.push(ch);
            }
            else{ // )인 경우
                //s이 비어있지 않다면 matching 성공
                if(!s.empty())
                    s.pop();
                else{ // ) is more than (
                    isvps=false;
                    break;
                }
            }
        }

        // 끝까지 매칭 성공하면 마지막에 stack is empty
        // if stack is not empty string is not vps
        if(!s.empty())
            isvps=false;

        if(isvps)
            cout << "YES\n";
        else
            cout << "NO\n";
        
    }

    return 0;
}