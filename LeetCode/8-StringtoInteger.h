#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long long ans = 0;
		bool f = true, s = false;
		int l = 0;
		for (int i = 0;i<str.size();i++) {
			if (str[i] >= '0'&&str[i] <= '9') {
				ans += str[i] - '0';
				s = true;
				l++;
			}
			else if (!s) {
				if (str[i] == '-') {
					f = false;
					s = true;
					l++;
				}
				else if (str[i] == '+') {
					f = true;
					s = true;
					l++;
				}
				else if (str[i] == ' ') {
					continue;
				}
				else {
					ans /= 10;
					break;
				}
			}
			else {
				ans /= 10;
				break;
			}

			if (i<str.size() - 1) {
				ans *= 10;
			}

			if (l>11) {
				break;
			}
		}

		ans *= f ? 1 : -1;

		if (ans>0x7fffffff || ans<-0x7fffffff - 1) {
			ans = f ? 0x7fffffff : -0x7fffffff - 1;
		}

		return (int)ans;
	}
};