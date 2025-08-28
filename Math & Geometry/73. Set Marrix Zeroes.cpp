class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // Intution:
        // Do book keeping in 0th row and 0th column
        // Rule 1: use first row (i.e. row = 0) for noting the column in which we encountered 0 
        // Rule 2: use first column (i.e. column = 0) for noting the row in which we encountered 0
        // Rule 3: use i = 0 and j = 0 cell whether 0th column encounters any 0
        // Rule 4: use tempvariable named ZerothRow if we encounter any 0 in 0th row
        // while traversing the matrix

        // Time Complexity Analysis:
        // O(M * N) where M is the number of rows and N is the number of columns

        // Space Complexity Analysis 
        // No extra space required as we are doing book keeping inside first row and first column
        // O(1) = constant space 

        bool ZerothRow = false;

        // First Pass:
        // First pass is just to traverse and noting down the 0 encountering as per given scheme in intution

        if(matrix[0][0] == 0 )
        {
            ZerothRow = true;
        }
        
        for(int i = 0 ;i < matrix.size() ; i ++)
        {
            for(int j = 0 ; j < matrix[0].size() ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    // mark jth column as encountered 0 as per rule 1 and rule 3
                    matrix[0][j] = 0;

                    if(i !=0 )
                    {
                        // mark ith row as encountered 0 as per rule 2
                        matrix[i][0] = 0;
                    }
                    else
                    {
                        // mark 0th row as encountered 0 as per rule 4
                        ZerothRow = true;   
                    }   
                }

            }
        }

        // Second Pass:
        // Start traversal from 1,1 as 0th row and 0th column is used for book keeping
        for(int i = 1 ; i < matrix.size() ; i ++)
        {
            for(int j = 1 ; j < matrix[0].size() ; j++)
            {                
                // Unfold Rule 1 
                if(matrix[0][j] == 0)
                    matrix[i][j] = 0;

                // Unfold Rule 2
                if(matrix[i][0] == 0)
                    matrix[i][j] = 0;

                
            }
        }
        // Now only traverse for 0th row and 0th column
        for(int i = 0 ; i < 1 ; i ++)
        {
            for(int j = 0 ; j < matrix.size() ; j++)
            {
                // Unfold Rule 3 first then only unfold Rule 4 as Rule 4 unfolding may affect unfold of rule 3
                if(matrix[0][0] == 0)
                    matrix[j][i] = 0;
            }
        }
           
        for(int i = 0 ; i < 1 ; i ++)
        {
            for(int j = 0 ; j < matrix[0].size() ; j++)
            {
                // Unfold Rule 4
                if(ZerothRow)
                    matrix[i][j] = 0;
                
            }
        }

             



        
    }
};