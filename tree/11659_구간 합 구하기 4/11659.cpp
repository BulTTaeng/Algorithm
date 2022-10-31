#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N ,M;

int inp[100002];
vector<int> stree;

void segtree();
int makeSegtree(int Node, int s , int e);
int query(int Node, int s, int e, int l, int r);


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i =1; i<=N; i++){
        cin >> inp[i];
    }

    int s,e;

    segtree();

    for(int i =0; i<M;i++){
        cin >> s >> e; 
        cout << query(1,1,N,s,e) << "\n";
    }

    return 0;
}

void segtree(){
    int h = (int)ceil(log2(N));
    int size = 1 << (h+1);
    stree.resize(size);
    makeSegtree(1,1,N);
}

int makeSegtree(int Node, int s , int e){
    if (s == e) return stree[Node] = inp[s];
    
    int mid = (s + e) / 2;
    int l = makeSegtree(Node * 2, s, mid);
    //부모 노드의 왼쪽 자식은 부모노드*2
    int r = makeSegtree(Node * 2 + 1, mid + 1, e);
    //부모 노드의 오른쪽 자식은 부모노드*2+1
    return stree[Node] = l + r;

}

int query(int Node, int s, int e, int l, int r){
    if (r < s || l > e) return 0; //범위초과한 케이스
    if (l <= s && e <= r) return stree[Node]; //원하는 구간 <= 현재 구간
 
    int mid = (s + e) / 2;
    int nextl = query(Node * 2, s, mid, l, r);
    int nextr = query(Node * 2 + 1, mid + 1, e, l, r);
    return nextl + nextr;
}
