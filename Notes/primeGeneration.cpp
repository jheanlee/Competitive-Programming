#include <vector>
#include <iostream>

using namespace std;


//better in both time and memory under lifetime circumstances
void eratosthenesSieve (int sieveLimit, vector<int> &primesResult) {
  vector<bool> isPrime(sieveLimit + 1, true);

  for (int i = 2; i <= sieveLimit; i++) {
    if (isPrime[i]) {
      primesResult.push_back(i);

      for (int j = i; j <= sieveLimit; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

void linearSieve (int sieveLimit, vector<int> &primesResult) {
  vector<int> lpf(sieveLimit + 1, 0);

  for (int i = 2; i < sieveLimit; i++) {
    if (lpf[i] == 0) {
      primesResult.push_back(i);
      lpf[i] = i;
    }

    for (int p : primesResult) {
      if (i * p >= sieveLimit) {break;}
      lpf[i * p] = p;

      if (i % p == 0) {break;}
    }
  }
}
