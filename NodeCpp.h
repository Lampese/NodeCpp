class Node{
	public:	
		string url="";
		void eval(string js_line){
			if(url=="")url="eval.js";
			ofstream out;
			out.open(url.c_str());
			out<<js_line;
			out.close();
			string rsur="node "+url;
			system(rsur.c_str());
		}
		void del(){
			ofstream out;
			out.open(url.c_str());
			out<<"";
			out.close();
		} 
};
class Node_js{
	public:
		string jsurl;
		void in(string js_line){
			 if(jsurl=="")jsurl="eval.js";
			 ofstream file(jsurl.c_str(),ios::app);
			 file<<js_line;
			 file.close();
		}
		void run(){
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
