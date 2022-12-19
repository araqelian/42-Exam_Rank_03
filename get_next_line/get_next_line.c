/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:18:13 by darakely          #+#    #+#             */
/*   Updated: 2022/11/27 12:52:13 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*ptr = malloc(10000);
	char	*copy_ptr = ptr;
	if (BUFFER_SIZE == 1)
	{
		while ((read(fd, copy_ptr, BUFFER_SIZE) > 0) && *copy_ptr++ != '\n')
			;
	}
	else
	{
		while ((read(fd, copy_ptr, 1) > 0) && *copy_ptr++ != '\n')
			;
	}
	if (copy_ptr > ptr)
	{
		copy_ptr = 0;
		return ptr;
	}
	free(ptr);
	return 0;
}
