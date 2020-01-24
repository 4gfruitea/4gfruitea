#include<stdio.h>
#include<ctime>
#include<cstdlib>
int t=1;
typedef struct spe{
	int a;
	int b;
	int c;
	int x;
}SPE;
class env{
	public:
		int y;
		int z;
		
		void competence(SPE *s1,SPE *s2){
			int temp;
			if(s1->c*s1->x+s2->c*s2->x<y){
				s1->x*=1+s1->b;
				s2->x*=1+s2->b;
			}
			else{
				temp=s1->x;
				s1->x=(float)s1->x*s1->a*y/((s1->x*s1->a+s2->x*s2->a)*s1->c)+1;
				s2->x=(float)s2->x*s2->a*y/((temp*s1->a+s2->x*s2->a)*s2->c)+1;
			}
			printf("第%d轮:环境资源数量为%d;物种1数量为%d;物种2数量为%d\n",t,y,s1->x,s2->x);
		}
		
		void change(void){
			y=10000*(1+(rand()%100-50)*(float)z/5000);
		}
};

int main(){
	SPE p,q;
	SPE *s1=&p,*s2=&q;
	env world;
	s1->a=20;
	s1->b=1;
	s1->c=10;
	s1->x=10;
	s2->a=1;
	s2->b=9;
	s2->c=1;
	s2->x=10;
	world.y=10000;
	world.z=100;
	srand((int)time(NULL));
	for(t=1;t<=100&&s1->x>=10&&s2->x>=10;t++){
		world.change();
		world.competence(s1,s2);
	}
	if(s1->x<10)
	    printf("物种2胜利");
	else if(s2->x<10)
	    printf("物种1胜利"); 
	else
	    printf("两物种达成平衡"); 
}
