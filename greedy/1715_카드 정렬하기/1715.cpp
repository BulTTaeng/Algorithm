#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int , vector<int> , greater<>>pq;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int temp;

    for(int i =0; i<N; i++){
        cin >> temp;
        pq.push(temp);
    }

    int f, s;
    int ans = 0;

    while(pq.size() != 1){
        f = pq.top();
        pq.pop();
        s=pq.top();
        pq.pop();
        ans += (f+s);
        pq.push(f+s);
    }

    cout << ans;
    return 0;
}
