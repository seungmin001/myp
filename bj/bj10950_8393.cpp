#include<iostream>
using namespace std;
int main(){
    //b10950
    int T,A,B;
    cin >>T;
    for(int i=0;i<T;i++){
        cin >>A >> B;
        if(A>0 && A<10 && B>0 && B<10)
            cout<<A+B<<endl;
    }
    return 0;
}

void b8393(){
    int N,sum=0;
    cin >>N;
    if(N>=1 && N<=10000){
        for(int i=1;i<=N;i++){
            sum+=i;
        }   
    }
    cout<<sum<<endl;
    return;
}