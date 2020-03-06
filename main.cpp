#include"class_definition.h"
#include"headers_and_prototypes.h"

int language=0;//global variable set to choose the language. 0 means Chinese, 1 means English
//you can add supported languages as you like
//by default, I chose UTF-8 as the character set

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
	int mode;
	cout<<"请输入数字来选择语言。0表示中文，1表示英语： "<<endl
            <<"please input a number to choose the language. 0 means Chinese, 1 means English: ";
    cin>>language;
    if(cin.fail()||!(language>=0&&language<=1)){
        cout<<"输入错误。退出中..."<<endl
                <<"input ERROR. quit now...";
        return 0;
    }
    instruction();
	if(language==0) cout<<endl<<"请输入数字:";
	else if(language==1) cout<<endl<<"please input a number:";
	while(cin>>mode&&mode>=0&&mode<=6){
		switch(mode){
		    case 0:func0();break;
			case 1:func1();break;
			case 2:func2();break;
			case 3:func3();break;
			case 4:func4();break;
			case 5:func5();break;
			case 6:func6();break;
			default:return 0;
		}
		if(language==0) cout<<endl<<"请输入数字:";
        else if(language==1) cout<<endl<<"please input a number:";
	}
}
