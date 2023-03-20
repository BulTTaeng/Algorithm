#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <math.h>

using namespace std;

bool visit[102];
int t, n;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> t;
    int x , y , sx ,sy , ex ,ey;

    for(int k =0; k<t ; k++){
        
        vector<pair<int , int>> v;
        memset(visit, false ,sizeof(visit));
        cin >> n;
        cin >> sx >> sy;
        for(int i=0; i<n; i++){
            cin >> x >> y;
            v.push_back(make_pair(x,y));
        }
        cin >> ex  >> ey;
        v.push_back(make_pair(ex , ey));

        int dis;
        int d1 ,d2;
        queue<pair<int , int>> q;
        q.push(make_pair(sx ,sy));
        int f , s;
        bool poss = false;

        while(!q.empty()){
            f = q.front().first;
            s = q.front().second;
            q.pop();

            if(f == ex && s == ey){
                poss =true;
                break;
            }

            for(int i =0; i<v.size(); i++){
                d1 = abs(f - v[i].first);
                d2 = abs(s - v[i].second); 
                dis = d1+d2;
                if(!visit[i] && dis <=1000){
                    q.push(make_pair(v[i].first , v[i].second));
                    visit[i] =true;
                }
            }


        }

        if(poss){
            cout << "happy" << "\n";
        }
        else{
            cout << "sad" << "\n";
        }
    }

    return 0;
}
