#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int population[11];
vector<int> v[11];
bool visit[11];

int city[11];

vector<int>loc1;
vector<int> loc2;


#define MAX 987654321

int c1 , c2 , ans = MAX;

void combination(int cnt);
bool connected();
void dfs(int loc , int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =1; i<=N; i++){
        cin >> population[i];
    }

    int temp;
    int t;

    for(int i =1 ; i<=N; i++){
        cin>> temp;

        for(int j =0; j<temp; j++){
            cin >> t;
            v[i].push_back(t); 
                   
        }
    }

    combination(1);
    if(ans == MAX){
        cout << -1;
    }
    else{
        cout << ans;
    }
    return 0;

}

void combination(int cnt){
    
    if(cnt == N+1){
        if(loc1.empty() || loc2.empty()) return;

        if(connected()){
            c1 = 0;
            c2 = 0;

            for(int i =1 ; i<=N; i++){
                if(city[i] == 1){
                    c1 += population[i];
                }
                else{
                    c2 += population[i];
                }
            }

            ans = min(ans , abs(c1 - c2));
        }

        return;
    }

    city[cnt] = 1;
    loc1.push_back(cnt);
    combination(cnt+1);
    loc1.pop_back();

    loc2.push_back(cnt);
    city[cnt] = 2;
    combination(cnt+1);
    loc2.pop_back();

}

bool connected(){
    memset(visit , false ,sizeof(visit));

    dfs(loc1[0] , 1);
    dfs(loc2[0] , 2);

    for(int i=1 ; i<=N ; i++){
        if(!visit[i]) return false;
    }

    return true;
}

void dfs(int loc , int num){
    visit[loc] = true;
    
    
    for(int i=0; i<v[loc].size(); i++){
        if(!visit[v[loc][i]] && city[v[loc][i]] == num){
            dfs(v[loc][i] , num);
        }
    }
    
}

