#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"extern.h"
#include <graphics.h>
//�����������     �Ӿ���  //110�� 
void print_mach(int num);  
void print_zuiyou(void);
void input_jianpan_changpin(void) ;
void print_changpin(int num);
void input_file_changpin(void); 
void output_file_best(void);
//ͼ���������  �Ӿ��� 
void scdd();//������� 

//ʱ����㺯��    �κ�Ȼ  //300�� 
int  c_time(int num);
int  time_mach(int num);
int t_max();
int max1(int ,int );
int min1(int ,int ); 
//ͼ�ν���     �κ�Ȼ 
void out();
void jxshuru(int ,int);   //��������ͼ�ν��� 
void shuchu1(clock_t ed,clock_t op);    //���ͼ�ν��� 
void input_jx(int j_m,int j_t,int time);             //���������޺�ʱ�� 

//create    ��һ��                 //350�� 
void create_parent(void);                //�����ױ� 
void bianyi_changpin(int number);		//���캯�� 
void xiugai_end(int number);			//�޸Ĵ������� 
//�������໥ת��      ��һ�� 
void zhuangma_changpin_mach(int num1, int num2);
void jiaohuan(int* x, int *y);	
void mach_machine(int num_1, int  num_2);
//ɫ�ʴ��� ��һ�� 
void secai();
void huaxian(int);

int main(void) {
	char p[10000];
    clock_t ed,op;
	{ 
	
	ed=clock(); 
	setinitmode(0);
	initgraph(1200, 720);
    setbkcolor(WHITE); //���ñ���ɫ 
    setfillcolor(LIGHTRED);
    setfont(12, 0, "����");
        //���û�ͼ��ɫΪ�� 
    setcolor(BLACK);
	char str[2];
	inputbox_getline("������", "��������1���ļ�����2", str, 2);
    int x;
	x=str[0]-'0'; 
	if(x==1)
	{
		inputbox_getline("������", "������", p, 10000);
		input_file_changpin();
	}
	if(x==2){  
	input_file_changpin();
	}
}
	
	create_parent();
	op=clock();
{	

	int i,j;
		for (i=0; i < num_m; i++) {
		for (j=0;j<m_gongjian[i] ; j++) {
			Best1[0][i][j][0]=Best[0][i][j][0];
		    Best1[0][i][j][1]=Best[0][i][j][1];
		    Best1[0][i][j][2]=Best[0][i][j][2];
		    Best1[0][i][j][3]=Best[0][i][j][3];
		    Best1[0][i][j][4]=Best[0][i][j][4];
		}
	}
    shuchu1(ed,op);
  
} 
}

