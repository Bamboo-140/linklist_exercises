#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define LEN sizeof(linklist)    /* 链表长度 */

typedef struct linknode    /* 定义链表结构 */
{
	float data;
	struct linknode *next;
}linklist;



int n=0,i=0;

linklist *initlist();    /* 初始化数据链表 */
insertdata(linklist *head,float data,int serial);    /* head:表头;data:数据;serial:序号; */
void print(linklist *head);    /* 输出表 */

int main()
{
	char c;    /* 是否继续 */
	float data;    /* 插入或要删除的数据*/
	int serial;    /* 插入或要删除的序号*/
	linklist *head;    /* typedef struct linknode linklist;  */

	head=initlist();    /* 初始化链表 */

	print(head);    /* 打印插入或删除前的链表数据 */


	insertdata(head,100,3);    /* 插入数据 */

#if(0)    /* 这里出错了，注释掉备用 */
	do{
		printf("请输入要插入的 数据和序号:\n");
		scanf("%f,%d",&data,&serial);
		insertdata(head,data,serial);
		printf("是否继续插入(Y/N):\n");
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

insertdata(linklist *head,float data,int serial)/* 链表名 数据 序号 */
{
	char c;
	linklist *p,*temp,*p1;
	temp=NULL;
	p=head;
	//	int i=0;    /* 循环变量 */
	if(p->next==NULL)	/* 表是否为空表 */
	{
		printf("此表为空，是否作为首元素?\n");
		scanf("%c",&c);
		if(c=='y'||c=='Y')
		{
			p1=(linklist *)malloc(LEN);
			if(!p1)    /* 是否申请成功 */
			{
				p->next=p1;
				p1->data=data;
				p1->next=NULL;
			}
			else
			{
				printf("申请失败!\n");
				return 0;
			}
		}
		else
		{
			printf("此表为空，操作失败!\n");
			return 0;
		}
		c=' ';    /* 初始化c */
	}
	else
	{
		if(serial<n && serial >0)    /*  */
		{
			p1=(linklist *)malloc(LEN);
			if(p1)    /* 成功申请 */
			{
				p1->data=data;
				//p->next=temp;/* 这里写错了 */
				
				while(i<serial)    /*将指针移到serial前面*/
				{
					p=p->next;
					i++;
				}
				if(p->next)    /* 判断是否为表尾 */
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
				printf("插入成功!\n");
			}
			else    /* 申请空间失败 */
			{
				printf("申请失败!\n");
				return 0;
			}
		}
		
		else if(serial>n)
		{
			printf("序列号超出表的长度!\n");
		}
	}
	printf("\n");
	return 1;
}

linklist *initlist()
{
	linklist *p1,*p2,*head;
	/* 链表初始化 */
	p1=p2=(linklist *)malloc(LEN);
	head=NULL;
	
	do{
		p1=(linklist *)malloc(LEN);
		printf("请输入第%d个不为0的数:",n+1);
		scanf("%f",&p1->data);
		p1->next=NULL;
		//if(((!p1->data - (int)p1->data) || p1->data<0) &&(0==n))
		if(0==n)
		{
			if(p1->data==0)
			{
				do
				{
					printf("请重新输入第%d个数:",n+1);
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
	printf("链表创建成功!\n");
	return head;
}
void print(linklist *head)
{
	linklist *p;
	p=head->next;    /* 表头不打印 */
	if(head->next)    /* 可以直接写成  if(p) */
	{
		while(p->next)
		{
			printf("%f \n",p->data);
			p=p->next;
		}
	}
	else
	{
		printf("表为空!\n");
	}
}
