#include<iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int , int>> jewel;
vector<int> bp;
priority_queue<int> pq;

int N , K;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> K;
    int m , v , temp;

    for(int i =0; i<N; i++){
        cin>> m >> v;
        jewel.push_back({m,v});
    }

    for(int i =0 ; i<K ; i++){
        cin >> temp;
        bp.push_back(temp);
    }

    sort(jewel.begin() , jewel.end());
    sort(bp.begin() , bp.end());
    
    long long ans = 0;
    int idx = 0;
    for(int i =0; i<K; i++){
        while(idx <N && bp[i] >= jewel[idx].first){
            pq.push(jewel[idx].second);
            idx++;
        }

        if(!pq.empty()){
            ans+= pq.top();
            pq.pop();
        }
    }

    cout << ans;
    return 0;

}
