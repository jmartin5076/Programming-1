//TextGame.cpp_Jeremy Martin_2/15/16
// this program runs the text based adventure Xyggafyg's Throne
#include <iostream> //import the library that allows us to use
					 //cout
#include <string>
#include <cstdlib> //import the library that allows us to use rand()
#include <ctime>

using namespace std;

int main()
{
	//establishing the constant variables for descriptions of the title and intro
	string const TITLE = "		Xyggafyg's Throne		\n		By: Jeremy Martin		\n";

	string const INTRO1 = "You have heard tales of an ancient powerful throne capable of giving anyone who sits on it great power.\n";
	string const INTRO2 = "But you have also heard tales of the place that the throne currently resides in, the castle of the great warlock Xyggafyg.\n";
	string const INTRO3 = "You have heard many stories of the horrible atrocities this warlock committed, but you decide to try to get to the throne anyway.\n";
	string const INTRO4 = "You find yourself standing outside the castle, pushing the door open fills you with determination.\n You bravely enter the door to the castle...\n \n";
	string const INTRO5 = "As you enter the castle, you hear the doors slam shut behind you.\"You shouldn't have entered here,\" says a shrill, raspy voice.\n";
	string const INTRO6 = "\"Now you will know what happens when you mess with Xyggafyg.\" You feel like you're going to have a bad time...\n";
	string const INTRO = INTRO1 + INTRO2 + INTRO3 + INTRO4 + INTRO5 + INTRO6; //concatenating strings to create the Intro

	//establishing the constant variables for decriptions of the rooms
	string const ENTRYWAY1 = "Entryway: You enter a grand entryway. Streaming down from the ceiling are six red and gold banners.\n";
	string const ENTRYWAY2 = "From what you can tell most of the architecture looks gothic in nature. You feel like the gargoyles, high atop their stone pillars, are watching you.\n";
	string const ENTRYWAY3 = "You see a lone dirty shovel sitting in the far corner. To the north you see a set of doors.\n";
	string const ENTRYWAY = ENTRYWAY1 + ENTRYWAY2 + ENTRYWAY3; //concatenating strings to create the decription of Entryway

	string const HALLWAY1 = "Hallway: As the doors open, you find yourself in a long and narrow hallway. The banners are faded from the passage of time, and the rug underneath you looks torn and tattered.\n";
	string const HALLWAY2 = "There is a set of doors to the north, and a set to the south.\n";
	string const HALLWAY = HALLWAY1 + HALLWAY2; //creating the description of the Hallway

	string const RESONATING_CHAMBER1 = "Resonating Chamber: As you enter the room, the first thing that you realize is that the room is mostly barren. There is a single chair in the middle of the room.\n";
	string const RESONATING_CHAMBER2 = "As you gaze around the room, you see a locked door to the north, you also see sets of doors leading to the east, west, and south.\n";
	string const RESONATING_CHAMBER3 = "You hear the same raspy voice, \"The key is definately not in the room to the east.\"\n";
	string const RESONATING_CHAMBER = RESONATING_CHAMBER1 + RESONATING_CHAMBER2 + RESONATING_CHAMBER3; //creating the description for the Resonating Chamber

	string const DARK_ROOM1 = "Dark Room: When you enter the room, the door slams shut behind you and plunges you into darkness. \"I told you the key wasn't here, hope you aren't scared of the dark.\"\n";
	string const DARK_ROOM2 = "Manic laughter fills the room, you think that you can barely make out the outline of a switch in the center of the room.\n";
	string const DARK_ROOM = DARK_ROOM1 + DARK_ROOM2; //creating the description of the Dark Room

	string const UNDERGROUND_LAKE1 = "Underground Lake: You enter the room and are startled by the sight of a large lake in the center of the room.\n";
	string const UNDERGROUND_LAKE2 = "Hanging above the lake is a key, it looks like it goes to a door. You believe that you could jump and grab the key if you tried.\n";
	string const UNDERGROUND_LAKE = UNDERGROUND_LAKE1 + UNDERGROUND_LAKE2; //creating the description for the Underground Lake

	string const THRONE_ROOM1 = "Throne Room: You unlock the door with the key. As you enter the room, you see the golden throne sitting before you.\n";
	string const THRONE_ROOM2 = "You hear the voice pleading to you, \"No, don't you dare sit on that throne, you have no idea what it contains...contains...contains...\"\n";
	string const THRONE_ROOM3 = "You realize that there is a record player skipping in the corner. You casually turn the record player off and admire the throne.\n";
	string const THRONE_ROOM = THRONE_ROOM1 + THRONE_ROOM2 + THRONE_ROOM3; // creating the description for the Throne Room

	//establishing the constant variables for the descriptions of the items
	string const SHOVEL = "As you get closer, you realize that the shovel is covered in fresh mud and what seem to be dandelion seeds. Perhaps this was used recently.\n"; //description for the shovel

	string const RUG = "The rug beneath your feet looks very old and tattered. It also smells slghtly of rutabagas, you're not quite sure why.\n"; //description of the rug

	string const CHAIR1 = "As you near the chair, you hear the voice again,\"Yes, you have completed your mission champion. Go ahead, sit down and claim your reward.\"\n";
	string const CHAIR2 = "You decide to take a seat. As you sit down, you hear a lunatic cackling in the distance, \"I can't believe you fell for that.\" The chair splinters beneath you.\n";
	string const CHAIR3 = "As you get up and brush yourself off, you hear chair pieces skittering across the floor. The chair sits in the middle of the room, back in one piece.\n";
	string const CHAIR = CHAIR1 + CHAIR2 + CHAIR3; //creating the description of the chair

	string const SWITCH = "You firmly grasp what you hope to be a lever. Flipping the switch sends light flooding throughout the room. The room seems really bare, as if it were made only to be a trap.\n"; //description of the switch

	string const KEY1 = "You ready yourself to jump for the key. As you jump, you slip and fall off course. You stiffen at the thought of being drenched in water.\n";
	string const KEY2 = "You hear the splash, but you aren't really wet. Turns out what you thought was a lake, was really just a puddle. You should probably just take the key and go.\n";
	string const KEY_TAKEN = "You grab the key and storm out of the puddle, clearly embarassed.\n"; //message given when key is taken
	string const KEY = KEY1 + KEY2; //description of the key

	string const THRONE = "This is it, the magical throne of legend. Take a seat and claim your prize!\n"; //description of the throne

	//establishing the constant variables for the random events
	string const DANDELION_CAGE1 = "Event 1: A cage falls onto you. You realize that the cage is made out of dandelions.\n";
	string const DANDELION_CAGE2 = "As you tear the cage to pieces, you realize that Xyggafyg may not be as fearsome of a warlock as you originally thought.\n";
	string const DANDELION_CAGE = DANDELION_CAGE1 + DANDELION_CAGE2; //creating the description for the Dandelion Cage event

	string const RUTABAGA_STORM = "Event 2: It starts to rain rutabagas. You have no clue why this is happening, but the room smells like rutabagas and failure.\n"; //description of the Rutabaga Storm event

	string const SKELETONS = "Event 3: The room is now filled with skeletons. Two look different from the rest, one is wearing a blue hoodie and the other is wearing a red scarf. You blink a few times, and they all disappear.\n"; //description of the Skeletons event

	//establishing the constant variables for the ending
	string const THE_END1 = "\n \n As you sit on the throne you feel a surge of power rush through you. And then you hear a flush... You realize with an embarassing look around the room, that you are in a bathroom.\n";
	string const THE_END2 = "Turns out all the rumors about the powerful throne were just bullshit (excuse the pun). Besides, if Xyggafyg had a relic of immense power, like the throne, shouldn't he be a better warlock than he is?\n";
	string const THE_END3 = "\n		THANKS FOR PLAYING!!		\n";
	string const THE_END = THE_END1 + THE_END2 + THE_END3; //creating the description for The End

	//establishing variables that are important to the gameplay
	string const HELP = "<direction>= moves in the specified direction\n <look>= repeats room discription\n <examine \"object\">= takes a closer look at the object\n <take \"object\">=used in the story\n <sit \"object\">= used in the story\n <exit>= closes the game\n";
	string room = "room1";
	string user_input;
	string key = "not taken";
	string throne = "empty";
	int randnum1;
	int randnum2;
	int randnum3;
	bool hasGivenDescription = false;

	//display the intro to the game
	cout << TITLE << endl;
	cout << INTRO << endl;
	//making the while loop that runs the game
	while (user_input != "exit" && throne != "occupied")
	{
		srand(time(0)); //seeding the random numbers to the time
		randnum1 = rand() % 10 + 1;
		randnum2 = rand() % 10 + 1;
		randnum3 = rand() % 10 + 1; //setting the random numbers

		if (room == "room1") //creating the if statements that allow us to cout the correct description for each room
		{
			if (randnum1 >= 1 && randnum1 <= 8) //setting the 80% chance for event 1
			{
				cout << DANDELION_CAGE << endl;
			}

			if (randnum2 >= 1 && randnum2 <= 4) //setting the 40% chance for event 2
			{
				cout << RUTABAGA_STORM << endl;
			}

			if (randnum3 == 1) //setting the 10% chance for event 3
			{
				cout << SKELETONS << endl;
			}

			if (!hasGivenDescription) //triggers whether the description of the room has been given or not
			{
				cout << ENTRYWAY << endl;
				hasGivenDescription = true;
			}

			cout << "What do you do?" << endl;
			cin >> user_input; //asking for user input

			if (user_input == "north") //making the commands available in this room
			{
				room = "room2";
				hasGivenDescription = false;
			}
			else if (user_input == "examine")
			{
				cin >> user_input;
				if (user_input == "shovel")
				{
					cout << SHOVEL << endl;
				}
			}
			else if (user_input == "help")
			{
				cout << HELP << endl;
			}
			else if (user_input == "look")
			{
				cout << ENTRYWAY << endl;
			}
			else if (user_input == "exit")
			{
				cout << "Goodbye" << endl;
			}
			else
			{
				cout << "\"I'm afraid I can't let you do that,\" says the raspy voice in your ear." << endl;
			}
		}
		else if (room == "room2")
		{
			if (randnum1 >= 1 && randnum1 <= 8) //setting the 80% chance for event 1
			{
				cout << DANDELION_CAGE << endl;
			}

			if (randnum2 >= 1 && randnum2 <= 4) //setting the 40% chance for event 2
			{
				cout << RUTABAGA_STORM << endl;
			}

			if (randnum3 == 1) //setting the 10% chance for event 3
			{
				cout << SKELETONS << endl;
			}

			if (!hasGivenDescription) //triggers whether the description of the room has been given or not
			{
				cout << HALLWAY << endl;
				hasGivenDescription = true;
			}

			cout << "What do you do?" << endl;
			cin >> user_input; //asking for user input

			if (user_input == "north") //making the commands available in this room
			{
				room = "room3";
				hasGivenDescription = false;
			}
			else if (user_input == "south")
			{
				room = "room1";
				hasGivenDescription = false;
			}
			else if (user_input == "examine")
			{
				cin >> user_input;
				if (user_input == "rug")
				{
					cout << RUG << endl;
				}
			}
			else if (user_input == "help")
			{
				cout << HELP << endl;
			}
			else if (user_input == "look")
			{
				cout << HALLWAY << endl;
			}
			else if (user_input == "exit")
			{
				cout << "Goodbye" << endl;
			}
			else
			{
				cout << "\"I'm afraid I can't let you do that,\" says the raspy voice in your ear." << endl;
			}
		}
		else if (room == "room3")
		{
			if (randnum1 >= 1 && randnum1 <= 8) //setting the 80% chance for event 1
			{
				cout << DANDELION_CAGE << endl;
			}

			if (randnum2 >= 1 && randnum2 <= 4) //setting the 40% chance for event 2
			{
				cout << RUTABAGA_STORM << endl;
			}

			if (randnum3 == 1) //setting the 10% chance for event 3
			{
				cout << SKELETONS << endl;
			}

			if (!hasGivenDescription) //triggers whether the description of the room has been given or not
			{
				cout << RESONATING_CHAMBER << endl;
				hasGivenDescription = true;
			}

			cout << "What do you do?" << endl;
			cin >> user_input; //asking for user input

			if (user_input == "north" && key == "taken") //establishing the commands that can be used in the room
			{
				room = "room6";
				hasGivenDescription = false;
			}
			else if (user_input == "east")
			{
				room = "room4";
				hasGivenDescription = false;
			}
			else if (user_input == "west")
			{
				room = "room5";
				hasGivenDescription = false;
			}
			else if (user_input == "south")
			{
				room = "room2";
				hasGivenDescription = false;
			}
			else if (user_input == "examine")
			{
				cin >> user_input;
				if (user_input == "chair")
				{
					cout << CHAIR << endl;
				}
			}
			else if (user_input == "help")
			{
				cout << HELP << endl;
			}
			else if (user_input == "look")
			{
				cout << RESONATING_CHAMBER << endl;
			}
			else if (user_input == "exit")
			{
				cout << "Goodbye" << endl;
			}
			else
			{
				cout << "\"I'm afraid I can't let you do that,\" says the raspy voice in your ear." << endl;
			}
		}
		else if (room == "room4")
		{
			if (randnum1 >= 1 && randnum1 <= 8) //setting the 80% chance for event 1
			{
				cout << DANDELION_CAGE << endl;
			}

			if (randnum2 >= 1 && randnum2 <= 4) //setting the 40% chance for event 2
			{
				cout << RUTABAGA_STORM << endl;
			}

			if (randnum3 == 1) //setting the 10% chance for event 3
			{
				cout << SKELETONS << endl;
			}

			if (!hasGivenDescription) //triggers whether the description of the room has been given or not
			{
				cout << DARK_ROOM << endl;
				hasGivenDescription = true;
			}

			cout << "What do you do?" << endl;
			cin >> user_input; //asking for user input

			if (user_input == "west") //establishing the commands that can be used in the room
			{
				room = "room3";
				hasGivenDescription = false;
			}
			else if (user_input == "examine")
			{
				cin >> user_input;
				if (user_input == "switch")
				{
					cout << SWITCH << endl;
				}
			}
			else if (user_input == "help")
			{
				cout << HELP << endl;
			}
			else if (user_input == "look")
			{
				cout << DARK_ROOM << endl;
			}
			else if (user_input == "exit")
			{
				cout << "Goodbye" << endl;
			}
			else
			{
				cout << "\"I'm afraid I can't let you do that,\" says the raspy voice in your ear." << endl;
			}
		}
		else if (room == "room5")
		{
			if (randnum1 >= 1 && randnum1 <= 8) //setting the 80% chance for event 1
			{
				cout << DANDELION_CAGE << endl;
			}

			if (randnum2 >= 1 && randnum2 <= 4) //setting the 40% chance for event 2
			{
				cout << RUTABAGA_STORM << endl;
			}

			if (randnum3 == 1) //setting the 10% chance for event 3
			{
				cout << SKELETONS << endl;
			}

			if (!hasGivenDescription) //triggers whether the description of the room has been given or not
			{
				cout << UNDERGROUND_LAKE << endl;
				hasGivenDescription = true;
			}

			cout << "What do you do?" << endl;
			cin >> user_input; //asking for user input

			if (user_input == "east") //establishing the commands available in this room
			{
				room = "room3";
				hasGivenDescription = false;
			}
			else if (user_input == "examine")
			{
				cin >> user_input;
				if (user_input == "key")
				{
					cout << KEY << endl;
				}
			}
			else if (user_input == "take")
			{
				cin >> user_input;
				if (user_input == "key")
				{
					key = "taken";
					cout << KEY_TAKEN << endl;
				}
			}
			else if (user_input == "help")
			{
				cout << HELP << endl;
			}
			else if (user_input == "look")
			{
				cout << UNDERGROUND_LAKE << endl;
			}
			else if (user_input == "exit")
			{
				cout << "Goodbye" << endl;
			}
			else
			{
				cout << "\"I'm afraid I can't let you do that,\" says the raspy voice in your ear." << endl;
			}
		}
		else if (room == "room6")
		{
			if (randnum1 >= 1 && randnum1 <= 8) //setting the 80% chance for event 1
			{
				cout << DANDELION_CAGE << endl;
			}

			if (randnum2 >= 1 && randnum2 <= 4) //setting the 40% chance for event 2
			{
				cout << RUTABAGA_STORM << endl;
			}

			if (randnum3 == 1) //setting the 10% chance for event 3
			{
				cout << SKELETONS << endl;
			}

			if (!hasGivenDescription) //triggers whether the description of the room has been given or not
			{
				cout << THRONE_ROOM << endl;
				hasGivenDescription = true;
			}

			cout << "What do you do?" << endl;
			cin >> user_input; //asking for user input

			if (user_input == "south")
			{
				room = "room3";
				hasGivenDescription = false;
			}
			else if (user_input == "examine")
			{
				cin >> user_input;
				if (user_input == "throne")
				{
					cout << THRONE << endl;
				}
			}
			else if (user_input == "sit")
			{
				cin >> user_input;
				if (user_input == "throne")
				{
					throne = "occupied";
				}
			}
			else if (user_input == "help")
			{
				cout << HELP << endl;
			}
			else if (user_input == "look")
			{
				cout << THRONE_ROOM << endl;
			}
			else if (user_input == "exit")
			{
				cout << "Goodbye" << endl;
			}
			else
			{
				cout << "\"I'm afraid I can't let you do that,\" says the raspy voice in your ear." << endl;
			}
		}
	}
	if (throne == "occupied") //dictating the action of how the game will close
	{
		cout << THE_END << endl;
	}
	else
	{
		cout << THE_END3 << endl;
	}
	//print string;
	return 0;
}