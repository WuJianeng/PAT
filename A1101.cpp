// 1101QuickSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
using namespace std;

int N;
const int MAX = 100050;
int seq[MAX];
int sortedArray[MAX];
bool flag[MAX] = { false};

void print() {
	for(int i = 0; i < N; ++i) {
		if (seq[i] == sortedArray[i])
			flag[i] = true;
		else
			flag[i] = false;
	}
	//剔除小于左边任一数的元素
	int leftMax = 0;
	for (int i = 0; i < N; ++i) {
		if (flag[i] && seq[i] < leftMax)
			flag[i] = false;
		leftMax = seq[i] > leftMax ? seq[i] : leftMax;
	}
	//剔除大于右边任一数的元素，并计数
	int rightMin = 10e9 + 10;
	int count = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (flag[i] && seq[i] > rightMin)
			flag[i] = false;
		if (flag[i]) count++;
		rightMin = seq[i] < rightMin ? seq[i] : rightMin;
	}	
	cout << count << endl;
	for (int i = 0; i < N; ++i) {
		if (flag[i]) {
			count--;
			cout << seq[i];
			if (count)cout << " ";
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> seq[i];
	}
	for (int i = 0; i < N; ++i)
		sortedArray[i] = seq[i];
	sort(sortedArray, sortedArray + N);	
	print();
	cout << endl;
	return 0;
}

