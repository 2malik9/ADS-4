// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
  int res = 0;
  int k = 0;
  while (k < len) {
    int l = k + 1;
    while (l < len) {
      if ((arr[k] + arr[l]) == value) {
        res++;
      }
      l++;
    }
    k++;
  }
  return res;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
  int res = 0;
  int last = len - 1;
  do {
    last = last - 1;
  } while (arr[last] > value);
  int k = 0;
    while (k < last) {
        int l = last;
        while (l > k) {
            if (arr[l] + arr[k] == value) {
                res++;
            }
            l--;
        }
        k++;
    }
    return res;
}

int cbinsearch(int *arr, int size, int value) {
  int res = 0;
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      res++;
      int k = mid + 1;
      while (k < size && arr[k] == value) {
        res++;
        k++;
      }
      k = mid - 1;
      while (k >= 0 && arr[k] == value) {
        res++;
        k--;
      }
      return res;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return res;
}

int countPairs3(int *arr, int len, int value) {
  return 0;
  int res = 0;
  int k = 0;
  while (k < len) {
    int number = value - arr[k];
    res = res + cbinsearch(&arr[k + 1], len - k - 1, number);
    k++;
  }
  return res;
}
