#include<bits/stdc++.h>
using namespace std;
/*
ou are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/
class Solution {
public:
    int noOfWays = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        calculateWays(nums,0,0,target);
        return noOfWays;
    }
private:
    void calculateWays(vector<int>& nums,int index,int currSum,int target){
        if(index == nums.size()){
            if(currSum == target) noOfWays++;
            return;
        }

        //include 
        calculateWays(nums,index+1,currSum + nums[index],target);

        //exclude
        calculateWays(nums,index+1,currSum - nums[index],target);
    }
};
//simple recursive solution with backtracking
// Time Complexity: O(2^n) where n is the number of elements in nums
int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution sol;
    cout << sol.findTargetSumWays(nums, target) << endl; // Output: 5
    return 0;
}