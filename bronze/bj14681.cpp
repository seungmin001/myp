#include<iostream>
using namespace std;
int main(){
    int x,y;
    cin >> x >> y;
    if(x*y>0 && x*y<=1000000){
        if(x>0)
            cout<<"1";
        else
            cout<<"3";
    }
    else if(x*y<0 && x*y>=-1000000){
        if(x<0)
            cout<<"2";
        else
            cout<<"4";       
    }
    return 0;
}