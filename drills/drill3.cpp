#include"std_lib_facilities.h"



int main()

{

string first_name, friend_name;

cout<<"Please enter your first name!\n";

cin>>first_name;

cout<<"Hello, "<<first_name<<endl;

cout<<"Enter the name of the friend you want to write the letter to\n";

cin>>first_name;

cout<<"Enter an other friend's name!"<<endl;
cin>>friend_name;


char friend_sex=0;
char m='m';
char f='f';

int age=0;

cout<<"Enter m if your friend is a male and enter a f if your friend is a female!"<<endl;

cin>>friend_sex;

if (friend_sex==m)
cout<<"If you see "<<friend_name<<" tell him to call me."<<endl;
else if (friend_sex==f)
cout<<"If you see "<<friend_name<< "tell her to call me."<<endl;
else cout<<"Invalid data"<<endl;


cout<<"Enter your friend's age!"<<endl;

cin>>age;

if (age <=0 || age>=110) error("you are kidding!");


cout<<"Dear "<<first_name<<","<<endl;
cout<<"How are you lately? I hope everything is fine. We are doing great over here in city xyz."<<endl;
cout<<"Hope we can meet up soon."<<endl;
cout<<"Have you seen "<<friend_name<<" lately?"<<endl;

cout<<"I hear you just had your birthday and you are "<<age<<" years old."<<endl;

if (age<12) cout<<"Next year you will be "<<age+1<<"."<<endl;
if (age==17) cout<<"Next year you will be able to vote."<<endl;
if (age>70) cout<<"I hope you are enjoying retirement."<<endl;

cout<<"Yours sincerely,"<<endl<<endl<<"Bence"<<endl;


return 0;


}