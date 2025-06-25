/*
    This code implements an efficient algorithm to find the length of the Longest Increasing Subsequence (LIS) in a given array.
    The approach used here is based on patience sorting and utilizes binary search to achieve O(n log n) time complexity.

    Key Points:
    -----------
    - The function `lengthOfLIS` takes a vector of integers `nums` and returns the length of the LIS.
    - It maintains a temporary vector `temp` which helps in determining the length of the LIS.
      Note: `temp` does NOT store the actual LIS, but its size at the end gives the length of the LIS.

    How Binary Search Helps:
    ------------------------
    - For each element in `nums`, if it is greater than the last element in `temp`, it is appended to `temp`.
    - Otherwise, we use `lower_bound` (which internally uses binary search) to find the first element in `temp` that is not less than the current element.
    - We then replace that element with the current element.
    - This ensures that `temp` always contains the smallest possible tail values for increasing subsequences of different lengths.
    - Using binary search (`lower_bound`) allows us to efficiently find the correct position to replace in O(log n) time for each element, resulting in an overall O(n log n) solution.

    Example Dry Run:
    ----------------
    For input: nums = {10, 9, 2, 5, 3, 7, 101, 18}
    - temp evolves as follows: [10] -> [9] -> [2] -> [2,5] -> [2,3] -> [2,3,7] -> [2,3,7,101] -> [2,3,7,18]
    - The length of LIS is the size of temp, which is 4.

    Note:
    -----
    - The actual LIS may not be the same as the contents of `temp`, but the length will be correct.
    - This method is optimal for finding the length of LIS, but not for reconstructing the actual sequence.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Binary search lower bound approach
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;  //but this temp does not actually store the LIS, it just help to get length of LIS
        temp.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()) { //last element
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin(); //iterator trick used here to get the index
                temp[ind] = nums[i];
            }
        }

        return temp.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Dry run for nums = {10, 9, 2, 5, 3, 7, 101, 18}
    // temp = [10] initially
    // For i = 1: nums[1]=9 < temp.back()=10, so replace temp[0] with nums[1], temp = [9]
    // For i = 2: nums[2]=2 < temp.back()=9, so replace temp[0] with nums[2], temp = [2]
    // For i = 3: nums[3]=5 > temp.back()=2, so append to temp, temp = [2, 5]
    // For i = 4: nums[4]=3 < temp.back()=5, so replace temp[1] with nums[4], temp = [2, 3]
    // For i = 5: nums[5]=7 > temp.back()=3, so append to temp, temp = [2, 3, 7]
    // For i = 6: nums[6]=101 > temp.back()=7, so append to temp, temp = [2, 3, 7, 101]
    // For i = 7: nums[7]=18 < temp.back()=101, so replace temp[3] with nums[7], temp = [2, 3, 7, 18]
    // Final size of LIS is len(temp) = 4
    //but the actual LIS is [2, 3, 7, 101] or [2, 3, 7, 18] depending on how you replace elements
    //Also, the temp array does not store the actual LIS, it just helps to find the length of LIS
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl; // Output: 4 (The LIS is [2, 3, 7, 101])
    return 0;
}