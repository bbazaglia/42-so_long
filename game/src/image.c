/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:56:11 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 14:31:07 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <image.h>
#include <stdlib.h>

t_image  *image_push(int id, char *name)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->name = name;
	image->id = id;
	return (image);
}
