#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N , K;
queue<int> q[21];
long long ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> K;
    
    string str;
    int l;
    for(int i =0; i <N; i++){
        cin >> str;
        l = str.length();
        
        while(!q[l].empty() && q[l].front() < i -K){
            q[l].pop();
        }
        
        ans += q[l].size();
        q[l].push(i);
    }
    
    cout << ans;
    return 0;
}
