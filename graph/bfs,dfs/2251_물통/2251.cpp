#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visit[202][202][202];
int a , b, c;
bool ans[202];

struct st{
    int a;
    int b;
    int c;
}typedef st;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> a >> b >> c;
    memset(visit ,false ,sizeof(visit));
    memset(ans , false , sizeof(ans));
    visit[0][0][c] = true;
    ans[c] = true;

    st temp;
    temp.a = 0;
    temp.b = 0;
    temp.c = c;

    queue<st> q;
    q.push(temp);
    
    st newone;
    int x , y ,z;

    while(!q.empty()){
        temp = q.front();
        x = temp.a;
        y = temp.b;
        z = temp.c;
        q.pop();

        //c -> b , c-> a , a->c , a->b , b-> a , b->c
        
        //b have space
        if(y<b){
            //c -> b
            if(b-y >= z){
                if(!visit[x][y+z][0]){
                    newone.a = x;
                    newone.b = y+z;
                    newone.c = 0;
                    q.push(newone);
                    visit[x][y+z][0] = true;

                    if(x == 0){
                        ans[newone.c] = true;
                    }
                }
            }
            else{
                if(!visit[x][b][z-(b-y)]){
                    newone.a = x;
                    newone.b = b;
                    newone.c = z-(b-y);
                    q.push(newone);
                    visit[x][b][z-(b-y)] = true;

                    if(x == 0){
                        ans[newone.c] = true;
                    }
                }
            }

            //a - > b
            if(b-y >= x){
                if(!visit[0][x+y][z]){
                    newone.a = 0;
                    newone.b = x+y;
                    newone.c = z;
                    q.push(newone);
                    visit[0][x+y][z] = true;

                    ans[newone.c] = true;
                    
                }
            }
            else{
                if(!visit[x - (b-y)][b][z] ){
                    newone.a = x - (b-y);
                    newone.b = b;
                    newone.c = z;
                    q.push(newone);
                    visit[x - (b-y)][b][z] = true;

                    if(newone.a == 0){
                        ans[newone.c] = true;
                    }
                }
            }

        }

        //a have space
        if(x < a){
            //c->a
            if(a-x >= z){
                if(!visit[x+z][y][0]){
                    newone.a = x+z;
                    newone.b = y;
                    newone.c = 0;
                    q.push(newone);
                    visit[x+z][y][0] = true;

                    if(newone.a == 0){
                        ans[newone.c] = true;
                    }
                }
            }
            else{
                if(!visit[a][y][z - (a-x)]){
                    newone.a = a;
                    newone.b = y;
                    newone.c = z - (a-x);
                    q.push(newone);
                    visit[newone.a][newone.b][newone.c] = true;

                    if(newone.a == 0){
                        ans[newone.c] = true;
                    }
                }
            }

            //b ->a
            if(a-x >= y){
                if(!visit[x+y][0][z]){
                    newone.a = x+y;
                    newone.b = 0;
                    newone.c = z;
                    q.push(newone);
                    visit[newone.a][newone.b][newone.c] = true;

                    if(newone.a == 0){
                        ans[newone.c] = true;
                    }
                }
            }
            else{
                if(!visit[a][y - (a-x)][z]){
                    newone.a = a;
                    newone.b = y - (a-x);
                    newone.c = z;
                    q.push(newone);
                    visit[newone.a][newone.b][newone.c] = true;

                    if(newone.a == 0){
                        ans[newone.c] = true;
                    }
                }
            }
            
        }

        //if c have space
        if(z < c){
            //a->c
            if(c-z >= x){
                if(!visit[0][y][x+z]){
                    newone.a = 0;
                    newone.b = y;
                    newone.c = x+z;
                    q.push(newone);
                    visit[newone.a][newone.b][newone.c] = true;

                    if(newone.a == 0){
                        ans[newone.c] = true;
                    }
                }
            }
            else{
                if(!visit[x - (c-z)][y][c]){
                    newone.a = x-(c-z);
                    newone.b = y;
                    newone.c = c;
                    q.push(newone);
                    visit[newone.a][newone.b][newone.c] = true;

                    if(newone.a == 0){
                        ans[newone.c] = true;
                    }
                }
            }

            //b->c
            if(c-z >= y){
                if(!visit[x][0][y+z]){
                    newone.a = x;
                    newone.b = 0;
                    newone.c = y+z;
                    q.push(newone);
                    visit[newone.a][newone.b][newone.c] = true;

                    if(newone.a == 0){
                        ans[newone.c] = true;
                    }
                }
            }
            else{
                if(!visit[x][y - (c-z)][c]){
                    newone.a = x;
                    newone.b = y-(c-z);
                    newone.c = c;
                    q.push(newone);
                    visit[newone.a][newone.b][newone.c] = true;

                    if(newone.a == 0){
                        ans[newone.c] = true;
                    }
                }
            }
        }
        
        
    }// end of queue

    for(int i =0; i<=c; i++){
        if(ans[i] == true){
            cout << i << " ";
        }
    }
    return 0;
    
}
