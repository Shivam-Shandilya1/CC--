// #include <bits/stdc++.h>

// using namespace std;

// vector<string> tokens; // to store the tokens

// // Function to check if a string can be generated from the given regular expression
// bool match(string reg, string str) {
// int i = 0, j = 0;
// while (i < reg.length() && j < str.length()) {
// if (reg[i] == '(') {
// int k = i;
// while (reg[k] != ')') {
// k++;
// }
// string sub = reg.substr(i + 1, k - i - 1);
// while (j < str.length() && match(sub, str.substr(j))) {
// j += sub.length();
// }
// i = k + 1;
// } else if (reg[i] == '*') {
// int k = i - 1;
// while (k >= 0 && reg[k] != '(') {
// k--;
// }
// string sub = reg.substr(k + 1, i - k - 1);
// while (j < str.length() && match(sub, str.substr(j))) {
// j += sub.length();
// }
// i++;
// } else if (reg[i] == '+') {
// int k = i - 1;
// while (k >= 0 && reg[k] != '(') {
// k--;
// }
// string sub = reg.substr(k + 1, i - k - 1);
// if (!match(sub, str.substr(j))) {
// return false;
// }
// while (j < str.length() && match(sub, str.substr(j))) {
// j += sub.length();
// }
// i++;
// } else if (reg[i] == '|') {
// int k = i;
// while (reg[k] != ')') {
// k++;
// }
// string sub = reg.substr(i + 1, k - i - 1);
// if (match(sub, str.substr(j))) {
// return true;
// }
// i = k + 1;
// } else if (reg[i] == str[j]) {
// i++;
// j++;
// } else {
// return false;
// }
// }
// return (i == reg.length() && j == str.length());
// }

// // Function to get the tokens from the input string
// void getTokens(string reg, string str) {
// int i = 0;
// while (i < str.length()) {
// bool flag = false;
// string temp = "";
// for (int j = str.length(); j > i; j--) {
// if (match(reg, str.substr(i, j - i))) {
// flag = true;
// temp = str.substr(i, j - i);
// i = j;
// break;
// }
// }
// if (flag) {
// tokens.push_back("$" + temp);
// } else {
// tokens.push_back("@" + str.substr(i, 1));
// i++;
// }
// }
// tokens.push_back("#");
// }

// int main() {
// string reg, str;

// // Reading the input from input.txt
// ifstream input("input.txt");
// getline(input, reg);
// getline(input, str);
// input.close();

// // Getting the tokens
// getTokens(reg, str);

// // Writing the output to output.txt
// ofstream output("output.txt");
// for (string token : tokens) {
//     output << token;
// }
// output.close();

// return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// const int N=1005;
// int n,m;
// string r,w,ans;
// int f[N][N];

// int dfs(int x,int y)
// {
//     if(f[x][y]) return f[x][y];
//     if(x==n&&y==m) return 1;
//     if(x>=n||y>=m) return -1e9;
//     int t=dfs(x+1,y),ret=-1e9;
//     if(r[x]=='a'||r[x]=='b')
//     {
//         if(r[x]==w[y]) ret=max(ret,dfs(x+1,y+1)+1);
//         return f[x][y]=ret;
//     }
//     if(r[x]=='+') ret=max(ret,dfs(x+1,y));
//     if(r[x]=='*') ret=max(ret,dfs(x+1,y));
//     if(r[x]=='.')
//     {
//         if(t>0) ret=max(ret,t);
//         if(r[x+1]==w[y]) ret=max(ret,dfs(x+2,y+1)+1);
//     }
//     return f[x][y]=ret;
// }

// int main()
// {
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     cin>>r>>w;
//     n=r.length();
//     m=w.length();
//     int i=0,j=0;
//     while(i<n&&j<m)
//     {
//         int k=dfs(i,j);
//         if(k<=0)
//         {
//             cout<<'@'<<w[j++];
//             continue;
//         }
//         cout<<'$';
//         while(k--)
//         {
//             if(r[i]=='a'||r[i]=='b') cout<<r[i++];
//             else i+=2;
//         }
//         j+=k;
//     }
//     cout<<'#'<<endl;
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

// Use of Thompson's Algorithm by converting the regular expression to postfix notation 
// to make it easier to convert to NFA.

