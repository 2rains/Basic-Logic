#include <stdio.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>

typedef struct employees{
   int employeeNumber;
   char name[20];
   int age;
   int pay;
   char department[10];
   struct employee *next;
}EMPLOYEE;      // 직원 구조

void print_list(EMPLOYEE *head);
EMPLOYEE *insert(EMPLOYEE data, EMPLOYEE *list);
EMPLOYEE *deleteEmployee(int data, EMPLOYEE *list);
int menu_click(int num);
EMPLOYEE *deleteEmployee_s(int data, EMPLOYEE *list);
void print_list_department(EMPLOYEE *head, int num);
//EMPLOYEE *deleteEm_department(int data, EMPLOYEE *list);

int main(void){
   //int i=0;
   EMPLOYEE *temp=NULL, *list=NULL, *deleteEm=NULL;
   EMPLOYEE newNode;
   int menu, a;
   FILE *fp, *fh, *fr ;   // 파일 열기
   int emNumber, ss;
   int depart_num, yesNo;
   
   menu = menu_click(a); // 메뉴 선택 
  
   if((fp = fopen("Master.txt","r"))==NULL){		// Master open 
      printf("ERROR");
      exit(-1);
   }
   
   if((fh = fopen("Hire.txt","r"))==NULL){			// Hire open
      printf("ERROR");
      exit(-1);
   }
   
   if((fr = fopen("Retire.txt", "r"))==NULL){
	  printf("ERROR");
	  exit(-1);
   }
	switch(menu){
		case 1 : 	//직원 정보 로드
		while(!feof(fp)){		// Master printf 
	      fscanf(fp,"%d %s %d %d", &newNode.employeeNumber, newNode.name, &newNode.age, &newNode.pay);
	      list = insert(newNode, list);	// Master.txt   
	   }
	   	printf("\n\n\t<<< 직원 정보 로드 >>>\n\n"); 
		print_list(list);
		printf("\n\n");
		break;
   
   case 2 : //신입 정보 로드
		while(!feof(fh)){	// Master + Hire printf
	      fscanf(fh,"%d %s %d %d", &newNode.employeeNumber, newNode.name, &newNode.age, &newNode.pay);
	      list = insert(newNode, list);	// Hire.txt
	   }
	   	printf("\n\n\t<<< 신입 정보 로드 >>>\n\n");
		print_list(list);
	   	printf("\n\n");
		break;
   
	case 3 :	// 퇴직자 사번 정보 로드
		while(!feof(fp)){		// Master printf 
	      fscanf(fp,"%d %s %d %d", &newNode.employeeNumber, newNode.name, &newNode.age, &newNode.pay);
	      list = insert(newNode, list);	// Master.txt   
	    }
		while(!feof(fr)){	// Master + Hire printf - Retire printf
	   	 fscanf(fr,"%d", &newNode.employeeNumber);
	   	 deleteEm = deleteEmployee(newNode.employeeNumber, list);
	    }
		printf("\n\n\t<<< 퇴직자 정보 로드 >>>\n\n");
		print_list(list);
	   	printf("\n\n");
	   	break;   	   
   
	case 4 :	//직원 및 신입 정보 로드
	   	while(!feof(fp)){		// Master printf 
	      fscanf(fp,"%d %s %d %d", &newNode.employeeNumber, newNode.name, &newNode.age, &newNode.pay);
	      list = insert(newNode, list);	// Master.txt   
	   }
		while(!feof(fh)){	// Master + Hire printf
	      fscanf(fh,"%d %s %d %d", &newNode.employeeNumber, newNode.name, &newNode.age, &newNode.pay);
	      list = insert(newNode, list);	// Hire.txt
	   }
	   	printf("\n\n\t<<< 직원 및 신입 정보 로드 >>>\n\n");
		print_list(list);
	   	printf("\n\n");
	   	break;
   
	case 5 :	// 퇴직자 제외한 직원 정보 로드
	   	while(!feof(fp)){		// Master printf 
	      fscanf(fp,"%d %s %d %d", &newNode.employeeNumber, newNode.name, &newNode.age, &newNode.pay);
	      list = insert(newNode, list);	// Master.txt   
	   }
		while(!feof(fh)){	// Master + Hire printf
	      fscanf(fh,"%d %s %d %d", &newNode.employeeNumber, newNode.name, &newNode.age, &newNode.pay);
	      list = insert(newNode, list);	// Hire.txt
	   }
		while(!feof(fr)){	// Master + Hire printf - Retire printf
	   	 fscanf(fr,"%d", &newNode.employeeNumber);
	     deleteEm = deleteEmployee(newNode.employeeNumber, list);  // Retire
	   }
	   	printf("\n\n\t<<< 퇴직자 제외한 직원 정보 로드 >>>\n\n");
	   	print_list(list);
	   	printf("\n\n");
	   	break;
	   	
	case 6 :	// 부서 정보 추가 
	   	while(!feof(fp)){		// Master printf 
	      fscanf(fp,"%d %s %d %d", &newNode.employeeNumber, newNode.name, &newNode.age, &newNode.pay);
	      list = insert(newNode, list);	// Master.txt   
	   }
		while(!feof(fh)){	// Master + Hire printf
	      fscanf(fh,"%d %s %d %d", &newNode.employeeNumber, newNode.name, &newNode.age, &newNode.pay);
	      list = insert(newNode, list);	// Hire.txt
	   }
		while(!feof(fr)){	// Master + Hire printf - Retire printf
	   	 fscanf(fr,"%d", &newNode.employeeNumber);
	     deleteEm = deleteEmployee(newNode.employeeNumber, list);  // Retire
		}
		printf("\n\n    사번 입력 : ");
		scanf("%d", &emNumber);
		print_list_department(list, emNumber);	
	   	printf("\n\n");
	   	//break;
	   	
	   	printf("   # 해당 직원 부서정보를 입력하시겠습니까? #\n\n\n");
		printf("    1.예     2.아니오(메뉴로 이동)\n\n\n"); 
	   	scanf("%d", &yesNo);
	   	
	   	if(yesNo == 1){
	   		// 부서 정보 + 번호 입력 
			printf("  ***********부서 정보***********\n\n");
			printf(" |  1.경영지원팀 2.재무팀 3.영업팀 4. 기획팀  |\n\n");
		   	printf("   추가할 부서 번호를 입력하세요 : ");
		   	scanf("%d", &depart_num); 
		} 
		else if(yesNo == 2){
			system("cls");
			return menu = menu_click(a);
		}
	   	
	   	
	}   
   return 0;
}


