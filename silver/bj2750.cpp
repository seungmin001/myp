#include <bits/stdc++.h>
using namespace std;
//수 정렬하기 sort이용x
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >>N;
    vector<int> num;
    while(N--){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    //sort(num.begin(),num.end());
    

    for(int i=0;i<num.size();i++){
        cout<<num[i]<<'\n';
    }
    return 0;
}