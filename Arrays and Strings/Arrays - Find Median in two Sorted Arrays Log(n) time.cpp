#include "Arrays_and_Strings.h"

/*
https://leetcode.com/articles/median-of-two-sorted-arrays/

There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

*/


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int size1 = (nums1.size() > 0) ? static_cast<int>(nums1.size()) : 0;
	int size2 = (nums2.size() > 0) ? static_cast<int>(nums2.size()) : 0;
	int totalsize = (((size1 + size2) / 2) + 1);
	//cout << "totalsize:" << totalsize << endl;
	vector<int>combined(totalsize, 0);
	int i = 0, j = 0, k = 0;
	while (i < size1 && j < size2 && k < totalsize) {
		if (nums1[i] < nums2[j]) {
			//cout << " add 1[" << i << "]" << nums1[i] << endl;
			combined[k++] = nums1[i++];
		}
		else {
			//cout << " add 2[" << j << "]" << nums2[j] << endl;
			combined[k++] = nums2[j++];
		}
	}
	//cout << "i:" << i << " j:" << j << " k:" << k << endl;
	while (i < size1 && k < totalsize) {
		combined[k++] = nums1[i++];
	}
	while (j < size2 && k < totalsize) {
		combined[k++] = nums2[j++];
	}
	printVector(combined);
	return ((size1 + size2) % 2 == 1) ? combined[(totalsize - 1)] : ((combined[(totalsize - 1)] + combined[(totalsize - 2)]) / 2.0);
}