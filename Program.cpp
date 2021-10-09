#include<bits/stdc++.h>
using namespace std;
int magic[3][3] = {{2,7,6},{9,5,1},{4,3,8}};
bool gameWon(int game[3][3]){
	//rows
	for(int i=0;i<3;i++){
		if((game[i][0]==game[i][1]) && (game[i][0]==game[i][2]) && (game[i][0]!=0))
			return true;
	}
	//cols
	for(int i=0;i<3;i++){
		if((game[0][i]==game[1][i]) && (game[0][i]==game[2][i]) && (game[0][i]!=0))
			return true;
	}
	//right dia
	if((game[0][0]==game[1][1]) && (game[0][0]==game[2][2]) && game[0][0]!=0)
		return true;
	//left dia
	if((game[0][2]==game[1][1]) && (game[0][2]==game[2][0]) && game[0][2]!=0)
		return true;
	return false;
}
void dispalyBoard(int game[3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(game[i][j]==0)
				cout<<" ";
			if(game[i][j]==1)
				cout<<"X";
			if(game[i][j]==2)
				cout<<"O";
			if(j<2)
				cout<<"|";
		}
		cout<<"\n";
		if(i<2)
			cout<<"- - -\n";
	}
}
bool boardEmpty(int game[3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(game[i][j]==0)
				return true;
		}
	}
}
class gameBoard{
	public: int b[3][3];
	gameBoard(){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				b[i][j]=0;
		//b[0][1]=2;
		}

};
int scCal(int game[3][3],int fill){
	int count=0;
	int temp[3][3];
	int opp;
	if(fill==1)
		opp=2;
	else opp=1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			temp[i][j] = game[i][j];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(temp[i][j]==0)
				temp[i][j]=fill;
	//Rows Check
	if( (temp[0][0]==fill || temp[0][1]==fill || temp[0][2]==fill) && (temp[0][0]!=opp && temp[0][1]!=opp && temp[0][2]!=opp) )
		count++;
	if( (temp[1][0]==fill || temp[1][1]==fill || temp[1][2]==fill) && (temp[1][0]!=opp && temp[1][1]!=opp && temp[1][2]!=opp))
		count++;
	if( (temp[2][0]==fill || temp[2][1]==fill || temp[2][2]==fill) && (temp[2][0]!=opp && temp[2][1]!=opp && temp[2][2]!=opp))
		count++;

	//Cols Check
	if( (temp[0][0]==fill || temp[1][0]==fill || temp[2][0]==fill) && (temp[0][0]!=opp && temp[1][0]!=opp && temp[2][0]!=opp))
		count++;
	if( (temp[0][1]==fill || temp[1][1]==fill || temp[2][1]==fill) && (temp[0][1]!=opp && temp[1][1]!=opp && temp[2][1]!=opp))
		count++;
	if( (temp[0][2]==fill || temp[1][2]==fill || temp[2][2]==fill) && (temp[0][2]!=opp && temp[1][2]!=opp && temp[2][2]!=opp))
		count++;

	//Dias Check
	if( (temp[0][0]==fill || temp[1][1]==fill || temp[2][2]==fill) && (temp[0][0]!=opp && temp[1][1]!=opp && temp[2][2]!=opp))
		count++;
	if( (temp[0][2]==fill || temp[1][1]==fill || temp[2][0]==fill) && (temp[0][2]!=opp && temp[1][1]!=opp && temp[2][0]!=opp))
		count++;

	return count;
}
int score(int game[3][3]){
	int xScore,oScore;
	xScore = scCal(game,1);
	oScore = scCal(game,2);
	return (oScore-xScore);
}
bool valid(int game[3][3],int x,int y){
	if(game[x][y]==0)
		return true;
	cout<<"Invalid MOVE!!";
	return false;
}
vector<pair<int, int> > get_available_moves(int game[3][3]) {
    vector<pair<int, int> > available_moves;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(game[i][j] == 0) {
                available_moves.push_back(make_pair(i, j));
            }
        }
    }
    return available_moves;
}
int main(){
	//int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
	//int board[3][3] = {{3,2,1},{5,1,6},{1,9,1}};
	gameBoard board;
	int x,y;
	bool player;
	//Computer = 2(0)
	//Player   = 1(X)
	//Blank    = 0(-)
	 while(boardEmpty(board.b)){
	 	//*********Players turn*********
	 	cout << "Current Board Status\n\n" << endl;
	 	dispalyBoard(board.b);
	 	cout<<"\n\n\n";
	 	do{
	 		vector<pair<int, int> > available_moves = get_available_moves(board.b);
	 		cout<<"Enter your move : (available moves: ";
	 		for(int i = 0; i < available_moves.size(); i++) {
                if (i != 0) {
                    cout << ", ";
                }
                cout << available_moves[i].first << " " << available_moves[i].second;
                //printf("oay");
	 		}
	 		cout << ")" << endl;
			cin>>x>>y;
	 	}while(!valid(board.b,x,y));
	 	player=true;
		board.b[x][y]=1;
	 	if(gameWon(board.b)&&player){
			dispalyBoard(board.b);
			cout<<"\nPlayer won!!\n";
			string play_again = "";
			cout << "play_again?(Yes/No)" <<endl;
			cin >> play_again;
			if(play_again == "Yes" || play_again == "YES" || play_again == "yes") {
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        board.b[i][j] = 0;
                    }
                }
                cout<<"\n\n\n";
                continue;
			}
			else {
                break;
			}
		}
		player=false;
		//********Computer's turn********
		//**********     MAX PLY BEGINS     ***********
		pair< pair<int,int> ,int > p[8];
		int pairCount=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){

				if(board.b[i][j]==0){

					board.b[i][j]=2;
					if(gameWon(board.b)){
						p[pairCount++] = make_pair(make_pair(i,j),INT_MAX);
					}
					else{
						//***********  MIN  PLY BEGINS    *********
						int minScore = INT_MAX;
						pair<int,int> bestPair;
						for(int k=0;k<3;k++){
							for(int l=0;l<3;l++){
								if(board.b[k][l]==0){
									board.b[k][l]=1;
									//**** Calculate score begins****
									int sc;
									if(gameWon(board.b)){
										sc = INT_MIN;
									}
									else{
										sc = score(board.b);
									}
									if(sc<minScore)
											minScore = sc;
									//****Calculate score ends*****
									board.b[k][l]=0;
								}
							}
						}
						p[pairCount++] = make_pair(make_pair(i,j),minScore);
						//**********  MIN PLY ENDS     **********
					}
					//reseting
					board.b[i][j]=0;
				}
			}
		}
		//************* MAX PLY ENDS *************
		pair<int, int> bestMove;
		int maxScore = INT_MIN;
		for(int c=0;c<pairCount;c++){
			if(p[c].second>=maxScore){
				bestMove = p[c].first;
				//cout<<"next best move";
				maxScore = p[c].second;
			}
			cout<<"i="<<p[c].first.first<<" j="<<p[c].first.second<<" score="<<p[c].second<<"\n";
		}
		board.b[bestMove.first][bestMove.second]=2;
		//*****check if computer won*****
		if(gameWon(board.b)&&!player){
			dispalyBoard(board.b);
			cout<<"\nComputer won!!\n";
			string play_again = "";
			cout << "play_again?(Yes/No)" <<endl;
			cin >> play_again;
			if(play_again == "Yes" || play_again == "YES" || play_again == "yes") {
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        board.b[i][j] = 0;
                    }
                }
                cout<<"\n\n\n";
                continue;
			}
			else {
                break;
			}
		}
	 }
}
