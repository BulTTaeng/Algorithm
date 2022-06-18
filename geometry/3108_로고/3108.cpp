#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;


struct square{
    int x1;
    int y1;
    int x2;
    int y2;
}typedef square;

int N;
bool check[1001];
int root[1001];
vector<square> v;

int x1, y1 , x2 , y2;
int xr , xl , yb ,yt;
int xdiff , ydiff;
int ans = 0;

int Find(int x);
void Union(int x , int y);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    square temp;
    temp.x1 = temp.y1 = temp.x2 = temp.y2 = 0;
    v.push_back(temp);

    for(int i =0; i<=N; i++){
        root[i] = i;
    }

    for(int i =1; i<=N; i++){
        cin >> x1 >> y1 >> x2 >> y2;

        for(int j= 0 ; j<v.size(); j++){
            temp = v[j];

            xr = min(x2, temp.x2);
            xl = max(x1, temp.x1);

            yb = max(y1, temp.y1);
            yt = min(y2, temp.y2);

            xdiff = xr - xl; 
            ydiff = yt - yb;

            if(temp.x1 <x1 && temp.y1 <y1 && temp.x2 > x2 && temp.y2 > y2){
                
            }
            else if(temp.x1 >x1 && temp.y1 > y1 && temp.x2 <x2 && temp.y2 < y2){
                
            }
            else if(temp.y1 > y2 || temp.x1 > x2 || y1 > temp.y2 || temp.x2 < x1){

            }
            else{
                Union(i,j);
            }
        }
        
        temp.x1 = x1;
        temp.y1 = y1;
        temp.x2 = x2;
        temp.y2 = y2;
        v.push_back(temp);
    }
    memset(check , false ,sizeof(check));

    int tt;

    for(int i = 0; i<=N; i++){
        tt= Find(i);
        
        if(!check[tt]){
            ans++;
            check[tt] = true;
        }
    }

    cout << ans-1;
    return 0;
}

int Find(int x ){
    if(root[x] == x) return x;
    else{
        return root[x] = Find(root[x]);
    }
}

void Union(int x , int y){
    x = Find(x);
    y = Find(y);

    root[y] = x;
}
