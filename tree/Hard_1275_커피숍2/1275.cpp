#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long inp[100001];
vector<long long> segtree;
int N , Q , x,y,a,b;

void segTree();
long long makeSegTree(int Node , int start , int end);
long long query(int Node , int start ,int end , int left , int right);
void update(int Node , int start , int end , int target , long long diff);


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> Q;

    for(int i =1; i<=N; i++){
        cin >> inp[i];
    }

    segTree();


    for(int i =0; i<Q; i++){
        cin >> x >> y >> a >> b;
        if(x > y) swap(x,y);
        cout << query(1,1,N,x,y) << "\n";
        update(1,1,N,a,b-inp[a]);
    }

    return 0;
}

void segTree(){
    int h = (int)ceil(log2(N));
    int size = 1 << (h+1);
    segtree.resize(size);
    makeSegTree(1, 1 , N);
}

long long makeSegTree(int Node , int start , int end){

    if(start == end) return segtree[Node] = inp[start];

    int mid = (start+end)/2;

    long long left = makeSegTree(Node*2 , start, mid);
    long long right = makeSegTree(Node*2 + 1 , mid+1 , end);

    return segtree[Node] = left+right;
    
}

long long query(int Node , int start ,int end , int left , int right){
    if(right < start || end < left ) return 0;
    if(left <= start && end <= right) return segtree[Node];

    int mid = (start+end)/2;

    long long l = query(Node*2 , start, mid , left , right);
    long long r = query(Node*2+1 , mid+1 , end , left , right);

    return l+r;
}

void update(int Node , int start , int end , int target , long long diff){
    if(target < start || end < target) return;

    segtree[Node] += diff;

    if(start == end){
        inp[target] += diff; 
    }
    else{
        int mid = (start+end)/2;
        update(Node*2 , start , mid , target,diff);
        update(Node*2 +1 , mid+1 , end , target , diff);
    }
}
