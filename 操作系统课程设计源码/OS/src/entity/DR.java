package entity;

public class DR {
	private Integer x;

	public Integer getX() {
		return x;
	}

	public void setX(Integer x) {
		this.x = x;
	}

	public DR(Integer x) {
		super();
		this.x = x;
	}

	@Override
	public String toString() {
		return "DR [x=" + x + "]";
	}
}
