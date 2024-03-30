// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
    int count = 0;
    int i = 0;
    while (i < len) {
        int j = i + 1;
        while (j < len) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
            j++;
        }
        i++;
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
    int count = 0;
    int lastnum = len - 1;
    do {
        lastnum = lastnum - 1;
    } while (arr[lastnum] > value);
    int i = 0;
    while (i < lastnum) {
        int j = lastnum;
        while (j > i) {
            if (arr[j] + arr[i] == value) {
                count++;
            }
            j--;
        }
        i++;
    }
    return count;
}

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int i = mid + 1;
            while (i < size && arr[i] == value) {
                count++;
                i++;
            }
            i = mid - 1;
            while (i >= 0 && arr[i] == value) {
                count++;
                i--;
            }
            return count;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
  return 0;
    int count = 0;
    int i = 0;
    while (i < len) {
        int num = value - arr[i];
        count = count + cbinsearch(&arr[i + 1], len - i - 1, num);
        i++;
    }
    return count;
}
