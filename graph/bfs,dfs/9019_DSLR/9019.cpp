#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int snum , tnum , T;
bool visit[10000];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;

    int num  , dnum , rnum , snum ,lnum;
    string op;

    while(T--){
        cin >> snum >> tnum;

        queue<pair<int ,string>> q;
        memset(visit ,false ,sizeof(visit));

        q.push(make_pair(snum , ""));

        while(!q.empty()){
            num = q.front().first;
            op = q.front().second;
            q.pop();

            if(num == tnum){
                cout << op << "\n";
                break;
            }

            dnum = (num *2) % 10000;

            if(!visit[dnum] ){
                q.push(make_pair(dnum , op + "D"));
                visit[dnum] = true;
            }

            snum = num-1;

            if(snum == -1){
                snum = 9999;
            }
            if(!visit[snum]){
                q.push(make_pair(snum , op + 'S'));
                visit[snum] = true;
            }

            lnum =  (num - (num/1000) *1000) * 10 + (num/1000);

            if(!visit[lnum]){
                q.push(make_pair(lnum , op+'L'));
                visit[lnum] = true;
            }

            rnum = (num%10)*1000 + (num/10);

            if(!visit[rnum]){
                q.push(make_pair(rnum , op+'R'));
                visit[rnum] = true;
            }

            
        }
    }

    return 0;
}
