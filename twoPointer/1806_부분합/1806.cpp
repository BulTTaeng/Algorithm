#include <iostream>
#include <vector>

using namespace std;

int N , S;
int inp[100001];

void solve();

#define MAX 987654321

int ans = MAX;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>> N >> S;

    for(int i =1; i<=N; i++){
        cin >> inp[i];
    }

    solve();
    
    if(ans == MAX){
        cout << 0;
    }
    else{
        cout << ans;
    }

    return 0;
}

void solve(){
    int s = 1;
    int e = 1;
    long long sum = 0;

    while(true){

        if(sum < S){
            sum += inp[e];
            e++;
        }
        else{
            ans = min(ans , e-s);
            sum -= inp[s];
            s++;
        } 

        if(e > N+1){
            break;
        }
    }
}
