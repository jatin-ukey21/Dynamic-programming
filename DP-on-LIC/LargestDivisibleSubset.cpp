#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Longest increasing subsequence concept will be used,
    // because of divisibility, question will be changed to Longest Divisible
    // Subsequence (LDS) make sure to sort the array before going to LDS,
    // because for any element nums[i], we want to ensure that all smaller
    // elements that can divide it come before it. Sorting helps us maintain the
    // required order for divisibility checks.
    //
    // Example to prove this:
    // Input: nums = [3, 5, 10, 20]
    // Without sorting, we might miss a valid chain like [5, 10, 20]
    // If we don't sort, we might look at 10 before 5, and not find that 10 % 5
    // == 0 After sorting: [3, 5, 10, 20] → 5 % 3 ❌, 10 % 5 ✅, 20 % 10 ✅ So
    // we can build the chain: [5, 10, 20] Hence, sorting ensures that when we
    // check divisibility, all valid smaller factors are already processed.

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //LONGEST DIVISIBLE SUBSEQUENCE
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n,1);
        
        sort(nums.begin(), nums.end());   //CRUCIAL LINE, MUST ADD THIS BEFORE MOVING TO LDS
        
        //int maxi = 1;
        for(int ind = 0; ind  < n; ind++){
             hash[ind] = ind;
            //ind - 1 -> we have to check elements before nums[ind]
            for(int prev_ind = 0; prev_ind <= ind - 1; prev_ind++){
                if(nums[ind] % nums[prev_ind]==0 && dp[ind] < dp[prev_ind] + 1){
                    dp[ind] = dp[prev_ind] + 1;
                    hash[ind] = prev_ind;
                }
            }
        }
        
        int lastindx = 0;
        int maxi = -1;
        for(int i = 0; i < n; i++){
            if(dp[i] > maxi){
                maxi = dp[i];
                lastindx = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[lastindx]);
        // till not reach the initialization value
        while(hash[lastindx] != lastindx){
            lastindx = hash[lastindx];
            temp.push_back(nums[lastindx]);
        }
        
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 5, 10, 20};
    // Example Dry Run:
    // Input: nums = {3, 5, 10, 20}     
    // After sorting: nums = {3, 5, 10, 20}
    // dp = [1, 2, 3, 4] (LDS lengths)
    // hash = [0, 0, 1, 2] (to reconstruct the subset)
    // Largest Divisible Subset: [5, 10, 20]
    // Expected Output: [5, 10, 20]
    // Explanation: 5 % 3 != 0, but 10 % 5 == 0 and 20 % 10 == 0,
    // so we can form the subset [5, 10, 20].
    // Note: The output may vary based on the input, but it will always be a valid
    // largest divisible subset.
    // Example: For input [1, 2, 3], the output could be [1, 2] or [1, 3] or [2, 3].

    vector<int> result = sol.largestDivisibleSubset(nums);
    
    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 5 10 20

    return 0;
}