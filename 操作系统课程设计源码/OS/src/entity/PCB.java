package entity;

public class PCB {
	private String outtitle;
	
	private int intitle;
	
	private PSW psw;
	
	private IR ir;
	
	private PC pc;
	
	private DR dr;
	
	//×èÈûÔ­Òò
	private String block;
	
	private int catchadd;
	
	private int size;

	public String getOuttitle() {
		return outtitle;
	}

	public void setOuttitle(String outtitle) {
		this.outtitle = outtitle;
	}

	public int getIntitle() {
		return intitle;
	}

	public void setIntitle(int intitle) {
		this.intitle = intitle;
	}

	public PSW getPsw() {
		return psw;
	}

	public void setPsw(PSW psw) {
		this.psw = psw;
	}

	public IR getIr() {
		return ir;
	}

	public void setIr(IR ir) {
		this.ir = ir;
	}

	public PC getPc() {
		return pc;
	}

	public void setPc(PC pc) {
		this.pc = pc;
	}

	public DR getDr() {
		return dr;
	}

	public void setDr(DR dr) {
		this.dr = dr;
	}

	public String getBlock() {
		return block;
	}

	public void setBlock(String block) {
		this.block = block;
	}

	public int getCatchadd() {
		return catchadd;
	}

	public void setCatchadd(int catchadd) {
		this.catchadd = catchadd;
	}

	public int getSize() {
		return size;
	}

	public void setSize(int size) {
		this.size = size;
	}

	@Override
	public String toString() {
		return "PCB [outtitle=" + outtitle + ", intitle=" + intitle + ", psw=" + psw + ", ir=" + ir + ", pc=" + pc
				+ ", dr=" + dr + ", block=" + block + ", catchadd=" + catchadd + ", size=" + size + "]";
	}

	
}