void shuchu1(clock_t ed,clock_t op)    //���ͼ�ν��� 
{
	int time=0;
	int let,v=30;
	for ( ; is_run(); delay_fps(5) ){
	  //  cleardevice();
	    secai();
	    line(540,0,540,600);
	    line(0,300,1300,300);
		scdd();
	    line(40,20,40,280);//y�� ���ϲ��� 
        line(40,20,500,20);//x��Ϊ560 
        line(40,320,40,580);//y��  ���²��� 
        line(40,320,500,320);//x��Ϊ560 
        int i=0,j=0,k=0,count=1,count1;//time_min=1300num_m;	
        char a[5],b[5],c[5],d[10],d1[10];//ר����������ת�ַ��� 
        while(count*460<time_min)//ȷ��x���С 
        {
        	count++;
		}
		count1=count+1; 
		outtextxy(40, 5, "0");
		outtextxy(40, 305, "0");
	
        
        for(i=0;i<num_m;i++)//��ͼx�ᣬy���123����ÿ���������� 
		{
		k+=260/(num_m);
		itoa(i,a,10);
		itoa(460*count/num_m*(i+1),d,10);
		itoa(460*count1/num_m*(i+1),d1,10);
        outtextxy(20, 8+k, a);//���ϻ����� 
        outtextxy(20, 308+k, a);//���»����� 
       
        line(40, 20+k,500,20+k );//ÿ�������ϵ��� ���� 
        line(40, 320+k,500,320+k );//���� 
        outtextxy(40+460/num_m*(i+1), 5, d);// ���� 
        outtextxy(40+460/num_m*(i+1), 305, d1);//  ���� 
      
        line(40+460/num_m*(i+1),20,40+460/num_m*(i+1),25);
        line(40+460/num_m*(i+1),320,40+460/num_m*(i+1),325);
        outtextxy(550,305,"�밴���������ʼ����");
        xyprintf(670,20,"���깤ʱ�䣺%d",time_min);//������깤ʱ�� 
        xyprintf(850,20,"����ʱ�䣺%f",double(op-ed)/CLOCKS_PER_SEC);//������깤ʱ�� 
        wgt=double(op-ed)/CLOCKS_PER_SEC;
        //������ͼ�ķ��� 
       for (j=0; j <m_gongjian[i]; j++) {
       	
       	 setfillcolor(RGB(Best[0][i][j][1]*131%256,Best[0][i][j][1]*2013%256,Best[0][i][j][1]*1999%256)); 
			bar(40+Best[0][i][j][2]/count,10+k,40+Best[0][i][j][3]/count,20+k);
			
			xyprintf(520+630/num_p*(j+1), k+310, "(%d,",Best[0][i][j][1]);//  
		    xyprintf(545+630/num_p*(j+1), k+310, "%d)",Best[0][i][j][4]);//  ģ���Ʒ�� �����  
		//	outtextxy(44+Best[0][i][j][2]/3, 8+k, b);
		//	outtextxy(50+Best[0][i][j][2]/3, 8+k, c);  //��С����� 
		}
        }
        
     //   huaxian(count);
        jxshuru(time,count1);
         	// if(time<time_min)
         	 //{
         	 	time+=20;
			  //}
			 // else
         	 //{
         	 //	time=time_min;
			 // }
         	if(time>time_min*3/2)
         	{
         		let=t_max();
         		xyprintf(700,305,"���ʱ�䣺%d",let);
         		out(); 
         		output_file_best();
			 }
		}
        //................................................................................................. 
        
        
      
       
		getch();
 
        closegraph();
       
}

