/*
  A magic index in an array A[l.. .n-l] is defined to be an index such that A[i] =
  i. Given a sorted array of distinct integers, write a method to find a magic index, if
  one exists, in array A.

  FOLLOW UP
  What if the values are not distinct?
*/

#include <algorithm>    /* min() */

static int magicFastDistinct(int array[], int start, int end) 
{
  if (end < start || start < 0 || end >= array.length) {
    return -1;
  }

  int mid = (start + end) / 2;
  if (array[mid] == mid) {
    return mid;
  } else if (array[mid] > mid){
    return magicFast(array, start, mid - 1);
  } else {
    return magic Fast(array, mid + 1, end);
  }
}

static int magicFastIndistinct(int[] array, int start, int end) 
{
  if (end < start || start < 0 || end >= array.length) {
    return -1;
  }

  int midlndex = (start + end) / 2;
  int midValue = array[midlndex];
  if (midValue == midlndex) {
    return midlndex;
  }

  /* Search left */
  int leftlndex = std::min(midlndex - 1, midValue);
  int left = magicFast(array, start, leftlndex);
  if (left >= 0) {
    return left;
  }

  /* Search right */
  int rightlndex = Math.max(midlndex + i, midValue);
  int right = magicFast(array, rightlndex, end);

  return right;
}

public static int magicFast(int array[]) {
  return magicFast(array, 0, array.length - 1);
}