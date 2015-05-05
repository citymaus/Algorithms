/*
	Quick Sort (Skiena)
  
	- Valuable for big n, <= 10^9
  - Randomly pick pivot can help avoid worst case: sorted array
  - Hoare better than Lomuto partition
	----------------------------------
	Time Complexity: O(n*log(n))
	Space Complexity: O(1)
  
  
		
*/
#include <cstdio>
#include <algorithm>
#include <utility>

void quick_sort(int s[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = s[(left + right) / 2];
	
	while (i <= j)
	{
		while (s[i] < pivot)
			i++;
		while (s[j] > pivot)
			j--;
		
		if (i <= j)
		{
			swap(&s[i], &s[j]);
			i++;
			j--;
		}
	}
	
	if (left < j)
		quick_sort(s, left, j);
	if (i < right)
		quick_sort(s, i, right);
}