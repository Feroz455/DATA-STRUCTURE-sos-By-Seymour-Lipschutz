/*
Page 161
Programming Problems 5.1 to 5.6 refer to the data structure in
Fig. 5.52, which consists of four alphabetized lists of clients
and their respective lawyers.

5.1 Write a program which reads an integer K and prints the list
of clients of lawyer K. Test the program for each K
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef struct _link
{
    string CLINT_NAME;
    int AGE;
    _link *next;
    _link *prev;
} LINKED;

typedef struct _lawyer
{
    string NAME;
    LINKED *CLINT;
} LAWYER;

/********************************/
void INSERT_END(LINKED **START, string NAME, int AGE)
{
    if ((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->CLINT_NAME = NAME;
        NEW->AGE = AGE;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;
        LINKED *NEW = new LINKED;
        NEW->CLINT_NAME = NAME;
        NEW->AGE = AGE;

        NEW->next = (*START);
        NEW->prev = LAST;
        (*START)->prev = NEW;
        LAST->next = NEW;
    }
}
void DISPLAY_FORWORD(LINKED **START)
{
    if ((*START) == NULL)
    {
        cout << "LIST IS EMPTY\n";
        return;
    }
    LINKED *PTR = (*START);
    while (PTR->next != *START)
    {

        cout << setw(10) << PTR->CLINT_NAME << " " << setw(3) << PTR->AGE << "\n";
        PTR = PTR->next;
    }
    cout << setw(10) << PTR->CLINT_NAME << " " << setw(3) << PTR->AGE << "\n";
}

int main()
{
    int k = 4, age;
    string name;
    LAWYER NAME[k];
    LINKED *START = NULL;
    for (int i = 0; i < k; i++)
    {
        cout << "Enter lowyer name\n";
        cin >> NAME[i].NAME;
        cout << "Enter clint NAME and AGE\n";
        cout << "TO STOP TYPE $$$$$\n";
        cin >> name;
        while (name != "$$$$$")
        {
            cin >> age;
            INSERT_END(&START, name, age);
            cin >> name;
        }
        NAME[i].CLINT = START;
        START = NULL;
        cout << "\nHELLO\n";
    }
    for (int i = 0; i < k; i++)
    {
        cout << "LOWYER NAME = " << NAME[i].NAME << endl;
        START = NAME[i].CLINT;
        DISPLAY_FORWORD(&START);
    }

    int temp;
    LINKED *PTR;
    
    for(int k = 0; k < 2; k++)
    {
        cout << "Enter age to show clint in age of upper then the age\n";
        cin >> temp;
        for (int i = 0; i < 4; i++)
        {
            START = NAME[i].CLINT;
            if ((START) == NULL)
            {
                cout << "LIST IS EMPTY\n";
                continue;
            }
            PTR = (START);
            while (PTR->next != START)
            {
                if(PTR->AGE >= temp)
                cout << setw(10)<< NAME[i].NAME  << setw(10) << PTR->CLINT_NAME << " " << setw(3) << PTR->AGE << "\n";
                PTR = PTR->next;
            }
            if(PTR->AGE >= temp)
            cout << setw(10)<< NAME[i].NAME  << setw(10) << PTR->CLINT_NAME << " " << setw(3) << PTR->AGE << "\n";
        }
    }

    return 0;
}

/*
OUTPUT
CLIENT
Davis


Hall
35

Moss
28

Ford
47

Brown
54

Ginn
38
$$$$$

Levine

Pride
42

Berk
38


White
45

Todd
25

Dixon
32

Newman
46
$$$$$

Nelson

Harris
42

Jackson
52

Roberts
40

Eisen
32

Adams
48

Cohen
36
$$$$$


Rogers
Fisher
32

Graves
42

Parker
50

Singer
45

Lewis
28
$$$$$



/********************************/
/*
Davis
Enter clint NAME and AGE
TO STOP TYPE $$$$$      


Hall
35

Moss
28

Ford
47

Brown
54

Ginn
38
$$$$$

HELLO
Enter lowyer name

Levine
Enter clint NAME and AGE
TO STOP TYPE $$$$$

Pride
42

Berk
38


White
45

Todd
25

Dixon
32

Newman
46
$$$$$

HELLO
Enter lowyer name

Nelson
Enter clint NAME and AGE
TO STOP TYPE $$$$$

Harris
42

Jackson
52

Roberts
40

Eisen
32

Adams
48

Cohen
36
$$$$$

HELLO
Enter lowyer name


Rogers
Enter clint NAME and AGE
TO STOP TYPE $$$$$
Fisher
32

Graves
42

Parker
50

Singer
45

Lewis
28
$$$$$

HELLO
LOWYER NAME = Davis
      Hall  35
      Moss  28
      Ford  47
     Brown  54
      Ginn  38
LOWYER NAME = Levine
     Pride  42
      Berk  38
     White  45
      Todd  25
     Dixon  32
    Newman  46
LOWYER NAME = Nelson
    Harris  42
   Jackson  52
   Roberts  40
     Eisen  32
     Adams  48
     Cohen  36
LOWYER NAME = Rogers
    Fisher  32
    Graves  42
    Parker  50
    Singer  45
     Lewis  28
Enter age to show clint in age of upper then the age
41
     Davis      Ford  47
     Davis     Brown  54
    Levine     Pride  42
    Levine     White  45
    Levine    Newman  46
    Nelson    Harris  42
    Nelson   Jackson  52
    Nelson     Adams  48
    Rogers    Graves  42
    Rogers    Parker  50
    Rogers    Singer  45
Enter age to show clint in age of upper then the age
48
     Davis     Brown  54
    Nelson   Jackson  52
    Nelson     Adams  48
    Rogers    Parker  50
*/