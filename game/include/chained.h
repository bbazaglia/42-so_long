/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:20:32 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 14:16:43 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINED_H
# define CHAINED_H

typedef struct s_chained{
    void                *data;
    struct s_chained   *next;   
}t_chained;

extern t_chained   *chained_push(void *data);
extern void         chained_next_first(t_chained **head, t_chained *set);
extern void         chained_next_last(t_chained **tail, t_chained *set);
extern void         chained_pop(t_chained **set, void (*pop)(void **data));

#endif