"""
Nina Demenchukova
CIS 41A   Fall 2018"
Unit D take-home assignment
"""
print("Execution results: \n")
#Part One - Sets

#Create a set named class1 and populate it with the students Li, Audry, Jia, Migel, Tanya.
class1 = {"Li", "Audry", "Jia", "Migel", "Tanya"}

#Create a set named class2 and populate it with the students Sasha, Migel, Tanya, Hiroto, Audry.
class2 = {"Sasha", "Migel", "Tanya", "Hiroto", "Audry"}

#Create a set named class3 and populate it with the students Migel, Zhang, Hiroto, Anita, Jia.
class3 = {"Migel", "Zhang", "Hiroto", "Anita", "Jia"}

#Print a sorted list of students who are in all three classes.
class1 & class2 & class3
print("Students in all three classes:", sorted(class1.intersection(class2, class3)))

#Print a sorted list of all students. 
print ("All students:", sorted(class1.union(class2,class3)))

#Print a sorted list of all students in class1 but not class2 or class3.
print("Students in class1 but not class2 or class3:", sorted(class1.difference(class2,class3)))

#Part Two - Swap
#Create a list containing elements 1, 2, 3
list =[1,2,3]

#Swap the second and third elements of the list. Do this with one line of code.
list[1], list[2] = list[2], list[1]

#Print the list.
print("List after swap:", list)

#Part Three – Tuple Basics
#Create a tuple that contains the elements Casablanca, 1942, romantic drama.
tuple = ('Casablanca', '1942', 'romantic drama')

#Unpack the tuple into variables title, year, genre.
title, year, genre = tuple

#Print the title.
print("My favorite movie is:", title)

#Part Four – Named Tuple
#Define a named tuple called Movie that contains the fields title, year, genre.
from collections import namedtuple
Movie = namedtuple('Movie', 'title year genre')

#Create a Movie tuple that contains the elements Casablanca, 1942, romantic drama.
favoritemovie = Movie('Casablanca', '1942', 'romantic drama')

#Print the title.
print("My favorite movie is:", favoritemovie.title)

#Part Five – Named Tuple Containing a List
#Define a named tuple called Moviestars that contains the fields title, year, genre, stars.
Moviestars = namedtuple('Moviestars','title year genre stars')

#Create a Moviestars tuple called favoritemovie that contains the elements Casablanca, 1942, romantic drama, and a list containing elements Humphrey Bogart, Ingrid Bergman.
stars = ['Humphrey Bogart', 'Ingrid Bergman']
favoritemovie = Moviestars('Casablanca', '1942', 'romantic drama', stars)

#Append Claude Rains to the stars list. Hint: Use the syntax favoritemovie.stars.append
favoritemovie.stars.append('Claude Rains')

#Print star Ingrid Bergman.
print("My favorite star is:", favoritemovie.stars[1])

#Print favoritemovie.
print(favoritemovie)
