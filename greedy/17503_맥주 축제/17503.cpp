#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;


vector<pair<int  , ll>> v;
int N, K;
ll M;
ll ans = -1;
ll maxi = 0;

bool cmp(pair <int,ll> p1, pair <int,ll> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    
    return p1.second < p2.second;
}

void bin();
bool ok(ll num);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M >> K;

    ll t;
    ll tt;

    for(int i =0; i<K; i++){
        cin >> t >> tt;
        v.push_back({t,tt});
        maxi = max(maxi , tt);
    }

    sort(v.begin() , v.end() , cmp);

    bin();
    cout << ans;
    return 0;

}

void bin(){
    ll start =0;
    ll end = maxi;
    ll mid;

    while(start<=end){
        mid = (start+end)/2;

        if(ok(mid)){
            end = mid-1;

            if(ans == -1){
                ans = mid;
            }
            else{
                ans = min(mid , ans);
            }
        }
        else{
            start = mid+1;
        }
    }
}

bool ok(ll num){

    priority_queue<ll> pq;

    for(int i =0; i<K; i++){
        if(v[i].second <= num){
            pq.push(v[i].first);
        }
        else{
            break;
        }
    }

    ll temp = 0;

    for(int i =0; i<N; i++){
        if(pq.empty()){
            temp = -1;
            break;
        }
        temp += pq.top();
        pq.pop();
    }

    if(temp >= M){
        return true;
    }
    else{
        return false;
    }
}
