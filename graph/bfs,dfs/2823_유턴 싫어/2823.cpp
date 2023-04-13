#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char inp[11][11];

struct st
{
    int x;
    int y;
    int px;
    int py;
}typedef st;


vector<pair<int , int>> v;
int ans=0;

int main(){
    int r ,c ;

    cin >> r >> c;

    for(int i =0;i <r; i++){
        for(int j =0; j<c ; j++){
            cin >> inp[i][j];
            if(inp[i][j] == '.'){
                v.push_back(make_pair(i,j));
            }
        }
    }
    int sf , ss , t =0;

    for(int i =0; i<v.size(); i++){
        sf = v[i].first;
        ss = v[i].second;

        queue<st> q;
        st temp , newone;
        temp.x = sf;
        temp.y = ss;
        temp.px = 999;
        temp.py = 999;

        q.push(temp);
        
        int f , s , pf , ps;
        ans = 0;
        t=0;

        while(!q.empty()){
            temp = q.front();
            q.pop();
            t =0;
            f = temp.x;
            s = temp.y;
            pf = temp.px;
            ps = temp.py;

            if(f == sf && s == ss){
                if(pf == 999 && ps == 999){

                }
                else{
                    ans=0;
                    break;
                }
            }

            if(f-1 >= 0 ){
                if(inp[f-1][s] == '.'){
                    if(f-1 == pf && s==ps){
                        t=t;
                    }
                    else{
                        newone.x =f-1;
                    newone.y = s;
                    newone.px = f;
                    newone.py = s;
                    q.push(newone);
                    t++;
                    }
                    
                }
            }

            if(s-1 >= 0 ){
                if(inp[f][s-1] == '.'){
                    if(f == pf && s-1==ps){
                        t=t;
                    }
                    else{
                        newone.x =f;
                    newone.y = s-1;
                    newone.px = f;
                    newone.py = s;
                    q.push(newone);
                    t++;
                    }
                    
                }
            }

            if(f+1 < r ){
                if(inp[f+1][s] == '.'){
                    if(f+1 == pf && s==ps){
                        t=t;
                    }
                    else{
                        newone.x =f+1;
                    newone.y = s;
                    newone.px = f;
                    newone.py = s;
                    q.push(newone);
                    t++;
                    }
                    
                }
            }
            if(s+1 < c ){
                if(inp[f][s+1] == '.'){
                    if(f == pf && s+1==ps){
                        t=t;
                    }
                    else{
                        newone.x =f;
                    newone.y = s+1;
                    newone.px = f;
                    newone.py = s;
                    q.push(newone);
                    t++;
                    }
                    
                }
            }

            if(t == 0){
                ans = 1;
                break;
            }
        }

        if(ans == 0){
            continue;
        }
        else{
            break;
        }
        
    }


    cout << ans;
    return 0;
}
