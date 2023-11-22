void sift_down(int arr[], int start, int end) {
	int parent = start;
	int child = parent * 2 + 1;
	while (child <= end) {
		if (child + 1 <= end && arr[child] < arr[child + 1])
			child++;
		if (arr[parent] >= arr[child])
			return;
		else {
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) {
	for (int i = (len - 1 - 1) / 2; i >= 0; i--)
		sift_down(arr, i, len - 1);
	for (int i = len - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		sift_down(arr, 0, i - 1);
	}
}