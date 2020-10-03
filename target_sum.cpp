/*
    I have used Dynamic Programming to solve this problem.
    dp[i][j] is the number of ways we can obtain sum equal to S if we are currently at the i'th index and our current sum is j.
    we have two options at each index, either add the current element or subtract it.
    The final ans is stored in dp[0][offset+0].
*/

class Solution {
public:
    
    int dp[20][2001],offset = 1000;
    
    int calculate(vector<int> &a,int ind,int sum,int S){
        if(ind == a.size()){
            return (sum == S);
        }
        if(dp[ind][offset+sum]!=-1){
            return dp[ind][offset+sum];
        }
        int &ans = dp[ind][offset+sum];
        ans = 0;
        ans += calculate(a,ind+1,sum+a[ind],S);
        ans += calculate(a,ind+1,sum-a[ind],S);
        return ans;
    }
    
    int findTargetSumWays(vector<int>& a, int S) {
        memset(dp,-1,sizeof(dp));
        return calculate(a,0,0,S);
    }
};