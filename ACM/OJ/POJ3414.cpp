#include<stdio.h>
#include<string.h>

const int maxn = 110;
int vis[maxn][maxn]; //���״̬�Ƿ���ӹ�
int a,b,c; //������С
int step; //���յĲ���
int flag; //��¼�Ƿ��ܹ��ɹ�

/* ״̬��¼ */
struct Status{
    int k1,k2; //��ǰˮ��״̬
    int op; //��ǰ����
    int step; //��¼����
    int pre; //��¼ǰһ�����±�
}q[maxn*maxn];
int id[maxn*maxn]; //��¼���ղ����ڶ����еı��
int lastIndex; //���һ���ı��

void bfs(){
    Status now, next; 
    int head, tail;
    head = tail = 0;

    q[tail].k1 = 0; q[tail].k2 = 0;
    q[tail].op = 0; q[tail].step = 0; q[tail].pre = 0;

    tail++;
    memset(vis,0,sizeof(vis));
    vis[0][0] = 1; //��ǳ�ʼ״̬�����

    while(head < tail) //�����зǿ�
	{
        now = q[head]; //ȡ������
        head++; //��������

        if(now.k1 == c || now.k2 == c) //Ӧ�ò���������������, c=0
        {
            flag = 1;
            step = now.step;
            lastIndex = head-1; //��¼���һ���ı��
        }

        for(int i = 1; i <= 6; i++) //�ֱ���� 6 �����
        {
            if(i == 1) //fill(1)
            {
                next.k1 = a;
                next.k2 = now.k2;
            }
            else if(i == 2) //fill(2)
            {
                next.k1 = now.k1;
                next.k2 = b;
            }
            else if(i == 3) //drop(1)
            {
                next.k1 = 0;
                next.k2 = now.k2;
            }
            else if(i == 4) // drop(2);
            {
                next.k1 = now.k1;
                next.k2 = 0;
            }
            else if(i == 5) //pour(1,2)
            {
                if(now.k1+now.k2 <= b) //������ܹ�װ�� b
                {
                    next.k1 = 0;
                    next.k2 = now.k1+now.k2;
                }
                else //����ܹ�װ�� b
                {
                    next.k1 = now.k1+now.k2-b;
                    next.k2 = b;
                }
            }
            else if(i == 6) // pour(2,1)
            {
                if(now.k1+now.k2 <= a) //������ܹ�װ�� a
                {
                    next.k1 = now.k1+now.k2;
                    next.k2 = 0;
                }
                else //����ܹ�װ�� b
                {
                    next.k1 = a;
                    next.k2 = now.k1+now.k2-a;
                }
            }

            next.op = i; //��¼����
            if(!vis[next.k1][next.k2]) //�����ǰ״̬û����ӹ�
            {
                vis[next.k1][next.k2] = 1; //��ǵ�ǰ״̬���
                next.step = now.step+1; //���� +1
                next.pre = head-1; //��¼ǰһ���ı��

                //q.push(next);
                //q[tail] = next; �����β
                q[tail].k1 = next.k1; q[tail].k2 = next.k2;
                q[tail].op = next.op; q[tail].step = next.step; q[tail].pre = next.pre;
                tail++; //��β�ӳ�

                if(next.k1 == c || next.k2 == c) //����ﵽĿ��״̬
                {
                    flag = 1; //��ǳɹ�
                    step = next.step; //��¼�ܲ�����
                    lastIndex = tail-1; //��¼���һ����ģ�������еı��
                    return;
                }
            }
        }
    }
}
int main(){
    while(scanf("%d%d%d", &a,&b,&c) != EOF){
        flag = 0; //��ʼ�����ܳɹ�
        step = 0;

        bfs();
        if(flag)
        {
            printf("%d\n", step);

            id[step] = lastIndex; //���һ����ģ�������еı��
            for(int i = step-1; i >= 1; i--)
            {
                id[i] = q[id[i+1]].pre; //��ǰ��ǰһ������ģ�������еı��
            }

            for(int i = 1; i <= step; i++)
            {
                if(q[id[i]].op == 1)
                    printf("FILL(1)\n");

                else if(q[id[i]].op == 2)
                    printf("FILL(2)\n");

                else if(q[id[i]].op == 3)
                    printf("DROP(1)\n");

                else if(q[id[i]].op == 4)
                    printf("DROP(2)\n");

                else if(q[id[i]].op == 5)
                    printf("POUR(1,2)\n");

                else if(q[id[i]].op == 6)
                    printf("POUR(2,1)\n");
            }
        }
        else printf("impossible\n");
    }
    return 0;
}
