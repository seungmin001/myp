#include <bits/stdc++.h>
using namespace std;

//deque 구현
//main함수의 pop 구현에서 cin으로 입력을 더 받는 걸 발견 못해서 푸는데 오래걸림

struct Deque
{
    int deque[10001];
    int begin, end;

    Deque()
    {
        begin = 0;
        end = 0;
    }

    void push_front(int X)
    {
        if (begin == 0)
        {
            //맨끝부터 뒤로 한칸씩 밈
            for (int i = end - 1; i >= begin; i--)
            {
                deque[i + 1] = deque[i];
            }
            end++;
            //추가
            deque[0] = X;
        }
        else
        {
            begin -= 1;
            deque[begin] = X;
        }
    }
    void push_back(int X)
    {
        deque[end] = X;
        end += 1;
    }
    int pop_front()
    {
        if (!this->empty())
        {
            begin++;
            return deque[begin - 1];
        }
        else
            return -1;
    }
    int pop_back()
    {
        if (!this->empty())
        {
            end -= 1;
            return deque[end];
        }
        else
            return -1;
    }
    int size()
    {
        return end - begin;
    }
    bool empty()
    {
        if (begin == end)
            return true;
        else
            return false;
    }
    int front()
    {
        if (!this->empty())
        {
            return deque[begin];
        }
        else
            return -1;
    }
    int back()
    {
        if (!this->empty())
        {
            return deque[end - 1];
        }
        else
            return -1;
    }
};

int main()
{

    Deque d;

    int N;
    cin >> N;

    while (N--)
    {
        string ins;
        cin >> ins;

        if (ins == "push_front")
        {
            int X;
            cin >> X;
            d.push_front(X);
        }
        else if (ins == "push_back")
        {
            int X;
            cin >> X;
            d.push_back(X);
        }
        else if (ins == "pop_front")
        {
            cout << d.pop_front() << "\n";
        }
        else if (ins == "pop_back")
        {
            cout << d.pop_back() << "\n";
        }
        else if (ins == "size")
        {
            cout << d.size() << "\n";
        }
        else if (ins == "empty")
        {
            cout << d.empty() << "\n";
        }
        else if (ins == "front")
        {
            cout << d.front() << "\n";
        }
        else if (ins == "back")
        {
            cout << d.back() << "\n";
        }
    }

    return 0;
}