/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:21:08 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/03 11:40:45 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

/* create a new node and push it to the front (head) of the linked list
returns a pointer to the newly created node 
can be used when you have a pointer to the new data
-> data stores an object or an image
*/
t_chained *chained_push(void *data)
{   
    t_chained    *set;
    set = (t_chained *)malloc(sizeof(t_chained));
    set->data = data;
    set->next = NULL;
    return (set);
}

/* add a node to the beginning of the linked list
directly updates the head pointer and doesn't return anything
*/
void     chained_next_first(t_chained **head, t_chained *set)
{
    if (!set)
        return;
    set->next = *head;
    *head = set;        
}

// add a node to the end of the linked list
void    chained_next_last(t_chained **tail, t_chained *set)
{
    t_chained    *upd;

    // if the list is empty, set the tail to the new node
    if (!*tail)
    {
        *tail = set;
        return ;
    }
    upd = *tail;
    // if the list is not empty, find the last node and add the new node to it
    while (upd->next)
        upd = upd->next;
    upd->next = set;
}
