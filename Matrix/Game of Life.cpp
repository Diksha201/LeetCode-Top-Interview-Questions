class Solution {
public:
   void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
       
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                              {0, -1},          {0, 1},
                                              {1, -1}, {1, 0}, {1, 1}};
        
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                
              
                for (auto dir : directions) {
                    int x = i + dir.first, y = j + dir.second;
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (abs(board[x][y]) == 1) { 
                            liveNeighbors++;
                        }
                    }
                }
                
                
                if (board[i][j] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = -1; // Alive -> Dead
                    }
                } else {
                    if (liveNeighbors == 3) {
                        board[i][j] = 2; // Dead -> Alive
                    }
                }
            }
        }
        
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 0) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};