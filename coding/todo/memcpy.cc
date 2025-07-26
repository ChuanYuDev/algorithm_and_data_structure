# include <iostream>

void * mymemcpy(void *dist, const void *src, int size){
    if (dist == nullptr || src == nullptr || size <= 0)
    {
        return nullptr;
    }

    char *pdist = nullptr;
    char *psrc = nullptr;

    if ((src < dist) && (char *)src + size > (char *)dist)
    {
        psrc = (char *)src + size - 1;
        pdist = (char *)dist + size - 1;

        while (size--)
        {
            *pdist-- = *psrc--;
        }
    }
    else
    {
        psrc = (char *)src;
        pdist = (char *)dist;

        while (size--)
        {
            *pdist++ = *psrc++;
        }
    }
    return dist;
}

int main()
{
    char src[] = "abcd";
    std::cout << sizeof(src) << std::endl;

    char *dist = (char *)malloc(sizeof(src));

    mymemcpy(dist, src, sizeof(src));
    std::cout << dist << std::endl;

    free(dist);
    
    return 0;
}