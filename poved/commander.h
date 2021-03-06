#pragma once
#include <vector>

//���������� ������� (Receiver)
class WordProcessor {
private:

public:
    void copy_idx1_idx2() {
        std::cout << "����������� � ������ ������ ������� � ������� idx1 �� ������� idx2" << std::endl;
    }
    void paste_idx() {
        std::cout << "�������� ���������� ������� ������ � ������� idx" << std::endl;
    }
    void insert_string_idx() {
        std::cout << "�������� ������ �string� � ������� idx" << std::endl;
    }
    void delete_idx1_idx2() {
        std::cout << "������� ��� ������� � ������� idx1 �� ������� idx2" << std::endl;
    }
    void undo() {
        std::cout << "�������� ���������� �������" << std::endl;
    }
    void redo() {
        std::cout << "��������� ���������� ������� ������" << std::endl;
    }
};


class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
protected:
    Command(WordProcessor* p) : pWP(p) {}
    WordProcessor* pWP;
};
class CopyWordCommand : public Command {
private:

public:
    CopyWordCommand(WordProcessor* p):Command(p){}
    void execute() override {
        pWP->copy_idx1_idx2();
    }
};
class PasteWordCommand : public Command {
private:

public:
    PasteWordCommand(WordProcessor* p) :Command(p) {}
    void execute() override {
        pWP->paste_idx();
    }
};
class InsertWordCommand : public Command {
private:

public:
    InsertWordCommand(WordProcessor* p) :Command(p) {}
    void execute() override {
        pWP->insert_string_idx();
    }
};
class DeleteWordCommand : public Command {
private:

public:
    DeleteWordCommand(WordProcessor* p) :Command(p) {}
    void execute() override {
        pWP->delete_idx1_idx2();
    }
};
class UndoWordCommand : public Command {
private:

public:
    UndoWordCommand(WordProcessor* p) :Command(p) {}
    void execute() override {
        pWP->undo();
    }
};
class RedoWordCommand : public Command {
private:

public:
    RedoWordCommand(WordProcessor* p) :Command(p) {}
    void execute() override {
        pWP->redo();
    }
};










int command()
{
    WordProcessor wp;
    // �������� ��������
    std::vector<Command*> v;

    v.push_back(new CopyWordCommand(&wp));

    v.push_back(new PasteWordCommand(&wp));

    v.push_back(new InsertWordCommand(&wp));

    v.push_back(new DeleteWordCommand(&wp));

    v.push_back(new UndoWordCommand(&wp));

    v.push_back(new RedoWordCommand(&wp));
   
    for (size_t i = 0; i < v.size(); ++i)
        v[i]->execute();

    for (size_t i = 0; i < v.size(); ++i)
        delete v[i];

    return 0;
    
}