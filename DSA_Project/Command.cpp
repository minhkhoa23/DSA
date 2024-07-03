#include "Command.h"

void DisplayOutputParameters(string outputParameters, long long countCompare, double runningTime) {
	if (outputParameters == "-time") {
		cout << "Running time: " << runningTime << endl;
	}
	else if (outputParameters == "-comp") {
		cout << "Comparisions: " << countCompare << endl;
	}
	else {
		cout << "Running time: " << runningTime << endl;
		cout << "Comparisions: " << countCompare << endl;
	}
}

void CompareOrRunningTimeSortArray(int*& a, int n, string Algorithm, string outputParameters, long long& countCompare, double& runningTime) {

	if (outputParameters == "-time") {
		if (Algorithm == "selection-sort") {
			runningTimeSelectionSort(a, n, runningTime);
		}
		else if (Algorithm == "shaker-sort") {
			runningTimeShakerSort(a, n, runningTime);
		} 
		else if (Algorithm == "counting-sort") {
			runningTimeCountingSort(a, n, runningTime);
		}
		else if (Algorithm == "insertion-sort") {
			runningTimeInsertionSort(a, n, runningTime);
		}
		else if (Algorithm == "shell-sort") {
			runningTimeShellSort(a, n, runningTime);
		}
		else if (Algorithm == "quick-sort") {
			runningTimeQuickSort(a, 0, n - 1, runningTime);
		}
		else if (Algorithm == "bubble-sort") {
			runningTimeBubbleSort(a, n, runningTime);
		}
		else if (Algorithm == "heap-sort") {
			runningTimeHeapSort(a, n, runningTime);
		}
		else if (Algorithm == "merge-sort") {
			runningTimeMergeSort(a, n, runningTime);
		}
		else if (Algorithm == "radix-sort") {
			runningTimeRadixSort(a, n, runningTime);
		}
		else if (Algorithm == "flash-sort") {
			runningTimeFlashSort(a, n, runningTime);
		}
	}
	else if (outputParameters == "-comp") {
		if (Algorithm == "selection-sort") {
			compareSeLectionSort(a, n, countCompare);
		}
		else if (Algorithm == "shaker-sort") {
			compareShakerSort(a, n, countCompare);
		}
		else if (Algorithm == "counting-sort") {
			compareCountingSort(a, n, countCompare);
		}
		else if (Algorithm == "insertion-sort") {
			compareInsertionSort(a, n, countCompare);
		}
		else if (Algorithm == "shell-sort") {
			compareShellSort(a, n, countCompare);
		}
		else if (Algorithm == "quick-sort") {
			compareQuickSort(a, 0, n - 1, countCompare);
		}
		else if (Algorithm == "bubble-sort") {
			compareBubbleSort(a, n, countCompare);
		}
		else if (Algorithm == "heap-sort") {
			compareHeapSort(a, n, countCompare);
		}
		else if (Algorithm == "merge-sort") {
			compareMergeSort(a, n, countCompare);
		}
		else if (Algorithm == "radix-sort") {
			compareRadixSort(a, n, countCompare);
		}
		else if (Algorithm == "flash-sort") {
			compareFlashSort(a, n, countCompare);
		}
	}
	else {
		int* b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}

		if (Algorithm == "selection-sort") {
			compareSeLectionSort(a, n, countCompare);
			runningTimeSelectionSort(b, n, runningTime);
		}
		else if (Algorithm == "shaker-sort") {
			compareShakerSort(a, n, countCompare);
			runningTimeShakerSort(b, n, runningTime);
		}
		else if (Algorithm == "counting-sort") {
			compareCountingSort(a, n, countCompare);
			runningTimeCountingSort(b, n, runningTime);
		}
		else if (Algorithm == "insertion-sort") {
			compareInsertionSort(a, n, countCompare);
			runningTimeInsertionSort(b, n, runningTime);
		}
		else if (Algorithm == "shell-sort") {
			compareShellSort(a, n, countCompare);
			runningTimeShellSort(b, n, runningTime);
		}
		else if (Algorithm == "quick-sort") {
			compareQuickSort(a, 0, n - 1, countCompare);
			runningTimeQuickSort(b, 0, n - 1, runningTime);
		}
		else if (Algorithm == "bubble-sort") {
			compareBubbleSort(a, n, countCompare);
			runningTimeBubbleSort(b, n, runningTime);
		}
		else if (Algorithm == "heap-sort") {
			compareHeapSort(a, n, countCompare);
			runningTimeHeapSort(b, n, runningTime);
		}
		else if (Algorithm == "merge-sort") {
			compareMergeSort(a, n, countCompare);
			runningTimeMergeSort(b, n, runningTime);
		}
		else if (Algorithm == "radix-sort") {
			compareRadixSort(a, n, countCompare);
			runningTimeRadixSort(b, n, runningTime);
		}
		else if (Algorithm == "flash-sort") {
			compareFlashSort(a, n, countCompare);
			runningTimeFlashSort(b, n, runningTime);
		}

		if (Algorithm == "bubble-sort") {
			compareBubbleSort(a, n, countCompare);
			runningTimeBubbleSort(b, n, runningTime);
		}
		else if (Algorithm == "heap-sort") {
			compareHeapSort(a, n, countCompare);
			runningTimeHeapSort(b, n, runningTime);
		}
		else if (Algorithm == "merge-sort") {
			compareMergeSort(a, n, countCompare);
			runningTimeMergeSort(b, n, runningTime);
		}

		delete[] b;
	}
}
void Command1(string Algorithm, string givenInput, string outputParameters) {
	int* a;
	int n;
	long long countCompare = 0;
	double runningTime = 0;

	ReadArrayFromFile(givenInput, a, n);

	//vector<string> algorithms = {"bubble-sort","heap-sort","merge-sort" };

	CompareOrRunningTimeSortArray(a, n, Algorithm, outputParameters, countCompare, runningTime);

	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << Algorithm << endl;
	cout << "Input file: " << givenInput << endl;
	cout << "Input size: " << n << endl;
	cout << "-------------------------" << endl;

	DisplayOutputParameters(outputParameters, countCompare, runningTime);

	WriteArrayToFile("output.txt", a, n);

	delete[] a;


}

