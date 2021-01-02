#include <iostream>
using namespace std;

int T=0; //test case
int stack[10000]; //stack array
int s_size = 0; //stack size

void push(int X) 
{ //top에 X를 push
    stack[s_size] = X;
    s_size += 1;
}

void pop(){ //top에 있는 것을 pop
    int pop_num=-1;
    if(s_size){ //비어있지 않으면 저장 후 정수 빼기
        pop_num=stack[s_size-1];
        stack[s_size - 1] = -1;
        s_size -= 1;
    }
    cout << pop_num << "\n"; //비어있을 경우 -1 출력
}

void size(){ //stack size 출력함수
    cout << s_size << "\n";
}

void empty(){ //stack 비어있으면 1 아니면 0 출력
    if(s_size==0)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}

void top(){ //top에 있는 거 출력(system call function과 이름이 겹쳐 이름 변경)
    if (s_size ==0) // s_size-1 == -1이면 오류발생
        cout << -1 << "\n";
    else
        cout << stack[s_size - 1] << "\n";
    // pop할 때 초기화를 -1 로 해서 empty면 -1 출력됨
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    string action="";
    int action2=-1; // action 이 push일 경우 받을 거

    while(T--){
        cin >> action;
        if(!action.compare("push")){
            cin >> action2;
            push(action2);
        }
        else if (!action.compare("pop"))
            pop();
        else if (!action.compare("size"))
            size();
        else if (!action.compare("empty"))
            empty();
        else if (!action.compare("top"))
            top();
    }

    return 0;
}