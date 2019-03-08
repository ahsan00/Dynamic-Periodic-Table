#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include <ctype.h>
#define max_atoms 112
#define W_NAME 17
#define W_ELECTRONIC 25

//THE SRUCURE:Periodic Table of the Elements
typedef struct
{
    int  Number;
    char Symbol[4];
    char Name [W_NAME];
    float  Weight;
    char Cstructure[30];
}
atoms;
atoms atom[max_atoms];


//------------------------------------------------
//read from a file.

void open_read ( atoms atom[] )
{
    FILE * p_elements ;
    int n = 0  ;
    if((p_elements=fopen( "periodica.txt", "r"))==NULL)   /*Check the file location*/
    {
        printf("The file does not exist.\n");
        exit(1);
    }
    else
    {
        while ( !feof(p_elements) )
        {
            fscanf( p_elements, "%d ", &atom[n].Number );
            fgets( atom[n].Symbol, 4, p_elements );
            fgets( atom[n].Name, W_NAME, p_elements );
            fscanf( p_elements, "%f", &atom[n].Weight );
            fgets( atom[n].Cstructure,30,p_elements);
            n++;
        }
        fclose( p_elements );
    }
}


//------------------------------------------------
//Display all atoms in the periodic table.

void display_all(atoms atom[])
{
    int i;
    for (i=0 ; i<max_atoms; i++)
    {
        printf("\t%d\t\t",atom[i].Number);
        printf("%s\t",atom[i].Symbol);
        printf("\t\t%s",atom[i].Name);
        printf("\t%.2f",atom[i].Weight);
        printf("\t\t%s",atom[i].Cstructure);
        printf("\n");
    }
}


//------------------------------------------------
//Display the search atom.

void display_search(atoms atom[],int n )
{
    printf("\n");
    int i=n;
    for (i = n ; i <= n  ; i++)
    {
        printf("\t Atomic Number : %d\n",atom[i].Number);
        printf("\t Atomic Symbol : %s\n",atom[i].Symbol);
        printf("\t Atomic Name   : %s\n",atom[i].Name);
        printf("\t Atomic Weight : %.2f\n",atom[i].Weight);
        printf("\t Crystal structure  : %s\n",atom[i].Cstructure);
        printf("\n\n");
    }
}


//------------------------------------------------
//Display Others elements.

int KeepOn()
{
    printf("\n\n");
    printf("  Atomic Number:\t");
    printf("Atomic Symbol:\t\t");
    printf("Atomic Name:\t\t");
    printf("Atomic Weight:\t");
    printf("Crystal structure:");
    printf("\n");

    return 0;
}

void display (atoms atom[],int n )
{
    int i=n;
    for (i = n ; i <= n  ; i++)
    {
        printf("\t%d\t",atom[i].Number);
        printf("\t%s\t",atom[i].Symbol);
        printf("\t\t%s",atom[i].Name);
        printf("\t%.2f\t\t",atom[i].Weight);
        printf("\t\t%s\n",atom[i].Cstructure);
        printf("\n");
    }
}


// ----------------------------------------
// List of the Halogens:

int Halogen()
{
    printf("\n\t The halogens are the five NonMetallic elements in the group VIIA\n");
    printf("\t of the periodic table. They have 7 electrons in their outer shells;\n");
    printf("\t then an oxidation number of -1. They are:");
    printf("\n\n\n\n");

    return 0;
}

int Halogens(atoms atom[])
{

    //PrintColumn();

    int Halogens [5] = {9, 17, 35, 53, 85};
    int i;
    int n;
    for (i = 0 ; i < 112 ; i++)
    {
        for( n = 0; n<5; n++)
        {
            if (atom[i].Number == Halogens[n])
                display(atom,i);
        }
    }

    return 0;
}


//---------------------------
// List of the Noble gas:

int Nobel_Gas()
{
    printf("\n  The six noble gases are present in group 18 of the periodic table.\n ");
    printf(" The number of electrons in their outer shell (2 for Helium, 8 for all\n ");
    printf(" others), makes them stable. They Noble Gases are:");
    printf("\n\n");

    return 0;
}

