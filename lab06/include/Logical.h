#ifndef LOGICAL_H
#define LOGICAL_H

class Logical {
public:
    //statyczna metoda ewaluacji dla jednoargumentowego operatora
    static bool eval(const class OneArg& op, bool val1);

    //statyczna metoda ewaluacji dla dwuargumentowego operatora
    static bool eval(const class TwoArg& op, bool val1, bool val2);
};

//klasa bazowa opeacji jednoargumentowych
class OneArg {
public:
    virtual bool operator()(bool val1) const = 0;
};

//klasa bazowa operacji dwuargumentowych
class TwoArg {
public:
    virtual bool result(bool val1, bool val2) const = 0;
};

//klasa wykonujaca operacaje  jednoarhgumentowa NOT
class NOT : public OneArg{
public:
    bool operator()(bool val1) const override;
};

//klasa wykojujaca operacje dwuargumentowa OR
class OR : public TwoArg {
public:
    virtual bool result(bool val1, bool val2) const override;
};

//klasa wykojujaca operacje dwuargumentowa AND
class AND : public TwoArg {
public:
    virtual bool result(bool val1, bool val2) const override;
};

//klasa wykojujaca operacje dwuargumentowa XOR
class XOR : public TwoArg {
public:
    virtual bool result(bool val1, bool val2) const override;
};



#endif