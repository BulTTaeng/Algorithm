#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int N , K;
vector<string> v;

bool visit[27];

int ans = 0;

void dfs(int idx, int num);
int can_make();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> K;

    string str;
    memset(visit, false ,sizeof(visit));

    for(int i =0; i<N; i++){
        cin >> str;
        v.push_back(str);
    }

    if(K < 5){
        cout << 0;
        return 0;
    }

    visit[0] = true;
    visit[2] = true;
    visit[(int)('t' - 'a')] = true;
    visit[(int)('i' - 'a')] = true;
    visit[(int)('n' - 'a')] = true;

    dfs(0 , 5);

    cout << ans;
    return 0;
}

void dfs(int idx, int num){

    if(num == K){
        ans = max(ans , can_make());
        return;
    }

    for(int i =idx+1; i<26; i++){
        if(!visit[i]){
            visit[i]= true;
            dfs(i , num+1);
            visit[i]= false;
        }
    }
    
}

int can_make(){

    bool poss = true;
    int re  = 0;
    for(int i =0; i<N; i++){
        poss = true;
        for(int j =4; j<v[i].size()-4; j++){
            if(!visit[(int)(v[i][j] - 'a')]){
                poss = false;
                break;
            }
        }

        if(poss){
            re++;
        }
    }

    return re;
}
