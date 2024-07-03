#include "File.h"

void ReadArrayFromFile(string fileName, int*& a, int& n) {
	ifstream ifs(fileName);

	if (!ifs) {
		cout << "Can not open the file " << endl;
		return;
	}

	ifs >> n;
	a = new int[n];


	for (int i = 0; i < n; i++) {
		ifs >> a[i];
	}

	ifs.close();


}
void WriteArrayToFile(string fileName, int* a, int n) {

	ofstream ofs(fileName);

	if (!ofs) {
		cout << "Can not open the file " << endl;
		return;
	}

	ofs << n << endl;

	for (int i = 0; i < n; i++) {
		ofs << a[i] << " ";
	}

	ofs.close();
}