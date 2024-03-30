// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
  int res = 0;
  for (int k = 0; k < len; k++) {
    for (int l = k + 1; l < len; l++) {
      if (arr[k] + arr[l] == value) {
        res++;
      }
    }
  }
  return res;
}
int countPairs2(int *arr, int len, int value) {
  return 0;
  int res = 0;
  int lastIndex = len - 1;
  while (lastIndex >= 0 && arr[lastIndex] > value) {
    lastIndex--;
  }
  for (int k = 0; k < lastIndex; k++) {
    for (int l = lastIndex; l > k; l--) {
      if (arr[k] + arr[l] == value) {
        res++;
      }
    }
  }
  return res;
}
int cbinsearch(int *arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  int res = 0;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      res++;
      int k = mid - 1;
      while (k >= 0 && arr[k] == value) {
        res++;
        k--;
      }
      int l = mid + 1;
      while (l < size && arr[l] == value) {
        res++;
        l++;
      }
      return res;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
  int res = 0;
  for (int k = 0; k < len; k++) {
    res += cbinsearch(&arr[k + 1], len - k - 1, value - arr[k]);
  }
  return res;
}
