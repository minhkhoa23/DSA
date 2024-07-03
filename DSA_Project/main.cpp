#include "Sort.h"   
#include "DataGenerator.h"
#include "File.h"		
#include "Check.h"
#include <chrono>
#include <vector>
#include "Command.h"

//int main() {
//	/*int* a;
//	int n = 10000;
//	long long countCompare = 0;
//	double runningTime = 0;
//
//	a = new int[n];
//
//	GenerateRandomData(a, n);
//	WriteArrayToFile("input.txt", a, n);
//	BubbleSort(a, n, countCompare, runningTime);
//
//	cout << "Running Time: " << runningTime << endl;
//	cout << "Compare: " << countCompare << endl;
//	outputArray(a, n);*/
//
//
//
//	int* a;
//	int n;
//
//	ReadArrayFromFile("input.txt", a, n);
//
//	cout << n;
//
//	//outputArray(a, n);
//
//
//	delete[] a;
//
//}

//#include <iostream>

int main(int argc, char* argv[]) {

    cout << "Number of command line arguments: " << argc << endl;

    if (argc < 5) {
        cout << "Error: Not enough command-line arguments." << endl;
        cout << "Command 1: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]" << endl;
        cout << "Command 2: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]" << endl;
        cout << "Command 3: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]" << endl;
        cout << "Command 4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]" << endl;
        cout << "Command 5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]" << endl;
        return 1;
    }

    for (int i = 0; i < argc; ++i) {
        cout << "Argument " << i << ": " << argv[i] << endl;
    }

    if (string(argv[1]) == "-a" && checkAlgorithm(string(argv[2]))) {
        if (argc == 6) {
            if (isInteger(string(argv[3])) && checkDataOrder(string(argv[4])) && checkOutputParameters(string(argv[5]))) {
                Command2(string(argv[2]), stoi(argv[3]), string(argv[4]), string(argv[5]));
                return 0;
            }
            else {
                return 1;
            }
        }
        else if (argc == 5) {
            if (checkOutputParameters(string(argv[4]))) {
                if (isInteger(string(argv[3]))) {
                    Command3(string(argv[2]), stoi(argv[3]), string(argv[4]));


                    return 0;
                }
                if (isFormatFile(string(argv[3]))) {
                    //Command 1

                    Command1(string(argv[2]), string(argv[3]), string(argv[4]));

                    return 0;
                }
            }

            return 1;
        }
        else {
            return 1;
        }
    }
    else if (string(argv[1]) == "-c" && checkAlgorithm(string(argv[2])) && checkAlgorithm(string(argv[3]))) {
        if (argc == 5) {
            if (isFormatFile(string(argv[4]))) {
                Command4(string(argv[2]), string(argv[3]), string(argv[4]));
                return 0;
            }
            return 1;
        }
        else if (argc == 6) {
            if (isInteger(string(argv[4])) && checkDataOrder(string(argv[5]))) {
                //Command 5
                cout << 1;
                Command5(string(argv[2]), string(argv[3]), stoi(argv[4]), string(argv[5]));
                return 0;
            }

            return 1;
        }
        
    }
    else {
        cout << "Error" << endl;
    }

    return 0;
}




