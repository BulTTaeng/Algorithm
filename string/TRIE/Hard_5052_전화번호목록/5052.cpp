#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int T ,N;

char inp[10001][11];

struct TRIE{
    bool end;
    TRIE * Node[10];

    TRIE(){
        end = false;
        for(int i =0; i<10; i++){
            Node[i] = NULL;
        }
    }

    void insert(char *str){
        if(*str == '\0' ){
            end = true;
            return;
        }

        int cur = *str -'0';
        if(Node[cur] == NULL){
            Node[cur] = new TRIE();
        }
        Node[cur]->insert(str+1);
    }

    bool find(char *str){
        if(*str == '\0'){ // 자기 자신
            return false;
        }

        if(end == true){ // 자기 자신 찾는 도중에 다른 문자열이 끝남.
            return true;
        }

        int cur = (int)(*str - '0');
        if(Node[cur] == NULL){
            return false;
        }

        return Node[cur]->find(str+1);

    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;

    int t;
    string s;

    while(T--){
        cin >> N;

        TRIE *Root = new TRIE();
		for (int i = 0; i < N; i++) {
			cin >> inp[i];
			Root->insert(inp[i]);
		}
		int i;
		for(i=0; i<N;i++){
			if (Root->find(inp[i])) {
				cout << "NO\n";
				break;
			}
		}
		if (i == N)
			cout << "YES\n";


    }

    return 0;
}
