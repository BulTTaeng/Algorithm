#include <iostream>

using namespace std;

int inp[300001];
int ans = 0;
int N;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for(int i =1; i<=N; i++){
        cin >> inp[i];
    }
    
    int n = N;

    for(int i = N; i>=1 ; i--){
        if(inp[i] == n){
            n--;
        }
    }

    cout << n;
    return 0;


}
