#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> v[102];
bool visit[102];
int n , t1 ,t2 , m;
int ans = -1;
queue<pair<int , int>> q;

void BFS(int start);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    cin>> t1 >> t2;
    cin >>m;
    int x , y;

    for(int i =1; i<=m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(visit ,false ,sizeof(visit));

    BFS(t1);
    cout << ans;
    return 0;
}

void BFS(int start){
    q.push(make_pair(start , 0));
    int f , s;

    while(!q.empty()){
      
        f = q.front().first;
        s = q.front().second;

        if(f == t2){
            ans = s;
            break;
        }

        q.pop();

        for(int i =0; i<v[f].size(); i++){
            if(!visit[v[f][i]] ){
                q.push(make_pair(v[f][i] , s+1));
                visit[v[f][i]] = true;
            }
        }
    }
    return;
}
