import java.util.Scanner;

public class Store {
	private float salesbyweek[][];

	Store() {
		salesbyweek = new float[5][7];
	}

	// getter and setters
	// setsaleforweekdayintersection(int week, int day, float sale)
	public void setsaleforweekdayintersection(int week, int day, float sale) {
		salesbyweek[week][day] = sale;
	}

	float[] getsalesforentireweek(int week) {
		return salesbyweek[week];
	}

	float getsaleforweekdayintersection(int week, int day) {
		return salesbyweek[week][day];
	}

	private float totalSalesForWeek[] = new float[5];
	private float averageSalesForWeek[] = new float[5];
	private float totalSalesForAllWeeks;
	private float averageWeeklySales;
	private int weekWithHighestSaleAmt;
	private int weekWithLowestSaleAmt;
	
	public float getTotalSalesForWeek(int week) {
		float sum = 0;
		// loop j for each day of week
		for (int j = 0; j < 7; j++) {
			sum = sum + salesbyweek[week][j];
		}
		return sum;		
	}
	
	private void analyzeTotalSalesForWeek() {
		int i; // week
		// loop i for each week
		for (i = 0; i < 5; i++) {
			totalSalesForWeek[i] = getTotalSalesForWeek(i);
		}
	}

	public float getAverageSalesForWeek(int week) {
		return totalSalesForWeek[week] / 7;
	}
	
	private void analyzeAvgSalesForWeek() {
		int i;
		for (i = 0; i < 5; i++) {
			averageSalesForWeek[i] = getAverageSalesForWeek(i);
		}
	}
	
	public float getTotalSalesForAllWeeks() {
		float sum = 0;
		for (int i = 0; i < 5; i++) {
			sum = sum + totalSalesForWeek[i];
		}
		return sum;
	}
	
	private void analyzeTotalSalesForAllWeeks() {
		totalSalesForAllWeeks = getTotalSalesForAllWeeks();
	}
	
	public float getAverageWeeklySales() {
		return totalSalesForAllWeeks / 5;
	}
	
	private void analyzeAverageWeeklySales() {
		averageWeeklySales = getAverageWeeklySales();
	}

	public int getWeekWithHighestSalesAmount() {
		int i;
		int week = -1;
		float highest = -1;
		for (i = 0; i < 5; i++) {
			if (totalSalesForWeek[i] > highest) {
				highest = totalSalesForWeek[i];
				week = i;
			}
		}
		return week;
	}
	
	private void analyzeWeekWithHighestSaleAmt() {
		weekWithHighestSaleAmt = getWeekWithHighestSalesAmount();
	}
	
	public int getWeekWithLowestSalesAmount() {
		int i;
		int week = -1;
		float lowest = 0;
		for (i = 0; i < 5; i++) {
			if (week == -1 || totalSalesForWeek[i] < lowest) {
				lowest = totalSalesForWeek[i];
				week = i;
			}
		}
		return week;
	}
	
	private void analyzeWeekWithLowestSaleAmt() {
		weekWithLowestSaleAmt = getWeekWithLowestSalesAmount();		
	}

	public void analyze() {
		analyzeTotalSalesForWeek(); // a.
		analyzeAvgSalesForWeek(); // b.
		analyzeTotalSalesForAllWeeks(); // c.
		analyzeAverageWeeklySales(); // d.
		analyzeWeekWithHighestSaleAmt(); // e.
		analyzeWeekWithLowestSaleAmt(); // f.
	}

	public void printdata() {
		for (int i = 0; i < 5; i++) {
			System.out.printf("    week[%d] = (", i);
			for (int j = 0; j < 7; j++) {
				System.out.printf(salesbyweek[i][j] + " ");
			}
			System.out.printf(")\n");
			// a. (print out weekly analyze results)
			System.out.printf("    week[%d].totalSales = %.02f\n", i, totalSalesForWeek[i]);
			// b. (print out weekly analyze results)
			System.out.printf("    week[%d].averageSales = %.02f\n", i, averageSalesForWeek[i]);
		}
		System.out.printf("");
		// . (print out global data results)
		System.out.printf("Total sales for all weeks: %.02f\n", totalSalesForAllWeeks);
		// c. (print out global data results)
		System.out.printf("Average weekly sales: %.02f\n", averageWeeklySales);
		// d. (print out global data results)
		System.out.printf("Week with highest sales amount: %d\n", weekWithHighestSaleAmt);
		// e. (print out global data results)
		System.out.printf("Week with lowest sales amount: %d\n", weekWithLowestSaleAmt);
		// f. (print out global data results)
		// ...
	}
}
