#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int num[200003];
int root[200003];
int T , N;
map<string ,int> m;

string name1 , name2;

int Find(int x);
void Union(int x , int y);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> T;
    int k = 1;
    int g1 , g2;
    int f;

    while(T--){
        cin >> N;
        k = 1;
        m.clear();
        
        for(int i =0 ; i<=N*2+1; i++){
            root[i] = i;
        }
        memset(num , 0 , sizeof(num));

        for(int i =0; i<N; i++){
            cin >> name1 >> name2;
            g1 = m[name1];
            g2 = m[name2];

            if(g1 == 0 && g2 == 0){
                m[name1] = k;
                k++;
                m[name2] = k;
                k++;

                Union((k-2) ,(k-1) );
                f = Find(k-2);
                num[f] += 2;
                cout << num[f] << "\n";
            }
            else if(g1 == 0 && g2 != 0){
                m[name1] = k;
                k++;
                
                Union(m[name1] , m[name2]);
                f = Find(m[name1]);

                num[f]++;
                cout << num[f] << "\n";
            }
            else if(g2 == 0 && g1 != 0){
                m[name2] = k;
                k++;

                Union(m[name1] , m[name2]);
                f= Find(m[name2]);

                num[f]++;
                cout << num[f] << "\n";
            }
            else{ // exist
                int f1 = Find(g1);
                int f2 = Find(g2);

                if(f1 == f2){
                    cout << num[f1] << "\n";
                }
                else{
                    int temp = num[f1] + num[f2];
                    Union(m[name1] , m[name2]);
                    f = Find(m[name1]);
                    num[f] = temp;
                    cout << num[f] << "\n";
                }
            }
        }
    }
}


int Find(int x ){
    if(root[x] == x) return x;
    else{
        return root[x] = Find(root[x]);
    }
}

void Union(int x , int y){
    x = Find(x);
    y = Find(y);

    if (x < y) {
		root[y] = x;
	}
	else if(x>y){
		root[x] = y;
	}
}
