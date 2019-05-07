"""
Nina Demenchukova
CIS 41A   Fall 2018"
Take-Home Assignments Unit I
"""

class LibraryPatron():
    def __init__(self, name):
        self.name            = name
        self.booksCheckedOut = []
    
    def checkOutBook(self, checkOutLimit, bookTitle):
        if len(self.booksCheckedOut) == checkOutLimit:
            print ("Sorry", self.name, "you are at your limit of",       checkOutLimit, "books")
        else:
            self.booksCheckedOut.append(bookTitle)
            print(self.name, "has checked out", bookTitle)
   
    def returnBook(self, book):
        title = book[0]
        for index in range(0, len(self.booksCheckedOut) - 1):
            checkedOutBookTitle = self.booksCheckedOut[index]
            if title == checkedOutBookTitle:
                self.booksCheckedOut.pop(index)
                print (self.name, "has returned", title)
         
    def printCheckedOutBooks(self):
        print (self.name, "has the following books checked out:")
        for bookTitle in self.booksCheckedOut:
            print (bookTitle)
      
class AdultPatron(LibraryPatron):
    def __init__(self, name):
        LibraryPatron.__init__(self, name)
        self.checkOutLimit = 4
      
    def checkOutBook(self, book):
        bookTitle = book[0]
        LibraryPatron.checkOutBook(self, self.checkOutLimit, bookTitle)
      
class JuvenilePatron(LibraryPatron):
    def __init__(self, name):
        LibraryPatron.__init__(self, name)
        self.checkOutLimit = 2
   
    def checkOutBook(self, book):
        bookTitle = book[0]
        bookType  = book[1]
        if bookType == "Juvenile":
            LibraryPatron.checkOutBook(self, self.checkOutLimit, bookTitle)
        else:
            print("Sorry", self.name, bookTitle, "is an adult book")


print("Sample Execution Results: ")

book1 = ["Alice in Wonderland", "Juvenile"]
book2 = ["The Cat in the Hat", "Juvenile"]
book3 = ["Harry Potter and the Sorcerer's Stone", "Juvenile"]
book4 = ["The Hobbit", "Juvenile"]
book5 = ["The Da Vinci Code", "Adult"]
book6 = ["The Girl with the Dragon Tattoo", "Adult"]
           
patron1 = JuvenilePatron("Jimmy")
patron2 = AdultPatron("Sophia")
      
patron1.checkOutBook(book6)
patron1.checkOutBook(book1)
patron1.checkOutBook(book2)
patron1.printCheckedOutBooks()
patron1.checkOutBook(book3)
patron1.returnBook(book1)
patron1.checkOutBook(book3)
patron1.printCheckedOutBooks()
patron2.checkOutBook(book5)
patron2.checkOutBook(book4)
patron2.printCheckedOutBooks()         
   
