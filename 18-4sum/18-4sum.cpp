class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> res;
        if (a.empty()){
            return res;
        }
        sort(a.begin(),a.end());
        for (int i = 0; i < a.size(); i++) {
            long long target_3 = (long long)target - (long long)a[i];
            for (int j = i + 1; j < a.size(); j++) {
                long long target_2 = target_3 - (long long)a[j];
                int front = j + 1;
                int back = a.size() - 1;
                while (front < back) {
                    int two_sum = a[front] + a[back];
                    if (two_sum < target_2) front++;
                    else if (two_sum > target_2) back--;
                    else {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = a[i];
                        quadruplet[1] = a[j];
                        quadruplet[2] = a[front];
                        quadruplet[3] = a[back];
                        res.push_back(quadruplet);
                        // Processing the duplicates of number 3
                        while (front < back && a[front] == quadruplet[2]) ++front;
                        // Processing the duplicates of number 4
                        while (front < back && a[back] == quadruplet[3]) --back;
                    }
                }
                // Processing the duplicates of number 2
                while (j + 1 < a.size() && a[j + 1] == a[j]) ++j;
            }
            // Processing the duplicates of number 1
            while (i + 1 < a.size() && a[i + 1] == a[i]) ++i;
        }
        return res;
    }
};