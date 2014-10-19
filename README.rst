NoDice
======
NoDice is a *very* simple dice roller written in C.
It uses pseudo-random number generation from the C standard library, which is a way of saying that its numbers aren't perfectly random (but it's plenty good enough for most things that you would want to roll a die or flip a coin for).

I wrote this utility mostly ofr my own purposes (for use in role-playing games), but if it has some use for other people, I have no issue with that.
``nodice`` allows a user to request as many as 4294967295 random numbers between 1 and 4294967295 (``UINT_MAX``), inclusive.
It also offers the ability to automatically color the floor and ceiling (if requested ``1`` would be colored red, and the maximum possible number would be colored green).


To-Do
-----
Add option for calling random values from `random.org <http://random.org>`_ to grab "truly random" values.

Dependencies
------------
Because ``nodice`` uses only C99 standard library functions, all it should need is a compiler which can build using the C99 standard.
However, for simplicity's sake, this project uses `tup <https://github.com/gittup/tup>`_ to manage building.
While you can build it manually, installing ``tup`` allows you to build this project by simply running ``tup upd``.

Contributions
-------------
All contributions are welcome (pull requests, constructive criticism, feature requests and musings), but pull requests should attempt to follow `these guidelines <http://github.com/HalosGhost/styleguides/blob/master/C.rst>`_ for consistency.
I am likely to reformat any commit that should deviate from these guidelines.