void out()
{
	FILE *fptr;
	int i = 0, j = 0;
	if ((fptr = fopen("putout2.txt", "w")) == NULL)
	{
		printf("There is not a file.");
	}
	else
	{
		int num = 0;
		int i = 0,m=0;
		for (; i < num_m; i++) {
			fprintf(fptr, "M%d��", i);
			int j = 0;
			 
			for (; j < m_gongjian[i]; j++) {
				if(d[m]==i&& Best1[0][i][j-1][3]<=g[m]&& Best1[0][i][j][2]>=g[m]+e[m])
				{
						fprintf(fptr, "(%d,����,%d)", g[m],g[m]+e[m]);
						m++;
			
				 } 
				 else{
				 
				fprintf(fptr, "(%d,%d-%d,%d)", Best1[0][i][j][2], Best1[0][i][j][1], Best1[0][i][j][4], Best1[0][i][j][3]);
}
			}
			fprintf(fptr, "\n");
		}
		fprintf(fptr, "Time Used:%.3fs\n", wgt);
		fprintf(fptr, "End Time:%d.\n", t_max());
		fclose(fptr);
	}
}
void jxshuru(int time,int count1)
{
	
    char a[2],b[4],c[3];
    int i,j,k=0,p_jx=0,tc=0;
		i=0;
		for (; i < num_m; i++) {
	    k+=260/(num_m);
		j = 0;
		for (;j<m_gongjian[i];j++ )  
		{
			setfillcolor(RGB(Best[0][i][j][1]*131%256,Best[0][i][j][1]*2013%256,Best[0][i][j][1]*1999%256)); 
			if(Best1[0][i][j][2]<=time)
			{
				if(Best1[0][i][j][3]<time)
				{
					bar(40+Best1[0][i][j][2]/count1,310+k,40+Best1[0][i][j][3]/count1,320+k);
					
				}
				else if(Best1[0][i][j][3]>=time)
				{
					bar(40+Best1[0][i][j][2]/count1,310+k,40+time/count1,320+k);
				}
			}
			
		}
	    
	} 
	i=0;
	k=0;
	for (; i < num_m; i++) {
	    k+=260/(num_m);
		j = 0;
		for (;j<m_gongjian[i];j++ )  
		{
			if(Best1[0][i][j][2]<=time)
			{
				if(Best1[0][i][j][3]<=time)
				{
			//		line(40+Best1[0][i][j][3]/count,310+k,40+Best1[0][i][j][3]/count,320+k);
				}
			}
		}
	    
	} 

	

	
	xyprintf(2,302,"%d",time); 
	if(kbhit()!=0)
		{
			int sh;
			inputbox_getline("������", "������", a, 2);
			sh=atoi(a);
		
			j_m=sh;
			inputbox_getline("������", "����ʱ��", b, 4);
		    state=1;
			j_t=atoi(b);
			mc++;
			d[mc]=j_m;
			e[mc]=j_t;
			f[mc]=time;
			
			for(j=0;Best1[0][j_m][j][2]<time;j++)
		    {
		    	ma=j; 
			}
		 	 
	        input_jx( j_m, j_t,time);

	        
			
	        
		}
		
			for(i=0;i<=mc;i++)
	{
	  //����ɫ��
	setfillcolor(LIGHTBLUE);
    bar(40+g[i]/count1,310+260/num_m*(d[i]+1),40+(g[i]+e[i])/count1,320+260/num_m*(d[i]+1));
    

}
		 tc=40; 
		for(i=0;i<=mc;i++)
		{
			xyprintf(1005,tc-20,"���޻�����%d",d[i]);
	        xyprintf(1100,tc-20,"����ʱ�䣺%d",e[i]);
	        xyprintf(1005,tc,"��ʼʱ�䣺%d",g[i]);
		    xyprintf(1100,tc,"����ʱ�䣺%d",g[i]+e[i]);
	        tc+=40;
	    }

		    
}

void input_jx(int j_m,int j_t,int time)             //���������޺�ʱ�� 
{
	int i,j,t,k=0,s=0,l=0,num=0,lt=0,q=0,w=0;
            ma++;
            if(time>=Best1[0][j_m][ma-1][3])
                {
                	counttime=time;
                	s=Best1[0][j_m][ma][2]-time;
                	for (i=0; i < num_m; i++)
	                {
		            for (j = 0;j<m_gongjian[i] ; j++) 
		            {
                	    if(Best1[0][i][j][2]>=counttime){
                    Best1[0][i][j][2]+=(j_t-s);
	                Best1[0][i][j][3]+=(j_t-s);
        	    }
				}
 
                }
            }
                else if(time<Best1[0][j_m][ma-1][3])
			    {
			    	counttime=Best1[0][j_m][ma-1][3];
			    	
                    s=Best1[0][j_m][ma][2]-Best1[0][j_m][ma-1][3];
                    if(s<j_t){
					
                    for (i=0; i < num_m; i++)
	                {
		            for (j = 0;j<m_gongjian[i] ; j++) 
		            {
                	    if(Best1[0][i][j][2]>=counttime){
                    Best1[0][i][j][2]+=(j_t-s);
	                Best1[0][i][j][3]+=(j_t-s);
        	    }
				}
			    }
			}
			}
			    g[mc]=counttime;
	t=Best1[0][j_m][ma][1];//��Ʒ��
	l=Best1[0][j_m][ma][4]+1;//�����
	lt=Best1[0][j_m][ma][3];//ͬһ��Ʒ��һ�������ʱ�� 

}

 void huaxian(int count){
        int i,j,k=0;
        for(i=0;i<num_m;i++)//��ͼx�ᣬy���123����ÿ���������� 
		{
		k+=260/(num_m);
        //������ͼ�ķ��� 
       for (j=0; j <m_gongjian[i]; j++) {
       	 
		
		   line(40+Best[0][i][j][3]/count,10+k,40+Best[0][i][j][3]/count,20+k);
		
		//	outtextxy(44+Best[0][i][j][2]/3, 8+k, b);
		//	outtextxy(50+Best[0][i][j][2]/3, 8+k, c);  //��С����� 
		}
        }
    }
