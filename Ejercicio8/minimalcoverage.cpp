#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct par
{
    int empezar, terminar;
    
    bool operator<(const par & otro) const
    {
        return empezar < otro.empezar;
    }
};

par todaspares[100005];
par solution[100005];

int main()
{
    string sep = "";
    int T, M;
    
    cin >> T;
    
    while (T--)
    {
        cout << sep;
        sep = "\n";
        cin >> M;
        
        int numpars = 0;
        while (cin >> todaspares[numpars].empezar >> todaspares[numpars].terminar,
            todaspares[numpars].empezar || todaspares[numpars].terminar)
        {
            if (todaspares[numpars].terminar > 0 && todaspares[numpars].empezar < M)
                ++numpars;
        }
        
        sort(todaspares, todaspares + numpars);
        
        todaspares[numpars].empezar = M + 1;
        
        int cont = 0;
        int izq = 0;
        int der = 0;
        
        while (izq < M && der < numpars)
        {
            solution[cont].terminar = 0;
            for (; todaspares[der].empezar <= izq; ++der)
                if (todaspares[der].terminar > solution[cont].terminar)
                    solution[cont] = todaspares[der];
            
            if (solution[cont].terminar == izq)
            {
                break;
            }
            izq = solution[cont].terminar;
            ++cont;
        }
        
        if (izq >= M)
        {
            cout << cont << '\n';
            
            for (int i = 0; i < cont; ++i)
            {
                cout << solution[i].empezar << ' ' << solution[i].terminar << '\n';
            }
        }
        else
            cout << "0\n";
    }
}
