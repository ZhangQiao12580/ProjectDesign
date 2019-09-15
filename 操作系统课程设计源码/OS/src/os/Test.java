package os;

import entity.DR;
import entity.IR;
import entity.PC;
import entity.PCB;
import entity.PSW;
import util.CatchUtil;
import util.FileOp;

/*** @author hp
* @date : 2018��12��8�� ����5:07:17*/
public class Test {
	public static void main(String[] args) {
		
		//��ʼ���ڴ��
		OS.emptycatch.put(0, 128);
		String []progressnames=FileOp.getFileName();
		
		for (int i = 0; i < progressnames.length; i++) {
			String orders[]=FileOp.getFileContent(progressnames[i]);
			int progresssize=orders.length;
			//System.out.println(progressnames[i]+progresssize);
			if(OS.pcbs.size()<10)
			{
				//�����ڴ��
				int bginpost=CatchUtil.catchAllocate(orders);
				if(bginpost==-1)
				{
					//�����ڴ�ʧ��
				}
				
				PCB pcb=new PCB();
				pcb.setOuttitle(progressnames[i]);
				pcb.setIntitle((int)Math.random()*100);
				pcb.setSize(orders.length);
				pcb.setCatchadd(bginpost);
				pcb.setDr(new DR(null));
				pcb.setIr(new IR(orders[0]));
				pcb.setPc(new PC(OS.pcbs.size(), bginpost+1));	//Ĭ�����еĽ��̵��������������
				//TODO
				pcb.setPsw(new PSW(0));
				pcb.setBlock("");
				
				//װ��pcb
				OS.pcbs.add(pcb);
				//�����������
				OS.preparelist.add(OS.pcbs.size()-1);
			}
		}
		CatchUtil.showCatch();
		/*//for (int i = 0; i < progressnames.length; i++) {
			int i=2;
			String orders[]=FileOp.getFileContent(progressnames[i]);
			int progresssize=orders.length;
			//System.out.println(progressnames[i]+progresssize);
			if(OS.pcbs.size()<10)
			{
				//�����ڴ��
				int bginpost=CatchUtil.catchAllocate(orders);
				if(bginpost==-1)
				{
					//�����ڴ�ʧ��
				}
				
				PCB pcb=new PCB();
				pcb.setOuttitle(progressnames[i]);
				pcb.setIntitle((int)Math.random()*100);
				pcb.setSize(orders.length);
				pcb.setCatchadd(bginpost);
				pcb.setDr(new DR(null));
				pcb.setIr(new IR(orders[0]));
				pcb.setPc(new PC(OS.pcbs.size(), bginpost+1));	//Ĭ�����еĽ��̵��������������
				//TODO
				pcb.setPsw(new PSW(0));
				pcb.setBlock("");
				
				//װ��pcb
				OS.pcbs.add(pcb);
				//�����������
				OS.preparelist.add(OS.pcbs.size()-1);
			}
		//}
*/		
		//CatchUtil.showCatch();
		for(int k=0;k<30;k++)
		{
			CPU.Run();
		}
		
		CatchUtil.showCatch();
	}
}
