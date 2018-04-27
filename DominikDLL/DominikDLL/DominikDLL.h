#pragma once
// __declspec(dllexport) before class name means that we want to export the whole class to be available in dll
// but you can also add this before public methods if you want to specify
extern "C" {
	int __declspec(dllexport) DominikDLL_sum(int a, int b);
}