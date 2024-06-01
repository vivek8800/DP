#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int coinExchangeUsingRecursion(vector<int> coins, int amount)
{
    // base case
    if(amount==0)
    {
        return 0;
    }
    
    if(amount<0)
    {
        return INT_MAX;
    }
    
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        int subAns=coinExchangeUsingRecursion(coins, amount-coins[i]);
        
        if(subAns!=INT_MAX)
        {
            mini=min(mini, subAns+1);
        }
    }
    
    return mini;
}

int main()
{
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    
    int target=7;
    cout<<"Min number of coins required to make target is: "<<coinExchangeUsingRecursion(coins, target)<<endl;
    return 0;
}
