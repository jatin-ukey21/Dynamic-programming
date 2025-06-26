#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& nums, int n)
{
		//Step 1 -- start from the beginning(longest increasing subsequence(LIS))
        vector<int> dp1(n, 1);

        for(int ind = 0; ind  < n; ind++){
            //ind - 1 -> we have to check elements before nums[ind]
            for(int prev_ind = 0; prev_ind <= ind - 1; prev_ind++){
                if(nums[prev_ind] < nums[ind] && dp1[prev_ind] + 1 > dp1[ind]){
                    dp1[ind] = dp1[prev_ind] + 1;
                }
            }
        }

		//Step 2 -- start from the ending (longest decreasing subsequence(LDS))
        //actually LDS is reverse of LIS
        vector<int> dp2(n, 1);

        for(int ind = n-1; ind  >= 0; ind--){
            //ind - 1 -> we have to check elements before nums[ind]
            for(int prev_ind = n - 1; prev_ind > ind; prev_ind--){
                if(nums[prev_ind] < nums[ind] && dp2[prev_ind] + 1 > dp2[ind]){
                    dp2[ind] = dp2[prev_ind] + 1;
                }
            }
        }

		//step 3: bitonic = dp1[i] + dp2[i] - 1, 
		//'-1'// Subtract 1 because nums[i] is counted twice in both dp1 and dp2

		int maxi = -1;
		for(int i = 0; i < n; i++){
			maxi = max(maxi,dp1[i] + dp2[i] - 1);
		}

		return maxi;
}

int main() {
    vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = nums.size();
    cout << "Length of Longest Bitonic Subsequence: " << longestBitonicSubsequence(nums, n) << endl;
    // Output: Length of Longest Bitonic Subsequence: 6
    // Explanation: The longest bitonic subsequence is [1, 2, 10, 4, 2, 1] or [1, 11, 10, 4, 2, 1], both of length 6.
    
    return 0;
}
