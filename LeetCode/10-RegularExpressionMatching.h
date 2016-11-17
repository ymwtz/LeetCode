#pragma once

#include"stdafx.h"

using namespace std;

//�ο����

class Solution {
public: bool isMatch(const string& s, const string& p) {
	return isMatch(s.c_str(), p.c_str());
}
private:
	bool isMatch(const char *s, const char *p) {
		//��pƥ����ɶ�s��ʣ����ƥ�䲻�ɹ�
		if (*p == '\0')
			return *s == '\0';
		// ��һ���ַ�����*��ֻҪ�ж��Ƿ�һ�¼���
		if (*(p + 1) != '*') {
			if (*p == *s || (*p == '.' && *s != '\0'))
				return isMatch(s + 1, p + 1);
			else
				return false;
		}
		else {
			// ��һ���ַ���*����p[i]==s[j]��������ѡ����*��ǰ��ƥ�����*�ź��ƥ��
			while (*p == *s || (*p == '.' && *s != '\0')) {
				if (isMatch(s, p + 2))
					return true; 
				s++;
			}
			return isMatch(s, p + 2);
		}
	}
};