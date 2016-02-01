/**
 * Construct Suffix Array
 * Simple method implement.
 *
 * hellfire (asyncloading#163.com)
 * Feb 1st, 2016
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX_N 1024

typedef struct suffix {
  int index;
  char *str;
} Suffix;


/* Suffix str compare, return with lexicographic order. */
int cmp(Suffix a, Suffix b)
{
  return strcmp(a.str, b.str) < 0;
}
/* Construct a sufffix array with parent string. */
int *construct_suffix_array(char *str, int n)
{
  /* Initialize suffix array. */
  Suffix suffixes[n];

  for (int i = 0; i < n; i ++)
  {
    suffixes[i].index = i;
    suffixes[i].str = str + i;
  }
  /* Sort with lexicographic order. */
  sort(suffixes, suffixes + n, cmp);
  int *suffix_array = new int[n];
  for (int i = 0; i < n; i ++)
  {
    suffix_array[i] = suffixes[i].index;
  }
  return suffix_array;
}

int main(int argc, char **argv)
{
  char str[MAX_N];
  while (gets(str) != NULL)
  {
    int len = strlen(str);
    int *suffix_array = construct_suffix_array(str, len);
    for (int i = 0; i < len; i ++)
    {
      cout << suffix_array[i] << ' ';
    }
    cout << endl;
  }
}
