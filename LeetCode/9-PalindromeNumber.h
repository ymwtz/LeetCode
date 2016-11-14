#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0) {
			return false;
		}

		int n = 1;
		int t = x;

		while (t / 10 != 0) {
			t /= 10;
			n *= 10;
		}

		while (n>1) {
			if (x % 10 == x / n) {
				x -= n*(x / n);
				n /= 100;
				x /= 10;
			}
			else {
				return false;
			}
		}

		return true;
	}
};