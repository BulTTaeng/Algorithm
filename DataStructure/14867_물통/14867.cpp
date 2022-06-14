#include <iostream>
#include <queue>
#include <map>

using namespace std;

int A, B , C , D;

struct st{
    int x;
    int y;
    int depth;
}typedef st;

queue<st> q;
map<int , bool> m[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> A >> B >> C >> D;
    st temp;
    temp.x = 0;
    temp.y = 0;
    temp.depth= 0;

    q.push(temp);
    int x, y , d;

    int ans = -1;

    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        d = q.front().depth;
        q.pop();
        //cout << x << "  " << y << " " << d << "\n";
        
        if(m[x][y]) continue;

        m[x][y] = true;

        if( x == C && y == D){
            ans = d;
            break;
        }


        if(x != 0 && y != 0){
            
            if( y != B){
                temp.x = 0;
                temp.y = y;
                temp.depth = d+1;
                q.push(temp);
            }

            if(x != A){
                temp.x = x;
                temp.y = 0;
                temp.depth = d+1;
                q.push(temp);
            }
        }


        if(x != A){
            temp.x = A;
            temp.y = y;
            temp.depth = d+1;
            q.push(temp);

            if(x+y > A){
                temp.x = A;
                temp.y = y - (A-x);
                temp.depth = d+1;
                q.push(temp);
            }
            else if (x+y > 0){
                temp.x = x+y;
                temp.y = 0;
                temp.depth = d+1;
                q.push(temp);
            }
        }

        if(y != B){
            temp.x = x;
            temp.y = B;
            temp.depth = d+1;
            q.push(temp);

            if(x+y > B){
                temp.x = x - (B-y);
                temp.y = B;
                temp.depth = d+1;
                q.push(temp);
            }
            else if (x+y > 0){
                temp.x = 0;
                temp.y = x+y;
                temp.depth = d+1;
                q.push(temp);
            }
        }


    }


    cout << ans;
    return 0;    
}

