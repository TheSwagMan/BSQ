/* ************************************************************************** */
/*                                                  ,---.                     */
/* bsq.c                                          ,.'-.   \                   */
/*                                               ( ( ,'"""""-.                */
/* Thomas POTIER <thomas.potier@outlook.com>     `,X          `.              */
/*                                               /` `           `._           */
/*                                              (            ,   ,_\          */
/*                                              |          ,---.,'o `.        */
/*                                              |         / o   \     )       */
/*                                               \ ,.    (      .____,        */
/*                                                  \|     ____,'     \       */
/*                                              '`'\  \        _,____,'       */
/*                                              \  ,--      ,-'     \         */
/*                                                ( C     ,'         \        */
/*                                                 `--'  .'           |       */
/*                                                   |   |         .O |       */
/*                                                  __|            ,-'_       */
/*                                                / `L     `._  _,'  ' `.     */
/*                                               /    `--.._  `',.   _\  `    */
/* C: 2017/08/04 23:44 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/07 23:30 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#include "bsq.h"

#include "reading.h"

#include <stdio.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte, c1, c2)\
	(byte & 0x80 ? c1 : c2),\
	(byte & 0x40 ? c1 : c2),\
	(byte & 0x20 ? c1 : c2),\
	(byte & 0x10 ? c1 : c2),\
	(byte & 0x08 ? c1 : c2),\
	(byte & 0x04 ? c1 : c2),\
	(byte & 0x02 ? c1 : c2),\
	(byte & 0x01 ? c1 : c2)

void	do_the_bsq(int fd)
{
	t_map_input	*map;
	int			i;
	int			c;

	map = get_input_as_bit(fd);
	m_putnbr_base(map->specs->height, 10);
	m_putchar(map->specs->empty);
	m_putchar(map->specs->obstacle);
	m_putchar(map->specs->fill);
	//m_putchar('\n');
	c = 0;
	while (map->data)
	{
		i = 0;
		while (i < map->data->length / 8)
		{
			printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(map->data->part[i], map->specs->obstacle, map->specs->empty));
			/*
			if (c++ % map->specs->width == 0)
				m_putchar('\n');
			*/
			(void)c;
			i++;
		}
		map->data = map->data->next;
	}
}

void	do_the_bsq_file(char *fn)
{
	int	fd;

	fd = open(fn, O_RDONLY);
	if (fd <= 0)
		map_error();
	do_the_bsq(fd);
	close(fd);
}

int		main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
		while (i < ac)
			do_the_bsq_file(av[i++]);
	else
		do_the_bsq(STDIN);
	return (0);
}
