#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<sys/time.h>
#include"quicksort.h"
#include"heapsort.h"
#include"mergesort.h"
#define datacnt 520000



char **word;

void swapN(int arr[], int a, int b){
    int tmp;
    tmp = arr[a];
    arr[a]= arr[b];
    arr[b] = tmp;
}

void swapS(char **arr, int a, int b){
    char tmp[101];
    strcpy(tmp,arr[a]);
    strcpy(arr[a],arr[b]);
    strcpy(arr[b],tmp);
}


int main()
{
    FILE *xfile;
    FILE *yfile;
    FILE *afile;
    FILE *bfile;
    struct timeval start;//起始點
	struct timeval end;//結束點
	unsigned long diff;//儲存計算的時間差

    int i, j;
    int *number = malloc(sizeof(int)*datacnt);
    int *data = malloc(sizeof(int)*datacnt);
    char **data2 = malloc(sizeof(char *)*datacnt);
    word = malloc(sizeof(char *)*datacnt);
    if(!word)
    {
        printf("erro\n");
    }
    srand(10);

    xfile = fopen("dataset1.txt", "w");
    for(i = 0; i < datacnt; i ++)
    { 
        *(data+i) = (rand()%10000) + 1;
    }
    for(i = 0; i < datacnt; i ++)
    {
        fprintf(xfile, "%d\n", *(data+i));
    }
    fclose(xfile);//

    yfile = fopen("dataset1.txt", "r");
    //FILE *ifile = yfile;
    for(i = 0; i < datacnt; i ++)
    {
        fscanf(yfile,"%d", &number[i]);
    }

   afile = fopen("dataset2.txt", "w");
    for(i = 0; i < datacnt; i ++)
    {
        *(data2+i) = malloc(sizeof(char)*101);
        for(j = 0; j < 100; j ++)
        {
            *(*(data2+i)+j) = rand()%26 + 'a';
        }
    }
    for(i = 0; i < datacnt; i ++)
    {
        fprintf(afile, "%s\n", *(data2+i));
        free(*(data2+i));
    }
    fclose(afile);

    bfile = fopen("dataset2.txt", "r");
   // FILE *jfile = bfile;
    for(i = 0; i < datacnt; i ++)
    {
        *(word+i) = malloc(sizeof(char)*101);
        fscanf(bfile, "%s", *(word+i));
    }


    gettimeofday(&start, NULL);//開始
    heap_sortN(number, datacnt);
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("heap_sortN: %f sec\n", diff / 1000000.0);//印出結果

    gettimeofday(&start, NULL);//開始
    heap_sortS(word, datacnt);
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("heap_sortS %f sec\n", diff / 1000000.0);//印出結果
    fclose(yfile);//不用關B?




    yfile = fopen("dataset1.txt", "r");
   // ifile = yfile;
    for(i = 0; i < datacnt; i ++)
    {
        fscanf(yfile,"%d", &number[i]);
    }
    fclose(bfile);

    bfile = fopen("dataset2.txt", "r");
    //jfile = bfile;
    for(i = 0; i < datacnt; i ++)
    {
        fscanf(bfile, "%s", *(word+i));
    }
    gettimeofday(&start, NULL);//開始
    quickSortN(number, 0, datacnt-1);
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("quickSortN %f sec\n", diff / 1000000.0);//印出結果

    gettimeofday(&start, NULL);//開始
    quickSortS(word, 0, datacnt-1);
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("quickSortS %f sec\n", diff / 1000000.0);//印出結果
    fclose(yfile);



    yfile = fopen("dataset1.txt", "r");
   // ifile = yfile;
    for(i = 0; i < datacnt; i ++)
    {
        fscanf(yfile,"%d", &number[i]);
    }
    fclose(bfile);
    
    bfile = fopen("dataset2.txt", "r");
    //jfile = bfile;
    
     for(i = 0; i < datacnt; i ++)
    {
        fscanf(bfile, "%s", *(word+i));
    }
    

    gettimeofday(&start, NULL);//開始
    mergesortN(number, 0 , datacnt-1);
    
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("merge_sortN %f sec\n", diff / 1000000.0);//印出結果
    
    
    gettimeofday(&start, NULL);//開始 
    mergesortS(word, 0 , datacnt-1);
    
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
    
	printf("merge_sortS %f sec\n", diff / 1000000.0);//印出結果

    for(i = 0; i < datacnt; i ++)
    {
        free(*(word+i));
    }

    fclose(yfile);
    fclose(bfile);
   // fclose(ifile);
    //fclose(jfile);
    free(data);
    free(data2);
    free(word);
    return 0;
}