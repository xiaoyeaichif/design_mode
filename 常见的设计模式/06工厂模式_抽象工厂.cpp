


#include<iostream>
#include<string>
using namespace std;


/*
	简单工厂	Simple Factory --》
		优点：把对象的创建封装在一个接口中，通过传入不同的标识，返回创建的对象,客户不用自己负责new对象，不用了解
		对象创建的详细过程
		缺点：提高对象的接口函数不闭合，不能对修改关闭

	工厂方法	Factory Method	----》
		优点：Factory是个基类，并且为纯虚函数，只提供一个接口，派生类只需要在类中重写虚函数即可实现不同的产品
		能够很好的进行修改与关闭
		缺点：只能简单的进行某一种产品的输出，但是很多产品之间是有关联关系的，属于一个产品组，工厂方没有考虑
	抽象工厂	Abstract Factory
		优点：把关联的关系都写进基类中，属于一个产品的所有接口函数都包含，派生类继承是时，只需要重写所有的接口就可以
		缺点：有一些接口只有某个产品需要使用，基类写了接口以后，每个派生类都必须重写

	工厂模式：主要是封装了对象的创建
*/

// 简单工厂模式
// 车的类型
class Car
{
public:
	Car(string name) :_name(name) {}
	virtual void show() = 0;
protected:
	string _name;
};

// 宝马车
class Bmw : public Car
{
public:
	// 构造函数初始化
	Bmw(string name) :Car(name) {}
	void show()
	{
		cout << "获取一辆宝马汽车: " << _name << endl;
	}
};
// 奥迪车
class Audi : public Car
{
public:
	// 构造函数初始化
	Audi(string name) :Car(name) {}
	void show()
	{
		cout << "获取一辆奥迪汽车: " << _name << endl;
	}
};

// 灯类
class Light
{
public:
	// 构造函数初始化
	Light(string light):_light(light)
	{

	}
	virtual void show() = 0;
protected:
	string _light;
};

// BMW灯
class BmwLight : public Light
{
public:
	// 构造函数初始化
	BmwLight(string light) :Light(light) {}
	void show()
	{
		cout << "获取一辆宝马汽车灯的型号: " << _light<< endl;
	}
};


// audi灯
class AudiLight : public Light
{
public:
	// 构造函数初始化
	AudiLight(string light) :Light(light) {}
	void show()
	{
		cout << "获取一辆Audi汽车灯的型号: " << _light << endl;
	}
};




// 使用工厂模式 + 抽象工厂
// 纯虚函数，只提供一个接口----》使用派生类继承
class AbstractFactory{
public:
	virtual Car* CreateCar(string name) = 0;
	virtual Light* CreateLight(string light) = 0;
};

// 创建宝马相关的配件
class BMWFactory :public AbstractFactory
{
	Car* CreateCar(string name)
	{
		return new Bmw(name);
	}
	//
	Light* CreateLight(string light)
	{
		return new BmwLight(light);
	}
};

// 创建奥迪相关的配件
class AUDIFactory :public AbstractFactory
{
	Car* CreateCar(string name)
	{
		return new Audi(name);
	}
	Light* CreateLight(string light)
	{
		return new AudiLight(light);
	}
};

int main_06()
{


	// 使用简单的工厂模式
	// 获取工厂指针
	// 父类的指针指向子类
	unique_ptr<AbstractFactory> bmwfactory(new BMWFactory());
	unique_ptr<AbstractFactory> audifactory(new AUDIFactory());
	// 虚函数实现的多态，直接调用子类的对应的函数
	// 宝马工厂
	unique_ptr<Car> p1(bmwfactory->CreateCar("X6"));
	unique_ptr<Light> l1(bmwfactory->CreateLight("xxxxx"));
	// audi 工厂
	unique_ptr<Car> p2(audifactory->CreateCar("A8"));
	unique_ptr<Light> l2(audifactory->CreateLight("aaaaa"));

	// 宝马工厂
	p1->show();
	l1->show();
	// 奥迪工厂
	p2->show();
	l2->show();
	return 0;
}