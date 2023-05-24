#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int inp[152];
bool visit[152];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N ,K;

    cin >> N >> K;

    for(int i = 0; i<N; i++){
        cin >> inp[i];
    }

    memset(visit, false ,sizeof(visit));
    
    q.push(0);
    int temp;

    int ans = -1;
    int count = -1;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        count ++;
        
        if(temp == K){
            ans = count;
            break;
        }

        if(visit[temp]){
            break;
        }

        visit[temp] = true;

        q.push(inp[temp]);
    }

    cout << ans;
    return 0;

}
