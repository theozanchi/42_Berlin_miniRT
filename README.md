![Minirt logo](.media/42_project_banner.png)

![Grade badge](https://img.shields.io/badge/110_%2F_100-004d40?label=final%20grade&labelColor=151515&logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIGhlaWdodD0iMjRweCIgdmlld0JveD0iMCAwIDI0IDI0IiB3aWR0aD0iMjRweCIgZmlsbD0iI0ZGRkZGRiI+PHBhdGggZD0iTTAgMGgyNHYyNEgweiIgZmlsbD0ibm9uZSIvPjxwYXRoIGQ9Ik0xMiAxNy4yN0wxOC4xOCAyMWwtMS42NC03LjAzTDIyIDkuMjRsLTcuMTktLjYxTDEyIDIgOS4xOSA4LjYzIDIgOS4yNGw1LjQ2IDQuNzNMNS44MiAyMXoiLz48L3N2Zz4=) ![Language Badge](https://img.shields.io/badge/C-fe428e?logo=C&label=language&labelColor=151515) ![Norminette Badge](https://img.shields.io/badge/passing-brightgreen?logo=42&label=norminette&labelColor=151515)![Library Badge](https://img.shields.io/badge/our_own_libft-004d40?logo=GitHub&label=library%20used&labelColor=151515)![Library Badge](https://img.shields.io/badge/minilibx-004d40?logo=GitHub&label=library%20used&labelColor=151515)

# miniRT

This project is about creating a ray tracer to render 3D scenes.
It is a group project done with Henri Laurence

The full subject can be found [here](.media/en.subject.pdf).

# Downloading and compiling the project

Clone the library and use `make` to compile
```shell
git clone https://github.com/theozanchi/42_Berlin_minirt/tree/main
cd 42_Berlin_miniRT
make
```
![Compilation screenshot](.media/compilation_complete_screenshot.png)

# Running the program
The program is launched without one argument, the `.rt` file that contains the information about the scene to render:

![Launching](.media/launching.png)

# Supported options of the `.rt` file
Here is an example of a config file for a scene: 
```
A 0.2							255,255,255

C 0,0,-10		0,0,1			80

L 0,0.1,1.0		0.8				255,255,255

sp 0,5,7		5				255,0,0 
sp 1.5,1,3		2				255,0,255 
sp -6,6,5		6				255,255,0 

pl 0,0,10		0,0,1			0,255,255 
pl 0,-1,0		0,1,0			255,0,255 

cy -2,2,5		1,1,0	2	4	255,228,196
```
The parameters are the following: 
* `A` `intensity` `rgb` - Ambient lighting
* `C` `position` `orientation` `focal` - Camera
* `L` `position` `intensity` `color` - Spotlight
* `sp` `position` `diameter` `color` - A sphere
* `pl` `position` `orientation` `color` - A plane
* `cy` `position` `orientation` `diameter` `height` `color` - A cylinder

This scene is rendered as follow: 

![Scene 3.0](.media/scene_3.0.png)

# Some other examples of rendered scenes
![Scene 3.1](.media/scene_3.1.png)
![Scene 6.0](.media/scene_6.0.png)

# Options
In the header file `minirt.h`, the following flags can be adjusted: 
* `SHADOW` to able or disable shadows in the scene
* `SPECULAR` to able or disable specular reflection