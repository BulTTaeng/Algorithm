#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int visit[1001];
vector<int> v[1001];

int N , M;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    
    int x, y;

    for(int i =0; i<M ; i++){
        cin >> x >> y;
        v[x].push_back(y);    
    }

    memset(visit , 0 ,sizeof(visit));
    
    int f , d;

    for(int i =1; i<=N; i++){

        if(visit[i] == 0){
            queue<pair <int , int>> q;
            q.push(make_pair(i , 1));

            visit[i] = 1;

            while(!q.empty()){
                f = q.front().first;
                d = q.front().second;
                q.pop();

                for(int j =0; j<v[f].size(); j++){
                    if(visit[v[f][j]] == 0){
                        visit[v[f][j]] = d+1;
                        q.push(make_pair(v[f][j] , d+1));
                    }
                    else{
                        if( visit[v[f][j]] < d+1){
                            visit[v[f][j]] = d+1;
                            q.push(make_pair(v[f][j] , d+1));
                        }
                    }
                }
            }

        }

    }

    for(int i = 1; i<=N; i++){
        cout << visit[i] << " ";
    }

    return 0;
}
