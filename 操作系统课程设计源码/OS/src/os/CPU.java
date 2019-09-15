package os;

import entity.PCB;
import entity.PSW;
import util.CatchUtil;
import util.FileOp;
import util.InteruptUtil;
import util.TimeThread;

/*** @author hp
* @date : 2018��12��8�� ����5:07:26*/
public class CPU {
	
	//cpu
	public static void Run()
	{
		if(OS.preparelist.size()<=0)
		{
			//ת���й����
			new TimeThread(1).run();
			System.out.println("���н���ִ�н�����������������");
			return;
		}
		//ʱ��Ƭ
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
				//�ж�
				pcb.setBlock(noworder.substring(1, 2));
				int blocktime=Integer.valueOf(noworder.substring(2,3));
				pcb.setPsw(new PSW(1));
				pcb.getIr().setNowpoint(OS.catches[pcb.getPc().getNextpoint()]);
				pcb.getPc().setNextpoint(pcb.getPc().getNextpoint()+1);
				//���̼���ȴ�����
				OS.waitlist.add(pcb.getPc().getPcbpost());
				//�ƶ�ʱ��֮��ѵȴ�����������߳������������
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
				System.out.println(pcb.getOuttitle()+"ʱ��Ƭ��ʱ");
			}
			else
			{
				//���д��
				FileOp.resWrite(pcb.getOuttitle(), x);
				
				//�ڴ�ָ�
				CatchUtil.catchRecycle(pcb.getCatchadd(), pcb.getSize());
				System.out.println(pcb.getOuttitle()+"ִ�н���");
			}
		}
		else
		{
			System.out.println(pcb.getOuttitle()+"Io�ж�");
		}
		//TODO ʱ��Ƭ����
		System.out.println("CPU Has Done!");
	}
}