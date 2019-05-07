package Adapter;
import java.util.Scanner;

public interface Creatable {
	public void createGradeBook(String fname);
	public void printGradeBook();
	public void getGradesInteractive(Scanner reader, String requestString);
}
