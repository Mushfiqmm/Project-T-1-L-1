# include "iGraphics.h"
#include<stdio.h>
#include <string.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib");
int screenwidth=1100,screenheight=800;
struct students
{
	char name[100];
	char bname[100];
	char  date[100];
	char av[10];
	char id[100];
};
students stds[50];
int studentID[2205200]={0};
char str[3][1000]={"Student name","ID number"};
//char str[1000];
int d,student=0,another_page=0,s=0;
int toomuch1=0;
int c,npage=0,page=0,page2=0,nnpage=0,page3=0,npage3=0;
int click=0;
int g=0,kep=0;
int rusure=0;
bool musicON=true;
bool musicON2=true;
int gmstate=0;
int len=0;
struct Booksws
{
	char book[100];
	char aname[100];
	char availabily[100];
}sbooks[100];

void showchar()
{
	iSetColor(0,0,0);
	iFilledRectangle(350,50,600,400);
	iSetColor(255,255,255);
	iRectangle(340,45,620,410);
	iSetColor(200,200,200);
    iText(400,400,"Enter your Name:",GLUT_BITMAP_HELVETICA_18);
	iRectangle(495, 350, 360, 30);
	iText(500,360,str[0],GLUT_BITMAP_HELVETICA_18);
	iText(400,300,"Enter student ID:",GLUT_BITMAP_HELVETICA_18);
	iRectangle(495, 250, 360, 30);
	iText(500,260,str[1],GLUT_BITMAP_HELVETICA_18);
	iSetColor(0,0,0);
	iFilledCircle(340, 460, 20, 100);
	iSetColor(255,255,255);
	iLine(330 ,470 ,350 ,450 );
	iLine(330 ,450 ,350 ,470 );
}
char strb[3][100];
int add=0;
int rw;
void rewrite()  ////return
{
	int m=0,avnum=0,g=0;
	while(stds[rw].av[g+1]!='\0') 
	{
	m = m*10 + (stds[rw].av[g]- '0');
	g = g + 1;
	}
	g=0;
	while(sbooks[m].availabily[g+1]!='\0') 
	{
	avnum = avnum*10 + (sbooks[m].availabily[g]- '0');
	g = g + 1;
	}
	avnum=avnum+1;
	strcpy(sbooks[m].availabily,"");
	sprintf(sbooks[m].availabily,"%d\n",avnum);
	FILE *str;
	str = fopen("catalogue.txt","w");
	int f =0;
	do	
	{
		fputs(sbooks[f].book, str);
	    fputs(sbooks[f].aname,str);
		fputs(sbooks[f].availabily,str);
	}while (sbooks[f++].book[0]!=0);
	fclose(str);
   	FILE *ptr;
   	ptr=fopen("record.txt","w");
	int k=0;
	//for(int k =1; stds[k-1].name[0]!=0;k++)
	do	
	{
		if(k!=rw)
		{
		fputs(stds[k].name, ptr);
	    fputs(stds[k].bname,ptr);
		fputs(stds[k].id,ptr);
		fputs(stds[k].date,ptr);
		fputs(stds[k].av,ptr);
		}
	}while (stds[k++].name[0]!=0);
	stds[k-2].name[0]=0;
	stds[k-2].bname[0]=0;
	stds[k-2].date[0]=0;
	stds[k-2].id[0]=0;
	stds[k-2].av[0]=0;
	fclose(ptr);
	
}
void ADD()
{
	iSetColor(0,0,0);
	iFilledRectangle(350,50,600,400);
	iSetColor(255,255,255);
	iRectangle(340,45,620,410);
	iSetColor(200,200,200);
	iText(400,400,"Enter Book name:",GLUT_BITMAP_HELVETICA_18);
	iRectangle(495, 350, 360, 30);
	iText(500,360,strb[0],GLUT_BITMAP_HELVETICA_18);
	iText(400,300,"Enter Author name:",GLUT_BITMAP_HELVETICA_18);
	iRectangle(495, 250, 360, 30);
	iText(500,260,strb[1],GLUT_BITMAP_HELVETICA_18);
	iText(400,200,"Enter Availability:",GLUT_BITMAP_HELVETICA_18);
	iRectangle(495, 150, 360, 30);
	iText(500,160,strb[2],GLUT_BITMAP_HELVETICA_18);
	iSetColor(0,0,0);
	iFilledCircle(340, 460, 20, 100);
	iSetColor(255,255,255);
	iLine(330 ,470 ,350 ,450 );
	iLine(330 ,450 ,350 ,470 );
}
int m=-1;
int i=0;
void takein()
{
	//strcpy(stds[i].name,str);
	//strcpy(stds[i].bname,buff[m]);
	//convsum();
	time_t t=time(NULL);
	struct tm *cur_time=localtime(&t);
	cur_time->tm_mday=cur_time->tm_mday+7;
    time_t newtime=mktime(cur_time);
    sprintf(str[2],"%d",newtime);
	FILE *ptr;
	ptr = fopen("record.txt","a");
	fprintf(ptr, "%s\n", str[0]);
	//fprintf(ptr,"%s",buff[m]);
	fprintf(ptr,"%s",sbooks[m].book);
	fprintf(ptr,"%s\n",str[1]);
	fprintf(ptr,"%s\n",str[2]);
	strcpy(str[0],"ur name");
	strcpy(str[1],"student id");
	//strcpy(str[2],"dd/mm/yyyy");
	char ava[10];
	sprintf(ava,"%d",m);
	fprintf(ptr,"%s\n",ava);
	fclose(ptr);
	int avnum=0,g=0;
	while(sbooks[m].availabily[g+1]!='\0') 
	{
	avnum = avnum*10 + (sbooks[m].availabily[g]- '0');
	g = g + 1;
	}
	avnum=avnum-1;
	strcpy(sbooks[m].availabily,"");
	sprintf(sbooks[m].availabily,"%d\n",avnum);
	FILE *str;
	str = fopen("catalogue.txt","w");
	int k =0;
	do	
	{
		fputs(sbooks[k].book, str);
	    fputs(sbooks[k].aname,str);
		fputs(sbooks[k].availabily,str);
	}while (sbooks[k++].book[0]!=0);
	fclose(str);
	//strcpy(stds[i].bname,str[1]);
	//stds[i].date=d;
	click=0;
}
int j=0;
void takeinb()
{
	FILE *ptr;
	ptr = fopen("catalogue.txt","a");
	fprintf(ptr, "%s\n", strb[0]);
	fprintf(ptr, "%s\n", strb[1]);
	fprintf(ptr, "%s\n", strb[2]);
	fclose(ptr);
	strcpy(strb[0],"");
	strcpy(strb[1],"");
	strcpy(strb[2],"");

}
void toomuch()
{
	iSetColor(0,0,0);
	iFilledRectangle(350,400,400,50);
	iSetColor(200,0,0);
	iText(370,420,"This student cannot take anymore books!!",GLUT_BITMAP_HELVETICA_18);
	iSetColor(0,0,0);
	iFilledCircle(340, 460, 20, 100);
	iSetColor(255,255,255);
	iLine(330 ,470 ,350 ,450 );
	iLine(330 ,450 ,350 ,470 );
	iSetColor(0,0,0);
	iFilledCircle(340, 460, 20, 100);
	iSetColor(200,0,0);
	iLine(330 ,470 ,350 ,450 );
	iLine(330 ,450 ,350 ,470 );
}
void takeinput(unsigned key)
{
   if(key == '\r')
   {
	 j++;

	 strcpy(str[j],"");
	 len=0;
	 if(j>1)
	 {
		int num=0;
		for(int d=0;str[1][d]!=0;d++)
		{
			num=num*10 + (str[1][d]-'0');
		}
		studentID[num]+=1;
		if(studentID[num]<=3)
		{
			takein();
		}
		else
		{
			toomuch1=1;
		}
		gmstate=0;
		j=0;
		i++;
	 }
	 //takein();
     //newhighscore();
   }
   else if (key == '\b')
   {
	if (len <=0)
	{
      len=0;
	}
	else{
		len--;
	}
	str[j][len] = '\0';
   }
   else{
	str[j][len] = key;
	len++;
	if(len > 25)
	  len = 25;
	
	str[j][len] = '\0';
   }
}
int len1=0;
void takeinputb(unsigned key)
{
	if(key == '\r')
   {
	if(key==0)
	{
		strb[kep][len1]='\n';
		//strb[kep][len1+1]='\0';
	}
	 kep++;
	 len1=0;
	 if(kep>2)
	 {
	 takeinb();
     add=0;
	 kep=0;
	 }
     //newhighscore();
   }
   else if (key == '\b')
   {
	if (len1 <=0)
	{
      len1=0;
	}
	else{
		len1--;
	}
	strb[kep][len1] = '\0';
   }
   else{
	strb[kep][len1] = key;
	len1++;
	if(len1 > 25)
	  len1 = 25;
	
	strb[kep][len1] = '\0';
   }
}

