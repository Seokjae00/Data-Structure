#include <string>
#include <iostream>
#include <list>
#include <map>

using namespace std;

struct Tman
{
    string name;
    Tman* f;

    list<Tman*> s;
    Tman() { f = NULL; }
};

map<string, Tman*> hash;

Tman* root;

void print(long dep, Tman* now)
{
    if (now == NULL)
        return;

    for (long i = 1; i <= dep; ++i)
        cout << '+';
    cout << now->name << endl;

    for (list<Tman*>::iterator j = now->s.begin(); j != now->s.end(); ++j)
        print(dep + 1, *j);
}

void hires(string n1, string n2)
{
    Tman* f = hash[n1];

    Tman* s = new Tman();

    s->name = n2;
    s->f = f;
    f->s.push_back(s);
    hash[n2] = s;
}

void fire(string n1)
{
    Tman* s = hash[n1];

    Tman* f = s->f;
    hash.erase(n1);
    while (s->s.size() != 0)
    {
        s->name = s->s.front()->name;
        hash[s->name] = s;
        s = s->s.front();
    }

    s->f->s.remove(s);
    delete s;
}

int main()
{
    string s1, s2;
    long i;
    cin >> s1;
    root = new Tman();
    hash[s1] = root;

    root->name = s1;
    while (cin >> s1)
    {
        if (s1 == "print")
        {
            cout << endl;
            print(0, root);
            for (i = 1; i <= 60; ++i) cout << '-';
            cout << endl;
        }
        else if (s1 == "fire")
        {
            cin >> s2;
            fire(s2);
        }
        else
        {
            cin >> s2;
            cin >> s2;
            hires(s1, s2);
        }
    }

    return 0;
}