void input_jianpan_changpin(void) {        		//���̶������� 
	scanf("%d %d", &num_p, &num_m);
	int k = 0;
	int i = 0;
	for (; i < num_p; i++) {
		int j = 0;
		char ch = 60;
		for (; ch != '\n'; scanf("%c", &ch)) {

			scanf("%d", &changpin[0][k][2]);
			scanf("%d", &changpin[0][k][3]);
			changpin[0][k][0] = i;
			changpin[0][k][1] = j;
			j++;
			k++;
			p_gongjian[i] = j;
		}
	}
	all_gongjian = k;
	
	//print_changpin(0);
}

void scdd()
{
	xyprintf(600,20,"%d",num_p);
    xyprintf(640,20,"%d",num_m);
	int k = 0;
	int i = 0;
	int s=20;//����y�� 
   int a,b;
   int atime;
	for (; i < num_p; i++) {
		atime=20;//����x�� 
		int j = 0;
		int x = 0;
		for (; x <num_m; x++) {
			a=changpin1[0][k][2];
            b=changpin1[0][k][3];
			xyprintf(540+atime,20+s,"%d",a);
            xyprintf(560+atime,20+s,"%d",b);
			j++;
			k++;
			atime+=40;
			p_gongjian[i] = j;
		}
		s+=15;
	}
}
void input_file_changpin(void) {				//�ļ��������� 

	FILE*fptr;
	fptr = fopen("input.txt", "r");

	if (fptr == NULL) {
		printf("can't open the file!\n");
		return;
	}
	fscanf(fptr, "%d %d", &num_p, &num_m);
    xyprintf(600,20,"%d",num_p);
    xyprintf(640,20,"%d",num_m);
	int k = 0;
	int i = 0;
	int s=20;//����y�� 
   int a,b;
	for (; i < num_p; i++) {
		 int atime=20;//����x�� 
		int j = 0;
		int x = 0;
		for (; x <num_m; x++) {
			fscanf(fptr, "%d", &changpin[0][k][2]);
			fscanf(fptr, "%d", &changpin[0][k][3]);
			a=changpin[0][k][2];
            b=changpin[0][k][3];
            changpin1[0][k][2]=a;
            changpin1[0][k][3]=b;
			xyprintf(540+atime,20+s,"%d",a);
            xyprintf(560+atime,20+s,"%d",b);
			changpin[0][k][0] = i;
			changpin[0][k][1] = j;
			j++;
			k++;
			atime+=40;
			p_gongjian[i] = j;
		}
		s+=15;
	}
	all_gongjian = k;

	fclose(fptr);
}
void output_file_best(void){					//�ļ������ѽ�� 
	FILE *fptr;
	int i = 0, j = 0;
	if ((fptr = fopen("putout1.txt", "w")) == NULL)
	{
		printf("There is not a file.");
	}
	else
	{
		int num = 0;
		int i = 0;
		for (; i < num_m; i++) {
			fprintf(fptr, "M%d��", i);
			int j = 0;
			 
			for (; j < m_gongjian[i]; j++) {
				fprintf(fptr, "(%d,%d-%d,%d)", Best[0][i][j][2], Best[0][i][j][1], Best[0][i][j][4], Best[0][i][j][3]);
	
			}
			fprintf(fptr, "\n");
		}
		fprintf(fptr, "Time Used:%.3fs\n", wgt);
		fprintf(fptr, "End Time:%d.\n", t_max());
		fclose(fptr);
	}
}

