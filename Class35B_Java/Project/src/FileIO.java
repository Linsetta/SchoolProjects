import java.io.*;
import java.util.*;

public class FileIO {
	private String fname = null;
	private boolean DEBUG = false;

	public FileIO(String fname) {
		this.fname = fname;
	}

	public Franchise readData() { //method for reading Franchise
		Franchise a1 = null; // trying to create Franchise
		int counter = 0; // create a counter of lines in the file
		try { // try to read a Frinchise
			FileReader file = new FileReader(fname); // opening file for reading data. 
			BufferedReader buff = new BufferedReader(file); // create a buffer reader
			String temp; // temprorary string variable
			boolean eof = false; // signal that end of file is reached
			while (!eof) { // reading data from a file while not eof
				String line = buff.readLine(); // reading line from a file
				counter++; // increament line counter
				if (line == null) // if line fail to read
					eof = true; // we reached eof
				else { 
					if (DEBUG) // only if debuging
						System.out.println("Reading" + line);  // show line on screan
					if (counter == 1) {  // if its the first line
						temp = line; // store line in the temprorary variable
						a1 = new Franchise(Integer.parseInt(temp)); // atempt to create a new frinchise
						if (DEBUG)  // only if debuging
							System.out.println("d  " + a1.numberofstores()); // prints a number of stores
					}
					if (counter == 2) // if second line of a file do nothing
						;
					if (counter > 2) { //otherwise
						  	int x = buildStore(a1, (counter-3), line); // creating a store
							if (DEBUG) // only if debuging
								System.out.println("Reading Store # "+(counter-2)+" Number of weeks read =  " +  x);// print store data
							if (DEBUG)  // only if debuging
							{	
								System.out.println("Data read:");  // prints a store data 
								a1.getStores(counter-3).printdata(); //function call to print store data
							}
					}
				}
			}
			buff.close(); // close file
		} catch (Exception e) { //if error 
			System.out.println("Error -- " +  e.toString()); // error validation
		}
		return a1; // Franchise a1 created
	}

	public int buildStore(Franchise a1, int counter, String temp) { // function to fill out store data
		Store tstore = new Store(); // create a new store
		String s1  =  ""; // variable to store number of sales for the day
		float sale = 0.0f; //variable  to store store sales
		int week = 0; // variable  to store  number of week sales
		int day = 0; //variable  to store sales by the week  day
		StringTokenizer st = new StringTokenizer(temp); // creates a new Tokenizer
	    while (st.hasMoreTokens()) { // loop through the tokens in the line
	         for(day=0;day<7;day++)
	         {
		    	 s1 = st.nextToken(); // reads the token - number of sales for the day
		         sale = Float.parseFloat(s1); // turning string into float
	        	 tstore.setsaleforweekdayintersection(week, day, sale); // set sale data for week and day
	         }
	         week++; // incrementing weeks
	    }
		a1.setStores(tstore, counter); // function call for 
	    return week; //  returns the weeks  of data in the store
	}
}
