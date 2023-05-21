#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

bool visit[52][52];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;

    cin >> t;

    for(int i =0; i<t; i++){
        int M , N , K;
        int x,y;
        int f , s;
        vector<pair<int , int>> inp;

        cin >> M >> N >> K;
        int ans = 0;
        memset(visit , false , sizeof(visit));

        for(int j =0; j<K; j++){
            cin >> x >> y;
            inp.push_back(make_pair(x,y));
            visit[x][y] = true;
        }

        for(int i =0; i<K; i++){
            f = inp[i].first;
            s = inp[i].second;

            if(!visit[f][s]){
                continue;
            }
            else{
                ans++;
                queue<pair<int , int>> q;
                q.push(make_pair(f,s));

                while(!q.empty()){
                    f= q.front().first;
                    s = q.front().second;
                    q.pop();

                    if(!visit[f][s]){
                        continue;
                    }
                    else{
                        visit[f][s] = false;
                        if(visit[f-1][s] == true && f>=1){
                            q.push(make_pair(f-1, s));
                        }
                        if(visit[f][s-1] == true && s>=1){
                            q.push(make_pair(f, s-1));
                        }
                        if(visit[f][s+1] == true && s<50){
                            q.push(make_pair(f, s+1));
                        }
                        if(visit[f+1][s] == true && f<50){
                            q.push(make_pair(f+1, s));
                        }
                    }
                }
            }

        }
        cout << ans <<"\n";

    }
    return 0;
}
