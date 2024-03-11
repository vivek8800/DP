/*
Dynamic Programming: 
    
   --> Learn from past means if you have already calculated any problem then not needed to calculate it again.
            |--->Store it in vector or map and use whenever required.
       
    Three Approach is possible in dynamic Programming:- 
        
        ---> Top-Down Approach :- Recursion + Memoisation
        ---> Bottom Up Approach :- Tabulation Method (Iterative approach)
        ---> Space Optimization :- Optimizing above two approach
        
        
    When to apply DP??
    
        ---> Overlapping Sub-Problems :- solving same problem again and again.
        ---> Optimal Sub-Structure :- When optimal solution of bigger problem can be calculated using optimal solution of smaller problem.
        
        Example: Fibonacci:--  0, 1, 1, 2, 3, 5, 8...
        
        Approach: f(n)= f(n-1) + f(n-2)
        
        Solution:
                                Dry Run of Fibnoicci Problem

                                            f(5)
                                            / \
                                           /   \
                                        f(4)  f(3)
                                        /  \    \
                                       /    \    \__________________
                                    f(3)   f(2)                   / \
                                    /  \     \                   /   \
                                   /    \     \______          f(2)  f(1)
                                 f(2)  f(1)       / \           / \    \
                                 / \     \       /   \         /   \   BC
                                /   \    BC    f(1) f(0)     f(1)  f(0)
                             f(1)  f(0)         /     \       /     \
                             /       \         BC     BC     BC     BC
                          BC         BC
        
        ---> in the above diagram f(2) and f(3) is overlapping Sub-Problems so we can apply DP here
        ---> f(0) and f(1) are not overlapping Sub-Problems because they are base case.
        
    Memoisation: To store ans of Sub-Problems
        
    Steps for Memoisation:

            1---> create DP array
                vector<int> dp(n+1, -1) ---> size of dp vector is n+1 and vector is filled with -1.
                
            2---> Store the sub problem ans in dp vector or replace ans integer with dp[n].
            
            3---> Write a condition just after base case
                check if answer is already exist
                
                                        5 = f(5)
                                            / \
                                           /   \
                                    3 = f(4)  f(3)
                                        /  \    \________
                                       /    \           \
                                2 = f(3)   f(2)     Already calculated = 2 so return this value without calculating.
                                    /  \     \________                  
                                   /    \            \  
                            1 = f(2)  f(1) = 1     Already calculated = 1 so return this value without calculating.
                                 / \     \           
                               /    \    BC
                              /      \
                        1 = f(1)     f(0) = 0        
                            /         \       
                          BC          BC
                         
*/

//******************* Fibonacci problem Solution without DP *********************//

/*

#include<iostream>
using namespace std;

int fib(int n)
{
    // Base cases
    if(n==0 || n==1)
    {
        return n;
    }
    
    // Recursive call
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    cout<<"Enter the number to get Fibonacci: "<<endl;
    cin>>n;
    
    int ans=fib(n);
    
    cout<<ans<<endl;
    return 0;
}


// Time complexity: O(2^n)
// Space complexity: O(n)

*/

//******************* Top Down Approach(DP) *********************//

/*

#include<iostream>
#include<vector>
using namespace std;

int topDownSolve(int n, vector<int> &dp)
{
    // Base cases
    if(n==0 || n==1)
    {
        return n;
    }
    
    // DP steps 3: check if answer is Already exist or not?
    if(dp[n]!= -1)
    {
        return dp[n];
    }
    
    // DP steps 2: replace ans integer with dp[n] array
    // Recursive call with 1 parameter extra
    dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
    
    return dp[n];
}

int main()
{
    int n;
    cout<<"Enter the number to get Fibonacci: "<<endl;
    cin>>n;
    
    // DP steps 1: Create dp array
    vector<int> dp(n+1, -1);
    
    int ans=topDownSolve(n, dp);
    
    cout<<"Fibonacci of "<<n<<" is: "<<ans<<endl;
    return 0;
}

// Time complexity: O(n)
// Space complexity: O(n)

*/


//******************* Bottom Up Approach (DP) *********************//

/*

#include<iostream>
#include<vector>
using namespace std;

int topDownSolve(int n)
{
    // DP steps 1: create dp array
    vector<int> dp(n+1, -1);
    
    // DP steps 2: observe base case of this problem(solved above)
    // and tr to replicate in iterative way
    
    dp[0]=0;
    
    if(n==0)
    {
        return dp[0];
    }
    
    dp[1]=1;
    
    if(n==1)
    {
        return dp[1];
    }
    
    // DP steps 3: loop should be in reverse of recursion or bottom up approach.
    // In recursion, recursive call goes from n = n to n=2; not 0 because for n = 0, and 1 is base case.
    // so here loop will run from 2 to n.
    // And inside for loop replace recursive call.
    for(int i=2;i<=n;i++)
    {
        dp[i]= dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main()
{
    int n;
    cout<<"Enter the number to get Fibonacci: "<<endl;
    cin>>n;
    
    int ans=topDownSolve(n);
    
    cout<<"Fibonacci of "<<n<<" is: "<<ans<<endl;
    return 0;
}

// Time complexity:  O(n)
// Space complexity: O(n)

*/


//******************* Space Optimization of Fibonacci problem *********************//



#include<iostream>
using namespace std;

int spaceOptmizeSolve(int n)
{
    // take two integer prev1 and prev2 and store initially 0 and 1 as we did in base case
    
    int prev2=0;
    
    int prev1=1;
    
    int curr;
    
    for(int i=2;i<=n;i++)
    {
        curr = prev1 + prev2;
        
        // shifting
        prev2=prev1;
        prev1=curr;
    }
    
    return curr;
}

int main()
{
    int n;
    cout<<"Enter the number to get Fibonacci: "<<endl;
    cin>>n;
    
    int ans=spaceOptmizeSolve(n);
    
    cout<<"Fibonacci of "<<n<<" is: "<<ans<<endl;
    return 0;
}

// Time complexity: O(n)
// Space complexity: O(1)




