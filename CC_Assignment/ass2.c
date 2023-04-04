#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***
 *    Nikhil Sharma
 *    2020A7PS1303H
 */
double temparr1[100];
char fileoperation1[100];
// Special character to check if branch or match
#define numm 256
#define nums 257
char *fileOp;

// Print file operation
void printCval(const char *str, int index){
    if(str[index] == 'r'){
        fileOp = "Read";
    }
    else if(str[index] == 'w'){
        fileOp = "Write";
    }
    else if(str[index] == 's'){
        fileOp = "Seek";
    }
    else if(str[index] == 'a'){
        fileOp = "Append";
    }
    else{
        fileOp = "Error";
    }
}

// We are converting the regular expression to postfix notation in order to make it easier to convert to NFA using Thompson's algorithm.
char * regexToPostfix(char * regexp , double *temparr, char *fileoperation) {
    // Variables to keep track of the number of alternations and atoms
    // Atom is the smallest unit of a pattern that can be matched
    // Alternation refers to the | operator where multiple patterns can be matched
    int numberOfAlts, numberOfAtoms;
#define MAX 1000
    int bufferSize = MAX * sizeof (char);

// Allocate memory dynamically for buffer
    char *buf = (char *) malloc(bufferSize);

   // static char buf[9000];
    char * end_ptr;

    // Parenthesis are used to group subexpressions
    struct {
        long int nalt;
        long int natom;
    }
            exprStack[100], * p;

    //Point to the beginning of the expression stack
    p = exprStack;
    // Point to the beginning of the buffer
    end_ptr = buf;
    // Initialize the number of alternations and atoms to 0
    numberOfAlts = 0;
    numberOfAtoms = numberOfAlts;

    // If the length of the regular expression is greater than the size of the buffer, return NULL
    int sizeOfString = strlen(regexp);


    if (sizeOfString >=  bufferSize / 2)
        return NULL;
    int tempIndex = 0;
    // loop through the regular expression
    for (int k = 0 ;*regexp; regexp++, k++) {
        // Check if the character is a space or a tab and if so, skip it
        if(temparr[tempIndex] == 0){
            temparr[tempIndex] = 1;
            fileoperation[tempIndex] = 'w';
        }
        else if(temparr[tempIndex] == 1){
            temparr[tempIndex] = 2;
            fileoperation[tempIndex] = 's';
        }
        else if(temparr[tempIndex] == 2){
            temparr[tempIndex] = 3;
            fileoperation[tempIndex] = 'a';
        }
        else if(temparr[tempIndex] == 3){
            temparr[tempIndex] = 0;
            fileoperation[tempIndex] = 'r';
        }
        if (*regexp == '|') {
            if (numberOfAtoms == 0)
                return NULL;
            while (--numberOfAtoms > 0)
                *end_ptr++ = '.';
            numberOfAlts += 1;
        } else if (*regexp == '(') {
            if (numberOfAtoms > 1) {
                --numberOfAtoms;
                *end_ptr++ = '.';
            }
            if (numberOfAtoms == 0) {
                temparr[tempIndex] = 0;
                fileoperation[tempIndex] = 'r';
            }
            if (p >= exprStack + 100)
                return NULL;
            p->nalt = numberOfAlts;
            p->natom = numberOfAtoms;
            p++;
            numberOfAlts = 0;
            numberOfAtoms = 0;
        } else if (*regexp == ')') {
            if (p == exprStack || numberOfAtoms == 0)
                return NULL;
            if (numberOfAtoms == 0)
                return NULL;
            while (--numberOfAtoms > 0)
                *end_ptr++ = '.';
            for (int k = 0; numberOfAlts > 0; numberOfAlts--)
                *end_ptr++ = '|';
            --p;
            numberOfAtoms = p->natom;
            numberOfAlts = p->nalt;
            numberOfAtoms += 1;
        } else if (*regexp == '+' || *regexp == '*') {
            if (numberOfAtoms == 0)
                return NULL;
            *end_ptr++ = *regexp;
            printCval(fileoperation, tempIndex);
        } else {
            if (numberOfAtoms > 1) {
                --numberOfAtoms;
                *end_ptr++ = '.';
            }
            *end_ptr++ = *regexp;
            numberOfAtoms += 1;
        }

    }

    // If the expression stack is not empty, return NULL
    if (p != exprStack)
        return NULL;

    // while there are atoms, add a dot
    while (--numberOfAtoms > 0)
        * end_ptr++ = '.';

    // while there are alternations, add a pipe
    for ( int k = 0 ; numberOfAlts > 0; numberOfAlts--, k++)
        *end_ptr++ = '|';

    // Add a null terminator
    * end_ptr = 0;
#undef MAX


    return buf;
}

// Match indicates that the state matches the string. Branch indicates that the createState branches to two other states.
// Match and Branch are the only special characters in the NFA.
enum {
    Match = numm,
    Branch = nums
};

// Struct to represent a state in the NFA
typedef struct State State;
typedef struct State {
    long int specialChar;
    State * branchState;
    State * nextState;
    long int lastlist;
} State;

