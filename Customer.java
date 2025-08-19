public class Customer {

	private String name;
	private byte age;
	private boolean isLicensed;
	private int kartCapacity;
	private String helmetSize;
	private String suitSize;
	private byte shoeSize;
	private boolean isMember;

	final double PRICE_PER_CC = 0.3;
	final double MEMBERSHIP_DISCOUNT = 0.1;

	public Customer() {
		name = "";
		age = 0;
		isLicensed = false;
		kartCapacity = 0;
		helmetSize = "";
		suitSize = "";
		shoeSize = 0; 
	}

	public Customer(String name, byte age, boolean isLicensed) {
		this.name = name; 
		this.age = age;
		this.isLicensed = isLicensed;
		kartCapacity = 0;
		helmetSize = "";
		suitSize = "";
		shoeSize = 0; 
	}

	// Mutators @ Setters
	public void setName(String name) {
		this.name = name;
	}

	public void setAge(byte age) {
		this.age = age;
	}

	public void setLicense(boolean isLicensed) {
		this.isLicensed = isLicensed;
	}

	public void setKartCapacity(int cc) {
		kartCapacity = cc;
	}

	public void setHelmetSize(String size) {
		helmetSize = size;
	}

	public void setSuitSize(String size) {
		suitSize = size;
	}

	public void setShoeSize(byte size) {
		shoeSize = size;
	}

	public void setMembership(boolean isMember) {
		this.isMember = isMember;
	}

	// Accessors @ Getters
	public String getName() {
		return name;
	}

	public byte getAge() {
		return age;
	}

	public boolean getLicense() {
		return isLicensed;
	}

	public int getKartCapacity() {
		return kartCapacity;
	}

	public double getKartPrice() {
		return kartCapacity * PRICE_PER_CC;
	}

	public String getHelmetSize() {
		return helmetSize;
	}

	public String getSuitSize() {
		return suitSize;
	}

	public byte getShoeSize() {
		return shoeSize;
	}

	public boolean getMembership() {
		return isMember;
	}

	// Racing Gear Prices
	public double getHelmetPrice() {
		if (helmetSize == "S")
			return 2;
		if (helmetSize == "M")
			return 4;
		if (helmetSize == "L")
			return 6;
		if (helmetSize == "XL")
			return 8;
		else
			return -1;
	}

	public double getSuitPrice() {
		if (suitSize == "S")
			return 5;
		if (suitSize == "M")
			return 10;
		if (suitSize == "L")
		    	return 15;
		if (suitSize == "XL")
			return 20;
		else
			return -1;
	}

	public double getShoePrice() {
		return shoeSize;
	}

	public boolean getMembership() {
		return isMember;
	}

	public double getMembershipDiscount() {
		return isMember == true ? MEMBERSHIP_DISCOUNT : 0;
	}

}

