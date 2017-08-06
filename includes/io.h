/* ************************************************************************** */
/*                                                  ,---.                     */
/* io.h                                           ,.'-.   \                   */
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
/* M: 2017/08/06 17:51 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <unistd.h>
# include <sys/fcntl.h>

# include "str.h"
# include "str_nbr_ops.h"

# define STDIN	0
# define STDOUT	1
# define STDERR	2
# define BUFSIZ	1000

typedef struct	s_reading_buff
{
	int		fd;
	char	buffer[BUFSIZ];
	int		c_len;
	int		c_off;
}				t_reading_buff;


void	m_putchar(char c);
void	m_putstr(char *str);
void	m_putnbr_base(int n, int base);

#endif
