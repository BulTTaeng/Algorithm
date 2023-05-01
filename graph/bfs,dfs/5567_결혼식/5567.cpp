#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visit[502];
vector<int> v[502];

int ans = 0;

void find_friends(int num , int depth);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n , m;
    cin >> n >> m;
    int x , y;
    for(int i=1; i<=m; i++){
        cin >> x >> y;
        if(x == 1){
            v[x].push_back(y);
        }
        else if( y == 1){
            v[y].push_back(x);
        }
        else{
            v[x].push_back(y);
            v[y].push_back(x);
        } 
    }

    memset(visit, false , sizeof(visit));
    find_friends(1,0);
    cout << ans;
    return 0;
}


void find_friends(int num , int depth){
    

    if(depth >2){
        return;
    }

    if(num != 1 && visit[num] == false){
        ans++;
    }

    visit[num] = true;

    for(int i =0; i<v[num].size() ; i++){
        find_friends(v[num][i] , depth+1);
    }
    return;   
}
