#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> t;

		for (auto i = 0;i < s.size();i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				t.push(s[i]);
			}
			else if (!t.empty()&&(t.top() == s[i] - 1 || t.top() == s[i] - 2)) {
				t.pop();
			}
			else
				return false;
		}
		
		if (t.empty()) {
			return true;
		}
		else
			return false;
	}
};