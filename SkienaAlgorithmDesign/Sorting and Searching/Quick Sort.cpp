/*
	Quick Sort (Skiena)
		(valuable for big n, <= 10^9)
	----------------------------------
	Time Complexity: O(nlogn)
	Space Complexity: O(?)
		
*/

void quick_sort(item_type s[], int left, int right)
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