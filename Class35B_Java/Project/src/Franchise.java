


public class Franchise {
	private Store stores[];

	public Franchise(int num) {
		stores = new Store[num];
	}

	public Store getStores(int i) {
		return stores[i];
	}

	public void setStores(Store stores, int i) {
		this.stores[i] = stores;
	}

	public int numberofstores() {
		return stores.length;
	}

	public void calc() {
		for (int i = 0; i < stores.length; i++) {
			stores[i].analyze();
		}
	}
	
	public void print() {
		System.out.printf("Franchise:\n");
		for (int i = 0; i < stores.length; i++) {
			System.out.printf("  Store[%d] = \n", i);
			stores[i].printdata();
		}
	}

}
