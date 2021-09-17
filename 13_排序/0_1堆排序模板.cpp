#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 递归方式构建大根堆(length是array的长度，i是第一个非叶子节点的下标)
void heapify(vector<int>& array, int length, int i) {
    int left = 2 * i + 1, right = 2 * i + 2;  //左右子节点下标
    int largest = i;                          //父节点下标

    if (left < length && array[left] > array[largest]) {
        largest = left;
    }
    if (right < length && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, length, largest);
    }
}

void heapSort(vector<int>& array) {
    if (array.size() == 0)
        return;

    int length = array.size();

    //构建大根堆，从最后一个非叶子节点向上
    for (int i = length / 2 - 1; i >= 0; --i) {
        heapify(array, length, i);
    }

    //调整大根堆
    for (int i = length - 1; i >= 0; --i) {
        //交换算法(等价于swap(arr[0], array[i])),将当前最大的放置到数组末尾
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        //将未完成的部分继续进行堆排序
        heapify(array, i, 0);
    }
    return;
}

//简洁实现，非最优实现
// 升序队列，小顶堆
// priority_queue <int,vector<int>,greater<int> > q;
// 降序队列，大顶堆
// priority_queue <int,vector<int>,less<int> >q;
void heapSort2(vector<int>& array) {
    int length = array.size();
    priority_queue<int> q;
    for (int i = 0; i < length; ++i) {
        q.push(-array[i]);
    }
    for (int i = 0; i < length; ++i) {
        array[i] = -q.top();
        q.pop();
    }
}

int main() {
    vector<int> nums = {3, 2, 4, 5, 6, 2, 9, 12, 1};
    vector<int> nums2 = {3, 2, 4, 5, 6, 2, 9, 12, 1};
    for (auto& num : nums)
        cout << num << ' ';
    cout << endl;
    heapSort(nums);
    for (auto& num : nums)
        cout << num << ' ';
    cout << endl;
    heapSort(nums2);
    for (auto& num : nums2)
        cout << num << ' ';
    cout << endl;
}