void surebox()
{
	iSetColor(0,0,0);
	iFilledRectangle(340,400,380,100);
	iSetColor(255,255,255);
	iFilledRectangle(450,420,50,20);
	iFilledRectangle(510,420,50,20);
	iText(360,450,"Are you sure you want to return this book?",GLUT_BITMAP_HELVETICA_18);
	iSetColor(0,0,0);
	iText(455,425,"Yes",GLUT_BITMAP_HELVETICA_18);
	iText(515,425,"No",GLUT_BITMAP_HELVETICA_18);
}

int gstate = -1;
/*
	function iDraw() is called again and again by the system.

	*/
char back[200]="img\\back.bmp";
char borrow[200]="img\\borrow.bmp";
char catalog[200]="img\\catalog.bmp";
char record[20]="img\\record.bmp";
char frontimg[3][20]={"img\\frontpage.bmp","img\\catalogue.bmp","img\\logbook.bmp"};
char frnt[20]="img\\realfrrnt.bmp";
int jj;
char im[20]="img\\imm.bmp";
void iDraw() {
	//place your drawing codes here
	iClear();
	if(gstate == -1)
		{
		iShowBMP(0,0,frnt);
		}
	else if(gstate==0)
	{
		//iShowBMP(0,0,im);
		iSetColor(180,180,180);
		iFilledRectangle(0,0,1100,800);
		//iShowBMP(0,0,im);
		//iSetColor(48,213,200);
		iSetColor(168,66,45);
		iFilledRectangle(40,625,900,35);
		//iFilledRectangle(30,5,920,660);
		//iShowBMP2(750,720,anima[g],0);
		iSetColor(0,0,0);
		//iFilledRectangle(940,685,135,45);
		iText(500,680,"book catalogue",GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 45, 630, "Books name",GLUT_BITMAP_HELVETICA_18);
		iText( 405, 630, "Author name",GLUT_BITMAP_HELVETICA_18);
		iText( 705, 630, "Availability",GLUT_BITMAP_HELVETICA_18);
		//iShowBMP2(600,400,borrow,255);
		iShowBMP2(20,700,back,0); //here
		 iLine(40 ,625 ,940 ,625);
		// iLine(400,20,400,660);
		// iLine(700,660,700,20);
		// iRectangle(40,20,900,640);
		//iLine(500, 460, 500, 10);
		FILE *showcar;
		showcar = fopen("catalogue.txt","r");
		//fgets(buff[0], 100, showcar);
		jj=0;
		int i=0;
		do
		{
			fgets(sbooks[i].book ,100 , showcar);
			fgets(sbooks[i].aname ,100 , showcar);
			fgets(sbooks[i].availabily ,100 , showcar);
			jj++;
		}while(sbooks[i++].book[0]!='\0');
		fclose(showcar);
		if(page==0)
		{
		for(int i=0;i<jj-1 && i <24;i++)
		{
		if(i%2!=0)
		{
		iSetColor(218,106,95);
		iFilledRectangle(40,595-i*25,900,25);
		}
		iSetColor(0,0,0);
		iText( 45,600-i*25, sbooks[i].book,GLUT_BITMAP_HELVETICA_18);
		iText( 405,600-i*25, sbooks[i].aname,GLUT_BITMAP_HELVETICA_18);
		iText( 705,600-i*25, sbooks[i].availabily,GLUT_BITMAP_HELVETICA_18);
		iLine( 40,595-i*25, 940, 595 -i*25);
		}
		int k;
		for(k=0;k <jj-1 && k <24 ; k++)
		{
			iSetColor(0,0,0);
			iFilledRectangle( 835, 598-25*k, 100, 20);
			iSetColor(200,200,200);
			iText( 850,602-25*k,"borrow", GLUT_BITMAP_HELVETICA_18);
		}
		if (k==24)
		{
			iSetColor(0,0,0);
			iFilledRectangle(980,30,100,40);
			iSetColor(200,200,200);
			iText(990,45,"next page",GLUT_BITMAP_HELVETICA_18);
			npage=1;
		}
		}
		if(page==1)
		{
			for(int i=0;i<jj-1-24*page && i < 24 ;i++)
			{
			if(i%2!=0)
			{
			iSetColor(218,106,95);
			iFilledRectangle(40,595-i*25,900,25);
			}
			iSetColor(0,0,0);
			iText( 45,600-i*25, sbooks[i+24].book,GLUT_BITMAP_HELVETICA_18);
			iText( 405,600-i*25, sbooks[i+24].aname,GLUT_BITMAP_HELVETICA_18);
			iText( 705,600-i*25, sbooks[i+24].availabily,GLUT_BITMAP_HELVETICA_18);
			iLine( 40,595-i*25, 940, 595 -i*25);
			}
			int k;
			for(k=0;k <jj-1-24*page && k <24; k++)
			{
				iSetColor(0,0,0);
				iFilledRectangle( 835, 598-25*k, 100, 20);
				iSetColor(200,200,200);
				iText( 850,602-25*k,"borrow", GLUT_BITMAP_HELVETICA_18);
			}
			iSetColor(0,0,0);
			iFilledRectangle(960,90,130,40);
			iSetColor(200,200,200);
			iText(965,105,"previous page",GLUT_BITMAP_HELVETICA_18);
			if (k==24)
			{
			iSetColor(0,0,0);
			iFilledRectangle(980,30,100,40);
			iSetColor(200,200,200);
			iText(990,45,"next page",GLUT_BITMAP_HELVETICA_18);
			npage=2;
			}
		}
		if(page==2)
		{
			for(int i=0;i<jj-1-24*page && i <24 ;i++)
			{
			if(i%2!=0)
			{
			iSetColor(218,106,95);
			iFilledRectangle(40,595-i*25,900,25);
			}
			iSetColor(0,0,0);
			iText( 45,600-i*25, sbooks[i+24*page].book,GLUT_BITMAP_HELVETICA_18);
			iText( 405,600-i*25, sbooks[i+24*page].aname,GLUT_BITMAP_HELVETICA_18);
			iText( 705,600-i*25, sbooks[i+24*page].availabily,GLUT_BITMAP_HELVETICA_18);
			iLine( 40,595-i*25, 940, 595 -i*25);
			}
			int k;
			for(k=0;k <jj-1-24*page && k < 24 ; k++)
			{
				iSetColor(0,0,0);
				iFilledRectangle( 835, 598-25*k, 100, 20);
				iSetColor(200,200,200);
				iText( 850,602-25*k,"borrow", GLUT_BITMAP_HELVETICA_18);
			}
			iSetColor(0,0,0);
			iFilledRectangle(960,90,130,40);
			iSetColor(200,200,200);
			iText(965,105,"previous page",GLUT_BITMAP_HELVETICA_18);
			if (k==24)
			{
			iSetColor(0,0,0);
			iFilledRectangle(980,30,100,40);
			iSetColor(200,200,200);
			iText(990,45,"next page",GLUT_BITMAP_HELVETICA_18);
			npage=3;
			}
		}
		96;
		if(page==3)
		{
			for(int i=0;i<jj-1-24*page && i <24 ;i++)
			{
			if(i%2!=0)
			{
			iSetColor(218,106,95);
			iFilledRectangle(40,595-i*25,900,25);
			}
			iSetColor(0,0,0);
			iText( 45,600-i*25, sbooks[i+24*page].book,GLUT_BITMAP_HELVETICA_18);
			iText( 405,600-i*25, sbooks[i+24*page].aname,GLUT_BITMAP_HELVETICA_18);
			iText( 705,600-i*25, sbooks[i+24*page].availabily,GLUT_BITMAP_HELVETICA_18);
			iLine( 40,595-i*25, 940, 595 -i*25);
			}
			int k;
			for(k=0;k <jj-1-24*page && k < 24 ; k++)
			{
				iSetColor(0,0,0);
				iFilledRectangle( 835, 598-25*k, 100, 20);
				iSetColor(200,200,200);
				iText( 850,602-25*k,"borrow", GLUT_BITMAP_HELVETICA_18);
			}
			iSetColor(0,0,0);
			iFilledRectangle(960,90,130,40);
			iSetColor(200,200,200);
			iText(965,105,"previous page",GLUT_BITMAP_HELVETICA_18);
			if (k==24)
			{
			iSetColor(0,0,0);
			iFilledRectangle(980,30,100,40);
			iSetColor(200,200,200);
			iText(990,45,"next page",GLUT_BITMAP_HELVETICA_18);
			npage=3;
			}
		}
		//iText(950,700,"ADD BOOKS",GLUT_BITMAP_HELVETICA_18);
		if(add == 1)
		{
			ADD();
		}
		if(gmstate==1)
		{
					FILE *ptr;
					ptr = fopen("record.txt","r");
					c=0;
					int k=0;
					//for(int k =1;fgets(stds[k].name, 100, ptr) !=0;k++) 
					do
					{
						fgets(stds[k].name, 100, ptr);
						fgets(stds[k].bname,100,ptr);
						fgets(stds[k].id,100,ptr);
						fgets(stds[k].date,100,ptr);
						fgets(stds[k].av,10,ptr);
						c++;
					}while(stds[k++].name[0]!=0);
					for(int d=0;d<2205200;d++)
					{
						studentID[d]=0;
					}
					for(int z=0;z<c-1;z++)
					{
					int num=0;
						for(int d=0;stds[z].id[d+1]!=0;d++)
						{
							num=num*10 + (stds[z].id[d]-'0');
						}
						studentID[num]=studentID[num]+1;
					}
					fclose(ptr);
			int num=0,g=0;
			while(sbooks[m].availabily[g+1]!='\0') 
			{
			num = num*10 + (sbooks[m].availabily[g]- '0');
			g = g + 1;
			}
			if(num>0)
			{showchar();
			s=0;
			}
			else
			{
				s=1;
				iSetColor(0,0,0);
				iFilledRectangle(350,400,300,50);
				iSetColor(200,200,200);
				iText(360,415,"The book is out of stock",GLUT_BITMAP_HELVETICA_18);
				iSetColor(0,0,0);
				iFilledCircle(340, 460, 20, 100);
				iSetColor(255,255,255);
				iLine(330 ,470 ,350 ,450 );
				iLine(330 ,450 ,350 ,470 );iSetColor(0,0,0);
				iFilledCircle(340, 460, 20, 100);
				iSetColor(255,255,255);
				iLine(330 ,470 ,350 ,450 );
				iLine(330 ,450 ,350 ,470 );
			}
		}
		if(toomuch1==1)
		{
			toomuch();
		}
	}
	else if(gstate==1)
	{
	FILE *showcar;
		showcar = fopen("catalogue.txt","r");
		//fgets(buff[0], 100, showcar);
		jj=0;
		
		int i=0;
		do
		{
			fgets(sbooks[i].book ,100 , showcar);
			fgets(sbooks[i].aname ,100 , showcar);
			fgets(sbooks[i].availabily ,100 , showcar);
			jj++;
		}while(sbooks[i++].book[0]!='\0');
		fclose(showcar);
	iSetColor(180,180,180);
	iFilledRectangle(0,0,1100,800);
	iSetColor(168,66,45);
	iFilledRectangle(40,625,905,35);
    //BiShowBMP(0,0,record);
	iSetColor(0,0,0);
	iText(500,680,"record book log",GLUT_BITMAP_TIMES_ROMAN_24);
	// iRectangle(40,25,905,635);
	// iLine(265,660,265,25);
	// iLine(450,660,450,25);
	// iLine(715,660,715,25);
	iLine(40 ,625 ,945 ,625);
	iText(45,635,"STUDENT NAME",GLUT_BITMAP_HELVETICA_18);
	iText(270,635,"STUDENT ID",GLUT_BITMAP_HELVETICA_18);
	iText(455,635,"BOOK NAME",GLUT_BITMAP_HELVETICA_18);
	iText(720,635,"DUE DATE",GLUT_BITMAP_HELVETICA_18);
	iShowBMP2(20,700,back,0);
	FILE *ptr;
	ptr = fopen("record.txt","r");
	c=0;
	int k=0;
	//for(int k =1;fgets(stds[k].name, 100, ptr) !=0;k++) 
	do
	{
		fgets(stds[k].name, 100, ptr);
	    fgets(stds[k].bname,100,ptr);
		fgets(stds[k].id,100,ptr);
		fgets(stds[k].date,100,ptr);
		fgets(stds[k].av,10,ptr);
		c++;
	}while(stds[k++].name[0]!=0);
	if(page2==0)
	{
	for(int k=0;k<c-1 && k <24;k++)
	{
		if(k%2!=0)
		{
			iSetColor(218,116,95);
			iFilledRectangle(40,600-k*25,905,25);
		}
		iSetColor(0,0,0);
		iText(45,605-k*25,stds[k].name,GLUT_BITMAP_HELVETICA_18);
		iText(270,605-k*25,stds[k].id,GLUT_BITMAP_HELVETICA_18);
		iText(455,605-k*25,stds[k].bname,GLUT_BITMAP_HELVETICA_18);
		int sum = atoi(stds[k].date);
		time_t t2=sum;
		struct tm *due_time=localtime(&t2);
		char *ptr=asctime(due_time);
		char s[100];
		sprintf(s,"%s ",ptr);
		//sprintf(s,"%d / %d / %d", due_time->tm_mday,due_time->tm_mon+1,due_time->tm_year+1900);
		iText(720,605-k*25,s,GLUT_BITMAP_HELVETICA_18);
		iLine(40,600-k*25,945,600-k*25);
		time_t now=time(NULL);
	}
	int k =0;
	for( k=0;k<c-1 && k < 24;k++)
	{
		iSetColor(0,0,0);
		iFilledRectangle(950,605-k*25,100,20);
		iSetColor(255,255,255);
		iText(970,610-k*25,"return",GLUT_BITMAP_HELVETICA_18);
	}
	if(k==24)
	{
		iSetColor(0,0,0);
		iFilledRectangle(980,730,100,40);
		iSetColor(200,200,200);
		iText(990,745,"next page",GLUT_BITMAP_HELVETICA_18);
		nnpage=1;
	}
	}
	if(page2==1)
	{
	for(int k=0;k<c-1-24*page2 && k <24;k++)
	{
		if(k%2!=0)
		{
			iSetColor(218,116,95);
			iFilledRectangle(40,600-k*25,905,25);
		}
		iSetColor(0,0,0);
		iText(45,605-k*25,stds[k+page2*24].name,GLUT_BITMAP_HELVETICA_18);
		iText(270,605-k*25,stds[k+page2*24].id,GLUT_BITMAP_HELVETICA_18);
		iText(455,605-k*25,stds[k+page2*24].bname,GLUT_BITMAP_HELVETICA_18);
		int sum = atoi(stds[k+page2*24].date);
		time_t t2=sum;
		struct tm *due_time=localtime(&t2);
		char *ptr=asctime(due_time);
		char s[100];
		sprintf(s,"%s ",ptr);
		//sprintf(s,"%d / %d / %d", due_time->tm_mday,due_time->tm_mon+1,due_time->tm_year+1900);
		iText(720,605-k*25,s,GLUT_BITMAP_HELVETICA_18);
		iLine(40,600-k*25,945,600-k*25);
		time_t now=time(NULL);
		iLine(40,600-k*25,940,600-k*25);
	}
	iSetColor(0,0,0);
	iFilledRectangle(960,680,130,40);
	iSetColor(200,200,200);
	iText(965,695,"previous page",GLUT_BITMAP_HELVETICA_18);
	int k =0;
	for( k=0;k<c-1-24*page2 && k < 24;k++)
	{
		iSetColor(0,0,0);
		iFilledRectangle(950,605-k*25,100,20);
		iSetColor(255,255,255);
		iText(970,610-k*25,"return",GLUT_BITMAP_HELVETICA_18);
	}
	if(k==24)
	{
		iSetColor(0,0,0);
		iFilledRectangle(980,730,100,40);
		iSetColor(200,200,200);
		iText(990,745,"next page",GLUT_BITMAP_HELVETICA_18);
		nnpage=2;
	}
	}
	if(page2==2)
	{
	for(int k=0;k<c-1-24*page2 && k <24;k++)
	{
		if(k%2!=0)
		{
			iSetColor(218,116,95);
			iFilledRectangle(40,600-k*25,905,25);
		}
		iSetColor(0,0,0);
		iText(45,605-k*25,stds[k+page2*24].name,GLUT_BITMAP_HELVETICA_18);
		iText(270,605-k*25,stds[k+page2*24].id,GLUT_BITMAP_HELVETICA_18);
		iText(455,605-k*25,stds[k+page2*24].bname,GLUT_BITMAP_HELVETICA_18);
		int sum = atoi(stds[k+page2*24].date);
		time_t t2=sum;
		struct tm *due_time=localtime(&t2);
		char *ptr=asctime(due_time);
		char s[100];
		sprintf(s,"%s ",ptr);
		//sprintf(s,"%d / %d / %d", due_time->tm_mday,due_time->tm_mon+1,due_time->tm_year+1900);
		iText(720,605-k*25,s,GLUT_BITMAP_HELVETICA_18);
		iLine(40,600-k*25,945,600-k*25);
		time_t now=time(NULL);
		iLine(40,600-k*25,940,600-k*25);
	}
	iSetColor(0,0,0);
	iFilledRectangle(960,680,130,40);
	iSetColor(200,200,200);
	iText(965,695,"previous page",GLUT_BITMAP_HELVETICA_18);
	int k =0;
	for( k=0;k<c-1-24*page2 && k < 24;k++)
	{
		iSetColor(0,0,0);
		iFilledRectangle(950,605-k*25,100,20);
		iSetColor(255,255,255);
		iText(970,610-k*25,"return",GLUT_BITMAP_HELVETICA_18);
	}
	if(k==24)
	{
		iSetColor(0,0,0);
		iFilledRectangle(980,730,100,40);
		iSetColor(200,200,200);
		iText(990,745,"next page",GLUT_BITMAP_HELVETICA_18);
		nnpage=3;
	}
	}
	fclose(ptr);
	if(rusure==1)
	{
		surebox();
	}
	}
	else if(gstate==4)
	{
	iSetColor(180,180,180);
	iFilledRectangle(0,0,1100,800);
    //BiShowBMP(0,0,record);
	iSetColor(168,66,45);
	iFilledRectangle(40,625,905,35);
	iSetColor(0,0,0);
	iText(500,680,"record book log",GLUT_BITMAP_TIMES_ROMAN_24);
	// iRectangle(40,25,905,635);
	// iLine(265,660,265,25);
	// iLine(450,660,450,25);
	// iLine(715,660,715,25);
	iLine(40 ,625 ,945 ,625);
	iText(45,635,"STUDENT NAME",GLUT_BITMAP_HELVETICA_18);
	iText(270,635,"STUDENT ID",GLUT_BITMAP_HELVETICA_18);
	iText(455,635,"BOOK NAME",GLUT_BITMAP_HELVETICA_18);
	iText(720,635,"DUE DATE AND TIME",GLUT_BITMAP_HELVETICA_18);
	iText(70,750,"TODAY'S DATE:",GLUT_BITMAP_HELVETICA_18);
	time_t tt=time(NULL);
	struct tm *cur_time=localtime(&tt);
	char *ftr=asctime(cur_time);
	char d[100];
	sprintf(d,"%s",ftr);
	iText(220,750,d,GLUT_BITMAP_HELVETICA_18);
	iShowBMP2(20,700,back,0);
	FILE *ptr;
	ptr = fopen("record.txt","r");
	c=0;
	int k=0;
	//for(int k =1;fgets(stds[k].name, 100, ptr) !=0;k++) 
	do
	{
		fgets(stds[k].name, 100, ptr);
	    fgets(stds[k].bname,100,ptr);
		fgets(stds[k].id,100,ptr);
		fgets(stds[k].date,100,ptr);
		fgets(stds[k].av,10,ptr);
		c++;
	}while(stds[k++].name[0]!=0);
	if(page2==0)
	{
	int k =0;
	for(k=0;k<c-1-24*page2 && k <24;k++)
	{
		if(k%2!=0)
		{
			iSetColor(218,116,95);
			iFilledRectangle(40,600-k*25,905,25);
		}
		iSetColor(0,0,0);
		iText(45,605-k*25,stds[k].name,GLUT_BITMAP_HELVETICA_18);
		iText(270,605-k*25,stds[k].id,GLUT_BITMAP_HELVETICA_18);
		iText(455,605-k*25,stds[k].bname,GLUT_BITMAP_HELVETICA_18);
		int sum = atoi(stds[k].date);
		time_t t2=sum;
		struct tm *due_time=localtime(&t2);
		char *ptr=asctime(due_time);
		char s[100];
		sprintf(s,"%s ",ptr);
		//sprintf(s,"%d / %d / %d", due_time->tm_mday,due_time->tm_mon+1,due_time->tm_year+1900);
		iText(720,605-k*25,s,GLUT_BITMAP_HELVETICA_18);
		iLine(40,600-k*25,945,600-k*25);
		time_t now=time(NULL);
		double d=difftime(now,t2);
		if(d>0)
		{
			iSetColor(0,0,0);
			iRectangle(950,605-k*25,130,20);
			iSetColor(100,0,0);
			iFilledRectangle(950,605-k*25,130,20);
			iSetColor(200,200,200);
			if(d<=604800)
	    	iText(965,610-k*25,"100 TK fine",GLUT_BITMAP_HELVETICA_18);
			if(d>604800 && d <=2592000)
			iText(965,610-k*25,"500 TK fine",GLUT_BITMAP_HELVETICA_18);
			if(d >2592000)
			iText(965,610-k*25,"1000 TK fine",GLUT_BITMAP_HELVETICA_18);
		}
		iSetColor(0,0,0);
	}
	// int k =0;
	// for( k=0;k<c-1 && k < 24;k++)
	// {
	// 	iSetColor(0,0,0);
	// 	iFilledRectangle(950,605-k*25,100,20);
	// 	iSetColor(255,255,255);
	// 	iText(970,610-k*25,"return",GLUT_BITMAP_HELVETICA_18);
	// }
	if(k==24)
	{
		iSetColor(0,0,0);
		iFilledRectangle(980,730,100,40);
		iSetColor(200,200,200);
		iText(990,745,"next page",GLUT_BITMAP_HELVETICA_18);
		nnpage=1;
	}
	}
	if(page2==1)
	{
	int k;
	for( k=0;k<c-1-24*page2 && k <24;k++)
	{
		if(k%2!=0)
		{
			iSetColor(218,116,95);
			iFilledRectangle(40,600-k*25,905,25);
		}
		iSetColor(0,0,0);
		iText(45,605-k*25,stds[k+page2*24].name,GLUT_BITMAP_HELVETICA_18);
		iText(270,605-k*25,stds[k+page2*24].id,GLUT_BITMAP_HELVETICA_18);
		iText(455,605-k*25,stds[k+page2*24].bname,GLUT_BITMAP_HELVETICA_18);
		int sum = atoi(stds[k+page2*24].date);
		time_t t2=sum;
		struct tm *due_time=localtime(&t2);
		char *ptr=asctime(due_time);
		char s[100];
		sprintf(s,"%s ",ptr);
		//sprintf(s,"%d / %d / %d", due_time->tm_mday,due_time->tm_mon+1,due_time->tm_year+1900);
		iText(720,605-k*25,s,GLUT_BITMAP_HELVETICA_18);
		iLine(40,600-k*25,945,600-k*25);
		time_t now=time(NULL);
		double d=difftime(now,t2);
		if(d>0)
		{
			iSetColor(100,0,0);
			iFilledRectangle(950,605-k*25,130,20);
			iSetColor(200,200,200);
			if(d<=604800)
	    	iText(965,610-k*25,"100 TK fine",GLUT_BITMAP_HELVETICA_18);
			if(d>604800 && d <=2592000)
			iText(965,610-k*25,"500 TK fine",GLUT_BITMAP_HELVETICA_18);
			if(d >2592000)
			iText(965,610-k*25,"1000 TK fine",GLUT_BITMAP_HELVETICA_18);
		}
		iSetColor(0,0,0);
		iLine(40,600-k*25,940,600-k*25);
	}
	iSetColor(0,0,0);
	iFilledRectangle(960,680,130,40);
	iSetColor(200,200,200);
	iText(965,695,"previous page",GLUT_BITMAP_HELVETICA_18);
	if(k==24)
	{
		iSetColor(0,0,0);
		iFilledRectangle(980,730,100,40);
		iSetColor(200,200,200);
		iText(990,745,"next page",GLUT_BITMAP_HELVETICA_18);
		nnpage=2;
	}
	}
	if(page2==2)
	{
	int k;
	for( k=0;k<c-1-24*page2 && k <24;k++)
	{
		if(k%2!=0)
		{
			iSetColor(218,116,95);
			iFilledRectangle(40,600-k*25,905,25);
		}
		iSetColor(0,0,0);
		iText(45,605-k*25,stds[k+page2*24].name,GLUT_BITMAP_HELVETICA_18);
		iText(270,605-k*25,stds[k+page2*24].id,GLUT_BITMAP_HELVETICA_18);
		iText(455,605-k*25,stds[k+page2*24].bname,GLUT_BITMAP_HELVETICA_18);
		int sum = atoi(stds[k+page2*24].date);
		time_t t2=sum;
		struct tm *due_time=localtime(&t2);
		char *ptr=asctime(due_time);
		char s[100];
		sprintf(s,"%s ",ptr);
		//sprintf(s,"%d / %d / %d", due_time->tm_mday,due_time->tm_mon+1,due_time->tm_year+1900);
		iText(720,605-k*25,s,GLUT_BITMAP_HELVETICA_18);
		iLine(40,600-k*25,945,600-k*25);
		time_t now=time(NULL);
		double d=difftime(now,t2);
		if(d>0)
		{
			iSetColor(100,0,0);
			iFilledRectangle(950,605-k*25,130,20);
			iSetColor(200,200,200);
			if(d<=604800)
	    	iText(965,610-k*25,"100 TK fine",GLUT_BITMAP_HELVETICA_18);
			if(d>604800 && d <=2592000)
			iText(965,610-k*25,"500 TK fine",GLUT_BITMAP_HELVETICA_18);
			if(d >2592000)
			iText(965,610-k*25,"1000 TK fine",GLUT_BITMAP_HELVETICA_18);
		}
		iSetColor(0,0,0);
		iLine(40,600-k*25,940,600-k*25);
	}
	iSetColor(0,0,0);
	iFilledRectangle(960,680,130,40);
	iSetColor(200,200,200);
	iText(965,695,"previous page",GLUT_BITMAP_HELVETICA_18);
	if(k==24)
	{
		iSetColor(0,0,0);
		iFilledRectangle(980,730,100,40);
		iSetColor(200,200,200);
		iText(990,745,"next page",GLUT_BITMAP_HELVETICA_18);
		nnpage=3;
	}
	}
	fclose(ptr);
	if(rusure==1)
	{
		surebox();
	}
	}
	else if(gstate==2)
	{
		iSetColor(180,180,180);
		iFilledRectangle(0,0,1100,800);
		iFilledRectangle(30,5,920,660);
		iSetColor(168,66,45);
		iFilledRectangle(40,625,900,35);
		//iShowBMP2(750,720,anima[g],0);
		iSetColor(0,0,0);
		iFilledRectangle(940,685,135,45);
		iText(500,680,"book catalogue",GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 45, 630, "Books name",GLUT_BITMAP_HELVETICA_18);
		iText( 405, 630, "Author name",GLUT_BITMAP_HELVETICA_18);
		iText( 705, 630, "Availability",GLUT_BITMAP_HELVETICA_18);
		//iShowBMP2(600,400,borrow,255);
		iShowBMP2(20,700,back,0); //here
		 iLine(40 ,625 ,940 ,625);
		// iRectangle(40,20,900,640);
		// iLine(400,20,400,660);
		// iLine(700,660,700,20);
		// iLine(500, 460, 500, 10);
		FILE *showcar;
		showcar = fopen("catalogue.txt","r");
		jj=0;
		int i=0;
		do
		{
			fgets(sbooks[i].book ,100 , showcar);
			fgets(sbooks[i].aname ,100 , showcar);
			fgets(sbooks[i].availabily ,100 , showcar);
			jj++;
		}while(sbooks[i++].book[0]!='\0');
		fclose(showcar);
		if(page==0)
		{
		int i;
		for( i=0;i<jj-1 && i <24;i++)
		{
		if(i%2!=0)
		{
		iSetColor(218,106,95);
		iFilledRectangle(40,595-i*25,900,25);
		}
		iSetColor(0,0,0);
		iText( 45,600-i*25, sbooks[i].book,GLUT_BITMAP_HELVETICA_18);
		iText( 405,600-i*25, sbooks[i].aname,GLUT_BITMAP_HELVETICA_18);
		iText( 705,600-i*25, sbooks[i].availabily,GLUT_BITMAP_HELVETICA_18);
		iLine( 40,595-i*25, 940, 595 -i*25);
		}
		if (i==24)
		{
			iSetColor(0,0,0);
			iFilledRectangle(980,30,100,40);
			iSetColor(200,200,200);
			iText(990,45,"next page",GLUT_BITMAP_HELVETICA_18);
			npage=1;
		}
		}
		if(page==1)
		{
			int i;
			for(i=0;i<jj-1-24*page && i < 24 ;i++)
			{
			if(i%2!=0)
			{
			iSetColor(218,106,95);
			iFilledRectangle(40,595-i*25,900,25);
			}
			iSetColor(0,0,0);
			iText( 45,600-i*25, sbooks[i+24].book,GLUT_BITMAP_HELVETICA_18);
			iText( 405,600-i*25, sbooks[i+24].aname,GLUT_BITMAP_HELVETICA_18);
			iText( 705,600-i*25, sbooks[i+24].availabily,GLUT_BITMAP_HELVETICA_18);
			iLine( 40,595-i*25, 940, 595 -i*25);
			}
			iSetColor(0,0,0);
			iFilledRectangle(960,90,130,40);
			iSetColor(200,200,200);
			iText(965,105,"previous page",GLUT_BITMAP_HELVETICA_18);
			if (i==24)
			{
			iSetColor(0,0,0);
			iFilledRectangle(980,30,100,40);
			iSetColor(200,200,200);
			iText(990,45,"next page",GLUT_BITMAP_HELVETICA_18);
			npage=2;
			}
		}
		if(page==2)
		{
			int i;
			for(int i=0;i<jj-1-24*page && i <24 ;i++)
			{
			if(i%2!=0)
			{
			iSetColor(218,106,95);
			iFilledRectangle(40,595-i*25,900,25);
			}
			iSetColor(0,0,0);			
			iText( 45,600-i*25, sbooks[i+24*page].book,GLUT_BITMAP_HELVETICA_18);
			iText( 405,600-i*25, sbooks[i+24*page].aname,GLUT_BITMAP_HELVETICA_18);
			iText( 705,600-i*25, sbooks[i+24*page].availabily,GLUT_BITMAP_HELVETICA_18);
			iLine( 40,595-i*25, 940, 595 -i*25);
			}
			iSetColor(0,0,0);
			iFilledRectangle(960,90,130,40);
			iSetColor(200,200,200);
			iText(965,105,"previous page",GLUT_BITMAP_HELVETICA_18);
			if (i==24)
			{
			iSetColor(0,0,0);
			iFilledRectangle(980,30,100,40);
			iSetColor(200,200,200);
			iText(990,45,"next page",GLUT_BITMAP_HELVETICA_18);
			npage=3;
			}
		}
		iSetColor(200,200,200);
		iText(950,700,"ADD BOOKS",GLUT_BITMAP_HELVETICA_18);
		if(add == 1)
		{
			ADD();
		}
		if(gmstate==1)
		{
			showchar();
		}
	}
	else if(gstate==3)
	{
		iSetColor(180,180,180);
		iFilledRectangle(0,0,1100,800);
		iSetColor(168,66,45);
		iFilledRectangle(100,610,900,40);
		iShowBMP2(20,700,back,0);
		iSetColor(0,0,0);
		// iRectangle(100,50,900,600);
		 iLine(100,610,1000,610);
		// iLine(400,650,400,50);
		// iLine(700,650,700,50);
		iText(450,700,"Student Info",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(105,615,"Student Name", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(405,615,"Student ID", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(705,615,"No of books", GLUT_BITMAP_TIMES_ROMAN_24);
		FILE *ptr;
		ptr = fopen("record.txt","r");
		c=0;
		int k=0;
		do
		{
			fgets(stds[k].name, 100, ptr);
			fgets(stds[k].bname,100,ptr);
			fgets(stds[k].id,100,ptr);
			fgets(stds[k].date,100,ptr);
			fgets(stds[k].av,10,ptr);
			c++;
		}while(stds[k++].name[0]!=0);
		for(int d=0;d<2205200;d++)
		{
			studentID[d]=0;
		}
		for(int z=0;z<c-1;z++)
		{
			int num=0;
			for(int d=0;stds[z].id[d+1]!=0;d++)
			{
				num=num*10 + (stds[z].id[d]-'0');
			}
			studentID[num]=studentID[num]+1;
		}
		fclose(ptr);
		int f=0,count1=0;
		for(int j=0; j<2205200;j++)
		{		
				if(studentID[j]>0)
				{
					count1++;
					if(page3==0)
					{
					for(int g=0;g<c-1;g++)
					{
						//iText(50+g*100,50,"yo",GLUT_BITMAP_TIMES_ROMAN_24);
						int num=0;
						for(int d=0;stds[g].id[d+1]!=0;d++)
						{
							num=num*10 + (stds[g].id[d]-'0');
						}
						if(num==j)
						{
							if(f%2!=0)
							{
								iSetColor(218,116,95);
								iFilledRectangle(100,585-f*25,900,25);
							}
							iSetColor(0,0,0);
							iText(105,590-f*25,stds[g].name,GLUT_BITMAP_HELVETICA_18);
							iText(405,590-f*25,stds[g].id,GLUT_BITMAP_HELVETICA_18);
							char noofbooks[100]={0};
							int v=0;
							while (studentID[j])
							{
								int rem=studentID[j]%10;
								noofbooks[v]=rem+'0';
								v++;
								studentID[j]/=10;
							}
							noofbooks[v+1]='\0';
							for(int v=0;v<strlen(noofbooks)/2;v++)
							{
								int temp=noofbooks[v];
								noofbooks[v]=noofbooks[strlen(noofbooks)-v-1];
								noofbooks[strlen(noofbooks)-v-1]=temp;
							}
							iText(705,590-f*25,noofbooks,GLUT_BITMAP_HELVETICA_18);
							iLine(100,585-f*25,1000,585-f*25);
							//iText(105,615,stds[g].,GLUT_BITMAP_TIMES_ROMAN_24);
							f++;
							break;
						}
					}
					if(count1>=24)
					{
						npage3=1;
						iSetColor(0,0,0);
						iFilledRectangle(980,730,100,40);
						iSetColor(200,200,200);
						iText(990,745,"next page",GLUT_BITMAP_HELVETICA_18);
					}
					}
					if(page3==1)
					{
					for(int g=0;g<c-1;g++)
					{
						//iText(50+g*100,50,"yo",GLUT_BITMAP_TIMES_ROMAN_24);
						int num=0;
						for(int d=0;stds[g].id[d+1]!=0;d++)
						{
							num=num*10 + (stds[g].id[d]-'0');
						}
						if(num==j)
						{
							if(f%2!=0 && f>=24*page3)
							{
								iSetColor(218,116,95);
								iFilledRectangle(100,585-(f-24)*25,900,25);
							}
							if(f>=24)
							{
							iSetColor(0,0,0);
							iText(105,590-(f-24*page3)*25,stds[g].name,GLUT_BITMAP_HELVETICA_18);
							iText(405,590-(f-24*page3)*25,stds[g].id,GLUT_BITMAP_HELVETICA_18);
							}
							char noofbooks[100]={0};
							int v=0;
							while (studentID[j])
							{
								int rem=studentID[j]%10;
								noofbooks[v]=rem+'0';
								v++;
								studentID[j]/=10;
							}
							noofbooks[v+1]='\0';
							for(int v=0;v<strlen(noofbooks)/2;v++)
							{
								int temp=noofbooks[v];
								noofbooks[v]=noofbooks[strlen(noofbooks)-v-1];
								noofbooks[strlen(noofbooks)-v-1]=temp;
							}
							if(f>=24)
							{
							iText(705,590-(f-24*page3)*25,noofbooks,GLUT_BITMAP_HELVETICA_18);
							iLine(100,585-(f-24*page3)*25,1000,585-(f-24*page3)*25);
							}
							//iText(105,615,stds[g].,GLUT_BITMAP_TIMES_ROMAN_24);
							f++;
							break;
						}
						
					}
					iSetColor(0,0,0);
					iFilledRectangle(960,680,130,40);
					iSetColor(200,200,200);
					iText(965,695,"previous page",GLUT_BITMAP_HELVETICA_18);
					if(count1>48)
					{
						npage3=2;
						iSetColor(0,0,0);
						iFilledRectangle(980,730,100,40);
						iSetColor(200,200,200);
						iText(990,745,"next page",GLUT_BITMAP_HELVETICA_18);
					}
					}
					if(page3==2)
					{
					for(int g=0;g<c-1;g++)
					{
						//iText(50+g*100,50,"yo",GLUT_BITMAP_TIMES_ROMAN_24);
						int num=0;
						for(int d=0;stds[g].id[d+1]!=0;d++)
						{
							num=num*10 + (stds[g].id[d]-'0');
						}
						if(num==j)
						{
							if(f%2!=0 && f>=24*page3)
							{
								iSetColor(218,116,95);
								iFilledRectangle(100,585-(f-24)*25,900,25);
							}
							if(f>=24*page3)
							{
							iSetColor(0,0,0);
							iText(105,590-(f-24*page3)*25,stds[g].name,GLUT_BITMAP_HELVETICA_18);
							iText(405,590-(f-24*page3)*25,stds[g].id,GLUT_BITMAP_HELVETICA_18);
							}
							char noofbooks[100]={0};
							int v=0;
							while (studentID[j])
							{
								int rem=studentID[j]%10;
								noofbooks[v]=rem+'0';
								v++;
								studentID[j]/=10;
							}
							noofbooks[v+1]='\0';
							for(int v=0;v<strlen(noofbooks)/2;v++)
							{
								int temp=noofbooks[v];
								noofbooks[v]=noofbooks[strlen(noofbooks)-v-1];
								noofbooks[strlen(noofbooks)-v-1]=temp;
							}
							if(f>=24*page3)
							{
							iText(705,590-(f-24*page3)*25,noofbooks,GLUT_BITMAP_HELVETICA_18);
							iLine(100,585-(f-24*page3)*25,1000,585-(f-24*page3)*25);
							}
							//iText(105,615,stds[g].,GLUT_BITMAP_TIMES_ROMAN_24);
							f++;
							break;
						}
						
					}
					iSetColor(0,0,0);
					iFilledRectangle(960,680,130,40);
					iSetColor(200,200,200);
					iText(965,695,"previous page",GLUT_BITMAP_HELVETICA_18);
					if(count1>72)
					{
						npage3=3;
						iSetColor(0,0,0);
						iFilledRectangle(980,730,100,40);
						iSetColor(200,200,200);
						iText(990,745,"next page",GLUT_BITMAP_HELVETICA_18);
					}
					}
				}
		}
		// if(f>23)
		// {
		// 	another_page=1;
		// 	iSetColor(0,0,0);
		// 	iFilledRectangle(980,30,100,40);
		// 	iSetColor(200,200,200);
		// 	iText(990,45,"next page",GLUT_BITMAP_HELVETICA_18);
		// }
	}
	else if(gstate==5)
	{
		iShowBMP(0,0,im);
		iShowBMP2(20,700,back,0);
		// iSetColor(65,42,42);
		// iFilledRectangle(330,80,500,600);
		// iSetColor(0,0,0);
		// iText(340,620,"A student can borrow a maximum of 3 books.",GLUT_BITMAP_HELVETICA_18);
		// iText(340,600,"The student who borrowed a book has to return it within a week.",GLUT_BITMAP_HELVETICA_18);
		// iText(340,580,"If not return within a week he/she will be fined.",GLUT_BITMAP_HELVETICA_18);
		// iText(340,560,"fine is 100 tk over a week,500 tk over 2 weeks and 1000 tk for more than 1 month.",GLUT_BITMAP_HELVETICA_18);
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void music()
{
	PlaySound("music\\music2.wav",NULL, SND_LOOP);
}
void iMouseMove(int mx, int my) {
	//printf("x = %d, y= %d\n",mx,my);
	//x=mx;
	//y=my;
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		if(gstate==-1 && mx>=64 && mx<=250 && my>=283 && my<=325)
		{
			//music();
			gstate=1;
		}
		if (gstate == -1 && mx >=64 && mx <= 172 && my >= 666 && my <= 710)
		{
			//music();
			gstate=2;
		}
		if(gstate==-1 && mx>=64 && mx<=253 && my>=571 && my<=612)
		{
			//music();
			gstate=0;
		}
		if (gstate==-1 && mx >=64 && mx <= 200 && my >=470 && my<= 517)
		{
			//music();
			gstate=3;
		}
		if(gstate==-1 && mx>=64 && mx<=176 && my>=379 && my<=421)
		{
			//music();
			gstate=4;
		}
		if(gstate==-1 && mx>=64 && mx<=166 && my>=188 && my<=229)
		{
			gstate=5;
			//music();
		}
		if(gstate==-1 && mx>=64 && mx<=144 && my>=91 && my<=133)
		{
			exit(1);
		}
		//x = mx;
		//y = my;
		if(gstate==0||gstate==1||gstate==2||gstate==3||gstate==4||gstate==5)
		{
			if(mx>=20 && mx<=70 && my>=700 && my <=750)
			{
				gstate=-1;
				gmstate=0;
				add=0;
				page=0;
				page2=0;
				page3=0;
				s=0;
				//music();
			}
			// if(gstate==0 && mx>=600 && mx<=680 && my >= 400 && my <= 450)
			// {
			// 	gmstate=1;
			// }
			for(int i=0;i<jj-1 && i <24;i++)
			{
				if(gstate==0 && s==0 && mx>=835 && mx<=935 && my >= 598-25*i && my <= 598-25*i+20)
				{
					strcpy(str[0],"Student name");
					strcpy(str[1],"student ID");
					strcpy(str[2],"dd/mm/yyyy");
					click=0;
					gmstate=1;
					m=i+page * 24;
					len=0;
				}
			}
			if(gmstate==1)
			{
				if(mx>= 499 && mx<=854 && my >=357 && my <= 378)
					{
						click=1;
						strcpy(str[0],"");
						j=0;
						//strcpy(str[1],"");
					}
			}
			if(gmstate==1 && mx>= 324 && mx<= 352 && my >= 449 && my<= 473)
			{
				gmstate=0;
				s=0;
			}
			if(gstate==2 && mx >=940 && mx <=940+135 && my >= 685 && my <=685+45)
			{
				add=1;
				len1=0;
			}
			if(add==1 && mx>= 324 && mx<= 352 && my >= 449 && my<= 473)
			{
				add=0;
				strcpy(strb[0],"");
				strcpy(strb[1],"");
				strcpy(strb[2],"");
				kep=0;
			}
			for(int j=0;j<c-1;j++)
			{
			if(gstate==1 && mx >=951 && mx <= 1049 && my >= 608-j*25 && my <=625-j*25)  ///hre
			{
				rw=j+page2*24;
				rusure=1;
				//rewrite();
			}
			}
			if (rusure==1 && gstate == 1)
			{
				if (mx >= 510 && mx <= 560 && my >= 421 && my <= 440)
				{
					rusure=0;
				}
				if(mx >= 450 && mx <= 500 && my >=421 && my <= 440)
				{
					rewrite();
					rusure=0;
				}
				
			}
			if(toomuch1==1 && mx>= 324 && mx<= 352 && my >= 449 && my<= 473)
			{
				toomuch1=0;
			}
			if(npage==1 && mx >= 980 && mx <=1080 && my >= 30 && my <= 70)
			{
				page=1;
				npage=0;
			}
			if(page==1 && mx >= 960 && mx <= 1090 && my >= 90 && my <= 130)
			{
				page=0;
			}
			if(npage==2 &&mx >= 980 && mx <=1080 && my >= 30 && my <= 70)
			{
				page=2;
				npage=0;
			}
			if(page==2 && mx >= 960 && mx <= 1090 && my >= 90 && my <= 130)
			{
				page=1;
			}


			if(nnpage ==1 && mx >= 980 && mx <= 1080 && my >= 730 && my <= 770)
			{
				page2=1;
				nnpage=0;
			}
			if(page2==1 && mx >= 960 && mx <= 1090 && my >= 680 && my <= 720)
			{
				page2=0;
			}
			if(nnpage ==2 && mx >= 980 && mx <= 1080 && my >= 730 && my <= 770)
			{
				page2=2;
				nnpage=0;
			}
			if(page2==2 && mx >= 960 && mx <= 1090 && my >= 680 && my <= 720)
			{
				page2=1;
			}

			if(npage3 ==1 && mx >= 980 && mx <= 1080 && my >= 730 && my <= 770)
			{
				page3=1;
				npage3=0;
			}
			if(page3==1 && mx >= 960 && mx <= 1090 && my >= 680 && my <= 720)
			{
				page3=0;
			}
			if(npage3 ==2 && mx >= 980 && mx <= 1080 && my >= 730 && my <= 770)
			{
				page3=2;
				npage3=0;
			}
			if(page3==2 && mx >= 960 && mx <= 1090 && my >= 680 && my <= 720)
			{
				page3=1;
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
	}
	
}

void animation()
{
	//iShowBMP2(400,400,anima[g],0);
	g++;
	if(g==6)
	{
		g=0;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if(gmstate==1 && click==1)
	{
		takeinput(key);
	}
	if (key == 'q') {
		//exit(0);
	}
	if(add == 1)
	{
		//len1 = 0;
		takeinputb(key);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	if(key == GLUT_KEY_DOWN)
	{
		if(musicON)
		{
			musicON=false;
			PlaySound(0,0,0);
		}
		else
		{
			musicON=true;
			PlaySound("music\\music1.wav",NULL, SND_LOOP | SND_ASYNC);
		}
	}

}
int main() {
	if(musicON)
	{
		PlaySound("music\\music1.wav",NULL,SND_LOOP | SND_ASYNC);
	}
	//place your own initialization codes here.
	iInitialize(screenwidth, screenheight, "bismillah");
	return 0;
}