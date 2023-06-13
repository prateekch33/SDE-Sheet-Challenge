#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   unordered_map<int,int> mp;
   for(int i=0;i<n;i++) {
      mp[arr[i]]++;
   }
   int j=0;
   for(int i=0;i<=2;i++) {
      for(int k=j;k<j+mp[i];k++){
         arr[k]=i;
      }
      j+=mp[i];
   }
}