#include<iostream>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <fstream>
#include<dos.h>

using namespace std;

int nn; // ptr numarul de laturi
int o; //optiuni in switch
int forma; //forma de corp geometric 3d

int n1,n2,m1,m2;

float a[50][50];
 float b[50][50];
 float c[50][50];

//--------Citire fisier pentru cub

void citireCub(int n, float x[50][50])
{
	ifstream cinCub("cub.in");
	cinCub>>nn;

	for(int i=1;i<=3;i++) {
        for(int j=1;j<=n;j++)
        {
            cinCub>>x[i][j];
        }
	}
    cinCub.close();
}

//--------Citire fisier pentru piramida

void citirePiramida(int n, float x[50][50])
{
	ifstream cinPiraminda("piramida.in");
	cinPiraminda>>nn;

	for(int i=1;i<=3;i++) {
        for(int j=1;j<=n;j++)
        {
            cinPiraminda>>x[i][j];
        }
	}

    cinPiraminda.close();
}

//---------Citire fisier pentru prisma

void citirePrisma(int n, float x[50][50])
{
	ifstream cinPrisma("prisma.in");
	cinPrisma>>nn;

	for(int i=1;i<=3;i++) {
        for(int j=1;j<=n;j++)
        {
            cinPrisma>>x[i][j];
        }
	}

    cinPrisma.close();
}

// -------Afisarea matricei corespunzatoare formei

void afisare(int n, float x[50][50])
{
    cout<<endl<<"Matricea formei alese este: "<<endl;

     for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=n;j++)

            cout<<x[i][j]<<" ";

            cout<<endl;
    }
}

void desenareCub(int n, float x[50][50])
{

	initwindow(800, 600);

    for(int j=1;j<=n/2-1;j++)
    {
    	line(x[1][j]-x[3][j], x[2][j]+x[3][j], x[1][j+1]-x[3][j+1], x[2][j+1]+x[3][j+1]);
    }
   	line(x[1][n/2]-x[3][n/2], x[2][n/2]+x[3][n/2], x[1][1]-x[3][1],x[2][1]+x[3][1]);

  	for(int j=n/2+1;j<=n-1;j++)
    {
        line(x[1][j]-x[3][j], x[2][j]+x[3][j], x[1][j+1]-x[3][j+1], x[2][j+1]+x[3][j+1]);
    }
	line(x[1][n]-x[3][n], x[2][n]+x[3][n], x[1][n/2+1]-x[3][n/2+1],x[2][n/2+1]+x[3][n/2+1]);

   	for(int j=1;j<=n/2;j++)
  	{
   		line(x[1][j]-x[3][j], x[2][j]+x[3][j], x[1][j+n/2]-x[3][j+n/2], x[2][j+n/2]+x[3][j+n/2]);
   	}
}



void desenarePiramida(int n, float x[50][50])
{

	initwindow(800, 600);

    for(int j=1;j<=n/2-1;j++)
    {
    	line(x[1][j]-x[3][j], x[2][j]+x[3][j], x[1][j+1]-x[3][j+1], x[2][j+1]+x[3][j+1]);
    }

  	for(int j=n/2+1;j<=n-2;j++)
    {
        line(x[1][j]-x[3][j], x[2][j]+x[3][j], x[1][j+1]-x[3][j+1], x[2][j+1]+x[3][j+1]);
    }

    for(int j=1;j<=n/2;j++)
  	{
   		line(x[1][j]-x[3][j], x[2][j]+x[3][j], x[1][j+n/2]-x[3][j+n/2], x[2][j+n/2]+x[3][j+n/2]);
   	}

   	 for(int j=1;j<=n-1;j++)
  	{
   		line(x[1][j]-x[3][j], x[2][j]+x[3][j], x[1][5]-x[3][5], x[2][5]+x[3][5]);
   	}
}

void desenarePrisma(int n, float x[50][50])
{
	initwindow(800, 600);

    for(int j=1;j<=n/2-1;j++)
    {
    	line(x[1][j]-x[3][j], x[2][j]+x[3][j], x[1][j+1]-x[3][j+1], x[2][j+1]+x[3][j+1]);
    }
    line(x[1][n/2]-x[3][n/2], x[2][n/2]+x[3][n/2], x[1][1]-x[3][1],x[2][1]+x[3][1]);

    for(int j=n/2+1;j<=n-1;j++)
    {
    	line(x[1][j]-x[3][j], x[2][j]+x[3][j], x[1][j+1]-x[3][j+1], x[2][j+1]+x[3][j+1]);
    }
    line(x[1][n]-x[3][n], x[2][n]+x[3][n], x[1][n/2+1]-x[3][n/2+1],x[2][n/2+1]+x[3][n/2+1]);

    for(int j=1;j<=n/2;j++)
  	{
   		line(x[1][j]-x[3][j], x[2][j]+x[3][j], x[1][j+n/2]-x[3][j+n/2], x[2][j+n/2]+x[3][j+n/2]);
   	}
}


