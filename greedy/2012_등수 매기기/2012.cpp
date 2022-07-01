#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N , temp;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for(int i =0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin() , v.end());

    int iter = 1;
    long long ans = 0;

    for(int i =0; i<N; i++){
        ans += abs(iter-v[i]);
        iter++;
    }

    cout <<ans;
    return 0;
    
}
