#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define LEN sizeof(linklist)    /* ������ */

typedef struct linknode    /* ��������ṹ */
{
	float data;
	struct linknode *next;
}linklist;



int n=0,i=0;

linklist *initlist();    /* ��ʼ���������� */
insertdata(linklist *head,float data,int serial);    /* head:��ͷ;data:����;serial:���; */
void print(linklist *head);    /* ����� */

int main()
{
	char c;    /* �Ƿ���� */
	float data;    /* �����Ҫɾ��������*/
	int serial;    /* �����Ҫɾ�������*/
	linklist *head;    /* typedef struct linknode linklist;  */

	head=initlist();    /* ��ʼ������ */

	print(head);    /* ��ӡ�����ɾ��ǰ���������� */


	insertdata(head,100,3);    /* �������� */

#if(0)    /* ��������ˣ�ע�͵����� */
	do{
		printf("������Ҫ����� ���ݺ����:\n");
		scanf("%f,%d",&data,&serial);
		insertdata(head,data,serial);
		printf("�Ƿ��������(Y/N):\n");
		getchar();
		getchar();
		getchar();
		scanf("%c",&c);
	}while(c=='y'||c=='Y');
#endif


	print(head);
	system("pause");
	return 0;
}

insertdata(linklist *head,float data,int serial)/* ������ ���� ��� */
{
	char c;
	linklist *p,*temp,*p1;
	temp=NULL;
	p=head;
	//	int i=0;    /* ѭ������ */
	if(p->next==NULL)	/* ���Ƿ�Ϊ�ձ� */
	{
		printf("�˱�Ϊ�գ��Ƿ���Ϊ��Ԫ��?\n");
		scanf("%c",&c);
		if(c=='y'||c=='Y')
		{
			p1=(linklist *)malloc(LEN);
			if(!p1)    /* �Ƿ�����ɹ� */
			{
				p->next=p1;
				p1->data=data;
				p1->next=NULL;
			}
			else
			{
				printf("����ʧ��!\n");
				return 0;
			}
		}
		else
		{
			printf("�˱�Ϊ�գ�����ʧ��!\n");
			return 0;
		}
		c=' ';    /* ��ʼ��c */
	}
	else
	{
		if(serial<n && serial >0)    /*  */
		{
			p1=(linklist *)malloc(LEN);
			if(p1)    /* �ɹ����� */
			{
				p1->data=data;
				//p->next=temp;/* ����д���� */
				
				while(i<serial)    /*��ָ���Ƶ�serialǰ��*/
				{
					p=p->next;
					i++;
				}
				if(p->next)    /* �ж��Ƿ�Ϊ��β */
				{
					temp=p->next;
					p->next=p1;
					p1->next=temp;
				}
				else
				{
					p->next=p1;
					p1->next=NULL;
				}
				printf("����ɹ�!\n");
			}
			else    /* ����ռ�ʧ�� */
			{
				printf("����ʧ��!\n");
				return 0;
			}
		}
		
		else if(serial>n)
		{
			printf("���кų�����ĳ���!\n");
		}
	}
	printf("\n");
	return 1;
}

linklist *initlist()
{
	linklist *p1,*p2,*head;
	/* �����ʼ�� */
	p1=p2=(linklist *)malloc(LEN);
	head=NULL;
	
	do{
		p1=(linklist *)malloc(LEN);
		printf("�������%d����Ϊ0����:",n+1);
		scanf("%f",&p1->data);
		p1->next=NULL;
		//if(((!p1->data - (int)p1->data) || p1->data<0) &&(0==n))
		if(0==n)
		{
			if(p1->data==0)
			{
				do
				{
					printf("�����������%d����:",n+1);
					scanf("%f",&p1->data);
					//}while((p1->data - (int)p1->data)|| p1->data<1);
				}while(p1->data==0);
			}
			head=p2;
			head->data=0;
			p2->next=p1;
			
		}
		//else if ((!p1->data-(int)p1->data) && n>0)
		else
		{
			p2->next=p1;
		}
		p2=p1;
		n+=1;
	}
	while(p1->data);
	printf("�������ɹ�!\n");
	return head;
}
void print(linklist *head)
{
	linklist *p;
	p=head->next;    /* ��ͷ����ӡ */
	if(head->next)
	{
		while(p->next)
		{
			printf("%f \n",p->data);
			p=p->next;
		}
	}
	else
	{
		printf("��Ϊ��!\n");
	}
}