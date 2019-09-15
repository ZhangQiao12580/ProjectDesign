package entity;

public class IR {
	private String nowpoint;

	public String getNowpoint() {
		return nowpoint;
	}

	public void setNowpoint(String nowpoint) {
		this.nowpoint = nowpoint;
	}

	public IR(String nowpoint) {
		super();
		this.nowpoint = nowpoint;
	}

	@Override
	public String toString() {
		return "IR [nowpoint=" + nowpoint + "]";
	}
}
