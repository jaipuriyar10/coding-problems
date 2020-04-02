problem:-https://practice.geeksforgeeks.org/problems/number-of-minimum-picks-to-get-k-pairs-of-socks-from-a-drawer/1

int find_min(int* a, int n, int k)
{
  int p=0,t=0;
  for(int i=0;i<n;i++)
   {
     p+=a[i]/2;
     if(a[i]%2)
      t+=(a[i]-1)/2;
      else
      t+=(a[i]-2)/2;
   }
  if(k>p) return -1;
  if(k<=t)
    return 2*(k-1)+n+1;
  return 2*t+n+k-t;
}
