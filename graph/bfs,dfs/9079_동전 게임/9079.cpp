#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;
int ans = -1;

int visit[2][2][2][2][2][2][2][2][2];

struct coins{
    int coin[3][3];
}typedef coins;

coins inp;

queue<pair<coins, int>> q;

coins flipRow(coins c, int row);
coins flipCol(coins c, int col);
coins flipDiagonal(coins c, bool isLeftTop);
bool visited(coins c);
bool isAnswer(coins c);
void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    char temp;

    while(T--) {
        ans = -1;
        memset(visit, false, sizeof(visit));
        q = queue<pair<coins, int>>();
        
        for(int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                cin >> temp;
                if (temp == 'H') {
                    inp.coin[i][j] = 0;
                } else {
                    inp.coin[i][j] = 1;
                }
            }
        }

        bfs();

        cout << ans << "\n";
    }

    return 0;
}

void bfs() {
    q.push({inp, 0});
    visited(inp);
    
    while(!q.empty()) {
        coins curr = q.front().first;
        int times = q.front().second;
        q.pop();

        bool answerFound = isAnswer(curr);
        if (answerFound) {
            ans = times;
            break;
        }

        bool visitBefore = false;

        for (int i=0; i<3; i++) {
            coins rowFlip = flipRow(curr, i);
            coins colFlip = flipCol(curr, i);
            
            visitBefore = visited(rowFlip);

            if (!visitBefore) {
                q.push({rowFlip, times + 1});
            }

            visitBefore = visited(colFlip);

            if (!visitBefore) {
                q.push({colFlip, times + 1});
            }
        }

        coins diaFlip1= flipDiagonal(curr, true);
        visitBefore = visited(diaFlip1);
        if (!visitBefore) {
            q.push({diaFlip1, times + 1});
        }

        coins diaFlip2= flipDiagonal(curr, false);
        visitBefore = visited(diaFlip2);
        if (!visitBefore) {
            q.push({diaFlip2, times + 1});
        }
    }
}

coins flipRow(coins c, int row) {
    coins temp = c;
    for (int i=0; i<3; i++) {
        temp.coin[row][i] = (temp.coin[row][i]+1) %2; 
    }

    return temp;
}

coins flipCol(coins c, int col) {
    coins temp = c;
    for (int i=0; i<3; i++) {
        temp.coin[i][col] = (temp.coin[i][col]+1) %2; 
    }

    return temp;
}

coins flipDiagonal(coins c, bool isLeftTop) { // 대각선
    coins temp = c;
    if (isLeftTop) {
        for (int i =0; i<3; i++) {
            temp.coin[i][i] = (temp.coin[i][i] + 1) % 2; 
        }
    } else {
        for (int i =0; i<3; i++) {
            temp.coin[i][2-i] = (temp.coin[i][2-i] + 1) % 2; 
        }
    }

    return temp;
}


bool visited(coins c) {
    bool temp = visit[c.coin[0][0]] [c.coin[0][1]] [c.coin[0][2]] [c.coin[1][0]] [c.coin[1][1]] [c.coin[1][2]] [c.coin[2][0]] [c.coin[2][1]] [c.coin[2][2]];

    if (!temp) {
        visit[c.coin[0][0]] [c.coin[0][1]] [c.coin[0][2]] [c.coin[1][0]] [c.coin[1][1]] [c.coin[1][2]] [c.coin[2][0]] [c.coin[2][1]] [c.coin[2][2]] = true;
        return false;
    } else {
        return true;
    }
}

bool isAnswer(coins c) {

    int temp =0;
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            temp += c.coin[i][j];
            //cout << c.coin[i][j] << " ";
        }
        //cout << " \n";
    }

    //cout << "\n\n";

    if (temp == 9 || temp == 0) {
        return true;
    }
    return false;
}
