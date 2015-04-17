/*
  Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
  column are set to 0.
*/
void set_zeros(int arr[][100], int N)
{
    bool row[100];
    bool col[100];
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));  

    // Store all rows and cols that contain a 0
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (arr[i][j] == 0)
        {
          row[i] = true;
          col[j] = true;
        }
      }
    }

    // Set rows and cols to 0
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (row[i] || col[j])
        {
          arr[i][j] = 0;
        }
      }
    }
}

void print_array(int arr[][100], int N)
{
  for (int x = 0; x < N; x++)
  {
    for (int y = 0; y < N; y++)
    {
      cout << arr[x][y] << " ";
    }
    cout << endl;
  }
}