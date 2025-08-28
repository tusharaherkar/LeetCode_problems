/**
 * @input A : Integer
 * 
 * @Output Integer
 */
// Que: Reverse the bits of an 32 bit unsigned integer A.
unsigned int reverse(unsigned int A) {
    
    // Corner Case 1:
    if(!A)
        return A;
    
    unsigned int reversed = 0, itr;
    for(itr = 0; itr < 32 ; itr++)
    {
       reversed |= (A>>itr&01)<<(31-itr);
    }
    return reversed;
}
