/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso- <nalonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 07:21:01 by nalonso-          #+#    #+#             */
/*   Updated: 2020/01/17 08:48:45 by nalonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

# define BUF_SIZE 10 // we set a small buf so the heap is not overloaded -> selon le subject il doit marcher avec des different valeurs dès 1 jusqu'à 10^7 et 9999 ¿raison?

int		get_next_line(int fd, char **line)
{
	int ret;
	char buf;
	char str;

	str = (const char *)*line;
	buf = [BUF_SIZE + 1];
	fd = open("42", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR); // lee y escribe, crea si no existe, writes as appenx after last byte, read and write perms 
	if (fd == -1)
	{
		ft_putstr("open() failed\n"); // checks the fd for errors when opening
		return (1);
	}
	ft_putnbr_fd(fd); // prints the number of bytes that have been read for fd -> Now we can manipulate file by using this result for fd value
	ret = read(fd, buf, BUF_SIZE); // read as many bytes as BUF_SIZE and stores what has been read in buf -> WATCH OUT! We need to read line by line selon le subject!
	while (ret) //while read != 0
	{
		buf[ret] = '\0'; // adds '\0' at the end of string, that's why BUF + 1
		ft_putnbr_fd(ret); //prints fd value
		ft_putstr_fd(buf); // prints what has been read
	}
	ft_putnbr_fd(ret); //this output should print zero (0)
	write(fd, ft_putstr(*line), ft_strlen(*line)); //to print string ¿?¿?¿?¿?¿?¿?
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n"); //checks the fd for errors when closing
		return (1);
	}
	return (0);
}

int		main ()
{
    int		fd;
	char	**line[10] = "bla bla";

	get_next_line(fd, **line);
	return (0);
}