# include <iostream>

int mystrcmp(const char *s1, const char *s2)
{
    int ret = 0;

    // unsigned for char comparison, if any difference, ret will not be 0, then exit loop
    while (!(ret = *(unsigned char *)s1 - *(unsigned char *)s2) && *s1)
    {
        s1++;
        s2++;
    }

    if (ret < 0)
    {
        return -1;
    }
    else if (ret > 0)
    {
        return 1;
    }

    return 0;
}

int main()
{
    char s1[] = "abc";
    char s2[] = "abc";

    std::cout << mystrcmp(s1, s2) << std::endl;
    return 0;
}