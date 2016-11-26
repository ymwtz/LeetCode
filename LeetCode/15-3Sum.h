#pragma once

#include"stdafx.h"

using namespace std;

//�ο����

class Solution {
public: 
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() < 3)
			return result;
		sort(nums.begin(), nums.end());
		const int target = 0;
		auto last = nums.end();
		for (auto i = nums.begin(); i < last - 2; ++i) {
			auto j = i + 1; 

			//��ֹ�ظ�
			if (i > nums.begin() && *i == *(i - 1))
				continue;

			auto k = last - 1;

			while (j < k) {

				if (*i + *j + *k < target) {
					++j; 
					//�����ظ�
					while (*j == *(j - 1) && j < k) ++j;
				}
				else if (*i + *j + *k > target) {
					--k;
					//�����ظ�
					while (*k == *(k + 1) && j < k) 
						--k;
				}
				else {
					result.push_back({ *i, *j, *k });
					++j;
					--k;
					while (*j == *(j - 1) && *k == *(k + 1) && j < k)
						++j;
				}
			}
		} 

		return result;
	}
};