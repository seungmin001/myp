#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,F;
    cin >>N >>F;

    int d=N/100; //N을 100으로 나눈 몫(뒤 2자리 빼고 나머지)
    d*=100; //N에서 뒤 두자리 00으로 가정한 수 만들기
    for(int i=0;i<100;i++){ //00~99
        if((d+i)%F==0){
            if(i<10) cout<<"0"<<i<<"\n";
            else cout<<i<<"\n";
            break;
        }
    }
    return 0;
}