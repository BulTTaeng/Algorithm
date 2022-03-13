#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int A  , B , C;
bool visit[1501][1501];

struct st{
    int a;
    int b;
    int c;
}typedef st;

queue<st> q;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    memset(visit ,false ,sizeof(visit));

    cin >> A >> B >> C;
    
    st temp;
    temp.a = A;
    temp.b = B;
    temp.c = C;
    q.push(temp);

    visit[A][B] = true;

    int a, b, c;

    while(!q.empty()){
        a = q.front().a;
        b = q.front().b;
        c = q.front().c;
        q.pop();

        if(a == b && b == c ){
            cout << 1;
            return 0;
        }

        if(a>b){
            temp.a = a-b;
            temp.b = b+b;
            temp.c = c;
            if(!visit[temp.a][temp.b] ){
                q.push(temp);
                visit[temp.a][temp.b] = true;
            }
        }

        if(c>b){
            temp.a = a;
            temp.b = b+b;
            temp.c = c-b;
            if(!visit[temp.a][temp.b] ){
                q.push(temp);
                visit[temp.a][temp.b] = true;
            }

        }

        if(b>a){
            temp.a = a+a;
            temp.b = b-a;
            temp.c = c;
            if(!visit[temp.a][temp.b] ){
                q.push(temp);
                visit[temp.a][temp.b] = true;
            }
        }

        if(c>a){
            temp.a = a+a;
            temp.b = b;
            temp.c = c-a;
            if(!visit[temp.a][temp.b] ){
                q.push(temp);
                visit[temp.a][temp.b] = true;
            }
            
        }

        if(b>c){
            temp.a = a;
            temp.b = b-c;
            temp.c = c+c;
            if(!visit[temp.a][temp.b] ){
                q.push(temp);
                visit[temp.a][temp.b] = true;
            }
        }

        if(a>c){
            temp.a = a-c;
            temp.b = b;
            temp.c = c+c;
            if(!visit[temp.a][temp.b] ){
                q.push(temp);
                visit[temp.a][temp.b] = true;
            }
        }
    }
    
    cout << 0;
    return 0;
}
