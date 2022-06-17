#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N , K;
int edge[101][101];
int root[101];
vector<int> group[101];
int groupnum  = 0 ;
vector<int> ans;

int dis[101][101];

void Union(int x , int y);
int Find(int x);
void Floyd();
int findMaxdis(int x);

#define MAX 987654321

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    cin >> K;

    int x , y;

    for(int i =1; i <=N; i++){
        root[i] = i;
    }

    for(int i =1; i<=N; i++){
        for(int j =1 ; j<=N; j++){
            if(i == j){
                dis[i][j] = 0;
            }
            else{
                dis[i][j] = MAX;
            }
        }
    }

    for(int i =0; i<K; i++){
        cin >> x >> y;
        dis[x][y] = 1;
        dis[y][x] = 1;
        Union(x, y);
    }


    Floyd();

    int g;
    int sum = MAX;
    int tempmin;
    int temp ;

    for(int i=1 ; i<=N; i++){
        g = Find(i);
        group[g].push_back(i);
    }

    for(int i =1; i<=N; i++){
        if(group[i].empty()){
            continue;
        }
        else{
            sum = MAX;
            
            for(int j=0; j<group[i].size(); j++){
                tempmin = findMaxdis(group[i][j]);
                if(sum > tempmin){
                    sum = tempmin;
                    temp = group[i][j];
                }
            }

            ans.push_back(temp);
        }
    }

    sort(ans.begin() , ans.end());

    cout << ans.size() << "\n";

    for(int i =0; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }

    return 0;

}

void Union(int x , int y){
    x = Find(x);
    y = Find(y);

    root[y] = x;
}

int Find(int x){
    if(root[x] == x) return x;
    else{
        return root[x] = Find(root[x]);
    }
}

void Floyd(){
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j =1 ; j<=N; j++){
                if(dis[i][k] != MAX && dis[k][j] != MAX){
                    if(dis[i][k] + dis[k][j] < dis[i][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
    }
}

int findMaxdis(int x){
    
    int re  =  0;

    for(int i =1; i<=N; i++){
        if(i == x){
            continue;
        }
        else if(dis[x][i] == MAX){
            continue;
        }
        else{
            re = max(re , dis[x][i]);
        }
    }

    return re;

}
