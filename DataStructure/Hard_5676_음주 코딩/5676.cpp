#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N , M;
int inp[100001];
char op;
int a, b;

vector<int> stree;

void initSegtree();
int makeSegTree(int Node , int start , int end);
int query(int Node , int start , int end , int left , int right);
int update(int Node ,int start , int end , int target , int diff);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    while(cin >> N >> M){
        memset(inp , 0 , sizeof(inp));

        for(int i =1; i<=N; i++){
            cin >> inp[i];
            if(inp[i] > 0 ){
                inp[i] = 1;
            }
            else if(inp[i] < 0 ) {
                inp[i] = -1;
            }
        }

        initSegtree();
        
        for(int i =0; i<M; i++){
            cin >> op >> a >> b;

            if(op == 'C'){

                if(b == 0){
                    update(1,1,N,a,0);
                }
                else if(b > 0){
                    update(1,1,N,a,1);
                }
                else{
                    update(1,1,N,a,-1);
                }
            }
            else{
                if(a>b){
                    swap(a,b);
                }
                int re = query(1,1,N,a,b);
                if(re == 0){
                    cout << 0;
                }
                else if( re > 0){
                    cout << '+';
                }
                else{
                    cout << '-';
                }
            }


        }
        cout << "\n";

    }

    return 0;
}

void initSegtree(){
    int h = (int)ceil(log2(N));
    int size = 1 << (h+1);
    stree.clear();
    stree.resize(size);
    makeSegTree(1,1,N);
}

int makeSegTree(int Node , int start ,int end){
    if(start == end) {
        return stree[Node] = inp[start];
    }


    int mid = (start+end)/2;

    int l = makeSegTree(Node*2 , start , mid);
    int r = makeSegTree(Node*2 + 1 , mid+1, end);
    
    return stree[Node] = l*r;
}

int query(int Node , int start ,int end ,int left ,int right){
    
    if(right < start || end < left) return 1;
    if(left <= start && end <= right) return stree[Node];

    int mid = (start+end)/2;

    int l = query(Node*2 , start , mid , left, right);
    int r = query(Node*2 + 1 , mid+1 , end, left ,right);

    return l*r;
}

int update(int Node ,int start , int end , int target , int diff){
    if(target > end || target < start) return stree[Node];

    if(start == end){
        return stree[Node] = diff;
    }
    else{
        int mid = (start+end)/2;

        int l = update(Node*2 , start , mid , target , diff);
        int r = update(Node*2+1 , mid+1 , end ,target , diff);

        return stree[Node] = l*r;
    }
}
