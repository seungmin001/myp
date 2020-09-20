#include<iostream>
#include<math.h>
using namespace std;
int bj1009(int a,int b){
    int ans=1;
    for(int i=0;i<b;i++){
        //10개니까 일의 자리 숫자만 살리면서 가면 오버플로우 안생기고 갈 수 있음
        ans*=a;
        ans%=10;    
    }
    if(ans==0)  ans=10;
    return ans;
}

int bj1009_opt(int a,int b){    //빠른 정답
    a%=10;  //일의 자리만 확인
    b%=4;   //모든 수는 4주기로 같은 일의자리 숫자가 나옴
    if(b==0)    b=4;    //0제곱하면 1되니까 4로처리

    int ans=(int)pow(a,b)%10;
    if(ans==0)  ans=10; //0나오면 10번 컴퓨터
    return ans;
}

int main(){
    int T,a,b;
    cin >> T;
    while(T--){
        cin >>a>>b;
        cout<<bj1009_opt(a,b)<<"\n";
    }
    return 0;
}
