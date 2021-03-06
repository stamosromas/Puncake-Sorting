#include <iostream>
using namespace std;

void swap(int& x, int& y);
void flip(int a[], int i);
int find_max(int a[], int n);
void print_arr(int arr[], int n);
void pancake_sort(int* arr, int n);

int main() {
	int a[] = { 3,2,4,1,5,8,0 };
	pancake_sort(a, 7);
	for (int i = 0; i < 7; i++)
		cout << a[i] << " ";
	return 0;
}

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
void flip(int a[], int i) {
	int start = 0;
	while (start < i) {
		swap(a[start], a[i]);
		start++;
		i--;
	}
}
int find_max(int a[], int n) {
	int mip = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > a[mip])
			mip = i;
	return mip;
}
void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
void pancake_sort(int* arr, int n) {
	for (int cur_size = n; cur_size > 1; cur_size--) {
		int mi = find_max(arr, cur_size);
		if (mi != cur_size - 1) {
			flip(arr, mi);
			print_arr(arr, n);
			cout << endl;
			flip(arr, cur_size - 1);
			print_arr(arr, n);
			cout << endl;
		}
	}
}