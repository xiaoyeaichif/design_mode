


#include<iostream>
#include<string>
using namespace std;


/*
	简单工厂	Simple Factory
	工厂方法	Factory Method	----》
	抽象工厂	Abstract Factory
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

// 使用工厂模式 + 工厂方法
// 纯虚函数，只提供一个接口----》使用派生类继承
class Factory {
public:
	virtual Car* CreateCar(string name) = 0;
};

// 创建宝马工厂
class BMWFactory :public Factory
{
	Car* CreateCar(string name)
	{
		return new Bmw(name);
	}
};

// 创建奥迪工厂
class AUDIFactory :public Factory
{
	Car* CreateCar(string name)
	{
		return new Audi(name);
	}
};

int main_05()
{
	

	// 使用简单的工厂模式
	// 获取工厂指针
	// 父类的指针指向子类
	unique_ptr<Factory> bmwfactory(new BMWFactory());
	unique_ptr<Factory> audifactory(new AUDIFactory());
	// 虚函数实现的多态，直接调用子类的对应的函数
	unique_ptr<Car> p1(bmwfactory->CreateCar("X6"));
	unique_ptr<Car> p2(audifactory->CreateCar("A8"));
	
	// 
	p1->show();
	p2->show();

	return 0;
}