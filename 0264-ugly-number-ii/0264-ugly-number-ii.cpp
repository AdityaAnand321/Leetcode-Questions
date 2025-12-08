class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n + 1);
        
        int i2 = 1, i3 = 1, i5 = 1;

        arr[1] = 1;

        for (int i = 2; i <= n; i++) {
            int i2un = arr[i2] * 2;
            int i3un = arr[i3] * 3;
            int i5un = arr[i5] * 5;

            int min_un = min({i2un, i3un, i5un});

            arr[i] = min_un;

            if (min_un == i2un) i2++;
            if (min_un == i3un) i3++;
            if (min_un == i5un) i5++;
        }
        return arr[n];
    }
};
