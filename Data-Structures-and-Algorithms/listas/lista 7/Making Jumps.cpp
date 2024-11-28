#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool valid(vector<vector<int>> &B, int r, int c){
    if (r < 0 || r >= (int)B.size()) 
        return false;
    else if (c < 0 || c >= (int)B[r].size())
        return false;
    else if (B[r][c] != 0) 
        return false;
    else 
        return true;
}

int solve(int r, int c, vector<vector<int>> &B){
    int anws = INT_MAX;
    for (auto &move : moves){
        int new_r = r + move.first;
        int new_c = c + move.second;
        if (valid(B, new_r, new_c)){
            B[new_r][new_c] = 1;
            anws = min(anws, solve(new_r, new_c, B));
            B[new_r][new_c] = 0;
        }
    }

    if (anws != INT_MAX){
        return anws;
    }
    else{
        anws = 0;
        for (auto row : B){
            anws += count(begin(row), end(row), 0);
        }
        return anws;
    }
}

//not in the board = -1
//in the board/unvisited = 0
//visited = 1

int main() {
    int rows;
    int skip, count, anws;
    int c = 1;
    pair<int,int> start;

    while ((cin >> rows)) {
        if (rows == 0) break;

        vector<vector<int>> board(rows);

        for (int i = 0; i < rows; i++) {
            cin >> skip >> count;
            board[i].resize(skip + count, -1);
            fill(board[i].begin() + skip, board[i].end(), 0); 
        }

        if (board[0][0] != 0){
            for (int i = 0; i < (int)board.size(); ++i){
                for (int j = 0; j < (int)board[i].size(); ++j){
                    if (board[i][j] == 0){
                        start = make_pair(i, j);
                    }
                }
            }
            board[start.first][start.second] = 1;
            anws = solve(start.first, start.second, board);
        }
        else{
            board[0][0] = 1;
            anws = solve(0, 0, board);
        }

        cout << "Case " << c << ", " << anws << " square" << (anws != 1 ? "s":"") << " can not be reached.\n";
        c++;
    }
    return 0;
}
