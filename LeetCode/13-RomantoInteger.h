#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		vector<int> n;
		for (size_t i = 0;i < s.size();++i) {
			switch (s[i])
			{
			case 'I':n.push_back(1);break;
			case 'V':n.push_back(5);break;
			case 'X':n.push_back(10);break;
			case 'L':n.push_back(50);break;
			case 'C':n.push_back(100);break;
			case 'D':n.push_back(500);break;
			case 'M':n.push_back(1000);break;
			default:
				break;
			}
		}

		int ans = n[n.size() - 1];

		for (int i = n.size() - 2;i >= 0;i--) {
			if (n[i] < n[i + 1]) {
				ans -= n[i];
			}
			else {
				ans += n[i];
			}
		}

		return ans;
	}
};
