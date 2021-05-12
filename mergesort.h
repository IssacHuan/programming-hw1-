#include<string.h>
void mergeN(int *arr, int low, int mid, int high) {
    int leftIndex = low;
    int rightIndex = mid + 1;
    int tempArrLength = high - low + 1;
    int tempArr[tempArrLength];
    int tempIndex = 0;

    while (leftIndex <= mid && rightIndex <= high) {
        if (arr[leftIndex] <= arr[rightIndex]) {
            tempArr[tempIndex] = arr[leftIndex];//比較小的放進去
            leftIndex++;
        }
        else {
            tempArr[tempIndex] = arr[rightIndex];//比較小的放進去
            rightIndex++;
        }
        tempIndex++;
    }
    if (leftIndex > mid) {
        while (rightIndex <= high) {
            tempArr[tempIndex] = arr[rightIndex];
            rightIndex++;
            tempIndex++;
        }
    }
    else {
        while (leftIndex <= mid) {
            tempArr[tempIndex] = arr[leftIndex];
            leftIndex++;
            tempIndex++;
        }
    }
    leftIndex = low;
    for (tempIndex=0; tempIndex<tempArrLength; tempIndex++) {
        arr[leftIndex] = tempArr[tempIndex];
        leftIndex++;
    }
}

void mergesortN(int *arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergesortN(arr, low, mid);
        mergesortN(arr, mid + 1, high);
        mergeN(arr, low, mid, high);
    }
}
void mergeS(char **a, int low, int mid, int high) {
    char **arr = a;
    int leftIndex = low;
    int rightIndex = mid + 1;
    int tempArrLength = high - low +1;
    //char *tempArr[tempArrLength];
    char **tempArr = (char**)malloc(sizeof(char*) * tempArrLength) ;
    int tempIndex = 0;
    
    while (leftIndex <= mid && rightIndex <= high) {
        if (strcmp(arr[leftIndex],arr[rightIndex])<=0) {
            tempArr[tempIndex]=arr[leftIndex];
            leftIndex++;
        }
        else {
            tempArr[tempIndex]=arr[rightIndex];
            rightIndex++;
        }
        tempIndex++;
    }
    if (leftIndex > mid) {
        while (rightIndex <= high) {
            tempArr[tempIndex]=arr[rightIndex];
            rightIndex++;
            tempIndex++;
        }
    }
    else {
        while (leftIndex <= mid) {
            tempArr[tempIndex]=arr[leftIndex];
            leftIndex++;
            tempIndex++;
        }
    }
    leftIndex = low;
    for (tempIndex=0; tempIndex<tempArrLength; tempIndex++) {
        arr[leftIndex]=tempArr[tempIndex];
        leftIndex++;
    }
}

void mergesortS(char **arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergesortS(arr, low, mid);
        mergesortS(arr, mid + 1, high);
        mergeS(arr, low, mid, high);
    }
}

