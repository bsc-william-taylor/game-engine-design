
<img src='preview.gif' />

<img src='icon.png' width='150' height='150' align='right' />

# Game Engine Design

The game engine design module aimed to teach students design patterns and common coding patterns found in game engines. It also taught students inheritance found in C++ and common C++ advanced topics such as the standard template library known as STL. 

## Assignment

The assignment was to develop a prototype game that showed off good use of modern C++ and design patterns. The goal was not to create an awesome game but merely show off the concepts taught in the module. Additionally a report was required to describe the design and what features have been implemented along with a general report. 

## Submission

A full implementation of the features set out in the coursework was implemented. I used OpenGL for drawing the basic shapes with texture support to be added in the future if wanted. Window management was done with SDL2 and Fonts were managed with the True Type Font library. I also implemented several key design patterns such as those below but no singleton for obvious reasons.

* Observer pattern
* Factory pattern
* State pattern
* Strategy pattern

I also adopted a data driven design so the loading and saving of game files was supported along with customization of the labels shown on screen in the credit scenes for example. 
 
## License

Apache 2.0