string RegularExpressionToPostFix(string regularExpression) 
{
    // Variables to keep track of the number of alternations and atoms

    // Atom is the smallest unit of a pattern that can be matched

    // Alternation refers to the | operator where multiple patterns can be matched
    int numberOfAlternations=0, numOfAtoms=0;

   //Creating Static Character Buffer of length 8k
    static char buf[8000];

    //Char Pointer 
    char *end_ptr;

    // Parenthesis are used for grouping of subexpressions
    struct
    {
        int alt_num;
        int atom_num;
    }expression_Stack[100],*ptr;

    //ptr points to the expression stack beginning 
    ptr = expression_Stack;

    // end_ptr points to the buffer beginning
    end_ptr = buf;



    // If regular expression's length >= size of the buffer/2
    // return NULL

    if(regularExpression.size() >= sizeof buf / 2)
    {
        return NULL;
    }

    //Iterating regularExpression
    for(auto it = regularExpression.begin(); it!=regularExpression.end(); it++)
    {
        //Use Switch operator for avoiding multiple ifelse case...
        switch(*it)
        {
            //Left Parenthesis
            case '(':
                if(numOfAtoms > 1)
                {
                    numOfAtoms-=1;
                    end_ptr++;
                    *end_ptr = '.';
                }

                if(ptr >= (expression_Stack + 100))
                {
                    return NULL;
                }

                ptr->alt_num = numberOfAlternations;

                ptr->atom_num = numOfAtoms;

                ptr+=1;

                numberOfAlternations = 0;
                numOfAtoms = 0;
                break;

            //Case of Union Operator    
            case '|':
                if(!(numOfAtoms))
                {
                    return NULL;
                }
                while(--(numOfAtoms))
                {
                    end_ptr++;
                    *end_ptr = '.';
                }

                numberOfAlternations++;

                break;
            //Right Parenthesis
            case ')':
                if(ptr == expression_Stack)
                {
                    return NULL;
                }

                if(!numOfAtoms)
                {
                    return NULL;
                }

                while(--(numOfAtoms))
                {
                    *(end_ptr++) = '.';
                }

                while(numberOfAlternations--)
                {
                    *(end_ptr++) = '|';
                }

                --ptr;

                numberOfAlternations = ptr->alt_num;

                numOfAtoms = ptr->atom_num;

                numOfAtoms++;

                break;

            //Operator like '*','+','?'
            
            case '*':
            case '+':
            case '?':
                if(!numOfAtoms)
                {
                    return NULL;
                }
                
                *(end_ptr++) = *it;
                
                break;

            default:

                if(numOfAtoms>1)
                {
                    numOfAtoms--;

                    *(end_ptr++) = '.';
                }

                *(end_ptr++) = *it;

                numOfAtoms++;

                break;
        }
    }

    // If the expression stack is not empty
    // Then there will be some error and we return NULL

    if(ptr != expression_Stack)
    {
        return NULL;
    }

    while(--numOfAtoms)
    {
        end_ptr++;

        *end_ptr = '.';
    }

    while(numberOfAlternations)
    {
        numberOfAlternations-=1;
        end_ptr++;
        *end_ptr = '|';
    }

    *end_ptr = 0;

    return buf;
}

// Match shows the  matching of state and the string.

// Branch shows the branching of two other states by createState.

enum
{
    MatchStateString = 256,
    Branch2States = 257
};

typedef struct State State;
struct State
{
    int special_Char,last_list;
    State *next_State,*branch_State;
};


// The state machine is represented by a list of states. 
// The list is terminated by a createState with special_Char == Match.

//Matching createState

State matchstate = { MatchStateString };
int States_Num;

// A State is created with the help of  special_Char, next and branch states.
State* createState(int ch, State *nxt_State, State *brn_State) {
    State *st;
    st = (State*)malloc(sizeof *st);

    States_Num++;

    st->special_Char = ch;
    st->next_State = nxt_State;
    st->last_list = 0;
    st->branch_State = brn_State;
    
    return st;
}


typedef struct Fragment Fr;
typedef union Ptrlist P_list;

// struct Fragment is created
struct Fragment
{
    State *head_node;

    P_list *out;
};

// Fr frag is created

Fr frag(State *head_node, P_list *out)
{
    Fr n = { head_node, out };

    return n;
}

//Union PtrList is created
union Ptrlist
{
    P_list *next;

    State *s;
};


//union P_list pointer path1 function takes pointer of pointer of State

P_list* path1(State **outptr)
{
    P_list *list = (P_list*)outptr;

    list->next = NULL;

    return list;
}


// void function patch take union pointer and state pointer as argumnets
void patch(P_list *l, State *s)
{
    P_list *next;

    while(l){
        next = l->next;
        l->s = s;
        l=next;
    }
}


P_list* append(Ptrlist *l1, Ptrlist *l2)
{
    P_list *oldl1;

    oldl1 = l1;
    while(l1->next)
        l1 = l1->next;
    l1->next = l2;
    return oldl1;
}


State* PostFixExpressionToNFA(string postfix)
{
    Fr stack[1000], *stackp, e1, e2, e;
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
                push(frag(s, path1(&s->next_State)));
                break;
            case '.':	/* catenate */
                e2 = pop();
                e1 = pop();
                patch(e1.out, e2.head_node);
                push(frag(e1.head_node, e2.out));
                break;
            case '|':	/* alternate */
                e2 = pop();
                e1 = pop();
                s = createState(Branch2States, e1.head_node, e2.head_node);
                push(frag(s, append(e1.out, e2.out)));
                break;
            case '?':	/* zero or one */
                e = pop();
                s = createState(Branch2States, e.head_node, NULL);
                push(frag(s, append(e.out, path1(&s->branch_State))));
                break;
            case '*':	/* zero or more */
                e = pop();
                s = createState(Branch2States, e.head_node, NULL);
                patch(e.out, s);
                push(frag(s, path1(&s->branch_State)));
                break;
            case '+':	/* one or more */
                e = pop();
                s = createState(Branch2States, e.head_node, NULL);
                patch(e.out, s);
                push(frag(e.head_node, path1(&s->branch_State)));
                break;
        }
    }

    e = pop();
    if(stackp != stack)
        return NULL;

    patch(e.out, &matchstate);
    return e.head_node;
