// we'cant have a == b
void swap(char &a, char &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void reverse1(char *s) {
    if (!s) return;
    char *p = s, *q = s;
    while (*q) ++q; // find the end
    --q; // set one char back, since we have null at the end.
    while (p < q) swap(*p++, *q--);
}

void reverse2(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; ++i)
        swap(s[i], s[n-i-1]);
}
