package util;

import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JLabel;

import os.OS;

/*** @author hp
* @date : 2018年12月8日 上午9:19:35*/
public class InteruptUtil {
	private int time;
	
	private int pcborder;
	
	public InteruptUtil(int time,int pcborder)
	{
		this.time=time;
		this.pcborder=pcborder;
	}
	
	public void run()
	{
		Timer timer=new Timer();
		timer.schedule(new TimeInded(time,pcborder), 0,1000);
	}
	
	class TimeInded extends TimerTask
	{
		private  Integer time;
		private Integer order;
		
		public TimeInded(Integer time,int order)
		{
			this.time=time;
			this.order=order;
		}

		@Override
		public void run() {
			//System.out.println("111111111111");
			this.time-=1;
			if(this.time==0)
			{
				//int index=Util.getPcbIndex(OS.waitlist, this.order);
				OS.waitlist.remove(order);
				OS.preparelist.add(order);
				this.cancel();
			}				
		}
	}
}
