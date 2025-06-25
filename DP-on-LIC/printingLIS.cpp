#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);     // dp[i] = length of LIS ending at index i
        vector<int> hash(n);      // hash[i] = index of previous element in LIS ending at i

        // Loop to build dp and hash arrays
        for (int ind = 0; ind < n; ind++) {
            hash[ind] = ind;  // Default: assume current element starts a new sequence

            // Check all elements before current to find increasing subsequences
            for (int prev_ind = 0; prev_ind < ind; prev_ind++) {
                // If nums[ind] can extend an increasing subsequence ending at prev_ind
                // and if doing so gives a longer subsequence than current dp[ind]
                if (nums[prev_ind] < nums[ind] && dp[ind] < dp[prev_ind] + 1) {
                    dp[ind] = dp[prev_ind] + 1;      // update dp to longer length
                    hash[ind] = prev_ind;            // update hash to remember the chain
                }
            }
        }

        // Find the index of the last element of the overall LIS
        int lastIndex = -1;
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxi) {
                maxi = dp[i];         // store length of LIS
                lastIndex = i;        // store last index of LIS
            }
        }

        // Reconstruct LIS using the hash array
        vector<int> lis;
        lis.push_back(nums[lastIndex]);  // start from the last element of LIS

        // Backtrack using hash array until we reach the start of the sequence
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];   // move to previous index in the LIS chain
            lis.push_back(nums[lastIndex]);
        }

        reverse(lis.begin(), lis.end());   // reverse to get LIS in correct order
        return lis;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    /*
Dry Run for nums = {10, 9, 2, 5, 3, 7, 101, 18}

Step 1: Initialization
n = 8
dp   = [1, 1, 1, 1, 1, 1, 1, 1]
hash = [0, 1, 2, 3, 4, 5, 6, 7]

Step 2: Building dp and hash arrays
We iterate from ind = 0 to n-1
For each ind, we check all prev_ind from 0 to ind-1
If nums[prev_ind] < nums[ind] and dp[ind] < dp[prev_ind] + 1,
we update dp[ind] = dp[prev_ind] + 1 and hash[ind] = prev_ind

After all iterations:
dp   = [1, 1, 1, 2, 2, 3, 4, 4]
hash = [0, 1, 2, 2, 2, 3, 5, 5]

Step 3: Finding the index of LIS
We search for the maximum value in dp[] and get its index

maxi = 4
lastIndex = 6 (nums[6] = 101)

Step 4: Reconstructing the LIS using the hash array
Start from lastIndex = 6
Add nums[6] = 101 to result
hash[6] = 5 → add nums[5] = 7
hash[5] = 3 → add nums[3] = 5
hash[3] = 2 → add nums[2] = 2
hash[2] = 2 → stop (hash[i] == i is the initialization condition)

The sequence collected (in reverse) = [101, 7, 5, 2]
Reverse it to get LIS = [2, 5, 7, 101]

Final LIS: 2 5 7 101
*/


    vector<int> lis = sol.getLIS(nums);
    
    cout << "Longest Increasing Subsequence: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;  // Output: Longest Increasing Subsequence: 2 5 7 101

    return 0;
}