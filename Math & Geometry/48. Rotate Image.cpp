class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int L = 0, R = matrix.size()-1;

        // Algo 1:

        // Take the top left in temp variable
        // Move all the elements in clockwise direction starting from bottom left
        // Even though we have n X n matrix in one go we are doing n-1 rotations 
        
        // Time Complexity Analysis:
        // O(N^2) where N is the number of elements in matrix

        // Space Complexity Analysis
        // O(1) = constant space

        while(L < R)
        {
            for(int i = 0 ; i < R-L ; i++)
            {
                int Top = L;
                int Bottom = R;

                // Get the top left element in temp variable
                int TopLeft = matrix[Top][L+i];

                // Move bottom left to the Top Left
                matrix[Top][L+i] = matrix[Bottom-i][L];

                //move bottom right to the bottom Left
                matrix[Bottom-i][L] = matrix[Bottom][R-i];

                //move top right to the bottom right
                matrix[Bottom][R-i] = matrix[Top+i][R];

                //move top Left to the 
                matrix[Top+i][R] = TopLeft;
            }
            // Inc L
            L++;
            // Dec R
            R--;
            // Make the rotation of matrix shrink

        }
        
    }
};