package Driver;

import util.*;
import model.*;
//import java.io.*;
import Adapter.*;
import java.util.Scanner;

public class Driver {

	public static void main(String[] args) {
		 //Test Instructor interface
		 Creatable p1 = new GradeBook();
		 Creatable p2 = new GradeBook();
		 
		 p1.createGradeBook("input5");
		 p2.createGradeBook("input4");
		 
		 System.out.printf("Subject 1 gradebook:\n");
		 p1.printGradeBook();
		 System.out.printf("Subject 2 gradebook:\n");		 
		 p2.printGradeBook();		 

		 Scanner reader = new Scanner(System.in);
		 p1.getGradesInteractive(reader, "\nInput id for subj1 or 0 to stop: ");
		 p2.getGradesInteractive(reader, "\nInput id for subj2 or 0 to stop: ");
		 reader.close();
		 
		 Printable s1 = (Printable)p1;
		 Printable s2 = (Printable)p2;
		 
		 System.out.printf("\nOther test subj1:");
		 s1.getStats();
		 s1.printstudentscores(7875);
		 s1.printstudentgrade(7875);

		 System.out.printf("\nOther test subj2:");		 
		 s2.getStats();		 
		 s2.printstudentscores(1134);
		 s2.printstudentgrade(1134);
		 s1.printstudentscores(9111); //invalid student id shld print a f 
		 
		 System.out.print("\nEXIT");
	 }
	
}
	
