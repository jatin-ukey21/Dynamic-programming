#include<bits/stdc++.h>
using namespace std;

/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without
 changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, 
word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.
*/

class Solution {
public:
    //this function will check if there is difference of at max 1 is between two strings or not, if it's true,s2 is predecessor of s1
    bool compare(string &s1,string &s2){
        if(s1.size() != s2.size() + 1) return false;

        int first = 0, second = 0;
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first++; second++;
            }
            else{
                first++;
            }
        }

        // If both pointers reach the end, s2 is a predecessor of s1
        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
    static bool comp(string s1,string s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);  //IMP step

        int n = words.size();
        vector<int> dp(n,1);
        int maxi = -1;
        for(int i = 0;i < n; i++){
            for(int prev = 0;prev <= i - 1; prev++){
                if(compare(words[i],words[prev]) && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                }
            }
            maxi = max(maxi,dp[i]);
        }

        // The variable 'maxi' now contains the length of the longest possible word chain.
        // We return 'maxi' as the answer.
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << sol.longestStrChain(words) << endl;  // Output: 5
    return 0;
}