# include <iostream>
using namespace std;

int sum(int arr[],int size){
	if(size==0){
		return 0;
	}
	int c=0;
	if(size==1){
		return arr[0]+c;
	}
	else {
		c=arr[0]+c;
		sum(arr+1,size-1);
		return c;
	}
}
int main(){
	int arr[]={2,2,5,1,6};
	cout<<"sum"<<sum(arr,5);
	return 0;
}
