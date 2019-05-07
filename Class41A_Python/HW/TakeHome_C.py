"""
Nina Demenchukova
CIS 41A   Fall 2018"
Unit C take-home assignment 
"""
print("Example output:\n")
#Create an empty list called list1.  Populate list1 with the values 1,3,5
list1 =[]
list1 =[1, 3, 5]

# Create list2 and populate it with the values 1,2,3,4
list2 = [1, 2, 3, 4]

#Create list3 by combining list1 and list2, print list3 (do with one line of code – use the + operator).
list3 = list1 + list2
print("d) list3 is: ", list3)

#Use sequence operator in to test list3 to see if it contains a 3, print True/False result (do with one line of code).
a = 3
#flag = False
#print("e) list3 contains a 3: {0}".format(a in list3)) 
print("e) list3 contains a 3: True" if a in list3 else "e) list3 contains a 3: False")
"""
if a in list3:
   print("e) list3 contains a 3: True")
else:   
   print("e) list3 contains a 3: False")
#Count the number of 3s in list3, print the result
b = list3.count(3)
print("f) list3 contains", b, "3s")
"""
#Determine the index of the first 3 in list3, print the result.
print("g) The index of the first 3 contained in list3 is", list3.index(3))

#Pop this first 3 and assign it to a variable called first3, print first3.
first3 = list3.pop(1)
print("h) first3 =",first3)

#Create list4, populate it with list3's sorted values, using the sorted built-in function.
list4 = sorted(list3)

#Print list3 and list4.
print("j) list3 is now:",list3)
print("j) list4 is:",list4)

#Slice list3 to obtain a list of the values 1,2,3 from the middle of list3, print the result.
print("k) Slice of list3 is:",list3[2:5])

#Determine the length of list3, print the result.
print("l) Length of list3 is", len(list3))

#Determine the max value of list3, print the result.
print("m) The max value in list3 is", max(list3))

#Sort list3 (use the list sort method), print list3.
print("Sorted list3 is:", sorted(list3))

#Create list5, a list of lists, using list1 and list2 as elements of list5, print list5.
list5 = [list1, list2 ]
print("o) list5 is:",list5)

#Print the value 4 contained within list5.
print("p) Value 4 from list5:", list5[1][3])

print ("\nSecond Script – Bit Operators")
#Assign the values 9 and 14 to variables a and b respectively.
a = 9
b = 14
#Print the binary values of a and b (use the bin built-in function).
print("b) binary of a = ", bin(a))
print("b) binary of b = ", bin(b))

#Calculate the value of a and b, print the result in binary.
print ("c) binary of a & b ", bin(a&b))

#Calculate the value of a or b, print the result in binary.
print ("d) binary of a | b = ", bin(a|b))
