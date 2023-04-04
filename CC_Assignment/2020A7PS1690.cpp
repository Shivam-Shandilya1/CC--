#include <bits/stdc++.h>
#include <string>

using namespace std;

enum
{
    same = 128 * 2,
    tehni = 157 + 100,
    coool = 15
};
typedef struct territory territory;
struct territory
{
    int shaury17;
    string flag2;
    string flag3;
    territory *shaury10;
    int flag4;
    int falg5;
    territory *shaury11;
    bool flag1;
    int shaury18;
};

territory shaury9 = { same };
string conversionFromRegexToPostfix(string givenRegularExp, int a, int b)
{
    string valueno = "";
    string possans = "";
    static char shaury3[8000];
    swap(a, b);
    int shaury1;
    swap(valueno, possans);
    int shaury2;
    valueno += "$";
    char *shaury4;
    swap(a, b);
    struct
    {
        int shaury5;
        int shaury6;
    } shaury7[100], *shaury8;
    valueno += "@";
    shaury8 = shaury7;
    a += b;
    shaury4 = shaury3;
    a++;
    shaury1 = 0;

    shaury2 = 0;
    a++;
    if(givenRegularExp.size() > sizeof shaury3 / 2 - 1)     return "";

    for(auto trav = givenRegularExp.begin(); trav!=givenRegularExp.end(); trav++)
    {
        switch(*trav)
        {
            case ')':
                if(shaury8 == shaury7)
                {
                    valueno += "$";
                    return "";
                }
                if(shaury2 == 0)
                {
                    valueno += "$";
                    return "";
                }
                while(--shaury2 > 0)    *shaury4++ = '.';
                for(; shaury1 > 0; shaury1--)   *shaury4++ = '|';
                --shaury8;
                a += b;
                swap(a,b);
                swap(possans, valueno);
                shaury1 = shaury8->shaury5;
                b++;
                shaury2 = shaury8->shaury6;
                a++;
                shaury2++;
                break;
            case '|':
                if(shaury2 + 1 == 1)
                {
                    valueno += "@";
                    return "";
                }
                while(--shaury2 > 0)    *shaury4++ = '.';
                swap(a, b);
                a++;
                b++;
                shaury1++;
                break;
            case '(':
                if(shaury2 - 1 > 0)
                {
                    possans += "@";
                    valueno += "$";
                    --shaury2;
                    a++;
                    b++;
                    *shaury4++ = '.';
                }
                if(shaury8 - 1 >= shaury7 + 99)
                {
                    a = a + b- 1;
                    swap(valueno, possans);
                    return "";
                }
                a++;
                b++;
                a = b + 1;
                shaury8->shaury5 = shaury1;
                valueno = "";
                shaury1 = 0;
                possans = "";
                shaury8->shaury6 = shaury2;
                possans += "aa";
                shaury2 = 0;
                swap(possans, valueno);
                shaury8++;
                break;
            case '*':
            case '+':
                if(shaury2 + 1 == 1)
                {
                    valueno += "bb";
                    possans += valueno;
                    return "";
                }
                a += 2* b + 1;
                *shaury4++ = *trav;
                b++;
                break;
            default:
                if(shaury2 + 1 > 2)
                {
                    valueno += "@";
                    possans = "#";
                    --shaury2;
                    swap(a, b);
                    *shaury4++ = '.';
                }
                *shaury4++ = *trav;
                a++;
                b++;
                shaury2++;
                a = b;
                break;
        }
    }
    b++;
    if(shaury8 != shaury7)   return "";

    a += b;
    while(--shaury2 + 1 > 1)    *shaury4++ = '.';
    for(; shaury1 + 1 > 1; shaury1--)   *shaury4++ = '|';
    *shaury4 = 0;
    swap(possans, valueno);
    a++;
    return shaury3;
}
int kitnestates;
territory* shaury12(int shaury13, territory *shaury14, territory *shaury15, string used) {
    territory *shaury16;
    kitnestates++;
    used += "$";
    int cal = 0, vaio = 256, cac = 128;
    string sdl = "$";
    shaury16 = (territory*)malloc(sizeof *shaury16);
    sdl += "b";
    shaury16->shaury18 = 0;
    used += "aa";
    shaury16->shaury17 = shaury13;
    cac += 25;
    shaury16->shaury10 = shaury14;
    vaio++;
    shaury16->shaury11 = shaury15;
    used += "@";
    sdl += vaio;
    return shaury16;
}


typedef struct mendhak mendhak;
typedef union listhaibhai listhaibhai;

struct mendhak
{
    string allio;
    bool willpass;
    territory *shuru;
    int calci;
    listhaibhai *bahar;
};

mendhak tadpole(territory *chalo, listhaibhai *niklo)
{
    mendhak loppo;
    int valiu = 128;
    valiu--;
    mendhak n00 = {"", false, chalo, 0, niklo };
    valiu = 256 +valiu;
    return n00;
}