void print_mach(int num) {						//���machine������ 
	int i = 0;
	for (; i < num_m; i++) {
		printf("M%d��", i);

		int j = 0;
		for (; j < m_gongjian[i]; j++) {
			printf("(%d,%d,%d,%d,%d)", machine[num][i][j][0], machine[num][i][j][1], machine[num][i][j][2], machine[num][i][j][3], machine[num][i][j][4]);
		}
		printf(".\n");

	}
}
void print_zuiyou(void) {						//���Best������ 
	int num = 0;
	int i = 0; 
	for (; i < num_m; i++) {
		printf("M%d��", i);
		int j = 0;
		for (; j < m_gongjian[i]; j++) {
			printf("(%d,%d-%d,%d)", Best[0][i][j][2], Best[0][i][j][1], Best[0][i][j][4], Best[0][i][j][3]);
		}
		printf(".\n");
	}
}
void print_changpin(int num){					//���changpin������ 
	int x = 0;
	int t = 1;
	int i = 0;
	for (; i < all_gongjian; i++)
	{
		printf("(%d,%d,%d,%d)", changpin[num][i][0], changpin[num][i][1], changpin[num][i][2], changpin[num][i][3]);

		if (t == p_gongjian[x]) {
			printf("\n");
			x++;
			t = t - p_gongjian[x - 1];
		}
		t++;
	}
	printf("\n\n");
}
void put_changpin(int num){
	int x = 0;
	int t = 1;
	int i = 0;
	for (; i < all_gongjian; i++)
	{
		printf("(%d,%d,%d,%d)", changpin[num][i][0], changpin[num][i][1], changpin[num][i][2], changpin[num][i][3]);

		if (t == p_gongjian[x]) {
			printf("\n");
			x++;
			t = t - p_gongjian[x - 1];
		}
		t++;
	}
	printf("\n\n");
}
int max1(int a, int b) 							//ȡ���ֵ 
{
	return (a > b ? a : b);
}
int min1(int a, int b) {						//ȡ��Сֵ 
	return (a < b ? a : b);
}

int time_mach(int num) {						//����machine[nunm]��ʱ�� 
	int time_pro[100] = { 0 };					//���ٺŲ�Ʒ �Ѽӹ�ʱ��
	int time_mach[100] = { 0 };					//���ٺû���������ʱ��
	int cishu_pro[100] = { 0 };					// ���ٺŲ�Ʒ�Ѽӹ� ����
	int cishu_mach[100] = { 0 };				//���� �Ѽӹ� ����

	int i = 0;
	int error1 = 0;
	int MAX = 0;
	int t = 0;

	for (t=0; t < all_gongjian; ) {
		i = i % num_m;							//iΪ��������δ�1��num_m�仯

		if (machine[num][i][cishu_mach[i]][4] == cishu_pro[machine[num][i][cishu_mach[i]][1]]) {
			int Max = max1(time_mach[i], time_pro[machine[num][i][cishu_mach[i]][1]]);

			machine[num][i][cishu_mach[i]][2] = Max;
			machine[num][i][cishu_mach[i]][3] = Max + machine[num][i][cishu_mach[i]][0];

			Max = machine[num][i][cishu_mach[i]][3];
			time_mach[i] = machine[num][i][cishu_mach[i]][3];
			time_pro[machine[num][i][cishu_mach[i]][1]] = time_mach[i];

			cishu_mach[i]++;
			cishu_pro[machine[num][i][cishu_mach[i] - 1][1]]++;
			error1 = 0;

			t++;
			MAX = max1(MAX, Max);
			/*			printf("MAX=%d\n", MAX);

			printf("t=%d\t\n", t);
			printf("cishu  mach  :\t");
			for (int x = 0; x < num_m; x++) {
			printf("%d ", cishu_mach[x]);
			}
			printf("\ncishu  pro:\t");
			for (int x = 0; x < num_p; x++) {
			printf("%d  ", cishu_pro[x]);
			}
			printf("\n");
			*/
		}
		i++;

		if (error1 > 1 + num_m) {
			return -1;
		}
		error1++;
	}

	return MAX;
}

