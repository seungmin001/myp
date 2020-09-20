#include<iostream>
using namespace std;

int main(){
    int x,y,w,h;
    cin >> x>>y>>w>>h;
    int hz,vt;
    if(w-x<x) hz=w-x;
    else hz=x;
    if(h-y<y) vt=h-y;
    else vt=y;

    if(hz<vt) cout<<hz;
    else cout<<vt;
    
    return 0;
}