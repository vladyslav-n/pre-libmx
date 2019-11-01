int mx_factorial_iter(int n) {
    if (n == 1 || n == 0)
        return 1;
    if (n > 1 && n < 13) 
    {
        int ans = 1;
        for (int i = 1; i <= n; i++)
            ans = ans * i;
        return ans;
    }
    else return 0;      
}

