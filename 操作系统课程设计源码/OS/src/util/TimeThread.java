package util;

import java.sql.Time;
import java.util.concurrent.TimeUnit;

import javax.swing.JLabel;

public class TimeThread implements Runnable{

	private int time;
	
	private JLabel jLabel;
	
	public TimeThread(int time)
	{
		this.time=time;
	}
	
	
	public TimeThread(JLabel label) {
		this.time=-1;
		this.jLabel=label;
	}
	
	/*public TimeThread(int limitSec) throws InterruptedException{
		this.limitSec = limitSec;
		System.out.println("Count from "+limitSec);
		while(limitSec > 0){
			System.out.println("remians "+ --limitSec +" s");
			TimeUnit.SECONDS.sleep(1);
		}
		System.out.println("Time is out");
	}*/
	//Test
	@Override
	public void run() {
		try {
			if(this.time<0)
			{
				this.time=0;
				while(true)
				{
					this.time+=1;
					this.jLabel.setText(String.valueOf(this.time));
					TimeUnit.SECONDS.sleep(1);
				}
			}
			else
			{
				while(this.time>0)
				{
					this.time-=1;
					TimeUnit.SECONDS.sleep(1);
					//Thread.sleep(1000);
				}
			}
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}
