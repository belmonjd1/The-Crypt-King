#include <iostream>
#include <string>
#include <tuple>

using namespace std;

/*
 * =====================================================================================
 *
 *        Filename:  project1.cpp
 *
 *        Description:  EECE1080C Spring, 2019 Project 1 Final Submission
 *                      This program is a game called "The Crypt King", which
 *                      is a text based role-playing game. The user is tasked
 *                      defeating a final boss, known as the "Crypt King", and
 *                      saving a princess. This program utilizes functions, switch
 *                      statements, and an abundance of if and do while loops.
 *                      It took a long while to make this program, enjoy it.
 *
 *        Version:  1.0
 *        Created:  03/13/2019 07:45:06 PM
 *        Revision:  none
 *        Compiler:  MinGW
 *
 *        Author:  Jared Belmont / M12850571 / belmonjd@uc.mail.edu
 *                 Braeden Butler / M12912314 / butlerbd@uc.mail.edu
 *
 *       Organization:  EECE1080C, Spring, 2019
 *
 * =====================================================================================
 */


void space() {                            //This program essentially clears the screen of the previous dialogue
    for (int i = 1; i < 100; i++){
        cout << endl;
    }
}

pair<int, string> introFunction() {       //This program is our intro program, i.e. this is the function
    int Class;                            //that displays the initial messages before any gameplay.
    string name;                          //This is where class and user name are defined initially

    cout << "______         ____" << endl;
    cout << "   |    |___| |__  " << endl;
    cout << "   |    |   | |____" << endl;
    cout << endl;
    cout << " _____  ___  _   _   ____  _____ " << endl;
    cout << "|      |___|  \\ /   |____|   |   " << endl;
    cout << "|_____ |  \\    |    |        |   " << endl;
    cout << endl;
    cout << "|   /__ __         ____    " << endl;
    cout << "|__/   |    |\\ |  |  __    " << endl;
    cout << "| \\  __|__  | \\|  |____|   " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "A game by Braeden Butler and Jared Belmont" << endl;
    cout << "(For best results, please maximize this window)" << endl;
    cout << endl;
    cout << endl;

    char playgame;
    cout << "Are you ready to begin your adventure? (y/n)" << endl;
    cin >> playgame;

    if(playgame == 'y'){
        for (int i = 1; i < 100; i++){
            cout << endl;
        }
    }
    if(playgame == 'n') {
        for (int i = 1; i < 100; i++){
            cout << endl;
        }
        cout << "Did you really think you had a choice?" << endl;
        cout << endl;
    }

    string playerName;
    cout << "What is your name, traveler?" << endl;          //Acquisition of user name
    cin >> playerName;
    cout << endl;

    do {
        cout << "What class would you like to play as?" << endl;      //Acquisition of user class. There are three options here
        cout << "Enter 1 to play as a wizard." << endl;
        cout << "Enter 2 to play as a fighter." << endl;
        cout << "Enter 3 to play as a theif." << endl;
        cin >> Class;
    }
    while (!(Class == 1 || Class == 2 || Class == 3));

    string classname;

    if (Class == 1) {
        classname = "Wizard";
    }
    if (Class == 2) {
        classname = "Fighter";
    }
    if (Class == 3) {
        classname = "Thief";
    }

    space();
    cout << "Greetings, " << playerName << " the " << classname << "." << endl;
    cout << "You and a band of your companions have been tasked "
            "by the king to kill the infamous Crypt King, a merciless "
            "demon tormenting the lands, and to rescue his daughter, the princess. "
            "You were going through the Crypt Kings castle when a sudden "
            "earthquake caused a stone to fall from the ceiling and knock "
            "you out." << endl;
    cout << endl;
    cout << "Aww...my head...wha...what happened?" << endl;
    cout << endl;
    cout << "You wake up in a dimly lit hallway, face first on the floor. "
         << "A torch softly burns a few feet from your face. You remember now. "
         << "You and your friends were tasked with rescuing the princess from the "
         << "evil tyrant known as The Crypt King. You must have "
         << "fallen and hit your head, your friends leaving you behind to continue the quest."
         << endl;
    cout << "Suddenly you hear a scream in the distance. Its the princess! You should probably "
         << "get moving." << endl;
    cout << endl;
    cout << "You get up and find yourself in a hallway with four doorways and a "
         << "staircase leading down. The way up is blocked off by rubble, "
         << "youll have to find another way out." << endl;

    pair<int, string> outputs;            //This is where it can get tricky. Since this function contains
    outputs.first = Class;                //two essential user inputs of different variable type, we had yo
    outputs.second = playerName;          //use the pair function to output the two values
    return outputs;
}

