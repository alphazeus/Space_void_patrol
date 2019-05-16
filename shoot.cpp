#include<iostream>
#include<conio.h>
#include<windows.h>
#include<vector>
#include<cstdlib>
#include<ctime>

const int sheight=20,swidth=60;
int MAXENEMY=5;
bool gameover=false;
bool fire=false;
int pxpos=3,pypos=sheight/2;
int firexstart=-1,firexstop=-1;
int numenemy=0;
std::vector<std::pair<int,int>> enemycord;
int score=0;
int diff=8;

bool check(int y,int x){
	for(int i=0;i<enemycord.size();i++){
		if(enemycord[i].first==x)
			if(enemycord[i].second==y)
				return true;
	}
	return false;
}

void change(){
	if(kbhit()){
		switch(getch()){
			case 'w':if(pypos>1)
						pypos--;
					break;
			case 's':if(pypos<sheight-2)
						pypos++;
					break;
			case 'a':if(pxpos>1)
						pxpos--;
					break;
			case 'd':if(pxpos<swidth/4)
						pxpos++;
					break;
			case ' ':fire=true;
					break;
			default:break;
		}
	}
	for(int i=0;i<enemycord.size();i++){
		enemycord[i].first--;
	}
	firexstop=-1;
	firexstart=-1;	
}
void testlogic(){
	for(int i=0;i<enemycord.size();i++){
		if(enemycord[i].first<=swidth/4+1)
			gameover=true;
	}
	if(fire){
		int tempx=swidth-2;
		firexstart=pxpos+1;
		for(auto it=enemycord.begin();it!=enemycord.end();it++){
			if(it->second==pypos){
				tempx=it->first-1;
				enemycord.erase(it);
				numenemy--;
				score++;
				break;
			}
		}		
		firexstop=tempx;
		fire=false;
	}
}
void show(){
	std::cout<<"\n\n\t\t\t\t\t\t    SCORE:"<<score<<"\n\n\n";
	for(int i=0;i<sheight;i++){
		for(int j=0;j<swidth;j++){
			if(i==0||j==0||j==swidth-1||i==sheight-1)
				std::cout<<"#";
			else if((i==pypos) && (j>=firexstart) && (j<=firexstop))
				std::cout<<"=";
			else if(j==pxpos && i==pypos)
				std::cout<<">";
			else if(check(i,j))
				std::cout<<"C";
			else if((i>0 && i<sheight-1) && (j==swidth/4+1))
				std::cout<<"|";

			else
				std::cout<<" ";
			if(j==swidth-1)
				std::cout<<"\n";
		}
	}
}

void resetall(){
	enemycord.clear();
	numenemy=0;	
	pxpos=3;
	pypos=sheight/2;
	gameover=false;
	firexstart=-1;
	firexstop=-1;
	score=0;	
}
void difficulty(){
	int select=0;
	while(1){
		system("cls");
		std::cout<<"\n\n\n\n\tSPACE\n\n\tVOID\n\n\tPATROL\n\n\n\n";
		std::cout<<"\t\t   Created by: _ALPHAZEUS_\n";
		std::cout<<"        -----------------------------------\n\t\t";
		if(select==0)std::cout<<"=>";
		else std::cout<<"  ";
		std::cout<<"LOW\n\t\t";
		if(select==1)std::cout<<"=>";
		else std::cout<<"  ";
		std::cout<<"MEDIUM\n\t\t";
		if(select==2)std::cout<<"=>";
		else std::cout<<"  ";
		std::cout<<"HIGH\n\n\n\n";
		std::cout<<"        -----------------------------------\n\t";
		std::cout<<"Use 'W' and 'S' to choose...";
		std::cout<<"\n\tPress SPACE to select the choice...";
		if(kbhit()){
			char s=getch();
			if((s=='W' || s=='w') && (select>0))select--;
			if((s=='S' || s=='s') && (select<2))select++;
			if(s==' ')break;
		}
		Sleep(150);
	}
	if(select==0){
		diff=8;
		MAXENEMY=5;
	}
	else if(select==1){
		diff==13;
		MAXENEMY=7;
	}
	else {
		diff==18;
		MAXENEMY=9;
	}
}
void Menuscreen(){
	int select=0;
	while(1){
		system("cls");
		std::cout<<"\n\n\n\n\tSPACE\n\n\tVOID\n\n\tPATROL\n\n\n\n";
		std::cout<<"\t\t   Created by: _ALPHAZEUS_\n";
		std::cout<<"        -----------------------------------\n\t\t";
		if(select==0)std::cout<<"=>";
		else std::cout<<"  ";
		std::cout<<"START\n\t\t";
		if(select==1)std::cout<<"=>";
		else std::cout<<"  ";
		std::cout<<"DIFFICULTY\n\t\t";
		if(select==2)std::cout<<"=>";
		else std::cout<<"  ";
		std::cout<<"EXIT\n\n\n\n";
		std::cout<<"        -----------------------------------\n\t";
		std::cout<<"Use 'W' and 'S' to choose...";
		std::cout<<"\n\tPress SPACE to select the choice...";
		if(kbhit()){
			char s=getch();
			if((s=='W' || s=='w') && (select>0))select--;
			if((s=='S' || s=='s') && (select<2))select++;
			if(s==' ')break;
		}
		Sleep(150);
	}
	if(select==1){
		difficulty();
		Menuscreen();
	}
	if(select==2)exit(0);
}

void Gameoverscreen(){
		system("cls");
		std::cout<<"\n     ooo            oo        oo       oo  ooooooo\n";
		std::cout<<"   oo   oo         oooo       ooo     ooo  oo\n";
		std::cout<<"  oo     oo       oooooo      oo oo oo oo  oo \n";
		std::cout<<" oo              oo    oo     oo  ooo  oo  ooooo\n";
		std::cout<<"  oo    oooo    oooooooooo    oo       oo  ooooo\n";
		std::cout<<"   oo     oo   oo        oo   oo       oo  oo\n";
		std::cout<<"    oo   oo   oo          oo  oo       oo  oo\n";
		std::cout<<"     oooo    oo            oo oo       oo  ooooooo\n\n\n";
		
		std::cout<<"    oooo     oo            ooo oooooooo ooooooooo\n";
		std::cout<<"   oo  oo     oo           oo  oo       ooo    ooo\n";
		std::cout<<"  oo    oo     oo         oo   oo       oo      oo\n";
		std::cout<<" oo      oo     oo       oo    ooooo    ooo    ooo\n";
		std::cout<<" oo      oo      oo     oo     ooooo    oooooooo \n";
		std::cout<<"  oo    oo        oo   oo      oo       oooooo\n";
		std::cout<<"   oo  oo          oo oo       oo       oo   ooo\n";
		std::cout<<"    oooo            ooo        oooooooo oo    oooo\n\n";

		std::cout<<"\tYOUR SCORE IS ...   ["<<score<<"]";
		std::cout<<"\n\n\tPress 'Q' key to continue...";
		
		while(1){
			if(kbhit()){
				char a=getch();
				if(a=='q' || a=='Q')break;
			}
		}
}

int main(){
	srand(time(0));
	while(1){
		Menuscreen();
		while(!gameover){
			if(numenemy<MAXENEMY && std::rand()%100<(diff+score/10)){
				enemycord.push_back(std::make_pair(swidth-2,(std::rand()%(sheight-2))+1));
				numenemy++;
			}
			system("cls");
			change();
			testlogic();
			show();
			Sleep(50);
		}
		Gameoverscreen();
		resetall();
	}
}