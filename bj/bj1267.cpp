#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    
    int y=0,m=0;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp; //한 통화
        y+=temp/30+1;
        m+=temp/60+1;
    }
    
    if(y*10<m*15) cout<<"Y "<<y*10<<"\n";
    else if(y*10>m*15) cout<<"M "<<m*15<<"\n";
    else cout<<"Y M "<<y*10<<"\n";
    
    return 0;
}