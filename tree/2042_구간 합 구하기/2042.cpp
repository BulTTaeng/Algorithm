#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N , M , K, a;
long long b, c;
long long inp[1000002];
vector<long long > stree;

void segtree();
long long makeSegTree(int Node , int start , int end);
long long query(int Node , int start , int end , int left , int right);
void update(int Node , int start , int end ,int target , long long diff);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M >> K;
    long long temp;

    for(int i =1; i<=N; i++){
        cin >> inp[i];    
    }

    segtree();

    for(int i =0; i<M+K; i++){
        cin >> a >> b >> c;
        if(a == 1){
            update(1,1,N,b, c - inp[b]);
        }
        else{
            cout << query(1,1,N,b,c) << " \n";
        }
    }

    return 0;
}

void segtree(){
    int h = (int)ceil(log2(N));
    int size = 1 << (h+1);
    stree.resize(size);
    makeSegTree(1,1,N);
}

long long makeSegTree(int Node , int start , int end){
    if(start == end) return stree[Node] = inp[start];
    
    int mid = (start+end)/2;

    long long left = makeSegTree(Node*2 , start , mid);
    long long right = makeSegTree(Node*2 +1 , mid+1 , end);

    return stree[Node] = left+right;
}

long long query(int Node , int start , int end , int left , int right){
    if(start > right || end < left) return 0;
    if(start >= left && end <= right) return stree[Node];

    int mid = (start+end)/2;

    long long l = query(Node*2 , start , mid , left, right);
    long long r = query(Node*2+1 , mid+1 , end , left ,right);

    return l+r;
}

void update(int Node , int start , int end ,int target , long long diff){
    if(target < start || target > end) return;

    stree[Node] += diff;

    if(start == end){
        inp[target] += diff;
    }
    else{
        int mid = (start +end)/2;
        update(Node*2 , start , mid , target , diff);
        update(Node*2 +1 , mid+1 , end , target , diff);
    }
}
