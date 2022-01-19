/*
Page 210
6.1 Consider the following stack of city names:

STACK: London, Berlin, Rome, Paris, _____, _____

(a) Describe the stack as the following operations take place:

(i) PUSH(STACK, Athens),

(ii) POP(STACK, ITEM)

(iii) POP(STACK, ITEM)

(iv) PUSH(STACK, Madrid)

(v) PUSH(STACK, Moscow)

(vi) POP(STACK, ITEM)

(b) Describe the stack if the operation POP(STACK, ITEM) deletes London.
*/
#include<iostream>
#include<iomanip>
using namespace std;
class STACK
{
private:
 typedef struct _node
    {
        string DATA;
        _node *next;
    }STK;
    int MAXSTK;
    int AVAIL;
    STK *START;
   
public:
    STACK(int N);
    ~STACK();
    void PUSH(string DATA);
    int POP(string &ITEM);
    void DISPLAY();
};
STACK::STACK(int N)
{
    MAXSTK = 0;
    AVAIL = N;
    START = nullptr;
}
//INSERT DATA INTO THE STACK
void STACK::PUSH(string DATA)
{
    if(AVAIL <= 0)
    {
        cout << "\nOVERFLOW\n";
    }
    if(START == nullptr)
    {
        STK *PTR = new STK;
        PTR->DATA = DATA;
        PTR->next = nullptr;
        START = PTR;
        MAXSTK++;
        AVAIL--;
    }
    else
    {
         STK *PTR = new STK;
        PTR->DATA = DATA;
        PTR->next = START;
        START = PTR;
        MAXSTK++;
        AVAIL--;
    }
}
//POPPING DATA FROM STACK
int STACK::POP(string &ITEM)
{
    if(START== nullptr)
    {
        cout << "\nUNDER FLOW\n";
        return 0;
    }
    ITEM = START->DATA;
    START = START->next;
    AVAIL++;
    MAXSTK--;
    return 1;
}
void STACK::DISPLAY()
{
    string ITEM;
    while(1)
    {
        if(POP(ITEM))
        cout << ITEM<< " ";
        else 
        break;
    }
}
STACK::~STACK()
{
}
int main()
{
    string  ITEM;
    STACK S(6);
    S.PUSH("LONDON");
    S.PUSH("BERLIN");
    S.PUSH("ROME");
    S.PUSH("PARIS");

    S.PUSH("ATHENS");
    if(S.POP(ITEM))
        cout << ITEM<< " ";
    if(S.POP(ITEM))
        cout << ITEM<< " ";
    S.PUSH("MADRID");
    S.PUSH("MOSCOW");
    if(S.POP(ITEM))
        cout << ITEM<< " ";
}
/*
ATHENS PARIS MOSCOW 
*/