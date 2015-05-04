

int getPopularElement(int a[])
{
  int count = 1, tempCount;
  int popular = a[0];
  int temp = 0;
  int arrsize = sizeof(a)/sizeof(int);
  for (int i = 0; i < (arrsize - 1); i++)
  {
    temp = a[i];
    tempCount = 0;
    for (int j = 1; j < arrsize; j++)
    {
      if (temp == a[j])
        tempCount++;
    }
    if (tempCount > count)
    {
      popular = temp;
      count = tempCount;
    }
  }
  return popular;
}