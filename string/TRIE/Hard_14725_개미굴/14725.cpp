#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N , K;

struct TRIE{
    map<string , TRIE*> m; 

    
    void insert(vector<string> v , int idx){
        if(idx == v.size()){
            return;
        }

        if(m.find(v[idx]) == m.end()){
            m[v[idx]] = new TRIE();
        }

        m[v[idx]]->insert(v, idx+1);
    }

    void print(int d){
        
        for(auto iter = m.begin() ; iter != m.end(); iter++){
            for(int i =0; i<d; i++){
                cout << "--";
            }
            cout << iter->first << "\n";
            iter->second->print(d+1);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    string temp;

    TRIE * root = new TRIE();

    for(int i =0 ;i<N; i++){
        cin >> K;
        vector<string> v;
        for(int j=0; j<K; j++){
            cin >> temp;
            v.push_back(temp);
        }

        root->insert(v, 0);
    }

    root->print(0);
}
