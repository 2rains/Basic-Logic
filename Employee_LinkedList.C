#include <stdio.h>
#define MAX 1000

typedef struct{
   char name[15];
}element;

typedef struct employee {   // 구조체 정의
   int employee_number; 
    element name;        // 구조체 멤버 1
    int age;              // 구조체 멤버 2
    int salary;
    
    struct employee *next;
} employee_s;

struct employee *pStart = NULL;

void employee_first_linklist(FILE *fp){
   employee_s *Current;
   
 while (!feof(fp)){
      
   Current = (employee_s*)malloc(sizeof(employee_s));
   fscanf(fp,"%d %s %d %d\n",&Current->employee_number,Current->name.name,&Current->age,&Current->salary);
   Current->next=NULL;
   
   if(pStart==NULL){
      
      pStart=Current;      
   }else{
      employee_s *temp =pStart;
      while(temp->next!=NULL)
         temp=temp->next;

      temp->next=Current;
   }
   

}
   
}
void employee_Retire(FILE *fp){
   
      employee_s *p=pStart;
   
    while (!feof(fp)){
       int del_data;
      fscanf(fp,"%d\n",&del_data);
      
      p=pStart;
      
      while(p->next !=NULL){
         
         if(pStart->employee_number==del_data){
            pStart=pStart->next;
            break;
         }else if(p->next->employee_number == del_data){
            
            p->next=p->next->next;
            
            
            break;
         }

         p=p->next;         
      }
      
      if(p==NULL){
         printf("해당값이 존재 하지 않습니다.\n");
      }
      
   }

}

void employee_Hire(FILE *fp){
   employee_s *add_node;

   
   while (!feof(fp)){
   add_node = (employee_s*)malloc(sizeof(employee_s));
     fscanf(fp,"%d %s %d %d\n",&add_node->employee_number,add_node->name.name,&add_node->age,&add_node->salary);
   add_node->next=NULL;
   employee_s *p=pStart;

      
      while(p !=NULL){
         
         if(pStart->employee_number > add_node->employee_number){
            //헤드가 더크면 
            add_node->next=pStart;
            pStart=add_node;
            break;
         }else if(p->next==NULL){
            //끝이라면 
            p->next=add_node;   
            break;
         }else if(p->next->employee_number>add_node->employee_number){
            //전이라면
            add_node->next=p->next;
            p->next=add_node;
            break; 
            
         }

         p=p->next;         
      }
      
 

       
    }
    

}


void main()
{
    FILE* fp = fopen("Master.txt", "r");  //test파일을 r(읽기) 모드로 열기
    FILE* Retire_fp = fopen("Retire.txt", "r");  //test파일을 r(읽기) 모드로 열기
    FILE* Hire_fp = fopen("Hire.txt", "r");  //test파일을 r(읽기) 모드로 열기
    FILE* fp_2 = fopen("Master2.txt", "w");  //test파일을 r(읽기) 모드로 열기

    
   employee_first_linklist(fp);
   
    employee_s *p=pStart;
    
     
         while(p !=NULL)
      {
          printf("%d %s %d %d\n",p->employee_number,p->name.name,p->age,p->salary);
         p=p->next;
      }
      
    printf("\n\n\n\n\n")   ;
   employee_Retire(Retire_fp);
      
      
   p=pStart;
    
     
         while(p !=NULL)
      {
          printf("%d %s %d %d\n",p->employee_number,p->name.name,p->age,p->salary);
         p=p->next;
      }
      
    printf("\n\n\n\n\n")   ;

   employee_Hire(Hire_fp);
      p=pStart;
    
     
         while(p !=NULL)
      {
          printf("%d %s %d %d\n",p->employee_number,p->name.name,p->age,p->salary);
          fprintf(fp_2,"%d %s %d %d\n",p->employee_number,p->name.name,p->age,p->salary);
         p=p->next;
      }

    
   
    fclose(fp); //파일 포인터 닫기
}
