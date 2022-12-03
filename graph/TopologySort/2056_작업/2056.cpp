#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int taketime[10001];
int N;

int maxi =0;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int time , parent , p;
    
    memset(taketime , 0 , sizeof(taketime));

    for(int i =0; i<=N; i++) {
        taketime[i] = 0;
    }
    int t=0;

    for(int i = 1; i<=N; i++){
        cin >> time >> parent;
        taketime[i] = time;
        t= time;

        for(int j=0; j<parent; j++){
            cin >> p;
            t = max(t, time + taketime[p]);
        }

        taketime[i] = t;
    }

    for(int i =1 ; i<=N; i++){
        maxi = max(taketime[i] , maxi);
    }

    cout << maxi;
    return 0;
}
