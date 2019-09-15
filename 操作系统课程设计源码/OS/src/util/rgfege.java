package util;

import entity.PCB;
import os.OS;

public class rgfege {
	public static void main(String[] args) {
		PCB pcb=new PCB();
		pcb.setIntitle(2);
		
		OS.pcbs.add(pcb);
		PCB a=OS.pcbs.get(0);
		a.setIntitle(8);
		System.out.println(OS.pcbs.get(0).getIntitle());
	}
}
