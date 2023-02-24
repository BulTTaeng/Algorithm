#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

bool visit[51];
vector<int> v[51];
int score[51];

int N;

int BFS(int start);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int x , y;
    while(true){
        cin >> x >> y;

        if(x == -1 && y ==-1){
            break;
        }

        v[x].push_back(y);
        v[y].push_back(x);
    }

    memset(score , 0 , sizeof(score));
    int mini = 999999999;

    for(int i = 1 ; i<=N ; i++ ){

        memset(visit, false ,sizeof(visit));
        score[i] = BFS(i);

        mini = min(mini , score[i]);
    }

    vector<int > a;

    for(int i =1; i<=N; i++){
        if(score[i] == mini){
            a.push_back(i);
        }
    }

    cout << mini << " " <<  a.size() << "\n";

    for(int i =0; i<a.size(); i++){
        cout << a[i] << " ";
    }

}

int BFS(int start){
    visit[start] = true;

    queue<pair<int , int>> q;
    q.push(make_pair(start, 0));
    
    int fr , sc , ans =0;

    while(!q.empty()){
        fr = q.front().first;
        sc = q.front().second;
        q.pop();

        ans = max(ans , sc);

        for(int i =0; i<v[fr].size(); i++){
            if(!visit[ v[fr][i] ]){
                q.push(make_pair(v[fr][i] , sc+1 ));
                visit[ v[fr][i] ] = true;
            }
        }

    }

    return ans;
}
