#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N , L;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> L;
    int temp;

    for(int i =0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    int ans = 0;
    int maxloc = 0;
    sort(v.begin() , v.end());

    int i =0;

    while(i<N){
        maxloc = v[i]+L-1;
        while(v[i] <= maxloc){
            i++;
        }
        ans++;
    }

    cout << ans;
    return 0;
}