pair<bool, bool> floorOneFunction (int Class, string playerName){   //This function controls the user gameplay of the first floor
    int floorOneDecision;                                           //and outputs two important variables that can be triggered or not.
    bool foundWeapon = false;                                       //This is why its a pair function
    bool foundLockpicks = false;

    do {
        stop:        //This stop anchor for the goto returns the user from the stairs if they wish to go back
        cout << endl;
        cout << "What are you going to do now?" << endl;
        cout << "Enter 1 to enter the right room." << endl;
        cout << "Enter 2 to enter the left room." << endl;              //Room choices for user, these have to display every time
        cout << "Enter 3 to enter the far right room." << endl;
        cout << "Enter 4 to enter the far left room." << endl;
        cout << "Enter 5 to go down the staircase." << endl;
        cin >> floorOneDecision;
        cout << endl;

        switch (floorOneDecision){               //here we used a switch function and used the cases inside to describe the rooms
            case 1:
                space();
                cout << "You walk into the closest room to the right and find a "    //This room mirrors the next two rooms in functionality,
                        "corpse splayed out in front of a wooden chest. It is "      //the user will find a class based weapon if they enter the
                        "one of your companions! He seems to have been killed by "   //right room (they can enter all three, its not a one time choice)
                        "a dart trap hidden in the chest. It seems as though he "    //the variable for having a weapon wil update to true, which will
                        "had a longbow and some arrows on him, in addition to "      //prevent the user from dying in fights.
                        "some lockpicks. " << endl;                                  //other items, such as lockpicks, are treated the same way
                cout << endl;
                cout << "The chest is empty besides an old green bottle and dust. "    //in this room, the user finds lockpicks (which can be used by any class)
                        "This was clearly a trap for any would be thieves. " << endl;  //and a bow, which can only be used as a weapon by thieves
                cout << endl;
                if (Class != 3){
                    cout << "You pick up the bow and attempt to draw the string "
                            "back. You manage to only get about halfway before "
                            "your arms give in. You might want to find a different "
                            "weapon. " << endl;
                    cout << endl;
                    cout << "You also pick up the lockpicks, though you arent "
                            "quite sure how to use them." << endl;
                    cout << endl;
                    foundLockpicks = true;
                }
                else {
                    cout << "You pick up the bow and shoot an arrow down the hallway. "
                            "It impacts into a wooden pillar harmlessly. This will "
                            "make a good weapon!" << endl;
                    cout << endl;
                    cout << "You also pick up the lockpicks, "
                            "which you are quite familiar with. " << endl;
                    foundWeapon = true;
                    foundLockpicks = true;
                break;
            case 2:
                space();
                cout << "You turn to the door on the right, which is already "
                        "slightly ajar. You push open the door and, to your horror, "
                        "there lies one of your friends in a pool of blood. It seems "   //this room is where the fighter finds his weapon
                        "as though he was stabbed in the stomach and bled out. "
                        "His sword lies next to him. The room itself seems "
                        "like an old equipment room and is filled with racks "
                        "that looked to have at one time held equipment, "
                        "but now lie empty. The only usable weapon "
                        "in the room is your friends sword." << endl;
                cout << endl;
                if (Class != 2){
                    cout << "You swing the sword a few times before dropping "
                            "it on the ground. Its pretty heavy and unfamiliar "
                            "to you. You might want to find a different weapon." << endl;
                    cout << endl;
                }
                else {
                    cout << "You pick up the sword and swing it a few "
                            "times through the air. It is balanced exceptionally "
                            "well. This will make a good weapon!" << endl;
                    cout << endl;
                    foundWeapon = true;
                }
                break;
            case 3:
                space();
                cout << "You walk down the hallway and turn into the "
                        "room on the right. Inside there are rows and rows "
                        "of dusty shelves filled with books and paper scrolls. "
                        "It seems as though this was a library of sorts. A thick "
                        "layer of dust coats everything except an overturned "          //this is where the wizard finds his weapon
                        "shelf and a table in the middle. " << endl;
                cout << endl;
                cout << "Sitting at this table is one of your friends, slumped "
                        "over and not moving. Underneath him is an opened book, "
                        "which has strange writing and symbols. It appears to be "
                        "a magical tome, maybe it was even his spellbook. It "
                        "seems as though he wont be needing it anymore. " << endl;
                cout << endl;
                if (Class != 1) {
                    cout << "You pick up the musty old tome and try to read the page. A weak "
                            "fizzle of arcane energy appears for a second, then sputters out "
                            "of existence. You might want to find a different weapon." << endl;
                    cout << endl;
                }
                else {
                    cout << "You pick up the spellbook and read the incantations on the page. "
                            "A ball of fire flies from your hand and impacts the stone. "
                            "This will make a good weapon!" << endl;
                    cout << endl;
                    foundWeapon = true;
                }
                break;
            case 4:
                space();
                cout << "You walk up to open the door and find it partially open." << endl;
                cout << endl;
                cout << "You hear noises coming from inside the room. Furniture being "
                        "overturned, glass bottles breaking. You peer inside and "                   //this is the first fight scene. there isnt much user input
                        "see a skeleton walking around. He must be one of the minions "              //but if the user didnt enter the room that had their weapon,
                        "of The Crypt King. He is holding a bloody sword, he might be "              //they will die. its essentially a bunch of if statements
                        "the one who killed your friends!" << endl;
                cout << endl;
                cout << "If you decide to enter the room, youll probably get into a fight." << endl;
                cout << "0: Enter Room" << endl;
                cout << "1: Turn Around" << endl;
                int fight1prompt;
                do {
                    cin >> fight1prompt;
                } while (!(fight1prompt == 0 || fight1prompt == 1));
                if (fight1prompt == 0) {
                    space();
                    cout << R"(

                                                                     ,~+II?+~.
                                                                    +:+??77777I7
                                                                   ,+++?77777II777~
                            ...........................           =I=I+I777+??77II7
                            ..............................       ~+I+,I7I?I77I+II?7
                            .................................   ~==,?7I++I:~.,I7~I7..........
                            ....................................:~::=II?,,I7??+~I+.........
                            ....................................=+:.??....III...:~.......
                            .....................................:I:=:+.,=I++=.~......
                            .....................................?+:++,~~?,.::=~
                            .....................................?+~.::=++.=~=
                            ...............................??I+...+::=.I.~,::
                            .........................+~:,~:.=I+I...?==,..,..,.
                            ........................~+777:+I+?I~~:,:.~~===~,=~
                            .......................+??777.::=~??..,..=,~+:+?=.+I+
                            .....................+~+I:,:,..+I..+++..~,+.,,,,.~~,++
                            ...................I~+I~~,:,:.==I=....~?I:...:?+,.I,:.?++?
                            .................I:+I~,~...II~I:~~II+:.:+I.?++...~??..:+II:
                            ..............I?,I+~:I......~+I+.........~I+===~+~.:..,=?~,
                            ............I:=I?:=I......I,+~~?I:....,=?=?~,....,II.=:,,+:=
                            .......I~~=?77+:,I........=,?..:~=++I+:..?I,=~==?+:.+:++,:I=
                            ......++::I7?~,=..........+=??.........~?=I,=:...:II=.?++:I?
                            ......?:I?+?::............=+,+=?IIIII?:.~?~+?..,:,:=....?:+I+
                            .......~=?+=..............:+I...,...,+=,~I:,~~?~.=I:.....?~I:
                            .......?~=..~.............+.+~:++?I?:.+~++~~,.,,,:.?......=+~+
                            ........=.?.+.............+++......=I,.=?~+==~+~~I~?......~=I+?
                            ........~.I,=.............?=?=..~II:~.,===,~=.,=+,?.......?=I:.
                            ........+:?=~..............=.,~?=:+....=,.+=~+++I+.........,=I=
                            ........?=+?...............:~=?~:...=,=+..,??.:+?..........~,II
                            .........?~+,...............~,..:,==:,.+...?,,,+...........?=+:~
                            .........+~+~?.......I~+~?....:~..,:?:?+:~?...................=
                            .........+~?=~.......~7?.?~+I:.=:++=..+I=I+~................,:II7?
                            .........::??,......:+I:,,+I=?,,,,,I....,,II:...............:==?~~
                            .........,=?7~+....??+I+,,,?I==::..,,=:.,,??I?...............:+++....
                            .........~I77I.?...=~+7I,~=+:?=,....,?I.,~I+I?................?+?.
                            .........:....=....??~7~:=?,~=,.,~,.??.+==I?+.....................
                            .........+I=,.+.....+II++?=?.:=.:?,+??++=,?I:...................................
                            .........?,,+?~......=?I:=:..?+,~I=I~.??=I?:.?~~?...............................
                            ..I......=:...?.?=?=.:??I:?:..=?,=I~.+?+I:II==77:...............................
                            ~=+=?...+~~:~??I~?::,~~?:I:?~..?~~,I.+==+=~:~?77:...............................
                            ~.::,,,,::?~,I?:=II7I+:=.=I?+,?.?:..~~?I.=~~+?I7=...............................
                            ~,:.,.=,:I.,=I,+~:77+~..:...+I~=..==?I?~...I:+7I?...............................
                            ...~I~,=:.,,::77~=7+=,,=+,,?+?:=:?+==:+.....~+7+................................
                            ...,:=~:,::,:I,?+~=:,.....?+?=I+~+,~:+I.....=?7+................................
                            ....,=+.+,,:?I+=:+?+:+I....=:,+..=?~??......?+7+................................
                            .....:=::?::~=?:=?=~,+I?++?........?........?=7+................................
                            ......???~:+:.?~7:,+?=~:=II?=+I.............I+7?................................
                            ........~,=~..,I?~=.?~II+=:~II?+=?I.........I+7II...............................
                            ........:=~?.???==I....+~I?+=:=?II?=+I......?+77?...............................
                            ........+?.I:?I77I,?......?+=I?+===III??=+I.=:77=?..............................
                            ..........+=7777?+=+.........?==I?++=~I7II??:?777=..............................
                            ..........~7?+::.:.~?...........I~?I?+++~?77I??==I+.............................
                            ..........?,+II7I.I,~?..............+=II?+++=?7II?I?=+?.........................
                            ............=~=+~+7+?~.................?~II??++~+77IIII?~?......................
                            ............I:I?I?~~7+=...................+~?I??++==I77III+.....................
                            ..............=,~:+I7:?:.....................~:~II???+==I7II+...................
                            ................+~:+7I,?+....................+++I:+IIIII?==I7~..................
                            .................?=~I7:~,.....................,+I+?:==+?IIII?==+................
                            ..................+,~I7,I~....................~??I:+........???+=...............
                            ....................,~I7.I+...................?:+I,?............................
                            ....................?++7I:~+...................:+I.?............................
                            .....................==?7:?=?..................+?I.?I...........................
                            ......................+~?7.?,..................?=I,??...........................
                            .......................++7I,?~.................??I,??...........................
                            ........................==77,??................??I=+?...........................
                            .........................:+7=+,~...............+==I,+...........................
                            ..........................~I777I:..............,~77I:...........................
                            ..........................~=7?+?+=.............:+=+?............................
                            ..........................==~+...,,+...........?::II,...........................
                            ..........................I+..::?7:,,..........+~.,,.+..........................
                            .........................+~:I?~I,,,?..........~+~?7I..:?................
                            .......................+.,,..++:.?............:+:++~,:.:.=.............
                            ...................I:.::..=~..:?.................::~~,,~~~.,.........
                            ................?~.~~+II:.~?......................++~~=.::,,~.......
                            .................:~+~..:?............................,,:+~.=+.......
                            ................I==~?....................................??....
                            )" << endl;
                    cout << "\"Huh? Who are you!? Prepare to die!\" the skelton shouts. "
                            "It then rushes forward, blade raised high!" << endl;
                    cout << endl;
                    if ((foundWeapon == true) && (Class == 2)) {
                        cout << "You sidestep his blow and raise your sword and strike down "
                                "beheading the skeleton!" << endl;
                        cout << endl;
                        cout << "You take a sigh of relief, the skeleton is now defeated. "
                                "It seems as though he had a key around his neck. It wouldnt "
                                "be a bad idea to take it. " << endl;
                        cout << endl;
                    }
                    if ((foundWeapon == true) && (Class == 1)) {
                        cout << "You sidestep his blow and mutter a few incantations from "
                                "the book. You raise your left hand and a powerful energy "
                                "blast comes out and blows the skeleton to pieces!" << endl;
                        cout << endl;
                        cout << "You take a sigh of relief, the skeleton is now defeated. "
                                "It seems as though he had a key around his neck. It wouldnt "
                                "be a bad idea to take it. " << endl;
                        cout << endl;
                    }
                    if ((foundWeapon == true) && (Class == 3)) {
                        cout << "You sidesetep his blow, nock an arrow, and release! The "
                                "arrow flies through the air and pins the skeleton's head "
                                "to the wall!" << endl;
                        cout << endl;
                        cout << "You take a sigh of relief, the skeleton is now defeated. "
                                "You look around the room, but it\'s pretty empty. You turn"
                                "and head back into the hallway. " << endl;
                        cout << endl;
                    }
                    if (foundWeapon == false) {
                        cout << "The skeleton rushes forwards and swings his sword in a wide "  //the user can die here if they havent found a weapon
                                "arc. You feel the pain as the sword rips across your chest, "
                                "spraying your blood against the wall. " << endl;
                        cout << endl;
                        cout << "You fall to the ground holding your chest as the skeleton "
                                "laughs and swings again!" << endl;
                        cout << endl;
                        cout << playerName << "\'s journey has come to an end!" << endl;
                        cout << endl;

                        exit(1);
                    }
                    cout << "You pick up the key and walk out of the room back into the hallway." << endl;
                    cout << endl;
                    break;
                }
                if (fight1prompt == 1) {                                              //they also have the option to not go into the room when warned
                    space();
                    cout << "Youve never really been the fighting type anyways. " << endl;
                    break;
                }
                break;
            case 5:                                                              //this controls movement to the second level, which the second function
                space();
                cout << "You walk to the set of stairs and look down, you cant see the "
                        "landing below. The screams seem to be coming from down here. " << endl;
                cout << endl;
                cout << "Do you truly wish to descend to level 2? (You cannot come back) " << endl;
                cout << "y/n" << endl;

                char level1descent;
                do {
                cin >> level1descent;
                } while(!(level1descent == 'y' || level1descent == 'n'));
                if (level1descent == 'n') {
                    space();
                    cout << "You decide it might be best to look around a bit before continuing on. " << endl;
                    goto stop;                                 //if the user turns back around, they go back to the anchor at the beginning of the do while
                }
                break;
            default:
                space();                                                  //in case the user inputs an invalid input, the user does nothing
                cout << "You stand there doing nothing. " << endl;
                break;
        }
    }
    } while(!(floorOneDecision == 5));            //program ends after 5 is input, which triggers the output and moves the user to the next function
    pair<bool, bool> outputs;
    outputs.first = foundWeapon;       //The outputs here are if the user picks up a weapon or lockpicks. This is essential to what the
    outputs.second = foundLockpicks;   //user can do in terms of combat and certain interactions going forwards
    return outputs;
}

