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
/* M: 2017/08/07 15:13 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#include "bsq.h"

#include "reading.h"

void	do_the_bsq(int fd)
{
	t_map_input	*map;

	map = get_input_as_bit(fd);
	m_putnbr_base(map->specs->height, 10);
	m_putchar(map->specs->empty);
	m_putchar(map->specs->obstacle);
	m_putchar(map->specs->fill);
	m_putchar('\n');
	while (map->data)
	{
		m_putnbr_base(map->data->length, 10);
		m_putchar('\n');
		if(*map->data->part & 0b10000000)
			m_putchar(map->specs->obstacle);
		else
			m_putchar(map->specs->empty);
		m_putchar('\n');
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
