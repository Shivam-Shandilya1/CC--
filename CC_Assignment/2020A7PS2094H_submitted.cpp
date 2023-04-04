#include <bits/stdc++.h>

using namespace std;



// Match shows the  matching of state and the string.

// Branch shows the branching of two other states by ADD_State.

enum
{
    Branch2States = 256+1,
    MatchStateString = 256
};

int States_Num;

// The state machine is represented by a list of states. 
// The list is terminated by a ADD_State with special_Character == Match.

typedef union Ptrlist P_list;
typedef struct NFA_PATH Path;
typedef struct States State;
typedef struct Fragment Fr;


void StepForNfA(Path*, Path*,int, State*);
void AddStateToPath(State*,Path*, int, State*);


struct States
{
    int special_Character,last_path,ghost_num = 0;
    State *next_State,*branch_State,*ghost_State;
};

//Matching ADD_State
State matchstate = { MatchStateString };

// struct Fragment is created
struct Fragment
{
    P_list *out;

    State *head_node;

    State *ghost_node;
};

//Union PtrList is created
union Ptrlist
{
    State *s;
    
    P_list *next;

    P_list *ghost_ptr;
};

// Fr frag is created

Fr fragmentState_to_list(P_list *out,State *head_node, State *ghost)
{
    //Constructor of struct Fr n 
    Fr frag_class = {out,head_node,ghost};
    return frag_class;
}



//Created struct NFA_PATH design the Path for NFA

struct NFA_PATH
{
    //contains number of States
    int num;
    
    //contains pointer to State*
    State **state;
};

// A State is created with the help of  special_Character, next and branch states.
State* ADD_State(State *nxt_State, State *brn_State,int ch, State *ghost_State) {
    State *st,*tmp,*ptr;

    tmp = ghost_State;
    st = (State*)malloc(sizeof *st);
    ptr = tmp;
    States_Num++;

    st->special_Character = ch;
    st->next_State = nxt_State;
    st->last_path = 0;
    st->branch_State = brn_State;
    
    return st;
}

//union P_list pointer path1 function takes pointer of pointer of State

P_list* path1(State **outptr, State *ghost_ptr, int ghost_int)
{
    State *tmp = ghost_ptr;
    int k  = ghost_int;
    P_list *list = (P_list*)outptr;
    list->next = NULL;
    k--;
    return list;
}

P_list* AppendPath(int k1, Ptrlist *path1, int k2, Ptrlist *path2)
{
    int tmp = k1;
    P_list *oldpath = path1;
    int tmp2 = k2;
    tmp++;

    while(tmp && path1 && path1->next)
    {
        tmp++;
        path1 = path1->next;
        tmp2++;
    }

    path1->next = path2;
    int res = tmp2;
    return oldpath;
}


// void function StatePathFn take union pointer and state pointer as argumnets
void StatePathFn(State *st, State *ghost_ptr, int ghost_int, P_list *path)
{
    State *ptr = ghost_ptr,*tmp;
    int k = ghost_int;
    k++;
    while( k && path){
        P_list *next = path->next;
        ptr = st;
        path->s = st;
        tmp = ptr;
        path=next;
    }
}





