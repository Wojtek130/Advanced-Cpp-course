#include <algorithm> 
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <typeinfo> 

using namespace std;

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

class Symbol {
protected:
    string value_;
public:
    Symbol(string value);
    ~Symbol();
    string get_value();
    virtual void f() = 0;
};

Symbol::Symbol(string value) {
    value_ = value;
}

Symbol::~Symbol()
{
}

string Symbol::get_value() {
    return value_;
}

class Number : public Symbol
{
private:
    /* data */
public:
    Number(string value);
    ~Number();
    void f() override {};
};

Number::Number(string value) : Symbol(value) {
}

Number::~Number()
{
}

class NotNumber : public Symbol
{
protected:
    int precedence_;
public:
    NotNumber(string value);
    ~NotNumber();
    int get_precedence();
};

NotNumber::NotNumber(string value) : Symbol(value)
{
}

NotNumber::~NotNumber()
{
}

int NotNumber::get_precedence()
{
    return precedence_;
}

class LeftBracket : public NotNumber
{
private:
    /* data */
public:
    LeftBracket(string value);
    ~LeftBracket();
    void f() override {};
};
LeftBracket::LeftBracket(string value) : NotNumber(value)
{
    precedence_ = 0;
}
LeftBracket::~LeftBracket()
{
}

class RightBracket : public NotNumber
{
private:
    /* data */
public:
    RightBracket(string value);
    ~RightBracket();
    void f() override {};
};
RightBracket::RightBracket(string value) : NotNumber(value)
{
    precedence_ = 3;
}
RightBracket::~RightBracket()
{
}

class LowPrecedenceOperator : public NotNumber
{
private:
    /* data */
public:
    LowPrecedenceOperator(string value);
    ~LowPrecedenceOperator();
    void f() override {};
};
LowPrecedenceOperator::LowPrecedenceOperator(string value) : NotNumber(value)
{
    precedence_ = 1;
}
LowPrecedenceOperator::~LowPrecedenceOperator()
{
}

class HighPrecedenceOperator : public NotNumber
{
private:
    /* data */
public:
    HighPrecedenceOperator(string value);
    ~HighPrecedenceOperator();
    void f() override {};
};
HighPrecedenceOperator::HighPrecedenceOperator(string value) : NotNumber(value)
{
    precedence_ = 2;
}
HighPrecedenceOperator::~HighPrecedenceOperator()
{
}

Symbol* string_to_symbol(string c) {
    // Symbol* s;
    // cout<<*c<<" : sym\n";
    if (all_of(c.begin(), c.end(), ::isdigit))
    {
        return new Number(c);
    }
    string lb = "({[";
    string rb = ")}]";
    string lpo = "+-";
    string hpo = "*/%";
    if (lb.find(c) != string::npos) {
        return new LeftBracket(c);
    }
    else if (rb.find(c) != string::npos) {
        return new RightBracket(c);
    }
    else if (lpo.find(c) != string::npos) {
        return new LowPrecedenceOperator(c);
    }
    else if (hpo.find(c) != string::npos) {
        return new HighPrecedenceOperator(c);
    }
    // cout<<c<<"endl";
    exit(0);
    throw new invalid_argument("not recognized symbol");
}

list<Symbol*> infix_to_RPN(string expression) {
    queue<Symbol*> q;
    list<Symbol*> out;
    stack<NotNumber*> s;
    for (char c : expression) {
        if (!isspace(c))
        {
            string cstr(1, c);
            q.push(string_to_symbol(cstr));
        }
    }
    while (!q.empty())
    {
        if (instanceof<Number>(q.front())) {
            out.push_back(q.front());
            q.pop();
            continue;
        }
        if (instanceof<LeftBracket>(q.front())) {
            s.push(dynamic_cast<NotNumber*>(q.front()));
            q.pop();
            continue;
        }
        if (instanceof<RightBracket>(q.front())) {
            while (!s.empty() && !instanceof<LeftBracket>(s.top()))
            {
                out.push_back(s.top());
                s.pop();
            }
            if (!s.empty())
            {
                s.pop();
            }
            q.pop();
            continue;
        }
        if (s.empty() || s.top()->get_precedence() < dynamic_cast<NotNumber*>(q.front())->get_precedence()) {
            s.push(dynamic_cast<NotNumber*>(q.front()));
            q.pop();
        }
        else {
            while (!s.empty() && s.top()->get_precedence() >= dynamic_cast<NotNumber*>(q.front())->get_precedence()) {
                out.push_back(s.top());
                s.pop();
            }
            s.push(dynamic_cast<NotNumber*>(q.front()));
            q.pop();
        }
        
    }
    while (!s.empty())
    {
        out.push_back(s.top());
        s.pop();
    }
    
    return out;
}

int main() {
    Number n = Number("1");
    LeftBracket lb = LeftBracket("{");
    for (auto e : infix_to_RPN("1+(2*3-1)-2"))
    {
        cout<<e->get_value();
    }
    cout<<endl;
}