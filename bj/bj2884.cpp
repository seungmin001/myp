#include<iostream>
using namespace std;
int main(){
    int H,M;
    cin >> H >>M;
    //M
    if(M>=0 && M<45){
        if(H>=1 && H<=23)
            H=H-1;
        else if(H==0)
            H=23;
        M=M+15; //60-(45-M)
    }
    else if(M>=45 && M<=59){
        M=M-45;
    }
    cout<<H<<" "<<M<<endl;
    return 0;
}