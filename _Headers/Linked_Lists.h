#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct Node
{
	int data;
	struct Node *next;
};