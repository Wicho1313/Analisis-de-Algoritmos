#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;

#define MAX_NUM_V 200
#define MAX_NAME 30

int Id(char name[], map<string, int> & mnt, int * sigid);
void MaxPar(int CargoMax[][MAX_NUM_V], int numV);
int Min(int a, int b);

int main(void)
{
    int CargoMax[MAX_NUM_V][MAX_NUM_V], numV, numE, cid, sigid,
        v1, v2, peso;
    map<string, int> mnt;
    char name[MAX_NAME + 1];

    cid = 1;
    while(1)
    {
        scanf("%d %d", &numV, &numE);
        if(numV == 0 && numE == 0)
            break;

        sigid = 0;
        memset(CargoMax, 0, MAX_NUM_V * MAX_NUM_V * sizeof(int));
        for(int e = 0; e < numE; e++)
        {
            scanf("%s", name);
            v1 = Id(name, mnt, &sigid);
            scanf("%s", name);
            v2 = Id(name, mnt, &sigid);
            scanf("%d", &peso);
            CargoMax[v1][v2] = peso;
            CargoMax[v2][v1] = peso;
        }
        MaxPar(CargoMax, numV);
        scanf("%s", name);
        v1 = Id(name, mnt, &sigid);
        scanf("%s", name);
        v2 = Id(name, mnt, &sigid);
        if(v1 < numV && v2 < numV)
        {
            printf("Escenario #%d\n%d toneladas\n\n", cid, CargoMax[v1][v2]);
        }
        cid++;
    }
    return 0;
}
int Id(char name[], map<string, int> & mnt, int * sigid)
{
    map<string, int>::iterator cont = mnt.find(name);
    int regresaId;
    if(cont == mnt.end())
    {
        regresaId = *sigid;
        mnt[name] = *sigid;
        (*sigid)++;
    }
    else
        regresaId = cont->second;

    return returnId;
}
void MaxPar(int CargoMax[][MAX_NUM_V], int numV)
{
    int u, v, k, load;
    for(k = 0; k < numV; k++)
        for(u = 0; u < numV; u++)
            for(v = 0; v < numV; v++)
            {
                if(CargoMax[u][k] && CargoMax[k][v])
                {
                    load = Min(CargoMax[u][k], CargoMax[k][v]);
                    if(load > CargoMax[u][v])
                        CargoMax[u][v] = load;
                }
            }
}
int Min(int a, int b)
{
    if(a > b)
        return b;
    return a;
}
