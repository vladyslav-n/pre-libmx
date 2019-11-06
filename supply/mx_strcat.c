int mx_strlen(const char *s);

char *mx_strcat(char *s1, const char *s2) 
{
    const int size1 = mx_strlen(s1);
    const int size2 = mx_strlen(s2);

    for (int i = 0; i <= size2; i++)
        s1[size1 + i] = s2[i];
    return s1;
}

