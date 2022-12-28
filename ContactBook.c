#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void diary();
void phonebook();
int calendar();
int yearcalendar();
int monbymon();
int dfd();
void add_diary();
void add_contact();
void search_diary();
void search_contact();
void delete_diary();
void delete_contact();
void view_all_diaries();
void view_all_contact();
int infomem();



int main()
{
int a;
start:
system("cls");
system("color FC");
printf("\t\t\t\t\t    H9 PSAP COURSE PROJECT\t\t\t\n\n\n");
printf("\t1. Diary\n\n");
printf("\t2. Phonebook\n\n");
printf("\t3. Calendar\n\n");
printf("\t4. Information about members of group\n\n");
printf("\t5. Exit");
printf("\n\n\n\n\n\n\nEnter your selection : ");
scanf("%d",&a);
if(a==1)
diary();
if(a==2)
phonebook();
if(a==3)
calendar();
if(a==4)
infomem();
if(a==5)
return 0;
goto start;
}

void diary(){
start:
system("cls");
system("color F5");
printf("\t\t\t\t\t          DIARY\n\n\n");
printf("\t1. Add Diary\n\n");
printf("\t2. View Diary\n\n");
printf("\t3. Delete a Diary\n\n");
printf("\t4. View all diaries\n\n");
printf("\t5. Go to main menu\n\n");
printf("\t6. Exit\n\n");
printf("\n\n\n\n\n\nEnter your selection : ");
int option;
scanf("%d",&option);
switch(option)
{
case 1:
add_diary();
break;
case 2:
search_diary();
break;
case 3:
delete_diary();
break;
case 4:
view_all_diaries();
break;
case 5:
main();
case 6:
exit(0);
default:
diary();
}
goto start;
}

void add_diary()
{
system("color F6");
FILE *dp;
dp=fopen("diary.txt","a+");
system ("cls");
printf("\t\t\t\t\t        ADD DIARY");
printf("\n\n\n\tDay        : ");
char day[20];
scanf("%s",day);
printf("\n\tDate     : ");
char date[20];
scanf("%s",date);
printf("\n\tName  : ");
char name[20];
scanf("%s",name);
printf("\n\tDiary Name        : ");
char dname[20];
scanf("%s",dname);
printf("\n\tDiary        : ");
char diary[200];
scanf("%s",diary);
fprintf(dp,"%s %s %s %s %s\n",day,date,name,dname,diary);
fclose(dp);
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
return 0;
}

void search_diary()
{
system("color F9");
FILE *dp;
int a=1,i=1;
dp=fopen("diary.txt","r");
system("cls");
printf("\t\t\t\t\t        SEARCH DIARY");
printf("\n\n\n\tEnter Diary Name : ");
char dname[20];
scanf("%s",dname);
char day[20],date[20],name[20],dname1[20],diary[200];
while(fscanf(dp,"%s %s %s %s %s\n",day,date,name,dname1,diary)!=EOF)
{
if(strcmp(dname,dname1)==0){
printf("\n\tDay        : %s",day);
printf("\n\tDate       : %s",date);
printf("\n\tName       : %s",name);
printf("\n\tDiary Name : %s",dname1);
printf("\n\tDiary      : %s",diary);
printf("\n\n");
}
else
a++;
i++;
}
if(a==i)
printf("\n\n\n\tNo such record found");
fclose(dp);
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
diary;
}

