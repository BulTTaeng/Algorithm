#include <iostream>
#include <cstring>
#include <math.h>
#include <queue>

using namespace std;

bool num[10000];
bool visit[10000];
int T , start , target;

bool is_prime(int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    for(int i =1000; i<=9999; i++){
        num[i] = is_prime(i);
    }

    cin >> T;

    int next , curr , d , ans = -1;

    while(T--){
        cin >> start >> target;
        queue<pair<int , int>>q;
        memset(visit ,false, sizeof(visit));
        ans = -1;

        q.push(make_pair(start , 0 ));
        visit[start] = true;

        while(!q.empty()){
            curr =q.front().first;
            d = q.front().second;
            q.pop();

            if(curr == target){
                ans = d;
                break;
            }

            for(int i =1; i <=9; i++){
                next = curr - (curr/1000)*1000 +i*1000;
                if(next == curr){
                    continue;
                }

                if(num[next] && !visit[next]){
                    q.push(make_pair(next , d+1));
                    visit[next] = true;
                }

            }

            for(int i =0; i <=9; i++){
                next = curr - ((curr/100) - (curr/1000) *10)*100 +i*100;
                if(next == curr){
                    continue;
                }

                if(num[next] && !visit[next]){
                    q.push(make_pair(next , d+1));
                    visit[next] = true;
                }

            }

            for(int i =0; i <=9; i++){
                next = curr - (curr%100 - curr%10) + i*10;
                if(next == curr){
                    continue;
                }

                if(num[next] && !visit[next]){
                    q.push(make_pair(next , d+1));
                    visit[next] = true;
                }

            }

            for(int i =0; i <=9; i++){
                next = curr - curr%10 + i;
                if(next == curr){
                    continue;
                }

                if(num[next] && !visit[next]){
                    q.push(make_pair(next , d+1));
                    visit[next] = true;
                }

            }

        }

        if(ans == -1){
            cout <<  "Impossible" << "\n";
        }
        else{
            cout << ans <<"\n";
        }
        
    }

    return 0;
}

bool is_prime(int num){
    int a = sqrt(num);

    for(int i = 2; i <=a; i++){
        if(num%i == 0) return false;
    }

    return true;
}
