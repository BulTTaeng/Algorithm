#include <iostream>
#include <queue>

using namespace std;

int N , P;
priority_queue<int> pq[7];
int ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> P;
    
    int line , pratt;

    for(int i =0; i<N; i++){
        cin >> line >> pratt;
        if(pq[line].empty()){
            pq[line].push(pratt);
            ans++;
        }
        else{
            bool check = false;

            while(!pq[line].empty()){
                if(pq[line].top() == pratt){
                    check = true;
                    break;
                }
                else if(pq[line].top() < pratt){
                    pq[line].push(pratt);
                    check = true;
                    ans++;
                    break;
                }
                else{
                    pq[line].pop();
                    ans++;
                }
            }

            if(!check){
                pq[line].push(pratt);
                ans++;
            }
        }
    }

    cout << ans;
    return 0;

}
