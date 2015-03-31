/*
	Insertion Sort (Skiena)
		(valuable only when n <= 10^5)
	----------------------------------
	Time Complexity: O(n^2)
	Space Complexity: 
*/

insertion_sort(item s[], int n)
{
	int i, j;
	for (i = 1; i < n i++)
	{
		j = i;
		while ((j > 0) && (s[j] < s[j-1])) 
		{
			swap(&s[j], &s[j-1]);
			j = j-1;
		}
	}
}