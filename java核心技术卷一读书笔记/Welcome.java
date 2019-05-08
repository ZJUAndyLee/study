import static java.lang.Math.*;
public class Welcome {//与C++类似 java的类也是由 访问修饰词+class+类名 来声明的
	
	
	public static void main(String[] args) {
		String greeting = "Welcome to core java!";
		System.out.println(greeting);//这里也就是java的通用语法即：object.method(parameters)
		for(int i=0;i<greeting.length();i++)
			System.out.print("=");
		System.out.println();
		//java 数据类型与目标平台无关 在任何平台或者任何系统上数据类型的大小都是相同的
		//1，整型：
		int ii; //4字节 -2^31~2^31-1
		short ss; //2字节 -2^15~2^15-1
		long ll; //8字节 -2^63~2^63-1
		byte bb; //1字节  -2^7~-2^7-1
		//2，浮点型：
		float ff; // 4字节 6-7为有效数字
		double dd; // 8字节 15位有效数字
		//3，char类型：
		char cc=65;//不同Unicode 的编码需要的字符数不同，\u0041\ u是unicode的标志。还有其他的转义序列：\b：退格 \t：制表
		// \n换行，\r回车，\"双引号，\'单引号，\\反斜杠
		//4，布尔类型
		boolean bl=true; //声明布尔值需要用全拼 而且布尔值与其他值直接不能转换即整型的0,1是不能与布尔类型的变量相互转换的
		//java声明一个变量之后必须对变量进行显式的初始化 ，在C++中变量的声明和定义是区分的而在Java中不区分声明和定义
		final double pi=3.14;//final 是声明常量时用到的 与C++中的const类似 在方法(函数)中定义常量就是方法(函数)常量
		//强制类型转换：
		double tmpD=9.997;
		int tmpI= (int)tmpD;//cast操作可能会导致信息丢失，在这个表达式中tmpI也就等于9，而如果想要实现四舍五入则需要：
		tmpI= (int)Math.round(tmpD); //Math.round()调用得到的是一个long类型的变量转化为int还是需要类型转换
		//java支持?:的三元操作
		double bigger = tmpI>tmpD?tmpI:tmpD;//与C++类似得到两者较大的数
		Size s=Size.Small;
	}
	enum Size {Small,Medium,Large,Extra_Large};// 枚举类 
	public static final double h = 6.62;// 当然我们也可以在方法(函数)外定义常量 常量与类中所有函数共享为类常量。
}
