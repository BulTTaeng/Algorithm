#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[51];

bool visit[51];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N;
    char t;
    cin >> N;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> t;
            if(t == 'Y'){
                v[i].push_back(j);
            }
        }
    }

    int maxi = 0;

    for(int i =0; i<N; i++){
        int ans = 0;

        queue<int> q;
        memset(visit , false ,sizeof(visit));
        visit[i] = true;
        ans += v[i].size();

        for(int j = 0; j<v[i].size(); j++){
            q.push(v[i][j]);
            visit[v[i][j]] = true;
        }

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(int j = 0; j<v[temp].size(); j++){
                if(!visit[v[temp][j]] ){
                    ans++;
                    visit[v[temp][j]] = true;
                }    
            }
        }

        if(maxi < ans){
            maxi = ans;
        }
    }

    cout << maxi;
    return 0;
}
