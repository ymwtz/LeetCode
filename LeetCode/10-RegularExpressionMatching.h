#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool>> f(p.size(), vector<bool>(s.size(), false));

		if (s[0] == p[0])
			f[0][0] = true;

		for (int i = 1;i < p.size();++i) {
			for (int j = 1;j < s.size();++j) {

			}
		}

		return false;
	}
};