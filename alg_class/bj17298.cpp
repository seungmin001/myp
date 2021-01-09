#include <bits/stdc++.h>
using namespace std;

//오큰수
//solve 참고함
//index이용.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N; //sequence size

    stack<int> s;             //nge를 찾지 못한 index stack. stack상단일수록 값 작음
    int array[1000001] = {0}; // input array
    int nge[1000001] = {0};   //nge array

    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        array[i] = temp;

        while (!s.empty() && temp > array[s.top()])
        { //새로 입력되는게 top보다 더 큼
            nge[s.top()] = temp;
            s.pop(); //nge 찾았으니 pop
        }
        //stack이 비어있거나 새입력이 top보다 작거나 같으면 nge가 아니므로 pass

        //set nge of current input => -1
        nge[i] = -1;

        //방금 입력된건 stack에 넣어서 다음것과 비교가능하게
        s.push(i);
    }

    nge[N] = -1; //마지막 수는 오른쪽 수가 없으므로 nge는 무조건 -1

    for (int i = 1; i <= N; i++)
    {
        cout << nge[i] << " ";
    }
    cout << "\n";

    return 0;
}