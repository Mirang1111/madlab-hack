#include<bits/stdc++.h>
using namespace std;
bool queensafe(int n , int row  , int col , int arr[][10])
{
    for(int i = row-1 , j = col ; i>=0 ; i--)
    {
        if(arr[i][j]==1)
        {
            return false;
        }
    }
    for(int i = row-1 , j = col -1 ; i>=0 && j>=0 ; i-- , j--)
    {
        if(arr[i][j]==1)
        {
            return false;
        }
    }
    for(int i = row-1 , j = col + 1 ; i>= 0 && j<n ; i-- , j++)
    {
        if(arr[i][j]==1)
        {
            return false;
        }
    }
    return true;
    
}
void solve(int n , int row , int arr[][10])
{
     if(row==n)
        {
            for(int i = 0 ; i<n;i++)
            {
                for(int j = 0 ; j<n ; j++)
                {
                    if(arr[i][j]==1)
                    {
                        cout<<"Q ";
                    }
                    else
                    {
                        cout<<"_ ";
                    }
                }
                cout<<endl;
            }
            cout<<endl;
            return ;
        }
    for(int col = 0 ; col < n; col++)
    {
        if(queensafe(n,row,col,arr)==true)
        {
        arr[row][col] = 1;
        solve(n,row+1,arr);
        arr[row][col] = 0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[10][10];
    solve(n,0,arr);
    
}
