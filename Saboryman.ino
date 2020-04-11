/*
 * 
 * Saboryman
 * 
 * Move mouse cursor random 1 px every 1 minutes. Yeah, I'm saboryman !
 * 
 * Copyright 2020 accribitz
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * This software is released under the GPLv3 License, see LICENSE.
 * 
 */

#include <limits.h>
#include <Mouse.h>

// const values
const unsigned int loopDelay = 60 * 1000; // ms
const unsigned int moveDistance = 1;      // px

// move distance
short int moveX, moveY;

void setup() {
  randomSeed( analogRead(0) );
  Mouse.begin();
}

void loop() {
  // map randam values to -1, 0 or 1
  moveX = random( LONG_MAX ) % 3 - 1;
  moveY = random( LONG_MAX ) % 3 - 1;
  Mouse.move( moveX * moveDistance, moveY * moveDistance, 0 );

  delay( loopDelay );
}
