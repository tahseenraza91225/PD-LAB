#include <stdio.h>
void Max_Heapify(int arr[], int N, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < N && arr[left] > arr[largest])
		largest = left;
	if (right < N && arr[right] > arr[largest])

		largest = right;
	if (largest != i) {

		int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
		Max_Heapify(arr, N, largest);
	}
}
 void Build_Max_Heap(int arr[],int N){
         for (int i = N / 2 - 1; i >= 0; i--)
                   Max_Heapify(arr, N, i);
}
void Max_HeapSort(int arr[], int N)
{
	Build_Max_Heap(arr,N);
	for (int i = N - 1; i >= 0; i--) {

		int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
		Max_Heapify(arr, i, 0);
	}
}
int main()
{   int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
	Max_HeapSort(arr, N);
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
