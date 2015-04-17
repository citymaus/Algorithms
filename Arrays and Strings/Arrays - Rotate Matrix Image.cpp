/*
  Given an image represented by an NxN matrix, where each pixel in the image is 4
  bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/
void rotate_image(int arr[][100], int N)
{
  for (int layer = 0; layer < N / 2; layer++)
  {
    // arr[y][x]
    int first = layer;
    int last = N - 1 - layer;
    for (int x = first; x < last; x++)
    {
      int offset = x - first;

      // Save top
      int top = arr[first][x];
      
      // left(0, ?)->top(?, 0)
      arr[first][x] = arr[last - offset][first];

      // bottom -> left
      arr[last-offset][first] = arr[last][last - offset];

      // right -> bottom
      arr[last][last - offset] = arr[x][last];

      // top -> right
      arr[x][last] = top;
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