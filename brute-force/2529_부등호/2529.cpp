#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k;
vector<char> v;
vector<string> anum;

bool visit[10];

void dfs(int num , string ans , int n);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> k;
    char t;
    for(int i =0; i<k; i++){
        cin >> t;
        v.push_back(t);
    }

    dfs(-1, "" , -1);

    sort(anum.begin() , anum.end());

    cout << anum.back() << "\n";
    cout << anum.front();

    return 0;
}

void dfs(int num , string ans , int n){
    if(ans.length() == k+1){
        anum.push_back(ans);
        return;
    }

    if(num == -1){
        for(int i =0 ; i<=9; i++){
                dfs(i , ans + to_string(i) , 0);
            }
    }
    else{
        visit[num] = true;
        if(v[n] == '<'){
            for(int i =num+1 ; i<=9; i++){
                if(!visit[i]){
                    dfs(i , ans +  to_string(i) , n +1);
                }
            }
        }
        else{
            for(int i =0 ; i<=num-1; i++){
                if(!visit[i]){
                    dfs(i , ans +  to_string(i)  , n+1);

                }
            }
        }

        visit[num] = false;
    }


}
