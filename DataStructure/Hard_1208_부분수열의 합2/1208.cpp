#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N , S;
int inp[42];
map<int , int> r;
long long ans = 0;

void dfsr(int idx , int sum);
void dfsl(int idx , int sum);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> S;

    for(int i =0; i<N; i++){
        cin >> inp[i];
    }

    dfsr(N/2, 0);
    dfsl(0 , 0);

    if(S == 0){
        cout << ans-1;
    }
    else{
        cout << ans;
    }
    return 0; 
}

void dfsr(int idx , int sum){

    if(idx == N){
        r[sum]++;
        return;
    }

    dfsr(idx+1 , sum );
    dfsr(idx+1 , sum + inp[idx]);

}

void dfsl(int idx , int sum){

    if(idx == N/2){
        ans += r[S-sum];
        return;
    }

    dfsl(idx+1 , sum );
    dfsl(idx+1 , sum + inp[idx]);

}

