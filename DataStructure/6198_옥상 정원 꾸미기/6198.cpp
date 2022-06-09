#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int N;
int inp[80002];
long long ans=0;
stack<pair<int , int>> s;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0 ; i<N; i++){
        cin >> inp[i];
    }

    int temp = 0;

    for(int i = N-1 ; i>=0 ; i--){
        
        temp = 0;
        while(!s.empty() && inp[i] > s.top().first){
            ans+= s.top().second;
            temp+= s.top().second;
            temp++;
            s.pop();
        }
        s.push({inp[i] , temp});
        
    }

    while(!s.empty()){
        ans += s.top().second;
        s.pop();
    }
    cout << ans;
    return 0;
}
