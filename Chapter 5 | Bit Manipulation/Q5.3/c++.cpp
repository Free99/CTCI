int next(int x) {
    int max_int = ~(1<<31);
    int num = count_one(x);
    if(num == 0 || x == -1) return -1;
    for(++x; count_one(x) != num && x < max_int; ++x);
    if(count_one(x) == num) return x;
    return -1;
}

int previous(int x) {
    int min_int = (1<<31);
    int num = count_one(x);
    if(num == 0 || x == -1) return -1;
    for(--x; count_one(x) != num && x > min_int; --x);
    if(count_one(x) == num) return x;
    return -1;
}

int count_one(int x) {
    int cnt = 0;
    for(int i = 0; i < 32; ++i) {
        if(x & 1) ++cnt;
        x >>= 1;
    }
    return cnt;
}

int next1(int x) {
    int xx = x, bit = 0;
    for(; (x&1) != 1 && bit < 32; x >>= 1, ++bit);
    for(; (x&1) != 0 && bit < 32; x >>= 1, ++bit);
    if(bit == 31) return -1; //011.., none satisfy
    x |= 1;
    x <<= bit;
    if(bit == 32) x = 0; // 11100..00
    int num1 = count_one(xx) - count_one(x);
    int c = 1;
    for(; num1 > 0; x |= c, --num1, c <<= 1);
    return x;
}

int previous1(int x) {
    int xx = x, bit = 0;
    for(; (x&1) != 0 && bit < 32; x >>= 1, ++bit);
    for(; (x&1) != 1 && bit < 32; x >>= 1, ++bit);
    if(bit ==31) return -1; //100..11, none satisfy
    x -= 1;
    x <<= bit;
    if(bit == 32) x = 0;
    int num1 = count_one(xx) - count_one(x);
    x >>= bit;
    for(; num1 > 0; x = (x<<1) | 1, --num1, --bit);
    x <<= bit;
    return x;
}
