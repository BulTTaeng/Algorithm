#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int x;
int loc;
int N;
int flag = -1;

void r_inorder(int curr);
void inorder(int curr);
void postorder(int curr);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    v.push_back(0);

    for (int i =0; i<N; i++) {
        cin >> x;
        if (x == -1) loc = i;
        v.push_back(x);
    }

    cin >> x;

    inorder(1);
	  r_inorder(1);
	  postorder(1);
    
    return 0;
}

void r_inorder(int curr) {
	if (curr < 1 || curr > N) return;
	r_inorder(curr*2+1);
	if (v[curr] == -1) {
        flag = 0;
		v[curr] = x;
	}
	if (flag == -1) {
		if (v[curr] < x) swap(v[curr], x);
	}
	r_inorder(curr*2);
}

void inorder(int curr) {
	if (curr < 1 || curr > N) return;
	inorder(curr*2);
	if (v[curr] > x) swap(v[curr], x);
	inorder(curr*2+1);
}

void postorder(int curr) {
	if (curr < 1 || curr > N) return;
	postorder(curr*2);
	postorder(curr*2+1);
	cout << v[curr] << " ";
}
