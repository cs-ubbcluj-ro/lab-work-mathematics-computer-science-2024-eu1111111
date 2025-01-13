#include <map>

#include <iterator>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;





typedef struct {
 int n;
 int elem[200][2];
} FIP;

FIP fip;
vector<string> st;
int pozTS=0;





void addFIP(int cod, int posST, FIP& f){
 f.elem[f.n][0]=cod;
 f.elem[f.n++][1]=posST;
}

int addST( string symbol, vector<string>& st, FIP& fip )
{
	auto it=upper_bound(st.begin(),st.end(),symbol);
	int position=it-st.begin();
	if (position>0 && symbol.compare(st[position-1])==0){
		return position-1;
	}
	else{
		for(int i=0;i<fip.n;i++)
			if((fip.elem[i][0]==0 || fip.elem[i][0]==1) && fip.elem[i][1]>=position)
				fip.elem[i][1]++;
		st.insert(it,symbol);
		return position;
	}
	
	
}

void addErr(string text, int line, string message, string& error){
	error.append("ERROR: ").append(text).append(" at line ").append(to_string(line)).append(" - ").append(message).append("\n\n");
}

void printFIP(FIP& f){
	ofstream fipFile;
    fipFile.open("FIP.txt");
	cout<<"nr elem fip"<<f.n<<endl;
	cout<<"Forma interna a programului: "<<endl;
	for(int i=0;i<f.n;i++){
		fipFile<<f.elem[i][0]<<" "<<f.elem[i][1]<<endl;
	         cout<<f.elem[i][0]<<" "<<f.elem[i][1]<<endl;
	}

	fipFile.close();
}


void printST( vector<string>& st)
{
	ofstream stFile;
	stFile.open("ST.txt");
	stFile<<"SYMBOL TABLE: nr elems ST "<<st.size()<<endl;
	for(int i=0; i<st.size(); i++)
	{
		stFile<<i<<" "<<st[i]<<endl;
	}
	stFile.close();
}


void printErr(string& error){
	ofstream errorFile;
	errorFile.open("Errors.txt");
	errorFile<<error;
	cout<<error<<endl;
	errorFile.close();
}