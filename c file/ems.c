#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct employee
{
    int d,m,y,id,expyear,age;
    float salary;
    long long int contact;
    char dept[50],post[50],educ[50],adds[70],name[50];
}e;

int empty();
int empty()
{
    int c=0;
    FILE *fp;
    fp=fopen("Record1.txt","r");
    while(fread(&e,sizeof(e),1,fp))
    {
        c=1;
    }
    fclose(fp);

    return c;
}


void insert();
void insert()
{
    FILE *fp;
    int i,id;
    int res;

    system("cls");
    fp=fopen("Record1.txt","a");
        do{
            int res;
            printf("\nEnter the ID of employee :: ");
            scanf("%d",&id);
            res=checkid(id);
            if(res==0)
            {
                e.id=id;
                break;
            }
            else if(res!=0)
            {
                printf("\n============================================================================================\n");
                printf("\n\t\t\t\t\ ID ALREADY EXIST !!!!!!!!!!\n");
                printf("\n============================================================================================\n");
            }
        }while(res!=0);


            printf("\nEnter the Name of employee :: ");
            scanf("%s",e.name);

        age();

        printf("\nEnter the Department name of employee ::");
        scanf("%s",&e.dept);

        contact();

        printf("\nEnter the Qualification of employee :: ");
        scanf("%s",&e.educ);

        checkexp();

        printf("\nEnter the Salary of employee :: ");
        scanf("%f",&e.salary);

        printf("\nEnter the Post of employee :: ");
        scanf("%s",&e.post);

        do
        {
            int d,m,y;
            printf("/nEnter join date ::");
            scanf("%d %d %d",&d,&m,&y);
            res=validate(d,m,y);
            if(res==0)
            {
                e.d=d;
                e.m=m;
                e.y=y;
                break;
            }
            else
            {
                 printf("\n============================================================================================\n");
                printf("\n\t\t\t\tEnter valid date ");
                 printf("\n============================================================================================\n");

            }
        }while(res!=0);

        fwrite(&e,sizeof(e),1,fp);

        fclose(fp);
}



int checkid(int);
int checkid(int id)
{
    int i;
    FILE *fpo;

        fpo=fopen("Record1.txt","r");
        while(fread(&e,sizeof(e),1,fpo))
        {
            if(id==e.id)
                {

                    return 1;
                }
        }
}


    fclose(fpo);



int validate(int,int,int);
int validate(int date,int month,int year)
{
	if(year>=1900 && year<=2019)
	{
		if(month>=1 && month<=12)
		{
			if( (date>=1 && date<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) )
				{
					return 0;
				}
			else if( (date>=1 && date<=30) && (month==4 || month==6 || month==9 || month==11) )
				{
					return 0;
				}
			else if( (date>=1 && date<=28) && month==2)
				{
					return 0;
				}
				else if(date==29 && month==2 && (year%400==0 || (year%4==0 && year%100!=0)))
                	{
                  	  return 0;
               	 	}
		}
        	else
       	 	{
           	 return 1;
       	 	}
	}
	else
    	{
        	return 1;
    	}
}

int age();
int age()
{
        printf("\nEnter the age of employee [21-65]:: ");
        scanf("%d",&e.age);
        if(e.age>=21 && e.age<=65)
        {
            return e.age;
        }
        else
        {
            while(!(e.age>=21 && e.age<=65))
            {
                 printf("\n============================================================================================\n");
                printf("\nWrong Age...");
                 printf("\n============================================================================================\n");

                printf("\nEnter the age of employee [21-65]:: ");
                scanf("%d",&e.age);
            }
        }
}


int checkexp();
int checkexp()
{
        printf("\nEnter the experience of employee :: ");
        scanf("%d",&e.expyear);
        if((e.expyear<e.age) && (e.expyear<=e.age-18))
        {
            return e.expyear;
        }
        else
        {
            while(e.expyear>=(e.age-18))
            {
                 printf("\n============================================================================================\n");
                printf("\nWrong experience ...");
                 printf("\n============================================================================================\n");

                printf("\nEnter the experience of employee :: ");
                scanf("%d",&e.expyear);
            }
        }
}




int contact();
int contact()
{
        printf("\nEnter the Contact no :: ");
        scanf("%lld",&e.contact);
        if(e.contact>999999999 && e.contact<10000000000)
        {
            return e.contact;
        }
        else
        {
            while(!(e.contact>999999999 && e.contact<10000000000))
            {
                 printf("\n============================================================================================\n");
                printf("\nwrong no ..");
                 printf("\n============================================================================================\n");

                printf("\nEnter only 10 digits for contact...");
                scanf("%lld",&e.contact);
            }
        }

}

