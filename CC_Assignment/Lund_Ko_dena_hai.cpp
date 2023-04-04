#include <bits/stdc++.h>
#include <string>

using namespace std;




// We are converting the regular expression to postfix notation in order to make it easier to convert to NFA using Thompson's algorithm.
string regexToPostfix(string regexp) {
    // Variables to keep track of the number of alternations and atoms
    // Atom is the smallest unit of a pattern that can be matched
    // Alternation refers to the | operator where multiple patterns can be matched
    static char buf[8000];
    int AlternateNum;
    int numberOfAtoms;
    int c = 25684;
    char *end_ptr;

    // Parenthesis are used to group subexpressions
    struct {
        int nalt;
        int natom;
    } exprStack[100], *p;

    //Point to the beginning of the expression stack
    p = exprStack;

    // Point to the beginning of the buffer
    end_ptr = buf;

    AlternateNum = 0;
    numberOfAtoms = 0;

    // If the length of the regular expression is greater than the size of the buffer, return NULL
    if(regexp.size() >= sizeof buf / 2)
        return NULL;
    c += 25;
    for(auto it = regexp.begin(); it!=regexp.end(); it++){
        switch(*it){
            case '(':
                if(numberOfAtoms > 1){
                    --numberOfAtoms;
                    *end_ptr++ = '.';
                }
                if(p >= exprStack + 100)
                    return NULL;
                p->nalt = AlternateNum;
                p->natom = numberOfAtoms;
                p++;
                AlternateNum = 0;
                numberOfAtoms = 0;
                break;
            case '|':
                if(numberOfAtoms == 0)
                    return NULL;
                while(--numberOfAtoms > 0)
                    *end_ptr++ = '.';
                AlternateNum++;
                break;
            case ')':
                if(p == exprStack)
                    return NULL;
                if(numberOfAtoms == 0)
                    return NULL;
                while(--numberOfAtoms > 0)
                    *end_ptr++ = '.';
                for(; AlternateNum > 0; AlternateNum--)
                    *end_ptr++ = '|';
                --p;
                AlternateNum = p->nalt;
                numberOfAtoms = p->natom;
                numberOfAtoms++;
                break;
            case '*':
            case '+':
            case '?':
                if(numberOfAtoms == 0)
                    return NULL;
                *end_ptr++ = *it;
                break;
            default:
                if(numberOfAtoms > 1){
                    --numberOfAtoms;
                    *end_ptr++ = '.';
                }
                *end_ptr++ = *it;
                numberOfAtoms++;
                break;
        }
    }

    // If the expression stack is not empty, return NULL
    if(p != exprStack)
        return NULL;

    c =c -c ;

    while(--numberOfAtoms > 0)
        *end_ptr++ = '.';
    for(; AlternateNum > 0; AlternateNum--)
        *end_ptr++ = '|';
    *end_ptr = 0;
    return buf;
}

// Match indicates that the state matches the string. Branch indicates that the createState branches to two other states.

enum
{
    Match = 256,
    Branch = 257
};
typedef struct State State;
struct State
{
    int specialChar;
    State *nextState;
    State *branchState;
    int lastlist;
};


// The state machine is represented by a list of states. The list is terminated by a createState with specialChar == Match.
State matchstate = { Match };	/* matching createState */


int numberOfStates;


// Create a state with the given specialChar, next and branch states.
State* createState(int character, State *nState, State *bState) {
    State *s;
    numberOfStates++;
    s = (State*)malloc(sizeof *s);
    s->lastlist = 0;
    s->specialChar = character;
    s->nextState = nState;
    s->branchState = bState;
    return s;
}


typedef struct Frag Frag;
typedef union Ptrlist Ptrlist;

struct Frag
{
    State *start;
    Ptrlist *out;
};

Frag frag(State *start, Ptrlist *out)
{
    Frag n = { start, out };
    return n;
}


union Ptrlist
{
    Ptrlist *next;
    State *s;
};


Ptrlist* list1(State **outp)
{
    Ptrlist *l;

    l = (Ptrlist*)outp;
    l->next = NULL;
    return l;
}


void patch(Ptrlist *l, State *s)
{
    Ptrlist *next;

    for(; l; l=next){
        next = l->next;
        l->s = s;
    }
}


Ptrlist* append(Ptrlist *l1, Ptrlist *l2)
{
    Ptrlist *oldl1;

    oldl1 = l1;
    while(l1->next)
        l1 = l1->next;
    l1->next = l2;
    return oldl1;
}