int NobleGas(atoms atom[])
{

    //PrintColumn();

    int Noble [] = {2, 10, 18, 36, 54,86};

    int i;
    int n;
    for (i = 0 ; i <112; i++)
    {
        for( n = 0; n<6; n++)
        {
            if (atom[i].Number == Noble[n])
                display(atom,i );
        }
    }
    return 0;
}



//-------------------------------
// List of the alkali metals:

int Alkalii()
{

    printf("\n\t The alkali metals are in group 1A of the periodic table. They have one\n ");
    printf("\t electron in their outer shell. They are reactive and good conductors of \n");
    printf("\t heat and electricity. They are softer (malleable, ductile) than most other metals.\n");
    printf("\t They are:");
    printf("\n\n");

    return 0;
}

int Alkali (atoms atom[])
{

    //PrintColumn();

    int Alkali [7] = {3, 11, 19, 37, 55, 87};
    int i;
    int n;
    for (i = 0 ; i <112 ; i++)
    {
        for( n = 0; n<6; n++)
        {
            if (atom[i].Number == Alkali[n])
                display(atom,i );
        }
    }
    return 0;
}


//------------------------------------------
//The alkaline earth elements:

int Alkaline_Earth()
{
    printf("\n\t The alkaline earth elements are metallic elements present in the\n ");
    printf("\t second group of the periodic table. They have an oxidation number of +2,\n ");
    printf("\t then very reactive. They are:");
    printf("\n\n");

    return 0;
}

int AlkalineEarth (atoms atom[])
{

    //PrintColumn();

    int AlkalineE[7] = {4, 12, 20, 38, 56, 88};
    int i;
    int n;
    for (i = 0 ; i <112 ; i++)
    {
        for( n = 0; n<6; n++)
        {
            if (atom[i].Number == AlkalineE[n])
                display(atom,i );
        }
    }
    return 0;
}



// -------------------------------------------------
//The metalloid elements:

int Metalloid()
{
    printf("\n\t Metalloids have properties of both metals and NonMetals. The Silicon \n");
    printf("\t and Germanium, are semi-conductors.\n");
    printf("\t These element is called Post Transitional Metals.\n");
    printf("\t They are:");
    printf("\n\n");

    return 0;
}

int Metalloids (atoms atom[])
{

    //PrintColumn();

    int Metalloids[8] = {5, 14, 32, 33, 51, 52, 84};
    int i;
    int n;
    for (i = 0 ; i < 112 ; i++)
    {
        for( n = 0; n<7; n++)
        {
            if (atom[i].Number == Metalloids[n])
                display(atom,i );
        }
    }
    return 0;
}


// -------------------------------------------
//The non metal elements:

int Non_Metal()
{
    printf("\n\t The Non_Metals are Hydrogen ( Group IA) and and the others in groups \n");
    printf("\t 14-16 of the periodic table.they don't  conduct electricity or heat very well.\n");
    printf("\t They do not reflect light. They are:");
    printf("\n\n");

    return 0;
}

int NonMetals (atoms atom[])
{

    //PrintColumn();

    int NonMetals[8] = {1, 6, 7, 8, 15, 16, 34};
    int i;
    int n;
    for (i = 0 ; i < 112 ; i++)
    {
        for( n = 0; n<7; n++)
        {
            if (atom[i].Number == NonMetals[n])
                display(atom,i );
        }
    }

    return 0;
}


//------------------------------------------
//The transitional metals:

int Transition_Metal()
{
    printf("\n\t The transition metals are the 38 elements in groups : 3 through \n");
    printf("\t 12 of the periodic table. As with all metals,they are malleable, and \n");
    printf("\t and conduct electricity and heat. The transition metals family contains \n");
    printf("\t Iron, Cobalt and Nickel : the only elements known to produce a magnetic \n");
    printf("\t field. They are:");
    printf("\n\n");

    return 0;
}

