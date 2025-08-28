class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
    
            // Algo:
            // 1. Maintain set <char> rowUni for set which belongs to row (Think: can we maintain Bitwiseflag for 1to 9)
            // 2. Maintain set <char> colUni for set which belongs to Coln
            // 3. squares[i][j] is one set which would check duplicacy of 3 x 3 sub-boxes 
            // 4. Check the duplicacy using above 3 forms of set
    
            vector<vector<set <char>>> squares(3, vector<set<char>>(3));
    
            vector<set<char> > Grids(9);
            
            //Traverse the whole board
            for(int i = 0 ; i < board.size() ; i++)
            {
                set <char> rowUni;
                set <char> colUni;
    
                for(int j = 0 ; j < board[i].size() ; j++)
                {
                    //uniquness among rows
                    if(board[i][j] != '.')
                    {
                        if(rowUni.count(board[i][j]))
                            return false;
                        rowUni.insert(board[i][j]);
                    }
                    //uniquness among coln
                    if(board[j][i] != '.')
                    {
                        if(colUni.count(board[j][i]))
                            return false;
                        colUni.insert(board[j][i]);
                    }
    
                    int squareRow = i/3;
                    int squareCol = j/3;
                    int GridLoc = ((i/3)*3) +(j/3);
    
                    //Check uniqueness among 9 squares which is the third condition in the question
                    if(board[i][j] != '.')
                    {
                        if(squares[squareRow][squareCol].count(board[i][j]))
                            return false;
                        
                        squares[squareRow][squareCol].insert(board[i][j]);
                    }
                    // if(board[i][j] != '.')
                    // {
                    //     if(Grids[GridLoc].count(board[i][j]))
                    //         return false;
    
                    //     Grids[GridLoc].insert(board[i][j]);    
                    // }
    
    
                }
            }
            return true;
        }
    };