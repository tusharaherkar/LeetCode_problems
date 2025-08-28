class DetectSquares {

    // point X Y co-ordinates to be stored in the form of long key
    // the freq of of the co-ordinates will be stored in the form of int key
    unordered_map < long, int> mp;

    // SetPoints is for dumping the given points in vector
    vector < vector<int> > SetPoints;
    // Think: Can we use map itself for doing this check?

public:
    long formKey(int X, int Y)
    {
        return ((static_cast <long>(X) << 32 )|  static_cast<long>(Y));
    }

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[formKey(point[0], point[1])]++;    
        SetPoints.push_back(point);

    }
    
    int count(vector<int> point) {
        
        int allPossibleSquares = 0;
        
        //check if the points in SetPoints are diagonal of square
        //  |
        //  |
        //  |
        //  |       Qty1         count(2, 2)
        //  |      (1, 2)       (2, 2)
        //  |
        //  |       Qty2         Qty1
        //  |      (1, 1)       (2, 1)
        //  --------------------------------------------
        //  |
        //  |
        // Here (1, 1) & (2, 2) are in diagonal of each other

        // SetPoints is vector of vector so (1, 1) will appear twice and it will be detected as diagonal point)

        for(auto &it: SetPoints)
        {
            int X = it[0], Y = it[1];
            // Diagonal of sqaure is present if difference between X and Y coordinates of given point and SetPoints
            // are equal and the points are not same then only diagonals present
            if(abs(point[0] - X) == abs(point[1] - Y) && (point[0] != X) && (point[1] != Y))
            {
                // Once diagonal is present check whether other points of square exists
                // and It is added to the allPossibleSquares
                allPossibleSquares += mp[formKey(X, point[1])] *  mp[formKey(point[0], Y)];
            }   
        }
        return allPossibleSquares;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */