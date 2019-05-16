//java中我们可以把我们的类写在一个不同的源文件 而且在main在的类不需要对你的其他文件进行引用等操作 编译器会自动帮你去寻找
import java.util.*;

//java在一个对象的构造器调用的过程为：
//1，所有数据域初始化为默认值(0,false,null)；2，按照在类声明中出现的次序，依次执行所有域初始化语句和初始化块；3，如果构造器第一行调用了第二个构造器，则执行第二个构造器主体；4，执行构造器主体

public class Employee {//与C++类似 关键词private表示只有类自己的方法才能访问  而public表示任何类的任何方法都能访问
	private String name;
	private double salary;
	private final String firstName;//final 类似于const用来修饰不会被修改的实例域并且final修饰的对象必须在构造器中被初始化
	private static int nextId;//static:静态域也称为类域是沿袭C++中的用法，含义也和C++中类似表示该类共有的一个变量
	private int Id;
	//即对于每一个类的对象而言都有一个nextId=1;
	private static final double pi=3.1415926535;//static final用来修饰一个静态常量，也即所有的变量共有同一个常量
	
	static {//java除了构造函数初始化还支持构造域初始化
		Random gen = new Random();
		nextId=gen.nextInt(10000);
	}
	
	public Employee(String aName,double aSalary,String str){//构造器，在C++中为构造函数，这个函数只能在new的时候被调用 不能由对象直接调用
		name =aName;
		salary=aSalary;
		firstName=str;//构造参数的命名规则一般是在参数名前面加一个a
	}
	//java与C++类似同样支持构造函数重载：
	public Employee(String str) {//overload 
		this("andy",2000,str);//在一个构造内 可以利用this直接调用另一个构造
	}
	public Employee() {//无参数构造函数 即默认构造函数，如果没有默认构造那么在类对象初始化时不传入参数是不允许的
		name="";
		firstName=null;//而对于所有的没有初始化的参数 会默认初始化但是我们一般要避免这种情况
	}
	
	public String getName() {
		return name;//当我们返回一个引用了可变对象 的地址时 我们就不能直接返回了 因为返回之后很有可能在外面会对该地址对应的对象进行修改从而改变类的private变量
		// (String) name.clone(); 这个时候我们只能调用一个克隆函数了
	}
	public void raiseSalary(double bypercent) {//.该方法有两个参数一个是在括号中的有被传递的显示参数
		double raise = this.salary*bypercent/10;
		this.salary+=raise;//这个类的状态参数为隐式参数 可以与C++中一样用this指针来引用
	}
	//C++中函数的定义大部分在类外进行定义 在类中定义的一般自动的成为内联(inline) 而java的函数都是在类中定义的。
	public static int getNextId() {//static静态方法不要通过类的对象进行调用直接通过类直接引用，但是静态方法不能调用隐式参数，只能用显示参数
		return nextId;//而且调用的参数也必须是类的静态域
	}
	//java在以下两种情况下会用到静态方法：1，不需要使用隐式参数即不需要用到类的作用域仅仅只需要显示参数即可。2，或者该方法仅需要访问类的静态域
	public static void main(String[] args) {
		Employee c1 =new Employee("saozhu",20000,"pdd");
		System.out.println(c1.getName());
		//java 每个类都可以有自己的main函数而每次运行的时候都不会去调用单独某一个类的main方法但是可以单独调用对应类的main函数来分块进行调试
	}
	//与C++不同java的方法的值的传递没有提供跟多的方法只能通过值进行传递，也就是所谓的拷贝传递。但是由于java中所有类的声明的变量其实都是该类对象的引用所以就有如下的规律
	//1，对于基本数据类型都是值传递无法对变量的值进行修改：
	public void tSwap(int x,int y) {//该函数无法完成x,y的交换
		int tmp=x;
		x=y;
		y=tmp;
	}
	public void traiseSalary(Employee xx,double pb) {//该函数可以改变传入的类的对象的引用所对应的对象的状态
		xx.raiseSalary(pb);
		//我们可以看成在调用的过程中进行了一次引用的拷贝，所以引用所对应的对象的状态也能随之改变
	}
	public void cSwap(Employee x,Employee y) {
		Employee tmp = x;
		x=y;
		y=tmp;//而在这里传入的两个参数在函数返回之后并不会交换  因为这里其实是对两个引用进行了拷贝所以交换的也是被拷贝的应用的值，所以得考虑其他方法交换两个引用的值
	}
	
	
}
