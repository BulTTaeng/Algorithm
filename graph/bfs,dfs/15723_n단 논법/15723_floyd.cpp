#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N,M;
bool graph[27][27];
int n1, n2;
string s,t, is;

void floyd();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(graph, false, sizeof(graph));

    cin >> N;
    for (int i =0; i<N; i++) {
        cin >> s >> is >> t;
        n1 = (int)(s[0]-'a');
        n2 = (int)(t[0]-'a');
        graph[n1][n2] = true;
    }

    floyd();

    cin >> M;

    for (int i =0; i<M; i++) {
        cin >> s >> is >> t;
        n1 = (int)(s[0]-'a');
        n2 = (int)(t[0]-'a');
        
        if (graph[n1][n2]) {
            cout << "T" << "\n";
        } else {
            cout << "F" << "\n";
        }
    }
    return 0;
}

void floyd() {
    for (int k=0; k<26; k++) {
        for (int i =0; i<26; i++) {
            for (int j =0; j<26; j++) {
                if(graph[i][k] && graph[k][j]) graph[i][j] = true;
            }
        }
    }
}
