#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

char inp[1002][1002];
vector<pair<int , int>> v;
bool visit[1002][1002];

int main(){
    ios_base:: sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int m , n ;

    cin >> m >> n;
    
    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            cin >> inp[i][j];
            if(i == 0 && inp[i][j] == '0'){
                v.push_back(make_pair(i,j));
            }
        }
    }

    memset(visit ,false , sizeof(visit));

    bool poss = false;
    int f ,s;
    for(int i =0; i<v.size(); i++){
        f = v[i].first;
        s = v[i].second;

        if(poss){
            break;
        }

        if(visit[f][s]){
            continue;
        }
        queue<pair<int,int>> q;
        q.push(make_pair(f,s));
        visit[f][s] = true;
        int x, y;
        while(!q.empty()){
            x =q.front().first;
            y = q.front().second;
            q.pop();

            if(x == m-1){
                poss = true;
                break;
            }
            if(x-1 >=0){
                if(!visit[x-1][y] && inp[x-1][y] == '0'){
                    q.push(make_pair(x-1,y));
                    visit[x-1][y] = true;
                }
            }
            if(y-1 >=0){
                if(!visit[x][y-1] && inp[x][y-1] == '0'){
                    q.push(make_pair(x,y-1));
                    visit[x][y-1] = true;
                }
            }

            if(x+1 <=m-1){
                if(!visit[x+1][y] && inp[x+1][y] == '0'){
                    q.push(make_pair(x+1,y));
                    visit[x+1][y] = true;
                }
            }
            if(y+1 <=n-1){
                if(!visit[x][y+1] && inp[x][y+1] == '0'){
                    q.push(make_pair(x,y+1));
                    visit[x][y+1] = true;
                }
            }

        }
        
        
    }

    if(poss){
        cout <<"YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