int TransitionMetals (atoms atom[])
{

    //PrintColumn();

    int i;
    int n;
    int m;
    int s;
    int x;

    for (i = 0 ; i < max_atoms  ; i++)
    {
        for( n = 21; n<31; n++)
        {
            if (atom[i].Number == n)
                display(atom,i );
        }

        for( m = 39; m<49; m++)
        {
            if (atom[i].Number == m)
                display(atom,i );
        }

        if(i == 56)
            display(atom, i);

        for( s = 72; s<81; s++)
        {
            if (atom[i].Number == s)
                display(atom,i );
        }

        if(i == 88)
            display(atom, i);

        for( x = 104; x <= max_atoms; x++)
        {
            if (atom[i].Number == x)
                display(atom,i );
        }
    }
    return 0;
}



// ------------------------------
//List of the rare earth elements

int Rare_Earth()
{
    printf("\n\t The thirty rare earth elements are made up of the lanthanide \n");
    printf("\t and actinide series. They are found in group 3 of the periodic table, and \n");
    printf("\t the 6th and 7th periods. They are:");
    printf("\n\n");

    return 0;
}


int RareEarth (atoms atom[])
{

    //PrintColumn();

    int i;
    int n;
    int m;

    printf("\n\n\t  1- The lanthanide series:\n\n");
    for (i = 0 ; i < 112  ; i++)
    {
        for( n = 57; n<72; n++)
        {
            if (atom[i].Number == n)
                display(atom,i );
        }
    }

    printf("\n\n\t 2- The actinide series:\n\n");
    for (i = 0 ; i <112  ; i++)
    {
        for( m = 89; m<105; m++)
        {
            if (atom[i].Number == m)
                display(atom,i );
        }
    }

    return 0;
}


// ------------------------------------------
//The Other Metals:

int Other_Metal()
{
    printf("\n\t The Other metals are the 7 elements located in groups 13, 14, and 15.\n");
    printf("\t They are:");
    printf("\n\n");

    return 0;
}

int OtherMetals (atoms atom[])
{

    //PrintColumn();

    int OtherMetal[7] = {13, 31, 49, 50, 81, 82, 83};

    int i;
    int n;
    for (i = 0 ; i < max_atoms ; i++)
    {
        for( n = 0; n<7; n++)
        {
            if (atom[i].Number == OtherMetal[n])
                display(atom,i );
        }
    }

    return 0;
}


//-------------------------------------
//S-block elements.

int S_Block()
{
    printf("\n\t The S-block elements are the 14 elements located in groups 1, 2, and Helium of group 18.\n");
    printf("\t They are:");
    printf("\n\n");

    return 0;
}

int S_block(atoms atom[])
{

    //PrintColumn();

    int S_block[] = {1, 2, 3, 4, 11, 12, 19, 20, 37, 38, 55, 56, 87, 88};

    int i;
    int n;
    for (i = 0 ; i < max_atoms ; i++)
    {
        for( n = 0; n<14; n++)
        {
            if (atom[i].Number == S_block[n])
                display(atom,i );
        }
    }

    return 0;
}


//-------------------------------------
//P-block elements.

int P_Block()
{
    printf("\n\t The P-block elements are the 30 elements located in groups 13, 14, 15, 16, 17 and 18.\n");
    printf("\t They are:");
    printf("\n\n");

    return 0;
}

int P_block(atoms atom[])
{

    //PrintColumn();

    int P_block[] = {5, 6, 7, 8, 9, 10, 13, 14, 15, 16, 17, 18, 31, 32, 33, 34, 35, 36,
                     49, 50, 51, 52, 53, 54, 81, 82, 83, 84, 85, 86};

    int i;
    int n;
    for (i = 0 ; i < max_atoms ; i++)
    {
        for( n = 0; n<30; n++)
        {
            if (atom[i].Number == P_block[n])
                display(atom,i );
        }
    }

    return 0;
}


//-------------------------------------
//D-block elements.

