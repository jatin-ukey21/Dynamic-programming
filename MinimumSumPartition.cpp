/*
Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 
such that the absolute difference between their sums is minimum and find the minimum difference.

Input: arr[] = [1, 6, 11, 5]
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
Hence, minimum difference is 1. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

  public:
    int minDifference(vector<int>& arr) {
       
        
        int n = arr.size();
      
        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += arr[i];

        vector<bool> prev(totalSum + 1, false);

        prev[0] = true;

        if (arr[0] <= totalSum) {
            prev[arr[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            vector<bool> curr(totalSum + 1, false);
            curr[0] = true;

            for (int target = 1; target <= totalSum; target++) {
                bool notTake = prev[target];

                bool take = false;
                if (arr[i] <= target) {
                    take = prev[target - arr[i]];
                }

                curr[target] = take || notTake;
            }

            prev = curr;
        }

        int mini = 1e9;
        for (int i = 0; i <= totalSum; i++) {
            if (prev[i] == true) {
                // Calculate the absolute difference between two subset sums
                int diff = abs(i - (totalSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 6, 11, 5};

    int result = sol.minDifference(arr);
    cout << "The minimum difference between two subsets is: " << result << endl;

    return 0;
}