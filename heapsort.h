/*void swapN(int arr[], int a, int b){
    int tmp;
    tmp = arr[a];
    arr[a]= arr[b];
    arr[b] = tmp;
}*/
//#include"quicksort.h"
void heapifyNum(int tree[], int n , int i){
    int c1 = 2*i +1;
    int c2 = 2*i +2;//i是父節點 c1 c2 是子節點
    int max = i;
    if(i>n) return ;
    if(c1 < n && tree[c1] > tree[max]) max = c1;
    if(c2 < n && tree[c2] > tree[max]) max =c2 ;
    if(max != i){
        swapN(tree, max, i);
        heapifyNum(tree, n , max );
    }
}
void buildheapN(int tree[], int n){
    int last_node = n-1;
    int parent = (last_node -1) / 2;
    int i;
    for(i = parent ; i >=0 ; i--){
        heapifyNum(tree, n, i );
    }
}
void heap_sortN(int tree[], int n){
    buildheapN(tree, n);
    int i;
    for(i=n-1;i>=0;i--){
        swapN(tree,i ,0);//每輪把最後跟第一個互換 然後提出最後一個(最大)砍斷
        heapifyNum(tree, i, 0);
    }
}
/*void swapS(char **arr, int a, int b){
    char tmp[101];
    strcpy(tmp,arr[a]);
    strcpy(arr[a],arr[b]);
    strcpy(arr[b],tmp);
}*/
void heapifyString(char **tree, int n , int i){
    int c1 = 2*i +1;
    int c2 = 2*i +2;//i是父節點 c1 c2 是子節點
    int max = i;
    if(i>n) return ;
    if(c1 < n && strcmp(tree[c1],tree[max])>0) max = c1;
    if(c2 < n && strcmp(tree[c2],tree[max])>0) max =c2 ;
    if(max != i){
        swapS(tree, max, i);
        heapifyString(tree, n , max );
    }
}
void buildheapS(char **tree, int n){
    int last_node = n-1;
    int parent = (last_node -1) / 2;
    int i;
    for(i = parent ; i >=0 ; i--){
        heapifyString(tree, n, i );
    }
}
void heap_sortS(char **tree, int n){
    buildheapS(tree, n);
    int i;
    for(i=n-1;i>=0;i--){
        swapS(tree,i ,0);//每輪把最後跟第一個互換 然後提出最後一個(最大)砍斷
        heapifyString(tree, i, 0);
    }
}
