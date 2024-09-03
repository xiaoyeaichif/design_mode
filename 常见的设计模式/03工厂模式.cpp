


#include<iostream>
#include<memory>
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
	Car(string name):_name(name){}
	virtual void show() = 0;
protected:
	string _name;
};

// 宝马车
class Bmw : public Car
{
public:
	// 构造函数初始化
	Bmw(string name):Car(name){}
	void show()
	{
		cout << "获取一辆宝马汽车: " << _name<<endl;
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
		cout << "获取一辆奥迪汽车: " <<_name<< endl;
	}
};

// 使用简单的工厂 + 枚举方案
// 枚举
enum CarType
{
	BMW,
	AUDI
};

class SimpleFactory
{
public:
	Car* createCar(CarType ct)
	{
		switch (ct)
		{
		case BMW:
			return new 	Bmw("X3");
		case AUDI:
			return new  Audi("A5");
		default:
			cerr << "传入工厂的参数不正确：" << ct << endl;
			break;
		}
		return nullptr;
	}
};


int main()
{
	// 使用裸指针进行初始化
	Car* p1 = new Bmw("X1");
	Car* p2 = new Audi("A6");
	
	p1->show();
	p2->show();

	delete p1;
	delete p2;

	// 使用智能指针解决
	unique_ptr<Car> p3(new Bmw("X1"));
	unique_ptr<Car> p4(new Audi("A6"));
	p3->show();
	p4->show();

	// 使用简单的工厂模式
	// 获取工厂指针
	unique_ptr<SimpleFactory> factory(new SimpleFactory());
	// 获取Car指针
	unique_ptr<Car>p5(factory->createCar(BMW));
	unique_ptr<Car>p6(factory->createCar(AUDI));
	p5->show();
	p6->show();
	
	return 0;
}