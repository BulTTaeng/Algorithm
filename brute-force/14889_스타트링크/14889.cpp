#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int N;
int inp[21][21];
int visit[21];

int ans = 987654321;

int cal();
void dfs( int num , int loc);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N; 

     for(int i =0; i<N; i++){
        for(int j =0; j<N ; j++){
            cin >> inp[i][j];
        }
    }
    memset(visit ,false ,sizeof(visit));

    dfs(0,0);

    cout << ans;
    return 0;
}

void dfs( int num , int loc){

    if(num == N/2){
        ans = min(ans , cal());
    }
    else{
        for(int i = loc; i<N; i++){
            if(!visit[i]){
                visit[i] = true;
                dfs(num+1 , i+1);
                visit[i]= false;
            }
        }
    }


}

int cal(){
    vector<int> team1;
    vector<int> team2;

    for(int i =0; i<N; i++){
        if(visit[i]){
            team1.push_back(i);        
        }
        else{
            team2.push_back(i);
        }
    }

    int s1 =0 ;
    int s2 = 0;

    for(int i =0; i<team1.size()-1; i++){
        for(int j =i+1; j<team1.size(); j++){
            s1 += inp[team1[i]][team1[j]];
            s1 += inp[team1[j]][team1[i]];

            s2 += inp[team2[i]][team2[j]];
            s2 += inp[team2[j]][team2[i]];
        }
    }

    return abs(s1-s2);
    
}

