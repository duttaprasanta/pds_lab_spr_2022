/*
* Programmer : Prasanta Dutta
*/

#include<stdio.h>
#include<stdbool.h>


bool checkSortedIncreasing(int n, int a[]){
    for(int i=0;i<=n-2;i++){
        if(a[i]>=a[i+1]){
            return false;
        }
    }
    return true;
}

int linearSearch(int n, int a[], int key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}

int binarySearch(int n, int a[], int key){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int elem[n];
    bool stat;
    do{
        printf("Enter the elements in sorted order : ");
        for(int i=0; i<n; i++)
        {
            scanf("%d", &elem[i]);
        }
        stat = !checkSortedIncreasing(n, elem);
        if(stat){
            printf("Not sorted. Enter again\n");
        }
    }while(stat);
    int key;
    printf("Enter the key element x, which you want to search : ");
    scanf("%d", &key);
    int algo;
    printf("Choose the algorithm: Type 1 for linear search and 2 for binary search : ");
    scanf("%d", &algo);
    if(algo==1){
        printf("Executing Linear Search\n");
        int index = linearSearch(n, elem, key);
        if(index==-1){
            printf("Element not found\n");
        }
        else{
            printf("Successful search\n");
            printf("Element %d has been found at index %d\n",key, index);
        }
    }
    else if(algo==2){
        printf("Executing Binary Search\n");
        int index = binarySearch(n, elem, key);
        if(index==-1){
            printf("Element not found\n");
        }
        else{
            printf("Successful search\n");
            printf("Element %d has been found at index %d\n",key, index);
        }
    }
    else{
        printf("Wrong choice\n");
    }
    return 0;
}

