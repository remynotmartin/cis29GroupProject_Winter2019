----------
Unresolved
----------
1. Standard gravity (as defined in the Game.h header) seems to only 
   affect players in the middle of a jump animation. For example, 
   if a player runs off of a platform without entering the jump 
   animation, they get accelerated toward the ground at a remarkable
   rate, much faster than would be expected with a constant downward
   acceleration.
2. If a player runs into a tile for long enough, they tend to clip 
   though and cause the camera to follow them into a void, where they
   disappear under the tiles and across the world.
