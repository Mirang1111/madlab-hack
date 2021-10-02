#include<bits/stdc++.h>
using namespace std;
int dp[100][100];  // memoization
int k(int wt[] , int val[] , int W , int n)
{
	if(W==0||n==0) // if W==0 , no capacity to store items is there , therefore the profit is zero
	{              // if n==0 , no items are there , therefore the profit is zero
		return 0;
	}
	if(dp[n][W]!=-1)
	{
		return dp[n][W];
	}
	if(wt[n-1]<=W)
	{
		int item_taken = val[n-1] + k(wt,val,W-wt[n-1],n-1);
		int not_taken = k(wt,val,W,n-1);
		int c = max(item_taken , not_taken); 
		dp[n][W] = c;
		return c;	
	}
	else if(wt[n-1]>W)
	{
		int no = k(wt,val,W,n-1);
		dp[n][W] = no;
		return no;
	}
}
int main()
{
	int n;
	cin>>n;
	int wt[n];
	for(int i = 0 ;i<n;i++)
	{
		cin>>wt[i];
	}
	int val[n];
	for(int i = 0 ; i<n;i++)
	{
		cin>>val[i];
	}
	int W;
	cin>>W;
	memset(dp,-1,sizeof(dp));
	int c = k(wt,val,W,n);
	cout<<"The maximum profit obtained in the 0/1 knapsack problem is "<<c;
	return 0;
}
