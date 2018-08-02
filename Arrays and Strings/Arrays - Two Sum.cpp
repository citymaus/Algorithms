/*
https://leetcode.com/problems/two-sum/description/
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.
	You may assume that each input would have exactly one solution, and you may not use the same element twice.

	Example:
	Given nums = [2, 7, 11, 15], target = 9,
	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].

*/
#include "Arrays_and_Strings.h"

class Solution {
public:
	/*
		Time complexity : O(n^2). 
			For each element, we try to find its complement by looping through the rest of array which takes O(n) time. 
			Therefore, the time complexity is O(n^2).

		Space complexity : O(1). 
	*/
	vector<int> twoSum_bruteForce(vector<int>& nums, int target) {
		int max = nums.size();
		vector<int> solution;
		for (int i = nums.size() - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (nums[i] + nums[j] == target) {
					solution.push_back(j);
					solution.push_back(i);
					break;
				}
			}
		}
		//cout << "i:" << solution[0] << "j:" << solution[1] << endl;
		return solution;
	}


	/*
		Time complexity : O(n). 
			We traverse the list containing nn elements exactly twice. 
			Since the hash table reduces the look up time to O(1), the time complexity is O(n).

		Space complexity : O(n). 
			The extra space required depends on the number of items stored in the hash table, 
			which stores exactly n elements. 
	*/
	vector<int> twoSum_hash(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		vector<int> solution;
		for (int i = 0; i < nums.size(); i++) {
			map.insert(nums[i], i);
		}
		for (int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if (map.find(complement) != map.end() && map.find(complement)->second != i) {
				solution.push_back(i);
				solution.push_back(map.find(complement)->second);
			}
		}
		return solution;
	}
};