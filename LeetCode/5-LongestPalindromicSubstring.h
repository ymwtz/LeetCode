#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int k = 0;
		int len = 1;
		int n = s.size();
		string ans;

		bool f[1000][1000];

		for (int i = 0;i < n;++i) {
			for (int j = 0;j < n;j++) {
				if (i == j)
					f[i][j] = true;
				else
					f[i][j] = false;
			}
		}

		for (int j = 0;j < n;++j) {
			for (int i = 0;i < j;i++) {
				f[i][j] = (s[i] == s[j] && ((j == i + 1) || (f[i + 1][j - 1])));

				if (f[i][j] && len < j - i + 1) {
					len = j - i + 1;
					k = i;
				}
			}
		}

		return s.substr(k, len);
	}
};