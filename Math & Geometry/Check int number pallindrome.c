int main()
{
    //int OrgNum = 123;
    int OrgNum = 1221;
    int TempNum = OrgNum;
    
    int reverseNum = 0;
    
    while(OrgNum)
    {
        reverseNum +=  (OrgNum%10);
        OrgNum/=10;
        if (OrgNum == 0) break;
        
        reverseNum *=10;
    }
    
    if(TempNum == reverseNum)
    {
        printf("\n Palidrome");
    }
    else 
    {
        printf("\n Not Palidrome");
    }
    
    return 0;
}