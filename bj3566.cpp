#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//40줄 로직이 가로는 가로끼리 세로는 세로끼리 비교해야하는데 그걸 생각 못했어서 헤맸다.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l_rh,l_rv,l_sh,l_sv;
    cin>>l_rh>>l_rv>>l_sh>>l_sv;

    int n; cin>>n;

    vector<int> price;
    for(int i=0;i<n;i++){

        int rh,rv,sh,sv,p;
        cin >>rh>>rv>>sh>>sv>>p;

        //나머지 0 아니면 몫+1
        //기본
        int qrh=l_rh/rh; //몫
        int r=l_rh%rh; //나머지
        if(r!=0) qrh+=1;

        int qrv=l_rv/rv;
        r=l_rv%rv;
        if(r!=0) qrv+=1;

        int qsh=l_sh/sh;
        r=l_sh%sh;
        if(r!=0) qsh+=1;

        int qsv=l_sv/sv;
        r=l_sv%sv;
        if(r!=0) qsv+=1;

        //가로최소개수 세로최소개수 구해서 곱
        int hz=qrh<qsh?qsh:qrh;
        int vt=qrv<qsv?qsv:qrv;
        int pos1=hz*vt; //기본모양 필요개수

        ////회전
        int qrh2=l_rh/rv; //몫
        r=l_rh%rv; //나머지
        if(r!=0) qrh2+=1;

        int qrv2=l_rv/rh;
        r=l_rv%rh;
        if(r!=0) qrv2+=1;

        int qsh2=l_sh/sv;
        r=l_sh%sv;
        if(r!=0) qsh2+=1;

        int qsv2=l_sv/sh;
        r=l_sv%sh;
        if(r!=0) qsv2+=1;

        //가로최소개수 세로최소개수 구해서 곱
        hz=qrh2<qsh2?qsh2:qrh2;
        vt=qrv2<qsv2?qsv2:qrv2;
        int pos2=hz*vt; //회전모양 필요개수

        //(기본,회전)더 작은걸로 최종 값 매기기
        if(pos1<pos2) price.push_back(p*pos1); 
        else price.push_back(p*pos2);
    }

    sort(price.begin(),price.end());
    cout<<price[0]<<"\n";

    return 0;
}