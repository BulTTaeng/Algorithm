#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long a,b;

    cin >> a  >> b;

    queue<pair<long long, long long>>q;

    q.push(make_pair(a,1));

    long long f , s;
    long long ans = -1;
    long long nf;

    while(!q.empty()){
        f= q.front().first;
        s = q.front().second;
        q.pop();

        if(f == b){
            ans = s;
            break;
        }

        nf = f *2;

        if(nf <=b){
            q.push(make_pair(nf, s+1));
        }

        nf = f*10 +1;

        if(nf <=b){
            q.push(make_pair(nf, s+1));
        }
        
    }

    cout << ans;
    return 0;
}
