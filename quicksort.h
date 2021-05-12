

int partitionN(int number[], int left, int right) { 
    int i = left - 1; 
    int j;
    for(j = left; j < right; j++) { 
        if(number[j] <= number[right]) { 
            i++; 
            swapN(number,i,j); ; 
        } 
    } 

    swapN(number,i+1,right); 
    return i+1; 
} 

void quickSortN(int number[], int left, int right) { 
    if(left < right) { 
        int q = partitionN(number, left, right); 
        quickSortN(number, left, q-1); 
        quickSortN(number, q+1, right); 
    } 
} 

int partitionS( char **arr, int left, int right) { 
    int i = left - 1; 
    int j;
    for(j = left; j < right; j++) { 
        if(strcmp(arr[j],arr[right])<=0) { 
            i++; 
            swapS(arr,i, j); 
        } 
    } 
    swapS(arr,i+1,right); 
    return i+1; 
} 
void quickSortS(char **arr, int left, int right) { 
    if(left < right) { 
        int q = partitionS(arr, left, right); 
        quickSortS(arr, left, q-1); 
        quickSortS(arr, q+1, right); 
    } 
} 