/**
 * Sort algorithm: insertion sort.
 *
 * hellfire (asyncloading#163.com)
 * Feb 5th, 2016
 */

#include<iostream>

#define MAX_N 1000;

using namespace std;

int *insertion_sort(int *arr, int n)
{
  for (int i = 1; i < n; i ++)
  {
    int tmp = arr[i];
    for (int j = i - 1; j >= 0; j --)
    {
      if (arr[j] > tmp)
      {
        arr[j + 1] = arr[j];
        arr[j] = tmp;
      }
    }
  }
  return arr;
}

int main(int argc, char **argv)
{
  // Test case
  int n;
  while (cin >> n)
  {
    int *nums = new int[n];

    for (int i = 0; i < n; i ++)
    {
      cin >> nums[i];
    }

    int *sorted_nums = insertion_sort(nums, n);
    for (int i = 0; i < n; i++)
    {
      cout << sorted_nums[i] << ' ';
    }
    cout << endl; 
  }
}

