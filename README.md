# RNG
Random map generation algorithm for roguelike game (WIP)

--

## How it works:

Place starting point S on random tile

Place end point F on random tile, so that the vertical distance and horizontal distance is greater than X*

Create a path from S to F (marking each tile in the path as an essential room) by randomly determining if a room is to be placed above/below or next to the previous room

For each essential room placed,  
&nbsp;&nbsp; for each adjacent empty tile,  
&nbsp;&nbsp;&nbsp;&nbsp; there is X* percent chance that it turned into a nonessential room

Expand grid into expandedGrid

(Essential rooms must be connected together)  
(Non essential rooms must have at least one connection)

For each room  
&nbsp;&nbsp; for each adjacent room that is not disconnected
&nbsp;&nbsp;&nbsp;&nbsp; there is X* percent chance of a connection (1), or else it is disconnected (-1)
&nbsp;&nbsp;&nbsp;&nbsp; if there is one possible connecting point left, it must become a connection
&nbsp;&nbsp;&nbsp;&nbsp; if there are no connecting points left, a random disconnection must becom a connection

Collapse expandedGrid into collapsedGrid, each tile assigned a value based on bordering connections and their position

&nbsp;&nbsp;&nbsp;&nbsp;1  
10[ ] 2  
&nbsp;&nbsp;&nbsp;&nbsp;5  
<br/><br/>

***\*value to be determined***
