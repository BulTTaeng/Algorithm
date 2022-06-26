//deqeu solve
//1372 ms
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

typedef long long ll;

int N , L;
ll inp[5000002];

deque<pair<int , int>> dq;


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> L;

    for(int i =1 ; i<= N ; i++){
        cin >> inp[i];
    }
    
    int s;

    for(int i =1 ; i<=N; i++){
        s = i-L+1;
        s = max(1, s);

        while(!dq.empty() && dq.back().first >= inp[i]){
            dq.pop_back();
        }

        dq.push_back({inp[i] , i});
        
        while(!dq.empty() && dq.front().second < s){
            dq.pop_front();
        }

        cout << dq.front().first << " ";
    }

    return 0;
}
