//模板题，多种解法

//快速排序
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

   private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (nums.size() <= 1)
            return;
        if (left >= right)
            return;  //递归停止
        int pivot = getPivot(nums, left, right);
        quickSort(nums, left, pivot);
        quickSort(nums, pivot + 1, right);
    }
    int getPivot(vector<int>& nums, int left, int right) {
        int pivot = left + rand() % (right - left + 1);  //随机选取中轴
        int pivotVal = nums[pivot];  //获得中轴值用于后续比较
        while (left <= right) {
            while (nums[left] < pivotVal) {
                ++left;
            }
            while (nums[right] > pivotVal) {
                --right;
            }
            if (left == right) {
                break;
            }
            if (left < right) {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            }
        }
        return right;
    }
};

//归并排序
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

   private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);  //创建临时数组
        int j = left, k = mid + 1;

        //合并两个有序数组
        for (int i = 0; i < temp.size(); ++i) {
            if (k > right || (j <= mid && nums[j] < nums[k])) {
                temp[i] = nums[j++];
            } else {
                temp[i] = nums[k++];
            }
        }

        //将临时数组拷回原数组
        for (int i = 0; i < temp.size(); ++i) {
            nums[left + i] = temp[i];
        }
    }
};

//堆排序简洁版本：使用大根堆完成升序排列
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        //堆排序简洁版本
        priority_queue<int> q;  //大根堆，因此存数的时候存负的，变相小根堆
        for (int i = 0; i < nums.size(); ++i) {
            q.push(-nums[i]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = -q.top();
            q.pop();
        }
        return nums;
    }
};

//堆排序简洁版本：使用优先队列模板建立小根堆完成升序排列
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q;  //小根堆
        for (int i = 0; i < nums.size(); ++i) {
            q.push(nums[i]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = q.top();
            q.pop();
        }
        return nums;
    }
};

//堆排序，完整实现
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

   private:
    //构建堆
    void heapify(vector<int>& nums, int length, int i) {
        int left = 2 * i + 1, right = 2 * i + 2;  //构建左右叶子节点
        int largest = i;                          //构建父节点
        if (left < length && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < length && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, length, largest);
        }
    }

    void heapSort(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        int length = nums.size();

        //构建大根堆，从最后一个非叶子节点往上构建
        for (int i = length / 2 - 1; i >= 0; --i) {
            heapify(nums, length, i);
        }
        for (int i = length - 1; i >= 0; --i) {
            swap(nums[0], nums[i]);  //将当前最大的放置到数组最后
            heapify(nums, i, 0);     //将未完成的部分进行堆排序
        }
    }
};