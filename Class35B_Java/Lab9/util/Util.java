package util;
import model.*;
import java.io.*;
import java.util.*;

public class Util {

	public Student[] readFile(String filename, Student[] stu) { 
		int i = 0;
		try {
			FileReader file = new FileReader(filename);
			BufferedReader buff = new BufferedReader(file);
			boolean eof = false;
			while (!eof && i<stu.length) {
				String line = buff.readLine();
				if (line == null)
					eof = true;
				else {
					if (!line.startsWith("Stud"))
						stu[i++] = getStudent(line);
				}
			 }
		 buff.close();
		 } catch (IOException e) {
		     System.out.println("Error -- " + e.toString());
		 }
		
		Student[] newArray = new Student[i];
		System.arraycopy(stu, 0, newArray, 0, i);
		
		return newArray;
	}
	
	public void writeStudentReporttodisk(StudentReport a1, String fname)
	{
		 try {
			 FileOutputStream p = new FileOutputStream(fname);
			 ObjectOutputStream p1 = new ObjectOutputStream(p);
			 p1.writeObject(a1);
			 p1.close();
		 } 
		 catch(Exception e)
		 {
		     System.out.println("Error -- " + e.toString());
		 }
	}

	 public StudentReport readStudentReportfromdisk(String fname)
	 {
		 StudentReport a= null;
		 try {
			 FileInputStream p = new FileInputStream(fname);
			 ObjectInputStream p1 = new ObjectInputStream(p);
			 a = (StudentReport )p1.readObject(); 
			 p1.close();
		 }
		 catch(FileNotFoundException e)
		 {
			 // no error message - just wrong name used
			 return null;
		 }
		 catch(Exception e)
		 {
		     System.out.println("Error -- " + e.toString());
		 } 
		 return a;
	 }
	 
		public void writeInstructorReporttodisk(InstructorReport a1, String fname)
		{
			try {
				FileOutputStream p = new FileOutputStream(fname);
				ObjectOutputStream p1 = new ObjectOutputStream(p);
				p1.writeObject(a1); 
			} 
			catch(Exception e)
			{
				System.out.println("Error -- " + e.toString());
			}
		}

		 public InstructorReport readInstructorReportfromdisk(String fname)
		 {
			 InstructorReport a= null;
			 try {
				 FileInputStream p = new FileInputStream(fname);
				 ObjectInputStream p1 = new ObjectInputStream(p);
				 a = (InstructorReport)p1.readObject(); 
			 } 
			 catch(Exception e)
			 {
				 System.out.println("Error -- " + e.toString());
			 } 
			 return a;
		 }


	public String getAnySer(final String fileName) {
        File dir = new File(".");   

        File[] fileList = dir.listFiles(new FilenameFilter() {
            public boolean accept(File dir, String name) {
                return name.endsWith(".ser") && name.startsWith(fileName);
            }
        });
        
        return fileList[0].getName();
	}
	 
	private Student getStudent(String s) {
		String[] r = new String[6];
		Student student = new Student();

		StringTokenizer st = new StringTokenizer(s);
		int i = 0;

	    while (st.hasMoreTokens()) {
	    	r[i++] = st.nextToken();
	    }
	    
	    student.setSID(Integer.parseInt(r[0]));
	    student.setScores(Integer.parseInt(r[1]), 
	    		Integer.parseInt(r[2]), 
	    		Integer.parseInt(r[3]), 
	    		Integer.parseInt(r[4]), 
	    		Integer.parseInt(r[5]));
		
		return student;
	}
	
}