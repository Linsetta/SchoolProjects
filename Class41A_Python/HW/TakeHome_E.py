"""
Nina Demenchukova
CIS 41A   Fall 2018"
Unit E take-home assignment
"""

print("First Script – Decision Making")
#Write a script that can determine where different plants can be planted.
#Each plant has a name, a type (Flower, Vegetable, Tree, etc.), and a maximum height.

print("Example output:")
print(input("Please enter the plant name: "))
print(input("Please enter the plant type:"))
print(input("Please enter the plant height:"))

plant = {
    'Name': 'Lily', 'Type': 'Flower', 'Height': 3,
    'Name': 'Bonsai', 'Type': 'Tree', 'Height': 2,
    'Name': 'Carrots', 'Type': 'Vegetable', 'Height': 1,
    'Name': 'Corn', 'Type': 'Vegetable', 'Height': 8,
    'Name': 'Rose', 'Type': 'Flower', 'Height': 5,
    'Name': 'Sunflower', 'Type': 'Flower', 'Height': 8
}

if 'Vegetable' in Type :
   print("A {0} can be planted in the Vegetable Garden.".format(Name))
elif 'Flower' in Type and Height <= 3:
   print("A {0} can be planted in the Low Garden or the High Garden.".format(Name)) 
elif 'Flower' in Type and Height >= 3 and Height <= 6:
   print("A {0} can be planted in the High Garden.".format(Name))
else:
   print("A {0} does not match the criteria for any of the gardens.".format(Name))
"""
print("Second Script – Guessing Game")
"""
"""
   Write a script that plays a simple guessing game.
   The script will generate a secret number from 1 to 100, inclusive, and the user will have to guess the number.
"""
   
import random

#this generates a random int from 1-100, inclusive
secretNum = random.randint(1,100)
print("Welcome to the guessing game.\nYou need to guess a number from 1 to 100.")
print(input("What is your guess?"))

if guess == secretNum:
   print("Congratulations!\nYou guessed the secret number in 1 guess!")
else:
   count = 1
   while (guess != secretNum):
      if (guess < secretNum):
         print ("Guess is too low.")
         count = count + 1
         print("What is your guess?")
         guess = int(input())         
         
      elif (guess > secretNum):
         print ("Guess is too high.")
         count = count + 1  
         print("What is your guess?")
         guess = int(input())         
   print("Congratulations!\nYou guessed the secret number in {0} guess!".format(count))
print ("Good bye!")

print("Third Script – has two parts\nPart One – Looping with String Methods")
"""
Update the Unit B Counting and Finding In-Class exercise to use a loop.
Assign the text "Believe you can and you're halfway there." to a variable called quote 
Loop through the quote to find and print the index of all the "a" characters.
"""
quote = "Believe you can and you're halfway there."
offset = 0;
indices = list()
for i in range(quote.count('a')):
    indices=quote.index('a',offset)
    print ("a found at index", indices)
    quote.find('a')
    offset = indices+1
indices = list()
for i in range(quote.count('a')):
    indices=quote.index('a',offset)
    print ("a found at index", indices)
    quote.find('a')
print("Part Two – Nested Loops")
"""
Write a script using nested for loops to generate a triangular multiplication table as illustrated below.
Ask the user how many rows they would like in their table.
"""
print("Please enter the number of rows for the multiplication table:")
rows = int(input())
num = 1
for i in range(1, rows+1):
    for j in range(1, i+1):
        print("{:2d}".format(i * j), end=" ")
        num = num+1
        print(" \r")