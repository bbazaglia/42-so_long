<h1 align="center">
	🎮 so_long
</h1>

![So long](<gamescreenshot.png>)

## 💡 About the project

This project is a very small 2D game using the graphic library provided by CODAM: [MLX42](https://github.com/codam-coding-college/MLX42).

Its purpose is to make you work with textures, sprites, and some other basic gameplay elements.

## 📋 Testing

To compile, go to the project path and run:

```shell
$ make bonus 
```

Then, execute the program passing a map file as an argument. 

```shell
$ ./so_long_bonus bonus_map.ber
```

<strong>How to play?</strong>

- Move the player using arrows

- Press ESC to exit the game

- Press'E' to open the door (after all crystals are collected)

##  👾 Some versions of this code

In the "source" directory, I provided my first version of the code.
I didn't update it because it was nice to realize how much I improved during the project.

In the "bonus" directory I provided my second version of the code, with refactored functions, an animation, and an enemy patrol.
The animation consists of the open/close door's movement after all the itens are collected, serving as a signal that you can exit the game.
The enemy is a flame that causes the interruption of the game if the player touches it.  

In the "game" directory I'm still building a third version of the code, in which I aim to work with linked lists to build coordenates and vectors. 
In the lib directory, you can check out the graphic library plus the LIBFT.
The LIBFT contains some functions that reproduce the behaviour of many functions found in the C library and others.
In this project, I used the get_next_line function, which works as a "fgets", and the ft_printf, that mimcs "printf".

##  📝 What was done in this code?

1- I check if the text file is in the correct formart (.ber)

2- I read the file, parsing the map to store it in a multidimensional array (matrix).

3- I check if the map is valid:

- The map can be composed of only these 5 characters:

0 for an empty space,

1 for a wall,

C for a collectible,

E for a map exit,

P for the player’s starting position.

(Note: I added an F for 'fire', the enemy from the bonus part).

- The map must be rectangular.

- The map must be closed/surrounded by walls.

- There is a valid path in the map (it is possible to collect every collectible present on the map and then then exit).
	
Here I used the <strong>flood fill algorithm</strong>, and as it modifies the map, I created a copy of the matrix specifically for this purpose. 

<strong>4-</strong> I use the graphic library to display an window and load the images.

5- I display instances of the images according to the map's positions.

6- I create a loop to check the player's movements.

-- In the bonus part, another loop was created to animate the door.

7- I delete all the images and terminate the graphic library's use.

8- I free the matrices.

9- During the entire execution of the program, if an error occurs, I display an error message and free the matrices.
