package util;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FileOp {
	
	public static String getPath()
	{
		return System.getProperty("user.dir")+"/pcs/";
	}
	
	public static String[] getFileName()
	{
		String names[]=new String[10];
		for (int i = 0; i < 10; i++) {
			int k=i+1;
			names[i]="pc-"+k+".txt";
		}
		return names;
	}
	
	public static String [] getFileContent(String filename)
	{
		File file = new File(FileOp.getPath()+filename);  
        BufferedReader reader = null;  
        ArrayList<String> list=new ArrayList<>();
        try {
            reader = new BufferedReader(new FileReader(file));  
            String tempString = null;  
            int line = 0;  
            // 一次读入一行，直到读入null为文件结束  
            while ((tempString = reader.readLine()) != null) {  
                list.add(tempString);
            }  
            reader.close();  
        } catch (IOException e) {  
            e.printStackTrace();  
        } finally {  
            if (reader != null) {  
                try {  
                    reader.close();  
                } catch (IOException e1) {  
                }  
            }  
        }
        
        String strs[]=new String[list.size()];
        for (int i = 0; i < list.size(); i++) {
			strs[i]=list.get(i);
		}
        
        return strs;
	}
	
	public static void resWrite(String filename,int x)
	{
		String filepath=System.getProperty("user.dir")+"/results/"+filename;
		  try {

			   String content = String.valueOf(x);

			   File file = new File(filepath);

			   // if file doesnt exists, then create it
			   if (!file.exists()) {
			    file.createNewFile();
			   }

			   FileWriter fw = new FileWriter(file.getAbsoluteFile());
			   BufferedWriter bw = new BufferedWriter(fw);
			   bw.write(content);
			   bw.close();
			  } catch (IOException e) {
			   e.printStackTrace();
			  }
	}
}
