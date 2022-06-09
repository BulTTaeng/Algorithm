#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int N;
int inp[500002];
int ans[500002];
stack<pair<int , int>> s;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =1 ; i<=N; i++){
        cin >> inp[i];
    }

    memset(ans , 0 ,sizeof(ans));

    for(int i = N ; i>=1 ; i--){
        
        while(!s.empty() && inp[i] >= s.top().first){
            ans[s.top().second] = i;
            s.pop();
        }

        s.push({inp[i] , i});
        
    }

    for(int i =1; i<=N; i++){
        cout << ans[i] <<" ";
    }
    return 0;
}
