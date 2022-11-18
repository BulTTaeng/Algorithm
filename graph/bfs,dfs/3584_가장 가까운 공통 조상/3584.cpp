#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int T , N;
vector<int> v[10001];
int visit1[10001];
int visit2[10001];

void dfs1(int x , int d);
void dfs2(int x , int d);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;

    int p , s;
    int n1 , n2;

    while(T--){
        cin >> N;

        for(int i =1; i<=N; i++){
            v[i].clear();
        }

        for(int i =1; i<N; i++){
            cin >> p >> s;
            v[s].push_back(p);
        }
        cin >> n1 >> n2;
        memset(visit1 , 0 ,sizeof(visit1));
        memset(visit2 , 0 ,sizeof(visit2));

        dfs1(n1 , 1);
        dfs2(n2 , 1);

        int sumd = 987654321;
        int parent = -1;

        for(int i =1 ; i<=N; i++){
            if(visit1[i] != 0 && visit2[i] != 0){

                if(sumd > visit1[i] + visit2[i] ){
                    sumd = visit1[i] + visit2[i];
                    parent = i;
                }
                
            }
        }

        cout << parent<<"\n";
    }

    return 0;
}

void dfs1(int x , int d){

    visit1[x] = d;

    for(int i =0; i<v[x].size(); i++){
        if(visit1[v[x][i]] == 0){
            dfs1(v[x][i],d+1);
        }
    }
}

void dfs2(int x , int d){

    visit2[x] = d;

    for(int i =0; i<v[x].size(); i++){
        if(visit2[v[x][i]] == 0){
            dfs2(v[x][i],d+1);
        }
    }
}