int D_Block()
{
    printf("\n\t The D-block elements are the 40 elements located in groups 3, 4, 5, 6, 7, 8, 9, 10, 11, and 12.\n");
    printf("\t These elements are called Transitional metal.\n");
    printf("\t They are:");
    printf("\n\n");


    return 0;
}

int D_block(atoms atom[])
{

    //PrintColumn();

    int i;
    int n;
    int m;
    int s;
    int x;

    for (i = 0 ; i < max_atoms  ; i++)
    {
        for( n = 21; n<31; n++)
        {
            if (atom[i].Number == n)
                display(atom,i );
        }

        for( m = 39; m<49; m++)
        {
            if (atom[i].Number == m)
                display(atom,i );
        }

        if(i == 56)
            display(atom, i);

        for( s = 72; s<81; s++)
        {
            if (atom[i].Number == s)
                display(atom,i );
        }

        if(i == 88)
            display(atom, i);


        for( x = 104; x <= max_atoms; x++)
        {
            if (atom[i].Number == x)
                display(atom,i );
        }
    }
    return 0;
}


//-------------------------------------
//F-block elements.

int F_Block()
{
    printf("\n\t The F-block elements are the 28 elements located in groups 3.\n");
    printf("\t These elements are called Lanthanide & Actinides series.\n");
    printf("\t They are:");
    printf("\n\n");

    return 0;
}

int F_block(atoms atom[])
{

    //PrintColumn();

    int i;
    int n;
    int m;

    for (i = 0 ; i < max_atoms  ; i++)
    {
        for( n = 58; n<=71; n++)
        {
            if (atom[i].Number == n)
                display(atom,i );
        }

        for( m = 90; m<104; m++)
        {
            if (atom[i].Number == m)
                display(atom,i );
        }
    }
    return 0;
}


//------------------------------------
//The liquid elements.

int liquid()
{
    printf("\n\t The Liquid elements are the 2 elements located in groups 17 and 12.\n");
    printf("\t These elements are liquid under normal condition.\n");
    printf("\t They are:");
    printf("\n\n");


    return 0;
}

int Liquid(atoms atom[])
{
    int liquid[]= {35,80};
    int i;
    int n;
    for (i = 0 ; i < max_atoms ; i++)
    {
        for( n = 0; n<2; n++)
        {
            if (atom[i].Number == liquid[n])
                display(atom,i );
        }
    }

    return 0;
}


//------------------------------------
//The Gases elements.

int Gas()
{
    printf("\n\t The Gases element are 11 elements located in groups 15, 16, 17, 18 and Hydrogen.\n");
    printf("\t They are:\n\n");

    return 0;
}

int Gases(atoms atom[])
{
    int Gas[]= {1,2,7,8,9,10,17,18,36,54,86};
    int i;
    int n;
    for (i = 0 ; i < max_atoms ; i++)
    {
        for( n = 0; n<11; n++)
        {
            if (atom[i].Number == Gas[n])
                display(atom,i );
        }
    }

    return 0;
}




//------------------------------------------------
//Search any elements
void Search ()
{
    char Response;
    do
    {
        int s_number;
        int i;
        int success = 0;
        printf("\n\t Enter the Number of the atom you are searching for: ");
        scanf("%d", &s_number);

        for (i = 0 ; i < s_number ; i++)
        {
            if (atom[i].Number == s_number)
            {
                printf("\n");
                display_search(atom,i);
                success = 1;
            }
            else
            {
                success =0;
            }
        }

        if(success==0)
        {
            printf("\n\t This atom is not in the table.\n");
        }

        printf("\n\t Do you want to try again ? Y : N --> ");
        scanf("%s", &Response);

        Response = toupper (Response);
    }
    while ( Response =='Y');
}


