int divide(int dividend, int divisor) {

     // Handle overflow case
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        
    long long dividendlong = dividend;
    long long divisorlong  = divisor;
    

    uint8_t negativeSign = (dividend < 0) ^ (divisor < 0);

    //printf("\n negativeSign: %d", negativeSign);


    dividendlong = llabs(dividendlong);
    divisorlong = llabs(divisorlong);


    
    
    long long quotient = 0;
    long long prevResult = 0; 
    long long currComputation = 0;

    while(dividendlong >= divisorlong)
    {
        long long shift = 0;

        while(dividendlong >= (divisorlong<<(shift+1)))
            shift++;
        
        quotient += (1<<shift);
        dividendlong -= (divisorlong<<shift);
    }

    return (negativeSign == 1 ? (-1 * quotient) : quotient);
}