#include "MemoryMatchGame.h"

MemoryMatchGame::MemoryMatchGame(){

}

void MemoryMatchGame:: veryStart() { //creates the very first window in the game
	cout << "		#############################################################" << endl;
	cout << "		#                    _                                      #" << endl;
	cout << "		#                  -=\\`\\                                    #" << endl;
	cout << "		#              |\\ ____\\_\\________  Memory Match Game        #" << endl;
	cout << "		#            -=\\c      '' '' '' '')                         #" << endl;
	cout << "		#               `~~~~~/ /~~`\                                #" << endl;
	cout << "		#                 -==/ /                                    #" << endl;
	cout << "		#                   '-'                                     #" << endl;
	cout << "		#                  _  _                                     #" << endl;
	cout << "		#                 ( `   )_                                  #" << endl;
	cout << "		#                (    )    `)                               #" << endl;
	cout << "		#              (_   (_ .  _) _)                             #" << endl;
	cout << "		#                                             _             #" << endl;
	cout << "		#                                            (  )           #" << endl;
	cout << "		#             _ .                         ( `  ) . )        #" << endl;
	cout << "		#           (  _ )_                      (_, _(  ,_)_)      #" << endl;
	cout << "		#         (_  _(_ ,)                                        #" << endl;
	cout << "		#############################################################" << endl << endl << endl;


	if (starting == 1) {
		cout << "		///-\\\\\\ " << endl;
		cout << "		|^   ^|" << "	  Select A Play Level:" << endl;
		cout << "		|O   O|" << "	  1. Easy ( 4 x 4 )" << endl;       // player chooses game level
		cout << "		|  ~  |" << "	  2. Moderate ( 6 x 6 )" << endl;
		cout << "	         \\ O /" << "    3. Hard ( 8 x 8 )" << endl;
		cout << "		  | |" << "     I choose:";
		cin >> size;

		switch (size) {
		case 1:
			size = 16;
			break;
		case 2:
			size = 36;							//each level is aasigned to size (total amount of slots in the game)
			break;
		case 3:
			size = 64;
			break;
		}
	}
	else {

		cout << "		///-\\\\\\ " << endl;
		cout << "		|^   ^|" << "	  Select A Time Interval:" << endl;
		cout << "		|O   O|" << "	  1. Easy ( 6 Seconds )" << endl;
		cout << "		|  ~  |" << "	  2. Moderate ( 4 Seceonds )" << endl;   //player chooses time interval 
		cout << "	         \\ O /" << "    3. Hard ( 2 Seconds )" << endl;
		cout << "		  | |" << "     I choose:";
		cin >> timeInterval;

		switch (timeInterval) {
		case 1:
			timeInterval = 6;
			break;															//interval is assigned to seconds
		case 2:
			timeInterval = 4;
			break;
		case 3:
			timeInterval = 2;
			break;
		}
		starting = 3;
		//cout << size << timeInterval;


	}
}

void MemoryMatchGame:: start() {
	system("Color E4");//70
		//veryStart();

	if (starting == 0) {
		starting = 1;
		veryStart();
	}
	system("cls");
	if (starting == 1) {			//to create a better functioning program, this code goes back to the same function and executes 
		starting = 2;				//different parts of the if else statements by itterating a constant called starting 
		veryStart();
		//cout << size << "  " << timeInterval;
	}
	if (starting == 3) {
		play();				//once both choices were made the player will start his/her game
	}
}

