#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<string> v;
bool visit[101];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    string str;

    for(int i =0; i<N; i++) {
        cin>> str;
        v.push_back(str);    
    }

    int ans = 0;    
    bool poss = true;
    char temp= '-';

    for(int i =0; i<v.size(); i++){
        str = v[i];
        poss = true;
        memset(visit ,false ,sizeof(visit));
        temp = '-';
        
        for(int j =0; j<str.length() ; j++){
            if(temp == str[j]){
                continue;
            }
            if(visit[str[j] - 'a']){
                poss= false;
                break; 
            }
            else{
                visit[str[j] - 'a'] = true;
                temp = str[j];
            }
        }

        if(poss){
            ans++;
        }
        
    }

    cout << ans;
    return 0;

}
