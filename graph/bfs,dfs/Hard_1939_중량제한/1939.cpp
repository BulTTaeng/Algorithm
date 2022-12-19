#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct st{
    int x;
    int y;
    int w;
}typedef st;

struct cmp{
    bool operator()(const st &s1 , const st &s2){
        return s1.w > s2.w;
    }
};

vector<pair<int , int >> v[10001];
vector<int > edge;

bool visit[10001];

int N , M , S , E;
bool poss;

int binary();
bool bfs(int limit);
bool dfs(int curr, int limit);

#define MAXX 1000000001

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    int x ,  y , w;

    for(int i =0; i<M; i++){
        cin >> x >> y >> w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
        edge.push_back(w);
    }
    cin >> S >> E;

    sort(edge.begin() , edge.end() , less<>());

    int a=binary();

    cout << a;
    return 0;
}

int binary(){
    int start = 0;
    int end = edge.size()-1;
    int mid;

    while(start <= end){
        mid = (start+end)/2;
        memset(visit , false ,sizeof(visit));
        poss = false;

        if(dfs(S, edge[mid])){
            //if we change upper line bfs(edge[mid]) , it will also work.
            start = mid+1;
        }
        else{
            end = mid - 1;
        }
    }

    return edge[end];
}

bool dfs(int curr, int limit){
    
    if(curr == E){
        poss = true;
        return true;
    }
    else{
        visit[curr ]  = true;

        for(int i =0; i<v[curr].size(); i++){
            if(!visit[v[curr][i].first] && limit <= v[curr][i].second){
                dfs(v[curr][i].first , limit);
            }
        }
    }

    return poss;
}



bool bfs(int limit){
    queue<int>q;

    memset(visit , false ,sizeof(visit));

    q.push(S);
    visit[S] = true;

    int x;

    bool poss = false;

    while(!q.empty()){
        x = q.front();
        q.pop();

        if(x == E){
            poss = true;
            break;
        }

        for(int i =0; i<v[x].size(); i++){
            if(!visit[v[x][i].first] && limit <= v[x][i].second){
                q.push(v[x][i].first);
                visit[v[x][i].first] = true;
            }
        }
    }

    return poss;
}


