#include <stdio.h>

int sqrt(int num){
    int i;
    if (num==0 || num==1)
        return num;
    for(i=0;i*i<num;i++);
    return i;
}

int binarysqrt(int num){
    if (num==0 || num==1)
        return num;
    int start=1,end=num,result;
    while (start<=end){
        int mid=(start+end)/2;
        if(mid*mid==num)
            return mid;
        else if(mid*mid<num){
            start=mid+1;
            result=mid;
        }
        else{
            end=mid-1;
        }
    }
    return result;
}