#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i, j = -1;
		for (i = 0;i<numbers.size() - 1;++i) {
			j = query(numbers, i + 1, target - numbers[i]);
			if (j != -1) {
				break;
			}
		}
		vector<int> ans;
		ans.push_back(i + 1);
		ans.push_back(j + 1);
		return ans;
	}

	int query(vector<int>& numbers, int startpos, int target) {
		int l, r, k;
		l = startpos;
		r = numbers.size() - 1;
		k = (l + r) / 2;
		while (numbers[k] != target)
		{
			if (numbers[k]<target) {
				l = k + 1;
			}
			else {
				r = k - 1;
			}
			if (l>r) {
				break;
			}
			k = (l + r) / 2;
		}
		if (numbers[k] == target) {
			return k;
		}
		else {
			return -1;
		}
	}
};