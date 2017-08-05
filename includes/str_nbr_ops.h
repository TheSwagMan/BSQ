/* ************************************************************************** */
/*                                                  ,---.                     */
/* str_nbr_ops.h                                  ,.'-.   \                   */
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
/* C: 2017/08/05 16:51 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/05 18:15 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#ifndef STR_NBR_OPS_H
# define STR_NBR_OPS_H

# include <stdlib.h>
# include "str.h"
# define BASE_CHARS	"0123456789abcdef"

int		m_atoi_base(char *str, int base);
char	*m_itoa_base(int nbr, int base);
int		nbrlen_base(unsigned int nbr, unsigned int base);

#endif
