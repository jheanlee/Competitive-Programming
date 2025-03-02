#include <bits/stdc++.h>
using namespace std;

//  use else if for clarity
//  check the ending conditions of the while loop; check for edge conditions or missed elements

//  [l, r]
class BinarySearchBothClosed {
  int binary_search(vector<int> &elements, int target) {
    int l = 0, r = elements.size() - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;
      if (elements[m] == target) {
        return m;
      } else if (elements[m] < target) {
        l = m + 1;
      } else if (elements[m] > target) {
        r = m - 1;
      }
    }

    return -1;  //  not found
  }

  int left_bound(vector<int> &elements, int target) {
    int l = 0, r = elements.size() - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;
      if (elements[m] == target) {
        r = m - 1;  //  do not return here; close up range instead
      } else if (elements[m] < target) {
        l = m + 1;
      } else if (elements[m] > target) {
        r = m - 1;
      }
    }

    if (l == elements.size()) return -1;  //  target is larger than any elements
    return (elements[l] == target) ? l : -1;  //  left bound or not found
  }

  int right_bound(vector<int> &elements, int target) {
    int l = 0, r = elements.size() - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;
      if (elements[m] == target) {
        l = m + 1;
      } else if (elements[m] < target) {
        l = m + 1;
      } else if (elements[m] > target) {
        r = m - 1;
      }
    }

    if (r < 0) return -1; //  target is smaller than any elements
    return (elements[r] == target) ? r : -1;  //  right bound or not found
  }
};