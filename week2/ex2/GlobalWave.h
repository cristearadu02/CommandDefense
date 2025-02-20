#pragma once

#include "Wave.h"

int compareEnemiesNumber(Wave* wave1, Wave* wave2);
int compareMoney(Wave* wave1, Wave* wave2);

/*
    Create 2 global functions that compare two wave in terms of: number of enemies and money per enemy.
If two waves are equal the return value of such a function will be 0. If the first wave is bigger than the second one,
the return value will be 1, otherwise -1. Make sure that you have the following: a cpp file for the methods specific to
the class a header file for the global functions a cpp file for the global functions implementation
- a main.cpp file that shows how the methods and global functions can be used.
*/