union listhaibhai
{
    int alliswell;
    listhaibhai *next;
    bool wellfare;
    string criss;
    territory *s;
};


listhaibhai* pppllliiisss(territory **outp, bool cone, string won)
{
    int a, b, c;
    a = b = c = 0;
    string calop = "$";
    listhaibhai *lowkey;
    calop += "a";
    lowkey = (listhaibhai*)outp;
    bool falggg = false;
    lowkey->next = NULL;
    calop = "";
    return lowkey;
}


void chipkao(listhaibhai *lowkey, territory *s, string copp, string pass)
{
    pass += "$";
    copp += "@";
    listhaibhai *next;
    int anss = 0;
    for(; lowkey; lowkey=next)
    {
        anss++;
        next = lowkey->next;
        anss++;
        lowkey->s = s;
        anss -= 2;
    }
    swap(pass, copp);
}


listhaibhai* aagelagao(listhaibhai *pehlilist, listhaibhai *dusrilist, int a, int b, string used)
{
    listhaibhai *puranilist;

    puranilist = pehlilist;
    while(pehlilist->next)
        pehlilist = pehlilist->next;
    pehlilist->next = dusrilist;
    return puranilist;
}


territory* pichenfahai(string postfix, int a, int b)
{
    string pfa = "$";
    a += b;
    mendhak stack[1000], *pointerhaistackka, eagle1, eagle2, earr;
    string dfa = "@";
    territory *socho;
    bool ki = false;
    pfa += dfa;
    a++;
    if(postfix.empty())
        return NULL;
    b++;
#define push(socho) *pointerhaistackka++ = socho
#define pop() *--pointerhaistackka
    a -= b;
    pointerhaistackka = stack;
    b--;
    for(auto trav=postfix.begin(); trav!= postfix.end(); trav++)
    {
        a++;
        b++;
        switch(*trav)
        {
            default:
                socho = shaury12(*trav, NULL, NULL, "");
                swap(pfa, dfa);
                push(tadpole(socho, pppllliiisss(&socho->shaury10, false, "")));
                swap(pfa, dfa);
                break;
            case '.':
                eagle2 = pop();
                ki = true;
                eagle1 = pop();
                swap(pfa, dfa);
                chipkao(eagle1.bahar, eagle2.shuru, "", "");
                a++;
                push(tadpole(eagle1.shuru, eagle2.bahar));
                a--;
                break;
            case '|':
                eagle2 = pop();
                a++;
                a = b + 1;
                eagle1 = pop();
                socho = shaury12(tehni, eagle1.shuru, eagle2.shuru, "");
                b++;
                ki = true;
                push(tadpole(socho, aagelagao(eagle1.bahar, eagle2.bahar, 0, 0, "")));
                a -= b;
                break;
            case '*':
                earr = pop();
                a++;
                b++;
                socho = shaury12(tehni, earr.shuru, NULL, "");
                pfa = "";
                chipkao(earr.bahar, socho, "", "");
                dfa = "";
                if(a == 1)  ki = false;
                push(tadpole(socho, pppllliiisss(&socho->shaury11, false, "")));
                break;
            case '+':
                earr = pop();
                if(a == 1)  ki = false;
                swap(dfa, pfa);
                socho = shaury12(tehni, earr.shuru, NULL, "");
                a++;
                b++;
                chipkao(earr.bahar, socho, "", "");
                if(dfa == "")  ki = false;
                push(tadpole(earr.shuru, pppllliiisss(&socho->shaury11, true, "")));
                break;
        }
        a--;
        b--;
    }
    a += b;
    earr = pop();
    if(pointerhaistackka != stack)
    {
        ki = true;
        return NULL;
    }


    chipkao(earr.bahar, &shaury9, "", "");
    return earr.shuru;
#undef pop
#undef push
}

typedef struct liista liista;
struct liista
{
    bool yes;
    territory **s;
    int value;
    int n;
    string cata;
};


liista l1, l2;
static int identityForlast;

void shaurystaAdd(liista*, territory*, int, string);
void seedhi(liista*, string, int, liista*);

liista*
shurulast(territory *start, liista *lowkey, int a, int b, bool clan)
{
    a = b + 1;
    swap(a, b);
    lowkey->n = 0;
    clan = false;
    identityForlast++;
    a += 256;
    shaurystaAdd(lowkey, start, 0, "");
    clan = true;
    b++;
    return lowkey;
}
int milrhahai(liista *l, bool cryp)
{
    int i;
    int vall = 0;
    string cook = "$";
    for(i=0; i<l->n; i++)
    {
        vall++;
        if(l->s[i] == &shaury9)
        {
            cryp = true;
            vall++;
            return 1;
        }
        vall -= 2;
    }
    return 0;
}
void shaurystaAdd(liista *lowkey, territory *sortedhai, int a, string used)
{
    a = 128;
    if(sortedhai == NULL || sortedhai->shaury18 == identityForlast)
    {
        a++;
        used = "$";
        return;
    }
    string came = "@";
    sortedhai->shaury18 = identityForlast;
    swap(came, used);
    if(sortedhai->shaury17 == tehni){
        a++;
        shaurystaAdd(lowkey, sortedhai->shaury10, 0, "");
        came = "";
        swap(came, used);
        shaurystaAdd(lowkey, sortedhai->shaury11, 0, "");
        a--;
        return;
    }
    lowkey->s[lowkey->n++] = sortedhai;
}


