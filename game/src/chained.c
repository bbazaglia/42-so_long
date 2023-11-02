/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:21:08 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 14:20:00 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <chained.h>
#include <stdlib.h>

t_chained *chained_push(void *data)
{
    t_chained    *set;

    set = (t_chained *)malloc(sizeof(t_chained));
    set->data = data;
    set->next = NULL;
    return (set);
}

void     chained_next_first(t_chained **head, t_chained *set)
{
    if (!set)
        return;
    set->next = *head;
    *head = set;        
}

void    chained_next_last(t_chained **tail, t_chained *set)
{
    t_chained    *upd;

    if (!*tail)
    {
        *tail = set;
        return ;
    }
    upd = *tail;
    while (upd->next)
        upd = upd->next;
    upd->next = set;
}
