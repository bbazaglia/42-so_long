#include <game.h>
#include <image.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum e_image{
    BACKGROUND_CUTE,
    FLOWER_1,
    FLOWER_2,
    FLOWER_3,
    FLOWER_4
}t_id;

int main(void)
{
    t_game  game;
    int     i;
    t_image *image;

    game_set(&game);

    game.image_next_last(&game, image_push(BACKGROUND_CUTE, "background cute"));
    game.image_next_last(&game, image_push(FLOWER_1, "Flower 1"));
    game.image_next_last(&game, image_push(FLOWER_2, "Flower 2"));
    game.image_next_last(&game, image_push(FLOWER_3, "Flower 3"));
    game.image_next_last(&game, image_push(FLOWER_4, "Flower 4"));
    image = game.image_search(&game, FLOWER_4);
    game.image_print(&game);
    game.pop(&game);
    return (0);
}