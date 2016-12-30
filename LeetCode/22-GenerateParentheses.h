#pragma once

#include"stdafx.h"

using namespace std;

class Solution {
private:
	//val=0±íÊ¾'('; val=1±íÊ¾')'
	typedef struct node {
		node *lchild, *rchild;
		int val;
		node(int v) :val(v),lchild(NULL),rchild(NULL) {}
	}*lnode;


	void buildtree(lnode f, int count, int remain) {
		if (!count && !remain)
			return;

		int c, r;
		if (count) {
			lnode lc = new node(0);
			f->lchild = lc;
			c = count - 1;
			r = remain + 1;
			buildtree(f->lchild, c, r);
		}

		if (remain) {
			lnode rc = new node(1);
			f->rchild = rc;
			r = remain - 1;
			c = count;
			buildtree(f->rchild, c, r);
		}
	}

	void DFS(lnode r, string s, vector<string> &ans) {
		if (r == NULL)
			return;

		if (r->val == 1)
			s.push_back(')');
		else
			s.push_back('(');

		if (r->lchild == NULL&&r->rchild == NULL) {
			ans.push_back(s);
		}

		DFS(r->lchild, s, ans);
		DFS(r->rchild, s, ans);
	}

public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		if (n == 0) {
			return ans;
		}

		lnode root = new node(0);
		int count = n - 1;	//Ê£Óà×óÀ¨ºÅ
		int remain = 1;		//Ê£ÓàÎ´Æ¥Åä×óÀ¨ºÅ

		buildtree(root, count, remain);

		string s;

		DFS(root, s, ans);

		return ans;
	}
};