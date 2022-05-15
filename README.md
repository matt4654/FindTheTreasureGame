# Find-the-Treasure Game Project - C++

## Goals

> * A player with a position and ability to move
> * Infinitely scrolling
> * Treasure with a position
> * Finding treasure is the win-state
> * Distance between the treasure and the player available

## Description

* Two `int` values represent the player's position on an infinite (closed) plane
* Player starts at `(0, 0)`
* Two `int` values represent treasure position - randomly selected at the beginning of the game
* Player has stamina which depletes from movement
* Game over when stamina runs out
* Starting stamina depends on treasure distance and difficulty selection 