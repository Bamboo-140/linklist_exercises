/************************/
/******�����������******/
/************************/
#include <stdio.h>
#include <malloc.h>    /* ��Ҫ�õ� malloc���� */
#include <string.h>
#include <stdlib.h>   

typedef struct linknode linklist;      /*���Ͷ��� linknode�ṹ linklist*/

#define LEN sizeof(linklist)    /*�궨�� LEN Ϊ �ṹ�ĳ���*/

struct linknode    /*����ṹ��*/
{
	float data;   /* ��������int��ʱ�������1С��С��ʱ���� */
	struct linknode *next; /* Ҳ����д��: linklist *next;*/
	
};

int main(void)
{
	int n=0;
	linklist *head,*p1,*p2,*p;       /* headΪͷָ�� p1,p2,pΪ��ʱָ�� */
	
	/* ��ʼ�� */
	p1=p2=(linklist *)malloc(LEN);
	head=NULL;    /* ���ں��������ά���а�������ɾ���Բ��ö���ͷ */ 
	
	/* �������� ��head���ǲ����κ����ݵģ�ֻ��Ϊһ����ͷ */
	
	/* printf("%d",sizeof(linklist));     // ���Գ����õ� */
	
	
	//do
	while(p1->data!=0)
	{
		
		p1=(linklist *)malloc(LEN);    /* ��̬�����ڴ� */
		
		if(!p1)    /* �жϽڵ��Ƿ񴴽��ɹ� */
		{
			printf("�ڵ㴴��ʧ��!");
		}
		else
		{
			printf("�������%d����Ϊ0����:\n",n+1);
			scanf("%f",&p1->data);
			
			if(0>=n && p1->data==0)    /* ������׸��ڵ�������0(������)���������룬ֱ�����벻Ϊ0���� */
			{
				while(p1->data==0)    /* Ϊ�˷�ֹ����С��������ѭ�����Խ�����ǿ��ת��Ϊint,�����ҽ������Ϊ��float���� */
				{
					printf("��������!�����������%d����:\n",n+1);
					getchar();
					scanf("%f",&p1->data);
				}
				
				p1->next=NULL;    
				p2->next=p1;
				head=p2;
				
			}
			else if (0>=n && p1->data !=0)    /* ���ýڵ��Ƿ�Ϊ�׽ڵ� nΪ0 */
			{
				p1->next=NULL;    
				p2->next=p1;
				head=p2;	
			}
			else if(0<n && p1->data !=0)
			{
				p1->next=NULL;
				p2->next=p1;
			}
			else if(0<n && p1->data==0)    /* ������� 0 �������¼�룬��������ѭ�� */
			{
				//free(p1);    /* ����һ��free���˽���ͻ������(��ѭ��) */
				printf("��������!��������%d���ڵ㡣\n",n);
				continue;
			}
			
		}
		p2=p1;
		n+=1;
		/* printf("%d",p1->data);    //������ */
		
	}//while(p1->data!=0);    /* �ڶ��θ��� while ��ʽ��������do while��ʽ */
	
	/* ������� */
	p=head;
	if(head->next==NULL)/* �ж������Ƿ�Ϊ�գ������е������Ϊ�����Ѿ������������Ĳ�����������������˴����� */
	{
		printf("������Ϊ��!\n");
	}
	
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;	
			printf(" %f\t",p->data);
			
			
		}
	}
	printf("\n");

/*
printf("\n\t���ά��:\n");
printf("\t+-----------------------------+\n");
printf("\t|          1.��������         |\n");
printf("\t|          2.ɾ������         |\n");
printf("\t|          3.��������         |\n");
printf("\t|                             |\n");
printf("\t|                             |\n");
printf("\t+-----------------------------+\n");
*/
	return 0;
}