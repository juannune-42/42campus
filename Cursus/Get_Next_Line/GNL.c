/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 04:35:21 by juannune          #+#    #+#             */
/*   Updated: 2026/02/07 03:42:50 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"

#include    <stdio.h>
#include    <fcntl.h>

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}

char *get_next_line(int fd)
{
    static char stash;
    char    *line;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    stash = read_to_stash(fd, stash);
    if (!stash)
        return NULL;
    line = extract_line(stash);    
    if (line)
        stash = update_stash(stash);
    else
    {
        free(stash);
        stash = NULL;
    }
    return NULL;
}

char    *read_to_stash(int fd, char *stash)
{
    char *buffer;
    ssize_t bytes_read;
    
    buffer = malloc (BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    if(!stash)
        stash = ft_strup ("");
    if (!stash)
        return (free(buffer), NULL);
    bytes_read = 1;
    While (!ft_strchr(stash, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            return (free(buffer), free(stash), NULL);
        if (bytes_read == 0)
            return (free(buffer), stash)
        buffer[bytes_read] = '\0';
        stash = append_to_stash(stash, buffer);
        if (!stash)
            return (free(buffer), NULL)
    }
    return(free(buffer, stash));
}
