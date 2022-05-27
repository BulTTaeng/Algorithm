#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<long long>v;
vector<long long> ans;

long long mini = 3000000009;

void solve();


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int temp;

    for(int i =0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin() , v.end());

    solve();

    sort(ans.begin() , ans.end());

    for(int i =0; i<3; i++){
        cout << ans[i] << " ";
    }
    return 0;
}

void solve(){
    int start, end;
    int mid;
    long long temp;

    for(int fixed = 0; fixed <N-2; fixed++){
        start = fixed+1;
        end = v.size()-1;
        while(start < end){
            temp = v[start] + v[end] + v[fixed];
            if(abs(temp) < abs(mini)){
                mini = temp;
                ans.clear();
                ans.push_back(v[fixed]);
                ans.push_back(v[start]);
                ans.push_back(v[end]);
            }

            if(temp >0){
                end--;
            }
            else{
                start++;
            }
        }    
    }
}
