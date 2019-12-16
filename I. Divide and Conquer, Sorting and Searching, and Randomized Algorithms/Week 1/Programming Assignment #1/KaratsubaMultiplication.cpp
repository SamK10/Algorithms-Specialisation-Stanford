#include<iostream>
#include<string>
#include<math.h>
using namespace std;

string sum(string s1, string s2){
	
	int sizediff=(s1.size()-s2.size());
	
	if(sizediff>0){
		for(int i=0;i<sizediff;i++){
			s2.insert(0,"0");
		}
	}
	
	else if(sizediff<0){
		for (int i = 0; i < -sizediff; i++)
		{
			s1.insert(0,"0");
		}
	}
	
	int carry=0;string sums;
	
	for(int i=s1.size()-1;i>=0;i--){
		sums.insert(0,to_string((((s1[i]-'0')+(s2[i]-'0')+carry)%10)));
		carry=(((s1[i]-'0')+(s2[i]-'0')+carry)/10);
		//cout<<"Adding "<<s1[i]<<"+"<<s2[i]<<" Carry="<<carry<<endl;
	}
	
	if(carry){
		/*for(int i=sums.size()-1;i>=0;i--){
			sums[i+1]=sums[i];
		}*/
		sums.insert(0,to_string(carry));
		//cout<<"Carrying"<<endl;
	}
	
	return sums;
}

string subt(string s1, string s2){
	
	int sizediff=(s1.size()-s2.size());
	
	if(sizediff>0){
		for(int i=0;i<sizediff;i++){
			s2.insert(0,"0");
		}
	}
	
	else if(sizediff<0){
		for (int i = 0; i < -sizediff; i++)
		{
			s1.insert(0,"0");
		}
	}	
	
	int diff=0;string result;
	
	for(int i=s1.size()-1;i>=0;i--){
		//cout<<"Subtracting "<<s1[i]<<"-"<<s2[i]<<endl;
		diff = (s1[i]-'0')-(s2[i]-'0');
		if(diff<0){
			diff = diff+10;
			s1[i-1]-=1;
			//cout<<"Borrowing"<<endl;
		}
		result.insert(0, to_string(diff));
	}
	
	return result;
}

string mult(string s1, string s2){
	
	int n=s1.size();
	//cout<<"n="<<n<<endl;
	
	if(n==1){
		int pd=(s1[0]-'0')*(s2[0]-'0');
		return to_string(pd);
	}
	
	//cout<<s1<<" "<<s2<<endl<<endl;
	string a = s1.substr(0,n/2); //cout<<a<<endl;
	string b = s1.substr(n/2,n/2); //cout<<b<<endl;
	string c = s2.substr(0,n/2); //cout<<c<<endl;
	string d = s2.substr(n/2,n/2); //cout<<d<<endl<<endl;

	string ac = mult(a,c);//cout<<ac<<endl;
	string bd = mult(b,d);//cout<<bd<<endl;
	string ad = mult(a,d);//cout<<ad<<endl;
	string bc = mult(b,c);//cout<<bc<<endl;
	string ad_bc = sum(ad,bc);//cout<<ad_bc<<endl<<endl;
			
	string pd1,pd2,pd3;

	for(int i=0;i<n;i++){
		pd1=ac.insert(ac.size(),"0");
		//cout<<pd1<<endl;
	}
			
	for (int i = 0; i < n/2; ++i){
		pd2=ad_bc.insert(ad_bc.size(),"0");
		//cout<<pd2<<endl;
	}

	//cout<<"sum = "<<sum<<endl<<endl;
	return sum(pd1,sum(pd2,bd));
		
}

int main(){
	//cout<<sum("2700",sum("390","4"));
	cout<<"Product = "<<mult("3141592653589793238462643383279502884197169399375105820974944592","2718281828459045235360287471352662497757247093699959574966967627")<<endl;
	return 0;
}