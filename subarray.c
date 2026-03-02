#include <stdio.h> 
#include <limits.h>

int max_sub_sum_arr(int *arr, int n){
    int max_sum = INT_MIN;

    for(int i=0; i<n; i++){
        int sum = 0; 
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum >= max_sum) {
                max_sum = sum; 
            }
        }
    }

    return max_sum;
}

int main () {
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max_sub_sum = max_sub_sum_arr(arr, n);
    printf("max sub array sum: %d\n", max_sub_sum);

    return 0; 
}