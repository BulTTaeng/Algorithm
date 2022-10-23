#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int visit[10001];
int N ,T , D , C;
queue<pair<int , int>> q;

#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;

    int x, y ,w;

    while(T--){
        cin >> N  >> D >> C;

        vector<pair<int , int>> v[10001];

        for(int i =0; i<D; i++){
            cin >> x >> y >> w;
            v[y].push_back(make_pair(x, w));
        }


        for(int i=1; i<=N; i++){
            visit[i] = INF;
        }

        q.push(make_pair(C, 0));
        visit[C] = 0;

        while(!q.empty()){
            x = q.front().first;
            w = q.front().second;
            q.pop();

            for(int i =0; i<v[x].size(); i++){
                if(visit[v[x][i].first]  > v[x][i].second + w){
                    visit[v[x][i].first] = v[x][i].second + w;
                    q.push(make_pair(v[x][i].first , visit[v[x][i].first]));
                }
            }
        }

        int ans  =0 ;
        int cnum = 0;

        for(int i = 1; i<=N ; i++){
            if(visit[i] == INF) continue;
            cnum++;
            ans = max(ans , visit[i] );
        }

        cout << cnum << " " << ans << "\n";
    }

    return 0;

}
