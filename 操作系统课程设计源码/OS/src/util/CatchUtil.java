package util;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import os.OS;

/*** @author hp
* @date : 2018��12��8�� ����2:43:05*/
public class CatchUtil {
	
	//�ڴ���䣬�����ڴ������ʼλ��
	public static int catchAllocate(String []orders)
	{
		String strs[]=OS.catches;
		int length=orders.length;
		Map<Integer, Integer> map=OS.emptycatch;
		Set<Integer> keys= map.keySet();
		int mink=-1,minv=129;
		Boolean isinsert=false;
		
		for(Integer key:keys)
		{
			int value=map.get(key);
			if(value>=length&&value<minv)
			{
				mink=key;
				minv=value;
				isinsert=true;
			}
		}
		for (int i = 0; i < length; i++) {
			strs[mink+i]=orders[i];
		}
		
		int value=map.get(mink);
		map.remove(mink);
		map.put(mink+length, value-length);
		OS.emptycatch=map;
		OS.fullcatch.put(mink, length);
		
		if(!isinsert)
		{
			return -1;
		}
		return mink;
	} 
	
	/**
	 * @param start ��ʼλ��
	 * @param length ����
	 * */
	public static void catchRecycle(int start,int length)
	{
		//�����ڴ�
		String strs[]=OS.catches;
		for(int i=start;i<length;i++)
		{
			strs[i]="";
		}
		OS.catches=strs;
		
		//ɾ����ռ�ڴ��
		OS.fullcatch.remove(start);
		
		Map<Integer, Integer> map=OS.emptycatch;
		//���ɨ��
		int nextkey=start+length;
		if(map.containsKey(nextkey))
		{
			int finvalue=length+map.get(nextkey);
			map.remove(nextkey);
			map.put(start, finvalue);
		}else
		{
			map.put(start, length);
		}
		//��ǰɨ��
		/*Set<Integer> keys = map.keySet();
		//ʹ�õ�������foreachʱ��������ѭ���ڲ�ɾ����������!!!!!!!!
		int frontkey=-1;
		for(Integer key : keys)
		{
			if(key<start&&key+map.get(key)==start)
			{
				int finlength=length+map.get(key);
				map.remove(key);
				map.put(key, finlength);
				frontkey=key;
				break;
			}
		}
		if(frontkey>-1)
		{
			int finlength=length+map.get(frontkey);
			map.remove(frontkey);
			map.put(frontkey, finlength);
		}*/
		
		OS.emptycatch=map;
	}
	
	//��������
	public static void catchArrange()
	{
		Map<Integer, Integer> map=OS.emptycatch;
		Set<Integer> keys = map.keySet();
		int arr[]=new int[129];
		for(Integer integer:keys)
		{
			int key=integer;
			int value=map.get(integer);
			arr[key]=value;
		}
		for(int i=0;i<128;i++)
		{
			int k=i+arr[i];
			 
			if(arr[k]>0)
			{
				arr[i]+=arr[k];
				arr[k]=0;
				i=0;
			}
		}
		Map<Integer, Integer> newmap=new HashMap<>();
		for(int i=0;i<128;i++)
		{
			if(arr[i]>0)
			{
				newmap.put(i, arr[i]);
				//System.out.println("arr"+i+"="+arr[i]);
			}
		}
		
		OS.emptycatch=newmap;
	}
	
	public static void showCatch()
	{
		catchArrange();
		catchArrange();
		
		Map<Integer,Integer> map=OS.fullcatch;
		Set<Integer> keys = map.keySet();
		System.out.println("Full:");
		for(Integer key : keys)
		{
			System.out.println(key+" "+map.get(key));
		}
		map=OS.emptycatch;
		keys = map.keySet();
		System.out.println("Empty:");
		for(Integer key : keys)
		{
			System.out.println(key+" "+map.get(key));
		}
	}
}
