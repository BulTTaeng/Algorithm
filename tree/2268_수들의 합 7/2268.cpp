#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N , M;
int a ,b ,c;
long long inp[1000001];
vector<long long> stree;

void initSegtree();
long long makeSegTree(int Node , int start ,int end);
long long query(int Node , int start , int end , int left , int right);
void update(int Node , int start ,int end ,int target , long long diff);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M;

    memset(inp , 0 ,sizeof(inp));

    initSegtree();

    for(int i =0; i<M; i++){
        cin >> a >> b >> c;

        if(a == 0){
            if(b > c){
                swap(b,c);
            }
            cout << query(1,1,N,b,c) << "\n";
        }
        else{
            update(1,1,N,b , c - inp[b]);
        }
    }
    
    return 0;
}

void initSegtree(){
    int h = (int)ceil(log2(N));
    int size =  1 << (h+1);
    stree.resize(size);
    makeSegTree(1,1,N);
}

long long makeSegTree(int Node , int start , int end){

    if(start == end) return stree[Node] = inp[start];

    int mid = (start+end)/2;

    long long left = makeSegTree(Node*2 , start, mid);
    long long right = makeSegTree(Node*2 + 1 , mid+1 , end);

    return stree[Node] = left+right;
    
}

long long query(int Node , int start , int end , int left , int right){
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) return stree[Node];

    int mid = (start+end)/2;

    return query(Node*2 , start , mid , left ,right) + query(Node*2+1 , mid+1 , end , left ,right);
}

void update(int Node , int start ,int end ,int target , long long diff){
    if(target < start || target > end) return;

    stree[Node] += diff;

    if(start == end){
        inp[target] += diff;
    }
    else{
        int mid = (start+end)/2;
        update(Node*2 , start , mid , target ,diff);
        update(Node*2 +1 , mid+1 , end ,target , diff);
    }

}