#undef pop
#undef push
}


//Created struct NFA_PATH design the Path for NFA
typedef struct NFA_PATH Path;

struct NFA_PATH
{
    //contains pointer to State*
    State **state;

    //contains number of States
    int num;
};


Path l1, l2;
static int listid;

void AddStateToPath(Path*, State*);
void StepForNfA(Path*, int, Path*);

// create State list 
Path *head_nodelist(State *head_node, Path *l)
{
    l->num = 0;
    listid++;
    AddStateToPath(l, head_node);
    return l;
}

// Check whether createState list contains a match.
int ismatch(Path *l)
{
    int i;



    for(i=0; i<l->num; i++)

        if(l->state[i] == &matchstate) {
            return 1;
        }
    return 0;
}

/* Add s to l, following unlabeled arrows. */
void
AddStateToPath(Path *l, State *s)
{
    if(s == NULL || s->last_list == listid)
        return;
    s->last_list = listid;
    if(s->special_Char == Branch2States){
        /* follow unlabeled arrows */
        AddStateToPath(l, s->next_State);
        AddStateToPath(l, s->branch_State);
        return;
    }
    l->state[l->num++] = s;


}

/*
 * StepForNfA the NFA from the states in clist
 * past the character special_Char,
 * to create next NFA createState set nlist.
 */


void StepForNfA(Path *clist, int c, Path *nlist) {
    int i;
    State *s;

    listid++;
    nlist->num = 0;


    for(i=0; i<clist->num; i++){

        s = clist->state[i];
        if(s->special_Char == c){


            AddStateToPath(nlist, s->next_State);

        }

    }

}

/* Run NFA to determine whether it matches s. */
int match(State *head_node, string s)
{
    int i, c;
    Path *clist, *nlist, *t;

    clist = head_nodelist(head_node, &l1);
    nlist = &l2;
    for(auto it = s.begin(); it!=s.end(); it++){

        c = *it & 0xFF;

        StepForNfA(clist, c, nlist);



        t = clist; clist = nlist; nlist = t;	/* swap clist, nlist */

    }

    return ismatch(clist);
}






string findValidTokens(string reg,string w) {
  
  string ans = "";
  while (w.length() > 0) {
    bool matched = false;
    for (int i = w.length(); i >= 0; i--) {
      string sub = w.substr(0, i);
      if (regex_match(sub,regex(reg))) {
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

    // //PostFixExpression:Variable
    // //contains the postfix form of regular Expression
    // string PostFixExpression;

    // //head_node:Variable
    // //contains the starting state of NFA
    // State *head_node;
    
    // // regex :Variable
    // // reads regular expression from input.txt
    // // InputString :Variable
    // // reads string that have to match from regula expressions.  
    string regex, InputString;
     

    // Reading the input from input.txt
    ifstream in("./input.txt");

    //Get first line from input.txt and store it in the regex variable
    getline(in, regex);

    //Get second line from input.txt and store it in the InputString variable
    getline(in, InputString);

    // // cout << regex <<endl;
    // // cout << InputString<<endl;

    // //DEBUG::ERROR IF FILE DOESN'T READ REGEX
    // if(regex.empty())
    // {
    //     cout<<"Regular Expression is ABSENT.\n";
    //     return -1;
    // }
    // //cout<<"The regex is: "<<regex<<endl;

    // //Convert Regex to PostFix Expression.......
    // PostFixExpression = RegularExpressionToPostFix(regex);
    // // cout<<PostFixExpression<<endl;

    // //DEBUG::ERROR IF POSTFIX EXPRESSION WILLN'T BE GENERATED
    // if(PostFixExpression.empty())
    // {
    //     cout<<regex<<"is not a correct regular expression"<<endl;
    //     return -1;
    // }

    // //Inititalize head_node to PostToNFA
    // //converting regular expression to NFA
    // head_node = PostFixExpressionToNFA(PostFixExpression);

    // //DEBUG::ERROR CAN"T CONVERT TO NFA
    // if(!head_node)
    // {
    //     cout<<"PostFixExpressionToNFA isn't working..."<<endl;
    //     cout<<PostFixExpression<<endl;
    //     return -1;
    // }

    // //Created Adjacency lists for NFA states
    // l1.state = (State**)malloc(States_Num * sizeof l1.state[0]);
    // l2.state = (State**)malloc(States_Num * sizeof l2.state[0]);


    string ans = findValidTokens(regex,InputString);

    cout << ans << endl;
     ofstream out("output.txt");
     out << ans;
    return 0;
}
