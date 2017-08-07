/* ************************************************************************** */
/*                                                  ,---.                     */
/* reading.c                                      ,.'-.   \                   */
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
/* C: 2017/08/04 23:37 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/07 23:32 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#include "reading.h"

t_map_input	*get_input_as_bit(int fd)
{
	t_map_input		*map;
	t_reading_buff	*buf;

	if (!(buf = malloc(sizeof(*buf))))
		exit(ERROR_MALLOC);
	buf->c_off = 0;
	buf->fd = fd;
	if (!(map = malloc(sizeof(*map))))
		exit(ERROR_MALLOC);
	if (!(map->specs = malloc(sizeof(*(map->data)))))
		exit(ERROR_MALLOC);
	if (!(map->data = malloc(sizeof(*(map->data)))))
		exit(ERROR_MALLOC);
	get_map(buf, map);
	return (map);
}

int			get_map_spec(t_reading_buff *buf, t_map_input *map)
{
	if ((buf->c_len = read(buf->fd, buf->buffer, BUFSIZ)) < 0)
		exit(ERROR_READ);
	while (buf->c_off < buf->c_len
			&& buf->buffer[buf->c_off] != '\n')
		buf->c_off++;
	map->specs->height = 0;
	if (buf->buffer[buf->c_off] == '\n' && buf->c_off >= 4)
	{
		map->specs->fill = buf->buffer[buf->c_off - 1];
		map->specs->obstacle = buf->buffer[buf->c_off - 2];
		map->specs->empty = buf->buffer[buf->c_off - 3];
		map->specs->height = m_simple_atoi_n(buf->buffer, buf->c_off - 3);
	}
	if (map->specs->height <= 0)
		return (0);
	return (1);
}

int			check_char(char c, t_map_input *map)
{
	if (c == map->specs->obstacle || c == map->specs->empty || c == '\n')
		return (1);
	return (0);
}

int			get_map(t_reading_buff *b, t_map_input *map)
{
	char	*tmp;
	int		tmp_len;
	int		b_off;

	if (!get_map_spec(b, map))
		return (0);
	b_off = b->c_off;
	while (b->c_len)
	{
		b_off = b->c_off;
		tmp_len = b->c_len - b->c_off;
		if (!(tmp = malloc((tmp_len / 8 + 1) * sizeof(*tmp))))
			exit(ERROR_MALLOC);
		while (b->c_off < b->c_len)
		{
			if (check_char(b->buffer[b->c_off], map))
			{
				if (b->buffer[b->c_off] == map->specs->obstacle)
					tmp[(b->c_off - b_off) / 8] |= 1;
			}
			else
				return (0);
			tmp[(b->c_off - b_off) / 8] <<= 1;
			b->c_off++;
		}
		tmp[b->c_off / 8] <<= 8 - (b->c_len % 8);
		if ((b->c_len = read(b->fd, b->buffer, BUFSIZ)) < 0)
			exit(ERROR_READ);
		b->c_off = 0;
		lida_push_back(&(map->data), tmp, tmp_len);
	}
	return (1);
}
