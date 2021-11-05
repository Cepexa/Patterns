#pragma once

class Builder {
protected:
	std::string  Product;
	
public:
	std::string getResult() {
		return Product;
	}
	virtual void toDo() = 0;
};
class ConcreteBuilderA : public Builder{
private:
public:
	
	void toDo()override {
		Product = "Порядковый номер; имя; координаты; время штрафа "
			"или строка «незачёт СУ» для обязательных КП";
	}
};
class ConcreteBuilderB : public Builder {
private:
public:
	
	void toDo()override {
		Product = "Подсчёт суммарного штрафа по всем необязательным КП.";
	}

};


class Director {
private:
	Builder* b;
public:
	Director(Builder* builder) : b(builder)	{}
	void construct() {
		b->toDo();
	}
	void changeBuilder(Builder* builder)  {
		b = builder;
	}
};


void builder() {

	Builder* b = new ConcreteBuilderA();
	Director* d = new Director(b);
	d->construct();
	std::cout<<b->getResult()<<std::endl;

	Builder* b2 = new ConcreteBuilderB();
	d->changeBuilder(b2);
	d->construct();
	std::cout << b2->getResult() << std::endl;

	delete b;
	delete  b2;
	delete d;
}
