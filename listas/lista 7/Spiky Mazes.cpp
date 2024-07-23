#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool valid(vector<vector<char>> &maze, int r, int c, int n, int m){
    return r >= 0 && r < n && c >= 0 && c < m && maze[r][c] != '#';
}

bool findPath(vector<vector<char>> &maze, int start_r, int start_c, int n, int m, int j){
    queue<tuple<int,int,int>> q; //row, col, spikes
    vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
    q.push(make_tuple(start_r, start_c, 0));
    visited[start_r][start_c] = 0;

    while (!q.empty()){
        auto [r, c, spikes] = q.front();
        q.pop();

        if (maze[r][c] == 'x'){
            queue<tuple<int, int, int>> q_back;
            vector<vector<int>> visited_back(n, vector<int>(m, INT_MAX));

            q_back.push(make_tuple(r, c, spikes));
            visited_back[r][c] = spikes;
            while (!q_back.empty()){
                auto [back_r, back_c, back_spikes] = q_back.front();
                q_back.pop();

                if (back_r == start_r && back_c == start_c){
                    return true;
                }

                for (auto move : moves){
                    int new_r = back_r + move.first;
                    int new_c = back_c + move.second;

                    if (valid(maze, new_r, new_c, n, m)){
                        int new_spikes = back_spikes + (maze[new_r][new_c] == 's' ? 1 : 0);
                        if (new_spikes <= j && new_spikes < visited_back[new_r][new_c]){
                            visited_back[new_r][new_c] = new_spikes;
                            q_back.push(make_tuple(new_r, new_c, new_spikes));
                        }
                    }
                }
            }
            return false;
        }
        
        for (auto move : moves){
            int new_r = r + move.first;
            int new_c = c + move.second;

            if (valid(maze, new_r, new_c, n, m)){
                int new_spikes = spikes + (maze[new_r][new_c] == 's' ? 1 : 0);
                if (new_spikes <= j && new_spikes < visited[new_r][new_c]){
                    visited[new_r][new_c] = new_spikes;
                    q.push(make_tuple(new_r, new_c, new_spikes));
                }
            }
        }
    }
    return false;
}

string solve(vector<vector<char>> &maze, int r, int c, int n, int m, int j){
   if (findPath(maze, r, c, n, m, j)){
        return "SUCCESS";
    } 
    else{
        return "IMPOSSIBLE";
    } 
}

//x = treasure
//@ = entrance/exit
//# = walls
//. = safe
//s = spike
int main(){
    int n, m, j;
    char ob;
    pair<int, int> start;
    cin >> n >> m >> j;
    vector<vector<char>> maze(n, vector<char>(m));
    for (int l = 0; l < n; l++){
        for (int c = 0; c < m; c++){
            cin >> ob;
            maze[l][c] = ob;
            if (ob == '@'){
                start = make_pair(l, c);
            }
        }
    }

    cout << solve(maze, start.first, start.second, n, m, j) << '\n';
    return 0;
}