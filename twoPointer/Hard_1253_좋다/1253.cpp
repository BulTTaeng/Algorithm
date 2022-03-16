#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N , ans = 0;;
vector<int> v;

bool binary(long long target);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int t;

    for(int i =0 ; i<N ; i++){
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin() , v.end());

    int sum;
    int re;

    for(int i =0; i<N; i++){
        
        if(binary(i)){
            ans++;
        }
        
    }

    cout << ans;
    return 0;
}

bool binary(long long target){
    int start = 0;
    int end = v.size()-1;
    int sum ;

    while(start<end){
        sum = v[start] + v[end] ;

        if(sum == v[target]){
            if(start != target && target != end ){
                return true;
            }
            else if(start == target){
                start++;
            }
            else if(end == target){
                end--;  
            }
        }
        else if(sum < v[target]){
            start++;
        }
        else{
            end--;
        }
    }

    return false;
}
