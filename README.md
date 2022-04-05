# TrappedHorse

This code is about a video I saw from the Numberphile youtube channel. The video is titeled "The Trapped Knight - Numberphile". In this video an infinite square shaped
spiral strating from 1 and goes to infinity is places on a infinitely big chess board. A horse is placed in the center (1), and it can move as a normal chess horse would
move. However, every move the horse makes should aim for the lowest possible value and it cannot go on a number that it have previously been on. The question asked in the
video was wether this horse would get trapped or not. It is shown in the video that horse would get trapped when it reaches the number 2084. There are also variations of 
this problem in which you change how you arrange the numbers starting from 1. I wanted to see if I could find this number myself. It turns out it is very hard to get a 
algebraic function from a this kind of spiral. I hope this may help people who also want to work with these kind of spirals.

Square Spiral:

................................        My code is written based on this form of the spiral. Changing where you put the 2, and changing the rotation the numbers follow 
........17 16 15 14 13..........        will not work with this code.
........18  5  4  3 12..........
........19  6  1  2 11..........
........20  7  8  9 10 27.......
........21 22 23 24 25 26.......
................................
