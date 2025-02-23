Design Patterns - Elements of Reusable Object-Oriented Software
===

<!-- 

this file should answer the following questions:
1. Overview (explains what this specific project does)

while the following questions seem to be common knowledge, it's better to include a brief explanation of them, to keep the reader on our page, and not lose them to the sea of wide internet...

2. What are design patterns? [x]
3. Why design patterns? [x]
4. Who set them? [x]

5. Contents of the folders?
6. Requirements and build (dependencies)

Due 2025, February 4th
 -->
# Overview

> _UNDER CONSTRUCTION_

<img src="https://wiki.archiveteam.org/images/8/8b/Underconstruction.gif" width="200" alt="under constructon sign">

- [Design Patterns - Elements of Reusable Object-Oriented Software](#design-patterns---elements-of-reusable-object-oriented-software)
- [Overview](#overview)
- [What, Why, and Who?](#what-why-and-who)
  - [What are Design Patterns?](#what-are-design-patterns)
  - [Why Design Patterns?](#why-design-patterns)
  - [Who came up with Design Patterns?](#who-came-up-with-design-patterns)
  - [References](#references)
  - [Book Implemented](#book-implemented)
- [What's inside](#whats-inside)
- [Requirements and Build](#requirements-and-build)
  - [How to build](#how-to-build)


# What, Why, and Who?

## What are Design Patterns?

Design patterns are typical solutions to commonly occurring problems in software design. They are like pre-made blueprints that you can customize to solve a recurring design problem in your code.

All patterns can be categorized by their _intent_, or purpose, for further reading please refer to [this](#references) section.

## Why Design Patterns?

Because design patterns are a toolkit of tried and tested solutions to common problems in software design.
They're like learning color blends instead of just trying out every pair of colors to get a desired color (solution).

## Who came up with Design Patterns?

 A history lesson here, 
 
**Short answer;** Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm, back in 1994.

**Better answer:** 
 
Design patterns gained popularity in computer science after the book _Design Patterns: Elements of Reusable Object-Oriented Software_ was published in 1994 by the so-called "Gang of Four" (Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides), which is frequently abbreviated as "GoF".

## References
Learn more on design patterns at <a href="https://refactoring.guru/design-patterns">Refactoring.Guru</a> and <a href="https://en.wikipedia.org/wiki/Software_design_pattern">Wikipedia</a>.

## Book Implemented
This is my implementation of the Design Patterns from the book

```text
'Design Patterns: Elements of Reusable Object-Oriented Software'
Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides
ISBN 0-201-63361-2
Copyright 1995
21th Printing, November 2000
```

The nice thing about the Design Patterns book is that it is... well... not complete :-) To come to a complete working implementation of all the Design Patterns presented in the book and be able to play with them, requires some extra coding.  The goal of this project is to actually provide the missing pieces and come to something that will compile and run cleanly.

On the following websites, I have found C++ code that helped me
complete everything:

* <http://www.c-jump.com/CIS75/Week11/>
* <http://www.c-jump.com/Download/Patterns/Prototype/html/>
* <https://code.google.com/p/basic-algorithm-operations/source/browse/trunk/DP>
* <http://dislab.hufs.ac.kr/wiki/Lecture/Design_Pattern>
* <http://blog.csdn.net/joey_zoy/article/details/5610810>
* <https://github.com/wangqiang8511/C---Design-Patterns-Examples/>

And here are some interesting slides that give some more explanation:

* <http://www.cs.toronto.edu/~penny/teaching/csc407/>

A more modern C++11 approach using Boost libraries was given in a talk by Tobias Darm given here:

* <http://www.infoq.com/presentations/gof-patterns-c-plus-plus-boost>

An interview from 2009 with the GoF authors is given here:

* <http://www.informit.com/articles/article.aspx?p=1404056>

A dependency analysis and refactoring of the Gang of Four examples can
be found at

* <https://github.com/zebmason/GoFRefactored/blob/master/README.md>

# What's inside
<!-- need to come up with a better title? -->
Implemented Design Patterns so far:

<details>
<summary>Behavioral Patterns</summary>
<ul>
    <li>Chain of responsibility</li>
    <li>Command</li>
    <li>Iterator (aka Cursor)</li>
    <li>Observer</li>
    <li>Strategy</li>
    <li>Template Method</li>
</ul>
</details>

<details>
<summary>Creational Patterns</summary>
<ul>
    <li>Abstract Factory</li>
    <li>Builder</li>
    <li>Factory Method</li>
    <li>Prototype</li>
</ul>
</details>
<!-- add maze thing -->

<details>
<summary>Foundation Classes</summary>
<ul>
</ul>
</details>
<!-- add content -->

<details>
<summary>Structural Patterns</summary>
<ul>
    <li>Adapter</li>
</ul>
</details>

<br>

# Requirements and Build

Requirements:
- Cmake
- C++ compiler
<!-- TODO: specify more, does it need some external library? -->

## How to build
Each category has its own cmake file, hence you will need to change directory to the desired category `cd`, run the following commands one by one:

```sh
cd {Category_dir}/
cmake -S . -B build
cmake --build ./build
...
```
You can also use CMake's `-j N` option for parallel builds on `N` cores and `-v` for verbose builds:

```sh
cmake --build build -j 4 -v
```

<!-- TODO: specify what to run next -->

> [!NOTE]
> Replace {Category_dir} with the actual directory name.

<!-- TODO: README file for each category and then redirect reader to each build section of corresponding README -->