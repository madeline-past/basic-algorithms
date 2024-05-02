#include<stdio.h>
int extendlargeregion(int *array,int pivot,int low,int high){
    int i=0;
    while(array[high-i]>=pivot && (high-i)>=(low+1)){
        i++;
    }
    array[low]=array[high-i];
    return (high-i);
}

int extendsmallregion(int *array,int pivot,int low,int high){
    if(low<high){
        int i=0;
        while(array[low+i]<=pivot && (low+i)<=(high-1)){
            i++;
        }
        array[high]=array[low+i];
        return (low+i);
    }
    return low;
}

int partition(int *array,int pivot,int first,int last){
    int low,high,highvac,lowvac;
    low=first;
    high=last;
    while(low<high){
        highvac=extendlargeregion(array,pivot,low,high);
        if(highvac>low){
            lowvac=extendsmallregion(array,pivot,low+1,highvac);
            low=lowvac;
        }
        else{
            break;
        }
        high=highvac-1;
    }
    return low;
}

void quicksort(int *array,int first,int last){
    if(first<last){
        int pivot=array[first];
        int splitpoint=partition(array,pivot,first,last);
        array[splitpoint]=pivot;
        quicksort(array,first,splitpoint-1);
        quicksort(array,splitpoint+1,last);
    }
}

int main(){
    int array[10]={23,1235,63,532,6245,234,4,123,43};
    quicksort(array,0,9);
   int loop;
   for(loop = 0; loop < 10; loop++)
      printf("%d ", array[loop]);
}