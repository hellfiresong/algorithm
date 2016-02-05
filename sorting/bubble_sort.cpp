/**
 * Sort algorithm: bublle sort.
 *
 * hellfire (asyncloading#163.com)
 * Feb 5th, 2016
 */

#include<iostream>

#define MAX_N 1000;

using namespace std;

int *bubble_sort(int *arr, int n)
{
  for (int i = 0; i < n; i ++)
  {
    for (int j = 0; j < i; j ++)
    {
      if (arr[i] < arr[j])
      {
        int tmp;
        tmp = arr[i];
        arr[i] = arr[j];
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

    int *sorted_nums = bubble_sort(nums, n);
    for (int i = 0; i < n; i++)
    {
      cout << sorted_nums[i] << ' ';
    }
    cout << endl; 
  }
}


