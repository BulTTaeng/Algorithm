#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
long long ans = 0;
stack<pair<long long , int>> s;
vector<long long> inp;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    long long temp;
    pair<long long , int > p;

    for(int i =0 ; i<N ; i++){
        cin >> temp;

        while(!s.empty() && s.top().first < temp){ // 차피 나보다 큰게 나온 순간 , 앞으로 나올 숫자는 나와 쌍을 이루지 못한다.
            //따라서 현재 값과 쌍을 이루면서 pop해주자.
            ans += s.top().second;
            s.pop();
        }

        //이제 stack에는 내림차순이 보장 된다.

        if(s.empty()){
            s.push({temp , 1});
        }
        else{
            if(s.top().first == temp){
                p = s.top();
                s.pop();

                //지금 스택의 top이 나의 현재 값과 같으면, 그 값이 pair로 가지는 숫자는 모두 다 현재값과 쌍을 이룰 수 있다.
                ans+=p.second;
                
                //지금 스택은 내림차순
                //만약 스택에 값이 있다면 현재 값보다 클 것임
                //그 값과 (현재 s.top()) 쌍을 이루 므로 +1
                if(!s.empty()){
                    ans++;
                }
                //현재 값과 s.top 도 쌍을 이룰 수 있다.
                p.second++;
                s.push(p);
            }
            else{
                //작으면 바로 앞에 값과 쌍을 이룰 수 있다.
                s.push({temp , 1});
                ans++;
            }
        }
    }

    cout <<ans;
    return 0;


}
