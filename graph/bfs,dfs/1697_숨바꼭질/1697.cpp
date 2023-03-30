#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visit[100002];
int n , k;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >>k;
    queue<pair<int , int>> q;
    q.push(make_pair(n,0));
    int depth;
    int x;
    memset(visit, false ,sizeof(visit));
    visit[n] = true;
    int ans;

    while(!q.empty()){
        x = q.front().first;
        depth= q.front().second;
        q.pop();

        if(x == k){
            ans = depth;
            break;
        }

        if(x-1 >=0){
            if(!visit[x-1]){
                q.push(make_pair(x-1, depth+1));
                visit[x-1] = true;
            }
        }

        if(x+1 <= 100000){
            if(!visit[x+1]){
                q.push(make_pair(x+1, depth+1));
                visit[x+1] = true;
            }
        }

        if(x*2 <= 100000){
            if(!visit[x*2]){
                q.push(make_pair(x*2, depth+1));
                visit[x*2] =true;
            }
        }
        
    }

    cout << ans;
    return 0;
}
