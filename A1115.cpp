// 1115HeapPaths.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;

int n;

int binaryKeys[1005];
vector<int> trace;
const int INITIAL_HEAP = -1;
const int MAX_HEAP = 0;
const int MIN_HEAP = 1;
const int NOT_HEAP = 2;
int heapType = INITIAL_HEAP;

//从根节点开始打印路径
void printStackTrace() {
	for (unsigned int i = 0; i < trace.size(); ++i) {
		if (i) {
			cout << " ";
		}
		cout << trace[i];
	}
	cout << endl;
}

//确认堆的类型
void assureHeapType(int nowPlace) {
	if (heapType == NOT_HEAP || nowPlace * 2 > n) {
		return;
	}
	if (heapType == -1) {
		if (nowPlace * 2 + 1 <= n) {
			if (binaryKeys[nowPlace] < binaryKeys[nowPlace * 2] ||
				binaryKeys[nowPlace] < binaryKeys[nowPlace * 2 + 1]) {
				heapType = MIN_HEAP;
			}
			else if (binaryKeys[nowPlace] > binaryKeys[nowPlace * 2] ||
				binaryKeys[nowPlace] > binaryKeys[nowPlace * 2 + 1]) {
				heapType = MAX_HEAP;
			}
		}
		else {
			if (binaryKeys[nowPlace] < binaryKeys[nowPlace * 2]) {
				heapType = MIN_HEAP;
			}
			else if (binaryKeys[nowPlace] > binaryKeys[nowPlace * 2]) {
				heapType = MAX_HEAP;
			}
		}
	}
	if (heapType == MIN_HEAP) {
		if (nowPlace * 2 + 1 <= n) {
			if (binaryKeys[nowPlace] > binaryKeys[nowPlace * 2] ||
				binaryKeys[nowPlace] > binaryKeys[nowPlace * 2 + 1]) {
				heapType = NOT_HEAP;
			}
		}
		else {
			if (binaryKeys[nowPlace] > binaryKeys[nowPlace * 2]) {
				heapType = NOT_HEAP;
			}
		}
		
	}
	if (heapType == MAX_HEAP) {
		if (nowPlace * 2 + 1 <= n) {
			if (binaryKeys[nowPlace] < binaryKeys[nowPlace * 2] ||
				binaryKeys[nowPlace] < binaryKeys[nowPlace * 2 + 1]) {
				heapType = NOT_HEAP;
			}
		}
		else {
			if (binaryKeys[nowPlace] < binaryKeys[nowPlace * 2]) {
				heapType = NOT_HEAP;
			}
		}
		
	}
}

//递归打印堆
void print(int nowPlace) {
	trace.push_back(binaryKeys[nowPlace]);
	//如果没有子节点，打印路径
	if (nowPlace * 2 > n) {
		printStackTrace();
	}else {
		assureHeapType(nowPlace);
		if (nowPlace * 2 + 1 <= n) {
			print(nowPlace * 2 + 1);
		}
		print(nowPlace * 2);
	}
	trace.pop_back();
}

void printHeapType() {
	if (heapType == NOT_HEAP) {
		cout << "Not Heap" << endl;
	}
	else if (heapType == MIN_HEAP) {
		cout << "Min Heap" << endl;
	}
	else {
		cout << "Max Heap" << endl;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> binaryKeys[i];
	}
	print(1);
	printHeapType();
	return 0;
}