int  c_time(int num)							//����changpin��ʱ�� 
{
	int m_endtime[1000]={0};
	int p_endtime[1000]={0};//��¼��������Ʒ��n���������ʱ��
	int m_num[1000]={0},p_num[1000]={0};//��¼����n�Ͳ�Ʒn�Ѿ������˼������� 
	int Max=0,MAX=0;   //MAX�����ʱ�� 
	int i=0;
	for(i=0;i<all_gongjian;i++)
	{
		Max=max1(p_endtime[changpin[num][i][0]],m_endtime[changpin[num][i][2]]);  //�Ҹò�Ʒ��Ӧ�Ļ������ȽϿ�ʼʱ��
		p_endtime[changpin[num][i][0]]=Max+changpin[num][i][3];                        
		m_endtime[changpin[num][i][2]]=Max+changpin[num][i][3];						   // ��Ʒ����ʱ�� ��������ʱ�� 
		Max=Max+changpin[num][i][3];      //��¼������ʱ�� 
		MAX=max1(MAX,Max);	            
	} 
	return MAX;
}
void copy_machine(int num_1, int  num_2)    //�ѷ���num1copy������num2
{
	int i = 0;
	for (; i < num_m; i++) {
		int j = 0;
		for (; j < m_gongjian[i]; j++) {
			int k = 0;
			for (; k < 5; k++) {
				machine[num_2][i][j][k] = machine[num_1][i][j][k];
			}
		}
	}
}
void m_better(int num_1, int num_2)
{
	int i = 0;
	for (; i < num_m; i++) {
		int j = 0;
		for (; j < m_gongjian[i]; j++) {
			int k = 0;
			for (; k < 5; k++) {
				jiaohuan(&machine[num_1][i][j][k], &better[num_2][i][j][k]);
			}
		}
	}
}
void b_Best(int num_2) {
	int i = 0;
	for (; i < num_m; i++) {
		int j = 0;
		for (; j < m_gongjian[i]; j++) {
			int k = 0;
			for (; k < 5; k++) {
				jiaohuan(&Best[0][i][j][k], &better[num_2][i][j][k]);

			}
		}
	}
}
void copy_changpin(int num1, int num2) {
	int i = 0;
	for (; i < all_gongjian; i++) {
		int j = 0;
		for (; j < 4; j++) {
			changpin[num2][i][j] = changpin[num1][i][j];
		}
	}
}
void copy_all(int a[100][100][5], int b[100][100][5]) {
	int i = 0;
	int j = 0; int k = 0;
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			for (k = 0; k < 5; k++) {
				jiaohuan(&a[i][j][k], &b[i][j][k]);

			}
		}
	}
}

void zhuangma_changpin_mach(int num1, int num2)   //num1Ϊchangpin ,num2Ϊmachine
{
	int cishu_mach[100] = { 0 };
	int i = 0;
	for (i=0; i < all_gongjian; i++) {

		int jiqi = changpin[num1][i][2];
		machine[num2][jiqi][cishu_mach[jiqi]][0] = changpin[num1][i][3];
		machine[num2][jiqi][cishu_mach[jiqi]][1] = changpin[num1][i][0];
		machine[num2][jiqi][cishu_mach[jiqi]][4] = changpin[num1][i][1];

		//		printf("i=%d", i);
		//		printf("cishu_mach[%d]=%d\n", jiqi, cishu_mach[jiqi]);
		cishu_mach[jiqi]++;

	}
	for (i=0; i < num_m; i++) {
		m_gongjian[i] = cishu_mach[i];         //!!??p_gongjian;
	}
}
void jiaohuan(int* x, int *y)					//��������
{
	int z = *x;
	*x = *y;
	*y = z;
}

