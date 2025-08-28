class Solution {
    public:
        bool searchMatrixOptimized(vector<vector<int>>& matrix, int target) {
            int rows = matrix.size();
            int cols = matrix[0].size();

            //Corner case 1:
            if(target < matrix[0][0] || target > matrix[rows-1][cols-1])
                return false;

            // Short Algo (Optimized):
            // First deciding row where target resides will take O(logM)
            // Once row is decided, searching of element inside row will take O(logN)
            // So total time complexity O(logM + logN)

            //Initialize top and bottom
            int top = 0;
            int bottom = rows-1;
            int midRow = 0;

            while(top <= bottom)
            {
                midRow = (top + bottom)/2;

                if(matrix[midRow][0] <= target && target <= matrix[midRow][cols-1])
                {
                    break;
                }
                // shift searching job to the upper side of midRow
                else if(target < matrix[midRow][0])
                {
                    bottom = midRow-1;
                }
                // shift searching job to the lower side of midRow
                else if(target > matrix[midRow][cols-1])
                {
                    top = midRow+1;
                }
            }

            // Now apply binary search in found out row 
            int L = 0;
            int R = cols-1;
            
            while(L <= R)
            {
                int mid = (L+R)/2;
                if(matrix[midRow][mid] == target)
                {
                    return true;
                }
                else if(matrix[midRow][mid] < target)
                {
                    L = mid+1;
                }
                else
                {
                    R = mid-1;
                }

            }
            return false;
        }
        bool searchMatrix(vector<vector<int>>& matrix, int target) {

            // Short Algo (Optimized):
            // First deciding row where target resides will take O(logM)
            // Once row is decided, searching of element inside row will take O(logN)
            // So total time complexity O(logM + logN)

            return searchMatrixOptimized(matrix, target);
    
            int rows = matrix.size();
            int cols = matrix[0].size();
            int L = 0;
            int R = (rows * cols)-1;
            int SearchRow, SearchCol;
    
            int mid;
    
            while(L <= R)
            {
                mid = (L+R)/2;
    
                SearchRow = mid/cols;
                SearchCol = mid%cols;
    
                if(matrix[SearchRow][SearchCol] == target)
                {
                    return true;
                }
                else if(matrix[SearchRow][SearchCol] < target)
                {
                    L = mid+1;
                }
                else
                {
                    R = mid-1;
                }
            }
            return false;
        }
    };