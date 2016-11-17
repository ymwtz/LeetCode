#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool>> f(p.size() + 1, vector<bool>(s.size() + 1, false));

		f[0][0] = true;

		for (int i = 0;i < p.size() + 1;++i) {
			for (int j = 0;j < s.size() + 1;++j) {

			}
		}

		return false;
	}
};