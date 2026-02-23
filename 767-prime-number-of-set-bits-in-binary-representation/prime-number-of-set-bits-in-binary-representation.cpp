class Solution {
public:
    bool check_prime(int x) {
        if (x < 2) {
            return false;
        }
        if(x==2)    return true;
        if (x % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    string tobinary(int n) {
        string binary = "";
        while (n > 0) {
            binary = char((n % 2) + '0') + binary;
            n = n / 2;
        }
        return binary;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            string converted = tobinary(i);
            int count = 0;
            for (int k = 0; k < converted.length(); k++) {
                if (converted[k] == '1') {
                    count++;
                }
            }
            cout<<count;
            if (check_prime(count)) {
                ans++;
            }
        }
        return ans;
    }
};