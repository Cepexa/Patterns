#pragma once

class Builder {
private:
	std::string nameKP;
	struct COORD{
		float latitude; //������
		float longitude; // �������
	}coord;
	float fine; //�����
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



//�� ���������� �.�. �� ����� ���� ������
void builder() {

}