#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int ans = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0,0,1,-1};
int iter1 = 0;
int iter2 = 0;

vector<pair<int,int>> gamePuzzle[2501];
vector<pair<int,int>> tablePuzzle[2501];
bool visit[2501];


void boardReverse(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j])
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }
}

void pullTo0(vector<pair<int,int>> &t){
    int minx = 55;
    int miny = 55;
    
    for(int i =0; i<t.size() ; i++){
        minx = min(t[i].first , minx);
        miny = min(t[i].second, miny);
    }
    
    for(int i =0; i<t.size() ; i++){
        t[i].first -= minx;
        t[i].second -= miny;
    }
    
    sort(t.begin(), t.end());
    
}

void dfs(int cx, int cy, vector<vector<int>> &board , int iter , int mode){
    board[cx][cy] = 0;
    
    if(mode == 1) gamePuzzle[iter].push_back({cx,cy});
    else tablePuzzle[iter].push_back({cx,cy});
    
    for(int i =0; i<4; i++){
        
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        
        if(nx<0 || ny <0 || nx>=N || ny >=N) continue;
        
        if(board[nx][ny] == 1){
            dfs(nx,ny,board , iter,mode);
        }
    }
}

void getPuzzleShapes(int x, int y, vector<vector<int>> &board, int mode){
    
    if(mode == 1){
        dfs(x,y, board, iter1, 1);
        pullTo0(gamePuzzle[iter1]);
        iter1++;
    }
    else{
        dfs(x,y, board, iter2, 2);
        pullTo0(tablePuzzle[iter2]);
        iter2++;
    }
    
}


void rotate(vector<pair<int,int>> &curr){
    //00 01 02 12 22 23
    //02 12 22 21 20 30
    
    //30 20 10 11 12 02
    
    int minr = 987654321;
    
    for(int i =0; i<curr.size(); i++){
        minr = min(minr , curr[i].first);
        minr = min(minr , curr[i].second);
    }
    
    int f;
    
    for(int i =0; i<curr.size(); i++){
        f = curr[i].first;
        curr[i].first = curr[i].second;
        curr[i].second = minr - f;
    }
    
    sort(curr.begin(), curr.end());
    pullTo0(curr);
    
    // for(int i =0; i<curr.size(); i++){
    //     cout << curr[i].first << "|" << curr[i].second <<" ";
    // }
    // cout <<"\n";
}

void findSamePuzzle(){
    
    bool poss= true;
    
    for(int i =0; i<iter1; i++){
        for(int j =0; j<iter2; j++){
            
            if(visit[j]) continue;
            if(gamePuzzle[i].size() != tablePuzzle[j].size()) continue;
            
            for(int p = 0; p<4; p++){
                poss =true;
                
                for(int k=0; k<gamePuzzle[i].size() ; k++){
                    if(gamePuzzle[i][k].first != tablePuzzle[j][k].first || gamePuzzle[i][k].second != tablePuzzle[j][k].second){
                        poss = false;
                        break;
                    }
                }// k

                if(poss){
                    ans += gamePuzzle[i].size();
                    visit[j] = true;
                    break;
                }
                if(p != 3) rotate(tablePuzzle[j]);
            }//p
            
            if(poss){
                break;
            }
        }// j
    } // i
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    N = game_board.size();
    boardReverse(game_board);
    
    for(int i =0; i<game_board.size(); i++){
        for(int j=0; j<game_board[i].size(); j++){
            if(game_board[i][j] == 1){
                getPuzzleShapes(i,j, game_board,1);
            }
            
            if(table[i][j] == 1){
                getPuzzleShapes(i,j,table,2);
            }
        }
    }
    
    memset(visit ,false ,sizeof(visit));
    findSamePuzzle();
    
    // for(int i =0; i<iter1; i++){
    //     for(int j =0; j<gamePuzzle[i].size(); j++){
    //         cout << gamePuzzle[i][j].first << " " << gamePuzzle[i][j].second << "/";
    //     }
    //     cout << "\n";
    // }
    
    // for(int i =0; i<iter2; i++){
    //     for(int j =0; j<tablePuzzle[i].size(); j++){
    //         cout << tablePuzzle[i][j].first << "/" << tablePuzzle[i][j].second << " ";
    //     }
    //     cout << "\n";
    // }
    
    answer = ans;
    return answer;
}
