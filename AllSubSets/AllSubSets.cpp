// AllSubSets.cpp : Defines the entry point for the console application.
/*
Given a set of distinct integers, S, return all possible subsets.
	1. Elements in a subset must be in non-descending order.
	2. The solution set must not contain duplicate subsets.
	3. Also, the subsets should be sorted in ascending ( lexicographic ) order.
	4. The list is not necessarily sorted.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool compare(int a, int b) { return a > b;  }

void subset_util(vector<int> &curr_sol, int n, vector<int> &A, vector<vector<int> > &sol_set)
{
	if (n == A.size()) //We have considered all the items
	{
		sol_set.push_back(curr_sol);
		return;
	}

	//take (n)th item
	curr_sol.push_back(A[n]);
	subset_util(curr_sol, n+1, A, sol_set);
	
	//or Dont take (n)th item
	curr_sol.pop_back();
	subset_util(curr_sol, n+1, A, sol_set);
		

}

void print_All_SubSets(vector<int> &A, vector<vector<int> > &sol_set)
{
	vector<int> currSol;
	subset_util(currSol, 0, A, sol_set); 
}

void unique_subSet_Util(vector<int> &curr_sol, int i, vector<int> &A, vector<vector<int> > &sol_set)
{
	if (i == A.size())
	{
		sol_set.push_back(curr_sol);
		return; 
	}

	//take ith element
	curr_sol.push_back(A[i]);
	unique_subSet_Util(curr_sol, i + 1, A, sol_set);

	//Or don't take ith element
	curr_sol.pop_back();
	while (i < A.size() - 1 && A[i + 1] == A[i]) { i++;  }
	unique_subSet_Util(curr_sol, i + 1, A, sol_set);
}

void print_Unique_Subsets(vector<int> &A, vector<vector<int> > &sol_set)
{
	vector<int> curr_set;

	unique_subSet_Util(curr_set, 0, A, sol_set);
}

void print_solution(vector<vector<int> > &sol_set)
{
	for (int i = 0; i < sol_set.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < sol_set[i].size(); j++)
		{
			cout << sol_set[i][j] << ",";
		}
		cout << "]" << endl;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	vector<vector<int> > sol_set, sol_set2;

	print_All_SubSets(A, sol_set);

	sort(sol_set.begin(), sol_set.end());

	print_solution(sol_set);

	cout << "UNIQUE COMBOS........." << endl;
	print_Unique_Subsets(A, sol_set2);
	sort(sol_set2.begin(), sol_set2.end());
	print_solution(sol_set2);
    return 0;
}

