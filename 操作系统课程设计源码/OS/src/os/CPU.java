package os;

import entity.PCB;
import entity.PSW;
import util.CatchUtil;
import util.FileOp;
import util.InteruptUtil;
import util.TimeThread;

/*** @author hp
* @date : 2018年12月8日 下午5:07:26*/
public class CPU {
	
	//cpu
	public static void Run()
	{
		if(OS.preparelist.size()<=0)
		{
			//转向闲逛进程
			new TimeThread(1).run();
			System.out.println("所有进程执行结束！！！！！！！");
			return;
		}
		//时间片
		int time=5;
		boolean isintrupt=false;
		PCB pcb=OS.pcbs.get(OS.preparelist.get(0));
		OS.preparelist.remove(0);
		String noworder=pcb.getIr().getNowpoint();
		Integer x=pcb.getDr().getX();
		while(!noworder.equals("end.")&&time!=0)
		{
			//System.out.println(noworder);
			if(noworder.contains("="))
			{
				x=Integer.valueOf(noworder.substring(2, 3));
			}
			else if(noworder.contains("++"))
			{
				x++;
			}
			else if(noworder.contains("--"))
			{
				x--;
			}
			else if(noworder.contains("!"))
			{
				//中断
				pcb.setBlock(noworder.substring(1, 2));
				int blocktime=Integer.valueOf(noworder.substring(2,3));
				pcb.setPsw(new PSW(1));
				pcb.getIr().setNowpoint(OS.catches[pcb.getPc().getNextpoint()]);
				pcb.getPc().setNextpoint(pcb.getPc().getNextpoint()+1);
				//进程加入等待队列
				OS.waitlist.add(pcb.getPc().getPcbpost());
				//制定时间之后把等待队列里面的线程移入就绪队列
				//System.out.println(blocktime);
				new InteruptUtil(blocktime, pcb.getPc().getPcbpost()).run();
				isintrupt=true;
				break;
			}
			pcb.getDr().setX(x);
			time--;
			int nextpoint=pcb.getPc().getNextpoint();
			noworder=OS.catches[nextpoint];
			pcb.getIr().setNowpoint(noworder);
			pcb.getPc().setNextpoint(nextpoint+1);
			new TimeThread(1).run();
		}
		if(!isintrupt)
		{
			if(time==0)
			{
				OS.preparelist.add(pcb.getPc().getPcbpost());
				System.out.println(pcb.getOuttitle()+"时间片超时");
			}
			else
			{
				//结果写入
				FileOp.resWrite(pcb.getOuttitle(), x);
				
				//内存恢复
				CatchUtil.catchRecycle(pcb.getCatchadd(), pcb.getSize());
				System.out.println(pcb.getOuttitle()+"执行结束");
			}
		}
		else
		{
			System.out.println(pcb.getOuttitle()+"Io中断");
		}
		//TODO 时间片清零
		System.out.println("CPU Has Done!");
	}
}