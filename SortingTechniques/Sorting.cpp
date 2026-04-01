/*
  This file has implementation for:
    Bubble Sort
    Insertion Sort
    Selection Sort
    Quick Sort
    Merge Sort
*/

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define ll long long
#define vi std::vector<ll>
#define si std::set<ll>

using namespace std;

void bubbleSort(vi &vec)
{
  for (int i = 0; i < vec.size() - 1; ++i)
  {
    bool isSorted = true; // To be adaptive
    for (int j = 0; j < vec.size() - i - 1; ++j)
    {
      if (vec[j] > vec[j + 1]) // not >=, to be stable
      {
        isSorted = false;
        swap(vec[j], vec[j + 1]);
      }
    }
    if (isSorted)
      return;
  }
}

void insertionSort(vi &vec)
{
  for (int i = 1; i < vec.size(); ++i)
  {
    for (int j = i; j > 0; j--)
    {
      if (vec[j] < vec[j - 1])
        swap(vec[j], vec[j - 1]);
      else
        break;
    }
  }
}

void selectionSort(vi &vec)
{
  for (int i = 0; i < vec.size() - 1; ++i)
  {
    int mini = i;
    for (int j = i + 1; j < vec.size(); ++j)
    {
      if (vec[j] < vec[mini])
        mini = j;
    }
    if (mini != i)
      swap(vec[mini], vec[i]);
  }
}

int partition(vi &vec, int l, int h)
{
  int pivot = vec[l];
  int i = l, j = h;
  do
  {
    do
    {
      i++;
    } while (vec[i] <= pivot);
    do
    {
      j--;
    } while (vec[j] > pivot);
    if (i < j)
    {
      swap(vec[i], vec[j]);
    }
  } while (i < j);
  swap(vec[l], vec[j]);
  return j;
}

void quickSort(vi &vec, int l, int h)
{
  int j;
  if (l < h)
  {
    j = partition(vec, l, h);
    quickSort(vec, l, j);     // Sort left partition
    quickSort(vec, j + 1, h); // Sort right partition
  }
}

vi merge(vi v1, vi v2)
{
  int i = 0, j = 0, s1 = v1.size(), s2 = v2.size();
  vi merged;

  while (i < s1 && j < s2)
  {
    if (v1[i] < v2[j])
      merged.push_back(v1[i++]);
    else
      merged.push_back(v2[j++]);
  }

  for (; j < s2; ++j)
    merged.push_back(v2[j]);
  for (; i < s1; ++i)
    merged.push_back(v1[i]);

  return merged;
}

void merge(vi &vec, int l, int mid, int h)
{
  int i = l, j = mid + 1;
  vi merged;
  while (i <= mid && j <= h)
  {
    if (vec[i] < vec[j])
      merged.push_back(vec[i++]);
    else
      merged.push_back(vec[j++]);
  }

  for (; j <= h; ++j)
    merged.push_back(vec[j]);
  for (; i <= mid; ++i)
    merged.push_back(vec[i]);

  for (int i = l, j = 0; j < merged.size(); ++i, ++j)
    vec[i] = merged[j];
}

void mergeSort(vi &vec, int l, int h)
{
  if (l < h)
  {
    int mid = (l + h) / 2;
    mergeSort(vec, l, mid);
    mergeSort(vec, mid + 1, h);
    merge(vec, l, mid, h);
  }
}

int main()
{
  vi a = {3, 5, 8, 10};
  mergeSort(a, 0, a.size() - 1);
  for (auto v : a)
    cout << v << " ";
}