// The state machine is represented by a list of states. The list is terminated by a createState with specialChar == Match.
State matchstate = {Match };
char* fileop[100];
int numberOfStates;

void addToOutput(char*string, int character, int index) {
    string[index] = character;
}



// Create a state with the given specialChar, next and branch states.
State * createState(int character, State * nState, State * bState) {
    numberOfStates+=1;
    State * s;
    s = malloc(sizeof * s);
    s -> nextState = nState;
    s -> lastlist = 0;
    s -> branchState = bState;
    s -> specialChar = character;
    return s;
}



// Union to represent a list of pointers to states. The list is terminated by a NULL pointer.
typedef union listOfPointer listOfPointer;

typedef union listOfPointer {
    listOfPointer * next;
    State * s;
} listOfPointer;

// Struct to represent a fragment of a string. A fragment is a list of states that can be reached from a single state.
typedef struct fragmentOfString {
    State * start;
    listOfPointer * out;
    long int sizeOfFragment;

} fragmentOfString;

fragmentOfString * fragmentStack[100] = { NULL };

// Create a fragment of a string with the given start state and list of pointers to states.
fragmentOfString getFragment(State * start, listOfPointer * out, int position) {
    fragmentOfString n;
    position++;
    n.start = start;
    n.out = out;
    return n;
}


// Create a list of pointers to states with the given state.
listOfPointer * list1(State ** pState) {
    listOfPointer * pListOfPointer = (listOfPointer * ) pState;
    pListOfPointer -> next = NULL;
    return pListOfPointer;
}


// Replace the list of pointers to states with the given state.
int replacePointer(listOfPointer * ptrlist, State * s, int num) {
    listOfPointer * next;
    for (int k = 0; ptrlist; ptrlist = next,k++) {
        next = ptrlist -> next;
        ptrlist -> s = s;
        num++;
    }
    return num;
}


// Append the second list of pointers to states to the first list of pointers to states.
listOfPointer * append(listOfPointer * l1, listOfPointer * l2, int num) {
    listOfPointer * oldl1 = l1;
    listOfPointer * old2;
    while (l1 -> next){

        l1 = l1 -> next;
        old2 = l1;
    }

    fileOp = "File_Write";
    l1 -> next = l2;
    return oldl1;
}
State* tempState;
listOfPointer *tempListOfPointer;

// Convert the postfix regular expression to an NFA.
State * postfixToNFA(char * postfix, double *temparr, char *fileoperation) {
    char * p, * q;
    fragmentOfString stack[1000], * stackp, e1, e2, e;
    State * s;
    if (postfix == NULL)
        return NULL;
    long int numOfValidNodes = 0;
    //Temporary fragment
    fragmentOfString tempFrag = {tempState, tempListOfPointer,numOfValidNodes };
    int numOfReplace = 0;
    // Define the push and pop macros
#define push(s) * stackp++ = s
#define pop() * --stackp
    // Initialize the stack pointer
    stackp = stack;
    // Loop through the postfix regular expression
    for (p = postfix;* p; p++) {
        switch ( * p) {
            case '.':

                e2 = pop();
                e1 = pop();

                tempFrag.sizeOfFragment+=2;
                replacePointer(e1.out, e2.start, numOfReplace);
                push(getFragment(e1.start, e2.out, numOfReplace));
                break;
            default:
                s = createState( * p, NULL, NULL);
                tempFrag.sizeOfFragment++;
                push(getFragment(s, list1(&s->nextState), numOfReplace));
                break;
            case '*':
                e = pop();
                s = createState(Branch, e.start, NULL);
                tempFrag.sizeOfFragment+=2;
                replacePointer(e.out, s, numOfReplace);
                push(getFragment(s, list1(&s->branchState), numOfReplace));
                break;

            case '|':
                e2 = pop();
                e1 = pop();
                tempFrag.sizeOfFragment+=2;
                s = createState(Branch, e1.start, e2.start);
                push(getFragment(s, append(e1.out, e2.out, numOfReplace), numOfReplace));
                break;

            case '+':
                e = pop();
                s = createState(Branch, e.start, NULL);
                tempFrag.sizeOfFragment+=2;
                replacePointer(e.out, s, numOfReplace);
                push(getFragment(e.start, list1(&s->branchState), numOfReplace));
                break;
        }
    }

    e = pop();
    if (stackp != stack)
        return NULL;
    // Add a match state to the end of the NFA
    replacePointer(e.out, &matchstate, numOfReplace);
    return e.start;
#undef pop
#undef push
}

// adjacency list representation of an NFA
typedef struct List List;
struct List {
    State ** s;
    int n;
};


// Variables and functions used to keep track of the list of states that can be reached from a single state.
List l1, l2;
static int listid;
static int stateCount = 0;

char traverseList(List *clist, int c, List *nlist, char t);
//int addstate(List * , State * );
// Add the given state to the given list of states.
int addstate(List * l, State * s, int stateCount) {
    if (s == NULL)
        return 0;
    if(s -> lastlist == listid)
        return 0;
    s -> lastlist = listid;
    stateCount++;
    if (s -> specialChar == Branch) {
        addstate(l, s -> nextState, stateCount);
        addstate(l, s -> branchState, stateCount);
        return 1;
    }
    l -> s[l -> n++] = s;

    return 1;

}
// Add state to start of list
List * startlist(State * start, List * l) {
    l -> n = 0;
    listid++;
    addstate(l, start, stateCount);
    return l;
}

