package os;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import entity.PCB;

public class OS {
	
	public static List<PCB> pcbs=new ArrayList<>();
	
	public static String catches[]=new String[128];
	
	//��������,��ŵ�����pcb����������
	public static List<Integer> preparelist=new ArrayList<>();
	
	//�ȴ�����
	public static List<Integer> waitlist=new ArrayList<>();
	
	//��ռ���ڴ�
	public static Map<Integer,Integer> emptycatch=new HashMap<>();
	
	//���ڴ�
	public static Map<Integer, Integer> fullcatch=new HashMap<>();
	
	//�жϱ�־
	public static Boolean interfalg = false;
}
