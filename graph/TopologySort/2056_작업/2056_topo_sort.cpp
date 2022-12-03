#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

vector<int> v[10001];
int taketime[10001];
int maxtime[10001];
int indgree[10001];

int N;

void findmin();

int main(){
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int time , parent , p;
    
    memset(taketime , 0 , sizeof(taketime));
    memset(indgree , 0 , sizeof(indgree));
    memset(maxtime , 0 ,sizeof(maxtime));
    

    for(int i = 1; i<=N; i++){
        cin >> time >> parent;
        taketime[i] = time;

        for(int j=0; j<parent; j++){
            cin >> p;
            v[p].push_back(i);
            indgree[i]++;
        }

    }

    findmin();

    return 0;
}

void findmin(){
    queue<int> q;

    for(int i = 1; i<=N; i++){
        if(indgree[i] == 0){
            q.push(i);
        }
        maxtime[i] = taketime[i];
    }

    int t = 0;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        t = taketime[f];

        for(int i =0; i<v[f].size() ; i++){
            indgree[v[f][i]]--;

            maxtime[v[f][i]] = max(maxtime[v[f][i]], maxtime[f] + taketime[v[f][i]] );

            if(indgree[v[f][i]] == 0){
                q.push(v[f][i]);
            }
        }

    }
    int ans = 0;

    for(int i =1; i<=N; i++){
        //cout << maxtime[i] << "  ";
        ans = max(ans , maxtime[i]);    
    }

    cout << ans;
}