void MemoryMatchGame::play() {
	srand(time(NULL));
	vector<string> myList;
	int random = rand() % 50;
	string item = cities[random];		//creating a vector that randomly picks city names. This is the very first item
	for (int i = 0; i < 2; i++) {
		myList.push_back(item);
	}
	while (true) {
		int random = rand() % 50;
		string item = cities[random];			//the loop checks to see that there are no repeats. The amount of times depends on the size of the board
		for (int g = 0; g < myList.size(); g++) {
			if (item == myList[g]) {			//if exists dont add to list
				break;
			}
			else {
				for (int i = 0; i < 2; i++) {  //if doesnt exist already, add to list
					myList.push_back(item);
				};
				break;
			}
		}
		if (myList.size() == (size)) {  //stop adding if reaches maximum amount of cards
			break;
		}

	}
	random_shuffle(myList.begin(), myList.end());   //randomly shuffle the vactor items



	int rows = sqrt(size);


	string* board = new string[rows * rows];
	for (int i = 0; i < rows; i++) {			//creates a pointer array and adds all the item to each element
		for (int j = 0; j < rows; j++) {
			string word = myList.at(i * rows + j);
			*(board + i * rows + j) = word;
		};



	}
	system("cls");
	table(rows);
	vector<vector<int>>vectCompare{};  //creating 2 vectors, the controled and the non constant 
	vector<vector<int>>vectCompare2{};

	while (true) {

		while (true) {
			int check = 0;
			cout << "	pick y1: ";
			cin >> vertical1;
			cout << "	pick x1: ";  //user picks a cell coordinate twice 
			cin >> horizontal1;
			cout << "	pick y2: ";
			cin >> vertical2;
			cout << "	pick x2: ";
			cin >> horizontal2;
			cout << endl;
			if (vectCompare.size() == 0) {
				break;							//if the controlled vector is empty then ignore
			}
			else {
				for (int q = 0; q < vectCompare.size(); q++) {
					if (vertical1 == vectCompare[q][0]) {
						if (horizontal1 == vectCompare[q][1]) {
							cout << "Please open a cell that is not yet open " << endl;		// tests to see if a cell that chould be open 
																							//corresponds with the current cell the cursor is on 
							check++;
							break;
						}
						else if (vertical2 == vectCompare[q][0]) {
							if (horizontal2 == vectCompare[q][1]) {                        //repeats process for the vertical value
								cout << "Please open a cell that is not yet open " << endl;
								check++;
								break;
							}
						}

					}
				}
				if (check == 1) {
					continue;
				}
				else { break; }
			}
			break;
		}

		system("cls");
		int k = 0;

		if (*(board + vertical1 * rows + horizontal1) == *(board + vertical2 * rows + horizontal2)) {   //if contents of one cell chose equal to the contents of another cell chosen by user
			vectCompare.push_back({ vertical1, horizontal1 });
			vectCompare.push_back({ vertical2,horizontal2 });
		}
		cout << endl;
		cout << "		  ";
		for (int s = 0; s < sqrt(size); s++) {
			cout << left << s << "          ";
		}
		cout << endl;
		for (int i = 0; i < rows; i++) {   //i represents the columns

			cout << endl;
			cout << "	" << i << "	|";
			for (int j = 0; j < rows; j++) { //j represents the item in the current row
				vectCompare2.push_back({ i,j });  //each cell has a coordinate and will be entered to a new 
												  //list that is compared with the coordinates that must be remained open
				while (test == 0) {
					if (vectCompare.size() == 0) {    //if empty, ignore
						;
					}
					else {
						for (int w = 0; w < vectCompare.size(); w++) {
							if ((vectCompare[w][0] == vectCompare2[0][0]) && (vectCompare[w][1] == vectCompare2[0][1])) {  //test if current coordinate matches with the must existing coordinate in vectCompare
								cout << left << setw(wordwidth) << *(board + i * rows + j) << setfill(initialSpace);  //if so print the city name
								++test;
							}

						}

					}


					if (test == 0) {
						if (((i == vertical1) && (j == horizontal1)) || ((i == vertical2) && (j == horizontal2))) {  //else open cell temporarily 
							cout << left << setw(wordwidth) << *(board + i * rows + j) << setfill(initialSpace);  
						}
						else {
							cout << left << setw(wordwidth) << "City" << setfill(initialSpace);                     // or print "city"
						}
						++test;
					}
					vectCompare2.clear();    //move on to the next coordinate to be checked and erase the previous one

				}

				test = 0;  //the table is officially drawn, time to ask for new coordinates from user
			}

			cout << left << endl << left << endl;

		}
		// reprint only matching cards
		if (*(board + vertical1 * rows + horizontal1) != *(board + vertical2 * rows + horizontal2)) {   //if contents of one cell equal to the contents of another cell
			for (int m = timeInterval; m > 0; m--) {
				cout << m;
				for (int k = 0; k < 3; k++) {   //if not chosen correctly, there will be a timer to indicate how much time is left to memorize
					Sleep(333);					// also 
					cout << ".";
				}

			}
			
			system("cls");
			int b = 0;
			cout << endl;
			cout << "		  ";
			for (int s = 0; s < sqrt(size); s++) {
				cout << left << s << "          ";
			}
			cout << endl;

			for (int i = 0; i < rows; i++) {

				cout << endl;
				cout << "	" << i << "	|";

				for (int j = 0; j < rows; j++) {
					vectCompare2.push_back({ i,j });
					while (test2 == 0) {
						if (vectCompare.size() == 0) {
							;
						}
						else {
							for (int w = 0; w < vectCompare.size(); w++) {//takes a step backand only print the already corectly matched cards
								if ((vectCompare[w][0] == vectCompare2[0][0]) && (vectCompare[w][1] == vectCompare2[0][1])) {
									cout << left << setw(wordwidth) << *(board + i * rows + j) << setfill(initialSpace);
									++test2;
								}

							}
						}


						if (test2 == 0) {
							cout << left << setw(wordwidth) << "City" << setfill(initialSpace);  //refil the rest with "city" 

							++test2;
						}
						vectCompare2.clear();

					}

					test2 = 0;
				}

				cout << left << endl << left << endl;

			}


		}
		if (vectCompare.size() == size) {
			end();
			break;
		}

		//vector takes in the coordinates
	}
}

void MemoryMatchGame::table(int rows) {  //very first table visible-> totally untouched and filled with "city"
	const char bar = '|';
	const int wordwidth = 11;
	const char initialSpace = ' ';
	//cout << rows;
	cout << endl;
	cout << "		  ";
	for (int s = 0; s < sqrt(size); s++) {
		cout << left << s << "          ";
	}
	cout << endl;
	for (int i = 0; i < rows; ++i) {
		cout << endl;
		cout << "	" << i << "	|";
		for (int j = 0; j < rows; j++) {
			cout << left << setw(wordwidth) << "City" << setfill(initialSpace);

		}
		cout << endl << endl;
	}
}

void MemoryMatchGame::end() {
	cout << "congradulations!! YOU WIN :)";  //end of the game
}