void GenerateInputData(int*& a, int n, string inputOrder) {

	a = new int[n];

	if (inputOrder == "-rand") {
		GenerateData(a, n, 0);
	}
	else if (inputOrder == "-nsorted") {
		GenerateData(a, n, 3);
	}
	else if (inputOrder == "-sorted") {
		GenerateData(a, n, 1);
	}
	else if (inputOrder == "-rev") {
		GenerateData(a, n, 2);
	}
}

string GetInputOrderDescription(string inputOrder) {

	if (inputOrder == "-rand") {
		return "Randomize";
	}
	else if (inputOrder == "-nsorted") {
		return "Nearly Sorted";
	}
	else if (inputOrder == "-sorted") {
		return "Sorted";
	}
	else if (inputOrder == "-rev") {
		return "Reversed";
	}
}

void Command2(string Algorithm, int inputSize, string inputOrder, string outputParameters) {

	int* a;
	int n = inputSize;

	long long countCompare = 0;
	double runningTime = 0;

	GenerateInputData(a, n, inputOrder);

	WriteArrayToFile("input.txt", a, n);

	CompareOrRunningTimeSortArray(a, n, Algorithm, outputParameters, countCompare, runningTime);

	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << Algorithm << endl;
	cout << "Input size: " << n << endl;
	cout << "Input order: " << GetInputOrderDescription(inputOrder) << endl;

	cout << "-------------------------" << endl;

	DisplayOutputParameters(outputParameters, countCompare, runningTime);

	WriteArrayToFile("output.txt", a, n);

	delete[] a;

}

void Command3(string Algorithm, int inputSize, string outputParameters) {
	int* a;
	int n = inputSize;

	long long countCompare = 0;
	double runningTime = 0;

	vector<string> inputOrders = { "-rand","-nsorted","-sorted","-rev" };


	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << Algorithm << endl;
	cout << "Input size: " << n << endl;


	for (int i = 0; i < inputOrders.size(); i++) {
		GenerateInputData(a, n, inputOrders[i]);

		string fileName = "input_" + to_string(i+1) + ".txt";
		WriteArrayToFile(fileName, a, n);

		CompareOrRunningTimeSortArray(a, n, Algorithm, outputParameters, countCompare, runningTime);

		cout << "Input order: " << GetInputOrderDescription(inputOrders[i]) << endl;
		cout << "-------------------------" << endl;

		DisplayOutputParameters(outputParameters, countCompare, runningTime);
		delete[] a;
		a = NULL;


		cout << endl;

	}
}

void Command4(string Algorithm1, string Algorithm2, string givenInput) {
	int* a, *b;
	int na, nb;
	long long countCompare1 = 0, countCompare2 = 0;
	double runningTime1 = 0, runningTime2 = 0;

	ReadArrayFromFile(givenInput, a, na);
	ReadArrayFromFile(givenInput, b, nb);


	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << Algorithm1 << " | " << Algorithm2 << endl;

	cout << "Input file: " << givenInput << endl;
	cout << "Input size: " << na << endl;

	cout << "-------------------------" << endl;

	CompareOrRunningTimeSortArray(a, na, Algorithm1, "-both", countCompare1, runningTime1);
	CompareOrRunningTimeSortArray(b, nb, Algorithm2, "-both", countCompare2, runningTime2);

	cout << "Running Time: " << runningTime1 << '\t' << "|  " << runningTime2 << endl;
	cout << "Comparisions: " << countCompare1 << '\t' << "|  " << countCompare2 << endl;


	delete[] a;
	delete[] b;
}

void Command5(string Algorithm1, string Algorithm2, int inputSize, string inputOrder) {
	int* a, * b;
	int na = inputSize, nb = inputSize;
	long long countCompare1 = 0, countCompare2 = 0;
	double runningTime1 = 0, runningTime2 = 0;

	GenerateInputData(a, na, inputOrder);
	b = new int[nb];

	for (int i = 0; i < nb; i++) {
		b[i] = a[i];
	}

	WriteArrayToFile("input.txt", a, na);

	CompareOrRunningTimeSortArray(a, na, Algorithm1, "-both", countCompare1, runningTime1);

	for (int i = 0; i < na; i++) {
		cout << b[i] << " ";
	}

	CompareOrRunningTimeSortArray(b, nb, Algorithm2, "-both", countCompare2, runningTime2);



	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << Algorithm1 << " | " << Algorithm2 << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "Input order: " << GetInputOrderDescription(inputOrder) << endl;
	cout << "-------------------------" << endl;


	cout << "Running Time: " << runningTime1 << '\t' << "|  " << runningTime2 << endl;
	cout << "Comparisions: " << countCompare1 << '\t' << "|  " << countCompare2 << endl;

	delete[] a;
	delete[] b;
}