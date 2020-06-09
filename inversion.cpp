// Counting inversions as seen in the class (the divide and conquer approach)
#include <iostream> 
using namespace std; 

// Merge two subarrays of array[]
int merge(int array[], int tempArr[], int left, int mid, int right) 
{ 
    int i, j, k; 
    i = left; 
    j = mid; 
    k = left; 
    int countInv = 0; 
    
    while ((i <= mid - 1) && (j <= right)) 
    {   
        // if left item is less than right item, there's no inversion
        if (array[i] <= array[j])  
        {    
            tempArr[k++] = array[i++];  
        } 
        else 
        // if left item is greater than right item, an inversion is done
        {         
            tempArr[k++] = array[j++];        
            countInv += (mid - i); 
        } 
    }
    while (i <= mid - 1)        
        tempArr[k++] = array[i++];         
    while (j <= right)         
        tempArr[k++] = array[j++];         
    for (i = left; i <= right; i++)   
        array[i] = tempArr[i];
    return countInv; 
}

// Merge the sublists, sorting the values
int mergeSort(int arr[], int tempArr[], int left, int right) 
{ 
    int mid, countInv = 0; if (right > left) 
    {        
        mid = (right + left)/2;         
        countInv = mergeSort(arr, tempArr, left, mid); // apply merge sort to left subarray     
        countInv += mergeSort(arr, tempArr, mid + 1, right); // apply merge sort to right subarray        
        countInv += merge(arr, tempArr, left, mid + 1, right); // apply merge to both subarrays 
    } 
    return countInv; 
}

// Count the number of inversions
int countInversions(int arr[], int size) 
{ 
    int tempArr[size]; 
    return mergeSort(arr, tempArr, 0, size - 1); 
} 

int main() 
{ 
    int i, size;
    cout << "Enter size of list: ";
    cin >> size;

    int a[size];
    cout << "Enter list: ";
    for (i = 0; i < size; i++)
        cin >> a[i];

    cout << "Total number of inversions: "<< countInversions(a, size)<<"\n";     
}
