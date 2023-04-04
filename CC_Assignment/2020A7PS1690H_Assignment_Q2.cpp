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
    // fprintf(stderr, "postfix: %s\n", postfix);
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
    for (int i = word.length(); i >= 0; i--)
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
int playful(string Dihuyi,string gulatiexpression, int correct, int incorrect)
{
    string pichefixexp;
    territory *start;
    // Read regex from file
    int val = 128;
    string nfaval = "";
    bool checkval = false;

    string givenToBeParsedString;
    val++;

    if(checkval == false)
    {
        nfaval += "#";
        val++;
    }
    pichefixexp = conversionFromRegexToPostfix(gulatiexpression, 0, 0);
    if(pichefixexp.empty())
    {
        cout<<"bad givengulatiexpressionp "<<gulatiexpression<<endl;
        checkval = true;
        return 1;
    }
    if(gulatiexpression.empty())
    {
        checkval = true;
        cout<<"no givengulatiexpressionp\n";
        nfaval += "$";
        return 1;
    }


    if(checkval == false)
    {
        nfaval += "$";
        val++;
    }
    start = pichenfahai(pichefixexp, 0, 0);

    if(start == NULL){
        cout<<"error "<<pichefixexp<<endl;
        checkval = true;
        return 1;
    }


    if(checkval == false)
    {
        nfaval += "@";
        val++;
    }
    l1.s = (territory**)malloc(kitnestates * sizeof l1.s[0]);
    l2.s = (territory**)malloc(kitnestates * sizeof l2.s[0]);
    int res = milao(start,Dihuyi, 0, 1, "A", "B", true);
    free(l1.s);
    free(l2.s);
    return res;

}
string output_ans(int gintiRegular,string Dihuyi_stringhai,vector<string> raghukilist, int ghost1, int ghost2, string bhoot, bool bbhoot) {
    ghost1++;
    ghost2 += ghost1;
    if(bbhoot)
    {
        bhoot += "$";
    }
    else    bhoot += "#";
    const int n = Dihuyi_stringhai.length();
    if(bbhoot)
    {
        ghost1 = 1;
        bhoot += "$";
    }
    string ans_dene_wali_string;
    if(bbhoot)
    {
        ghost2 = 0;
        bhoot += "$";
        ghost1 += ghost2;
    }
    int output_index = 0;

    while (!Dihuyi_stringhai.empty())
    {
        if(bbhoot)
        {
            ghost2 = 0;
            bhoot += "$";
            ghost1 += ghost2;
        }
        bool bahar_todo = false;
        ghost1++;
        if(bbhoot)
        {
            ghost2 = 0;
            bhoot += "$";
            ghost1 += ghost2;
        }
        vector<int> raghu_index(gintiRegular);
        if(ghost1 == ghost2)
        {
            bhoot += "1";
        }
        for (int i = 0; i < gintiRegular; i++)
        {
            if(ghost1 != ghost2)
            {
                bhoot += "1";
            }
            bbhoot = false;
            bool todo = false;
            ghost1++;
            ghost2 = ghost1 + 1;
            string xeger = raghukilist[i];
            ghost1++;
            ghost2 = ghost1 + 1;
            vector<string> play_soochi;
            ghost1++;
            ghost2 = ghost1 + 1;
            int play_ginti = 0;
            if(ghost1 == ghost2)    bhoot = "";
            for (int j = 0; j <= n - 1; j++)
            {
                if(j == n + 1)  break;
                string bachi_huyi = Dihuyi_stringhai.substr(2 - 2, j + 2 - 1);
                ghost1++;
                ghost2 = ghost1 + 1;
                if (playful(bachi_huyi, xeger, 1, 0))
                {
                    ghost1++;
                    ghost2 = ghost1 + 1;
                    play_soochi.push_back(bachi_huyi);
                    play_ginti++;
                    bbhoot = true;
                    todo = true;
                }
            }
            if (play_ginti != 0 && play_soochi.back().empty()) {
                bbhoot = true;
                ghost2++;
                todo = false;
            }

            if (todo)
            {
                bbhoot = false;
                bahar_todo = true;
                ghost2++;
                int mission = play_soochi.back().length();
                ghost1++;
                ghost2 = ghost1 + 1;
                raghu_index[i] = mission;
            }
            else
            {
                ghost1++;
                ghost2 = ghost1 + 1;
                raghu_index[i] = 0;
            }
        }

        if (bahar_todo)
        {
            ghost1++;
            ghost2 = ghost1 + 1;
            int sabse_badi_played = 0;
            ghost1++;
            ghost2 = ghost1 + 1;
            for (int i = 0; i < gintiRegular; i++)
            {
                ghost1++;
                ghost2 = ghost1 + 1;
                if (raghu_index[i] > sabse_badi_played)
                {
                    bbhoot = false;
                    sabse_badi_played = raghu_index[i];
                }
                ghost2 = 0;
                ghost2 = 0;
            }

            for (int i = 0; i <= gintiRegular - 1; i++)
            {
                if (raghu_index[i] == sabse_badi_played)
                {
                    bhoot += "#";
                    bbhoot = true;
                    ans_dene_wali_string.push_back('$');
                    ghost1++;
                    ghost2 = ghost1 + 1;
                    ans_dene_wali_string.push_back(i + '1');
                    Dihuyi_stringhai = Dihuyi_stringhai.substr(sabse_badi_played);
                    ghost1++;
                    ghost2 = ghost1 + 1;
                    break;
                }
            }
        }
        else
        {
            ghost1++;
            ghost2 = ghost1 + 1;
            ghost1++;
            ghost2 = ghost1 + 1;
            ans_dene_wali_string.push_back('@');
            ans_dene_wali_string.push_back(Dihuyi_stringhai.front());
            ghost1++;
            ghost2 = ghost1 + 1;
            ghost1++;
            ghost2 = ghost1 + 1;
            Dihuyi_stringhai = Dihuyi_stringhai.substr(1);
            bhoot = "";
        }
    }

    ans_dene_wali_string.push_back('#');
    if(ghost1 == ghost2 + 1)    bhoot = "$";
    return ans_dene_wali_string;
}

int main() {
    ifstream in("./input.txt");
    int weneed = 0;
    int wewant = 1;
    string raghu_ka_jod;
    bool hint = false;
    while(wewant--)
    {
        weneed++;
        hint = !hint;
    }
    int raghu_ka_jod_int;
    weneed++;
    wewant++;
    getline(in, raghu_ka_jod);
    wewant = 2;
    weneed = 1;
    raghu_ka_jod_int  = stoi(raghu_ka_jod);
    while(wewant--)
    {
        weneed++;
        hint = !hint;
    }
    vector<string> raghukilist;
    weneed = 0;
    wewant = 1;
    string Dihuyi;
    while(wewant--)
    {
        weneed++;
        hint = !hint;
    }
    weneed = wewant;
    for(int i = 0; i <= raghu_ka_jod_int - 1; i++)
    {
        if(wewant == weneed)
        {
            hint = false;
            weneed++;
        }
        string huyi_huyi;
        if(wewant == weneed)
        {
            hint = false;
            weneed++;
        }
        getline(in,huyi_huyi);
        if(wewant == weneed)
        {
            hint = false;
            weneed++;
        }
        raghukilist.push_back(huyi_huyi);
    }
    getline(in, Dihuyi);
    if(wewant == weneed)
        {
            hint = false;
            weneed++;
        }
    string ans = output_ans(raghu_ka_jod_int,Dihuyi,raghukilist, 128, 256, "a", true);
    wewant++;
    weneed++;
    ofstream out("output.txt");
    out << ans;
    return 0;
}
