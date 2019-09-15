package os;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import entity.PCB;

public class OS {
	
	public static List<PCB> pcbs=new ArrayList<>();
	
	public static String catches[]=new String[128];
	
	//就绪队列,存放的是在pcb池里面的序号
	public static List<Integer> preparelist=new ArrayList<>();
	
	//等待队列
	public static List<Integer> waitlist=new ArrayList<>();
	
	//已占用内存
	public static Map<Integer,Integer> emptycatch=new HashMap<>();
	
	//空内存
	public static Map<Integer, Integer> fullcatch=new HashMap<>();
	
	//中断标志
	public static Boolean interfalg = false;
}
