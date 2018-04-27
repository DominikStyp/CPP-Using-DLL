# CPP-Using-DLL
C++: Making DLL library and using dynamically load it into the project
This contains 2 separate projects:
- ConsoleApplication1 (which invokes compiled DominikDLL.dll file)
- DominikDLL (which is DLL library)

# ConsoleApplication1 
- useDLL.cpp  - this file contains simple C++ code:
```C++
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
```
which loads library via: 
```C++
HINSTANCE dll = LoadLibrary(L"DominikDLL.dll");
```
and extracts <b>DominikDLL_sum</b> function from this library.
```C++
DominikDLL_sum func = (DominikDLL_sum)GetProcAddress(dll, "DominikDLL_sum");
```

# DominikDLL 
- DominikDLL.cpp  - wchich contains implementation of the DLL library functions
```C++
#include "DominikDLL.h"
extern "C" {
	int DominikDLL_sum(int a, int b) {
		return a + b;
	}
}
```
- DominikDLL.h - which contains functions definitions
```C++
#pragma once
// __declspec(dllexport) before class name means that we want to export the whole class to be available in dll
// but you can also add this before public methods if you want to specify
extern "C" {
	int __declspec(dllexport) DominikDLL_sum(int a, int b);
}
```
Where ``` __declspec(dllexport) ``` specifies which functions/classes you want to export from this library
In Debug folder are compiled and builded files ready to run under Windows.
Open this project via <b>DominikDLL.sln</b> Visual Studio Solution file.
