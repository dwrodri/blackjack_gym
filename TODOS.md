# TODOS

The features of the blackjack gym are still unranked. This is prone to cause
some discontnet. While I acknowledge that design is important, I'd like to 
have something that **works**, and then focus on getting it working beautifully,
and only then focus on getting it working fast. Everything on this list is designated
a requirement for the software gym to reach alpha development stage, unless stated otherwise.

---


## Design (Very important!)
- [ ] Decide on specifics for sharing player state over the socket (medium)
- [ ] Decide if betting and pool data needs to separate from the play data (medium) 
- [ ] Figure out how _one_ game of 21 would be played in a synchronous manner (easy)
- [ ] Figure out how _multiple_ games of 21 could be played at the same time asynchronously (hard)

## Basic functionality (Almost as important)
- [ ] add basic moves (Hit, Stand, Double Down) (easy)
- [ ] add support for splitting a player's hand (medium)
- [ ] make game such that mutiple players are at the table, each move is round robin (easy)
- [ ] Separate client and server model
- [ ] code up client that can send plays to server 

## Code Quality things to make my code acceptable to other humans
- [ ] Get some basic documentation going with Doxygen, or something
- [ ] Look into deploying some form of CI system, automated testing
- [ ] COMMENT THE DAMN FUNCTIONS 
- [ ] Write a Contributors.md with style guide, and other things.
- [ ] Flesh out CMake config

## Bells, Whistles, and other non-alpha things
- [ ] Dockerfile?
- [ ] Asynchronous UDP style client-server interactions for multiple games?
- [ ] Load balancer for managing multiple games at once?
- [ ] Terminal UI for server?
- [ ] Push this to linux package repositories
- [ ] Offer Python bindings (might move this to alpha features to ease adoption)
- [ ] Make this a card playing game engine for deep learning?

