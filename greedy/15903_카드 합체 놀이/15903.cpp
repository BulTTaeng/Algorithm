#include <iostream>
#include <queue>

using namespace std;

int N , M;
priority_queue<long long , vector<long long> , greater<>>pq;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    long long temp;

    for(int i =0; i<N; i++){
        cin >> temp;
        pq.push(temp);
    }

    long long  f, s;

    while(M--){
        f = pq.top();
        pq.pop();
        s = pq.top();
        pq.pop();

        pq.push(f+s);
        pq.push(f+s);
    }

    long long ans = 0;

    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }

    cout << ans;
    return 0;
}
