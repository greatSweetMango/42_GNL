/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:39:44 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/16 17:07:17 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew(int fd)
{
	t_list	*rv_lst;

	rv_lst = (t_list *)malloc(sizeof(t_list));
	rv_lst -> fd = fd;
	rv_lst -> buf = NULL;
	rv_lst -> next = NULL;
	rv_lst -> read_flag = 1;
	rv_lst -> node_flag = 1;
	return (rv_lst);
}

void	ft_lstdelone(t_list **head, t_list *node, t_list *pre_node)
{
	if (*head == node)
	{
		*head = node->next;
		if (node)
			free(node);
		node = NULL;
	}
	else
	{
		pre_node->next = node->next;
		if (node)
		{
			free(node);
			node = NULL;
		}
	}
}

char	*get_line(t_list *file)
{
	long long	i;
	char		*line;
	char		*temp;

	if (!(file->buf[0]) && !file->read_flag)
	{
		file->node_flag = 0;
		free(file->buf);
		file->buf = NULL;
		return (NULL);
	}
	if (!(ft_strchr(file->buf, '\n')))
	{
		file->node_flag = 0;
		return (ft_strjoin(file->buf, "", 1));
	}
	line = (char *)ft_calloc(ft_strlen(file->buf, '\n') + 2, sizeof(char));
	i = -1;
	while (++i <= (long long)ft_strlen(file->buf, '\n'))
		line[i] = file->buf[i];
	temp = ft_strjoin(&(file->buf[i]), "", 0);
	if (file->buf)
		free(file->buf);
	file->buf = temp;
	return (line);
}

void	read_buf(t_list *file)
{
	char	*str;
	int		bytes;

	if (!file->read_flag || !file)
		return ;
	str = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (file->node_flag && !(file->buf))
		file->buf = (char *)ft_calloc(1, 1);
	while (!ft_strchr(file->buf, '\n'))
	{
		bytes = read(file->fd, str, BUFFER_SIZE);
		if (bytes <= 0)
		{
			file->read_flag = 0;
			break ;
		}
		str[bytes] = '\0';
		file->buf = ft_strjoin(file->buf, str, 1);
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	t_list			*pre_node;
	char			*line;

	if (!head)
		head = ft_lstnew(fd);
	node = head;
	while (node)
	{
		if (node->fd == fd)
			break ;
		pre_node = node;
		node = node->next;
	}
	if (!node)
	{
		node = ft_lstnew(fd);
		pre_node->next = node;
	}
	read_buf(node);
	line = get_line(node);
	if (!(node->node_flag))
		ft_lstdelone(&head, node, pre_node);
	return (line);
}
