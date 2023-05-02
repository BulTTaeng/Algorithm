#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int inp[52][52];
bool visit[52][52];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int w , h;

    while(true){
        cin >> w >> h;

        if(w == 0 && h == 0){
            break;
        }

        memset(inp, 0 , sizeof(inp));
        memset(visit, false , sizeof(visit));
        vector<pair<int , int >> v;
        queue<pair<int , int>> q;

        for(int i =1; i<=h; i++){
            for(int j =1; j<=w; j++){
                cin >> inp[i][j];
                if(inp[i][j] == 1){
                    v.push_back(make_pair(i,j));
                }
            }
        }

        int f ,s , ans = 0;

        for(int i =0; i<v.size() ; i++){
            int land_f = v[i].first;
            int land_s = v[i].second;

            if(visit[land_f][land_s] == true){
                continue;
            }

            ans++;
            q.push(make_pair(land_f,land_s));

            while(!q.empty()){
                f = q.front().first;
                s = q.front().second;
                q.pop();
                
                    visit[f][s] = true;
                    if(visit[f-1][s] == false && inp[f-1][s] == 1){
                        q.push(make_pair(f-1, s));
                        visit[f-1][s] = true;
                    }
                    if(visit[f][s-1] == false && inp[f][s-1] == 1){
                        q.push(make_pair(f, s-1));
                        visit[f][s-1] = true;
                    }
                    if(visit[f+1][s] == false && inp[f+1][s] == 1){
                        q.push(make_pair(f+1, s));
                        visit[f+1][s] = true;
                    }
                    if(visit[f][s+1] == false && inp[f][s+1] == 1){
                        q.push(make_pair(f, s+1));
                        visit[f][s+1] = true;
                    }

                    if(visit[f-1][s-1] == false && inp[f-1][s-1] == 1){
                        q.push(make_pair(f-1, s-1));
                        visit[f-1][s-1] = true;
                    }
                    if(visit[f+1][s+1] == false && inp[f+1][s+1] == 1){
                        q.push(make_pair(f+1, s+1));
                        visit[f+1][s+1] = true;
                    }
                    if(visit[f-1][s+1] == false && inp[f-1][s+1] == 1){
                        q.push(make_pair(f-1, s+1));
                        visit[f-1][s+1] = true;
                    }
                    if(visit[f+1][s-1] == false && inp[f+1][s-1] == 1){
                        q.push(make_pair(f+1, s-1));
                        visit[f+1][s-1] = true;
                    }
                }
            

        }
        cout << ans << "\n";

    }

}
