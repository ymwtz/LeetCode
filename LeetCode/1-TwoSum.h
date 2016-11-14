#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i, j;
		vector<int> ans;
		bool done = false;
		for (i = 0;i<nums.size() - 1;i++)
		{
			for (j = i + 1;j<nums.size();j++)
			{
				if (nums[i] + nums[j] == target)
				{
					done = true;
					break;
				}
			}
			if (done)
			{
				break;
			}
		}
		ans.push_back(i);
		ans.push_back(j);
		return ans;
	}
};