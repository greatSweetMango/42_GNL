/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:40:21 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/16 16:42:34 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				fd;
	char			*buf;
	struct s_list	*next;
	int				read_flag;
	int				node_flag;
}	t_list;

char	*get_next_line(int fd);
void	read_buf(t_list *file);
char	*get_line(t_list *file);
t_list	*ft_lstnew(int fd);
void	ft_lstdelone(t_list **head,
			t_list *node,
			t_list *pre_node);
size_t	ft_strlen(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2, int need_free);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcpy(char *dst,
			const char *src,
			size_t dstsize);

#endif
