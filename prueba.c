#include "libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    char *res;
    int i;
    int j;
    
    i = 0;
    j = 0;
    /* allocating the required memory */
    res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!res)
        return (NULL);
    /* copying s1 into our res string */
    while (s1[i])
        res[j++] = s1[i++];
    /* we have to reset i to 0, otherwise we won't copy s2
     * from the start
     */
    i = 0;
    /* copying s2 into our res string */
    while (s2[i])
        res[j++] = s2[i];
    /* !! don't forget to NUL-terminate the string !! */
    res[j] = 0;
    /* finallly, we can return the new string */
    return (res);
}