void disp();
void disp()
{
    FILE *fp1;
    fp1=fopen("Record1.txt","r");

    system("cls");

    printf("\n\t\t============  All the data of Employee  ============\n");

    while(fread(&e,sizeof(e),1,fp1))
    {
        printf("\n\t\tID of employee :: %d",e.id);
        printf("\n\t\tName of employee :: %s",e.name);
        printf("\n\t\tAge :: %d",e.age);
        printf("\n\t\tDepartment name :: %s",e.dept);
        printf("\n\t\tContact No. :: %lld",e.contact);
        printf("\n\t\tQualification of employee :: %s",e.educ);
        printf("\n\t\tExperience of employee :: %d",e.expyear);
        printf("\n\t\tSalary :: %.2f",e.salary);
        printf("\n\t\tPost of employee :: %s",e.post);
        printf("\n\t\tJoining date :: %d %d %d",e.d,e.m,e.y);
        printf("\n_________________________________________________________________________________\n");
    }

    fclose(fp1);
}

void searchid();
void searchid()
{
    FILE *fp2;
    int id,avl,ch1;

    system("cls");

    printf("\n\t\tEnter the ID of the employee :: ");
    scanf("%d",&id);

    avl=avlid(id);
    if(avl==0)
    {
        {
        printf("\n\t\tId is not available!!!");
        }
        do
        {
            printf("\n\t\tDo you want to search again other ID ..[yes==1/no==0]");
            scanf("%d",&ch1);
            if(ch1==1)
            {
                searchid();
            }
            else
            {
                return;
            }
        }while(ch1==1);
    }

    else
    {
        fp2=fopen("Record1.txt","r");

        while(fread(&e,sizeof(e),1,fp2))
        {

            if(e.id==id)
            {
                printf("\n\t\tID of employee :: %d",e.id);
                printf("\n\t\tName of employee :: %s",e.name);
                printf("\n\t\tAge :: %d",e.age);
                printf("\n\t\tDepartment name :: %s",e.dept);
                printf("\n\t\tContact No. :: %lld",e.contact);
                printf("\n\t\tQualification of employee :: %s",e.educ);
                printf("\n\t\tExperience of employee :: %d",e.expyear);
                printf("\n\t\tSalary :: %.2f",e.salary);
                printf("\n\t\tPost of employee :: %s",e.post);
                printf("\n\t\tJoining date :: %d %d %d",e.d,e.m,e.y);
                printf("\n\t_________________________________________________________________________________\n");
            }
        }
     }
     fclose(fp2);

}

