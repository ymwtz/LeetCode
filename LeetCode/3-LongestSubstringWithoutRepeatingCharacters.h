#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int a[128];
		int k = 0, sum = 0;

		for (int i = 0;i<128;i++) {
			a[i] = -1;
		}

		for (int i = 0;i<s.size();++i) {
			if (a[s[i]] == -1) {
				a[s[i]] = i;
				sum++;
			}

			else {
				i = a[s[i]] + 1;

				for (int j = 0;j <= 128;++j) {
					a[j] = -1;
				}

				if (sum>k) {
					k = sum;
				}

				a[s[i]] = i;
				sum = 1;
			}
		}
		if (sum>k) {
			k = sum;
		}
		return k;
	}
};