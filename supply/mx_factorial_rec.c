int mx_factorial_rec(int n) {
    if (n == 1 || n == 0)
        return 1;
    if (n > 1 && n < 13) 
        return mx_factorial_rec(n-1) * n;
    else return 0;
}