//-------funcite de inmultire a 2a matrici

int i,j,k;
void inmultire(float a[50][50],float b[50][50],float c[50][50], int m, int n, int p, int r)
{

    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++) {
            for(int k=1;k<=m;k++) {
                c[i][j]=0;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=p;j++) {
            for(int k=1;k<=m;k++) {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}



void scalare(float b[50][50])
{
	for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            a[i][j]=0;
        }
	}  // ---- initializam matricea de scalare cu 0


    float ox, oy, oz;

    cout<<endl<<"Dati indicele de SCALARE al AXEI Ox: ";
    cin>>ox;

    cout<<endl<<"Dati indicele de SCALARE al AXEI Oy: ";
    cin>>oy;

    cout<<endl<<"Dati indicele de SCALARE al AXEI Oz: ";
    cin>>oz;

    a[1][1]=ox;
    a[1][2]=0;
    a[1][3]=0;
    a[2][1]=0;
    a[2][2]=oy;
    a[2][3]=0;
    a[3][1]=0;
    a[3][2]=0;
    a[3][3]=oz;

cout<<"---------------------------"<<endl;
cout<<"Matricea scalare: "<<endl;
    for(i=1; i<=3; i++)
    {
        for(j=1; j<=3;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }


    inmultire(a, b, c, 3, 3, nn, 3);
    cout<<nn;
    if(forma==1) {
        desenareCub(nn, c);
    } else if(forma==2) {
        desenarePiramida(nn, c);
    } else desenarePrisma(nn, c);

    afisare(nn, c);


}

void adunare(float a[50][50],float b[50][50],float c[50][50], int li, int co)
{

	for(int i=1;i<=li;i++) {
        for(int j=1;j<=co;j++)
        {
            c[i][j]=0;
        }
	}


    for(int i=1;i<=li;i++) {
        for(int j=1;j<=co;j++)
        {
            c[i][j]+=a[i][j]+b[i][j];
        }
    }


    cout<<"Matricea adunare: "<<endl;
    for(int i=1;i<=li;i++)
    {
        for(int j=1;j<=co;j++) {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

}

void tranzlatie(float b[50][50])
{
	for(int i=1;i<=3;i++) {
        for(int j=1;j<=nn;j++) {
            a[i][j]=0;
        }
	}


    float ox, oy, oz;

    cout<<endl<<"Dati indicele de TRANSLATIE al AXEY Ox: ";
    cin>>ox;

    cout<<endl<<"Dati indicele de TRANSLATIE al AXEY Oy: ";
    cin>>oy;

    cout<<endl<<"Dati indicele de TRANSLATIE al AXEY Oz: ";
    cin>>oz;


        for(j=1; j<=nn; j++)
        {
            a[1][j]=ox;
            a[2][j]=oy;
            a[3][j]=oz;
        }
        cout<<"--------------------------"<<endl;
        cout<<"Matrice translatie"<<endl;
        for(i=1; i<=3; i++)
        {
            for(j=1; j<=3;j++) {
                 cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"Matricea initiala: "<<endl;
        afisare(nn, b);

        adunare(a, b, c, 3, nn);
        //afisare(nn, c);

        if(forma==1) {
            desenareCub(nn, c);
        } else if(forma==2) {
            desenarePiramida(nn, c);
        } else desenarePrisma(nn, c);
}

void rotatie(float b[50][50])
{
	int opr;

	cout<<"Alegeti una dintre urm. optiuni pentru rotatie: " <<endl;
	cout<<" 1 - Axa Ox" << endl;
	cout<<" 2 - Axa Oy" <<endl;
	cout<<" 3 - Axa Oz" <<endl;
	cin>>opr;

	 switch(opr)
        {
            case 1:
                //dupa Ox
            {
                float u;
    			float radiani;

    			cout<<endl<<"Dati unghiul de ROTATIE: ";
    			cin>>u;
    			radiani= (u*3.14)/180;
    			cout<<radiani<<endl;
    			a[1][1]=1;
    			a[1][2]=0;
    			a[1][3]=0;
    			a[2][1]=0;
   	 			a[2][2]=cos(radiani);
   				a[2][3]=-sin(radiani);
   	 			a[3][1]=0;
    			a[3][2]=sin(radiani);
    			a[3][3]=cos(radiani);

                cout<<"--------------------------"<<endl;
    			cout<<"Matrice rotatie"<<endl;
    			for(i=1; i<=3; i++)
   				{
   				    for(j=1; j<=3;j++) {
                         cout<<a[i][j]<<" ";
   				    }
                    cout<<endl;
    			}

   				inmultire(a, b, c, 3, 3, nn, 3);
    			if(forma==1){
                    desenareCub(nn, c);
        		} else if(forma==2) {
                    desenarePiramida(nn, c);
        		} else desenarePrisma(nn, c);

                break;
			}
            case 2:
                //dupa Oy
            {
                float u;
    			float radiani;

    			cout<<endl<<"Dati unghiul de ROTATIE: ";
    			cin>>u;
    			radiani= (u*3.14)/180;
    			cout<<radiani<<endl;
    			a[1][1]=cos(radiani);
    			a[1][2]=0;
    			a[1][3]=sin(radiani);
    			a[2][1]=0;
   	 			a[2][2]=1;
   				a[2][3]=0;
   	 			a[3][1]=-sin(radiani);
    			a[3][2]=0;
    			a[3][3]=cos(radiani);

                cout<<"--------------------------"<<endl;
    			cout<<"Matrice rotatie"<<endl;
    			for(i=1; i<=3; i++)
   				{
   				    for(j=1; j<=3;j++) {
                        cout<<a[i][j]<<" ";
   				    }
                    cout<<endl;
    			}

   				inmultire(a, b, c, 3, 3, nn, 3);
    			if(forma==1) {
                    desenareCub(nn, c);
        		} else if(forma==2) {
                    desenarePiramida(nn, c);
        		} else desenarePrisma(nn, c);

                break;
			}
            case 3:
                //dupa Oz
            {
                float u;
    			float radiani;

    			cout<<endl<<"Dati unghiul de ROTATIE: ";
    			cin>>u;
    			radiani= (u*3.14)/180;
    			cout<<radiani<<endl;
    			a[1][1]=cos(radiani);
    			a[1][2]=-sin(radiani);
    			a[1][3]=0;
    			a[2][1]=sin(radiani);
   	 			a[2][2]=cos(radiani);
   				a[2][3]=0;
   	 			a[3][1]=0;
    			a[3][2]=0;
    			a[3][3]=1;

                cout<<endl<<"--------------------------";
    			cout<<endl<<"Matrice rotatie"<<endl;
    			for(i=1; i<=3; i++)
   				{
   				    for(j=1; j<=3;j++) {
                        cout<<a[i][j]<<" ";
   				    }
                    cout<<endl;
    			}

   				inmultire(a, b, c, 3, 3, nn, 3);
    			if(forma==1) {
                    desenareCub(nn, c);
        		} else if(forma==2) {
                    desenarePiramida(nn, c);
        		} else desenarePrisma(nn, c);

                break;
			}
  		    break;
	}
}

void matrice(float b[50][50])
{
	for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            a[i][j]=0;
        }
	}


    float ox, oy, oz;
	int op;

	cout<<"Alegeti una din optiunie urm. pentru axa de : "<<endl;
	cout<<" 1 -Axa Ox"<<endl;
	cout<<" 2 -Axa Oy"<<endl;
	cout<<" 3 -Axa Oz"<<endl;
	cin>>op;

        switch(op)
        {
            case 1:
                //dupa Ox
            {
                cout<<"Dati indicele de  al AXEI Oy: "<<endl;
    			cin>>oy;

   			    cout<<"Dati indicele de  al AXEI Oz: "<<endl;
  			    cin>>oz;

				a[1][1]=1;
    			a[1][2]=oy;
   				a[1][3]=oz;
    			a[2][1]=0;
    			a[2][2]=1;
				a[2][3]=0;
				a[3][1]=0;
				a[3][2]=0;
				a[3][3]=1;

				cout<<"---------------------------"<<endl;
				cout<<"Matricea : "<<endl;
  				for(i=1; i<=3; i++)
   				{
   				    for(j=1; j<=3;j++) {
                        cout<<a[i][j]<<" ";
   				    }
                    cout<<endl;
    			}

       			//desenareCub(nn, b);
        		//afisare(nn, b);
        		inmultire(a, b, c, 3, 3, nn, 3);
        		if(forma==1) {
                    desenareCub(nn, c);
        		} else if(forma==2) {
                    desenarePiramida(nn, c);
        		} else desenarePrisma(nn, c);

				afisare(nn, c);

                break;
			}
            case 2:
                //dupa Oy
            {
				cout<<"Dati indicele de  al AXEI Ox: "<<endl;
    			cin>>ox;

   			    cout<<"Dati indicele de  al AXEI Oz: "<<endl;
  			    cin>>oz;

				a[1][1]=1;
    			a[1][2]=0;
   				a[1][3]=0;
    			a[2][1]=ox;
    			a[2][2]=1;
				a[2][3]=oz;
				a[3][1]=0;
				a[3][2]=0;
				a[3][3]=1;

				cout<<endl<<"---------------------------";
				cout<<endl<<"Matricea "<<endl;
  				for(i=1; i<=3; i++)
   				{
   				    for(j=1; j<=3;j++) {
                        cout<<a[i][j]<<" ";
   				    }
                    cout<<endl;
    			}

       			//desenareCub(nn, b);
        		//afisare(nn, b);
        		inmultire(a, b, c, 3, 3, nn, 3);
        		if(forma==1) {
                    desenareCub(nn, c);
        		} else if(forma==2) {
                    desenarePiramida(nn, c);
        		} else desenarePrisma(nn, c);

                break;
			}
            case 3:
                //dupa Oz
            {
                cout<<"Dati indicele de  al AXEI Ox: "<<endl;
    			cin>>ox;

   			    cout<<"Dati indicele de  al AXEI Oy: "<<endl;
  			    cin>>oy;

				a[1][1]=1;
    			a[1][2]=0;
   				a[1][3]=0;
    			a[2][1]=0;
    			a[2][2]=1;
				a[2][3]=0;
				a[3][1]=ox;
				a[3][2]=oy;
				a[3][3]=1;

				cout<<"---------------------------"<<endl;
				cout<<"Matricea : "<<endl;
  				for(i=1; i<=3; i++)
   				{
   				    for(j=1; j<=3;j++) {
                        cout<<a[i][j]<<" ";
   				    }
                    cout<<endl;
    			}

       			//desenareCub(nn, b);
        		//afisare(nn, b);
        		inmultire(a, b, c, 3, 3, nn, 3);
        		if(forma==1) {
                    desenareCub(nn, c);
        		} else if(forma==2) {
                    desenarePiramida(nn, c);
        		} else desenarePrisma(nn, c);
                break;
			}
  		    break;
	}
}

int main()
{


    cout<<"Selectati forma geometrica dorita: "<<endl;
    cout<<"1 - Cub"<<endl;
    cout<<"2 - Piramida"<<endl;
    cout<<"3 - Prisma hexagonala"<<endl;
    cin>>forma;


        switch(forma)
        {
            case 1:

                {

                    ifstream cinCub("cub.in");
                    cinCub>>nn;
                    cinCub.close();
                    citireCub(nn, b);

                    break;
                }
            case 2:

                {
                    ifstream cinPiramida("piramida.in");
                    cinPiramida>>nn;
                    cinPiramida.close();
                    citirePiramida(nn, b);

                    break;
                }
            case 3:
                {
                    ifstream cinPrisma("prisma.in");
                    cinPrisma>>nn;
                    cinPrisma.close();
                    citirePrisma(nn, b);
                    break;
                }
            case 0:
                break;
    }

    afisare(nn, b);


    cout<<"Selectati o optiune din meniu: "<<endl;
    cout<<"1 - Desenare"<<endl;
    cout<<"2 - Scalare"<<endl;
    cout<<"3 - Translatie"<<endl;
    cout<<"4 - Rotire"<<endl;
    cout<<"5 - Forfecare"<<endl;
    cout<<"0 - Iesire"<<endl;
    cin>>o;

   do{
        switch(o)
        {
            case 1:
                //Scalare
            {
				if(forma==1) {
                    desenareCub(nn, b);
                } else if(forma==2) {
                    desenarePiramida(nn, b);
                } else
                    desenarePrisma(nn, b);

                break;}
            case 2:
                //Scalare
            {


                scalare(b);

                break;}
            case 3:
                //Translatie
                {
                tranzlatie(b);



                break;}
        case 4:
            //Rotatie
            rotatie(b);
            break;
        case 5:
            //
            {

            matrice(b);

            break;}

        case 0:
            break;
    }

    cout<<"Selectati o optiune din meniu: "<<endl;
    cout<<"1 - Desenare"<<endl;
    cout<<"2 - Scalare"<<endl;
    cout<<"3 - Translatie"<<endl;
    cout<<"4 - Rotire"<<endl;
    cout<<"5 - Forfecare"<<endl;
    cout<<"0 - Iesire"<<endl;
    cin>>o;

    }while(o!=0);


    return 0;
    getch();
    closegraph();
}



