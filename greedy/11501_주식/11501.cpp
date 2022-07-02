#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

long long ans = 0;
int T , N , temp;
int count[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> T;

    while(T--){
        cin >> N;

        ans = 0;
        vector<int> v;
        priority_queue<int> pq;
        memset(count , 0 , sizeof(count));

        for(int i =0; i<N; i++){
            cin >> temp;
            v.push_back(temp);
            pq.push(temp);
        }

        for(int i =0; i<N; i++){
            if(v[i] == pq.top()){
                pq.pop();

                while(!pq.empty()){
                    if( count[pq.top()] != 0){
                        count[pq.top()]--;
                        pq.pop();
                    }
                    else{
                        break;
                    }
                }
            }
            else if(v[i] < pq.top()){
                ans += (pq.top() - v[i]);
                count[v[i]]++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
