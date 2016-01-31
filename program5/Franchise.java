//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #3
//Due: 1/27/2016
//Handed: 1/26/2016

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
	
}