void print_list(EMPLOYEE *head) { 	// 직원 전체 리스트 
   if (head == NULL)printf ("\n       *************************"); 
   else { printf("\t%d %s %d %d\n", head->employeeNumber, head->name, head->age, head->pay); 
	print_list (head->next);
   } 
 
}

EMPLOYEE *insert(EMPLOYEE data, EMPLOYEE *list){	// 직원 오름차순 정렬 
   EMPLOYEE *current = NULL, *follow = NULL, *newnode = NULL;
   current = follow = list;
   // 새로운 노드의 생성
   if ((newnode = (EMPLOYEE *) malloc (sizeof (EMPLOYEE))) == NULL) {
      printf ("No memory allocated..\n");
      return NULL;
   }
   newnode->employeeNumber = data.employeeNumber;
   strcpy(newnode->name,  data.name);
   newnode->age = data.age;
   newnode->pay = data.pay;
   // 삽입 위치로 이동
   while ((current != NULL) && (current->employeeNumber < newnode->employeeNumber)) {		// 오름차순 정렬 
      follow = current;
      current = current->next;
   }
   // 삽입
   newnode->next = current;
   if (current == list) list = newnode; //insert as first node
   else follow->next = newnode; // insert into middle or end
   
   return list;
}

EMPLOYEE *deleteEmployee(int data, EMPLOYEE *list){	// 퇴직 사원 삭제 
	EMPLOYEE *follow, *current;
	current = follow = list;
	
	while((current != NULL) && (current->employeeNumber != data)){	// list(사원데이터), data(삭제데이터)!!!!employeeNumber는 사번끼리 비교해야함 
		follow = current;
		current = current->next;	
	}
	
	if(current == NULL){
		printf("삭제할 데이터 없음"); 
		return list;
	}
	
	if(list == current) list = current->next;	// 첫 번째 노드 삭제
	else if(current->next == NULL) follow->next = NULL;		// 마지막 노드 삭제 
	else follow->next = current->next;		// 가운데 노드 삭제
	free(current);
	return list; 
}

EMPLOYEE *deleteEmployee_s(int data, EMPLOYEE *list){	// 퇴직사원 제외 직원 삭제 
	EMPLOYEE *follow, *current;
	current = follow = list;
	
	while((current != NULL) && (current->employeeNumber == data)){	// list(사원데이터), data(삭제데이터)!!!!employeeNumber는 사번끼리 비교해야함 
		follow = current;
		current = current->next;	
	}
	
	if(current == NULL){
		printf("삭제할 데이터 없음"); 
		return list;
	}
	
	if(list == current) list = current->next;	// 첫 번째 노드 삭제
	else if(current->next == NULL) follow->next = NULL;		// 마지막 노드 삭제 
	else follow->next = current->next;		// 가운데 노드 삭제
	free(current);
	return list; 
}

int menu_click(int num){	// 메뉴 선택(첫화면) 
	int i;
	
	printf("\n\n\t*********직원관리프로그램*********\n\n");
	printf("\t 1. 직원 정보 로드\n");
	printf("\t 2. 신입 정보 로드\n");
	printf("\t 3. 퇴직자 정보 로드\n");
	printf("\t 4. 직원 및 신입 정보 로드\n");
	printf("\t 5. 퇴직자 제외한 직원 정보 로드 \n");
	printf("\t 6. 부서 정보 추가 \n");
	printf("\t 0. 프로그램 종료\n");
	printf("\n\t사용하실 메뉴 번호를 입력하세요 : ");
	scanf("%d", &num); 
	
	switch(num){
		case 1 :
			printf("\t1번 선택\n");
			system("cls");
			break;
		case 2 :
			printf("\t2번 선택\n");
			system("cls");
			break;
		case 3 :
			printf("\t3번 선택\n");
			system("cls");
			break;
		case 4 :
			printf("\t4번 선택\n");
			system("cls");
			break;
		case 5 :
			printf("\t5번 선택\n");
			system("cls");
			break;
		case 6 :
			printf("\t6번 선택\n");
			system("cls");
			break;
		case 0 :
			printf("\t0번 선택\n");
			printf("종료합니다\n");
			exit(-1);
		default : 
			printf("\t잘못 입력했습니다\n");
	}
	return (num);
}


void print_list_department(EMPLOYEE *head, int num) { 	// 직원 정보 검색(부서)  
   if (head == NULL)printf ("\n     사번오류 혹은 퇴직자입니다"); 
   else if(head->employeeNumber == num) 
   {printf ("\n   ----------사원 정보-----------\n\n    %d %s %d %d\n" , head->employeeNumber, head->name, head->age, head->pay); 
   } else print_list_department (head->next, num); 
}
