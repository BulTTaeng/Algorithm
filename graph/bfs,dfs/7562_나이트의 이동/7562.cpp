#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visit[303][303];

struct st{
    int x;
    int y;
    int depth;
} typedef st;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t , n ,cx,cy ,tx,ty;
    cin >> t;

    for(int i =0; i<t ; i++){
        cin >> n;
        cin >> cx >> cy;
        cin >> tx >> ty;

        int ans = 0;

        memset(visit, false ,sizeof(visit));

        queue<st> q;

        st temp;
        temp.x = cx;
        temp.y = cy;
        temp.depth = 0;

        int f , s;
        st temp2;

        q.push(temp);
        
        while(!q.empty()){
            temp = q.front();
            q.pop();

            f = temp.x;
            s = temp.y;

            visit[f][s] = true;
            
            if(f == tx && s == ty){
                ans = temp.depth;
                break;
            }

            if(f-2 >=0 && s+1<n){
                if(!visit[f-2][s+1]){
                    temp2.x = f-2;
                    temp2.y = s+1;
                    temp2.depth = temp.depth+1;
                    q.push(temp2);
                    visit[f-2][s+1] = true;
                }
            }
            if(f-1 >=0 && s+2<n){
                if(!visit[f-1][s+2]){
                    temp2.x = f-1;
                    temp2.y = s+2;
                    temp2.depth = temp.depth+1;
                    q.push(temp2);
                    //q.push(make_pair(f-1, s+2));
                    visit[f-1][s+2] = true;
                }
            }


            if(f+1 <n && s+2<n){
                if(!visit[f+1][s+2]){
                    temp2.x = f+1;
                    temp2.y = s+2;
                    temp2.depth = temp.depth+1;
                    q.push(temp2);
                    //q.push(make_pair(f+1, s+2));
                    visit[f+1][s+2] = true;
                }
            }
            if(f+2 <n && s+1<n){
                if(!visit[f+2][s+1]){
                    temp2.x = f+2;
                    temp2.y = s+1;
                    temp2.depth = temp.depth+1;
                    q.push(temp2);
                    //q.push(make_pair(f+2, s+1));
                    visit[f+2][s+1] = true;
                }
            }


            if(f+2 <n && s-1>=0){
                if(!visit[f+2][s-1]){
                    temp2.x = f+2;
                    temp2.y = s-1;
                    temp2.depth = temp.depth+1;
                    q.push(temp2);
                    //q.push(make_pair(f+2, s-1));
                    visit[f+2][s-1] = true;
                }
            }
            if(f+1 <n && s-2>=0){
                if(!visit[f+1][s-2]){
                    temp2.x = f+1;
                    temp2.y = s-2;
                    temp2.depth = temp.depth+1;
                    q.push(temp2);
                    //q.push(make_pair(f+1, s-2));
                    visit[f+1][s-2] = true;
                }
            }


            if(f-1 >=0 && s-2>=0){
                if(!visit[f-1][s-2]){
                    temp2.x = f-1;
                    temp2.y = s-2;
                    temp2.depth = temp.depth+1;
                    q.push(temp2);
                    //q.push(make_pair(f-1, s-2));
                    visit[f-1][s-2] = true;
                }
            }
            if(f-2 >=0 && s-1>=0){
                if(!visit[f-2][s-1]){
                    temp2.x = f-2;
                    temp2.y = s-1;
                    temp2.depth = temp.depth+1;
                    q.push(temp2);
                    //q.push(make_pair(f-2, s-1));
                    visit[f-2][s-1] = true;
                }
            }

        }
        cout << ans << "\n";
    }
}
