#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

string board = "";
set<string> s;
int ans = 0;
queue<pair<int,string>> q;

string A(string str);
string B(string str);
string C(string str);
string D(string str);
void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char c;
    
    for (int i =0; i<2; i++) {
        for (int j =0; j<4; j ++) {
            cin >> c;
            board += c;
        }
    }

    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    q.push({0,"12345678"});
    s.insert("12345678");

    while(!q.empty()) {
        int time = q.front().first;
        string curr = q.front().second;
        q.pop();

        if (curr == board) {
            ans = time;
            break;
        }

        string n = A(curr);
        
        if(s.find(n) == s.end()) {
            q.push({time+1, n});
            s.insert(n);
        }

        n = B(curr);
        
        if(s.find(n) == s.end()) {
            q.push({time+1, n});
            s.insert(n);
        }

        n = C(curr);
        
        if(s.find(n) == s.end()) {
            q.push({time+1, n});
            s.insert(n);
        }

        n = D(curr);
        
        if(s.find(n) == s.end()) {
            q.push({time+1, n});
            s.insert(n);
        }
    }
}

string A(string str) {
    for (int i =0; i<4; i++) {
        swap(str[i], str[7-i]);
    }
    return str;
}

string B(string str) {
    string t = str;
    for (int i =3; i>=1; i--) {
        t[i] = t[i-1];
    }
    t[0] = str[3];
    for (int i =4; i<8; i++) {
        t[i] = t[i+1];
    }
    t[7] = str[4];
    return t;
}

string C(string str) {
    swap(str[1], str[2]);
    swap(str[2], str[5]);
    swap(str[5], str[6]);
    return str;
}

string D(string str) {
    swap(str[0], str[4]);
    return str;
}
