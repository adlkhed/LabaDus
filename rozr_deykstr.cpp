#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"Ukrainian");
    int n,i,j;
    n = 30;//кількість вершин
    int am[n][n];
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++){
            am[i][j]=0;
        }
    }

    am[0][1]=am[1][0]=6;
    am[0][6]=am[6][0]=4;
    am[1][2]=am[2][1]=1;
    am[1][7]=am[7][1]=8;
    am[2][3]=am[3][2]=1;
    am[2][8]=am[8][2]=3;
    am[3][4]=am[4][3]=3;
    am[3][9]=am[9][3]=1;
    am[4][5]=am[5][4]=3;
    am[4][10]=am[10][4]=5;
    am[5][11]=am[11][5]=7;
    am[6][7]=am[7][6]=2;
    am[6][12]=am[12][6]=5;
    am[7][8]=am[8][7]=1;
    am[7][13]=am[13][7]=1;
    am[8][9]=am[9][8]=4;
    am[8][14]=am[14][8]=3;
    am[9][10]=am[10][9]=2;
    am[9][15]=am[15][9]=4;
    am[10][11]=am[11][10]=4;
    am[10][16]=am[16][10]=1;
    am[11][17]=am[17][11]=7;
    am[12][13]=am[13][12]=7;
    am[12][18]=am[18][12]=5;
    am[13][14]=am[14][13]=1;
    am[13][19]=am[19][13]=7;
    am[14][15]=am[15][14]=2;
    am[14][20]=am[20][14]=1;
    am[15][16]=am[16][15]=3;
    am[15][21]=am[21][15]=4;
    am[16][17]=am[17][16]=7;
    am[16][22]=am[22][16]=2;
    am[17][23]=am[23][17]=8;
    am[18][19]=am[19][18]=7;
    am[18][24]=am[24][18]=8;
    am[19][20]=am[20][19]=3;
    am[19][25]=am[25][19]=2;
    am[20][21]=am[21][20]=1;
    am[20][26]=am[26][20]=1;
    am[21][22]=am[22][21]=8;
    am[21][27]=am[27][21]=3;
    am[22][28]=am[28][22]=3;
    am[22][23]=am[23][22]=5;
    am[23][29]=am[29][23]=7;
    am[24][25]=am[25][24]=4;
    am[25][26]=am[26][25]=7;
    am[26][27]=am[27][26]=3;
    am[27][28]=am[28][27]=3;
    am[28][29]=am[29][28]=6;

    int numb[30]{-1};
    int rebra=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (am[i][j]!=0)
                rebra++;// кількість ребер
        }
    }
    int weight[n]; //ваги
    bool visited[n]; //пройдені
    for (i=0;i<n;i++)
    {
        weight[i]=10000000;
        visited[i]=0;
    }
    weight[0]=0;
    visited[0]=1;
    int nmin,Vmin1,Vmin2;
    while (rebra!=0)
    {
        nmin=10000000;
        for (i=0;i<n;i++)
        {
            if (visited[i]==1)//якщо була пройдена
            {
                for (j=0;j<n;j++)
                {
                    if (weight[i]+am[i][j]<nmin&&am[i][j]!=0)//по рядку і шукає мін
                    {
                        nmin=weight[i]+am[i][j];
                        Vmin1=i;
                        Vmin2=j;
                    }
                }
            }
        }
        if (weight[Vmin2]>nmin)
        {
            weight[Vmin2]=nmin;
            numb[Vmin2]=Vmin1;
        }
        visited[Vmin2]=1;
        am[Vmin1][Vmin2]=am[Vmin2][Vmin1]=0;
        rebra-=2;//віднімаю ребра
    }

    int endd=29;
    int way[n];
    i=0;
    cout<<"\nВага мiнiмального шляху = "<<weight[endd]<<endl;

    cout<<"\nШлях:"<<endl;
    while (endd!=0)
    {
        way[i]=endd;
        endd=numb[endd];
        i++;
    }
    way[i]=0;

    for (i;i>=0;i--)
    {
        cout<<way[i];
        if (i!=0) cout<<"->";
    }
    cout<<endl;
}
