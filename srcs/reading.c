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
/* M: 2017/08/06 21:03 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
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

int			get_map(t_reading_buff *b, t_map_input *map)
{
	if (!get_map_spec(b, map))
		return (0);
	while (b->c_len)
	{
		map->data->length = b->c_len - b->c_off;
		if (!(map->data->part = malloc(map->data->length / 8 + 1)))
			exit(ERROR_MALLOC);
		while (b->c_off < b->c_len)
		{
			map->data->part[b->c_off / 8] <<= 1;
			if (b->buffer[b->c_off] == map->specs->obstacle)
				map->data->part[b->c_off / 8] |= 1;
			else if (b->buffer[b->c_off] == map->specs->empty)
				map->data->part[b->c_off / 8] |= 0;
			else
				return (0);
			map->data = map->data->next;
			b->c_off++;
		}
		if ((b->c_len = read(b->fd, b->buffer, BUFSIZ)) < 0)
			exit(ERROR_READ);
	}
	return (1);
}
