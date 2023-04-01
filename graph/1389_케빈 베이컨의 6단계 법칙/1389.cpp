#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

vector<int>v[102];
int num[102];
bool visit[102];
int ans[102];

int n , m, mink = 99999999; 

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin. tie(0);

    cin >>  n >> m;
    int x , y;
    
    for(int j =0; j<m; j++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x); 
    }
    
    memset(ans , 0 , sizeof(ans));

    for(int i =1; i<=n ;i++){
        queue<pair<int , int >> q;
        q.push(make_pair(i,0));
        memset(num , 0, sizeof(num));
        memset(visit, false ,sizeof(visit));
        visit[i] = true;
        int f ,depth;

        while(!q.empty()){
            f = q.front().first;
            depth = q.front().second;
            q.pop();

            for(int j =0; j<v[f].size(); j++){
                if(!visit[v[f][j]]){
                    q.push(make_pair(v[f][j],depth+1));
                    num[f] = depth+1;
                    visit[v[f][j]] = true;
                }
            }
        }// end of q

        for(int k =1; k<=n; k++){
            ans[i] += num[k]; 
        }

        if(ans[i] <mink){
            mink = ans[i];
        }
    }//end of i loop

    for(int i =1; i<=n; i++){
        if(ans[i] == mink) {
            cout << i;
            break;
        }
    }
    return 0;
}
