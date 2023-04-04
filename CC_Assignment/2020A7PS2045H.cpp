#include <bits/stdc++.h>
#include <string>

using namespace std;

int x = 1;
int y = 2;
float z = 3;

string reTOps(string regular)
{

    int noOFdusra;
    int noOFelements;

    static char buf[8000];
    char *antim_pointer;

    struct
    {
        int dusri;
        int ele;
    } expressionstc[100], *p;

    p = expressionstc;

    antim_pointer = buf;

    noOFdusra = 0;
    noOFelements = 0;

    if (regular.size() >= sizeof buf / 2)
        return NULL;

    for (auto it = regular.begin(); it != regular.end(); it++)
    {
        switch (*it)
        {
        case '(':
            if (noOFelements > 1)
            {
                --noOFelements;
                *antim_pointer++ = '.';
            }
            if (p >= expressionstc + 100)
                return NULL;
            p->dusri = noOFdusra;
            p->ele = noOFelements;
            p++;
            noOFdusra = 0;
            noOFelements = 0;
            break;
        case '|':
            if (noOFelements == 0)
                return NULL;
            while (--noOFelements > 0)
                *antim_pointer++ = '.';
            noOFdusra++;
            break;
        case ')':
            if (p == expressionstc)
                return NULL;
            if (noOFelements == 0)
                return NULL;
            while (--noOFelements > 0)
                *antim_pointer++ = '.';
            for (; noOFdusra > 0; noOFdusra--)
                *antim_pointer++ = '|';
            --p;
            noOFdusra = p->dusri;
            noOFelements = p->ele;
            noOFelements++;
            break;
        case '*':
        case '+':
        case '?':
            if (noOFelements == 0)
                return NULL;
            *antim_pointer++ = *it;
            break;
        default:
            if (noOFelements > 1)
            {
                --noOFelements;
                *antim_pointer++ = '.';
            }
            *antim_pointer++ = *it;
            noOFelements++;
            break;
        }
    }

    if (p != expressionstc)
        return NULL;

    while (--noOFelements > 0)
        *antim_pointer++ = '.';
    for (; noOFdusra > 0; noOFdusra--)
        *antim_pointer++ = '|';
    *antim_pointer = 0;
    return buf;
}

enum
{
    Match = 256,
    Branch = 257
};

typedef struct State State;
struct State
{
    int badhiyach;
    State *aglastate;
    State *dandist;
    int antimsuchi;
};

State milgyast = {Match};

int noOFsthan;

State *createState(int kiridar, State *nst, State *bst)
{
    State *s;
    noOFsthan++;
    s = (State *)malloc(sizeof *s);
    s->antimsuchi = 0;
    s->badhiyach = kiridar;
    s->aglastate = nst;
    s->dandist = bst;
    return s;
}

typedef struct Frag Frag;
typedef union Ptrlist Ptrlist;

struct Frag
{
    State *shurukro;
    Ptrlist *out;
};

Frag frag(State *shurukro, Ptrlist *out)
{
    Frag n = {shurukro, out};
    return n;
}

union Ptrlist
{
    Ptrlist *agla;
    State *s;
};

Ptrlist *list1(State **outp)
{
    Ptrlist *l;

    l = (Ptrlist *)outp;
    l->agla = NULL;
    return l;
}

void patch(Ptrlist *l, State *s)
{
    Ptrlist *agla;

    for (; l; l = agla)
    {
        agla = l->agla;
        l->s = s;
    }
}

Ptrlist *append(Ptrlist *l1, Ptrlist *l2)
{
    Ptrlist *oldl1;

    oldl1 = l1;
    while (l1->agla)
        l1 = l1->agla;
    l1->agla = l2;
    return oldl1;
}

