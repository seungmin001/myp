#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore(); //이거를 안해줘서 첫 sentence가 "" 크기가 0이되어 밑에서 pos 접근 오류 발생했었음.

    while(T--){
        string sentence;
        getline(cin, sentence);
       
        stack<char> s;
        int pos=0;
        // sentence의 끝까지 갈 때 까지
        // 맨 뒤에 단어가 안나옴 > 밑 비교문에서 처음에 length-1로 해서 마지막 단어 글자에서 나가서 안됐었음.
        while(pos!=sentence.length()){
            //공백 발견 할 시 stack모두 pop하며 출력
            if(sentence[pos]==' '){
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }
                cout << " "; //whitespace
            }
            // 아니면 계속 push
            else{
                s.push(sentence[pos]);            
            }
            pos+=1; //한칸 뒤로
        }
        //마지막 단어 출력
        while (!s.empty())
        {
            cout << s.top();
            s.pop();
        }
        cout << "\n"; //다음 문장
    }

    return 0;
}