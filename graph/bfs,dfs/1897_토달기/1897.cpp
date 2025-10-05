#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <map>

using namespace std;

int d;
string word;
map<string, bool> m;
string ans = "";
queue<string> q;
//char alphaber[] = {a,b,c,d,e,f,g,h,i,g,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> d >> word;

    string temp;

    for (int i =0; i<d; i++) {
        cin >> temp;
        m.insert({temp, false});
    }

    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    q.push(word);
    m[word] = true;

    char a = 'a';
    char z = 'z';
    
    while(!q.empty()) {
        string x = q.front();
        q.pop();

        if(ans.length() < x.length()) {
            ans = x;
        } 

        for (int i =0; i<=x.length(); i++) {
            for (int j = (int)a; j<=(int)z; j++) {
                string nx = x;
                char curr = (char)j;
                nx.insert(i,string(1,curr));

                if (m.find(nx) != m.end() && m[nx] == false) {
                    q.push({nx});
                    m[nx] = true;
                }
            }

        }
    }
}
