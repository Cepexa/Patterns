#pragma once

class Builder {
private:
	std::string nameKP;
	struct COORD{
		float latitude; //широта
		float longitude; // долгота
	}coord;
	float fine; //штраф
public:

};
class ConcreteBuilderA : Builder{
private:

public:

};
class ConcreteBuilderB : Builder {
private:

public:

};


class Director {
private:
	Builder* b;
public:
	Director(Builder* builder) : b(builder)	{}
	void cobstruct() {

	}
};



//не реализовал т.к. не понял суть задачи
void builder() {

}