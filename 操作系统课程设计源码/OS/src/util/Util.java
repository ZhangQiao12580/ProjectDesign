package util;

import java.util.List;

import os.OS;

/*** @author hp
* @date : 2018年12月8日 上午9:36:07*/
public class Util {
	
	/**
	 * @return 返回pcb在就绪或等待队列中的位置
	 * **/
	public static int getPcbIndex(List<Integer> list,int pcborder)
	{
		for (int i = 0; i < list.size(); i++) {
			if(list.get(i)==pcborder)
			{
				return i;
			}
		}
		return -1;
	}
	
}
