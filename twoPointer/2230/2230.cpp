#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N , M;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    int t;

    for(int i =0; i<N ; i++) {
        cin >> t;
        v.push_back(t);
    }

    long long diff = 0;
    long long ans = -1;
    int start = 0 ;
    int end = 0;

    sort(v.begin() , v.end());

    while(start<= end && end<v.size()){
        diff = v[end] - v[start];

        if(diff < M){
            end++;
        }
        else if(diff == M){
            ans = M;
            break;
        }
        else if(diff > M){
            if(ans == -1){
                ans = diff;
            }
            else{
                ans = min(diff , ans);
            }
            start++;
        }
    }

    cout << ans;
    return 0;
}
