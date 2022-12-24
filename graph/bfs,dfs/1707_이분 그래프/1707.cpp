#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int visit[20001];
vector<int> v[20001];

int K , V ,E;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> K;

    int x, y;
    int t , d;


    for(int k = 0 ; k < K; k++){
        cin >> V >> E;

        bool poss = true;

        for(int i =0; i<20001; i++){
            v[i].clear();
            visit[i] = -1;
        }

        queue<pair<int , int > > q;

        for(int i =0; i<E; i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);    
        }

        for(int i = 1 ; i<=V; i++){
            if(!poss ){
                break;
            }

            if(visit[i] == -1){
                q.push(make_pair(i , 0));
                visit[i] = 0;

                while(!q.empty()){
                    t = q.front().first;
                    d= q.front().second;
                    q.pop();

                    for(int j =0; j<v[t].size(); j++){
                        if(visit[v[t][j]] == -1){
                            visit[v[t][j]] = (d+1) % 2;
                            q.push( make_pair ( v[t][j] , d+1) );
                        }
                        else if(visit[v[t][j]] == d%2){
                            poss = false;
                        }
                    }

                    if(visit[t] == -1){
                        visit[t] = d%2;
                    }
                }
                
            }

        }

        if(poss){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" <<"\n";
        }
    }

    return 0;
}
