
import java.util.*;//载入util包  输入用到的Scanner类包含在util的包中。
import static java.lang.Math.*;

import java.math.BigInteger;
public class Welcome2 {//与C++类似 java的类也是由 访问修饰词+class+类名 来声明的
	
	
	public static void main(String[] args) //java main函数的参数String[] args是用来接受命令行的输入信息的
	{
		String greeting="Hello";//java本身并没有内置String类但是 java标准库中有一个预定义的string类
		//1.子串：
		String s= greeting.substring(0,3);//这个类的方法与C++类似但是参数的含义不同substring(x,y)x表示复制的起点，y表示复制终点的后一位！
		//也就是不想复制的第一个位置
		System.out.println(s);
		//2.拼接： 可以直接在后面加其他的类型之后就会都转换为字符串
		int an=99;
		System.out.println("The answer is "+an);
		//与C++不同的是java的String类的每个字符是不可修改的但是C++是可以单独对每个字符进行修改操作。
		//3.相等判断 由于java的字符串是共享的 但是并不是所有产生的字符串都是共享的 而且java字符串不是一个字符数组更像是一个字符指针
		//所以不能用==运算符判断相等要调用函数：
		greeting.equals(s);//返回一个布尔变量 还可以这样：
		greeting.equalsIgnoreCase(s);//这个函数调用判断时忽略大小写
		//由于字符串的更像是一个字符指针所以java字符串的空串与null串是不同的
		String str="";//空串是一个对象的实例 有自己的长度0，也有自己的内容“”
		str.length();//0
		String ss=null;//而null则表示啥都没有
		//String类是由char值序列组成 char由UTF-6编码表示 大多数字符只需要一个代码单元但是有些辅助字符需要两个代码单元 这个时候.length()函数可能就返回的不是真正的字符串长度了
		//String API 一些常用的类函数
		s.charAt(0);//返回给定位置的代码单元
		s.indexOf("w");
		Scanner in = new Scanner(System.in);//要通过控制台进行输入，首先要定义一个scanner的类然后必须与标准的输入流进行关联。
		String name = in.nextLine();//nextLine函数读入下一行的所有输入
		String firstname = in.next();//next()读入下一个字符串 以空格为分隔符
		int age=in.nextInt();//nextInt()读入下一个整数，同样的nextDouble()读入下一个浮点数
		//格式化输出：
		System.out.printf("Hello,%s.Next year, you'll be %d",name,age);//java保留了C里面的格式化的输出
		//此外还添加了一些可以控制格式化输出的标志：
		System.out.printf("%,.2f",10000.0/3);//诸如,+,0,-等符号放在%+符号+char这种形式可以格式化输入 如该语句可以得到：3,333.33
		String message = String.format("Hello,%s.Next year, you'll be %d",name,age);//可以格式化得到字符串
		System.out.printf("%tc",new Date());//该语句用来打印当前的日期和时间
		label:
			while(true) {
				while(true) {
					if(4>3)
						break label;//label:标明的语句块是一个新的特性 他可以从内层循环直接跳出整个标签后的语句块 是一个内层循环直接跳出的方法
				}
			}
		//文件输入与输出
		Scanner fin = new Scanner(Paths.get("myfile.txt"),"UTF-8");//get()的参数为文件路径可以为绝对路径 也可以是java运行路径的相对路径，UTF-8是编码模式
		PrintWriter fout = new PrintWriter("myfile.txt","UTF-8");//文件输出 其中对象fout就可以像system.out一样去调用各种print函数了
		//大数值
		BigInteger a = BigInteger.valueOf(100);//BigInteger大整数的类   valueof用来将普通数值转换为大数值
		//由于java没有为用户提供运算符重载的功能所以只能通过函数调用的方式实现重载
		BigInteger b = BigInteger.valueOf(1000000000*1000000000);
		BigInteger c = a.add(b); //加法
		BigInteger d = c.multiply(b); //乘法
		//java 数组：
		int[] arr = new int[100];//int[] 可以看成是java的一个变量类型这样的话就可以看成是定义一个数组变量 而内存的申请类似于C++ 用new语句
		int arr2[]=new int[100]; //这样也行但是这样不太好理解数组定义好之后，数字数组都被初始化为0，而类数组都会被初始化为null
		//for each 循环类似于C++auto语句
		for(int x : arr) {
			x+=arr.length;//数组也可以类似类的方式调用成员函数
		}
		arr2=arr;//在java中允许数组直接这样的赋值，表示的是两个变量同时应用同一块地址空间的数组，有点像C++指针的赋值
		int[] Narr = Arrays.copyOf(arr, arr.length);//而将数据进行拷贝则需要调用Arrays的成员函数，第二个参数表示拷贝的数组的长度 
		//Arrays库里面也有很多API：
		Arrays.sort(arr);//快速排序arr数组
		Arrays.binarySearch(arr, 32);//二分查找找到目标值 找到则返回数组下标 否则返回一个负值
		Arrays.equals(arr,arr2);//判断两个数组的值完全相等则返回true
		//二维数组：
		double[][] bl;
		bl = new double[15][20];//二维数组的内存申请比C++简单不需要再重新对每个变量进行申请而是一次性解决即可
		for(double[] y:bl) {
			for(double z:y)
				System.out.printf("%.2f",z);
		}//二维数组遍历
		//java的数组的可变化性非常大 语法上是与C++ int **a =new int*[m];类似的
		double[] tmp = bl[10];
		bl[10]=bl[11];
		bl[11]=tmp;//java 的数组甚至可以相互交换位置
		
		int[][] arr3=new int[10][];
		for(int i=0;i<10;i++) {
			arr3[i] = new int[i+1];//这样可以建立长短不一的不规则数组 其实语法和C++的指针的指针很相似
		}
	}
	
}
