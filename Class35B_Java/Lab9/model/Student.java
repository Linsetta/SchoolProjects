package model;

import java.io.Serializable;

public class Student implements Serializable {

	private static final long serialVersionUID = 1L; // error  fixed by compiler
	private int SID;
	private int scores[] = new int[5];
	
	// Constructor
	public Student()
	{
	}
	
	public Student(int SID, int[] scores)
	{
		this.SID = SID;
		this.scores = scores;
	}
	
	
	public int getSID() {
		return SID;
	}
	public void setSID(int sID) {
		SID = sID;
	}
	public int[] getScores() {
		return scores;
	}
	public void setScores(int[] scores) {
		this.scores = scores;
	}

	public void setScores(int score1, int score2, int score3, int score4, int score5) {
		this.scores = new int[5];
		this.scores[0] = score1;
		this.scores[1] = score2;
		this.scores[2] = score3;
		this.scores[3] = score4;
		this.scores[4] = score5;
	}
	
	public String getGrade() {
		double score = totalScore();
		String c = "F";
		if (score>=0.6) {
			c = "D-";
			if (score>=0.63) {
				c = "D";
				if (score>=0.7) {
					c = "D+";
					if (score>=0.73) {
						c = "C";
						if (score>=0.77) {
							c = "C+";
							if (score>=0.8) {
								c = "B-";
								if (score>=0.83) {
									c = "B";
									if (score>=0.87) {
										c = "B+";
										if (score>=0.9) {
											c = "A-";
											if (score>=0.93) {
												c = "A";
												if (score>=0.97)
													c = "A+";
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return c;
	}

	public double totalScore() {
		double d = 0;
		if (scores.length>0) {
			for (int i=0; i<scores.length; i++) {
				d += this.scores[i];
			}
			d = d/(100*scores.length);
		}
		return d;
	}
	
	public  void print() {
		System.out.printf("\n%d ", this.SID);
		for (int i=0; i<scores.length; i++) {
			System.out.printf("%03d ", this.scores[i]);
		}
	}
}
