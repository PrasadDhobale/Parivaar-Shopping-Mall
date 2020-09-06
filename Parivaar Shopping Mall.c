/*  Program By : 
				Prasad Dhobale.
				9067404012
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	
	char un[15],passwd[15],cus[15],em[30];
	struct node *addr;
	long long int m;
}*temp,*start,*curr;

struct bill{
	char Pname[50];
	int Pid;
	int Pprice,B;
	float gst;
	struct bill *addr1;
	
}*b,*temp1,*start1,*curr1;


void Admin();
void user();

void padded();
int Login(char[],char[]);
void Create(char[],char[],char[],char[],long long int);
int display();
int Bill(int,char[],int,int,float);
int display1();
int main()
{
	int c;
	char ch,u[15],p[15];
	do{
		system("cls");  
		printf("\n\t\t\t\t	--{{ PARIVAR SHOPPING MART }}--\t");
		printf("\n\t**_______________________________________________________________________________________________**");
		printf("\n\n\t\t	New Agriculture College Building ,Shivaji Nagar Ascent Mall, \n\t\t  		University Road Opp,Pune, Maharashtra-411007\t");
		printf("\n\t**_______________________________________________________________________________________________**");
		printf("\n\n\t\t	     _________\t\t\t	     	     ________");
		printf("\n\t\t\t1 -  [ Admin ]	\t\t\t	2 -  [ User ] ");
		printf("\n\t\t\t     ---------				     	     --------");
		printf("\n\n\t\t\t\t\t\tEnter Your Role : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\n\t\t\tEnter Username : ");
				scanf("%s",u);
				printf("\n\t\t\tEnter Password : ");
				scanf("%s",p);
				if(strcmp(u,"PraMayu")==0&&strcmp(p,"PraMay")==0)
				{
					Admin();
				}
				else
				{
					printf("\n\t\t**** Incorrect Username Or Password ****");
				}
				break;
			case 2:
				user();
				break;
			default:
				printf("\n\n\t\t\t**** Invalid Choice ****");
		}
		printf("\n\n\n\t\t\tDo You Want to Continue To Home Page... Press P : ");
		scanf("%s",&ch);
	}while(ch=='P'||ch=='p');
	return 0;
}
int Bill(int ch,char pname[10],int pprice,int qty,float g)
{
	b=malloc(sizeof(struct bill));
	b->Pid=ch;
	strcpy(b->Pname,pname);
	b->Pprice=pprice;
	b->B=qty;
	b->gst=g;
	b->addr1=NULL;
	if(start1==NULL)
	{
		start1=b;
	}
	else
	{
		curr1=start1;
		while(curr1->addr1!=NULL)
		{
			curr1=curr1->addr1;
		}
		curr1->addr1=b;
	}
}
int Login(char uname[15],char pass[15])
{
	int cnt=0;
	int flag=0;
	if(start==NULL)
	{
		printf("\n\tDatabase Empty.......");
	}
	else
	{
		curr=start;
		while(curr!=NULL)
		{
			cnt++;
			flag=0;
			if(strcmp(curr->un,uname)==0)
			{
				if(strcmp(curr->passwd,pass)==0)
				{
					flag=cnt;
					break;
				}
				else
					printf("\n\tPassword Incorrect....");
			}
			else
			{
				printf("\n\tUsername Incorrect.....");
			}
			curr=curr->addr;
		}		
	}
	return flag;
}
void Create(char cname[15],char uname[15],char pass[15],char cpass[30],long long int mn)
{
	temp=malloc(sizeof(struct node));
	strcpy(temp->un,uname);
	strcpy(temp->passwd,pass);
	strcpy(temp->cus,cname);
	strcpy(temp->em,cpass);
	temp->m=mn;
		
	temp->addr=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		curr=start;
		while(curr->addr!=NULL)
		{
			curr=curr->addr;
		}
		curr->addr=temp;
	}
	printf("\n\n\t\t....Account Created Successfully  !!!!\n\n");
}
int display()
{
	if(start==NULL)
	{
		printf("\n\n\t\t\t**** Sorry !!!Database is Empty.Because We Still Don't Have Any Customer ******");
	}
	else
	{
		curr=start;
		printf("\n\n\t\t\t\t**** Customer Details *****");
		while(curr!=NULL)
		{
			printf("\n\n\t\t*******************************************************\n");
			printf("\n\t\t\tCustomer Name\t:\t%s",curr->cus);
			printf("\n\n\t\t\tE-Mail ID\t:\t%s",curr->em);
			printf("\n\n\t\t\tUsername\t:\t%s",curr->un);
			printf("\n\n\t\t\tPassword\t:\t%s",curr->passwd);
			printf("\n\n\t\t\tMobile Number\t:\t%lld",curr->m);
			printf("\n\t\t_________________________________________________________");
			curr=curr->addr;
		}	
	}
	return 0;
}
int display1()
{
	float Total=0,Ftotal=0,GST=0;
	
	if(start1==NULL)
	{
		printf("\n\n\n\t\t\t*** Product Not Added Yet .... ***");
	}
	else
	{
		system("cls");
		curr1=start1;
		printf("\n\t\t\t\t  __________________________");
		printf("\n\n\t\t*****************|| PARIVAR SHOPPING MART ||******************");
		printf("\n\t\t\t\t  __________________________");
		printf("\n\t\tNew Agriculture College Building ,Shivaji Nagar Ascent Mall, \n\t\t  	University Road Opp,Pune, Maharashtra-411007\t");
		printf("\n\n\t\t\t** Customer Name | Mr. / Mrs. :- %s **",curr->cus);
		printf("\n|______________________________________________________________________________________________________");
		printf("\n|    												       |\n|	Product ID\tProduct Name\t	Product Price\t G.S.T \t Prod Quantity\t Total Price   ");
		printf("\n|______________________________________________________________________________________________________|");
		while(curr1!=NULL)
		{
			
			GST=(curr1->gst/100)*curr1->Pprice;			
			Total=(float)curr1->Pprice * curr1->B+GST;
			Ftotal=(float)Ftotal+Total;
			printf("\n|\t %d\t\t %s\t\t %d\t\t %.1f%% %\t    %d\t\t  %.2f\t",curr1->Pid,curr1->Pname,curr1->Pprice,curr1->gst,curr1->B,Total);
			curr1=curr1->addr1;			
		}
		printf("\n|______________________________________________________________________________________________________|");
		printf("\n\n\t\t\t\t\t\t\t\t\t| Final Total  | :  %.2f",Ftotal);
		printf("\n\n\n\t-----------------------------------------------------------------------------------");
		printf("\n\t\t*NOTE*    : You Will Lost Your Shopping Data If You Logged Out  ");
		printf("\n\t----------------------------------------------------------------------------------");
	}	
	printf("\n\n\n\t\t\t======**T H A N K     Y O U , V I S I T    A G A I N**======");
	
	return 0;
}
void padded()
{
	printf("\n\t\t....Product Added To Cart Successfully !!!!\n");
}
void user()
{
	int ch,flag=0;
	long long int mn;
	float g;
	int b=0,b2=0,b3=0,b4=0,b5=0;
	char cname[15];
	char uname[15],pass[15],cpass[30];
	char usern[15],pas[15],cho;
	int pprice,pid;
	char pname[10];
	do{
		start1=NULL;
		system ("cls");
		printf("\n\t\t\t\t\t                      /*");
		printf("\n\t\t\t\t\t\t     ________/") ;
		printf("\n\t\t\t\t\t\t    |   P   /\t");
		printf("\n\t\t\t\t\t[ PARIVAR   |   M  /\tMARKET ]");
		printf("\n\t\t\t\t\t\t    |_____/\t");
		printf("\n\t\t\t\t\t\t    *    *");
		
		printf("\n\n\t\t|----------------* WELCOME TO OUR SHOPPING MART *---------------|");
		printf("\n                |                                                               |");
		printf("\n\t\t|\t\t\t1 : Register                            |");
		printf("\n\t\t|\t\t\t2 : Login                               |");		
		printf("\n\t\t|---------------------------------------------------------------|");	//display  Is Only for Admin......
		printf("\n\t\tEnter Your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n\tEnter Your Name : ");
				scanf("%s",cname);
				printf("\n\tEnter Username : ");
				scanf("%s",uname);
				printf("\n\tCreate Password : ");
				scanf("%s",pass);
				printf("\n\tEnter E-Mail ID : ");
				scanf("%s",cpass);
				printf("\n\tEnter Your Mobile Number : ");
				scanf("%lld",&mn);
				Create(cname,uname,pass,cpass,mn);
				break;
			case 2:
				printf("\n\tEnter Registered Username : ");
				scanf("%s",&uname);
				printf("\n\n\tEnter Registered Password : ");
				scanf("%s",&pass);
				
				flag=Login(uname,pass);
						
				if(flag>0)
				{
					
					
					do{
						system("cls");
						printf("\n\t\t\t******** WEL-COME | Mr. / Mrs. : %s **********\n",curr->cus);
						printf("\n\t\t|-------------------*O U R     P R O D U C T S*-----------------|");
						printf("\n\t\t|\t\t\t*1 - Books				|	\n\t\t|\t\t\t*2 - Mobiles		 		|		\n\t\t|\t\t\t*3 - Electronics	  		|\n\t\t|\t\t\t*4 - Laptops				|\n\t\t|\t\t\t*5 - Groceries				|");
						printf("\n\t\t|---------------------------------------------------------------|");
						printf("\n\n\tEnter the Category In Which You Want To Shopping : ")	;
						scanf("%d",&ch);
						switch(ch)
						{
							case 1:
					    		do{
									system ("cls");
									printf("\n\t\t~~~ Books Name With Price ~~~");
									printf("\n\n\t| Book.ID  |\t| Books Name |\t\t| Book Price |");
									printf("\n|---------------------------------------------------------------------------|");
									printf("\n\t  101-\t\tThe Winter\t:\t 	200");
									printf("\n\t  201-\t\tHonestness\t:\t 	250");
									printf("\n\t  301-\t\tBelieve Me\t:\t 	300");
									printf("\n\t  401-\t\tThe Sniper\t:\t 	450");
									printf("\n\t  501-\t\tI Never..\t:\t 	500");
									printf("\n|---------------------------------------------------------------------------|");
									printf("\n\n\tEnter Book ID : ");	
									scanf("%d",&ch);
									switch(ch)
									{
										case 101:
											printf("\n\tEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"The Winter");
				 							pprice=200;
				 							g=4.4;
											Bill(ch,pname,pprice,b,g);
											break;
										case 201:
											printf("\n\tEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Honestness");
				 							pprice=250;
				 							g=4.7;				 							
											Bill(ch,pname,pprice,b,g);
											break;
										case 301:
											printf("\n\tEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Believe Me");
				 							pprice=300;
				 							g=3.4;
											Bill(ch,pname,pprice,b,g);
											break;
										case 401:
											printf("\n\tEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"The Sniper");
				 							pprice=450;
				 							g=3.8;
											Bill(ch,pname,pprice,b,g);
											break;
										case 501:
											printf("\n\tEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"I Never...");
				 							pprice=500;
				 							g=2.9;
											Bill(ch,pname,pprice,b,g);
											break;											
										default:
											printf("\n\t\t....Invalid Choice....");
									}
									printf("\n\tIf You Want to Purchase More Books.. Press B : ");
									scanf("%s",&cho);
								}while(cho=='b'||cho=='B');
								break;
							case 2:									
								do{
									system("cls");																	
									printf("\n\t\t ~~~~~ Brand Name With Price ~~~~~\n");
									printf("\n\t  | Mobile ID |\t	| Mobile Name |\t\t	| Mobile Price |");
									printf("\n\t|-----------------------------------------------------------------------------|");	
									printf("\n\t	411-\t\tSamsang Galaxy S10\t:\t	70000");
									printf("\n\t	412-\t\tRedmi Note 9\t	:\t	20000");
									printf("\n\t	413-\t\tVivo Y70 Pro\t	:\t	25000");
									printf("\n\t	414-\t\tOppo A7\t\t	:\t	10000");
									printf("\n\t	415-\t\tApple F11 Pro\t	:\t	99000");
									printf("\n\t|-----------------------------------------------------------------------------|");	
									
									printf("\n\tEnter Mobile ID : ");
									scanf("%d",&ch);
									switch(ch)
									{
										case 411:
											printf("\n\tEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Samsang S10");
				 							pprice=70000;
				 							g=9.5;
											Bill(ch,pname,pprice,b,g);
											break;
										case 412:
											printf("\n\tEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Redmi Note 9");
				 							pprice=20000;
				 							g=7.2;
											Bill(ch,pname,pprice,b,g);
											break;
										case 413:
											printf("\n\tEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Vivo Y70 Pro");
				 							pprice=25000;
				 							g=8.3;
											Bill(ch,pname,pprice,b,g);
											break;
										case 414:
											printf("\n\tEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Oppo A7 ");
				 							pprice=10000;
				 							g=6.9;
											Bill(ch,pname,pprice,b,g);
											break;
										case 415:
											printf("\n\tEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Apple F11 Pro");
				 							pprice=99000;
				 							g=9.3;
											Bill(ch,pname,pprice,b,g);
											break;
										default:
											printf("\n\t\t....Invalid Option.....");
									}
									printf("\n\tIf You Want To Purchase More Mobile.... Press M : ");
									scanf("%s",&cho);
								}while(cho=='m'||cho=='M');					
								break;
							case 3: 								
								do
								{
									system("cls");
									printf("\n\t\t\t\t ~~~ Electronics with prices ~~~\n");
									printf("\n\t  | Product.ID  |\t	| Product Name |\t |  Price |");
									printf("\n\t|-----------------------------------------------------------------------------|");
									printf("\n\t\t 142 -\t\t\tRecorders\t\t:\t750");
									printf("\n\t\t 143 -\t\t\tConditioner\t\t:\t20,000");
									printf("\n\t\t 144 -\t\t\tDVD Players\t\t:\t1500");
									printf("\n\t\t 145 -\t\t\tMP3 Players\t\t:\t780");
									printf("\n\t\t 146 -\t\t\tRefrigerator\t\t:\t30,000");
									printf("\n\t\t 147 -\t\t\tSound System\t\t:\t15,000");
									printf("\n\t|-----------------------------------------------------------------------------|");	
									printf("\n\n\tEnter Product ID : ");	
									scanf("%d",&ch);
									switch(ch)
									{
										case 142:
											printf("\nEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Recorders");
				 							pprice=750;
				 							g=2.3;
											Bill(ch,pname,pprice,b,g);
										break;
										case 143:
											printf("\nEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Conditioners");
				 							pprice=20000;
				 							g=4.1;
											Bill(ch,pname,pprice,b,g);
										break;
										case 144:
											printf("\nEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"DVD Players");
				 							pprice=1500;
				 							g=5.3;
											Bill(ch,pname,pprice,b,g);
										break;
										case 145:
											printf("\nEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"MP3 Players");
				 							pprice=780;
				 							g=4.5;
											Bill(ch,pname,pprice,b,g);
										break;
										case 146:
											printf("\nEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Refrigerators");
				 							pprice=30000;
				 							g=3.7;
											Bill(ch,pname,pprice,b,g);
										break;
										case 147:
											printf("\nEnter Quantity : ");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Sound System");
				 							pprice=500;
				 							g=4.2;
											Bill(ch,pname,pprice,b,g);
										break;
										default:
											printf("\n\t\t....Invalid Choice....");
										}
										printf("\nIf You Want to Purchase More Electronics Equipments.. Press E : ");
									scanf("%s",&cho);							
								}while(cho=='e'||cho=='E');
								break;
							case 4:
								do{					
									system("cls");		
									printf("\n\t\t\t\t ~~~ Laptops with price ~~~\t");
									printf("\n\n\t| Item.ID  |\t\t | Item Name |\t\t\t| Price |");
									printf("\n\t|-----------------------------------------------------------------------|");
									printf("\n\t  620    - 	\t Lenovo V130\t\t:\t40,000");
									printf("\n\t  621    - 	\t DELL-XPS\t\t:\t50,000");
									printf("\n\t  622    - 	\t SONY VAIO\t\t:\t45,000");
									printf("\n\t  623    - 	\t Apple Macbook\t\t:\t75,000");
									printf("\n\t  624    - 	\t Acer SlimNOTE\t\t:\t54,000");
									printf("\n\t  625    - 	\t HP Pavillion\t\t:\t35,000");
									printf("\n\t|-----------------------------------------------------------------------|");
									printf("\n\n\tEnter Laptop ID :");
									scanf("%d",&ch);
									switch(ch){
											case 620:
												printf("\n\tEnter Quantity : ");
												scanf("%d",&b);
												padded();
												strcpy(pname,"Lenovo	");
				 								pprice=40000;
				 								g=5.5;
												Bill(ch,pname,pprice,b,g);
												break;
											case 621:
												printf("\n\tEnter Quantity : ");
												scanf("%d",&b);
												padded();
												strcpy(pname,"DELL-XPS");
					 							pprice=50000;
					 							g=6.6;
												Bill(ch,pname,pprice,b,g);
												break;
											case 622:
												printf("\n\tEnter Quantity : ");
												scanf("%d",&b);
												padded();
												strcpy(pname,"SONY VAIO");
				 								pprice=45000;
				 								g=7.3;				 								
												Bill(ch,pname,pprice,b,g);
												break;
											case 623:
												printf("\n\tEnter Quantity : ");
												scanf("%d",&b);
												padded();
												strcpy(pname,"Apple Macbook");
					 							pprice=75000;
					 							g=7.7;
												Bill(ch,pname,pprice,b,g);
												break;
											case 624:
												printf("\n\tEnter Quantity : ");
												scanf("%d",&b);
												padded();
												strcpy(pname,"Acer SlimNote");
				 								pprice=54000;
				 								g=5.8;
												Bill(ch,pname,pprice,b,g);
												break;
											case 625:
												printf("\n\tEnter Quantity : ");
												scanf("%d",&b);
												padded();
												strcpy(pname,"HP Pavillion");
					 							pprice=35000;
					 							g=6.2;
												Bill(ch,pname,pprice,b,g);
												break;
											default:
												printf("\n\t\t....Invalid Choice.....");
											}
										
										printf("\nIf You Want to Purchase More Laptops.. Press L : ");
										scanf("%s",&cho);							
									}while(cho=='l'||cho=='L');
								break;
							case 5:
								do{
									system("cls");	
									printf("\n\t\t\t ~~~~~~~ Grocery items with price ~~~~~~\n");
									printf("\n\t\t| Item.ID  |\t\t| Item Name |\t\t| Price |");
									printf("\n\t|-----------------------------------------------------------------------|");
									printf("\n\t\t 132 -\t\t\t Kechup\t\t :\t  80");
									printf("\n\t\t 133 -\t\t\t Bread\t\t : \t  70");
									printf("\n\t\t 134 -\t\t\t Cheese\t\t :\t  90");
									printf("\n\t\t 135 -\t\t\t Milk\t\t :\t  75");
									printf("\n\t\t 136 -\t\t\t Rice\t\t : \t  65");
									printf("\n\t|-----------------------------------------------------------------------|");
									printf("\n\n\tEnter Item ID :  ");
									scanf("%d",&ch);
									switch(ch)
									{
										case 132:											
											printf("\n\tEnter Quantity :");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Kechup	");
											pprice=80;
											g=2.3;
											Bill(ch,pname,pprice,b,g);								
											break;
										case 133:
											printf("\n\tEnter Quantity :");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Bread	");
											pprice=70;
											g=3.3;
											Bill(ch,pname,pprice,b,g);
											break;
										case 134:
											printf("\n\tEnter Quantity :");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Cheese	");
											pprice=90;
											g=2.7;
											Bill(ch,pname,pprice,b,g);
											break;
										case 135:
											printf("\n\tEnter Quantity :");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Milk	");
											pprice=75;
											g=2.9;
											Bill(ch,pname,pprice,b,g);
											break;
										case 136:
											printf("\n\tEnter Quantity :");
											scanf("%d",&b);
											padded();
											strcpy(pname,"Rice	");
											pprice=65;
											g=2.5;
											Bill(ch,pname,pprice,b,g);
											break;											
										default :
											printf("\n\t\t....Invaid choice......");
									}
									printf("\n\tIf You Want To Purchase More Grocery..Press G : ");
									scanf("%s",&cho);
								}while(cho=='G'||cho=='g');
								break;							
							default:
								printf("\n\t\t________Invalid________");
						}			
						display1();
						printf("\n\n\tIf You Want to Continue Shopping to Main ...Press Y : ");
						scanf("%s",&cho);
					}while(cho=='y'||cho=='Y');
					printf("\n\n\t\t\t***** Logged Out Successfully....!!!!! *****");
				}
				else
				{
					printf("\n\n\t\t\t** ..Sorry !! Account Not Found.. **");
				}
				break;			
			default:
				printf("\n\n\t\tInvalid choice......");
		}
		printf("\n\n\t\tIf You Want To Shopping In Our Main Category... Press 1 : ");
		scanf("%d",&ch);
	}while(ch==1);
}
void Admin()
{
	system("cls");
	display();
}