//------------------------------------------------
//Print the hits.
char The_Menu ()
{
    char Choose ;
    int  Flag   ; /* Yes or No the choice is valid*/
    printf("\n   Hints :\n");
    printf("  -> L to list all the elements \n");
    printf("  -> G Noble Gases\n");
    printf("  -> H Halogens\n");
    printf("  -> A Alkali\n");
    printf("  -> E Alkaline Earth\n");
    printf("  -> M Metalloid \n");
    printf("  -> N Non Metals \n");
    printf("  -> T Transition Metals \n");
    printf("  -> R Rare Earth \n");
    printf("  -> O Other Metals \n");
    printf("  -> B S-Block Elements\n");
    printf("  -> P P-Block Elements\n");
    printf("  -> D D-Block Elements\n");
    printf("  -> F F-Block Elements\n");
    printf("  -> C Liquid Elements\n");
    printf("  -> I Gases Elements\n");
    printf("  -> S to search\n");
    printf("  -> Q to quit\n");

    do
    {
        printf("\n Choose among  A, B, C, D, E, F, G, H, I, L, M, N, O, P, Q, R, S, T: --> ");
        fflush(stdin);
        Choose = toupper(getchar());
        printf("\n\n");
        Flag = (    Choose == 'L' || Choose == 'G' || Choose == 'H' || Choose == 'A' || Choose == 'E'
                    || Choose == 'M' || Choose == 'N' || Choose == 'T' || Choose == 'R' || Choose == 'O'
                    || Choose == 'B' || Choose == 'P' || Choose == 'D' || Choose == 'F' || Choose == 'S'
                    || Choose == 'C' || Choose == 'I'||Choose == 'Q' );
        if (!Flag)
            printf(" The choice is not valid . Try again ! \n\n");
    }
    while (!Choose);

    return Choose;
}


//------------------------------------------------
//choose char for actions.

void cases()
{
    int k=13;
    char Choose;
     HANDLE  hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    do
    {
SetConsoleTextAttribute(hConsole,k);
        Choose=The_Menu();

        k--;
        switch (Choose)
        {
        case 'L':
        {
            KeepOn();
            display_all(atom);
            break;
        }

        case 'H':
        {
            Halogen();
            KeepOn();
            Halogens(atom);
            break ;
        }

        case 'G':
        {
            Nobel_Gas();
            KeepOn();
            NobleGas(atom);
            break;
        }

        case 'A':
        {
            Alkalii();
            KeepOn();
            Alkali(atom);
            break;
        }

        case 'E':
        {
            Alkaline_Earth();
            KeepOn();
            AlkalineEarth (atom);
            break;
        }

        case 'M':
        {
            Metalloid();
            KeepOn();
            Metalloids (atom);
            break;
        }

        case 'N':
        {
            Non_Metal();
            KeepOn();
            NonMetals(atom);
            break;
        }

        case 'T':
        {
            Transition_Metal();
            KeepOn();
            TransitionMetals (atom);
            break;
        }

        case 'R':
        {
            Rare_Earth();
            KeepOn();
            RareEarth (atom);
            break;
        }

        case 'O':
        {
            Other_Metal();
            KeepOn();
            OtherMetals (atom);
            break;
        }

        case 'B':
        {
            S_Block();
            KeepOn();
            S_block (atom);
            break;
        }

        case 'P':
        {
            P_Block();
            KeepOn();
            P_block (atom);
            break;
        }

        case 'D':
        {
            D_Block();
            KeepOn();
            D_block (atom);
            break;
        }

        case 'F':
        {
            F_Block();
            KeepOn();
            F_block (atom);
            break;
        }

        case 'C':
        {
            liquid();
            KeepOn();
            Liquid (atom);
            break;
        }

        case 'I':
        {
            Gas();
            KeepOn();
            Gases (atom);
            break;
        }

        case 'S':
            Search ();
            break;
        }
    }
    while (Choose != 'Q');
}


//------------------------------------------

int  main()
{
    printf("\t\t\t\t WELCOME TO OUR PROJECT\n\n\t\t\t\t  MODERN PERIODIC TABLE\n");
    open_read (atom);
    printf("\n\n");
    cases ();

    return 0;
}
