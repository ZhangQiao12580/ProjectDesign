package util;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import os.OS;

/*** @author hp
* @date : 2018年12月8日 下午2:43:05*/
public class CatchUtil {
	
	//内存分配，返回内存表中起始位置
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
	 * @param start 开始位置
	 * @param length 长度
	 * */
	public static void catchRecycle(int start,int length)
	{
		//重置内存
		String strs[]=OS.catches;
		for(int i=start;i<length;i++)
		{
			strs[i]="";
		}
		OS.catches=strs;
		
		//删除已占内存表
		OS.fullcatch.remove(start);
		
		Map<Integer, Integer> map=OS.emptycatch;
		//向后扫描
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
		//向前扫描
		/*Set<Integer> keys = map.keySet();
		//使用迭代器、foreach时，不能再循环内部删除集合内容!!!!!!!!
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
	
	//磁盘整理
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
