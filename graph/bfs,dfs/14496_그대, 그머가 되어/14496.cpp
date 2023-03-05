#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

bool visit[1002];
queue<pair<int , int>> q;
vector<int> v[1002];

int a , b , N , M;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> a >> b;
    cin >> N >> M;
    int x , y;

    for(int i =0; i<M; i++){
        cin >>x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    q.push(make_pair(a,0));
    visit[a] =true;
    int f, s;
    int poss = -1;

    while(!q.empty()){
        f = q.front().first;
        s = q.front().second;
        q.pop();

        if(f == b){
            poss  =s;
            break;
        }

        for(int i =0; i<v[f].size() ; i++){
            if(!visit[v[f][i]]){
                q.push(make_pair(v[f][i] , s+1));
                visit[v[f][i]] = true;
            }
        }
    }

    cout << poss;
    return 0;
}
