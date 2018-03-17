#include<stdio.h>
#include<conio.h>
#include<string.h>
char arr[3][3];


void input(int,int,int);
void display();
int check(int);

int main()
{ char player1[30],player2[30];

  int i,turn=1,loc1,loc2,chk,j,k,inc=4,x;
 for(j=0;j<3;j++)
  {for(k=0;k<3;k++)
   {arr[j][k]=inc;
    inc++;
   }
  }

 for(x=0;x<35;x++)
 {printf(" ");
 }
 printf("TIC TAC TOE");

 printf("\nWelcome to the Game\n");
 printf("Enter the name of player 1:");
 gets(player1);
 printf("\n");
 printf("Enter the name of player2:");
 gets(player2);
 printf("\n");
 printf("Get ready to play\n Press any key to Start....");
 getch();

  for(x=0;x<35;x++)
    {printf(" ");
    }
    printf("TIC TAC TOE\n");
 for(i=0;i<9;i++)
 {

   if(turn==1)
   {printf("Player %s's turn\n",player1);
   }
   else
   {printf("Player %s's turn\n",player2);
   }

   printf("Enter the location:");
   scanf("%d",&loc1);
   scanf("%d",&loc2);

   printf("\n");

   input(loc1,loc2,turn);
   chk=check(turn);
   if(chk==1)
   {
      for(x=0;x<35;x++)
    {printf(" ");
    }
    printf("TIC TAC TOE\n");

     display();
     if(turn==1)
   {
    printf("Player %s WON\n",player1);
   }
   else
   {printf("Player %s WON\n",player2);
   }
   break;
   }
   if(turn==1)
   {turn=2;
   }
   else
   {turn=1;
   }
   if(chk==2)
   {
      for(x=0;x<35;x++)
    {printf(" ");
    }
    printf("TIC TAC TOE\n");

     display();
     printf("It's DRAW");
    break;
   }


     for(x=0;x<35;x++)
    {printf(" ");
    }
    printf("TIC TAC TOE\n");

   display();
 }
getch();
return 0;
}

void input(int l,int m,int trn1)
{
  if(trn1==1)
   {arr[l][m]='X';
   }
   else
   {arr[l][m]='O';
   }

}
void display()
{int i,j;
 for(i=0;i<3;i++)
 {for(j=0;j<3;j++)
  {if((arr[i][j]=='x')||(arr[i][j]=='X')||(arr[i][j]=='o')||(arr[i][j]=='O'))
   {printf("%c  ",arr[i][j]);
   }
   else
   {printf("   ");
   }
  }
  printf("\n");
 }
}
int check(int trn)
{ int i,j,count=0;
  for(i=0;i<3;i++)
  {if((arr[i][0]==arr[i][1])&&(arr[i][0]==arr[i][2]))
   {
   return 1;
   }
  }
   for(i=0;i<3;i++)
  {if(arr[0][i]==arr[1][i]&&arr[0][i]==arr[2][i])
   {
   return 1;
   }

  }
   if((arr[0][0]==arr[1][1]&&arr[0][0]==arr[2][2])||(arr[0][2]==arr[1][1]&&arr[0][2]==arr[2][0]))
   {
   return 1;
   }
   for(i=0;i<3;i++)
   {for(j=0;j<3;j++)
    {if(arr[i][j]=='X'||arr[i][j]=='O')
     {count++;
     }
    }
   }
   if(count==9)
   {return 2;
   }
   return 0;

}



























