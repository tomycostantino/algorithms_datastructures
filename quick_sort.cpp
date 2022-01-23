#include <iostream>
#include <string>

using namespace std;

void displayArray(int arr[], int size);
void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void swap(int* xp, int* yp);

int main() {
	int a[10] = {23,32,43,56,11,764,323,123,657,87};
	cout << "Unsorted: ";
	displayArray(a, 10);
	cout << endl;
	cout << "Quicksorted: ";
	quickSort(a, 0, 10);
	displayArray(a, 10);
	cout << endl;

	system("pause");
	return 0;
}
void displayArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}
void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
int partition(int a[], int low, int high) {
	int pivot = a[low];
	int i = low, j = high;
	//loop until i and j cross paths
	while (i < j) {
		//i looks for value in array which is BIGGER than pivot value
		do {
			i++;
		} while (a[i] < pivot); //Stop loop once value in a[i] greater than pivot
	 //j looks for value in array which is smaller than pivot value
		do{
			j--;
		} while (a[j] > pivot);
		//IF i and j have crossed paths, we can assume we've
		//found a value bigger with i and a value smaller with j, so swap them
		if (i < j)
			swap(a[i], a[j]);
	}
	swap(a[low], a[j]);
	//return j so that new quicksort can partition work into two loads
	//one left of j and one of
	return j;
}
void quickSort(int a[], int low, int high) {
	if (low < high) { //look up towers of hanoi algorithms
		int partitionIndex = partition(a, low, high);
		quickSort(a, low, partitionIndex);
		quickSort(a, partitionIndex + 1, high);
	}
}
