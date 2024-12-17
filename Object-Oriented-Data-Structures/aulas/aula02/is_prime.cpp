#include <bits/stdc++.h>
#include "prime.h"

bool is_prime(int n){
    int d;
    if(n <= 1) return false;
    for (d = 2; d*d <= n; d++) {
        if (n%d == 0)
            return false;
    }
    return true;
}