#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int P, N;
float a,b,c =0;

int stones[101];
vector<pair<int,bool>> persons; // true: left false: right

void solve() {
    for (int i=0; i<persons.size(); i++) {
        int loc = persons[i].first;
        bool dir = persons[i].second;

        if (dir) { // left
            for (int j=loc-1; j>0; j--) {
                stones[j]++;
            }
        } else { // right
            for (int j=loc+1; j<=100; j++) {
                stones[j]++;
            }
        }
    }

    int count_a = 0, count_b = 0, count_c = 0;

    for (int i=1; i <=100; i++) {
        if (stones[i] % 3 == 0) {
            count_a++;
        } else if (stones[i] % 3 == 1) {
            count_b++;
        } else if (stones[i] % 3 == 2) {
            count_c++;
        }
    }

    a = P * (float)count_a / 100;
    b = P * (float)count_b / 100;
    c = P * (float)count_c / 100;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(stones, 0, sizeof(stones));

    cin >> P >> N;

    int loc;
    char dir;

    for (int i =0; i<N; i++) {
        cin >> loc >> dir;
        if (dir == 'L') {
            persons.push_back(make_pair(loc,true));
        } else {
            persons.push_back(make_pair(loc,false));
        }
    }

    solve();

    printf("%.2f", a);
    printf("\n");
    printf("%.2f", b);
    printf("\n");
    printf("%.2f", c);
    printf("\n");
    return 0;
} 
