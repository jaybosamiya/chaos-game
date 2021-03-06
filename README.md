Chaos Game
==========

> Play the chaos game to create awesome fractal images

Screenshots
-----------

![](images/screenshot1.jpg)

![](images/screenshot2.jpg)

![](images/screenshot3.jpg)

![](images/screenshot4.jpg)

Video Demo
----------

It has come to my notice that Yu-Jie Lin has made a nice video showing the features of this program, which can be seen on youtube [here](https://www.youtube.com/watch?v=9gt72c9ni5w).

How it works
------------

The tool takes takes multiple points as input from the user. Then, it assigns the centroid of these points as the initial point. Then, it iterates moving towards a random point, moving in a ratio of `r` taken as input.

Usage
-----

```bash
./chaos-game
```

+ Left Click: Add new point
+ Right Click: Define starting point
+ Keypress x: Delete latest point
+ Keypress f: Run the chaos game
+ Keypress c: Toggle colouring
+ Keypress q: Quit


Build process
-------------

```bash
mkdir build
cd build
cmake ..
make
```

Requirements
------------

+ OpenCV 2.x
+ CMake 2.8 or above

License
-------

This software is licensed under the [MIT License](http://jay.mit-license.org/2016)
