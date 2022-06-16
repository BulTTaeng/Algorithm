#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int inp[3][3];
map<string ,int> m;
queue<pair<string , int>> q;
string target = "123456780";

int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1 };
int ans = -1;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string str="";

    for(int i =0; i<3; i++){
        for(int j =0; j<3; j++){
            cin >> inp[i][j];
            str += to_string(inp[i][j]);
        }
    }

    q.push({str , 0});

    m[str] = 1;
    int d = 0;
    int r , c;
    int loc;
    int nx , ny;

    while(!q.empty()){
        str = q.front().first;
        d = q.front().second;
        q.pop();

        if(str == target){
            ans = d;
            break;
        }

        for(int i =0; i<str.length() ; i++){
            if ( str[i] == '0'){
                loc = i;
                break;
            }
        }

        r = loc/3;
        c = loc%3;

        for(int i =0 ; i<4; i++){
            nx = r+dx[i];
            ny = c + dy[i];

            if(nx >= 0 && ny>=0 && nx<3 && ny<3){
                swap(str[loc] , str[nx*3+ny]);
                
                if(m[str] == 0){
                    q.push({str , d+1});
                    m[str] =1;
                }
                swap(str[nx*3+ny] , str[loc]);
            }
        }
    }

    cout << ans;
    return 0;
}
