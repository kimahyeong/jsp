#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int time_min = 10000;
int num_p = 0;
int num_m = 0;
int all_gongjian = 0;			//һ���������л�������ӹ��Ĺ�������
int all_mach = 100;				//��ͬ��������������

int p_gongjian[100] = { 0 };		//��ͬ��Ʒ�������мӹ�����
int m_gongjian[100] = { 0 };		//��ͬ�����ϵĹ�����������


int changpin[1000][1000][4];          //��Ʒ����Ʒ�ӹ�˳�򣬻�����ʱ�䡣
int changpin1[1000][1000][4]; 
int process[1000][1000][5] = { 0 };			//��Ʒ	����	ʱ�䣬����

int machine[1000][100][100][5] = { 0 };		//num1����	num2���г������	ʱ�䣬��Ʒ. ��ʼʱ�䣬����ʱ��,cixu

int better[10][100][100][5] = { 0 };

int parent[2][100][100][5] = { 0 };
int children[10][100][100][5] = { 0 };
int Best[1][100][100][5] = { 0 };
int Best1[1][100][100][5] = { 0 };
int time_m[1000] = { 0 };						//��¼ʱ�䣬������
int time_changpin[1000]={0};
int j_m=-1;           //���޻����ͼ���ʱ�� 
int j_t=0;
int a_jx[100]={0};     //ÿ�������ļ���ʱ�� 
int ma=-1;       //�û����������ĸ��ñ����� 
int state=0; 
int counttime=-1;
int mc=-1;
int d[100]={0};
int e[100]={0};
int f[100]={0};
int g[100]={0};
double wgt;