bool floorTwoFunction (int Class, string playerName, bool foundWeapon, bool hasLockpicks) {    //this function controls the gameplay of the second floor
    int floorTwoDecision;                                                              //only one pertinent new variable introduced. output is a boolean
    bool oldMansWisdom = false;
    bool hasPotion = false;

    space();

    cout << endl;
    cout << "You descend the stairs to the second level. It seems a little "
            "more dank in this hallway. The closest room to the left is "
            "collapsed in. There are three other rooms in the hallway and "
            "a set of stairs going down." << endl;
    cout << endl;

    do {
        escape:
        cout << endl;
        cout << "What are you going to do now?" << endl;
        cout << "Enter 1 to enter the right room." << endl;
        cout << "Enter 2 to enter the far left room." << endl;                         //options for rooms to enter. switch statement allows multiple cases
        cout << "Enter 3 to enter the far right room." << endl;                        //which act as rooms
        cout << "Enter 4 to go down the staircase." << endl;
        cin >> floorTwoDecision;
        cout << endl;

        switch(floorTwoDecision) {
        case 1:
            space();
            cout << "You walk to the closest doorway and open the old "                //case for first floor. no changes to variables
                    "wooden door." << endl;
            cout << endl;
            cout << "The old door creaks as if it might break off in your "
                    "hands. Inside, the room smells of dust and is filled "
                    "with cobwebs. It seems like nobody has been in here "
                    "for a while. Besides a couple of old paintings, "
                    "broken wood boxes, and on old skeleton in the corner, "
                    "there is nothing of interest within this room. The "
                    "skeleton seems to be clutching a piece of paper." << endl;
            cout << endl;
            cout << "You walk up to the skeleton and pluck the note "
                    "from its bony grasp. You open the note and read:" << endl;

            cout << "\"If youre reading this, Im dead. It was my last will to "
                    "make you read this\"" << endl;

            cout << R"(                                                ........  .................
                                                              .:??=.  .  ..................
                                                              :???.  .... ................
                                                   .=?+.      =???.   .. .................
                                                   .=??~     .++++.       . ..............
                                                   .~?++.    .?II+      .   ..............
                                                   .~+++.    .I+++.       .  .............
                                                   .:++?.    ,?+++.        .  ............
                                                    :=++=    =I+?+        .. .............
                                           ~++.     ,~+++   .IIII?.       ..  .............
                                           .=??~.   ,~+++.  ,7?+?I.           .............
                                            :=?+=   ,=+?I.. ~I?+++.       . .. ...........
                                            .:++I~. ,=+?I?. =7++++.        .. ............
                                             .~+=+~.,:~=+?,.+I???+.     ....   ............
                                             ..~=++=.:~=+++.I7???+    .=????+, ............
                                               ,~=?I+,:~+??????II?.  +I77I7????,..........
                                               .:~===+:~=I7??+????+?I??I7D7$??II:..........
                                                .~~===+~++???+++++?+?$I?7$II??7??..........
                                                 .:~==++?+++??+?++??++7??.  .?II=..........
                                                 ..:~+=+++?++?++++??++=.    ...IO+~.......
                                                   .:~~==++++++I?+++?=.       .???+.......
                                                    .:~=++++=I+++???I+.       +??++:.......
                                                    .,~=+?+=+=+++???7? .    ..????++.......
                                                    .:~====++=++??I7I7?7,...I7OI??++~.......
                                                    .,:===++?+???77I777II?Z$$IIII??+........
                                                    .,~=====+++??7I77IIIII7$II?+??~.........
                                                    .:~~=====+++?7IIII????+7??+++...........
                                                    .:~======++??7?II??+?+++I++: ............
                                                    .:~=======+?+$?I????++?+?=.   ...........
                                                    .,~=++==+=++II?+??+++?++..    ............
                                                    .:~~=======++?I?++?+?+,.      ...........
                                                    ,:~========++?+I++?+=.       ............
                                                   .,::~========+?+??=?=.         ............
                                                   .,::~==++====++++I=.         ..............
                                                   ,::~~~====+=++++=.            .............
                                                   ,::~==+=+==++++.         .   ..............
                       )" << endl;
            cout << endl;
            cout << "You crumple the note and walk out of the room." << endl;
            cout << endl;
            break;
        case 2:
            space();
            cout << "You walk down the hallway and enter the furthest door to the left. "             //encounter with old man. if this old man isnt given a healing potion
                    "Inside, you see a pretty mundane room filled with a table, overturned "          //the variable oldMansWisdom evaluates to false. If he is given the potion
                    "chair, and a prison cell. Inside, there is an old man chained to the "           //it evaluates to true
                    "wall. You walk up to inspect the corpse when suddenly it breathes! " << endl;
            cout << endl;
            cout << "\"Please! Please help me!\" he cries. \"I don\'t know how much longer "
                    "I can last! I need healing!\"." << endl;
            cout << endl;
            cout << "You don\'t know much about the healing arts, but you can tell he\'s in "
                    "pretty rough shape. There\'s a heavy slash mark "
                    "across his chest and he looks to be exhausted from days worth of torture. "
                    "He won\'t last long without some powerful healing. " << endl;

            if (hasPotion == true) {
                cout << "You take out the red vial you found in the other room and press "
                        "it to his lips. He draws back at first but then gives in. He gulps "
                        "down the vile smelling red liquid, and almost instantly, you see "
                        "the long gash in his chest close up. Right before your very eyes, "
                        "the old man\'s wounds close and color returns to his skin." << endl;
                cout << endl;
                cout << "\"I\'m alive! Oh thank you! I would have died without your help! "
                        "How can I possibly repay you?\" he asks." << endl;
                cout << endl;
                cout << "You tell him why you are here, and his face hardens a bit. " << endl;
                cout << endl;
                cout << "\"I too came here to kill the Crypt King. It was a long time ago. "
                        "I failed and he has kept me here ever since. That weapon you have won\'t "
                        "work on him. You\'ll need to break the staff in his throne room "
                        "before you can hurt him! It\'s his source of power!\" " << endl;
                cout << endl;
                cout << "It seems as though you\'ll need to destroy this staff before you "
                        "attempt to kill the Crypt King. You walk back into the hallway. " << endl;
                cout << endl;
                oldMansWisdom = true;
            }
            if (hasLockpicks == true && Class == 3) {
                cout << "Before you leave, you take out the set of lockpicks you had found "
                        "on your friends corpse and pick the lock. With a soft click, the "        //here the lockpicks will break if the user isnt of the class thief
                        "old man is released from the wall. Because of your deft fingers, "
                        "the lockpicks are still intact and can be used again. You tell "
                        "him to stay here and wait until it is safe to leave. You then walk "
                        "back into the hallway." << endl;
                cout << endl;
            }
            if (hasLockpicks == true && !(Class == 3)) {
                cout << "Before you leave, you turn around and take out the lockpicks you "
                        "found on your friends corpse. You\'re not quite sure how to use "
                        "them, but you give it a try anyways. After jamming the lockpicks "
                        "around in the manacles for a bit, they finally release a loud crack. "
                        "The old man is now free, but the lockpicks are broken. You tell "
                        "the old man to stay here and wait until it is safe to leave. You "
                        "then walk back into the hallway." << endl;
                cout << endl;
            }
            if (hasLockpicks == false && hasPotion == false) {
                cout << "You cannot help this man. You turn and walk into the hallway." << endl;
                cout << endl;
            }
            break;
        case 3:
            space();
            cout << "You walk down the hallway and turn to go into the room "
                    "on the right, but stop suddenly. You hear movement from the "
                    "inside, probably another one of the Crypt King’s lackeys. "
                    "You peek through the ajar door to see a skeleton with a "
                    "poleaxe walking around breaking furniture. This seems "
                    "to be an infirmary of sorts, or at least was. It seems "       //this fight encounter is identical to the first, except at the
                    "that the skeleton has destroyed most of whats in here, "       //end you get a healing potion, which can be use on the old man
                    "but there might be something salvageable here. " << endl;      //to get the oldMansWisdom to become true
            cout << endl;
            cout << R"(
                    ~===:~~~:
                  ~~==~~~~~~~::
                 ~:~======~~~:::
                 ~~===+~~==~=~:::
                ~:++~+==:~~~=~:::
                :=~~~==~==~~=~~:
                 ~===~~~:=~~~~,:.
  ~~~           ,,:.....~.,....:,.
 ~,,:           ~~=::,:=..::,:~~:..
 :   ::        ...=~:,.~.,.,,:~:,,,.
~     ,        ..,,,...,~=~:,...:,,..
+       =      ..,~......,:::........,
=~        = ,  ...,.:,...,::~........
::        ~=~.,,~ ,.~,............
~          ,~,~~,,,,~:.. .....  ..
~=          ,~,,,:=.,,~:..........,
:=           =::.,,,+:::,..~=..,~:: : ..,,
,    ~:,            =~, ,:~.:~:~::=..~,::,.:~:..,:,,
,,.  ~=                 :,,=.:~~=~:.=:=:,.,:,.....:=:~
...~:=:                 =,.~.~=+~=~~~~~::.::,.....,:=::,
.,,::=                  ~~. =:==~=====~:,:~:  ,~~:.=:=:,
:::~                   ==,  ==:~:,,,.:~~. .~,==+=.~:~,:
~..,                   :,:=,==,  ,:~::  ~=~.,, ~?~ , ,,
~=..:                  =..,~=~~~==+:.,==,.=,,. ,:~   =,
: ,.                  ,=++~=~., ,,:=+. .:,::  ,~=
=.,.                 =  .~=:=++~==,  +,,:::  ,::
.,                 ,==~~=:,, .,,.~. ~:::,  ~+
,,                .,.~:~,,~=~==~  ~, ~.   ~~
.,               :~+=~=,+ ,:,,  ~, ~     =
,.              +~+=:.,:=~::,~:  = :   :,
.,.              ,~ ., ~+=~==,,:=,,    =
 .,.              ~ .,  =++=,:=,:,:   ,=
  ,,                     :~~:, +::    ::
   ,,                  ::,::~:::      ~:
    ,.               ~:,,:,~=~,      :~:
    .,.             +=,:::~,~~,.  ,::=~
     ...             =:::::::=~.,::~~~~~
      :,.          ~~~~~:.   :,,:~,:~~~
       ,.       ~=~:~~+::,    ::,,=,,=
        ,,   ====    ,~:,,    ~~  =,~:
        ..,=++=     ~..~      =: :,:~
         .,,        ,.  :   :=~~~::~,:==
       ===::.         :~~~=,,:~  ,~:,:~~
     ,=+~  ,~=~:     :~~ ,~  ~,   :~~ :~=
    ~=~     .+ :~:.:. ~,       ,~~~=   =+~
  :=~=~    ~.,+ ::.:=                   ++
  =+~~      ::,: ::::                   ==:
  ~~~~~     . ,=,   ::                   :=,
  ~~~~       :=,,,  .                    =+=
  ~~~           ,,                        ++=
   ~~~          ,,,                       ~+?=
   ~~:           ,:~:                      :+~
   ,=~           ,.,.                      ====+=
    ~~             ,,.                     ~~==~
    ==             .,,.                    ==~.~~~~
    ,~              ,..                     ::==~,,~
     :~              ,,,                      ~=: ,,
     =+:~~            ,,.,  .                   :~: ,
      =,~:~~:          ,..:=,+~                   =: :
   ~~:,~~~++=         .,,,:,=+:                    =: ~
+~=~~~=+:: ,~~          .,,,,::=                     ~: ~
:~:~~~~:,                  :,,::~~=                      ~: :
=:,=~==                     ,.,,::,,~I                       :,:~+~=
: ~.=,                   ,:II=~:,,:...                       :~:.~:=
~=:                    ,+I+~++:,.,,.,~:                       ~~~::~,~
              ++=~,.,     ...++,                       :,,:~:,~
               ,,            :~~:                      ~=~:~~~~~
                             .+~=:                       ~~~:=~=~
                              .?:~,                        ==,:~=:
                               .I=~                         =~,,~~+
                                ,??:                         =,:,~~~
                                 =++:                        :~~=~=.,
                                 .?=+:                        .~:: ,=,
                                  .I==:                        ~= ~ ~~
                                   ,I+=,                        ~: : ~
                                    ,I+~                         ,: =
                                     =??~
                                     .I+I:
                                      .I=+:
                                       .I=~
                                        .?=,
                                         .I,

  )" << endl;
            cout << endl;
            cout << "That skeleton looks pretty tough, and he isn’t gonna "
                    "go down without a fight." << endl;
            cout << endl;
            cout << "0: Enter Room" << endl;
            cout << "1: Turn Around" << endl;
            int fight2prompt;
            do {
                cin >> fight2prompt;
            } while (!(fight2prompt == 0 || fight2prompt == 1));
            if (fight2prompt == 0) {
                space();
                cout << "The skeleton turns around, surprised by your intrusion." << endl;
                cout << endl;
                cout << "\"Another adventurer, eh? Ill kill you like I did your friends!\"" << endl;
                cout << endl;
                if ((foundWeapon == true) && (Class == 2)) {
                    cout << "And with that, he raises his poleaxe and lunges towards you! You "
                            "raise your sword and block the heavy blow. Through gritted teeth, "
                            "you manage to push back the skeleton executioner. He rushes in for "
                            "another attack, but you manage to chop off his arm before he can "
                            "swing! With a final push of effort, you drive your blade into the "
                            "skeletons chest, killing it. " << endl;
                    cout << endl;
                }
                if ((foundWeapon == true) && (Class == 1)) {
                    cout << "And with that, he raises his poleaxe and lunges towards you! You "
                            "mutter a few words and wave your hand in front of you. A blue shield "
                            "appears and deflects the poleaxe! The skeleton recoils and is thrown "
                            "against the wall by an energy blast! As it tries to get up from the "
                            "blow, you swirl your hand and throw a bolt of fire at the skeleton, turning it to ash!" << endl;
                    cout << endl;
                }
                if ((foundWeapon == true) && (Class == 3)) {
                    cout << "And with that, he raises his poleaxe and lunges towards you! You "
                            "dive to the side and pull out three arrows. Time slows to a creep "
                            "as you hold your breath. In the blink of an eye, you shoot three "
                            "arrows at the skeleton! Two impact the chest and one splinters the "
                            "skull. By the time you hit the ground and roll out of your dodge, "
                            "the skeleton is already a pile of bones." << endl;
                    cout << endl;
                }
                if (foundWeapon == false) {
                    cout << "And with that, he raises his poleaxe and lunges toward you! You "    //if the user didnt get a weapon on floor 1, they die
                            "try to dive to the side, but the skeleton is too fast! He suddenly "
                            "turns his overhead strike into a swipe and the battleaxe catches "
                            "you in your side! " << endl;
                    cout << endl;
                    cout << "You fall to the floor as consciousness fades, and "
                            "the last thing you see is the skeleton raise his poleaxe and swing "
                            "towards your head!" << endl;
                    cout << endl;
                    cout << playerName << "\'s journey has come to an end!" << endl;
                    cout << endl;

                    exit(1);
                }
                cout << "You look around the room for anything of use. All "
                        "you find is broken pieces of wood and cobwebs. You "
                        "almost give up, but then you find an old looking "
                        "green pouch that had fallen behind a cupboard. Inside, "
                        "you find 4 small broken vials and 1 intact vial, "
                        "which is filled with an unknown, foul-smelling red liquid. " << endl;
                cout << endl;
                cout << "You take the red vial and walk back into the hallway. " << endl;
                hasPotion = true;
                cout << endl;
                break;
            }
                if (fight2prompt == 1) {                                                     //the user can choose to turn around and go back into the hallway
                    space();
                    cout << "Youve never really been the fighting type anyways. " << endl;
                    break;
                }
            break;
        case 4:
            space();
            space();
            cout << "You head towards the stairs going down and hear the princess scream. "      //this level descent is identical to the one before
                    "You can tell she\'s close. You can feel a presence in the back of your "
                    "head, warning you to prepare yourself before you head down." << endl;
            cout << endl;
            cout << "Do you truly wish to enter the Crypt king\'s Lair? " << endl;
            cout << "y/n" << endl;

            char level2descent;
            do {
            cin >> level2descent;
            } while(!(level2descent == 'y' || level2descent == 'n'));
            if (level2descent == 'n') {
                space();
                cout << "You decide it might be best to prepare yourself to fight the Crypt King. " << endl;
                goto escape;                                 //if the user turns back around, they go back to the anchor at the beginning of the do while
            }
            break;
        default:
            space();
            cout << "You stand there doing nothing. " << endl;
            break;
        }
    } while(!(floorTwoDecision == 4));
    return oldMansWisdom;                   //all other variables are defined in main already. This is the only one from this floor that needs to be outputted
}

