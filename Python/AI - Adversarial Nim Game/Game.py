# Name: Claudio Osorio
# Date: 2/13/2022
# Section: Module 5 and 6
# Assignment: Adversarial Search - Nim Game
# Due Date: 2/13/2022
# About this project: This project is about the Nim Game but the Computer plays as an adversary using the Alpha Beta
# Prunning algorithm.
# Game Implementation written by Claudio Osorio

import random
from collections import namedtuple
import numpy as np
from copy import deepcopy

GameState = namedtuple('GameState', 'to_move, utility, board, moves')

# Pre : accepts empty rockList, random pile as integers
# Post: creates the board
def create_board(rockList, randPile):
    # create board
    for i in range(0, randPile):
        randRock = random.randint(1, 4)
        rockList.append(randRock)
    print("-" * 25)

# Pre : accepts empty rockList, random pile as integers
# Post: prints the board
def display_board(rockList, randPile):
    # display board
    print("-" * 25)
    for i in range(0, randPile):
        print('Pile {}: {}'.format(i + 1, 'O' * rockList[i]))
    print("-" * 25)


# Pre : accepts modified rockList, random integer for piles, current player as string
# Post: returns a string when input is invalid, updates game board for following turns
def get_valid_input(rockList, randPile, player):
    # Begin loop that tests for valid input - if valid, break loop - if not, keep asking

    count = 0
    while True:
        if player == name1:
            stones = input('{}, how many stones to remove? '.format(player))
            piles = input('Pick a pile to remove from: ')
        elif player == "COMPUTER":
        # Generating a current state of the game
            state = gen_state(to_move=player, pile_amt=randPile, rocks_per_pile=rockList)
            # If it's the computer then don't ask for input.
            # Instead generate it using alpha beta prunning
            best_move = alpha_beta_search(state)

            # Adjusted index
            piles = str(best_move[0])
            stones = str(best_move [1])
            print(f"Computer's Move:\nStones to remove: {stones}\nPile to remove from: {piles}")

        # If all conditions for input are CORRECT, break out of loop
        if (stones and piles) and (stones.isdigit()) and (piles.isdigit()):
            if (int(stones) > 0) and (int(piles) <= len(rockList)) and (int(piles) > 0):
                if (int(stones) <= rockList[int(piles) - 1]):
                    if (int(stones) != 0) and (int(piles) != 0):
                        break

        # If not, display this statement
        print("Hmmm.",player,", you entered an invalid value. Please try again.")

    # Update state
    rockList[int(piles) - 1] -= int(stones)


# Pre : accepts modified rockList, random integer for piles, names of players, current palyer as string
# Post: prints winner of game, asks if players want to play game again, determine current player
def play(rockList, randPile, name1, name2, player):
    # Begin loop to initiate player switching
    while rockList != [0] * len(rockList):
        get_valid_input(rockList, randPile, player)

        # display the board
        display_board(rockList, randPile)

        # switch players 2->1, 1->2
        if player == name1:
            player = name2
        else:
            player = name1

    print(player," is the winner :)")

def gen_state(to_move='PlayerName', pile_amt = [], rocks_per_pile = []):
    # Generating possible moves (pile_number, rocks_inpile)
    moves = list()
    for each_pile in range(pile_amt):
        for rocks in range(rocks_per_pile[each_pile]):
            moves.append((each_pile + 1, rocks + 1))
    #Defining Board
    board = (rocks_per_pile, pile_amt)
    return GameState(to_move=to_move, utility=0, board=board, moves=moves)

# Functions used by alpha_beta
def max_value(state, alpha, beta):
    v = -np.inf

    # Terminal test:
    if len(state.moves) == 0:
        return state.utility

    for each_move in state.moves:
        # v = max(v, min_value(successor_result(state,each_move), alpha, beta))
        v = max(v, min_value(successor_result(state,each_move), alpha, beta))
        if v >= beta:
            return v
        alpha = max(alpha, v)
    return v

def min_value(state, alpha, beta):
    v = np.inf

    # Terminal test:
    if len(state.moves) == 0:
        return state.utility

    for each_move in state.moves:
        v = min(v, max_value(successor_result(state,each_move), alpha, beta))
        if v <= alpha:
            return v
        beta = min(beta, v)
    return v

# Searches deep into the game and goes through all nodes finding the optimal move
def alpha_beta_search(state):
    print(f"Calculating...")
    player = state.to_move
    best_score = -np.inf # Alpha
    beta = np.inf #
    best_action = None
    for each_move in state.moves:
        v = min_value(successor_result(state,each_move), best_score, beta)
        if v > best_score:
            best_score = v
            best_action = each_move
    return best_action

def successor_result(state, move):
    if move not in state.moves:
        return state  #The move didn't have any effect

    # Created an updated copy of the board
    rocks_per_pile = deepcopy(state.board[0])
    pile_amt = deepcopy(state.board[1])

    for pile_index in range(pile_amt): # For all piles
        if move[0] == pile_index + 1 :   # if the pile of the move matches
            # Removes the specified amount of rocks specified by this move
            rocks_to_remove = move[1]
            rocks_per_pile[pile_index] = rocks_per_pile[pile_index] - rocks_to_remove
            break

    # Update list of moves now that there are less rocks.
    # This excludes previous moves that are no longer valid
    updated_moves = list()


    for pile_index in range(pile_amt):  # For all piles
        for rocks in range(rocks_per_pile[pile_index]): # For every rock in the pile
            updated_moves.append((pile_index + 1, rocks + 1)) # Add a move

    # Recreating board, making new one because Tuples cannot be modified.
    board = (rocks_per_pile, pile_amt)

    if state.to_move != "COMPUTER":
        next_turn_player = "COMPUTER"
    else:
        next_turn_player = "Player1"

    # Updated state successor (after move reducing rocks)
    return GameState(to_move= next_turn_player,
                     utility=compute_utility(board, state.to_move),
                     board=board,
                     moves=updated_moves)

# Calculates utility for each resulting board
def compute_utility(board,player):
    rockList = board[0]
    pile_amt = board[1]
    piles_with_rocks = 0
    for rocks in rockList:
        if rocks > 1:
            piles_with_rocks += 1;

    # If there is only a single pile
    # then there should be 1 rock left only
    if piles_with_rocks == 1:
        for rocks in rockList: # For all piles
            if rocks > 1:
                return -1 if player == "COMPUTER" else +1;
        return +1 if player == "COMPUTER" else -1;

    # Count piles empty
    piles_empty = 0
    for rocks in rockList:
        if rocks == 0:
            piles_empty +=1



    # Rewarding when there are more empty piles
    if piles_empty == pile_amt:
        return -1 if player == "COMPUTER" else +1;
    else:
        return +1 if player == "COMPUTER" else -1;

    return 0

# Define an empty rocklist to append rocks to, define random integers, call functions
rockList = []

# random number of rock piles
pile_amt = random.randint(2, 4)
# NOTE: randRock = random number of rocks

#get the name of the players
name1 = input("Enter player 1 name: ")
name2 = "COMPUTER"

# Set current player to 1 (for switching later)
player = name1

create_board(rockList, pile_amt)
display_board(rockList, pile_amt)  # Set initial board

play(rockList, pile_amt, name1, name2, player)
