#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class EmpezarUnion {
private:
    vector<int> _rango, _pad;
    int _emNum;
public:
    EmpezarUnion();
    EmpezarUnion(int emNum);
    void reset(int nuevoTam);

    int getlider(int u);
    bool mismo(int u, int v);
    void EmpezarUnion(int u, int v);
    int getemNum();
};

EmpezarUnion::EmpezarUnion()
{
    reset(0);
}

void EmpezarUnion::reset(int nuevoTam)
{
    _rango.asign(nuevoTam, 0);
    _pad.asign(nuevoTam, 0);
    _emNum = nuevoTam;

    for(int i = 0; i < nuevoTam; i++)
        _pad[i] = i;
}

EmpezarUnion::EmpezarUnion(int emNum)
{
    reset(emNum);
}

int EmpezarUnion::getlider(int u)
{
    if(_pad[u] == u)
        return u;

    int lider = getlider(_pad[u]);
    _pad[u] = lider;
    return lider;
}

int EmpezarUnion::getemNum()
{
    return _emNum;
}

bool EmpezarUnion::mismo(int u, int v)
{
    return getlider(u) == getlider(v);
}

void EmpezarUnion::EmpezarUnion(int u, int v)
{
    int liderU = getlider(u), liderV = getlider(v);

    if(liderU == liderV)
        return;

    _emNum--;
    if(_rango[liderU] > _rango[liderV])
    {
        _pad[liderV] = liderU;
    }
    else
    {
        _pad[liderU] = liderV;
        if(_rango[liderU] == _rango[liderV])
            _rango[liderV]++;
    }
}

int TamArbolMin(vector<p<int, p<int, int> > > & caminos, int numV)
{
    sort(caminos.begin(), caminos.end());

    int minW = 0, numE = (int) caminos.size(), wE;
    EmpezarUnion spanForest(numV);
    p<int, int> pV;
    for(int i = 0; i < numE; i++)
    {
        if(spanForest.getemNum() == 1)
            break;

        wE = caminos[i].first;
        pV = caminos[i].second;
        if(!spanForest.mismo(pV.first, pV.second))
        {
            minW += wE;
            spanForest.EmpezarUnion(pV.first, pV.second);
        }
    }

    return minW;
}

int main(void)
{
    vector<p<int, p<int, int> > > caminos;
    int numV, numE, sumE, u, v, pesoE, MinCamino;

    while(1)
    {
        scanf("%d %d", &numV, &numE);
        if(numV == 0 && numE == 0)
            break;

        caminos.clear();
        sumE = 0;

        for(int i = 0; i < numE; i++)
        {
            scanf("%d %d %d", &u, &v, &pesoE);
            sumE += pesoE;
            caminos.push_back(make_p(pesoE, make_p(u, v)));
        }

        MinCamino = TamArbolMin(caminos, numV);
        printf("%d\n", sumE - MinCamino);
    }

    return 0;
}