void delete_diary()
{
system("color FA");
int a=0,i=0;
FILE *dp,*dp1;
dp=fopen("diary.txt","r+");
dp1=fopen("tmp.txt","w");
system("cls");
printf("\t\t\t\t\t        DELETE DIARY");
printf("\n\n\n\tEnter Diary Name : ");
char dname[20];
scanf("%s",dname);
char day[20],date[20],name[20],dname1[20],diary[200];
while(fscanf(dp,"%s %s %s %s %s\n",day,date,name,dname1,diary)!=EOF)
{
i++;
if(strcmp(dname,dname1)==0)
{
continue;
}
fprintf(dp1,"%s %s %s %s %s\n",day,date,name,dname1,diary);
if(strcmp(dname,dname1)!=0)
a++;
}
fclose(dp);
fclose(dp1);
dp=fopen("diary.txt","w");
dp1=fopen("tmp.txt","r");
while(fscanf(dp1,"%s %s %s %s %s\n",day,date,name,dname1,diary)!=EOF)
{
    fprintf(dp,"%s %s %s %s %s\n",day,date,name,dname1,diary);
}
fclose(dp);
fclose(dp1);
remove("tmp.txt");
if(a==i)
printf("\n\n\n\tNo such diary found");
else
printf("\n\n\n\tDiary deleted Successfully");
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
return 0;
}

void view_all_diaries()
{
system("color FB");
FILE *dp;
int i=0;
dp=fopen("diary.txt","r");
system("cls");
printf("\t\t\t\t\t      ALL DIARIES \n");
char day[20],date[20],name[20],dname1[20],diary[200];
while(fscanf(dp,"%s %s %s %s %s\n",day,date,name,dname1,diary)!=EOF)
{
printf("\n\tDay        : %s",day);
printf("\n\tDate       : %s",date);
printf("\n\tName       : %s",name);
printf("\n\tDiary Name : %s",dname1);
printf("\n\tDiary      : %s",diary);
i++;
}
printf("\n\n\n\t%d diaries found",i);
fclose(dp);
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
return 0;
}

void phonebook(){
system("cls");
system("color F5");
printf("\t\t\t\t\t          PHONEBOOK\n\n\n");
printf("\t1. Add contact\n\n");
printf("\t2. Search contact\n\n");
printf("\t3. Delete contact\n\n");
printf("\t4. View all contact\n\n");
printf("\t5. Go to main menu\n\n");
printf("\t6. Exit\n\n");
printf("\n\n\n\n\n\nEnter your selection : ");
int option;
scanf("%d",&option);
switch(option)
{
case 1:
add_contact();
break;
case 2:
search_contact();
break;
case 3:
delete_contact();
break;
case 4:
view_all_contact();
break;
case 5:
main();
case 6:
exit(0);
default:
phonebook();
}
}

void add_contact()
{
system("color F6");
FILE *fp;
fp=fopen("contact.txt","a+");
system ("cls");
printf("\t\t\t\t\t        ADD CONTACT");
printf("\n\n\n\tName        : ");
char name[20];
scanf("%s",name);
printf("\n\tSurname     : ");
char sur[20];
scanf("%s",sur);
printf("\n\tMobile no.  : ");
char mobile[11];
scanf("%s%*c",mobile);
char op;
printf("\n\tAdd more details [Y/N] : ");
scanf("%c",&op);
if(op==89||op==121)
{
printf("\n\tEmail Id    : ");
char emailid[30];
scanf("%s",emailid);
printf("\n\tBirthdate   : ");
char birthd[15];
scanf("%s",birthd);
printf("\n\tRelation    : ");
char rel[15];
scanf("%s",rel);
fprintf(fp,"%s %s %s %s %s %s\n",name,sur,mobile,emailid,birthd,rel);
fclose(fp);
}
else{
char emailid[30]="-------";
char birthd[15]="-------";
char rel[15]="-------";
fprintf(fp,"%s %s %s %s %s %s\n",name,sur,mobile,emailid,birthd,rel);
fclose(fp);}
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
phonebook();
}

void search_contact()
{
system("color F9");
FILE *fp;
int a=1,i=1;
fp=fopen("contact.txt","r");
system("cls");
printf("\t\t\t\t\t        SEARCH CONTACT");
printf("\n\n\n\tEnter Name : ");
char name[20];
scanf("%s",name);
char name1[20],sur[20],mobile[11],emailid[30],birthd[15],rel[15];
while(fscanf(fp,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel)!=EOF)
{
if(strcmp(name,name1)==0){
printf("\n\tName        : %s",name1);
printf("\n\tSurname     : %s",sur);
printf("\n\tMobile no.  : %s",mobile);
printf("\n\tEmail ID    : %s",emailid);
printf("\n\tBirthdate   : %s",birthd);
printf("\n\tRelation    : %s",rel);
printf("\n\n");
}
else
a++;
i++;
}
if(a==i)
printf("\n\n\n\tNo such contact found");
fclose(fp);
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
phonebook();
}

