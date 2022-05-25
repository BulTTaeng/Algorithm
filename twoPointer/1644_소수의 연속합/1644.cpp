#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> prime;
bool is_prime[4000001];

int N;

void make_prime();


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    make_prime();
    
    int s = 0;
    int e = 0;
    int temp =0;
    int ans = 0;
    prime.push_back(40000001);

    if(N == 1){
        cout << 0;
        return 0;
    }

    while(s<=e && e<prime.size()){

        if(temp == N){
            ans++;
            temp-=prime[s];
            s++;
        }
        else if(temp < N){
            temp += prime[e];
            e++;
        }
        else{
            temp -=prime[s];
            s++;
        }
    }


    cout << ans;
    return 0;
}

void make_prime(){
    memset(is_prime , true ,sizeof(is_prime));

    int iter = 2;
    int temp;
    for(int i =2; i<=sqrt(N)+1;  i++){
        iter = 2;
        temp = 0;
        while(temp <= N){
            is_prime[temp] = false;
            temp = i*iter;
            iter++;
        } 
    }

    for(int i =2; i<=N; i++){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }
}