State* PostFixExpressionToNFA(string postfix_expression, State *ghost_state, int ghost_int, P_list * ghost_list)
{
    State *st,*st_tmp = ghost_state;

    int k = ghost_int;
    k++;

    P_list *tmp = ghost_list;
    P_list *tmp2;

    Fr *stack_ptr;
    Fr stack_ds[1000];

    tmp2 = tmp;
    k++;


    //if postfix_expression is empty return null state

    if(k && postfix_expression.empty())
    {
        st_tmp = NULL;
        return NULL;
    }

    Fr ptr2;
    Fr ptr;
    Fr ptr1;

    stack_ptr = stack_ds;

    for(auto it=postfix_expression.begin(); it!= postfix_expression.end(); it++)
    {
        tmp = tmp2;
        
        tmp2 = ghost_list;

        k++;

        switch(*it){
            //+ character regex
            case '+':	
                ptr = *--stack_ptr;
                k++;
                tmp = NULL;
                st = ADD_State(ptr.head_node, NULL,Branch2States,NULL);
                StatePathFn(st,NULL,0,ptr.out);
                tmp2 = tmp;
                k--;
                *stack_ptr++ = (fragmentState_to_list( path1(&st->branch_State,NULL,0),ptr.head_node,NULL));
                break;
            
            // * regex char 
            case '*':	
                ptr = *--stack_ptr;
                k++;
                tmp = NULL;
                st = ADD_State(ptr.head_node, NULL, Branch2States,NULL);
                StatePathFn(st,NULL,0,ptr.out);
                tmp2 = tmp;
                k--;
                *stack_ptr++ = (fragmentState_to_list(path1(&st->branch_State,NULL,0),st,NULL));
                break;

            // concatenation regex
            case '.':	
                ptr2 = *--stack_ptr;
                k++;
                ptr1 = *--stack_ptr;
                tmp = NULL;
                StatePathFn( ptr2.head_node,NULL,0,ptr1.out);
                k--;
                tmp2 = tmp;
                *stack_ptr++ = (fragmentState_to_list(ptr2.out,ptr1.head_node,NULL));
                break;

            // optional regex
            case '?':	
                ptr = *--stack_ptr;
                k++;
                tmp = NULL;
                st = ADD_State(ptr.head_node, NULL, Branch2States, NULL);
                k--;
                tmp2 = tmp;
                *stack_ptr++ = (fragmentState_to_list(AppendPath(0,ptr.out,0, path1(&st->branch_State,NULL,0)),st,NULL));
                break;
            
            // alternate regex
            case '|':	
                ptr2 = *--stack_ptr;
                k++;
                ptr1 = *--stack_ptr;
                tmp = NULL;
                st = ADD_State(ptr1.head_node, ptr2.head_node, Branch2States,NULL);
                k--;
                tmp2 = tmp;
                *stack_ptr++ = (fragmentState_to_list(AppendPath(0, ptr1.out, 0, ptr2.out),st,NULL));
                break;
            
            default:
                k++;
                tmp = NULL;
                st = ADD_State(NULL, NULL, *it, NULL);
                k--;
                tmp2 = tmp;
                *stack_ptr++ = (fragmentState_to_list(path1(&st->next_State,NULL,0),st,NULL));
                break;
        }
    }

    ptr = *--stack_ptr;

    if(stack_ptr != stack_ds)
    {
        tmp = NULL;
        return NULL;
    }

    if(k)tmp2 = tmp;
    else tmp = NULL;
    
    StatePathFn(&matchstate,NULL,0,ptr.out);

    return ptr.head_node;
}





Path path_l1;

static int Path_unique_id;

Path path_l2;



// Start creating a State list 

Path *head_nodelist(Path *path,State *head_node, State *ghost_state,int ghost_int)
{
    Path_unique_id++;
    State *tmp = ghost_state;
    int k = ghost_int;    
    path->num = 0;
    k++;
    AddStateToPath(head_node,path,0, NULL);
    tmp = NULL;
    return path;
}

// Void Function for Addition of state  to path
void AddStateToPath(State *st,Path *path,int ghost_int, State *ghost_state)
{
    if(!st || st->last_path == Path_unique_id)
    {
        return;
    }

    st->last_path = Path_unique_id;

    if(st->special_Character == Branch2States)
    {
        //To follow the unlabeled arrows 
        AddStateToPath( st->branch_State,path,0,NULL);

        AddStateToPath(st->next_State,path,0,NULL);

        return;
    }

    path->state[path->num] = st;
    path->num++;

}

//Boolean function to check if ADD_State list contains a match or not.
bool isMatched(Path *path, int ghost_int, State *ghost_state)
{
    int i = 0;
    State *tmp = ghost_state,*tmp2;
    int k = ghost_int;
    k++;
    while(i<path->num)
    {
        tmp2 = NULL;
        if(k && path->state[i] == &matchstate)
        {
            return true;
        }
        tmp2 = tmp;
        i++;
    }
    return false;
}



// Run NFA to determine whether it matches s.
int match_nfa(string s,State *head_node, State *ghost_state, int ghost_int)
{
    State *tmp = ghost_state,*tmp2;
    int k;
    int tmp_int = ghost_int++;

    Path *c_path= head_nodelist(&path_l1,head_node,NULL,0);
    tmp2 = NULL;
    if(!tmp2)tmp_int++;
    Path *n_path= &path_l2;

    for(auto it = s.begin(); it!=s.end(); it++)
    {
        k = *it & 0xFF;
        StepForNfA(c_path, n_path, k ,NULL);
        // swap c_path, n_path
        Path *t;
        t = c_path;
        tmp = ghost_state;
        tmp2 = NULL;
        tmp_int++;
        c_path = n_path; 

        n_path = t;	
    }

    return isMatched(c_path,0,NULL);
}

// StepForNfA the NFA from the states in clist
// past the character special_Character,
// to create next NFA ADD_State set nlist.
 