void delete_contact()
{
system("color FA");
int a=0,i=0;
FILE *fp,*fp1;
fp=fopen("contact.txt","r+");
fp1=fopen("temp.txt","w");
system("cls");
printf("\t\t\t\t\t        DELETE CONTACT");
printf("\n\n\n\tEnter Name : ");
char name[20];
scanf("%s",name);
char name1[20],sur[20],mobile[11],emailid[30],birthd[15],rel[15];
while(fscanf(fp,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel)!=EOF)
{
i++;
if(strcmp(name,name1)==0)
{
continue;
}
fprintf(fp1,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel);
if(strcmp(name,name1)!=0)
a++;
}
fclose(fp);
fclose(fp1);
fp=fopen("contact.txt","w");
fp1=fopen("temp.txt","r");
while(fscanf(fp1,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel)!=EOF)
{
    fprintf(fp,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel);
}
fclose(fp);
fclose(fp1);
remove("temp.txt");
if(a==i)
printf("\n\n\n\tNo such contact found");
else
printf("\n\n\n\tContact deleted Successfully");
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
phonebook();
}

void view_all_contact()
{
system("color FB");
FILE *fp;
int i=0;
fp=fopen("contact.txt","r");
system("cls");
printf("\t\t\t\t\t        ALL CONTACTS\n");
char name1[20],sur[20],mobile[11],emailid[30],birthd[15],rel[15];
while(fscanf(fp,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel)!=EOF)
{
printf("\n\n\tName        : %s",name1);
printf("\n\tSurname     : %s",sur);
printf("\n\tMobile no.  : %s",mobile);
printf("\n\tEmail ID    : %s",emailid);
printf("\n\tBirthdate   : %s",birthd);
printf("\n\tRelation    : %s",rel);
i++;
}
printf("\n\n\n\t%d contacts found",i);
fclose(fp);
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
phonebook();
}


int calendar()
{
int a;
star:
system("cls");
system("color F1");
printf("\t\t\t\t\t          CALENDAR\n\n\n");
printf("\t1. Year Calendar\n\n");
printf("\t2. Month by Month Calendar\n\n");
printf("\t3. Day from Date\n\n");
printf("\t4. Go to main menu\n\n");
printf("\t5. Exit");
printf("\n\n\n\n\n\n\nEnter your selection : ");
scanf("%d",&a);
if(a==1)
yearcalendar();
if(a==2)
monbymon();
if(a==3)
dfd();
if(a==4)
main();
if(a==5)
return 0;
goto star;
}

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
" ",
"January",
"February",
"  March",
"  April",
"   May",
"  June",
"  July",
" August",
"September",
"October",
"November",
"December"
};

int yearcalendar()
{
int year,daycode,d1,d2,d3,month, day,a;
system("color F2");
fullyear:
system("cls");
printf("Enter a year (YYYY) : ");
scanf("%d", &year);
nextyear:
system("cls");
printf("loading");
for(int i=0;i<3;i++){
sleep(1);
printf(".");}
system("cls");
d1=(year-1)/4;
d2=(year-1)/100;
d3=(year-1)/400;
daycode =(year+d1-d2+d3)%7;
if(year%4==0 && year%100!=0 || year%400==0)
days_in_month[2]=29;
else
days_in_month[2]=28;
for(month=1;month<=12;month++)
{printf("\n\n\n\t  %s %d",months[month],year);
printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
for(day=1;day<=1+daycode*5;day++){
printf(" ");}
for(day=1;day<=days_in_month[month];day++)
{printf("%2d",day);
if((day+daycode)%7>0)
printf("   " );
else
printf("\n " );}
daycode=(daycode+days_in_month[month])%7;
sleep(1);}
printf("\n\n\nEnter 1 for next year, 0 to change year and 2 to go to calendar :");
scanf("%d",&a);
if(a==0)
goto fullyear;
if(a==1){
year++;
system("cls");
goto nextyear;}
if(a==2)
return 0;
}