// Check if the given list of states contains the match state
int ismatch(List * l) {
    int i;
    long int num = l->n;
    for (i = 0; i < num; i++)
        if (l -> s[i] == & matchstate) {
            return 1;
        }
    return 0;
}



int charToInt(char *s){
    return *s & 0xFF;
}
// traverse NFA from state list after consuming character c
char traverseList(List * clist, int c, List * nlist, char pos) {
    int i;
    State * s;
    listid+=1;
    nlist -> n = 0;
    for (i = 0; i < clist -> n; i++) {
        pos = 't';
        s = clist -> s[i];
        if (s -> specialChar == c) {
            addstate(nlist, s -> nextState, stateCount);
            pos ='f';
            addToOutput((char*)fileop, s->specialChar, i);
        }
    }
    return pos;

}

void swapList(List ** l1, List ** l2) {
    List * t;
    t = * l1;
    * l1 = * l2;
    * l2 = t;
}
// Run NFA to determine whether it matches s
int match(State * start, char * s, int n) {
    int c;
    List * clist, * nlist, * t;

    clist = startlist(start, & l1);
    nlist = & l2;
    int k = n;
    for (int k = 0;* s; s++) {
        // Convert the character to an integer
        c = charToInt(s);
        // Traverse the NFA
        traverseList(clist, c, nlist, 'f');
        k+=1;
        swapList(&clist, &nlist);
    }
    return ismatch(clist);
}

// Temporary Variables
int temp1, temp2;


#define false 0
#define true 1
int regex_match(char * regex, char * string) {
   char * postFixExp = regexToPostfix(regex, temparr1, fileoperation1);
   State * start = postfixToNFA(postFixExp, temparr1, fileoperation1);
    l1.s = malloc(numberOfStates * sizeof l1.s[0]);
    l2.s = malloc(numberOfStates * sizeof l2.s[0]);
    int result = match(start, string, strlen(string));
    free(l1.s);
    free(l2.s);

    return result;

}

char* printOutput2(char ** regex_list, char * input_string, int regex_count) {
  const int n = strlen(input_string);
  char *outputString = (char *) malloc(sizeof(char) * 9000);
  int output_index = 0;

  while(*input_string != '\0'){
      int outer_break_flag = false;
      int regex_indices[regex_count];

      for(int i = 0; i < regex_count; i++){
          int break_flag = false;
          char * regex = regex_list[i];
          char match_list[n][n];
          int match_count = 0;

          for(int j = 0; j < n; j++){
              char substring[n];
              strncpy(substring, input_string, j);
                substring[j] = '\0';
                
                if(regex_match(regex, substring)) {
                    strncpy(match_list[match_count], substring, n);
                    match_count++;
                    break_flag = true;
                }
          }
          if(match_count != 0 && match_list[match_count - 1][0] == '\0'){
              break_flag = false;
          }
          if(break_flag){
              outer_break_flag = true;
             int position = strlen(match_list[match_count - 1]);
             regex_indices[i] = position;
          } else {
              regex_indices[i] = 0;
          }
      }
      if(outer_break_flag){
          int max_length_substring_matched = 0;
            for(int i = 0; i < regex_count; i++){
                if(regex_indices[i] > max_length_substring_matched){
                    max_length_substring_matched = regex_indices[i];
                }
            }

            for(int i = 0; i < regex_count; i++){
                if(regex_indices[i] == max_length_substring_matched){
                    outputString[output_index++] = '$';
                    outputString[output_index++] = i + '1';
                    input_string += max_length_substring_matched;
                    break;
                }
            }
      } else{
          outputString[output_index++] = '@';
          outputString[output_index++] = *input_string;
          input_string++;
      }

  }

    outputString[output_index++] = '#';
    outputString[output_index] = '\0';
    return outputString;

}


#undef false
#undef true




int main(int argc, char ** argv) {
    int numOfRegex;

// Read first line of input.txt
    FILE * fp = fopen("input.txt", "r");
    char* number_of_regex = (char *) malloc(sizeof(char) * 1000);
    fscanf(fp, "%s", number_of_regex);
    numOfRegex = atoi(number_of_regex);
    free(number_of_regex);
    //Create an array of strings to store regexes
    char * regexes[numOfRegex];
    for (int i = 0; i < numOfRegex; i++) {
        regexes[i] = (char *) malloc(sizeof(char) * 1000);
        fscanf(fp, "%s", regexes[i]);

    }
// Read the input string
    char * inputString = (char *) malloc(sizeof(char) * 1000);
    fscanf(fp, "%s", inputString);
    fclose(fp);
    FILE *fp2 = fopen("output.txt", "w");
    fprintf(fp2, "%s", printOutput2(regexes, inputString, numOfRegex));
    fclose(fp2);

    return 0;

}