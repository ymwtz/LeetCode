#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ans;

		int k = 0, len = 0;
		for (size_t i = 0;i < strs.size();i++) {
			if(strs[i].size()>len){
				len = strs[i].size();
				k = i;
			}
		}

		for (int j = 0;j < len;j++) {
			char c = strs[k][j];
			bool f = true;
			for(int i=0;i<strs.size();i++){
				if (strs[i][j] != c) {
					f = false;
					break;
				}
			}

			if (f) {
				ans.push_back(c);
			}
			else {
				break;
			}
		}

		return ans;
	}
};