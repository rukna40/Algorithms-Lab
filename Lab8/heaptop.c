    #include <stdio.h>
    #include <stdlib.h>

    void heapify(int n, int h[n]){
        int i,j,k,v,flag;
        for(i=n/2;i>=0;i--){
            flag=0;
            k=i;
            v=h[k];
            while(flag==0 && 2*k<=n){
                j=2*k;
                if(j<n)
                    if(h[j]<h[j+1]) 
                        j=j+1;
                if (v>=h[j])
                    flag=1;
                else{
                    h[k]=h[j];
                    k=j;
                }
            }
            h[k]=v;
        }
        return;
    }

    void buildHeap(int n,int h[n]) {
        for (int i = 1; i <= n; i++) {
            printf("Enter element %d: ", i);
            scanf("%d", &h[i]);
            heapify(i,h);
        }
    }

    void delete(int n, int h[n],int val){
        int i;
        for (i=1;i<=n;i++){
            if (h[i]==val){
                break;
            }   
        }
        if (i > n) {
            printf("Element not found\n");
            return;
        }
        h[i]=h[n];
        heapify(n - 1, h);
    }

    void main(){ 
        int h[20],i,n; 

        printf("\nEnter the number of Elements:"); 
        scanf("%d",&n); 

        buildHeap(n,h); 
        printf("\nThe heap created:"); 
        for(i=1;i<=n;i++) 
        { 
        printf("%d\t",h[i]); 
        } 
        delete(n,h,9);
        printf("\nAfter deleting:"); 
        for(i=1;i<=n;i++) 
        { 
        printf("%d\t",h[i]); 
        } 
    } 
    
