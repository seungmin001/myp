#include <bits/stdc++.h>
using namespace std;

//오등큰수 frequency NGF
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    //모두 int array로 했더니 프로그램 시작이 안됨. segmentation fault
    //int array[1000001]={0};//input number array
    int freq[1000001] = {0}; //frequency array
    //int NGF[1000001]={0};//NGF array
    vector<int> array;
    vector<int> NGF;
    array.push_back(0); //index 0 채우기용
    NGF.push_back(0);   //index 0 채우기용

    //index : i , value : array[i] , freq of value : freq[array[i]]
    //먼저 모든 입력값의 frequency를 구해놓는다.
    for (int i = 1; i <= N; i++)
    {
        //cin >> array[i];
        //freq[array[i]]+=1; //값이 등장할 때마다 +1
        //cout<<freq[array[i]];
        //NGF[i]=-1; //초기화
        int temp;
        cin >> temp;
        array.push_back(temp);
        freq[temp] += 1;
        NGF.push_back(-1);
    }
    stack<int> s; //오등큰수를 찾지못한 index 저장 stack

    //find ngf
    for (int i = 1; i <= N; i++)
    {
        //stack 값있고, top index array값의 freq보다 내 array값의 freq이 더 크면 top의 NGF는 내 값이 된다.
        while (!s.empty() && freq[array[s.top()]] < freq[array[i]])
        {
            NGF[s.top()] = array[i];
            s.pop(); //NGF 찾았으니 pop
        }
        s.push(i);
    }

    for (int i = 1; i <= N; i++)
    {
        cout << NGF[i] << " ";
    }
    cout << "\n";

    return 0;
}