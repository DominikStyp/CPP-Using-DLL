#include <Windows.h>
#include <iostream>

using namespace std;
typedef int(*DominikDLL_sum)(int, int);

int main() {
	HINSTANCE dll = LoadLibrary(L"DominikDLL.dll");
	if (dll == NULL) {
		cout << "Can't load DLL library";
		cin.get();
		return 0;
	}
	else {
		// using DLL object
		DominikDLL_sum func = (DominikDLL_sum)GetProcAddress(dll, "DominikDLL_sum");
		if (!func) {
			cout << "ERROR! Can't resolve function DominikDLL_sum";
			cin.get();
		    return 0;
		}
		int sumResult = func(100, 11);
		cout << "Sum 100 + 11 = " << sumResult;
		cin.get();
	}
	return 0;
}