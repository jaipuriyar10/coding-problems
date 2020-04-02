problem:-https://practice.geeksforgeeks.org/contest-problem/rob-the-houses/1/


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// arr: input array
// num: size of array
int kadane(int arr[],int num)
{
    int sum=0;
    int x=0;
    for(int i=0;i<num;i++)
    {
        sum+=arr[i];
        if(sum<0)
        {
            sum=0;
        }
        if(x<sum)
        {
            x=sum;
        }
    }
    return x;
}
int  maxMoney(int arr[], int num)
{
    int sum=0;
    int k=kadane(arr,num);
    for(int i=0;i<num;i++)
    {
        sum+=arr[i];
        arr[i]=(-arr[i]);
    }
    sum+=kadane(arr,num);
    return max(sum,k);
    
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	    
	    
	    cout << maxMoney(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
