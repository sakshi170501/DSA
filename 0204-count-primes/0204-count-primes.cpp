class Solution {
public:
    int countPrimes(int n) {

        vector<bool> sieve(n, true);

        if (n <= 2)
            return 0;

        sieve[0] = sieve[1] = false;

        for (int i = 2; i * i < n; i++) {

            if (sieve[i] == true) {

                int j = i * i;

                while (j < n) {
                    sieve[j] = false;
                    j += i;
                }
            }
        }

        return count(sieve.begin(), sieve.end(), true);
    }
};