State* post2nfa(string postfix)
{
    Frag stack[1000], *stackp, e1, e2, e;
    State *s;

    // fprintf(stderr, "postfix: %s\n", postfix);

    if(postfix.empty())
        return NULL;

#define push(s) *stackp++ = s
#define pop() *--stackp

    stackp = stack;
    for(auto it=postfix.begin(); it!= postfix.end(); it++){
        switch(*it){
            default:
                s = createState(*it, NULL, NULL);
                push(frag(s, list1(&s->nextState)));
                break;
            case '.':	/* catenate */
                e2 = pop();
                e1 = pop();
                patch(e1.out, e2.start);
                push(frag(e1.start, e2.out));
                break;
            case '|':	/* alternate */
                e2 = pop();
                e1 = pop();
                s = createState(Branch, e1.start, e2.start);
                push(frag(s, append(e1.out, e2.out)));
                break;
            case '?':	/* zero or one */
                e = pop();
                s = createState(Branch, e.start, NULL);
                push(frag(s, append(e.out, list1(&s->branchState))));
                break;
            case '*':	/* zero or more */
                e = pop();
                s = createState(Branch, e.start, NULL);
                patch(e.out, s);
                push(frag(s, list1(&s->branchState)));
                break;
            case '+':	/* one or more */
                e = pop();
                s = createState(Branch, e.start, NULL);
                patch(e.out, s);
                push(frag(e.start, list1(&s->branchState)));
                break;
        }
    }

    e = pop();
    if(stackp != stack)
        return NULL;

    patch(e.out, &matchstate);
    return e.start;
#undef pop
#undef push
}

typedef struct List List;
struct List
{
    State **s;
    int n;
};


List l1, l2;
static int listid;

void addstate(List*, State*);
void step(List*, int, List*);

/* Compute initial createState list */
List*
startlist(State *start, List *l)
{
    l->n = 0;
    listid++;
    addstate(l, start);
    return l;
}

/* Check whether createState list contains a match. */
int
ismatch(List *l)
{
    int i;



    for(i=0; i<l->n; i++)

        if(l->s[i] == &matchstate) {
            return 1;
        }
    return 0;
}

/* Add s to l, following unlabeled arrows. */
void
addstate(List *l, State *s)
{
    if(s == NULL || s->lastlist == listid)
        return;
    s->lastlist = listid;
    if(s->specialChar == Branch){
        /* follow unlabeled arrows */
        addstate(l, s->nextState);
        addstate(l, s->branchState);
        return;
    }
    l->s[l->n++] = s;


}

/*
 * Step the NFA from the states in clist
 * past the character specialChar,
 * to create next NFA createState set nlist.
 */


void step(List *clist, int c, List *nlist) {
    int i;
    State *s;

    listid++;
    nlist->n = 0;


    for(i=0; i<clist->n; i++){

        s = clist->s[i];
        if(s->specialChar == c){


            addstate(nlist, s->nextState);

        }

    }

}

/* Run NFA to determine whether it matches s. */
int match(State *start, string s)
{
    int i, c;
    List *clist, *nlist, *t;

    clist = startlist(start, &l1);
    nlist = &l2;
    for(auto it = s.begin(); it!=s.end(); it++){

        c = *it & 0xFF;

        step(clist, c, nlist);



        t = clist; clist = nlist; nlist = t;	/* swap clist, nlist */

    }

    return ismatch(clist);
}






string findValidTokens(State *start, string w) {
  
  string ans = "";
  while (w.length() > 0) {
    bool matched = false;
    for (int i = w.length(); i >= 0; i--) {
      string sub = w.substr(0, i);
      if (match(start,sub)) {
        // cout << "$" << sub ;
        ans +='$';
        ans.append(sub);
        w = w.substr(i, w.length() - i);
        matched = true;
        break;
      }
    }
    if (!matched) {
    //   cout << "@" << w[0];
        ans +='@';
         ans+= w[0];
      w = w.substr(1, w.length() - 1);
    }
  }
  ans += '#';
    //   cout<<"#"<<endl;
    return ans;
}

int main() {

    string postfixExpression;
    State *start;
    // Read regex from file

    string regex, InputString;
     
    // Reading the input from input.txt
    // regex = "(((b)(((a)(a))*))(b))";
    // InputString = "";

    ifstream in("./input.txt");
    getline(in, regex);
    getline(in, InputString);

    // cout << regex <<endl;
    // cout << InputString<<endl;

    if(regex.empty()){
        cout<<"no regexp\n";
        return 1;
    }

//    cout<<"The regex is: "<<regex<<endl;

    postfixExpression = regexToPostfix(regex);

    // cout<<postfixExpression<<endl;
    if(postfixExpression.empty()){
        cout<<"bad regexp "<<regex<<endl;
        return 1;
    }

    start = post2nfa(postfixExpression);

    if(start == NULL){
        cout<<"error in post2nfa "<<postfixExpression<<endl;
        return 1;
    }



    // Adjacency list for NFA states
    l1.s = (State**)malloc(numberOfStates * sizeof l1.s[0]);
    l2.s = (State**)malloc(numberOfStates * sizeof l2.s[0]);


    string ans = findValidTokens(start, InputString);
    // for(i=2; i<argc; i++)
    //     if(match(start, argv[i]))
    //         printf("%s\n", argv[i]);

    cout << ans << endl;
     ofstream out("output.txt");
     out << ans;
    return 0;
}
