package model;
import java.io.Serializable;

public class InstructorReport implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Student s[] = null;
	private Statistics st = null;

	public InstructorReport(Student[] s, Statistics st) {
		this.s = s;
		this.st = st;
	}

	public void print(int id) {
		System.out.printf("Stud Qu1 Qu2 Qu3 Qu4 Qu5 Grade");
		for(int i=0; i<s.length; i++) {
			if (s[i].getSID() == id) {
				s[i].print();
				System.out.printf(" %s", s[i].getGrade());
			}
		}
		System.out.printf("\n");
		st.print();
	}

	
	public void print() {
	
		System.out.printf("Stud Qu1 Qu2 Qu3 Qu4 Qu5 Grade");
		for(int i=0; i<s.length; i++) {
			s[i].print();
			System.out.printf(" %s", s[i].getGrade());
		}
		
		System.out.printf("\n");
		
		st.print();
		
	}
}
