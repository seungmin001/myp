#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    //10으로 나눈 몫:왼 10으로 나눈 나머지:오
    //원래 입력값과 같아질때까지 반복
    int num = N;
    int count = 0;
    while (true)
    {
        count++;
        //10보다 작으면 그 값이 오른쪽 자리 수가 되는 것 고려
        int q = num < 10 ? 0 : num / 10;
        int r = num < 10 ? num : num % 10; //왼
        int sum = q + r;
        int sum_r = sum % 10; //오

        num = r * 10 + sum_r;

        if (num == N)
            break; //종료조건
    }
    cout << count << "\n";
    return 0;
}