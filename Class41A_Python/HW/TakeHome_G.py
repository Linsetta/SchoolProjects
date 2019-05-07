"""
Nina Demenchukova
CIS 41A   Fall 2018"
Take-Home Assignments Unit G
"""
"""Build a second dictionary from the USPresidents.txt file described in the previous exercise. Each key will again be a state abbreviation, however, the value will be the count of presidents from that state.
Create a set of the ten most populous US states (CA, TX, FL, NY, IL, PA, OH, GA, NC, MI).
Then create a new set that represents a set of populous US states that have had presidents born in them (you should be able to do this with one line of code).Print a count of this new set along with an alpha-sorted listing of these states and how many presidents have been born in them.
"""

#Part One – Reading a data file 
def part_1():
    statesFile = open("States.txt", "r")
    contents   = statesFile.read()
    statesFile.close()
    filterRegion           = "Midwest"
    highestPopulation      = 0
    highestPopulationState = None
    for rowContent in contents.split("\n"):
        if rowContent != "":
            rowWords   = rowContent.split(" ")
            state      = rowWords[0]
            region     = rowWords[1]
            population = int(rowWords[2])
            if region == filterRegion and population > highestPopulation:
                highestPopulation      = population
                highestPopulationState = state
    print("Highest population state in the", filterRegion, "is:", highestPopulationState, highestPopulation)

#Part Two – A Dictionary of Lists 
def part_2():
    uSPresidentsFile = open("USPresidents.txt", "r");
    contents         = uSPresidentsFile.read()
    uSPresidentsFile.close();
    statePresidentDict = {}
    for rowContents in contents.split("\n"):
        if rowContents != "":
            rowParts        = rowContents.split("\t")
            state           = rowParts[0]
            president       = rowParts[1]
            statePresidents = None
            if state in statePresidentDict:
                statePresidents = statePresidentDict[state]
            else: # if state is not key within statePresidents, add empty list as value for key state
                statePresidents           = []
                statePresidentDict[state] = statePresidents
            statePresidents.append(president)
    mostPresidentCount      = 0
    mostPresidentCountState = None
    for state in statePresidentDict:
        statePresidents     = statePresidentDict[state]
        statePresidentCount = len(statePresidents)
        if statePresidentCount > mostPresidentCount:
            mostPresidentCount      = statePresidentCount
            mostPresidentCountState = state
    print ("The state with the most presidents is", mostPresidentCountState, "with", mostPresidentCount, "presidents:")
    for president in statePresidentDict[mostPresidentCountState]:
        print (president)
    
#Part Three – Dictionary Keys and Sets 
def part_3():
    # read presidents into dictionary, statePresidentCountDict, for use below
    presidentsFile = open("USPresidents.txt", "r")
    presidentsFileContents = presidentsFile.read()
    presidentsFile.close()
    statePresidentCountDict = {}
    for rowContents in presidentsFileContents.split("\n"):
        if rowContents != "":
            rowParts = rowContents.split("\t")
            state     = rowParts[0]
            president = rowParts[1]
            if state in statePresidentCountDict:
                statePresidentCountDict[state] += 1
            else:
                statePresidentCountDict[state] = 1
    print (statePresidentCountDict)
    # done reading statePresidentCountDict
    # read state populations into dictionary, statePopulationDict, for use below
    populationsFile = open("States.txt", "r")
    populationsFileContents = populationsFile.read()
    populationsFile.close()
    statePopulationDict = {}
    for rowContent in populationsFileContents.split("\n"):
        if rowContent != "":
            rowWords   = rowContent.split(" ")
            state      = rowWords[0]
            region     = rowWords[1]
            population = int(rowWords[2])
            statePopulationDict[state] = population
    #print (statePopulationDict)
    # done reading state populations
    # use insertion sort to get top 10 most populous states
    remainingStates = []
    for state in statePopulationDict:
        remainingStates.append(state)
    mostPopulousStates = []
    for index in range(0, 10):
        maximumPopulation      = 0
        maximumPopulationState = None
        for state in remainingStates:
            statePopulation = statePopulationDict[state]
            if statePopulation > maximumPopulation:
                maximumPopulation = statePopulation
                maximumPopulationState = state
        mostPopulousStates.append(maximumPopulationState)
        remainingStates.remove(maximumPopulationState)
    # done with insertion sort of top 10 most populous states
    # calculate which of top 10 states have had presidents born in them
    statesWithPresidents = set()
    for state in mostPopulousStates:
        if state in statePresidentCountDict:
            statesWithPresidents.add(state)
    # create alpha sorted list of top 10 set of states that have had presidents in them
    alphaSortedStatesWithPresidents = []
    for state in statesWithPresidents:
        alphaSortedStatesWithPresidents.append(state)
    alphaSortedStatesWithPresidents.sort()
    # print results
    print (len(statesWithPresidents), "of 10 high population states have had presidents born in them:")
    for state in alphaSortedStatesWithPresidents:
        print (state, statePresidentCountDict[state])
                
def main():
   print("Example output:")
   part_1()
   part_2()
   part_3()

    
if __name__ == '__main__':
   main()