int avlid(int id);
int avlid(int id)
{
    FILE *fp;
    fp=fopen("Record1.txt","r");

    while(fread(&e,sizeof(e),1,fp))
    {
        if(id==e.id)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}


void searchdept();
void searchdept()
{
    FILE *fp2;
    char dept[30];
    int avldep,ch1;
    system("cls");

    printf("\n\t\tEnter the Department of the employee :: ");
    scanf("%s",dept);

    avldep=avldept(dept,30);
    if(avldep==0)
    {
        {
            printf("\n\t\tDepartment is not available!!!");
        }
        do
        {
            printf("\n\t\tDo you want to search again other ID ..[yes==1/no==0]");
            scanf("%d",&ch1);
            if(ch1==1)
            {
                searchdept();
            }
            else
            {
                return;
            }
        }while(ch1==1);
    }
    else
    {
        fp2=fopen("Record1.txt","r");

        while(fread(&e,sizeof(e),1,fp2))
        {
            if(strcmp(e.dept,dept)==0)
            {
                printf("\n\t\tID of employee :: %d",e.id);
                printf("\n\t\tName of employee :: %s",e.name);
                printf("\n\t\tAge :: %d",e.age);
                printf("\n\t\tDepartment name :: %s",e.dept);
                printf("\n\t\tContact No. :: %lld",e.contact);
                printf("\n\t\tQualification of employee :: %s",e.educ);
                printf("\n\t\tExperience of employee :: %d",e.expyear);
                printf("\n\t\tSalary :: %.2f",e.salary);
                printf("\n\t\tPost of employee :: %s",e.post);
                printf("\n\t\tJoining date :: %d %d %d",e.d,e.m,e.y);
                printf("\n\t_________________________________________________________________________________\n");
            }
        }
     }
     fclose(fp2);
}



int avldept(char dept[ ],int n);
int avldept(char dept[ ],int n)
{
    FILE *fp;
    fp=fopen("Record1.txt","r");

    while(!feof(fp))
    {
        fread(&e,sizeof(e),1,fp);
        if(strcmp(dept,e.dept)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}



void sort();
void sort()
{
    FILE *fpo;
    int a[50],count=0,i,j,c,temp;

    system("cls");

    fpo=fopen("Record1.txt","r");
    while(fread(&e,sizeof(e),1,fpo))
    {
        a[count]=e.salary;
        count++;
    }

    for(i=0;i<count;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }


    for(i=0;i<count;i++)
    {
        rewind(fpo);

        while(fread(&e,sizeof(e),1,fpo))
        {
            if(a[i]==e.salary)
            {
                printf("\n\t\tID of employee :: %d",e.id);
                printf("\n\t\tName of employee :: %s",e.name);
                printf("\n\t\tAge :: %d",e.age);
                printf("\n\t\tDepartment name :: %s",e.dept);
                printf("\n\t\tContact No. :: %lld",e.contact);
                printf("\n\t\tQualification of employee :: %s",e.educ);
                printf("\n\t\tExperience of employee :: %d",e.expyear);
                printf("\n\t\tSalary :: %.2f",e.salary);
                printf("\n\t\tPost of employee :: %s",e.post);
                printf("\n\t\tJoining date :: %d %d %d",e.d,e.m,e.y);
                printf("\n\t________________________________________________________________________________\n");
            }
        }
    }
    fclose(fpo);
}



void sortid();
void sortid()
{
    FILE *fpo;
    int a[50],count=0,i,j,c,temp;

    system("cls");

    fpo=fopen("Record1.txt","r");
    while(fread(&e,sizeof(e),1,fpo))
    {
        a[count]=e.id;
        count++;
    }

    for(i=0;i<count;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }


    for(i=0;i<count;i++)
    {
        rewind(fpo);

        while(fread(&e,sizeof(e),1,fpo))
        {
            if(a[i]==e.id)
            {
                printf("\n\t\tID of employee :: %d",e.id);
                printf("\n\t\tName of employee :: %s",e.name);
                printf("\n\t\tAge :: %d",e.age);
                printf("\n\t\tDepartment name :: %s",e.dept);
                printf("\n\t\tContact No. :: %lld",e.contact);
                printf("\n\t\tQualification of employee :: %s",e.educ);
                printf("\n\t\tExperience of employee :: %d",e.expyear);
                printf("\n\t\tSalary :: %.2f",e.salary);
                printf("\n\t\tPost of employee :: %s",e.post);
                printf("\n\t\tJoining date :: %d %d %d",e.d,e.m,e.y);
                printf("\n\t________________________________________________________________________________\n");
            }
        }
    }
    fclose(fpo);
}


void deletedata();
void deletedata()
{
        FILE *fpo,*fpt;
        int id;
        system("cls");

        printf("\n\t\tEnter the ID which you want to delete ::");
        scanf("%d",&id);

        if(avlid(id)==0)
        {
            printf("\n\t\tID is not available!!!");
        }
        else
        {
            fpo=fopen("Record1.txt","r");
            fpt=fopen("Tempfile.txt","w");

            while(fread(&e,sizeof(e),1,fpo))
            {
                if(e.id!=id)
                {
                    fwrite(&e,sizeof(e),1,fpt);
                }
            }
            fclose(fpo);
            fclose(fpt);

            fpo=fopen("Record1.txt","w");
            fpt=fopen("Tempfile.txt","r");

            while(fread(&e,sizeof(e),1,fpt))
            {
                fwrite(&e,sizeof(e),1,fpo);
            }

            printf("\n\t\tRecord is Deleted..");

            fclose(fpo);
            fclose(fpt);
        }
}

void update();
void update()
{
        FILE *fpt,*fpo;
        int id,ch,avl,ch1;

        system("cls");

        printf("\n\t\tEnter the ID to update :: ");
        scanf("%d",&id);

        avl=avlid(id);
        if(avl==0)
        {
            printf("\n\t\tId is not available!!!");
        }
        else
        {
            fpo=fopen("Record1.txt","r");
            fpt=fopen("Tempfile.txt","w");

            while(fread(&e,sizeof(e),1,fpo))
            {
                if(e.id!=id)
                {
                    fwrite(&e,sizeof(e),1,fpt);
                }
                else
                {
                    do
                    {
                    printf("\n\t\t1. Update Name of Id %d",id);
                    printf("\n\t\t2. Update Age of Id %d",id);
                    printf("\n\t\t3. Update Department name of Id %d",id);
                    printf("\n\t\t4. Update Contact No. of Id %d",id);
                    printf("\n\t\t5. Update Qualification of employee of Id %d",id);
                    printf("\n\t\t6. Update Experience of employee of Id %d",id);
                    printf("\n\t\t7. Update Salary of Id %d",id);
                    printf("\n\t\t8. Update Post of employee of Id %d",id);
                    printf("\n\t\t9. Update all Data of ID %d",id);
                    printf("\n\t_____________________________________________________________\n");
                    printf("\n\t\tEnter the Choice to update ::");
                    scanf("%d",&ch);

                    switch(ch)
                    {
                    case 1:
                        printf("\n\t\tEnter the Name of employee ::");
                        scanf("%s",&e.name);
                        break;

                    case 2:
                        age();
                        break;

                    case 3:
                        printf("\n\t\tEnter the Department name of employee ::");
                        scanf("%s",&e.dept);
                        break;

                    case 4:
                        contact();
                        break;

                    case 5:
                        printf("\n\t\tEnter the Qualification of employee ::");
                        scanf("%s",&e.educ);
                        break;

                    case 6:
                        checkexp();
                        break;

                    case 7:
                        printf("\n\t\tEnter the Salary of employee ::");
                        scanf("%f",&e.salary);
                        break;

                    case 8:
                        printf("\n\t\tEnter the Post of employee ::");
                        scanf("%s",&e.post);
                        break;

                    case 9:
                        printf("\n\t\tEnter the Name of employee ::");
                        scanf("%s",e.name);

                        age();

                        printf("\n\t\tEnter the Department name of employee ::");
                        scanf("%s",&e.dept);

                        contact();

                        printf("\n\t\tEnter the Qualification of employee ::");
                        scanf("%s",&e.educ);

                        printf("\n\t\tEnter the Experience of employee ::");
                        checkexp();

                        printf("\n\t\tEnter the Salary of employee ::");
                        scanf("%f",&e.salary);

                        printf("\n\t\tEnter the Post of employee ::");
                        scanf("%s",&e.post);

                        break;

                    default:
                        printf("\n\t\tInvalid Choice!!");
                        break;
                    }

                    printf("\n\n\t\tDo you want to cont..[0=no/1=yes] ::");
                    scanf("%d",&ch1);

                    }while(ch1==1);

                    fwrite(&e,sizeof(e),1,fpt);
                }
            }

            fclose(fpo);
            fclose(fpt);

            fpo=fopen("Record1.txt","w");
            fpt=fopen("Tempfile.txt","r");

            while(fread(&e,sizeof(e),1,fpt))
            {
                fwrite(&e,sizeof(e),1,fpo);
            }

            fclose(fpo);
            fclose(fpt);

            printf("\n\t\tRecord Updated...");
        }
}



int main()
{
    int ch,emp1;
   do
    {
        printf("\n\t==================  Select Your choice  ==================\n");

        printf("\n\t\t1. Insert Data");
        printf("\n\t\t2. Display Data");
        printf("\n\t\t3. Search by Id no.");
        printf("\n\t\t4. Search by Dept. Name");
        printf("\n\t\t5. Sort by ID");
        printf("\n\t\t6. Sort by salary");
        printf("\n\t\t7. Delete Data");
        printf("\n\t\t8. Update Data");
        printf("\n\t\t9. Exit");

        printf("\n\t\tEnter your choice ::");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            insert();
            break;

        case 2:
            emp1=empty();
            if(emp1==0)
            {
                printf("\n\t\tThe file is empty!!!");
            }
            else
            {
                disp();
            }
            break;

        case 3:

            emp1=empty();
            if(emp1==0)
            {
                printf("\n\t\tThe file is empty!!!");
            }
            else
            {
                searchid();
            }
            break;

        case 4:

            emp1=empty();
            if(emp1==0)
            {
                printf("\n\t\tThe file is empty!!!");
            }
            else
            {
                searchdept();
            }
            break;

        case 5:
            emp1=empty();
            if(emp1==0)
            {
                printf("\n\t\tFile is empty!!");
            }
            else
            {
                sortid();
            }
            break;


        case 6:
            emp1=empty();
            if(emp1==0)
            {
                printf("\n\t\tFile is empty!!");
            }
            else
            {
                sort();
            }
            break;

        case 7:

            emp1=empty();
            if(emp1==0)
            {
                printf("\n\t\tThe file is empty!!!");
            }
            else
            {
                deletedata();
            }
            break;

        case 8:

            emp1=empty();
            if(emp1==0)
            {
                printf("\n\t\tThe file is empty!!!");
            }
            else
            {
                update();
            }
            break;

        case 9:
            printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf("\n\n\t\t\t\tTHANK YOU FOR USING OUR SYSTEM \t\t\t\t\t  \n ");
            printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            exit(0);
            break;

        default:
            printf("\n\t\tInvalid Choice!!!");
            break;
        }
    }while(ch!=9);

    return 0;
}