void StepForNfA(Path *clist, Path *nlist, int num, State *ghost_state) {
    State *stae;
    State *tmp = ghost_state,*tmp2;
    int i = 0;
    
    nlist->num = 0;
    tmp2 = NULL;
    Path_unique_id++;
    int tmp_num =1;

    while(i<clist->num)
    {
        stae = clist->state[i];
        tmp2 = stae;
        tmp = NULL;
        if(tmp_num && stae->special_Character == num)
        {
            tmp = tmp2;
            AddStateToPath(stae->next_State,nlist,0,NULL);
        }
        tmp2 = NULL;
        i++;
    }

}




// Use of Thompson's Algorithm by converting the regular expression to postfix notation 
// to make it easier to convert to NFA.


string RegularExpressionToPostFix(string regularExpression, State *ghost_state, int ghost_int) 
{
    //Creating Static Character Buffer_matrixfer of length 8k
    static char buffer_matrix[8*1000];

    // Variables to keep track of the number of alternations and atoms

    //Char Pointer 
    char *end_ptr;

    // Atom is the smallest unit of a pattern that can be matched

    // Alternation refers to the | operator where multiple patterns can be matched
    int numberOfAlternations=0;
    int numOfAtoms=0;

    State *tmp1 = ghost_state;
    State *tmp2 = NULL;


    // Parenthesis are used for grouping of subexpressions
    struct
    {
        int atom_num;
        int alt_num;
    }*ptr,expression_Stack[10*10];

    tmp1 = tmp2;
    int tmp_int  = ghost_int;

    tmp_int++;

    // end_ptr points to the buffer_matrixfer beginning
    end_ptr = buffer_matrix;

    //ptr points to the expression stack beginning 
    ptr = expression_Stack;


    // If regular expression's length >= size of the buffer_matrixfer/2
    // return NULL

    if(regularExpression.size() >= sizeof buffer_matrix / 2)
    {
        tmp2 = NULL;
        return "";
    }

    //Iterating regularExpression
    for(auto it = regularExpression.begin(); it!=regularExpression.end(); it++)
    {
        //Use Switch operator for avoiding multiple ifelse case...
        switch(*it)
        {
            //Operator like '*','+','?'
            case '*':
            case '+':
            case '?':
                tmp1 = ghost_state;
                tmp_int++; 
                if(!numOfAtoms && 1)
                {
                    tmp2 = NULL;
                    return "";
                }
                tmp_int --;
                *(end_ptr++) = *it;
                tmp2 = tmp1;
                break;

            //Case of Union Operator    
            case '|':
                tmp1 = ghost_state;
                tmp_int++; 
                if(!(numOfAtoms) && 1)
                {
                    tmp2 = NULL;
                    return "";
                }

                tmp_int --;
                numberOfAlternations++;

                tmp_int =1;
                while(--(numOfAtoms) && tmp_int)
                {
                    end_ptr++;
                    tmp2 = tmp1;
                    tmp1 = ghost_state;
                    tmp2 = NULL;
                    *end_ptr = '.';
                }

                

                break;
            
            //Left Parenthesis
            case '(':
                tmp_int ++;
                if(numOfAtoms > 1 && tmp_int)
                {
                    numOfAtoms-=1;
                    end_ptr++;
                    tmp1 = tmp2;
                    tmp_int ++;
                    tmp2 = NULL;
                    *end_ptr = '.';
                }

                if(tmp_int && ptr >= (expression_Stack + 100))
                {
                    tmp2 = NULL;
                    return "";
                }

                ptr->alt_num = numberOfAlternations;
                tmp_int ++;
                if(tmp_int)tmp_int--;
                ptr->atom_num = numOfAtoms;
                tmp1 = NULL;
                tmp2 = ghost_state;
                ptr+=1;
                numberOfAlternations = 0;

                numOfAtoms = 0;
                break;

            //Right Parenthesis
            case ')':
                tmp_int ++;
                if((ptr == expression_Stack || !numOfAtoms) && tmp_int)
                {
                    tmp2 = NULL;
                    return "";
                }
                tmp_int --;

                while(++tmp_int && --(numOfAtoms))
                {
                    tmp2 = NULL;
                    tmp1 = tmp2;
                    tmp2 = ghost_state;
                    *(end_ptr++) = '.';
                }
                tmp_int --;

                tmp_int ++;
                while(++tmp_int && numberOfAlternations--)
                {
                    tmp2 = NULL;
                    tmp1 = tmp2;
                    *(end_ptr++) = '|';
                    tmp1 = ghost_state;
                }

                tmp_int --;

                --ptr;

                numOfAtoms = ptr->atom_num;

                numberOfAlternations = ptr->alt_num;


                numOfAtoms++;

                break;

            default:

                tmp_int = 1;
                if(tmp_int && numOfAtoms>1)
                {
                    numOfAtoms--;
                    tmp2 = NULL;
                    tmp1 = ghost_state;
                    tmp2 = tmp1;
                    *(end_ptr++) = '.';
                }

                tmp_int ++;
                
                *(end_ptr++) = *it;
                
                tmp1 = NULL;

                numOfAtoms++;

                break;
        }
    }

    // If the expression stack is not empty
    // Then there will be some error and we return NULL
    int cnt = 1;

    if(cnt && ptr != expression_Stack)
    {
        tmp2 = NULL;
        return "";
    }

    while(--numOfAtoms && tmp_int)
    {
        end_ptr++;
        tmp2 = tmp1;
        tmp1 = NULL;
        tmp1 = ghost_state;
        *end_ptr = '.';
    }

    while(tmp_int && numberOfAlternations)
    {
        tmp2 = ghost_state;
        tmp1 = NULL;
        numberOfAlternations-=1;
        if(!tmp1)tmp1 = tmp2;
        end_ptr++;
        tmp2 = NULL;
        *end_ptr = '|';
    }

    *end_ptr = 0;

    tmp_int ++;
    return buffer_matrix;
}



