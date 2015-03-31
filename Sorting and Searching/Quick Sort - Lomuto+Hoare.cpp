/*
	Quick Sort (with Lomuto or Hoare partition)
  
	- Valuable for big n, <= 10^9
  - Randomly pick pivot can help avoid worst case: sorted array
  - Hoare better than Lomuto partition
	----------------------------------
	Time Complexity: O(n*log(n))
	Space Complexity: O(1)
  		
*/

int lomuto_partition(vector <int> & arr, int start, int end, int* numswaps)
{
  int x = arr[end];
  int i = start - 1;
  //cout << "start:" << start << " / end:" << end << endl;
  for (int j = start; j < end; j++)
  {
      if (arr[j] <= x)
      {
          i = i + 1;
          swap(arr[i], arr[j]);
          *numswaps = *numswaps + 1;
          //print_arr(arr);
          //cout << endl;
      }
  }
  swap(arr[i + 1], arr[end]);
  *numswaps = *numswaps + 1;
  //print_arr(arr);
  //cout << endl;
  return i + 1;
}

int hoare_partition (vector <int> & arr,int p, int r) {
  int x = arr[p];
  int i = p - 1;
  int j = r;
  while (1) {
      do  j--; while (arr[j] > x);
      do  i++; while (arr[i] < x);
      if  (i < j) 
          swap(arr[i], arr[j]);
      else 
          return j + 1;
  }
}

int quick_sort4(vector <int> & arr, int start, int end)
{
    int numswaps = 0;
    int p_idx;
    
    if (start < end)
    {
        p_idx = lomuto_partition(arr, start, end, &numswaps);
        numswaps += quick_sort4(arr, start, p_idx-1);
        numswaps += quick_sort4(arr, p_idx+1, end);
    } 
    //cout << "numswaps: " << numswaps << endl;
    return numswaps;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, r;
    int qswaps;
    cin >> N;
    vector <int> sortmeq;
    for (int i = 0; i < N; i++)
    {
        cin >> r;
        sortmeq.push_back(r);
    }
    //cout << endl << endl << "quick sort:" << endl;
    qswaps = quick_sort4(sortmeq, 0, N-1);
    cout << qswaps << endl;
    return 0;
}