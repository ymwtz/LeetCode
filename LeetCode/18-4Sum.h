#pragma once

#include"stdafx.h"

using namespace std;

//TLE

/*class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if (nums.size() < 4)
			return result;
		sort(nums.begin(), nums.end());

		for (auto i = nums.begin();i < nums.end() - 3;i++) {
			if (i > nums.begin() && *i == *(i - 1))
				continue;

			for (auto j = i + 1;j < nums.end()-2;j++) {
				if (j > i+1 && *j == *(j - 1))
					continue;

				auto k = j+1;
				auto l = nums.end() - 1;
				while (k < l) {
					int sum = *i + *j + *k + *l;
					if (sum < target) {
						k++;
						while (*k == *(k - 1) && k < l) ++k;
					}
					else if (sum > target) {
						l--;
						while (*l == *(l + 1) && k < l)
							l--;
					}
					else {
						result.push_back({ *i, *j, *k, *l });
						++k;
						--l;
						while (*k == *(k - 1) && *l == *(l + 1) && k < l) {
							++k;
							--l;
						}

					}
				}
			}
		}

		return result;
	}
};*/

//题解：
//用hashmap存两数之和
//

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if (nums.size() < 4)
			return result;
		sort(nums.begin(), nums.end());

		unordered_map<int, vector<pair<int, int> > > cache;
		for (size_t a = 0; a < nums.size(); ++a) {
			for (size_t b = a + 1; b < nums.size(); ++b) {
				cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
			}
		}

		for (int c = 0; c < nums.size(); ++c) {
			for (size_t d = c + 1; d < nums.size(); ++d) {
				const int key = target - nums[c] - nums[d];
				if (cache.find(key) == cache.end()) continue;
				const auto& vec = cache[key];
				for (size_t k = 0; k < vec.size(); ++k) {
					if (c <= vec[k].second)
						continue;
					result.push_back({ nums[vec[k].first],
						nums[vec[k].second], nums[c], nums[d] });
				}
			}
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};