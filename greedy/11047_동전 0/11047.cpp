#include <iostream>
#include <vector>

using namespace std;

int N , K;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> K;
    int temp;

    for(int i =0; i<N; i++){
        cin >> temp;
        v.push_back(temp); 
    }

    int ans = 0;
    int i =N-1;

    while(K){
        if(i == 0){
            ans += K;
            break;
        }
        if(v[i] <= K){
            ans += K/v[i];
            K = K%v[i];
        }
        else{
            i--;
        }
    }

    cout << ans;
    return 0;
}
