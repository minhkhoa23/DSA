#include "Sort.h"

//Selection Sort 

void compareSeLectionSort(int* a, int n, long long& count_compare) {
	count_compare = 0;
	for (int i = 0; ++count_compare && i < n - 1; i++) {

		int minIndex = i;
		for (int j = i + 1; ++count_compare && j < n; j++) {
			if (++count_compare && a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		int temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;

	}

}

void runningTimeSelectionSort(int* a, int n, double& runningTime) {

	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		int temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;

	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}

//Shaker Sort

void compareShakerSort(int* arr, int n, long long& count_compare) {
	count_compare = 0;
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (++count_compare && swapped) {
		swapped = false;

		for (int i = start; ++count_compare && i < end; ++i) {
			if (++count_compare && arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true;
			}
		}

		if (++count_compare && !swapped) {
			break;
		}

		--end;

		swapped = false;

		for (int i = end - 1; ++count_compare && i >= start; --i) {
			if (++count_compare && arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true;
			}
		}

		++start;
	}
}


void runningTimeShakerSort(int* arr, int n, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();
	bool swapped = true;
	int start1 = 0;
	int end1 = n - 1;

	while (swapped) {
		swapped = false;

		for (int i = start1; i < end1; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}

		--end1;

		swapped = false;

		for (int i = end1 - 1; i >= start1; --i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		++start1;
	}
	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}



//Counting Sort

void compareCountingSort(int* a, int n, long long& count_compare) {
	count_compare = 0;

	if (++count_compare && n <= 1) {
		return;
	}

	int maxVal = -1e9;
	for (int i = 0; ++count_compare && i < n; i++) {
		if (++count_compare && a[i] > maxVal) {
			maxVal = a[i];
		}
	}

	int* count = new int[maxVal + 1];

	for (int i = 0; ++count_compare && i <= maxVal; i++) {
		count[i] = 0;
	}



	for (int i = 0; ++count_compare && i < n; ++i) {
		++count[a[i]];
	}


	for (int i = 1; ++count_compare && i <= maxVal; ++i) {
		count[i] += count[i - 1];
	}


	int* output = new int[n];
	for (int i = n - 1; ++count_compare && i >= 0; --i) {
		output[--count[a[i]]] = a[i];
	}


	for (int i = 0; ++count_compare && i < n; ++i) {
		a[i] = output[i];
	}

	delete[] output;
	delete[] count;
}



void runningTimeCountingSort(int* a, int n, double& runningTime) {

	auto start = chrono::high_resolution_clock::now();
	if (n <= 1) return;

	int maxVal = -1e9;
	for (int i = 0; i < n; i++) {
		if (a[i] > maxVal) {
			maxVal = a[i];
		}
	}

	int* count = new int[maxVal + 1];

	for (int i = 0; i <= maxVal; i++) {
		count[i] = 0;
	}



	for (int i = 0; i < n; ++i) {
		++count[a[i]];
	}


	for (int i = 1; i <= maxVal; ++i) {
		count[i] += count[i - 1];
	}


	int* output = new int[n];
	for (int i = n - 1; i >= 0; --i) {
		output[--count[a[i]]] = a[i];
	}


	for (int i = 0; i < n; ++i) {
		a[i] = output[i];
	}

	delete[] output;
	delete[] count;

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
	// Doan code duoc lay tu nguon chat gpt
}


//Insertion Sort
void compareInsertionSort(int* a, int n, long long& count_compare) {
	count_compare = 0;
	for (int i = 1; ++count_compare && i < n; i++) { //iterate through element of array from beginning to end

		int value = a[i]; // value holds value of element a[i]
		int vitri = i - 1; // vitri holds previous position of element a[i]
		while (++count_compare && vitri >= 0 && ++count_compare && a[vitri] > value) {  // this loop shifts previous element to right if it > value
			a[vitri + 1] = a[vitri];  // shifts previous element to right
			vitri--;  // update vitri to check next element
		}
		a[vitri + 1] = value;  // insert value into correct position
	}
}


void runningTimeInsertionSort(int* a, int n, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();
	for (int i = 1; i < n; i++) { //iterate through element of array from beginning to end

		int value = a[i]; // value holds value of element a[i]
		int vitri = i - 1; // vitri holds previous position of element a[i]
		while (vitri >= 0 && a[vitri] > value) {  // this loop shifts previous element to right if it > value
			a[vitri + 1] = a[vitri];  // shifts previous element to right
			vitri--;  // update vitri to check next element
		}
		a[vitri + 1] = value;  // insert value into correct position
	}
	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}






//Shell Sort
void compareShellSort(int* a, int n, long long& count_compare) {
	for (int interval = n / 2; ++count_compare && interval > 0; interval /= 2) { // loop over the intervals
		for (int i = interval; ++count_compare && i < n; i++) {
			int temp = a[i]; // temp holds the value to be compared
			int j;
			for (j = i; ++count_compare && j >= interval && a[j - interval] > temp; j -= interval) {

				a[j] = a[j - interval]; // shift element to make room for temp
			}
			a[j] = temp; // place temp in correct position
		}
	}
}


void runningTimeShellSort(int* a, int n, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();
	for (int interval = n / 2; interval > 0; interval /= 2) { // loop over the intervals
		for (int i = interval; i < n; i++) {
			int temp = a[i]; // temp holds the value to be compared
			int j;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {

				a[j] = a[j - interval]; // shift element to make room for temp
			}
			a[j] = temp; // place temp in correct position
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}
//Quick Sort
int ComparePartition(int* a, int low, int high, long long& count_compare) {
	int pivot = a[high]; // choose a last element to be the pivot
	int i = low - 1; // i holds last index of elements that less than pivot
	for (int j = low; ++count_compare && j < high; j++) { //iterates from low to high

		++count_compare;
		if (a[j] <= pivot) {  //check a[j] <= pivot
			i++;   // increase i
			swap(a[i], a[j]);  // swap element less than pivot to the left of pivot
		}

	}
	swap(a[i + 1], a[high]); // swap pivot to correct position

	return i + 1; // return position of pivot
}

int Partition(int* a, int low, int high) {
	int pivot = a[high]; // choose a last element to be the pivot
	int i = low - 1; // i holds last index of elements that less than pivot
	for (int j = low; j < high; j++) { //iterates from low to high
		if (a[j] <= pivot) { //check a[j] <= pivot
			i++; // increase i
			swap(a[i], a[j]); // swap element less than pivot to the left of pivot
		}
	}
	swap(a[i + 1], a[high]); // swap pivot to correct position
	return i + 1; // return position of pivot
}

void quickSort(int* a, int low, int high, long long& count_compare) {
	if (low < high) { //check if the subarray has more than one element
		++count_compare;
		int pi = ComparePartition(a, low, high, count_compare); // partition the array and get the pivot index
		quickSort(a, pi + 1, high, count_compare);  // recursive sort the right subarray
		quickSort(a, low, pi - 1, count_compare); // recursive sort the left subarray
	}
	else {
		++count_compare;
	}
}

void quickSortNoCompare(int* a, int low, int high) {
	if (low < high) { //check if the subarray has more than one element
		int pi = Partition(a, low, high);  // partition the array and get the pivot index
		quickSortNoCompare(a, pi + 1, high); // recursive sort the right subarray
		quickSortNoCompare(a, low, pi - 1); // recursive sort the left subarray
	}
}



void compareQuickSort(int* a, int low, int high, long long& count_compare) {
	count_compare = 0;
	quickSort(a, low, high, count_compare);
}


void runningTimeQuickSort(int* a, int low, int high, double runningTime) {
	auto start = chrono::high_resolution_clock::now();
	quickSortNoCompare(a, low, high);
	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}

//Bubble Sort
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void compareBubbleSort(int* a, int n, long long& count_compare) {
	count_compare = 0;

	for (int i = 0; ++count_compare &&  i < n - 2; i++) {
		for (int j = 0; ++count_compare && j < n - 2 - i; j++) {
			if (++count_compare && a[j + 1] < a[j]) {
				swap(a[j + 1], a[j]);
			}
		}
	}

}

void runningTimeBubbleSort(int* a, int n, double& runningTime) {

	auto start = chrono::high_resolution_clock::now();

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < n - 2 - i; j++) {
			if ( a[j + 1] < a[j]) {
				swap(a[j + 1], a[j]);
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}


// ,,,, - time

//Heap Sort


void compareHeapify(int* a, int n, int i, long long& count_compare) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (++count_compare && l < n && ++count_compare && a[l] > a[largest])
		largest = l;

	if (++count_compare && r < n && ++count_compare && a[r] > a[largest])
		largest = r;

	if (++count_compare && largest != i) {
		swap(a[i], a[largest]);
		compareHeapify(a, n, largest, count_compare);
	}
}

void compareHeapSort(int* a, int n, long long& count_compare) {
	for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
		compareHeapify(a, n, i, count_compare);

	for (int i = n - 1; ++count_compare && i > 0; i--) {
		swap(a[0], a[i]);
		compareHeapify(a, i, 0, count_compare);
	}
}

void runningTimeHeapify(int* a, int n, int i) {

	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[largest])
		largest = l;

	if (r < n && a[r] > a[largest])
		largest = r;

	if (largest != i) {
		swap(a[i], a[largest]);
		runningTimeHeapify(a, n, largest);
	}
}

void runningTimeHeapSort(int* a, int n, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();

	for (int i = n / 2 - 1; i >= 0; i--)
		runningTimeHeapify(a, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		runningTimeHeapify(a, i, 0);
	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}

// Merge Sort



void compareMerge(int* a, int left, int mid, int right, long long& count_compare) {
	int n = right - left + 1;
	int* temp = new int[n];
	int idx = 0;

	int i = left, j = mid + 1;

	while (++count_compare && i <= mid && ++count_compare && j <= right)
	{
		if (++count_compare && a[i] <= a[j])
		{
			temp[idx++] = a[i++];
		}
		else
		{
			temp[idx++] = a[j++];
		}
	}

	while (++count_compare && i <= mid)
	{
		temp[idx++] = a[i++];
	}

	while (++count_compare && j <= right)
	{
		temp[idx++] = a[j++];
	}

	for (int i = 0; ++count_compare && i < n; i++)
	{
		a[left + i] = temp[i];
	}

	delete[] temp;
}

void compareMergeSortHelper(int* a, int left, int right, long long& count_compare) {

	if (++count_compare && left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;

	compareMergeSortHelper(a, left, mid, count_compare);
	compareMergeSortHelper(a, mid + 1, right, count_compare);
	compareMerge(a, left, mid, right, count_compare);
}

void compareMergeSort(int* a, int n, long long& count_compare) {
	count_compare = 0;
	compareMergeSortHelper(a, 0, n - 1, count_compare);
}

void runningTimeMerge(int* a, int left, int mid, int right) {
	int n = right - left + 1;
	int* temp = new int[n];
	int idx = 0;

	int i = left, j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
		{
			temp[idx++] = a[i++];
		}
		else
		{
			temp[idx++] = a[j++];
		}
	}

	while (i <= mid)
	{
		temp[idx++] = a[i++];
	}

	while (j <= right)
	{
		temp[idx++] = a[j++];
	}

	for (int i = 0; i < n; i++)
	{
		a[left + i] = temp[i];
	}

	delete[] temp;
}

void runningTimeMergeSortHelper(int* a, int left, int right) {
	if (left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;

	runningTimeMergeSortHelper(a, left, mid);
	runningTimeMergeSortHelper(a, mid + 1, right);
	runningTimeMerge(a, left, mid, right);
}

void runningTimeMergeSort(int* a, int n, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();

	runningTimeMergeSortHelper(a, 0, n - 1);

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}

// Radix Sort

void compareRadixSort(int* a, int n, long long& count_compare) {

	count_compare = 0;

	int base = ceil(log10(*max_element(a, a + n) + 1));
	int exp = 1;


	for (int i = 0; ++count_compare && i < base; i++) {
		vector<vector<int>> result(10);

		for (int j = 0; ++count_compare && j < n; j++) {
			result[(a[j] / exp) % 10].push_back(a[j]);
		}
		exp *= 10;

		int index = 0;

		for (int k = 0; ++count_compare && k < 10; k++) {
			if (!result[k].empty()) {
				for (int x : result[k]) {
					a[index++] = x;
				}
			}
		}
	}
}

void runningTimeRadixSort(int *a, int n, double& runningTime) {

	auto start = chrono::high_resolution_clock::now();

	int base = ceil(log10(*max_element(a, a + n) + 1));
	int exp = 1;


	for (int i = 0; i < base; i++) {
		vector<vector<int>> result(10);

		for (int j = 0; j < n; j++) {
			result[(a[j] / exp) % 10].push_back(a[j]);
		}
		exp *= 10;

		int index = 0;

		for (int k = 0; k < 10; k++) {
			if (!result[k].empty()) {
				for (int x : result[k]) {
					a[index++] = x;
				}
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}



/*
* Idea: Basing on sorting each digit of the integer in descending or ascending, classify the elements according to each digit: units, tens, hundreds, thousands,...
* Step-by-step discription:
* - Finding out the max element, the numbers of digit is the numbers of loop.
* - Classify the elements into 2D array, save the data from 2D array to original array. Repeat until the last digit.
* Complexity: O(d(n + b)) or O(n):
* - n: number of elements.
* - b: base.
* - d: number of digit of the max element.
* This is an algorithm that executes in linear time but it is only suitable with sorting the integers.
*/



//Flash Sort

void compareFlashSort(int a[], int n, long long& count_compare) {

	count_compare = 0;

	int maxVal = *max_element(a, a + n);
	int minVal = *min_element(a, a + n);
	int dis = maxVal - minVal;

	if (minVal == maxVal) return;

	int bucket = 045 * n;
	vector<int> L(bucket, 0);

	for (int i = 0; ++count_compare && i < n; i++) {
		int k = (int)((bucket - 1) * (a[i] - minVal) / dis);
		L[k]++;
	}

	for (int i = 1; ++count_compare && i < bucket; i++) {
		L[i] += L[i - 1];
	}

	int count = 0;
	int i = 0;
	while (count < n && ++count_compare) {
		int k = int((bucket - 1) * (a[i] - minVal) / dis);
		while (i >= L[k] && ++count_compare) {
			k = int((bucket - 1) * (a[++i] - minVal) / dis);
		}
		int temp = a[i];
		while (i != L[k] && ++count_compare) {
			k = int((bucket - 1) * (a[i] - minVal) / dis);
			swap(temp, a[--L[k]]);
			++count;
		}
	}

	// Insertion sort
	for (int x = 1; ++count_compare && x < n; x++) {
		int key = a[x];
		int y = x - 1;
		while (y >= 0 && a[y] > key) {
			count_compare += 2;
			a[y + 1] = a[y];
			y--;
		}
		a[y + 1] = key;
	}
}


void runningTimeFlashSort(int* a, int n, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();

	int maxVal = *max_element(a, a + n);
	int minVal = *min_element(a, a + n);
	int dis = maxVal - minVal;

	if (minVal == maxVal) return;

	int bucket = 045 * n;
	vector<int> L(bucket, 0);

	for (int i = 0; i < n; i++) {
		int k = (int)((bucket - 1) * (a[i] - minVal) / dis);
		L[k]++;
	}

	for (int i = 1; i < bucket; i++) {
		L[i] += L[i - 1];
	}

	int count = 0;
	int i = 0;
	while (count < n) {
		int k = int((bucket - 1) * (a[i] - minVal) / dis);
		while (i >= L[k]) {
			k = int((bucket - 1) * (a[++i] - minVal) / dis);
		}
		int temp = a[i];
		while (i != L[k]) {
			k = int((bucket - 1) * (a[i] - minVal) / dis);
			swap(temp, a[--L[k]]);
			++count;
		}
	}

	// Insertion sort
	for (int x = 1; x < n; x++) {
		int key = a[x];
		int y = x - 1;
		while (y >= 0 && a[y] > key) {
			a[y + 1] = a[y];
			y--;
		}
		a[y + 1] = key;
	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}




void outputArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";

	}
	cout << endl;
}

