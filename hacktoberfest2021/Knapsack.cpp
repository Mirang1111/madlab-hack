#include<bits/stdc++.h>
using namespace std;
int dp[100][100];  // dp array
int k(int wt[] , int val[] , int W , int n)
{
	for(int i = 0 ; i<n+1;i++)
	{
		for(int j = 0 ; j<W+1;j++)
		{
			if(i==0 || j==0)       // base condition in recursion == initialization in the tabulation method
			{
				dp[i][j] = 0;
			}
			else if(wt[i-1]<=j)   // condition same as recursion , just replace n , W with i , j
			{
				dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]] , dp[i-1][j]);
			}
			else if(wt[i-1] > j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][W];
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
	int c = k(wt,val,W,n);
	cout<<"The maximum profit obtained in the 0/1 knapsack problem is "<<c;
	return 0;
}
