#include<iostream>
using namespace std;

/*
The first player always wins if played optimally.

First note that the result of game is definite. There's
no tie, because someone will definitely pick the last
piece. It's either win or lose.

The game has two states: winning and losing.
A state is winning iff there exists at least one move
after which the state will be losing.
Otherwise its a losing state i.e. any move leads to
winning state.

Assume the first player will lose (the game starts with
losing state). So whatever move he makes will lead to
winning state. Let say he picks 1. We are left with
set {2,3,4...,n} and it is a winning state.
Let second player pick x and all its divisors in
order to win the game. Now its a losing state.
We are left with set S = {2,3,..,n} - {d : d|x}.
But this state can also be reached when first player
pick x (and all its divisors (which includes 1) )
in the first move itself. This means that set S
is winning state. A set can't be winning and losing
at same time. Hence contradiction.
First player always has a winning move.
*/

int main(){
	int t; cin >> t;
	while(t--){
		int n, first; cin >> n >> first;
		if(first==0) cout << "Airborne wins.\n";
		else cout << "Pagfloyd wins.\n";
	}
	return 0;
}