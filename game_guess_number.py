'''
a game in which you have to guess the number drawn
version 0.01
author: Neo_RS
created on
'''

from random import randint # import randint function

answer = randint(1, 20) # draw a number
guess_as_str = input("Zgadnij liczbę: ") # enter your answer
guess = int(guess_as_str) # change str to int

# check entered answer
while guess != answer:
    if guess < answer :
        print("Za mała!")
    else:
        print("Za duża!")
    guess_as_str = input("Zgadnij liczbę: ")    ### check DRY
    guess = int(guess_as_str)                   ### check DRY

print("Brawo!")