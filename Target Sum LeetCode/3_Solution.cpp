#include<bits/stdc++.h>
using namespace std;

int target(int n, int s, int *a) {
	int sum = 0;
	for(int i = 0; i<n; i++) sum += a[i];
	
	if(sum < s || (s+sum)%2 == 1) return 0;
	
	int w = (s+sum)/2;
	int dp[n+1][sum+1];
	
	// Initialization
	for(int i=0; i<=w; i++) dp[0][i] = 0;
	for(int i=0; i<=n; i++) dp[i][0] = 1;
	
    for(int i=1; i<=n; i++) {
	    for(int j=0; j<=w; j++) {
			if(a[i-1] <= j) dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
		    else dp[i][j] = dp[i-1][j];
	    }
    }
	return dp[n][w];
}

int main() {
	int n, s; cin>>n>>s;
	int a[n+1];
	for(int i = 0; i<n; i++) cin>>a[i];
	
	cout<<target(n, s, a)<<endl;
}
