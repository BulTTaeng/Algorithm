#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N , K;

int mini =987654321;
bool visit[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> K;
    queue<pair<int , int>>q;
    q.push(make_pair(N,0));
    int loc , d;
    int nx ,count = 0;

    memset(visit ,false ,sizeof(visit));
    visit[N] = true;
    vector<int> v;

    int num = 0;

    while(!q.empty()){
        loc = q.front().first;
        d = q.front().second;
        q.pop();

        if(d > mini){
            break;
        }

        if(d > num){
            for(int i =0; i<v.size(); i++){
                visit[v[i]] = true;
            }
            v.clear();
            num++;
        }

        v.push_back(loc);
        
        if(mini != 987654321){
            if(d == mini && loc == K){
                count ++;
            }
            continue;
        }

        else if(loc == K){
            mini = d;
            count++;
            continue;
        }

        nx = loc +1;

        if(nx >=0 && nx<= 100000){
            if(!visit[nx]){
                q.push(make_pair(nx , d+1));
                //v.push_back(nx);
            }
        }

        int nx1 = loc -1;

        if(nx1 >=0 && nx1<= 100000){
            if(!visit[nx1]){
                q.push(make_pair(nx1 , d+1));
                //v.push_back(nx1);
            }
        }

        int nx2 = loc *2;

        if(nx2 >=0 && nx2<= 100000){
            if(!visit[nx2]){
                q.push(make_pair(nx2 , d+1));
                //v.push_back(nx2);
            }
        }



        
    }

    cout << mini << "\n" << count;
    return 0;

}