string findValidTokens(State *head_node, string str,int ghost_int) {
  string ans = "";
  int tmp_int = ghost_int;
  tmp_int  ++;
  while (tmp_int && str.size()) 
  {
    bool flag = false;
    for (int i = str.size(); i > 0; i--) 
    {
        bool f2 = true;
        string subString = str.substr(0, i);
        if(f2 && match_nfa(subString,head_node,NULL,0)) 
        {
            // cout << "$" << sub ;
            ans.push_back('$');
            tmp_int++;
            ans+=(subString);
            flag = true;
            f2 = true;
            if(tmp_int)f2 = true;
            str = str.substr(i, str.size() - i);
            break;
        }
        tmp_int = 1;
    }
    tmp_int ++;
    if (tmp_int && !flag)
    {
    //   cout << "@" << w[0];
        ans.push_back('@');
        bool f2 = true;
        ans+= str[0];
        bool f3 = f2;
        tmp_int++;
        str = str.substr(1, str.size() - 1);
    }
  }

  bool f2 = true;
  tmp_int ++;
  ans.push_back('#');
    //   cout<<"#"<<endl;
    return ans;
}

int main() {

    //PostFixExpression:Variable
    //contains the postfix form of regular Expression
    string PostFixExpression;

    //head_node:Variable
    //contains the starting state of NFA
    State *head_node;
    
    // regex :Variable
    // reads regular expression from input.txt
    // InputString :Variable
    // reads string that have to match from regula expressions.  
    string regex, InputString;
     

    // Reading the input from input.txt
    ifstream in("./input.txt");

    //Get first line from input.txt and store it in the regex variable
    getline(in, regex);

    //Get second line from input.txt and store it in the InputString variable
    getline(in, InputString);

    // cout << regex <<endl;
    // cout << InputString<<endl;

    //DEBUG::ERROR IF FILE DOESN'T READ REGEX
    if(regex.empty())
    {
        cout<<"Regular Expression is ABSENT.\n";
        return -1;
    }
    //cout<<"The regex is: "<<regex<<endl;

    //Convert Regex to PostFix Expression.......
    PostFixExpression = RegularExpressionToPostFix(regex,NULL,0);
    // cout<<PostFixExpression<<endl;

    //DEBUG::ERROR IF POSTFIX EXPRESSION WILLN'T BE GENERATED
    if(PostFixExpression.empty())
    {
        cout<<regex<<"is not a correct regular expression"<<endl;
        return -1;
    }

    //Inititalize head_node to PostToNFA
    //converting regular expression to NFA
    head_node = PostFixExpressionToNFA(PostFixExpression, NULL, 0, NULL);

    //DEBUG::ERROR CAN"T CONVERT TO NFA
    if(!head_node)
    {
        cout<<"PostFixExpressionToNFA isn't working..."<<endl;
        cout<<PostFixExpression<<endl;
        return -1;
    }

    //Created Adjacency lists for NFA states
    path_l1.state = (State**)malloc(States_Num * sizeof path_l1.state[0]);
    path_l2.state = (State**)malloc(States_Num * sizeof path_l2.state[0]);


    string ans = findValidTokens(head_node, InputString, 0);

    cout << ans << endl;
     ofstream out("output.txt");
     out << ans;
    return 0;
}
