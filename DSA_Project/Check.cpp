#include "Check.h"

bool isInteger(string str) {

	for (int i = 0; i < str.size(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}

	return true;
}

bool isFormatFile(string str) {
	const char* c_str = str.c_str();
	const char* pch = strchr(c_str, '.');

	if (pch == nullptr || pch == c_str || *(pch + 1) == '\0') {
		return false;
	}

	if (strcmp(pch + 1, "txt") == 0) {
		return true;
	}
	return false;
}

bool checkAlgorithm(string token) {

	vector<string> algorithms = { "selection-sort", "shaker-sort", "counting-sort", "insertion-sort", "shell-sort", "quick-sort", "bubble-sort","heap-sort","merge-sort", "radix-sort", "flash-sort" };

	for (int i = 0; i < algorithms.size(); i++) {
		if (token == algorithms[i]) {
			return true;
		}
	}

	return false;
}

bool checkDataOrder(string token) {

	vector<string> dataOrder = { "-rand","-nsorted","-sorted","-rev" };

	for (int i = 0; i < dataOrder.size(); i++) {
		if (token == dataOrder[i]) {
			return true;
		}
	}

	return false;
}

bool checkOutputParameters(string token) {
	vector<string> outputParameters = { "-time","-comp","-both" };

	for (int i = 0; i < outputParameters.size(); i++) {
		if (token == outputParameters[i]) {
			return true;
		}
	}

	return false;

}