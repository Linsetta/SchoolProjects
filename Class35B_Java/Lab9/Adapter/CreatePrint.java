package Adapter;

import java.util.Scanner;

import model.*;
import util.*;
public abstract class CreatePrint implements Creatable, Printable {

	 private Util u = new Util();
	 private Student arr[] = new Student[40];
	 private Statistics s = new Statistics();
	 private StudentReport arr2[] = new StudentReport[40];
	 private String fileName;

	 public void createGradeBook(String fname) { 
		fileName = fname;
		arr = u.readFile(fname + ".txt", arr);
		
		if (arr.length>0) {
				
				s.findavg(arr);
				s.findlow(arr);
				s.findhigh(arr);
				
				arr2 = new StudentReport[arr.length];
				for(int i=0;i<arr.length;i++)
				{
					 if(arr[i]!=null) {
						 arr2[i] = new StudentReport(arr[i], s);
						 u.writeStudentReporttodisk(arr2[i], fileName+"."+arr2[i].getStudent().getSID()+".ser" );
					 }
				}
				
				InstructorReport rep = new InstructorReport(arr, s);
				u.writeInstructorReporttodisk(rep, fileName + ".gradebook");
				
			} else
			{
				System.out.printf("No data");
			}
	 }

	 public void printGradeBook() { 
		 InstructorReport rep = u.readInstructorReportfromdisk(fileName + ".gradebook");
		 if (DEBUG) {
			 if (rep != null)
				 rep.print();
			 else
				 System.out.printf("\n\nNot found");
			 System.out.printf("\n\n");
		 }
	 }
	 
	 //use debug flag for printing. if debug = true then print other no printing.

	public void getStats() {
		
		Util fname = new Util();
		String name = fname.getAnySer(fileName);
		
		StudentReport studentReport = fname.readStudentReportfromdisk(name);
		if (DEBUG) {
			if (studentReport != null)
				studentReport.getStatistics().print();
			else
				System.out.printf("\n\nNot found");
		}
	}

	public void printstudentscores(int id) {
		String name = fileName + "." + id+".ser";
		Util fname = new Util();
		StudentReport studentReport = fname.readStudentReportfromdisk(name);
		if (DEBUG) {
			if (studentReport != null)
				studentReport.getStudent().print();
			else
				System.out.printf("\n\nNot found");
		}
	}
	
	public void getGradesInteractive(Scanner reader, String requestString) {	
		 System.out.print(requestString);
		 int id = 0;
		 while((id = reader.nextInt()) > 0) {
			 printstudentgrade(id);
			 System.out.print(requestString);			 
		 }
	}

	
	public void printstudentgrade(int id) {
		String name = fileName + "." + id+".ser";
		Util fname = new Util();
		StudentReport studentReport = fname.readStudentReportfromdisk(name);
		if (DEBUG) {
			if (studentReport != null)
			{
				String ts = studentReport.getStudent().getGrade();
				System.out.printf("\nGrade: %s", ts);
			}
			else
				System.out.printf("\n\nNot found");
		}
	}
}