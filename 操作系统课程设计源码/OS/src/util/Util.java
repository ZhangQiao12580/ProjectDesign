package util;

import java.util.List;

import os.OS;

/*** @author hp
* @date : 2018��12��8�� ����9:36:07*/
public class Util {
	
	/**
	 * @return ����pcb�ھ�����ȴ������е�λ��
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
