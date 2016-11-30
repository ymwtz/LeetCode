#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ans;

		if (digits.size() == 0) {
			return ans;
		}

		string t = "";
		combine(0, digits, t, ans);

		return ans;
	}

	void combine(int i, const string digits, string &s, vector<string> &ans) {
		if (i == digits.size()) {
			ans.push_back(s);
			return;
		}

		vector<string> phone = {
			{ ' ' },
			{ ',' },
			{ 'a','b','c' },
			{ 'd','e','f' },
			{ 'g','h','i' },
			{ 'j','k','l' },
			{ 'm','n','o' },
			{ 'p','q','r','s' },
			{ 't','u','v' },
			{ 'w','x','y','z' }
		};

		int k = digits[i] - '0';
		for (size_t j = 0;j < phone[k].size();j++) {
			s.push_back(phone[k][j]);
			combine(i + 1, digits, s, ans);
			s.pop_back();
		}
	}
};