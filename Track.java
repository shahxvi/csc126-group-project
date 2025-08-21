public class Track {

	private String format;
	private String name;

	public Track(String format, String name) {
		this.format = format;
		this.name = name;
	}

	public setFormat(String format) {
		this.format = format;
		this.name = "";
	}

	public setName(String name) {
		this.format = "";
		this.name = name;
	}

	public Track() {
		this.format = "";
		this.name = "";
	}

	public String getFormat() {
		return format;
	}

	public String getName() {
		return name;
	}

}

