class Solution {
public:

    bool canConstruct(string ransomNote, string magazine) {

        //Corner Case 1:
        if(ransomNote.length() > magazine.length())
            return false;

        unordered_map <char, int> magazineMap;

        // First build the dictionary from which we can use the ingredients 
        // Iterate over magazine and note the freq of each of the chars of magazine
        for(int i = 0 ; i < magazine.length() ; i++)
        {
            magazineMap[magazine[i]]++;   

        }

        // Iterate over ransomNote 
        for(int i = 0 ; i < ransomNote.length() ; i++)
        {
            // subtract freq of magazineMap by 1 whenever we encounter the ransomNote
            // else
            // return false if ransomNote has char which is not exists in magazineMap or it has exasted the magazineMap limit of chars
            if(magazineMap.find(ransomNote[i]) != magazineMap.end() && magazineMap[ransomNote[i]] > 0)
                magazineMap[ransomNote[i]]--;
            else
                return false;
        }
        //return true if all ransomNote follows all the conditions given in problem statement
        return true;

    }
};