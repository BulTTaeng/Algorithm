#include <iostream>
#include <queue>

using namespace std;

priority_queue<int , vector<int> , greater<>> pq;

int N , temp;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for(int i =0; i<N; i++){
        cin >> temp;
        pq.push(temp);
    }

    int ans = 0;

    while(!pq.empty()){
        temp = pq.top();
        pq.pop();

        ans = max(temp * (int)(pq.size()+1) , ans);
    }

    cout << ans;
    return 0;
}
