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

int middle(int *array,int first,int last,int mid){
    if(first<last){
        int pivot=array[first];
        int splitpoint=partition(array,pivot,first,last);
        array[splitpoint]=pivot;
        if(splitpoint==mid){
            return pivot;
        }
        else if(splitpoint>mid){
            middle(array,first,splitpoint-1,mid);
        }
        else{
            middle(array,splitpoint+1,last,mid);
        }

    }
}

int main(){
    int array[9]={23,1235,63,532,6245,234,4,123,43};
    int mid=middle(array,0,8,4);
    printf("%d\n",mid);
}