int monbymon()
{
int year,daycode,d1,d2,d3,month, day, a;
system("color F3");
yearmonthbymonth:
system("cls");
printf("Enter a year (YYYY) : ");
scanf("%d", &year);
for(;year>0;year++){
d1=(year-1)/4;
d2=(year-1)/100;
d3=(year-1)/400;
daycode =(year+d1-d2+d3)%7;
if(year%4==0 && year%100!=0 || year%400==0)
days_in_month[2]=29;
else
days_in_month[2]=28;
for(month=1;month<=12;month++){
system("cls");
printf("\n\n\n\t  %s %d", months[month],year);
printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
for(day=1;day<=1+daycode*5;day++){
printf(" ");}
for(day=1;day<=days_in_month[month];day++){
printf("%2d",day);
if((day+daycode)%7>0)
printf("   " );
else
printf("\n " );}
daycode=(daycode+days_in_month[month])%7;
printf("\n\n\n\n\n\n\n\n\npress 1 for next month, 0 to change the year and 2 to go to calendar : ");
scanf("%d",&a);
if(a==0)
goto yearmonthbymonth;
if(a==2)
return 0;
}}}

int dfd(){
int d,m,y,a;
system("color F4");
start:
system("cls");
printf("Enter the date  : ");
scanf("%d",&d);
printf("Enter the month : ");
scanf("%d",&m);
printf("Enter the year  : ");
scanf("%d",&y);
if(d>=32||m>=13||y/10000!=0||y/1000==0)
printf("\n\n\n\n\nPlease enter correct date\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
else
day(d,m,y);
sleep(3);
end:
printf("press 1 to run program again, press 2 for calendar : ");
scanf("%d",&a);
if(a==1)
goto start;
else if(a==2)
return 0;
else{
printf("enter correct selection - ");
goto end;
}
}

int day(int date,int month,int year) {
int day,yr,yd,l=1;
yr = year % 100;
yd = year / 100;
day=1.25*yr+findm(month,year)+date-2*(yd % 4);
day=day%7;
loop:
system("cls");
printf("loading");
for(int i=0;i<3;i++){
sleep(1);
printf(".");}
sleep(1);
l++;
if(l<3)
goto loop;
l=1;
system("cls");
printf("The Given Date is : %d/%d/%d \n", date, month, year);
switch (day){
case 0:printf("Day is : Saturday\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
break;
case 1:printf("Day is : Sunday\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
break;
case 2:printf("Day is : Monday\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
break;
case 3:printf("Day is : Tuesday\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
break;
case 4:printf("Day is : Wednesday\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
break;
case 5:printf("Day is : Thursday\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
break;
case 6:printf("Day is : Friday\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
break;
default:printf("Please enter correct date .\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");}
return 0;
}
int findm(int mo,int ye){
int d,leap;
if ((ye%100==0)&&(ye%400!=0))
leap=0;
else if (ye%4==0)
leap=1;
else
leap=0;
d=3+(2-leap)*((mo+2)/(2*mo))+(5*mo+mo/9)/2;
d%=7;
return d;
}

int infomem()
{
int a;
system("cls");
system("Color FD");
printf("\t\t\t\t\t  Members of group H9\n\n\n");
printf("\t46 Ganesh Karode\n\n");
printf("\t47 Omkar Karpe\n\n");
printf("\t48 Kartik Rupauliha (A.G.L.)\n\n");
printf("\t49 Kartik Rajput (G.L.)\n\n");
printf("\t50 Nakul Kasar");
printf("\t\n\n\n\n\n\nPress any key to go back to main menu");
getch();
main();
}
