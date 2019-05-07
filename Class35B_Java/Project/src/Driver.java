import java.util.Scanner;

public class Driver {
	
	private static void printTotalSalesForWeek(int stores, Franchise f) {
		for (int i = 0; i < 5; i ++) {
			float weekTotalSales = f.getStores(stores - 1).getTotalSalesForWeek(i);
			System.out.printf("    store[%d].week[%d].totalSales = %.02f\n", stores, i + 1, weekTotalSales);
		}
	}
	
	private static void printAverageSalesForWeek(int stores, Franchise f) {
		for (int i = 0; i < 5; i ++) {
			float weekAvgSales = f.getStores(stores - 1).getAverageSalesForWeek(i);
			System.out.printf("    store[%d].week[%d].averageSales = %.02f\n", stores, i + 1, weekAvgSales);
		}
	}
	
	private static void printTotalSalesForAllWeeks(int stores, Franchise f) {
		float totalSales = f.getStores(stores - 1).getTotalSalesForAllWeeks();
		System.out.printf("    store[%d].totalSales = %.02f\n", stores, totalSales);
	}
	
	private static void printAverageWeeklySales(int stores, Franchise f) {
		float avgWeeklySales = f.getStores(stores - 1).getAverageWeeklySales();
		System.out.printf("    store[%d].averageWeeklySales = %.02f\n", stores, avgWeeklySales);
	}
	
	private static void printWeekWithHighestSalesAmount(int stores, Franchise f) {
		int highestWeek = f.getStores(stores - 1).getWeekWithHighestSalesAmount() + 1;
		System.out.printf("    store[%d].weekWithHighestSalesAmount = %d\n", stores, highestWeek);
	}
	
	private static void printWeekWithLowestSalesAmount(int stores, Franchise f) {
		int lowestWeek = f.getStores(stores - 1).getWeekWithLowestSalesAmount() + 1;
		System.out.printf("    store[%d].weekWithLowestSalesAmount = %d\n", stores, lowestWeek);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FileIO a1 = new FileIO("/home/linsetta/Desktop/deanza/Java/Java 35B/assignment336b/src/Salesdat.txt");
		Franchise f = a1.readData();
		f.calc();
		//f.print();
	
		int stores = 0;
		int operations = -1;
		System.out.printf("Welcome to analyzer." + "\n");
		System.out.printf("The data about stores 1 through 5 is available." + "\n");
		System.out.printf("Please, enter the number of store which data would  your like to analyze. "
				+ "or please enter '6', if you want to see all presents stores  : " + "\n");
		Scanner input = new Scanner(System.in);
		while (stores < 1 || stores > 6) {
			stores = input.nextInt();
			if (stores < 1 || stores > 6) {
				System.out.printf("Store must be 1 through 6.\n");
			}
		}
		while (operations < 0 || operations > 6) {
			System.out.printf(
				"Please, enter the number of operations which data would your like to analyze. "
						+ "or please enter '0', if you want to see all informations about the store number %d\n",
				stores);
			System.out.printf("1.Total Sales For Week " + "\n");
			System.out.printf("2.Average Sales For Week " + "\n");
			System.out.printf("3.Total Sales For All Weeks " + "\n");
			System.out.printf("4.Average Weekly Sales " + "\n");
			System.out.printf("5.Week With  HighestSale Amt " + "\n");
			System.out.printf("6.Week With LowestSale Amt " + "\n");
			System.out.printf("0.All operations" + "\n");
			operations = input.nextInt();
			if (operations < 0 || operations > 6) {
				System.out.printf("Please choose a valid operation (0 through 6).\n");
			}
		}
		switch (operations) {
		case 1:
			printTotalSalesForWeek(stores, f);
			break;
		case 2:
			printAverageSalesForWeek(stores, f);
			break;
		case 3:
			printTotalSalesForAllWeeks(stores, f);
			break;
		case 4:
			printAverageWeeklySales(stores, f);
			break;
		case 5:
			printWeekWithHighestSalesAmount(stores, f);
			break;
		case 6:
			printWeekWithLowestSalesAmount(stores, f);
			break;
		case 0:
			printTotalSalesForWeek(stores, f);
			printAverageSalesForWeek(stores, f);
			printTotalSalesForAllWeeks(stores, f);
			printAverageWeeklySales(stores, f);
			printWeekWithHighestSalesAmount(stores, f);
			printWeekWithLowestSalesAmount(stores, f);
			break;
		default:
			System.out.printf("That is an invalid operation.\n");
			break;
		}
	}

}