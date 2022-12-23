//Contributed by KRUTHIKA MP
#include <stdio.h>
int main()
{
int ch=0;
while(ch<5)
{
printf("------------------------------------------\n");
printf("MENU\n1.Insertion\n2.Selection\n3.Quick\n4.Merge\n");
printf("------------------------------------------\n");
printf("Enter the choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:insertion();break;
case 2:selection();break;
case 3:quick();break;
case 4:mergesorting();break;
default: printf("Thank You");
}
}
}
void selection()
{
int a[100], n, i, j, min, swap;
printf("\n-----------SELECTION SORTING----------\n");
printf("\nEnter number of elements =\n");
scanf("%d", &n);
printf("Enter %d Numbers = \n", n);
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
for(i = 0; i < n - 1; i++)
{
min=i;
for(j = i + 1; j < n; j++)
{
if(a[j] < a[min])
min=j;
}
if(min!= i)
{
swap=a[i];
a[i]=a[min];
a[min]=swap;
}
}
printf("Sorted Array is :\n");
for(i = 0; i < n; i++)
printf("%d\n", a[i]);
return 0;
}
void quickSort(int[], int, int);
int  partition(int[], int, int);
void swap(int*, int*);
void quick()
{
    int n,i;
    printf("\n------QUICK SORTING--------\n");
    printf("\nEnter number of elements= \n");
    scanf("%d",&n);

    int arr[n];

    printf("Enter %d Elements\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    quickSort(arr,0,n-1);

    printf("After the QuickSort\n");

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}

void quickSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex-1);
        quickSort(arr, pIndex+1, end);
    }
}

int partition(int arr[], int start, int end)
{
    int pIndex = start;
    int pivot = arr[end];
    int i;
    for(i = start; i < end; i++)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[end], &arr[pIndex]);
    return pIndex;
}

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
void insertion()
{
    int n, i, j, temp;
    int arr[64];
    printf("\n-------INSERTION--------\n");
    printf("\nEnter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
void mergesorting()
{
    int arr[100];
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i=0; i < n; ++i) {
       printf("Enter number%d: ",i+1);
        scanf("%d", &arr[i]);
        }

	printf("Given array is \n");
	printArray(arr, n);



	printf("\nSorted array is \n");
	mergeSort(arr, 0, n - 1);
	printArray(arr, n);
	return 0;}