State *pt2nf(string ptfx)
{
    Frag stack[1000], *stp, e1, e2, e;
    State *s;

    if (ptfx.empty())
        return NULL;

#define push(s) *stp++ = s
#define pop() *--stp

    stp = stack;
    for (auto it = ptfx.begin(); it != ptfx.end(); it++)
    {
        switch (*it)
        {
        default:
            s = createState(*it, NULL, NULL);
            push(frag(s, list1(&s->aglastate)));
            break;
        case '.':
            e2 = pop();
            e1 = pop();
            patch(e1.out, e2.shurukro);
            push(frag(e1.shurukro, e2.out));
            break;
        case '|':
            e2 = pop();
            e1 = pop();
            s = createState(Branch, e1.shurukro, e2.shurukro);
            push(frag(s, append(e1.out, e2.out)));
            break;
        case '?':
            e = pop();
            s = createState(Branch, e.shurukro, NULL);
            push(frag(s, append(e.out, list1(&s->dandist))));
            break;
        case '*':
            e = pop();
            s = createState(Branch, e.shurukro, NULL);
            patch(e.out, s);
            push(frag(s, list1(&s->dandist)));
            break;
        case '+':
            e = pop();
            s = createState(Branch, e.shurukro, NULL);
            patch(e.out, s);
            push(frag(e.shurukro, list1(&s->dandist)));
            break;
        }
    }

    e = pop();
    if (stp != stack)
        return NULL;

    patch(e.out, &milgyast);
    return e.shurukro;
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
static int listkanaam;

void statebadao(List *, State *);
void chado(List *, int, List *);

List *
shurukrolist(State *shurukro, List *l)
{
    l->n = 0;
    listkanaam++;
    statebadao(l, shurukro);
    return l;
}

int ismatch(List *l)
{
    int i;
    for (i = 0; i < l->n; i++)

        if (l->s[i] == &milgyast)
        {
            return 1;
        }
    return 0;
}

void statebadao(List *l, State *s)
{
    if (s == NULL || s->antimsuchi == listkanaam)
        return;
    s->antimsuchi = listkanaam;
    if (s->badhiyach == Branch)
    {
        statebadao(l, s->aglastate);
        statebadao(l, s->dandist);
        return;
    }
    l->s[l->n++] = s;
}

void chado(List *dl, int c, List *gl)
{
    int i;
    State *s;

    listkanaam++;
    gl->n = 0;

    for (i = 0; i < dl->n; i++)
    {

        s = dl->s[i];
        if (s->badhiyach == c)
        {
            statebadao(gl, s->aglastate);
        }
    }
}

int match(State *shurukro, string s)
{
    int i, c;
    List *dl, *gl, *t;

    dl = shurukrolist(shurukro, &l1);
    gl = &l2;
    for (auto it = s.begin(); it != s.end(); it++)
    {

        c = *it & 0xFF;

        chado(dl, c, gl);
        t = dl;
        dl = gl;
        gl = t;
    }
    return ismatch(dl);
}

string dhundhosahitoken(State *shurukro, string w)
{

    string uttar = "";
    while (w.length() > 0)
    {
        bool milgye = false;
        for (int i = w.length(); i >= 0; i--)
        {
            string sub = w.substr(0, i);
            if (match(shurukro, sub))
            {
                uttar += '$';
                uttar.append(sub);
                w = w.substr(i, w.length() - i);
                milgye = true;
                break;
            }
        }
        if (!milgye)
        {
            uttar += '@';
            uttar += w[0];
            w = w.substr(1, w.length() - 1);
        }
    }
    uttar += '#';
    return uttar;
}
int regex_match(string inputString,string rg)
{
     string ptfxExpression;
    State *shurukro;
    if (rg.empty())
    {
        cout << "no regular\n";
        return 1;
    }

    ptfxExpression = reTOps(rg);

    if (ptfxExpression.empty())
    {
        cout << "bad regular " << rg << endl;
        return 1;
    }

    shurukro = pt2nf(ptfxExpression);

    if (shurukro == NULL)
    {
        cout << "error in pt2nf " << ptfxExpression << endl;
        return 1;
    }

    l1.s = (State **)malloc(noOFsthan * sizeof l1.s[0]);
    l2.s = (State **)malloc(noOFsthan * sizeof l2.s[0]);

    int res = match(shurukro,inputString);
    free(l1.s);
    free(l2.s);
    return res;

}
string uttarprapt(int regex_count,string input_string,vector<string> regex_list) {
    int tmp2 = 1;
    string uttarstring;
    int tmp1 = 0;
    tmp2 = tmp1;
    int numb = input_string.size();
    tmp2++;

    while (input_string.size()!=0) {
        vector<int> regex_indices(regex_count);

        int outer_break_flag = 0;

        for (int i = 0; i < regex_count; i++) 
        {
            int tmp_int =0;
            
            string regex = regex_list[i];
            tmp_int = 2;
            bool break_flag;
            if(tmp_int)break_flag = false;
            tmp_int =3;
            int match_count = 0;

            vector<string> match_list;
            for (int j = 0; j < numb; j++) {
                string substring = input_string.substr(0, j + 1);
                int tmp_int3 = 0;
                tmp_int3++;
                if (regex_match(substring, regex)) {
                    match_list.push_back(substring);
                    match_count++;
                    break_flag = true;
                }
            }

            if (match_count != 0 && match_list.back().empty()) {
                break_flag = false;
            }

            if (break_flag) {
                outer_break_flag = true;
                int position = match_list.back().length();
                regex_indices[i] = position;
            } else {
                regex_indices[i] = 0;
            }
        }

        if (outer_break_flag) {
            int max_length_substring_matched = 0;

            for (int i = 0; i < regex_count; i++) {
                if (regex_indices[i] > max_length_substring_matched) {
                    max_length_substring_matched = regex_indices[i];
                }
            }

            for (int i = 0; i < regex_count; i++) {
                if (regex_indices[i] == max_length_substring_matched) {
                    uttarstring.push_back('$');
                    uttarstring.push_back(i + '1');
                    input_string = input_string.substr(max_length_substring_matched);
                    break;
                }
            }
        } else {
            uttarstring.push_back('@');
            uttarstring.push_back(input_string.front());
            input_string = input_string.substr(1);
        }
    }

    uttarstring.push_back('#');
    return uttarstring;
}

// int main() {
//     ifstream in("./input.txt");
//     string regex_cnt;
//     int regex_cnt_int;
//     getline(in, regex_cnt);
//     regex_cnt_int  = stoi(regex_cnt);
//     vector<string> regex_list;
//     string InputString;
//     for(int i=0;i<regex_cnt_int;i++)
//     {
//         string regex;
//         getline(in,regex);
//         regex_list.push_back(regex);
//     }
//     getline(in, InputString);
//     string ans = printResult(regex_cnt_int,InputString,regex_list);
//     ofstream out("output.txt");
//     out << ans;
//     return 0;
// }

int main()
{
    ifstream inp("./input.txt");
    string regex_gnti;
    getline(inp, regex_gnti);
    int regex_cntshankhya;
    vector<string> regex_list;
    string InputString;
    regex_cntshankhya  = stoi(regex_gnti);
    
    for(int i=0;i<regex_cntshankhya ;i++)
    {
        string regex;
        getline(inp,regex);
        regex_list.push_back(regex);
    }

    State *tmp_state = NULL;
    State *tmp2 = tmp_state;
    int tmp_in1 = 0;
    tmp_in1++;

    if(tmp_in1)getline(inp, InputString);

    

    string uttar = uttarprapt(regex_cntshankhya,InputString,regex_list);

    // cout << uttar << endl;
    ofstream out("output.txt");
    out << uttar;
    return 0;
}