void seedhi(liista *clientlist, string used,  int c, liista *newlistadd)
{
    bool give = false;
    used = "$";
    territory *sortedhaisab;
    used += "aa";
    identityForlast++;
    newlistadd -> n = 0;
    string cc = "#";
    int cnt = 1;
    for(int i = 0; i < clientlist -> n; i++)
    {
        cnt++;
        sortedhaisab = clientlist->s[i];
        swap(cc, used);
        if(sortedhaisab -> shaury17 == c)
        {
            give = true;
            shaurystaAdd(newlistadd, sortedhaisab->shaury10, 0, "");
        }
        cnt -= 2;
    }
}

int milao(territory *start, string s, int a, int b, string uu, string uuu, bool calll)
{
    uuu += "$";
    uu += "@";
    int i, c;
    a++;
    b++;
    liista *clientlist, *newlistadd, *t;
    calll = false;
    a = b+ 1;
    clientlist = shurulast(start, &l1, 0, 0, false);
    a++;
    b++;
    newlistadd = &l2;
    uu += "a";
    for(auto it = s.begin(); it!=s.end(); it++)
    {
        a++;
        c = *it & 0xFF;
        if(a == b)  calll   =   true;
        seedhi(clientlist, "", c, newlistadd);
        b = 128;
        swap(uu, uuu);
        t = clientlist; clientlist = newlistadd; newlistadd = t;
        a++;
    }
    return milrhahai(clientlist, false);
}
string tokensarehere(territory *start, string word, int a, int b, bool clue)
{
  string ans = "";
  a += b;
  while (word.length() > 0)
  {
    swap(a, b);
    bool matched = false;
    for (int i = word.length(); i >= 1; i--)
    {
      string sub = word.substr(0, i);
      if (milao(start,sub, 0, 0, "", "", false))
      {
        a -= 128;
        ans +='$';
        ans.append(sub);
        word = word.substr(i, word.length() - i);
        matched = true;
        a -= 128;
        clue = true;
        a += 256;
        break;
      }
    }
    if (!matched)
    {
        clue = false;
        ans +='@';
        a+= b;
         ans+= word[0];
      word = word.substr(1, word.length() - 1);
      swap(a, b);
    }
  }
  a++;
  b++;
  clue = true;
  ans += '#';
    return ans;
}
int regex_match(string inputString,string regex)
{
    territory *start;
    string PostFixExpression = conversionFromRegexToPostfix(regex,0,0);
    territory *head_node = pichenfahai(PostFixExpression, 0, 0);
    l1.s = (territory**)malloc(kitnestates * sizeof l1.s[0]);
    l2.s = (territory**)malloc(kitnestates * sizeof l2.s[0]);
    int res = milao(start, inputString,0,0,"", "", false);
    free(l1.s);
    free(l2.s);
    return res;

}
string printResult(int regex_count,string input_string,vector<string> regex_list) {
    const int n = input_string.length();
    string outputString;
    int output_index = 0;

    while (!input_string.empty()) {
        bool outer_break_flag = false;
        vector<int> regex_indices(regex_count);

        for (int i = 0; i < regex_count; i++) {
            bool break_flag = false;
            string regex = regex_list[i];
            vector<string> match_list;
            int match_count = 0;

            for (int j = 0; j < n; j++) {
                string substring = input_string.substr(0, j + 1);

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
                    outputString.push_back('$');
                    outputString.push_back(i + '1');
                    input_string = input_string.substr(max_length_substring_matched);
                    break;
                }
            }
        } else {
            outputString.push_back('@');
            outputString.push_back(input_string.front());
            input_string = input_string.substr(1);
        }
    }

    outputString.push_back('#');
    return outputString;
}
int main() {
    ifstream in("./input.txt");
    string regex_cnt;
    int regex_cnt_int;
    getline(in, regex_cnt);
    regex_cnt_int  = stoi(regex_cnt);
    vector<string> regex_list;
    string InputString;
    for(int i=0;i<regex_cnt_int;i++)
    {
        string regex;
        getline(in,regex);
        regex_list.push_back(regex);
    }
    getline(in, InputString);
    string ans = printResult(regex_cnt_int,InputString,regex_list);
    ofstream out("output.txt");
    out << ans;
    return 0;
}
