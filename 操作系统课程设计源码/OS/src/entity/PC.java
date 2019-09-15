package entity;

import os.Test;
import util.TimeThread;

public class PC {
	
	private int pcbpost;
	
	private int nextpoint;

	public int getPcbpost() {
		return pcbpost;
	}

	public void setPcbpost(int pcbpost) {
		this.pcbpost = pcbpost;
	}

	public int getNextpoint() {
		return nextpoint;
	}

	public void setNextpoint(int nextpoint) {
		this.nextpoint = nextpoint;
	}

	public PC(int pcbpost, int nextpoint) {
		super();
		this.pcbpost = pcbpost;
		this.nextpoint = nextpoint;
	}

	@Override
	public String toString() {
		return "PC [pcbpost=" + pcbpost + ", nextpoint=" + nextpoint + "]";
	}
	
	public static void Test()
	{
		System.out.println("1");
		new TimeThread(5).run();
		System.out.println("2");
	}
	
	public static void main(String[] args) {
		PC.Test();
	}
}
