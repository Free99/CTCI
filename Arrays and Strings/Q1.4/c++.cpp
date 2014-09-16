// 变位词的组成字符是一样的，所以按照字典排序两个字符串也就相等了。 因此我们可以用O(nlongn)的时间去排序，然后比较。

bool isAnagram1(string s, string t) {
    if (s == "" || t == "") return false;
    if (s.length() != t.length()) return false;

    sort(&s[0], &s[0] + s.length());
    sort(&t[0], &t[0] + t.length());
    if (s == t) return true;
    else return false;
}

// 统计每个词出现的次数，然后看这两个字符串中字符数是否一样。
// 先开一个辅助数组来保存各字符出现次数。我们可以开一个大小为256的
// 整数数组，遍历第一个字符串时，将相应字符出现的次数加1；
// 遍历第二个字符串时，将相应字符出现的次数减1。
// 最后如果数组256个数都为0，说明两个字符串是变位词。

bool isAnagram(string s, string t) {
    if (s == "" || t == "") return false;
    if (s.length() != t.length()) return false;
    
    int len = s.length();
    int c[256];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < len; ++i) {
        ++c[(int) s[i]];
        --c[(int) t[i]];
    }
    for (int i = 0; i < 256; ++i) 
        if (c[i] != 0) return false;
    return true;
}
