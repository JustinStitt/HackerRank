class Solution {
public:
    
    int countPrimes(int n) {
        if(n < 1) return 0;
        
        vector<bool> primes(n, 1); // O(n) space
        
        primes[0] = 0;
        primes[1] = 0;
        
        for(int x = 2; x*x < n; ++x) {
            if(!primes[x]) continue; // dont consider
            
            int c = 2;
            while(x*c < n) {
                primes[x*c++] = 0;
            } // end while
        } // end for
        
        /* linearly count all remaining primes */
        int count{};
        for(int x{}; x < n; ++x) {
            count += primes[x];
        }
        return count;
    } // end countPrimes

}; // end Solution

/*
    sieve of erasthosnes
    start at 2
    if prime, remove all multiples of it from vector
    else skip
*/
