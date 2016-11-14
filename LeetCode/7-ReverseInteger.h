#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	int reverse(int x) {
		long long t = x;
		bool f = false;
		queue<long long> guo;

		if (t<0) {
			t *= -1;
			f = true;
		}

		while (t != 0) {
			guo.push(t % 10);
			t = t / 10;
		}

		while (!guo.empty()) {
			t += guo.front();
			guo.pop();
			if (!guo.empty())
				t *= 10;
		}

		if (f)
			t *= -1;

		long long test = t;
		if (test > 0x7fffffff || test < -0x7fffffff) {
			return 0;
		}

		return (int)t;
	}
};