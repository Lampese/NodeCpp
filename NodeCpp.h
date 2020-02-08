void eval(string js_line,string url){
	if(url=="")url="eval.js";
	ofstream out;
	out.open(url.c_str());
	out<<js_line;
	out.close();
	string rsur="node "+url;
	system(rsur.c_str());
	remove(url.c_str());
}
int str_to_int(string str){
	int number=0;
	for(int i=0;i<str.size();i++)
		number=(number<<1)+(number<<3)+(str[i]^48);
	return number;
}
string json_in(string json_string,string what,string cfrom_url){
		ofstream out;
		string jsurl=cfrom_url+"json.js";
		out.open(jsurl.c_str());
		out<<"var fs = require('fs');\n";
		out<<"var json="<<json_string<<";\n";
		out<<"fs.writeFile('test.txt',"<<"json."<<what<<",()=>{} );";
		out.close();
		string openjs="node "+jsurl;
		system(openjs.c_str());
		ifstream in;
		string end;
		string txturl=cfrom_url+"test.txt";
		in.open(txturl.c_str());
		in>>end;
		in.close();
		remove(jsurl.c_str());
		remove(txturl.c_str());
		return end;
}
class Node_js{
	public:
		string jsurl;
		void in(string js_line){
			 if(jsurl=="")jsurl="eval.js";
			 ofstream file(jsurl.c_str(),ios::app);
			 file<<js_line;
			 file.close();
		}
		void run(){;
			string rsur="node "+jsurl;
			system(rsur.c_str());
		}
		void del(){
			ofstream out;
			out.open(jsurl.c_str());
			out<<"";
			out.close();
		} 
};
