package src;

import java.io.IOException;
public class TranslateByte {
	public static void main(String [] args) throws IOException{
		if(args.length<2) {
			System.err.println("Usage: Java TranslationByte FROM TO");
			return;
		}
		byte from =(byte)args[0].charAt(0);
		byte to =(byte)args[1].charAt(0);
		int b;
		System.out.println("Input the source:");
		while((b=System.in.read())!=-1) {
			System.out.write(b==from?to:b);
		}
	}
}