void create_parent(void)						//�����ױ� 
{
	
	int jishu=0;
	int num1, num2;
	srand((unsigned)time(NULL));
	
	zhuangma_changpin_mach(0, 0);
	
	time_m[0] = time_mach(0);
	int time_2=0;
	int number = 1;	
	int xunhuan=0;
	int u=0;
	for(u=0;u<1;u++)
	for(xunhuan=0;xunhuan<1000;xunhuan++){
	
	for (number=1; number <1001;) {
		
		copy_changpin(number-1, number);
		int i = 0;
		int j = 0;
			for (i=0; i < 10; i++) {
				int num1 = rand() % all_gongjian;
					int num2 = (rand()) % all_gongjian;
					if (changpin[number][num1][0] != changpin[number][num2][0])
				{
						for (j=0; j < 4; j++) {
					jiaohuan(&changpin[number][num1][j], &changpin[number][num2][j]);
			}
		}
	}

			xiugai_end(number );
			
			zhuangma_changpin_mach(number, number);

			int time_ = time_mach(number );
			time_m[number] = time_;

	//		int time_  =c_time(number);
//			time_changpin[number]=time_;
						
			if (time_ != -1)
			{
			if (time_ < time_min) {
				m_better(number , 0);
				b_Best(0);
			}
			else if (time_2 > time_) {
				m_better(number , 1);
			}
			time_min = min1(time_min, time_);

		}

		number++;
		jishu++;

	}
	}
}

void bianyi_changpin(int number)				//������� 
{
	int i = 0;
	int j = 0;
	for (i=0; i < 15; i++) {
		int num1 = rand() % all_gongjian;
		int num2 = (rand()+5) % all_gongjian;
		if (changpin[number][num1][0] != changpin[number][num2][0])
		{
			for (j=0; j < 4; j++) {
				jiaohuan(&changpin[number][num1][j], &changpin[number][num2][j]);
			}
		}
	}
}

void xiugai_end(int number){					//�޸Ĵ������� 
	int i=0,j=0,k=0;
	for(i=0;i<num_p;i++){
		int cishu=0;
		for(j=0;j<all_gongjian;j++){
			if(i==changpin[number][j][0]){
				if(cishu==changpin[number][j][1]){
				cishu++;
			}else {
				int x;
				for(x=j;x<all_gongjian;x++){
					if(i==changpin[number][x][0]&&cishu==changpin[number][x][1]){
						int y=0;
						for(y=0;y<4;y++){
							jiaohuan(&changpin[number][j][y],&changpin[number][x][y]);
						}
						break;
					}
				}
				cishu++;
			}
		}
	}
	
}
}



int t_max()
{
	int i,j,max=Best1[0][0][num_p-1][3];
	for (i=1; i < num_m; i++)
	{
		if(Best1[0][i][num_p-1][3]>max)
		{
			max=Best1[0][i][num_p-1][3];
		}
	    
    }
    return max;
}
void yanhou1(int i,int k)
{
    int g=0,j=0;
	for (j = k;j<num_p ; j++)
    {
	if(Best1[0][i][j][2]<Best1[0][i][j-1][3])
	{
		g=Best1[0][i][j-1][3]-Best1[0][i][j][2];
		Best1[0][i][j][2]+=g;
	    Best1[0][i][j][3]+=g;
	}
    }
}

void secai()
{
	int i,v=30;
	for(i=0;i<num_p;i++)
        {
        	xyprintf(5+v,640,"%d",i);
        	setfillcolor(RGB(i*131%256,i*2013%256,i*1999%256));
        	bar(5+v,660,35+v,680);
        	v+=30;
		}
		outtextxy(5+v,640, "����");
		setfillcolor(LIGHTBLUE);
        bar(5+v,660,35+v,680);
}
