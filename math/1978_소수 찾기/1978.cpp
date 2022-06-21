#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N ;
bool is_prime[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    
    memset(is_prime , true , sizeof(is_prime));
    is_prime[1] = false;

    for(int i =2 ;i<=sqrt(1001) ; i++){

        if(!is_prime[i]){
            continue;
        }

        for(int j=i*2; j<1001; j+=i){
            is_prime[j] = false;
        }
    }

    int temp;
    int ans =0;

    for(int i =0; i<N; i ++){
        cin >> temp;
        if(is_prime[temp]){
            ans++;
        } 
    }
    cout << ans;
    return 0;
}
