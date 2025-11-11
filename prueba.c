
#include "libft.h"

char *ft_strdup(const char *s1)
{
    char *dest;
    size_t i;
    
    /* allocating enough memory for s1 + 1 character
     * for the NUL-terminating character
     */
    dest = (char *) malloc(ft_strlen(s1) + 1);
    if (!dest)
        return (NULL);
    i = 0;
    /* looping over the whole s1 string */
    while (s1[i])
    {
        /* copying the current s1 character into the same
         * position in the dest string we allocated above
         */
        dest[i] = s1[i];
        i++;
    }
    /* setting the NUL-terminating character */
    dest[i] = 0;
    /* finally, we return the newly created string */
    return (dest);
}