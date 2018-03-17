long long int inverseNumber(int num) {

            int MOD=1000003;
            // Inverse modulo : https://en.wikipedia.org/wiki/Modular_multiplicative_inverse
            // Calculate num ^ MOD-2  % MOD
            long long int ans = 1, base = (long long) num;
            long long power = MOD - 2;
            while (power > 0) {
                if (power == 1) {
                    return (ans * base) % MOD;
                }
                if (power % 2 == 0) {
                    base = (base * base) % MOD;
                    power /= 2;
                } else {
                    ans = (ans * base) % MOD;
                    power--;
                }
            }
            return ans;
        }
