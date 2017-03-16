/************************/
/******单向链表测试******/
/************************/
#include <stdio.h>
#include <malloc.h>    /* 需要用到 malloc函数 */
#include <string.h>
#include <stdlib.h>   

typedef struct linknode linklist;      /*类型定义 linknode结构 linklist*/

#define LEN sizeof(linklist)    /*宏定义 LEN 为 结构的长度*/

struct linknode    /*定义结构体*/
{
	float data;   /* 当这里是int型时，输入比1小的小数时出错 */
	struct linknode *next; /* 也可以写成: linklist *next;*/
	
};

int main(void)
{
	int n=0;
	linklist *head,*p1,*p2,*p;       /* head为头指针 p1,p2,p为临时指针 */
	
	/* 初始化 */
	p1=p2=(linklist *)malloc(LEN);
	head=NULL;    /* 对于后期链表的维护有帮助，增删可以不用动表头 */ 
	
	/* 加入数据 但head中是不存任何数据的，只作为一个表头 */
	
	/* printf("%d",sizeof(linklist));     // 测试长度用的 */
	
	
	//do
	while(p1->data!=0)
	{
		
		p1=(linklist *)malloc(LEN);    /* 动态申请内存 */
		
		if(!p1)    /* 判断节点是否创建成功 */
		{
			printf("节点创建失败!");
		}
		else
		{
			printf("请输入第%d个不为0的数:\n",n+1);
			scanf("%f",&p1->data);
			
			if(0>=n && p1->data==0)    /* 如果在首个节点上输入0(空链表)则，重新输入，直到输入不为0的数 */
			{
				while(p1->data==0)    /* 为了防止输入小数进入死循环可以将这里强制转换为int,这里我将上面改为了float类型 */
				{
					printf("输入有误!请重新输入第%d个数:\n",n+1);
					getchar();
					scanf("%f",&p1->data);
				}
				
				p1->next=NULL;    
				p2->next=p1;
				head=p2;
				
			}
			else if (0>=n && p1->data !=0)    /* 检测该节点是否为首节点 n为0 */
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
			else if(0<n && p1->data==0)    /* 如果输入 0 代表结束录入，跳过本次循环 */
			{
				//free(p1);    /* 这里一旦free掉了结果就会出错了(死循环) */
				printf("创建结束!共创建了%d个节点。\n",n);
				continue;
			}
			
		}
		p2=p1;
		n+=1;
		/* printf("%d",p1->data);    //测试用 */
		
	}//while(p1->data!=0);    /* 第二次改用 while 形式，不再用do while形式 */
	
	/* 输出链表 */
	p=head;
	if(head->next==NULL)/* 判断链表是否为空，这里有点多余因为上面已经不允许空链表的产生，保险起见保留此处代码 */
	{
		printf("此链表为空!\n");
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
printf("\n\t表的维护:\n");
printf("\t+-----------------------------+\n");
printf("\t|          1.插入数据         |\n");
printf("\t|          2.删除数据         |\n");
printf("\t|          3.查找数据         |\n");
printf("\t|                             |\n");
printf("\t|                             |\n");
printf("\t+-----------------------------+\n");
*/
	return 0;
}