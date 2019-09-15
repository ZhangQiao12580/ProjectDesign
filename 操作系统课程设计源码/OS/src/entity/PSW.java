package entity;

import java.util.ArrayList;
import java.util.List;

import util.FileOp;

public class PSW {
	/*public static void main(String[] args) {
		String string="1234";
		System.out.println(string.substring(2,3));
		FileOp.resWrite("123.txt", 1218646);
	}*/
	//0¾ÍĞ÷Ì¬ 1×èÈûÌ¬
	public int state;

	public int getState() {
		return state;
	}

	public void setState(int state) {
		this.state = state;
	}

	public PSW(int state) {
		super();
		this.state = state;
	}

	@Override
	public String toString() {
		return "PSW [state=" + state + "]";
	}
}
