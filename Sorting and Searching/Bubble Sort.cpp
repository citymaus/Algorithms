/*
  Bubble Sort
    http://www.cprogramming.com/tutorial/computersciencetheory/sorting1.html
  
  - Not great for large data sets
  - Extremely inefficient
	----------------------------------
	Time Complexity: O(n^2)
	Space Complexity: O(1)
*/

bubble_sort(int array[], int n)
{
  for(int x=0; x<n; x++)
	{
		for(int y=0; y<n-1; y++)
		{
			if(array[y]>array[y+1])
			{
				int temp = array[y+1];
				array[y+1] = array[y];
				array[y] = temp;
			}
		}
	}
}