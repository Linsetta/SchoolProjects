"""
Nina Demenchukova
CIS 41A   Fall 2018"
Unit F take-home assignment 
"""
#Part One – Keyword Arguments and Default Values


def invoice(unitPrice, quantity, shipping = 10, handling = 5):
    """invoice function.Generate an invoice. Has two required arguments and two keyword arguments."""
    #print(invoice.__doc__)
    Positional: (unitPrice, quantity)
    Keywords: {'shipping': 10, 'handling': 5}
 
    print("Cost (unitPrice*quantity) =", unitPrice*quantity)
    print("shipping = ", shipping) 
    print("handling = ", handling)
    total = unitPrice*quantity + shipping + handling
    print("Total = ", total, "\n")     
    
#Part Two – args (Variable-Length Arguments)   
def getInput():
    groupName = input('Enter your group project: ')
     
    std= input('Enter students name in the group. Separate names by a space: ')    
    students = std.split(' ')#converts names to a list ['Sam', 'Joe']

    return groupName, students

def printGroupMembers(group, *args):
    print('Members of', group)#
    #print('inside printGroupMembers func',kwargs) #{'names': ['Sam', 'Joe']}

    for i in args:
        print(i)
    print()

#Part Three – Non-Rectangular (Ragged) 2D lists 
def buildBell(rowCount):
    bell = [[1]]
    for row in range(1, rowCount):               
        lastRow              = bell[row - 1]
        lastElementOfLastRow = lastRow[row - 1]
        newRow               = [lastElementOfLastRow]
        for column in range(1, row + 1):
            newRow.append(lastRow[column - 1] + newRow[column - 1])
        bell.append(newRow)
    return bell
    
def printBell(bell):
    for row in bell:
        for element in row:
            print(str(element).rjust(5), end="")
        print();
    
def main(): 
    print("Example output:")
    invoice(20, 4, 8)
    invoice(15, 3, handling=15)
    
    #First Test
    printGroupMembers("Group A", "Li", "Audry", "Jia")
    
    #Second Test
    groupB = ["Group B", "Sasha", "Migel", "Tanya", "Hiroto"]
    printGroupMembers(*groupB)
    
    bell = buildBell(8)
    printBell(bell)

if __name__ == '__main__':
    main()


