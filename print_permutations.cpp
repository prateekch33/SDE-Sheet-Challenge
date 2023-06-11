#include <bits/stdc++.h> 

void palindromes(string &s,int i, vector<string> &ans) {
    if(i==s.size()) {
        ans.push_back(s);
        return;
    }

    for(int j=i;j<s.size();j++) {
        swap(s[j],s[i]);
        palindromes(s,i+1,ans);
        swap(s[j],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    palindromes(s,0,ans);
    return ans;
}