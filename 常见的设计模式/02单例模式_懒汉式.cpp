
#include<iostream>
#include<mutex>
using namespace std;

/*
	单例模式：不管创建多少次，都只能获得一个对象实例
	1：常见使用单例的有日志模块，数据库模块
	2：单例模式分为饿汉式单例模式和懒汉式单例模式
	3：饿汉式单例模式线程安全---》还没有获取实例对象，实例对象就已经生成
	也就是说实例还没有生成就已经先有了对象-----》数据段会优先于函数段先产生
	----》所以饿汉式单例模式是线程安全的，另外获取的实例对象首先在数据段生成（静态对象）

	4：懒汉式模式线程不安全---》唯一的实例对象，直到第一次获取它的时候，才产生-----》
	也就是说有了函数调用才生成该对象
*/

#if 0

static mutex mtx;  // 定义一个互斥量

// 懒汉式单例模式
class Singleton
{
public:
	// 获取唯一的静态实例
	static Singleton *getInstance()
	{
		// 锁放在这里的话，单线程执行效率太低
		if (instance == nullptr)
		{
			// 要保证线程安全，必须加锁
			lock_guard<mutex>lock(mtx);
			if (instance == nullptr) // 锁 + 双重判断----》确保线程安全
			{
				instance = new Singleton();
			}
		}
		return instance;
	}
private:
	static Singleton *instance; // 定义一个类的实例对象的指针
	// 构造函数私有化
	Singleton()
	{

	}
	// 禁止拷贝构造和赋值构造函数
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

// 类外初始化
Singleton * Singleton::instance = nullptr;


// 定义一个唯一的实例对象

// 数据段的创建在函数之前
int main()
{
	Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = Singleton::getInstance();
	Singleton* p3 = Singleton::getInstance();
	// 输出三个指针的地址，检验是否一致
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;
	return 0;
}

// 线程安全----可重入函数

#endif
