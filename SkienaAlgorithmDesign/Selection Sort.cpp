/*
	Selection Sort (Skiena)
		(valuable only when n <= 10^5)
	----------------------------------
	Time Complexity: O(n^2)
	Space Complexity: O(1)
*/

selection_sort(int s[], int n)
{
	int i, j;
	int min;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (s[j] < s[min])
			{
				min = j;
			}
			swap(&s[i], &s[min]);
		}
	}
}