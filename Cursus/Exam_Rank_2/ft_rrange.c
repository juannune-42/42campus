
#include <stdlib.h>

int *ft_rrange(int  start, int  end)
{
    int i = 0;
    int range = (end - start) < 0 ? 
        ((end -start) * -1) + 1 : (end- start) + 1;
    int *array = (int *) malloc(range * sizeof(int));
    if (!array)
        return (NULL);
    while (i < range)
    {
        if (end < start)
            array[i] = end++;
        else
            array[i] = end--;
        i++;
    }
    return (array);
}
