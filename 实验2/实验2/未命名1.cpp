#include<iostream>
using namespace std;
int NO;
class jihe;
void start(jihe &A,jihe &B);
int fun(jihe A,int a);
class jihe{
	string name;
	int sum;
	public:
		int *a;
		string getname(){
			return name;
		}
		jihe() = default;
		jihe(string p){
			name = p;
		};
		int getsum(){
			return sum;
		}
		void init(int n);
		void init(int aa,int bb,int ch);
		void show();
		friend void bing(jihe &C,jihe A,jihe B);
		friend void jiao(jihe &C,jihe A,jihe B);
		friend void conbu(jihe &C,jihe A,jihe B);
		friend void juebu(jihe &C,jihe A,jihe B);
		friend void dccha(jihe &C,jihe A,jihe B);
};


void jihe::show(){
	int i = 0;
	while(a[i]!=NO&&i<sum){
		cout<<name<<"["<<i<<"] = "<<a[i]<<endl; 
		i++;
	}
}
void jihe::init(int n){
	int i;
	sum = n;
	a = new int[n];
	for(i=0;i<n;i++){
		cout<<"请输入"<<name<<"中第"<<i+1<<"个元素："<<endl; 
		cin>>a[i];
	}
}
void jihe::init(int aa,int bb,int ch){
	switch(ch){
		case 1:{
			int t = aa+bb;
			sum = t;
			a = new int[t];
			break;
		}
		case 2:{
			int t = aa>bb?aa:bb;
			sum = t;
			a = new int[t];
			break;
		}
	}
	int i;
	for(i = 0;i < sum;i++){
		a[i] = NO;
	}
}
void bing(jihe &C,jihe A,jihe B){
	C.init(A.getsum(),B.getsum(),1);
	int i,j,k = 0;
	for(i = 0;i<A.getsum();i++){
		if(fun(C,A.a[i])){
			C.a[k++] = A.a[i];
		}
	}
	for(i = 0;i<B.getsum();i++){
		if(fun(C,B.a[i])){
			C.a[k++] = B.a[i];
		}
	}
}
void jiao(jihe &C,jihe A,jihe B){
	C.init(A.getsum(),B.getsum(),2);
	int i,j,k = 0;
	for(i = 0;i<A.getsum();i++){
		for(j = 0;j<B.getsum();j++){
			if(A.a[i]==B.a[j]&&fun(C,A.a[i])){
				C.a[k++] = A.a[i];
			}
		}
	}
}
void conbu(jihe &C,jihe A,jihe B){
	C.init(A.getsum(),0,2);
	int i,j,k = 0;
	for(i = 0;i<A.getsum();i++){
		if(fun(B,A.a[i])){
			C.a[k++] = A.a[i];
		}
	}
}
void dccha(jihe &C,jihe A,jihe B){
	C.init(A.getsum(),B.getsum(),1);
	jihe D,E;
	D.init(A.getsum(),B.getsum(),1);
	E.init(A.getsum(),B.getsum(),2);
	bing(D,A,B);
	jiao(E,A,B);
	conbu(C,D,E);
}
int fun(jihe A,int a){
	int i;
	int judge = 1;
	for(i=0;i<A.getsum();i++){
		if(a==A.a[i]){
			judge = 0;
			break;
		}
	}
	return judge;
}


int main(){
	cout<<"请输入一个集合中不会出现的数："<<endl;
	cin>>::NO; 
	int a;
	while(a != 0)
	{
	cout<<"请输入运算符号：（1表示并，2表示交，3表示相对补，4表示绝对补，5表示对称差，0表示退出）"<<endl;
	cin>>a;
	switch(a){
		case 1:{
			jihe A("A"),B("B");
			jihe C("C");
			start (A,B);
			bing(C,A,B);
			cout<<"A并B结果为："<<endl;
			C.show();
			break;
		}
		case 2:{
			jihe A("A"),B("B");
			jihe C("C");
			start (A,B);
			jiao(C,A,B);
			cout<<"A交B结果为："<<endl;
			C.show(); 
			break;
		}
		case 3:{
			jihe A("A"),B("B");
			jihe C("C");
			start (A,B);
			conbu(C,A,B);
			cout<<"A-B结果为："<<endl;
			C.show(); 
			break;
		}
		case 4:{
			jihe E("E"),B("B");
			jihe C("C");
			start (E,B);
			conbu(C,E,B);
			cout<<"~B结果为："<<endl;
			C.show(); 
			break;
		}
		case 5:{
			jihe A("A"),B("B");
			jihe C("C");
			start (A,B);
			dccha(C,A,B);
			cout<<"A对称差B结果为："<<endl;
			C.show(); 
			break;			
		}
		default :{
			break;
		}
	}
}
	return 0;
}

void start(jihe &A,jihe &B){
	cout<<"请分别输入"<<A.getname()<<" "<<B.getname()<<"集合的元素个数："<<endl;
	int a,b;
	cin>>a>>b;
	A.init(a);
	B.init(b); 
	cout<<"输入完毕！"<<endl;
}
