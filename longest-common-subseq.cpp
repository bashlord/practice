#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
int max(int a, int b)
{   return (a > b)? a : b; }
//from http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
int lcs( char *X, char *Y, int m, int n )// O(mn) time complexity
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}
  
int main() {
    string a;
    string b;
    
    cin >> a;
    cin >> b;
    
    int a1 = a.length();
    int b1 = b.length();
    char aa[a1];
    char bb[b1];
    strcpy (aa, a.c_str());
    strcpy (bb, b.c_str());

    
    int max1 = 0;
    int arr[a1+1][b1+1];

    
    printf("%d\n", lcs(aa,bb,a1,b1));
    
    
    return 0;
}



/* //time complexity of O(2^n), way worse
int lcs( char *X, char *Y, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs(X, Y, m-1, n-1);
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
*/
