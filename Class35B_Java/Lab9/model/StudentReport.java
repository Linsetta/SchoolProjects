package model;

import java.io.Serializable;

public class StudentReport implements Serializable{ // fixed error by compiler proposale
		 /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
		//we will serialize instances of Student Report.
		 private Student x; //for one student
		 private Statistics y; //for entire class.

		 public StudentReport(Student x, Statistics y) 
		 {
			 this.setStudent(x);
			 this.setStatistics(y);
		 }

		public Student getStudent() {
			return x;
		}

		public void setStudent(Student x) {
			this.x = x;
		}

		public Statistics getStatistics() {
			return y;
		}

		public void setStatistics(Statistics y) {
			this.y = y;
		}

		public void print() {
			System.out.printf("\nThe student data:");			
			this.x.print();
			System.out.printf("\nStatistics:");
			this.y.print();
		}
		
		
		}