pair<bool, bool> bossRoom(int Class, string playerName, bool foundWeapon, bool hasLockpicks, bool oldMansWisdom) {
    int bossRoomDecision;
    bool savedPrincess = false;                         //this function controls the boss room and has the inputs of the other outputted functions
    bool killedCK = false;                              //it outputs two of the end results used to write up a conclusion to the game

    space();

    cout << "You swallow your fears and head down the stairs...into the Crypt Kings lair!" << endl;
    cout << endl;
    cout << "You make it to the bottom landing of the stairs and find "
            "yourself in a large chamber. Towards the back of the room "
            "there is a throne fit for a giant made of dragon\'s bone. In "
            "the center of the room is a large stone sarcophagus, inscripted "
            "with strange glowing runes. Behind the sarcophagus stands a "
            "staff, which is emitting a strange, hypnotic purple glow. And "
            "there, in the corner, lies a metal cage containing none other "
            "than the princess herself! " << endl;
    cout << endl;
    cout << R"(
            ????????????????????????????????????????????????????????????????????????????????
            +==++=++=+=++=+=++=++=+==+=+?=+=++=++=?++?=??=?=+?=?+=?=+?=??+?=+?=?++?=+?=?++?+
            +++++?+++?++++??+??++??+++??+???+??+??+??+??+???+??+??+??+???+??+??+??+???+?????
            ?++++++=++++++?+?=++=+????=+++++??=?????=??+???+?????+?????????????????+????????
            +??+++?+~+?~==+?++++?~??++=?+???++=++??=???+++?+++??+????????+=?????????+??+=???
            ++~=++?++=~~~+?==++=+?====??=++===+????++~~+?+=+=~????+???+?+===+?+??????++==+?+
            ~=++~+=+~~~~~~++?~?=+~~====+++~=+~~+??+??+++?+I?I?I==??++?+=======++??=+======++
            ~~~~~~~~~~~~~~~~~~~~~~====~=??~=?=~??=IIIII?=+~+??I+I+?II~======================
            ~~~~~~~~~~~~~~~~~~~~~===~??+~++=++=????????II??++?~?I??II=======================
            ~~~~~~~~~~~~~~~~~~~~==++???+?+??=????+??+,~:~??+?=~=+==?~==+====================
            ~~~~~~~~~~~~~~~~~~~===???+?+??++????+:=~++~==+++==++=+I+???=====================
            ~~~~~~~~~~~~~~~~~~==?III+??+??????+=?????+=++???++=+??~~~?===+==================
            ~~~~~~~~~~~~~~~~~~~?IIIIII~??????=?=+?=++?IIIIIIII?+++==+++=:+==================
            ~~~~~~~~~~~~~~~~~~~?IIII7?II?I??:?==+++?IIIIIIIIIIIII?=+=+???+==================
            ~~~~~~~~~~~~~~~~~=????IIIIII7I?=?+=++??IIIIIIIIIIIIIIII+=?????==================
            ::~~~~~~~~~~~~~~~~????I?III7II+??+==??IIIIIIIIIIIIIIIII??+????==================
            ::::~~~~~~~~~~~~~+++???+??III????=++?IIIIIIIIIIIIIIIIII??+=~??==================
            :::::~~~~~~~~~~:=++++?????I???I?+???IIIIIIIIIIIIIIIIIIII??==+??=================
            ::::::~~~~~~~~~=+++++???????+I??++?+~~==?IIIIIIIIIII?++?I+?++,+I================
            ::::::::~~~~~~~~=++=+=?????+?I?+=IIIIIIII?+IIIIIII?=IIIII+??=?=~================
            ::::::::::~~~~+=+?++++??????II???I??~+++??IIIIIIII?++++?II=?=??===+=============
            :::::::::::~~~~++???++?++?+??I?:?:....,++?IIIIIII?,=.,~~+?+=?+?:================
            ::::::::::::~=~???+++++++++??I+=,,+,,~+..+?IIIIII~.::=~,.~=~===+=?==============
            ::::::::::::~~++??+++++++++???,.= :~..~+:I?IIIIII?:~.+:?.,+=~=?:=+~=============
            :::::::::::~~~???I?+?+++++????+?I7~+::=.?IIIIIIII?=+.=:I+:+~=~+?~+:=============
            :::::::::::~=?=???II??++++???=++,~?=?I?IIIIIIIIIII?I?==+=,+++==,I+==~===========
            :::::::::::~??++???I=??++????==?I????IIIIII?IIIIIIIII??I?~+=+:==??==============
            ::::::::::==?=++?+???II+?????+??????IIIIIIIIIIIIIIIIII??+==?=++=~I~=============
            :::::::::~~?+==+?+?+????I?I?.?+??????IIIIIII????=IIIII???+~?~?:=+?I=============
            ::::::::~~=?=+=++?++??+??II?=+?????IIIIIIIIII+=~?IIIII??+++==???+=I=============
            :::::::~~=?+~+++++=++=+??II+??????IIIIIIIIIIIIIIIIIIII??~++,+??~+?II+===~~==~===
            ::::~:~~~+==+=~==+~?+=+????,.=??IIIIIIIIIIII?+++IIIII??+=++++??I??=I~?===~~=~~~=
            :::::~::~~+=+=~=~===:=++?I?=+=,?IIIIIIII~=:??77I::III??+~++?~?II=????=?==~~~~~~~
            ::~:~::=~=:?=~=~~=+==+++?I+~=,=:?IIIIIIIIII?????IIIII~=~=++?=?I?=?+??=?==~~~~~~~
            ::::+~=:==:+~:=~=~===++?I?++=~+==,?IIIIIIIII?+?IIIII:=~==++++???==+~?==?~~~~~~~~
            ::~:~=:==++==+=~==:=++???~=====+++=~=IIIIIIIIIIIIII~+~~==++,???+=~=:?==?~~~:~~~~
            :+:~+,~~~:?=~+~~=====+?I?=~~==:?I?++++=+IIIIIIIII+=~+:~=?+=+?+?+=++?==~=~~~+~I~~
            =:~=::~==++~:+~=====+???++=~~==?IIII??++++.=III?::==+=~==:=++=~?+++?==~=~~~~~=~~
            ::+,~~=++?=:~+:+:==+???+:?:~:==?IIIIIIII??+++:~~=:~====~=~==++???:+?~~~=~~~~~~~~
            :+:~~~?:??:++=+=:+=????+=+=:+=+?IIIIIIIIII???+~~+=++~~=~~:=~,?==?=+?~~=~~~~~?~==
            ~~~~~?++?=:~+++~==+????++=~+=+=?IIIIIIIIIII??+~:++~~~~++~~~+~+++~=+?~~~~~~~~~~~~
            ~=~~+++?+~+::+==+????~=++=+?=++?IIIIIIIIII?I??:+~=+~~~+++~~~?:=+==+~~=~~~~~~?~~~
            ~~=+==?+:,+====+??I?~=?=+,:~~++?IIIIIIIIIII?++=?I=+~~~=??~===?~,++?~+~~~~~~~:~~~
            ~~+????=~=,=:=+????:=?=~==+++?+=IIIIIIII?????:=?~++====???++++?~:=?:~~~~~~~~:~~~
            ~==+??+~~=::=+?I??=+=+++~~+=+++=IIIIIII??+?I+?=~=+?=++~???=++++?=?,=+~~~~=~+?~~~
            ?+++?+=,=~==+???++??===+~==+++++IIIIII???I+++?===?++++=??I+??++~?I+=+=~~~~~~I~~~
            =?~?+=~=~:~????~+=+++++=+?+~????IIIII?++I?++++++,?=???+IIII????+I::=~+==~~~:~~~~
            ???+~~+~,+???~==++~=?++++:?IIIIIIII??++I???+?=++?I=????IIII?????:I++==?=~~~~~~~~
            ??+=~===?????~:++?+???+:?IIIIIIIIII?I+I=?~+??++?II+????????=???:+??:===?~~=~~~~~
            +?~=,=????=I~I++~~+=?=??IIIII?I?II?????==?=??+??II?????+???~+~+++:?:=+=~??=~?~~~
            ++=:=???:??++~~=:~~??IIIIIIIIIIII+?+????,??I????I?I?+?++??+:=++++=?+,++==??~=~~~
            +=:=???+??+=~~:.+=???IIIIIIIIIIII?~??=+=?+~I+??????+++++?++:===+++++~=?+===?+===
            +:???,=?+=??+===:+???IIIIIIIIIIII??????:?:=I++?+:??=====~++,~~====++~==?+~==~++=
            +???I++~???~:::==???IIIIIIIIIIIII+??~~~I?~=??++++?++=~~~~==,~::~~:==?:++?+=====~
            ??~=~+?~I=~~~:==+??IIIIIIIIIII=I=~?+?:=?~~:??====+==:~:~:==::::::,=~+?==++?~====
            ?~=++=:?+~======?IIIIIIIIIIIIII?+??=?=~+:~~+++~~~~===::::~+::::,~~:?+?==+???~===
            ++==++~?:++::++??IIIIIIIII?I+?~+=?++?=?~==~~==,::~:~=+~,+?II??++==+=~?~=~+???==~
            :+??,:+~?:~,=+,IIIIIIIII?=+I=+?+??++==+====::===::::~=?IIII??=?~===+=+?==~+???=~
            =~:?+~=I~~:==+==,~+IIII+=?~=+,~+??=++++:=====,,~+:===++????+I?+=:==+++?===+???+=
            +??~=~I~=~+++++===~.~I=?~~~?:~+~??:?+?=++++===~~:==~+?+?=I+I+?~=+===~+?~=+=+??++
            ==?~,=~+~=++?++==~~~~,,=,+?+?=+??++??+?:++++==~~~~==+~?==I?+=+==:=+~?~+?===+??++
            +I+?:?=~~?????+++=~:,~~~~~+====??++?+??:??++==~~:=++~??IIIII??+=,=+~?~+?:~==+?++
            :?=?:~~~?????+++~====+:=++=+=+I?++++:===?+++===~~~++???IIIII??+===+~?+???~==+??+
            ??:?+~+++??+++++=:+===~+?~+=++???=+?==:++++====~~=+++??IIIII??+==++~?~~??:~==+?=
            I++?++~++++++++++=:+=+:++:+?+~?++:+?+==+++====~~~=++???IIIII??++=++=?~+?I+~~+?+=
            ???++==++++=++==,~~+==+?++?:???++~+?++++=====~~~~=++???IIIII?+++=+?=??=?I?++=?==
            +??++~++=======+,=~+~++~=:??=?+++=+?+?++===~~~~~~=++???IIIII?+++=++=???:II~++~==
            ?=?~+++========.:,++~+?+=+~????+==+?+?++==~~~~~~~==+???IIII??+++=+?+??++?II+++~=
            ?:?==+==~~~~===::,++~+:=~?++??++==+?==+~==~~~~~~~~=+???IIII??++~=+?+II:=~??++=~=
            ?:?====~~~~~~~~=:+=:++,=+~?+??++==+==~=+==~=~~~~~~++???IIII??++,=+?+?I?+++???++=
            ?~?===,~~~~~~~~~~+=,,?=:?++???+=+~+~=?:+==~~~~~~~~++???IIII??++~++?+?II=~,???~~=
            +:+=:=+~::::~~~~=+==~,~?=++I??+=~~+:=~~+?=~~:~::~~++??IIII???+++?????II=~=???~:=
            +,+==~+,::::::::~==~+=:?++??++?=~++:+~~I????~::::~++??IIII??+++=++????I===~+??~=
            ~:+++~+?:::::::~,~~.,=?++????++=?,+:+~:~????~~::::++??IIII??++==+++???I~=~~:++?+
            :?+++,+?+:::::::~~:?=,+~=??++=~~::+~~::~~~~~~~::::++??IIII??++:==++?????+~~+,?+?
            ,?+~+,+?I,~:::::,.:~=?+++??+?+=~+:+~:~~~~~~~~~:~+~+???IIII??+++====????I+=~=:.?+
            :+==+:+?I~~~::~~:,?:~+~+?++++==?:+++~~~~~~~~~~::?=????IIII??++=~==~+????+=~~==:?
            )" << endl;
    cout << endl;
    cout << "The cage is surrounded by large piles of gold and treasure "
            "chests. Both are guarded by two skeletal minions who stand "
            "at the ready. They have not seen you yet." << endl;
    cout << endl;

    cout << endl;
    cout << "What are you going to do now?" << endl;
    cout << "Enter 1 to sneak to the princess." << endl;
    cout << "Enter 2 to attack the Crypt King." << endl;                                //no do while loop because you can only do one choice
    cout << "Enter 3 to steal the gold." << endl;                                       //every choice has to lead to the end. no repition
    cin >> bossRoomDecision;
    cout << endl;

    switch(bossRoomDecision) {
    case 1:
        space();
        if (Class == 3) {
              cout << "Like a whisper in the night, you stealthfully creep up "           //if the user is a thief, they can sneak up to the princess, save her, and escape
                      "to the princess\' cage. But the cage is locked! " << endl;
              cout << endl;
              if (hasLockpicks == true) {
                  cout << "You pull out the lockpicks and quickly unlock the door. "
                          "The princess is free, but the guards and Crypt King remain. " << endl;
                  cout << endl;
                  savedPrincess = true;
              }
              if (hasLockpicks == false) {
                  cout << "You pull on the bars with all your might, but the cage remains locked. "
                          "You have no way of freeing the princess! She looks at you with tears in "
                          "her eyes. Maybe the Crypt King has a key. " << endl;
                  cout << endl;
              }
              cout << "You are about to attack the guards when you see daylight out of the "
                      "corner of your eye. A way out! You could escape now while you have the chance! " << endl;
              cout << endl;
              cout << "What do you do? " << endl;
              cout << endl;
              cout << "Enter 0 to attack the Crypt King and end this!" << endl;
              cout << "Enter 1 to escape the Crypt King\'s dungeon." << endl;
              cout << endl;
              int fightOrFlight;
              do {
                  cin >> fightOrFlight;
              } while(!(fightOrFlight == 0 || fightOrFlight == 1));
              if (fightOrFlight == 0) {
                  goto Attack;                //this takes you to the combat encounter
              }
              if (fightOrFlight == 1) {
                  goto run;               //this takes you to the very end where you can escape, but doesnt update any of the variables like saved princess of killedCk
              }
           }
           if (!(Class == 3)) {
              cout << "You trip on a stone halfway to the cage and alert the guards!" << endl;
              goto Attack;                 //if you arent a thief, you trigger combat here
           }
           break;
      case 2:
           Attack:                     //if attack was chosen initially or triggered from case one, it goes to the beginning of combat
           space();
           cout << "STOP SCROLLING" << endl;
           cout << "You step forward and callout the Crypt King. The skeletal minions notice "
                   "your presence and creep forwards. Suddenly, the sarcophagus bursts open "
                   "and out flies the Crypt King himself. He\'s as tall as a giant and as fearsome as a "
                   "demon, with a skull wreathed in flames. " << endl;
           cout << endl;
           cout << R"(
                   7777                             777I==~777
                  777777                           7777?~=~=I7 7
                   7 777777      77777777   777777777II+==~==+777
                  7777?777777   777777777777777777777I?=~~~~~~+7
                   7777=~7777777777II7777777777=~=~?+=I?=~I~?777
                  7777777~I77777I+~~++77777777~=~~~=+++?+=~~?7
                  777777I?:=II?+~~~=~~=?II7777I===~~===+===+?I77
                  77?77III+~~::~~~~~~+~~=+?I7III?~~~~===~?~?~=?I77
                  77?=?77+I=::~~~~~~~~=+==+II?+===~~~~~~~=~++==?I777                7
                   77I?I77I~:~~=~~=:::~~=~====~~:~==~~~~====~~==+II7777777       7777777
                     77777II+~~::~~~~~~~+~~~~~~~~~~+=~~~~=+?=~~~=+II77777I77I77  7777777
                       7777I+==~~=+=+++~~~~~~:~~~~=~~~~~~~+=+=~=~=++II7II+===I77777777777
                        77777I?~~~+~=+==~~~~~~~=:~~~~~~=~~=~+~=======~~~~~=~~?7777777+777
                         77777I+=~=~~~+=~~==~~~~+::=~~::~==~=====+~=~~~~~~=+~=?III7I??777
                       777IIIII?~~~=~~=~~+~==~~~~=~~+=::=+~~~=+==+=~~~~~=+=+===~===~+=I7
                      7777?=?~??=~~+=:~=~=~+~~~~~+~:~~==~~~~~~~=?===~==~~=++===~~~=7~+I7
                     7777~~~~~~==~~++:~~+=+=+==?=~=~=~~=7~~:~==~=+=~~~~=~=~+=?+~~+=?=+77
                     77II~~~~~=~~~==~:~~~==?++=~~~~~===::~?:~===~==~=~+~~~~~=+==~~~=?I77
                      7I=~~~~~~~~:+=~~~~~==?++=~~~~~~~=~,~~I++~~+=?+=~~=:~~~=~=~=++=?7777
                       7++~~~~~~~=++==~~=~~==?+====~~:~::=~===~=~~++~~===,,,~~~~=~~=+I7777
                       77I=~~~~=??=+~?~=~??+==++==+=~=~:::======+?+?+~~~==:::=+===:,~=7777
                        7I=~:~~~=?=~~+=~~~====+===~+=~=~:,=~==+?+?++==+???I:=~==?+?=~:+77777
                        7~~+I===++=~~~?~:~~~=~~===~~~==~::::~==++++++?+?++++?+~~~+?=~:~?77 7
                    7777=~~?+~~++???+::~::::~:~++~~::::::::~~+?+???????????==++++=+?:::=~777
                    777I=~~?=~=+~I?===::~:=~:+~==~~::::::::==?IIIIIII?IIIIIII+I+?+==+=~+=?777
                      ?I=~==+?==~~??~:~:~:=~~:~+=~::::::::==?II?II7II77I777IIII?=I?=~=::~+77
                      7?I~=+????++?+=~~:~~:~:~:::~::,::~:~~+77:7I777II777777777777?II:::~?77
                      7+=??++++?~++=~++==~~~===::,:,::~:..,.,:.~=+?IIII7777777I?III+?7,,,~I777
                      I=~=???~=====I~~?++=~~:==+::::::::...,,::::,,.++?777777I=..,...~I:,~~=I77
                   7 77~:~=+?++~==,?III?=~::,+~~~::::~?...,::=+==~,,,++?II77I+,,,~::,,.:?,~~=77
                   777I~:~:=++==~=+~==?III?I?~=:~:,,~??...:=~=??+=:,,+=I?+???=~,~~~==~,,~=:~+77
                  ? 7I=~::~~=I~=+I=~=?~~++I??+~~~~:,~I,,,:=++????+=~:~I+??+77?=~===?+==,.?:~I77
                  +=+=~~~:~~~+==~~~::~::++??+===:=,,=II,:~=++???==~:,.==+7,,.,~:===+===:,?:~+77
                  7==~==~~:~??~~~~:,,=:++=?+?~:::=::+??:,,~=======~:.?,~......,I~=====~,.+:~=77
                  7+~===:::==::::,:::,:=+++?++:=::,:=I??I,,.......?II~:.........?7~==:,..~::~77
                  7=:+:~::::~~=+:,~~:,=:,+==~:~,=.,,:=+?I+~.....IIII+:=,......,.=+I~,,,..:,,=I7
                  77=~~::~::::~=::~:~?~+~===:::~:.,::::~=?II===?????~:...........I77+II~::::,~77
                  77I+~::~~:~:=~~~=??+~==+==~~:,,,::,,:=++=+=~I,=+++~:...........?III7?~=:~:.:I7
                  7777~::::=~~+==?????=+=++=+~:~:.~,:~=I?+~+++==+~:~~:,...,:=....?II++?++=~~::~77
                  7777I:=:~+?++?+???++==~?+=~~::,,:,:~+?I?II??+=~:~=~~+,..,=~?..??I+=II?+==~~:~~7
                   777II+=:++?=???+==~=~===~~~:,,=:::~,::,?I???II~++:,=+:~,:~====?=:I?I??+~~~::=7
                    77II?=~~=====+~=+?=~:=+++~:?:~:,,:::~::~?==.~++?,.:=::=:~~:~=?==++=~~~::,:=77
                  777I=~~=~:+===+~~=~~=:~++?==++=~.,....,.,:~+++=:~I,,:~+~+=:?:::===+=~~:~~::=I7
                  77+=::==~~+++=~?~,,+?=++++===:,::,,::,~..,=~::.~~:,::,,.?.,II.?I:?~~~~::::~=77
                   +======~~~==++?=~++++=++==+~,,::,,~~~:...:=?+~~~~~:,:,:+?:?I???=?:==~:~~~:~77
                  7=~~====:~~~===+=:?+=?++++==~~:=:::+=+~,,..~=~=+=,.=,~=:~?:+??,:~?:=:::~::=777
                  7=~~~~~~:::::=~+:~+~===++++=:~~:~:??+?,~::,,::~+~7,?~=:.......::,,~+~:~~+I77
                  7?==~::~=~::~+=+=?=~:,:=+++==~==~=++?=,:::,.::=I: .=,.,...,...,::~,::~=~I77
                  77 7I=~II?~:+=~+===:~,:=~==~~~~=++=??+,:~~,,:7=.,,,,,,,,...,,::~~:~~~~~I77
                      77777I+===~~++~::~====~~~::~=+?=+?~~=:,,...,...:,:..,..:,~:~~~~~~:+77
                           7?~~~+=+~=:~~~~=~~:::::~=?+?I~=~:,..,.,,,.::,.,,,:::::::~::,:?77
                           77I?=??=+:=~~~~~:::~::,,~+++I+~~:::~,,,::,.~=~:,,:,:::,::,:,.I77
                             77777I=+:~::~=:,:::~:,::==++==~~:,:::~:~~=::,,:~::+,,,,.,,?77
                                777I=:::~~~:=:~:,.:=,~=~:+==?~:,:~:~~:~~~+~:~~=~?:,,,,~I77
                                  77I~,:=~~~~:~::~:=:~~:~,~=+++,::::~~=,?+=:~~:~::,.,,+77
                                   7777I777777I+~~:~=:,:~~:=~=~+~,::::~:,~~==~::,,,,,,+7
                                    777777 77777I:~~~::~~~~~=+==~+?,,:,,..~~~~::::~:::+77
                                            77777I~~~::~~,::~==+:==:~,,,.:,:~~,:::+~:::77
                                               7777~~~,~:~::::~:::::I=?.::::,,:,,,~:::~I7
                                                777I~~:.:::,:,~~~~~,=~++?I:::,,:~~:::~:?7
                                                  77+II?~,:,,:~~~,~:~::~:+:+~+:~:::::,~I7
                                                 77777777?=,:::~~~:~~:,:.~:?::~~~::::~77
                                                  7 777777?~:::::~:::::,,:=~:::,:::~~I7
                                                      7 777,:~~~,,,,::,::::::,,,:~=+77
                                                        7 I+~:,.,,,,:,::::~:::,::=+77
                                                           77~:?:,,,:~,:::::~:::~=7
                                                              7777II?I+=::~~+II77
                   )" << endl;
           cout << endl;
           if (foundWeapon == false) {
              cout << "You go to attack...and realize you don\'t have a weapon. Ouch." << endl;     //theres a lot of if statements here. the take away is that
              cout << endl;                                                                           //if you dont have a weapon and dont have the old mans wisdom, you die
              cout << "The Crypt King and his minions tear through you without resistance. " << endl;
              cout << endl;
              cout << playerName << "\'s journey has come to an end! " << endl;
              cout << endl;
              exit(1);
           }
           if (Class == 3 && oldMansWisdom == true && foundWeapon == true) {
              cout << "You remember the old mans advice and shoot an arrow towards the staff. "
                      "The crystal atop shatters in an explosion of purple energy and the Crypt "
                      "King groans. His minions rush up to attack. You drop to the left and "
                      "dash to the right, all the while shooting arrows like a maniac. You deal "
                      "with the minions easily and begin to work on the Crypt King himself. You "
                      "dodge his attacks, counter his blows with returned arrows, and after a "
                      "long battle, only you remain standing." << endl;
              cout << endl;
           }
           if (Class == 3 && oldMansWisdom == false && foundWeapon == true) {
              cout << "You desperately shoot arrows at the Crypt King, who laughs them off as "
                      "an elephant would a mosquito. As you fight off his minions, he raises a "
                      "giant arm and crushes you with an earth shattering blow!" << endl;
              cout << endl;
              cout << playerName << "\'s journey has come to an end! " << endl;
              cout << endl;
              exit(1);
           }
           if (Class == 2 && oldMansWisdom == true && foundWeapon == true) {
              cout << "You remember the old mans advice, destroy the staff! You run past "
                      "the minions in a mad beeline towards the staff. You duck under the "
                      "crypt kings legs and cleave the staff in two, releasing a purplish "
                      "explosion of energy. The crypt king howls in pain! You use this "
                      "opportunity to mercilessly slash his ankles. As he falls to the "
                      "ground, you plunge your blade hilt deep into the throat. With a "
                      "gurgle, the crypt king topples over. " << endl;
              cout << endl;
           }
           if (Class == 2 && oldMansWisdom == false && foundWeapon == true) {
              cout << "You run into the fray of battle. You fight off the minions and the "
                      "crypt king as long as you can. Dodging blows, returning attacks, but "
                      "it seems to have no effect! Your body eventually wears down from "
                      "exhaustion and you drop to one knee. The crypt king laughs and shoots "
                      "a purple lightning bolt at you, killing you instantly." << endl;
              cout << endl;
              cout << playerName << "\'s journey has come to an end! " << endl;
              cout << endl;
              exit(1);
           }
           if (Class == 1 && oldMansWisdom == true && foundWeapon == true) {
              cout << "You read an invocation from the tome and three rays of fire burst "
                      "from your outstretched hand! One evaporates the purple crystal and "
                      "the other two go right into the chests of the skeletal minions. As "
                      "the crystal explodes, the crypt king howls in pain! You take this "
                      "chance to shoot a beam of ice towards the crypt king. It hits him "
                      "in his midsection and freezes him halfway through! As he falls to "
                      "the floor, he shatters on impact." << endl;
              cout << endl;
           }
           if (Class == 1 && oldMansWisdom == false && foundWeapon == true) {
              cout << "You levitate towards the center of the room and shoot out magic "
                      "missiles like a porcupine. The skeletal minions are instantly shredded. "
                      "You fall to the floor, exhausted from your display of magic. When you "
                      "look up, you see the crypt king smiling at you. He speaks in a language "
                      "you can\'t understand, but you cast a spell to translate his words. " << endl;
              cout << endl;
              cout << "\"Foolish mortal! You cannot hurt me with your weak and mundane sorcery! "
                      "Prepare for everlasting torment!\" " << endl;
              cout << endl;
              cout << "And with that, the Crypt King hurls you through Hell." << endl;
              cout << endl;
              cout << playerName << "\'s journey has come to an end! " << endl;
              cout << endl;
              exit(1);
          }
          cout << "You stand victorius over the corpse of the Crypt King and his minions. "
                  "You\'re so exhausted from the fight that you want to pass out, but "
                  "you\'ve got a job to do. You snatch what looks to be a key from the Crypt "
                  "King\'s corpse and walk over to the princess\' cage and unlock it. " << endl;
          cout << endl;
          cout << "You walk out of the dungeon with the princess in tow, and the Crypt King slain. " << endl;
          cout << endl;
          savedPrincess = true;
          killedCK = true;
          run:              //if you decided to run, you go here, after the variables are updated
          break;
    case 3:
          space();
          cout << "You greedy bastard. " << endl;
          cout << endl;
          cout << "You move over to the gold pile, and surprisingly no one notices. And as you start "
                  "to stuff piles of gold coin into your pockets, you fail to notice "
                  "the Crypt King awaken and just stare you down. " << endl;
          cout << endl;
          cout << "The Crypt King then impales you through the back with a large pitchfork, killing "
                  "you instantly. " << endl;
          cout << endl;
          cout << playerName << "\'s journey has come to an end! " << endl;
          cout << endl;
          exit(1);
    }
    pair<bool, bool> outputs;
    outputs.first = savedPrincess;               //the variables are put into a pair and outputted to main
    outputs.second = killedCK;
    return outputs;
}


