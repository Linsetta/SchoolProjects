package model;

import java.io.Serializable;

public class Statistics implements Serializable {

	private static final long serialVersionUID = 1L; // error  fixed by compiler

	private int[] lowscores = new int[5];
	public int[] getLowscores() {
		return lowscores;
	}

	public void setLowscores(int[] lowscores) {
		this.lowscores = lowscores;
	}

	public int[] getHighscores() {
		return highscores;
	}

	public void setHighscores(int[] highscores) {
		this.highscores = highscores;
	}

	public float[] getAvgscores() {
		return avgscores;
	}

	public void setAvgscores(float[] avgscores) {
		this.avgscores = avgscores;
	}

	private int[] highscores = new int[5];
	private float[] avgscores = new float[5];

	public void findlow(Student[] a) {
		if (a.length > 0) {
			for (int i = 0; i < 5; i++) {
				lowscores[i] = Integer.MAX_VALUE;
				for (int k = 0; k < a.length; k++) {
					if (lowscores[i] > a[k].getScores()[i])
						lowscores[i] = a[k].getScores()[i];
				}
			}
		}
	}

	public void findhigh(Student[] a) {
		if (a.length > 0) {
			for (int i = 0; i < 5; i++) {
				highscores[i] = Integer.MIN_VALUE;
				for (int k = 0; k < a.length; k++) {
					if (highscores[i] < a[k].getScores()[i])
						highscores[i] = a[k].getScores()[i];
				}
			}
		}
	}

	public void findavg(Student[] a) {
		if (a.length > 0) {
			for (int i = 0; i < 5; i++) {
				for (int k = 0; k < a.length; k++) {
					avgscores[i] += (float) a[k].getScores()[i];
				}
				avgscores[i] /= a.length;
			}
		}
	}

	public void print() {

		System.out.printf("\nlow scores: ");
		for (int i = 0; i < 5; i++)
			System.out.printf(" %d", lowscores[i]);

		System.out.printf("\nhigh scores: ");
		for (int i = 0; i < 5; i++)
			System.out.printf(" %d", highscores[i]);

		System.out.printf("\naverage scores:");
		for (int i = 0; i < 5; i++)
			System.out.printf(" %.1f", avgscores[i]);
	}
}
