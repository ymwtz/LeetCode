#pragma once

#include"stdafx.h"

using namespace std;

//参考题解

class Solution {
public: bool isMatch(const string& s, const string& p) {
	return isMatch(s.c_str(), p.c_str());
}
private:
	bool isMatch(const char *s, const char *p) {
		//若p匹配完成而s有剩余则匹配不成功
		if (*p == '\0')
			return *s == '\0';
		// 下一个字符不是*，只要判断是否一致即可
		if (*(p + 1) != '*') {
			if (*p == *s || (*p == '.' && *s != '\0'))
				return isMatch(s + 1, p + 1);
			else
				return false;
		}
		else {
			// 下一个字符是*，若p[i]==s[j]，有两种选择，与*号前的匹配或与*号后的匹配
			while (*p == *s || (*p == '.' && *s != '\0')) {
				if (isMatch(s, p + 2))
					return true; 
				s++;
			}
			return isMatch(s, p + 2);
		}
	}
};