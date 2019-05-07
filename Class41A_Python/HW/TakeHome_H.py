"""
Nina Demenchukova
CIS 41A   Fall 2018"
Take-Home Assignments Unit H
"""
print("Sample Execution Results: ")
#First Script - Variable-Length Keyword Arguments - kwargs 
def overseerSystem(**kwargs):
    if "temperature" in kwargs:
        if kwargs["temperature"] > 500:
            print ("Warning: temperature is", kwargs["temperature"])
    if "CO2level" in kwargs:
        if kwargs["CO2level"] > 0.15:
            print ("Warning: CO2level is", kwargs["CO2level"])
    if "miscError" in kwargs:
        print ("Misc error #" + str(kwargs["miscError"]))

overseerSystem(temperature=550)
overseerSystem(temperature=475)
overseerSystem(temperature=450, miscError=404)
overseerSystem(CO2level=.18)
overseerSystem(CO2level=0.2, miscError=418)

print("Second Script - Operator Overloading")

import math

class BritCoins():
    __coinValues = {"pound":240, "shilling":12, "penny":1} # value of each type of coin in pennies 
    def __init__(self, **kwargs):
        self.totalPennies = 0     
        for coinType in kwargs:
            self.totalPennies += (self.__coinValues[coinType] * kwargs[coinType])
    def __add__ (self, other):
        total = self.totalPennies + other.totalPennies
        return BritCoins(penny=total)
    def __sub__(self, other):
        total = self.totalPennies - other.totalPennies
        return BritCoins(penny=total)
    def __str__(self):
        resultString = ""
        remainingPennies = self.totalPennies
        pound = remainingPennies // self.__coinValues["pound"]
        if pound != 0:
            resultString += (" " + str(pound) + " pounds")
            remainingPennies -= (pound * self.__coinValues["pound"])
        shilling = math.floor(remainingPennies // self.__coinValues["shilling"])
        if shilling != 0:
            resultString += (" " + str(shilling) + " shillings")
            remainingPennies -= (shilling * self.__coinValues["shilling"])
        penny = math.floor(remainingPennies // self.__coinValues["penny"])
        if penny != 0:
            resultString += (" " + str(penny) + " pennies")
            remainingPennies -= (penny * self.__coinValues["penny"])
        return (resultString)
    
c1 = BritCoins(pound=4, shilling=24, penny=3)
c2 = BritCoins(pound=3, shilling=4, penny=5)
c3 = c1 + c2
c4 = c1 - c2

print ("c1:" + str(c1))
print ("c2:" + str(c2))
print ("c3:" + str(c3))
print ("c4:" + str(c4))
