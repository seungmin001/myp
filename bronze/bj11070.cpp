#include <bits/stdc++.h>
using namespace std;

struct team
{
    int gain, lose;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //test case
    int T;
    cin >> T;
    while (T--)
    {
        vector<team> myteam;
        //n > 팀 개수 m > 전체경기수
        int n, m;
        cin >> n >> m;
        //팀 당 총 득점 실점 팀 개수만큼 넣어놓기
        for (int i = 0; i < n; i++)
        {
            team t = {0, 0};
            myteam.push_back(t);
        }
        while (m--)
        {
            //team a,b a:p b:q
            int a, b, p, q;
            cin >> a >> b >> p >> q;

            myteam[a - 1].gain += p;
            myteam[a - 1].lose += q;
            myteam[b - 1].gain += q;
            myteam[b - 1].lose += p;
        }

        double low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            double temp = 0; //비교군
            int s2 = myteam[i].gain;
            int a2 = myteam[i].lose;

            if (s2 == 0 && a2 == 0)
                temp = 0;
            else
            {
                double w = pow(s2, 2) / (pow(s2, 2) + pow(a2, 2));
                temp = w * 1000;
            }
            low = min(low, temp);
            high = max(high, temp);
        }

        cout << (int)high << "\n"
             << (int)low << "\n";
    }
    return 0;
}
