#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result=0;
		int d = 0xfffffff;

		sort(nums.begin(), nums.end());

		for (size_t i = 0;i < nums.size() - 2;i++) {
			size_t j = i + 1;

			size_t k = nums.size() - 1;
			while (j < k) {
				int t = nums[i] + nums[j] + nums[k] - target;
				if (t < 0) {
					if (abs(d) > abs(t)) {
						result = nums[i] + nums[j] + nums[k];
						d = t;
					}
					j++;
					while (nums[j] == nums[j - 1] && j < k) {
						j++;
					}
				}
				else if (t >= 0) {
					if (abs(d) > abs(t)) {
						result = nums[i] + nums[j] + nums[k];
						d = t;
					}
					k--;
					while (nums[k] == nums[k + 1] && j < k) {
						k--;
					}
				}
				else {
					return nums[i] + nums[j] + nums[k];
				}
			}
		}

		return result;
	}
};