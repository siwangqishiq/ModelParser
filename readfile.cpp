#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

std::string& trim(std::string &s, std::string suffix = " "){
	if (s.empty()) 
		return s;
	     
	s.erase(0,s.find_first_not_of(suffix));
	s.erase(s.find_last_not_of(suffix) + 1);
	return s;
}

class ParseObj{
public:
	bool debug = false;
	int parse(std::string filePath){
		std::ifstream infile(filePath);
		
		if(infile.is_open()){
			std::string line;
			while(std::getline(infile , line)){
				//std::cout << "read file line : " << line << std::endl;
				readFileLine(line);
			}
		}

		infile.close();
	}
private:
	void readFileLine(std::string &line){
		std::string content = trim(line , "\t");
		
		if(content[0] == '#'){ //此行为注释
			return; 
		}
		if(debug){
			std::cout << content << std::endl;
		}

		std::vector<std::string> contents;
		std::istringstream in(content);
		std::string tmp;
		while(in >> tmp){
			//std::cout << tmp;
			contents.push_back(tmp);
		}//end while
		//std::cout << std::endl;

		for(std::string &c : contents){
				
		}//end for each

		size_t dimension = contents.size();
		std::cout << dimension << std::endl;
		switch(contents[0]){
			case "v"://顶点
			std::cout << contents[1] << " " << contents[2] << "  " << contents[3] << std::endl;

			break;
		}//end switch
	}

};


int main(int argc , char *argv[]){
	ParseObj parser;
	parser.parse(std::string("01Alocasia_obj.obj"));

	return 0;
}

