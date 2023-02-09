#include <iostream>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

set<long long> S;

long long s , t;
queue<pair<long long , string >> q;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> s >> t;

    if(s == t){
        cout << 0;
        return 0;
    }
  
    q.push(make_pair(s , ""));
    long long n;
    string d;
    long long nx;
  
    while(!q.empty()){
        n = q.front().first;
        d = q.front().second;
        q.pop();

        S.insert(n);

        if(n == t){
            cout << d;
            return 0;
        }

        nx = n * n;

        if(nx<=1000000000){
            if(S.find(nx) == S.end()){
                q.push(make_pair(nx , d + "*"));
                //S.insert(nx);
            }
        }

        nx = n + n;

        if(nx<=1000000000){
            if(S.find(nx) == S.end()){
                q.push(make_pair(nx , d + "+"));
                //S.insert(nx);
            }
        }

        nx = n - n;

        if(nx<=1000000000){
            if(S.find(nx) == S.end()){
                q.push(make_pair(nx , d + "-"));
                //S.insert(nx);
            }
        }

        if(n != 0){
            nx = n / n;

            if(nx<=1000000000){
                if(S.find(nx) == S.end()){
                    q.push(make_pair(nx , d+ "/"));
                    //S.insert(nx);
                }
            }
        }


    }
    
    cout << -1;
    
    return 0;
}
