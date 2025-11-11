/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:17:50 by juannune          #+#    #+#             */
/*   Updated: 2025/11/10 23:35:50 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t    src_len;
    size_t    dst_len;
    
    /* getting the original lenth of src and dst */
    src_len = ft_strlen(src);
    dst_len = ft_strlen(dst);
    /* this check can be ommited if you implement the strnlen function */
    if (dst_len >= dstsize)
        dst_len = dstsize;
    /* if the dst_len is equal to dst_size
     * this means that we don't need to concatenate anything since
     * the dst already contains the maximum number of characters
     */
    if (dst_len == dstsize)
        return (dstsize + src_len);
    /* if dstsize is big enough to accomodate both src and dst */
    if (src_len < dstsize - dst_len)
    /* we used ft_memcpy again, since it works directly on memory
     * addresses, we can offset the pointer of dst by dst_len so our
     * dst pointer is now set at the end of dst, then we tell ft_memcpy to
     * copy the content of src there for a maximum of src_len + 1
     * character
     */
        ft_memcpy(dst + dst_len, src, src_len + 1);
    else
    {
    /* in this case, we do the same thing as above, we offset the dst 
     * pointer by dst_len and then we copy src there
     * this time, we copy dstsize - dst_len - 1 character
     */
        ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
    /* as with ft_strlcpy, we then NUL-terminate the string */
        dst[dstsize - 1] = '\0';
    }
    /* finally, we return the original length of src + dst */
    return (dst_len + src_len);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t srclen = ft_strlen(src);
    size_t dstlen = ft_strlen(dst);

    if (dstlen >= dstsize)
        return (dstsize + srclen);

    if (srclen < dstsize - dstlen)
    {
        ft_memcpy(dst + dstlen, src, srclen + 1);
    }
    else
    {
        ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
        dst[dstsize - 1] = '\0';
    }
    return dstlen + srclen;
}
