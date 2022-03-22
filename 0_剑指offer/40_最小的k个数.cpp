// 快排
class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        this->k = k;
        quickSort(arr, 0, arr.size() - 1);
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(arr[i]);
        }
        return ans;
    }

   private:
    void quickSort(vector<int>& arr, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) >> 1;
        int val = arr[mid];
        int i = l, j = r;
        while (i <= j) {
            while (arr[i] < val)
                ++i;
            while (arr[j] > val)
                --j;
            if (i >= j)
                break;
            if (i < j) {
                swap(arr[i++], arr[j--]);
            }
        }
        if (j < k) {
            quickSort(arr, j + 1, r);
        } else {
            quickSort(arr, l, j);
        }
    }
    vector<int> ans;
    int k;
};

// 堆排序
class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> q;
        for (int i = 0; i < k; ++i) {
            q.push(arr[i]);
        }
        for (int i = k; i < arr.size() && !q.empty(); ++i) {
            if (arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};
