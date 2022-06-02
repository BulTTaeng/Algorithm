#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long long N , K,temp;
vector<long long > v;
long long maxi  = 0;
long long ans = 0;

void solve();
bool ok(long long x);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> K;

    for(long long i =0; i<N; i++){
        cin >> temp;
        maxi = max(maxi , temp);
        v.push_back(temp);
    }

    solve();

    cout << ans;
    return 0;

}

void solve(){
    long long start = 1;
    long long end = maxi+1;
    long long mid;
    while(start<=end){
        mid = (start+end)/2;

        if(ok(mid)){
            start = mid+1;
        }       
        else{
            end = mid-1;
        }
    }
}

bool ok(long long x){
    long long re = 0;
    
    for(long long i =0; i<N; i++){
        re += v[i]/x;
    }

    if(re >= K){
        ans = max(ans , x);
        return true;
    }

    return false;
}
