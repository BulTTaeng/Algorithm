#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int maxi = 0;
int ans = 0;
vector<pair<int , int>> v;
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    int dead , cup;

    for(int i =0; i<N; i++){
        cin >> dead >> cup;
        maxi = max(dead , maxi);
        v.push_back({dead , cup});
    }

    sort(v.begin(), v.end() , greater<>());

    int iter = 0;

    maxi++;

    while(--maxi){
        cout << maxi;
        while(iter < N && v[iter].first == maxi){
            pq.push(v[iter].second);
            iter++;
        }

        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
    return 0;

}
