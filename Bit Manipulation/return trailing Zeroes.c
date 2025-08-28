/**
 * @input A : Integer
 * 
 * @Output Integer
 */

 // Que: Given an integer A, count and return the number of trailing zeroes.

 // O/p:
 // Return an integer denoting the count of trailing zeroes.

//  Input 1:

//  A = 18
// Input 2:

//  A = 8

// Output 1:

//  1
// Output 2:

//  3

int solve(int A) {
    
    return log2(A & ~(A-1));   
}
