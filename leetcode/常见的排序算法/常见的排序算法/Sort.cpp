#pragma once
#include "Sort.hpp"
//´òÓ¡
void print(vector<int>& nums) {
	for (int e : nums) {
		cout << e << " ";
	}
	cout << endl;
}

//Ö±½Ó²åÈëÅÅĞò
void insertSort(vector<int>& nums) {
	for (int i = 1; i < nums.size(); ++i) {
		int tmp = nums[i];
		int j = i - 1;
		while (j >=0 && tmp < nums[j]) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = tmp;
	}
}

//Ï£¶ûÅÅĞò
void shellSort(vector<int>& nums) {
	int gap = nums.size() / 2;
	while (gap >= 1) {
		for (int i = gap; i < nums.size(); ++i) {
			int tmp = nums[i];
			int j = i - gap;
			while (j >= 0 && tmp < nums[j]) {
				nums[j + gap] = nums[j];
				j -= gap;
			}
			nums[j + gap] = tmp;
		}
		gap /= 2;
	}
}

//Ñ¡ÔñÅÅĞò
void selectSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		int index = i;
		int min = nums[i];
		for (int j = i + 1; j < nums.size(); ++j) {
			if (nums[j] < min) {
				index = j;
				min = nums[j];
			}
		}
		swap(nums[i], nums[index]);
	}
}

void Adjustdown(vector<int>& nums, int parent, int size) {
	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size && nums[child + 1] > nums[child])
			child++;
		if (nums[child] > nums[parent]) {
			swap(nums[child], nums[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
	
}
//¶ÑÅÅĞò
void heapSort(vector<int>& nums) {
	for (int i = (nums.size() - 1 - 1) / 2; i >= 0; --i) {
		Adjustdown(nums, i, nums.size());
	}
	for (int i = nums.size() - 1; i >= 0; --i) {
		swap(nums[0], nums[i]);
		Adjustdown(nums, 0, i - 1);
	}
}

//Ã°ÅİÅÅĞò
void bubbleSort(vector<int>& nums) {
	for (int i = 0; i < nums.size() - 1; ++i) {
		int j = nums.size() - 1;
		while (j > i) {
			if (nums[j] < nums[j - 1])
				swap(nums[j], nums[j - 1]);
			j--;
		}
	}
}

//¿ìËÙÅÅĞò¡ª¡ªÍÚ¿Ó·¨
void digHole(vector<int>& nums, int l, int r) {
	if (l >= r)
		return;
	int left = l;
	int right = r;
	int tmp = nums[left];
	while (left < right) {
		while (left < right && tmp < nums[right]) {
			right--;
		}
		if (left < right) {
			nums[left] = nums[right];
			left++;
		}
		while (left < right && nums[left] < tmp) {
			left++;
		}
		if (left < right) {
			nums[right] = nums[left];
			right--;
		}
		
	}
	nums[left] = tmp;
	digHole(nums, l, left - 1);
	digHole(nums, left + 1, r);
} 


void quickSort(vector<int>& nums) {
	digHole(nums, 0, nums.size() - 1);
}

void merge(vector<int>& nums, int left, int right, int mid) {
	vector<int> lnums(nums.begin() + left, nums.begin() + mid + 1);
	vector<int> rnums(nums.begin() + mid + 1, nums.begin() + right + 1);
	lnums.push_back(INT_MAX);
	rnums.push_back(INT_MAX);
	//ºÏ²¢Á½¸öÓĞĞòÊı×é
	int l = 0, r = 0;
	for (int i = left; i <= right; ++i) {
		if (lnums[l] < rnums[r]) {
			nums[i] = lnums[l++];
		}
		else {
			nums[i] = rnums[r++];
		}
	}

}

//¹é²¢ÅÅĞò
void mergeSort(vector<int>& nums, int begin, int end) {
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	mergeSort(nums, begin, mid);
	mergeSort(nums, mid + 1, end);
	merge(nums, begin, end, mid);
}