void finalMessage(string playerName, bool savedPrincess, bool killedCK) {
    if (savedPrincess == true && killedCK == false) {                             //the outputs of the boff floor go here ultimately and the final game ending is determined from
                                                                                 //the values of these variables
        cout << "You and the princess run as fast as you can from the Crypt King\'s dunegeon. "
                "Even though you were not successful in killing the Crypt King himself, you "
                "did manage to save the king\'s daughter. The king rewards you handsomly with land "
                "and his daughters hand in marriage. However, the Crypt King still remains. One day, "
                "you will have to return and kill him once and for all. " << endl;
        cout << endl;
    }
    if (savedPrincess == true && killedCK == true) {
        cout << "You and the princess leave the Crypt King\'s dunegeon. You manage even manage to take "
                "some of the treasure with you. Your eturn to the king a hero. Not only did you save his "
                "daughter, you rid the lands of the evil scourge that was the Crypt King. In addition to "
                "the princess\' hand in marriage, you are given land to live on and wealth beyond imagination. "
                "because of you, this land can now know peace. " << endl;
        cout << endl;
    }
    if (savedPrincess == false && killedCK == false) {
        cout << "You run as fast as your legs can take you from the Crypt King\'s dungeon. You return to the "
                "king empty handed. You were lucky to just make it out alive. He gives you some money for "
                "the loss of your friends, but it isn\'t much. You might not have saved the princess or "
                "killed the Crypt King, but you did make it out alive. That\'s more than your friends can say. " << endl;
        cout << endl;
    }
    cout << R"(
            ~~~:I??+==~~~=~++????+++=:~::~==+??++=~~=??+???+====::::~==?++=+=:::::~=~++++=~=~~~=+?+=~:~:::+==~:~::~~=++~~~++++?+++~::::~=++=~::+===~:~~+?~~~~==:++~=:=~~====
            ~:~:I+?+=~~~~~~++??????=+~~::~~=?I??+=~~=?++?+?=+++~::::~=+??+++=:::::~=~++++===~~~~+?++~:~:::++=~:~::~~=++~~~=+++?+++~:::,~~++=~::?===~:~:+?:~~~==~+++~~==~~==~
            ~:~~II++=:~~~~==+??+??++~~~::~~=+?+++==~=+=+??+++===~:::~===?+?==~::::~==+=+=+==~~==??+~~:~:::++==~~::~~=++~=~++++?++==::::~=++=~::++==~:~~+?~~~~==~++==~~~~~==~
            ~:::II++=:~~~~=++??+??+==:~~:~~==???++=~~+=+????+==~=:,:~==+?++~==:~:::~=+++++==~~=++?+~~~~::~++==~:::~~+++~~~++++?++==:~::~~::=~::++=~~:~:+?=:~~~=~++~~~~=~~===
            ~~::I??+~~~~=~=++??+?+~:~:::,::~=?~==+~~~+=+????+=+=~:,:~==??++===:::::~===++++=~~=+??+~~~~::?=+==~:::~~+++=~~+~~~~~:::::,,:::~:::~:~~::~~~+?=:~~~=~+++~~~~~~===
            ~~::II?I~==~=~~=+??=::::::::,.,,::,:,,.,,==++??+====~:~~~=+=??+++=:::::~+++++=+=~~++??+=~~~~:?+===~:::~~++==~~=:::,:,:,:,,,,,~,,:~,,,,::::~=?=:~~~=~++=~~~~~==+=
            ~~::I???==~~=~~=++~=::,:,,:,,:~:::,,,,.,.,,:=?+?===~~::::==++?++==:::::~+=+++===~~+??++=~~~::?++==~~~:~~?+=~~~::::,,,.,,:,,,..,,,,,.,,,,:::~==:~~~=~+++=~~=~==+=
            ~~~~+I?+==~~~~===~:::~,,,,,,,~:,,,,,,,:~,,,.,,:?++==+::,:~+=??++==:::::~=~=+++~+~==?++==~~~::?+===~~::~~++~~::~,:,,,,......,:,.:,.,,.,,.,,,,:~~~~~===++~=~=~~+==
            =~::~??++==~~~~~=,,,,:,.,...,,.,:,,,,:~,,,,,....,=~+~~:::~===?++~==:::::===++==?~++?++==~~~::?+===~:::~~=:~:~~=:~:,,.....::,..,.,...,.....,,,::~~~=~=?+~=~=~===+
            ~~:~:??+?==~~~~::,,,,,..,,,.,,:=~:::,,,,:::,,,,.,,.:=~:,~~==+?++===:::::~=++++==~++?+++=~~~~:?+==~~:::~~::~~:~,:,:,,.,,,,.~,,,...,.....,~:,,.::::~=~=++~=~==~==+
            =~:::I??+=~~~~:::,,,,,..,....,:.,,,,~,,:,::,,,,,....,~:::~=+++?+++=~::::~+==+++==+???+==~~~~~?+==~~::::::~::~,,,,,,,,,.,,:,,,,,,,,,,.......,..,,:,=~=?+==~~=~~=+
            =~~::I???=~~~::~:,,:,......,:,::::::,,.,,.,.,........,::::==++?+?==::::::++++++==+???++=~~~~~?+==~~~~~:::,,:,,,,,,.,,,:::~~~~~::::::,,:,,...,.,,,,~==?++=~~=~~=+
            =~~::I?++=:~~.~~~,,,,,,,:,~=========::,,,.....,,.....,,:,:~=++?++=~::::::+~=+++==+??I+==~~~:~?+==~~~:,:~::~::~::,,:::~~=====+++===~~=~~~:,,.,....,:~=?++~~~=~~=+
            =~:::I+?+~~:,:,::,::::,:++?+????+++====~::,,...........,::~==+?++~=~::::~==+++=+=+???+==:~~~:?+==~~::::,,,,::~:::~~===++++??????++======~~:,,,.,.,,~~+++=~~=~~=+
            +=~~~I?++~~:,:,::::::~????III??II?+++=++==~~:,..........::~==+?++==~::::~~~++++=++I??===~~~~~?+==~~~~:,:,..,:~~==+?IIIII????I????+++=====~~~::,..,,,~+++~=~=~~=+
            ==~:=I??+=~~:,,:,:~:??IIIIII7IIII?????+++++=~~~:,.......::~==+??=?==:::::~~+=++++????===:~~~=?+==:~~:::,,,,,===+I7777IIIIIIII?????+++======~~~:,.,,,,++=~=~=~=~+
            =~~:~+???~=:~:~:~~???III7777IIIIIII?+????+?+++=~~:......,::=+=??++==::::::=+++=++??+++~~~~~~+?+==~~~:::,,,,=?III7777IIIIIIIIII???????+++====~~~:,...,~++~=~=~~==
            ==~~:~???==~:=~::??IIII7I77IIIIIII+?????????++++=~:,...,.,:~=+=++=~=:,::::=+=+++??I?+==~~~~~??+==~~~:::::,~?IIIII7IIIIIIIIIIIIIII?????+++===~~~~:,,.,:++==~===~=
            ==~~::??+==,,===+??IIII77I7II?+?IIIIII+=???+++++=~~:,.,..,:~==+?++~=~:::::==+?++??I+++~~~~~~??+==~~:::~~~+?IIIIII77777IIIIIIIII????++++++==~~~~::,..,,~+~=~~=~~=
            ==~:::??=+=:~?=~??IIIII7777IIIIIIII?III?+??+++====~::,,...:~=~+?+?=~=:::::===++=?I?++==~~~~~I?+==:~~::~~=?IIIIIII777777IIIIII????+====:::::~~~~~:,,..,,===~~==~=
            ==~::~II??=,~:~+?IIIIIIIIII7?IIIIII??I+=::,,,,~,:~::::,...:~===?++?+=,::::~~+++=+I+++==~~~~~?++==~~~::~==??IIIIIIIII?I????????++=~~::,,,,~:~::~~:,,,,,,,~=~~=~==
            +=~~::I?++~:,,~+?I??++?~=+??IIIII?I??=~::,,,.,,,.,.,::,...,~==+??++~=,::,:~~=++++I++===~~~~~?+===~~~::~~=+?I?++==~~~===+++++===~~::::::~~~~~~~:~~,,,,..~~=~~=~~+
            +=~~:~I?+?~,,:=+?~~~:,,,:,,,:??II??+=::,:::~~~~~~~,.,::,..,:~+=+???~=:::,::==++=?I+=+==~~~~:?++==~:::,::~??===:,::::~~~==+++==~:::::::~~~~~~~~~:~:,,,,:,===~=~~=
            ==~~::I???=:,:++~~=+?+?+==~:~=?II??+=:~:::~++++~~~::,::,,.,~~==???+==~,:,::=++++???=++=~~~~~?+===~:::~:::?=+??+=~~~~~~~~~+?++=~:::,::~~~=~~::~~~~~,,,,~~+==~==~~
            ==~~~:??+=~~::+~~++??II?+==++??II??+~::::~+++==~~::::,::..,:~==+?++===::,::=+=+=???++==~~~~:?====~::::,,:?+?++++~==~:::~~+II?+~::,:::,..,,::,:~~~~,,.,,++==~===~
            +=~~::~??=~~,~=+++?+???+=~:~~+?III?=::,::,.:,,,,,::~::::,.,:~==+??+?=~:::,:~=+++???+===~~~::?====~~::~,::??+==+=?=~:::::~=I7I?=:~:,:~....,,,:::~~~,,,,,++~=~==~~
            +=~~:::+?+==,==+++++,,,,,~,:+???II?=:::,:=~+=~:,,,:~~:::,..,~==+??++==:,,,:~=+++I?++~~~:~~~:?====~~::::::+?++=~,,,.,~~:=+?I7??=~~~:~~:~~~~~~~~~=~~,,,,,++~=~~==~
            +=~~:::?+?~=,=+??+,:~:=====+I???II+=:::~=++++===~~~~=~~:,,,,:~==+?+=~~:::,:~~=++I??+=~~:~~:~?====~::::::~??+=+++====~~=?I?III?=~~~~~~~~::~======~~~,,,:++==~~=~=
            ==~~:::???==:+??????++=+=~=+??I?II?=~:~=++?+++========~:,,.::~==+?++~=~::,,:~=++I?++=~~:~~~+?+==~~::~::::??III?++=~~=+I???III?+~~~~==++++=======~~~,:::?+~=~~=~~
            ==~~:::I=++~,+?IIII?+=+???II?I?III?+=~~~=++++?????++=~~:,..::~==+?++==~::,,:==++I?+++~~:~~~I?===~~::~:+::?IIIIIII??IIII???III?+=~~==+++?????++===~~,~~:?+~=~~=~~
            =+~~~::I?+?~,+?IIIIIIIIIIIIIIIIII???+=:~=+++??????++=~~::,,::~==+++++=~::,,,=+++??++==~~~~:I?=~=~~:::~+::??III77IIIIIIII??I7I?+==~~~=++??????++==~~:~~~??~==~=~~
            =+=~::,I??+=:+?IIIIIIIIIIIII?IIIII??+=~~~=+???????++=~~:,:,:,:=~=+?++~=::,,:~==+?+==~~~~~~~I++==~~::::+=:+?III777IIIII??IIII??+==~~~~~=+????+++=~~~:~~~?+~==~===
            ==~~~::I=++=~+IIIIIIIIIIIII?I?++??+=~:~:~:=+??????+=~~::,:::,~~=++?++~=::,,:~+++?==+~~~:~~:I?+==::~:::??=+?III777III??II?????+==~~~~~:~=+++++===~~~~~=~?++==~===
            ?+=~~::?+?+=+=?IIIIIIIIII??I?==++==~,.::~:~=++??+++=~:::::~,,:~~=+?++~~~:,,,:==+?+=+~~~~~:~?++==::~:~~+???IIIIIII??==+?+=====~~~::,::~~~~=======~~~=~~=?++==~~==
            ?==~~::+?++~+????IIIII?+??I?~:,:=~~,,:::::~~==++++=~~::::::,::~~+=?+=~+~,,,,:~++I+=+~=~~~:~?+==~::~:::??+I?III??++=~+?+~,::::::,::::~~~::::~~~~~~~~==~+?+===~~=~
            ?==~~:,~?=+~?I+???I??+++?????====~:::::::::~~====~=~~:::~::::,:=~=??+=~~:,,,,~=+?+=+~~~~~::??=~=::::::??+I????++=~~~=???=~:::::::::::~~:::,:::~~~~~====?++~=~~=~
            +~=~~:::??+=???????++==??IIII??++=~~~::::::::~~===~~:::::~:::,:=~=+?+++~,,,,,~=+?==+~~~~~:~??+==::::~:??++?+++==~:~~+++++==::~~::::,:::::,,:~~~~~~~:=~+??+~=~~=~
            ?==~~::,?+=~?I?++++++==+?II????+~===~~~~~::::~~~~=~=~:::~~:::::~~==?+=~~:,,,,~==+=~~~~:~~:~?++==~::,::??+???++==~~===+====+++==~=::::::::::::=~~~~~~~~~??+==~~~~
            +==~~:::??==+II?++=+==+????I?I????++=~~:::::::::~===~::::::::::~===?==~~~,,,,:==?+~=~~:~~:+??==~~:::::?+~+~?++++~:::~~~~~::~~~:::,,,,:,.,:::~=~~~~~~~~~??+~==~~~
            +?+~~:::+??~=?I?+++++============~~~::,,,:,,.,,~=+=~::::=~~::,:~==++++=:~,,,,::+++=~~~:~~:??+==~:::::~?+===?????=~~~:.,~=====~=====~=:.:~~~~~=~~~~~~~~~??+~==~=~
            +===~~::?=+===~~+++?+=~~,,,:===~=~:==:=~=::,,:~~=+~~~:::~~::,,,:=~+?+++=~,,,,,:=?+~=~~:~~:I?==~~~:::~+??+==+????+=+??I==~,.++=+==,,,:::~~~~~~~~~~:~~~~~+??+~=~~~
            +?==~~:,I?++=~:~++++?=+??+.,+:?+?+=+=~~,,.,::~~~~=~:~::+~~~:::,~=~=++++~~,,,,,~=?+=+~~:~~~I+==~~~::::+?~++++++??++??I??+++++==++=~~~:~~~~~~~~~~~~,::~~~+?++==~~=
            ?+=~~~:,?=++=:~::+++???????++,,,,,,,,,,::::::~~~~~::~::=~:~::,::~~=++++~~:,,,,~=?++=~~:~~:I?===~:::::+?+~+=?I+?+++??????+++=++++==::~~~~~~~~~~~:~:::~~~+?+~==~~~
            ??=~~~::+=?+=:~::=++????II??++????+++===~:::~~~=~~:~::~+~~=::,,:~====::,,:,,..,,?+=~:~:~~:??==~~~::::+?+=+=+??++??????+?+++=~~~~~~~~~~~~~~~~~~~~~~~:~=~=?+=~=~~~
            ?++=~~:::?++~:+:~~=+?????I???+++++====~~::::~~~~~~::::,,,,:,:,,,....,,,,,...,,,,?==~~~:~~~?+=~=~:::~~+?++=++???=+??????++==~~~~~~::~:~~~~~~~~:~~~:~::~=+??+~=~~~
            ?+==~~::,+~+~~~::::++???I?????+==~~~~~~~~~~~~==~~::::,,.........,,,,,......,,,,,?+=~~~~~~:??==~~:::::+?+~=+?=+??++???I??++==~~~~~~~~~~~=~~~~~:~~~:~::~==??+~=~~=
            ~++=~::::+?+~~~==:::++??IIII??+=~~~~~~~~~~~~~=~~~::::,,,,,,......,,,,,,......,.,++=~~::~~:??~~~::::::+?+~~=+++???=+??IIII????++========~~~:::~~~~~:~:~~=??+~~=~~
            ~+==+=::::+===+~~:~=~=+?IIIII????+++++=====~~~~~:::::,,,,,,,,,...........,,..,,.==~~~::~~:??+~~,::,::???=~=+?+????==??IIIIIII????++++=~~~::::~~~~~::~~~=??+===~=
            ~=~,,,~~~~====~~~~~~~?=??IIIIIII????+++++===~~:::,,::,,,..............,.,,,,,,,,~==:~:::~=+?=~~::,,::?++====??+???=~=????????????++==~~~::::~~~~~~:::~~=??++==~~
            ,,:,:====:::::::,~~~~??=+?IIIII?I????++++==~:::,,:::::.....,,,.........,,,,,...,=~~:~::~:?+=~~~::,:::?+~+=~+=?+????+~~=?+++++++======:::,::~~~~~~~,::~=:??++~=~~
            ::::,=======::,,:::::???=+??III????++++==~~::,,:::::::....,,,,,,,,,,,,,,,,,,,.,,=~~~~::::+++=~~::,:::?=+==~++?+?????+::~=======~~~~:::,,:::~~~~~~~~::~~~+?+=:=~~
            ::::::,,::::,,,::~~~~????==+????++=+++=~~::,,::::::::::...,.,,,,................~~~~~::::?+==~~::,:::??+===++?,??????+=~::::::::::,,,,,::~~~~~~~~~~::~~~+??+~~~~
            ,~~=~~~~~~~:::::,:::~?????=~++=======~~:::,,::::::::::::...,.,,..........,,.,,..=~~:~::::?+=~~~::,::~?~+:..,,,???????++++~:,,,,,,,,,::::~~~~~~~~~~~~:.==+??+~~~~
            ==~::::~~~~~~~~=~~~~=??II??+=~~~:::::::,,::::::~~::::::::.................,,,...=~~~~,:::?+~~~~::,::=?=..,,,,.????????++++~~~::::::::::~~~~~~~~~~~~~~....??+~~~~
            :::::,,~~=~,::,,,,,:????I????+=~~::::::::::::~~~~~:::::~::......................=::::,:::+=~~~~,,,,,,,...,,,,.????????++++===~~~~~~:~~~~~~~~~~~~~~~~~.........~~
            ,,=~~~~~~~~::::,,,,+?????I????++=~~~~~~~~~~~~~~~~~~::::~~:.............,,,,,,,,,:::,~::::+=~~,,,,,,,,....,,.,.????????++++++==~~~~~~~~~~~~~=~~~~~~~~:...........
            ,,::::,,,,,::::::::II????II????++==~~~~~~~~~~~~~~~:::~:~~.................,,,,,.,,,.,,,::=,,,,,,,.,,....,,,.,.:??????++++++++===~~~~~~~~~~~~~~~~~~~~............
            :::~~~~~~~~:::::.=?II?????II????++==~~~~~~~~~~~~~~::::::,.......................,,...,,,,,,,,,,..,,,.....,..,,.+?????+++++++++===~~~~~~~~~~~~~~~~~~.............
            ,~~~~~~~~~:~~::,,?III????I???????+++==~:~~~~~~~~~~:::::,.....................,,,..,,,.,,..,,,,.,,,.......,,,...,+?????++++++=====~~~~~~~~~~~~~~~~~..............
            ~~~~~:::::::,,,,,,?I?????????????++++=========~~~~::::..........................,,,,,......,,.,,,........,,,.,..,+???+?+++++=====~~~~~=====~~~~~:...............
            ~~~=~~==,,,,,,,,,,,+??????????????++++++======~~~:::,..........................,.,,.....,...,,.,,.........,,,.....++?+++++++=============~~~~~~.................
                                                                      )" << endl;
    cout << endl;
    cout << endl;
    cout << "To read all the fight scene and up, scroll until you see STOP SCROLLING. " << endl;
    cout << endl;
    cout << endl;
    cout << "CREDITS: " << endl;
    cout << "Thanks for playing our game " << playerName << "! We had a lot of fun making it! " << endl;
    cout << "We\'d like to thank the various people, wherever they are, who have posted "
            "the helpful resources we have used to help make this game. " << endl;
    cout << endl;
    cout << endl;
    cout << "This was a game by Jared Belmont and Braeden Butler " << endl;
    cout << endl;
    cout << endl;
}

int main(){
    pair<int, string> inputs = introFunction();                   //call of the intro function and the unpacking of variabes necessary to other functions
    int Class = inputs.first;
    string playerName = inputs.second;

    pair<bool, bool> inputs2 = floorOneFunction(Class, playerName);      //call of the floor 1 function and the unpacking of necessary variables
    bool foundWeapon = inputs2.first;
    bool hasLockpicks = inputs2.second;

    bool oldMansWisdom = floorTwoFunction(Class, playerName, foundWeapon, hasLockpicks);  //call of the floor 2 function and the unpacking of variables

    pair<bool, bool> inputs3 = bossRoom(Class, playerName, foundWeapon, hasLockpicks, oldMansWisdom);    //call of boss room function and the unpacking of variables
    bool savedPrincess = inputs3.first;
    bool killedCK = inputs3.second;

    finalMessage(playerName, savedPrincess, killedCK);    //call of the final message and credits

    return 0;
}
