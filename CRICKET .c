#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct Player 
{
	
    int JerseyNumber;
    char PlayerName[100]; 
    int Runs;
    int Wickets;
    int MatchesPlayed;
};

void AddPlayer(struct Player** players, int* numPlayers, int size);
void RemovePlayer(struct Player** players, int* numPlayers);
void SearchPlayer(struct Player** players, int numPlayers);
void UpdatePlayerData(struct Player** players, int numPlayers);
void DisplayTop3Players(struct Player** players, int numPlayers);
void DisplayAllPlayers(struct Player** players, int numPlayers);
void AlradyStore(struct Player** players, int* numPlayers);
void Massenger(struct Player** players, int numPlayers);

int main()
 {
 	system("color 9F");
    int size = 100;
    struct Player* players = (struct Player*)malloc(size * sizeof(struct Player));
    int numPlayers = 0;
    int choice;

   AlradyStore(&players, &numPlayers);

    do {
        printf("\n\t\t\t**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("\t\t\t* Player Management System Menu *\n");
        printf("\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>**\n\n");
        printf("\t\t\t1. Store Player\n");
        printf("\t\t\t2. Display All Players\n");
        printf("\t\t\t3. Remove Player\n");
        printf("\t\t\t4. Search Player\n");
        printf("\t\t\t5. Update Player Data\n");
        printf("\t\t\t6. Display Top 3 Players\n");
        printf("\t\t\t7. Messenger for Players\n");
        printf("\t\t\t8. Exit\n\n");
        printf("\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddPlayer(&players, &numPlayers, size);
                break;
            case 2:
                DisplayAllPlayers(&players, numPlayers);
                break;
            case 3:
                RemovePlayer(&players, &numPlayers);
                break;
            case 4:
                SearchPlayer(&players, numPlayers);
                break;
            case 5:
                UpdatePlayerData(&players, numPlayers);
                break;
            case 6:
                DisplayTop3Players(&players, numPlayers);
                break;
            case 7:
                Massenger(&players, numPlayers);
                break;
            case 8:
                printf("\t\t\tTHANKS FOR VISITING.\n");
                break;
            default:
                printf("\t\t\tInvalid choice. Please try again.\n");
        }
    } while (choice != 8);

    free(players);
    return 0;
}

void AlradyStore(struct Player** players, int* numPlayers) {
    
    
    (*players)[0].JerseyNumber = 12;
    strcpy((*players)[0].PlayerName, "sachin");
    (*players)[0].MatchesPlayed = 100;
    (*players)[0].Runs = 5000;
    (*players)[0].Wickets = 10;

    (*players)[1].JerseyNumber = 7;
    strcpy((*players)[1].PlayerName, "dhoni");
    (*players)[1].MatchesPlayed = 90;
    (*players)[1].Runs = 2000;
    (*players)[1].Wickets = 9;

    (*players)[2].JerseyNumber = 18;
    strcpy((*players)[2].PlayerName, "virat");
    (*players)[2].MatchesPlayed = 80;
    (*players)[2].Runs = 4000;
    (*players)[2].Wickets = 7;

    (*players)[3].JerseyNumber = 13;
    strcpy((*players)[3].PlayerName, "jadeja");
    (*players)[3].MatchesPlayed = 70;
    (*players)[3].Runs = 1756;
    (*players)[3].Wickets = 12;

    (*players)[4].JerseyNumber = 14;
    strcpy((*players)[4].PlayerName, "gambir");
    (*players)[4].MatchesPlayed = 60;
    (*players)[4].Runs = 2520;
    (*players)[4].Wickets = 4;

    (*players)[5].JerseyNumber = 45;
    strcpy((*players)[5].PlayerName, "rohit");
    (*players)[5].MatchesPlayed = 1926;
    (*players)[5].Runs = 18654;
    (*players)[5].Wickets = 967;
    
    *numPlayers =6;
}

void DisplayAllPlayers(struct Player** players, int numPlayers) {
    if (numPlayers == 0) {
        printf("\t\t\tPlayer database is empty. No players to display.\n");
        return;
    }

    printf("\n");
    printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
    printf("\t\t\t| Jersey Number |      Player Name    |    Runs    | Wickets | Matches Played  |\n");
    printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
    
    for (int i = 0; i < numPlayers; i++)
	 {
        printf("\t\t\t| %-13d | %-19s | %-10d | %-7d | %-15d |\n",
               (*players)[i].JerseyNumber, (*players)[i].PlayerName, (*players)[i].Runs, (*players)[i].Wickets, (*players)[i].MatchesPlayed);
    }
    
    printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
}

void AddPlayer(struct Player** players, int* numPlayers, int size) {
    if (*numPlayers >= size) {
        printf("\t\t\tPlayer database is full. Cannot add more players.\n");
        return; 
    }

    struct Player newPlayer;
    printf("\t\t\tEnter Jersey Number: ");
    scanf("%d", &newPlayer.JerseyNumber);
    printf("\t\t\tEnter Player Name: ");
    scanf("%s", newPlayer.PlayerName);
    printf("\t\t\tEnter Runs: ");
    scanf("%d", &newPlayer.Runs);
    printf("\t\t\tEnter Wickets: ");
    scanf("%d", &newPlayer.Wickets);
    printf("\t\t\tEnter Matches Played: ");
    scanf("%d", &newPlayer.MatchesPlayed); 

    (*players)[*numPlayers] = newPlayer;
    (*numPlayers)++;
    printf("\t\t\tPlayer added successfully.\n");
}

void RemovePlayer(struct Player** players, int* numPlayers)
 {
    if (*numPlayers == 0)
	 {
        printf("\t\t\tPlayer database is empty. Cannot remove a player.\n");
        return;
    }

    int choice;
    printf("\t\t\tHow would you like to remove the player?\n");
    printf("\t\t\t1. Remove by Jersey Number\n");
    printf("\t\t\t2. Remove by Player Name\n");
    printf("\t\t\tEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
	 {
        int JerseyToRemove;
        printf("\t\t\tEnter the Jersey Number of the player you want to remove: ");
        scanf("%d", &JerseyToRemove);

        int i, j;
        int found = 0;
        for (i = 0; i < *numPlayers; i++) 
		{
            if ((*players)[i].JerseyNumber==JerseyToRemove) 
			{
                for (j = i; j < *numPlayers - 1; j++) 
				{
                    (*players)[j] = (*players)[j+1];//b ecous remove the player the jth value or the old members are heare j+1
                }
                (*numPlayers)--;// number -- becous it is an number zero aaraha tha na oh oplayer ka array me ++
                printf("\t\t\tPlayer with Jersey Number %d is removed.\n", JerseyToRemove);
                found = 1;
                break;
            }
        }
        if (!found)
		 {
            printf("\t\t\tPlayer with Jersey Number %d not found.\n", JerseyToRemove);
        }
    } else if (choice == 2)
	 {
        char NameToRemove[100];
        printf("\t\t\tEnter the name of the player you want to remove: ");
        scanf("%s", NameToRemove);
        int i, j;
        int found = 0;
        for (i = 0; i < *numPlayers; i++)
		 {
            if (strcmp((*players)[i].PlayerName, NameToRemove) == 0)
			 {
                for (j = i; j < *numPlayers - 1; j++)
				 {
                    (*players)[j] = (*players)[j+1];//same heare 
                }
                (*numPlayers)--;
                printf("\t\t\tPlayer with Name '%s' is removed.\n", NameToRemove);
                found = 1;
                break;
            }
        }
        if (!found)
		 {
            printf("\t\t\tPlayer with Name '%s' not found.\n", NameToRemove);
        }
    } else {
        printf("\t\t\tInvalid choice.\n");
    }
}
void SearchPlayer(struct Player** players, int numPlayers)
 {
    if (numPlayers == 0) {
        printf("\t\t\tPlayer database is empty. Cannot search for a player.\n");
        return;
    }

    int choice;
    printf("\t\t\tHow would you like to search the player?\n");
    printf("\t\t\t1. Search by Jersey Number\n");
    printf("\t\t\t2. Search by Player Name\n");
    printf("\t\t\tEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
	 {
        int SearchJersey;
        printf("\t\t\tEnter the Jersey Number of the player you want to search: ");
        scanf("%d", &SearchJersey);

        int i, found = 0;
        for (i = 0; i < numPlayers; i++)
		 {
            if ((*players)[i].JerseyNumber == SearchJersey) 
			{
                printf("\t\t\tPlayer found:\n");
                printf("\t\t\tJersey Number: %d Player Name: %s Runs: %d Wickets: %d Matches Played: %d\n",
                       (*players)[i].JerseyNumber, (*players)[i].PlayerName, (*players)[i].Runs, (*players)[i].Wickets, (*players)[i].MatchesPlayed);
                found = 1;
                break;
            }
        }
        if (!found)
		 {
            printf("\t\t\tPlayer with Jersey Number %d not found.\n", SearchJersey);
        }
    } else if (choice == 2)
	 {
        char SearchName[100];
        printf("\t\t\tEnter the name of the player you want to search: ");
        scanf("%s", SearchName);

        int i, found = 0;
        for (i = 0; i < numPlayers; i++)
		 {
            if (strcmp((*players)[i].PlayerName, SearchName) == 0) 
			{
                printf("\t\t\tPlayer found:\n");
                printf("\t\t\tJersey Number: %d Player Name: %s Runs: %d Wickets: %d Matches Played: %d\n",
                       (*players)[i].JerseyNumber, (*players)[i].PlayerName, (*players)[i].Runs, (*players)[i].Wickets, (*players)[i].MatchesPlayed);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\t\t\tPlayer with name '%s' not found.\n", SearchName);
        }
    } else {
        printf("\t\t\tInvalid choice.\n");
    }
}

void UpdatePlayerData(struct Player** players, int numPlayers)
 {
    if (numPlayers == 0) {
        printf("\t\t\tPlayer database is empty. Cannot update player data.\n");
        return;
    }

    int choice;
    printf("\t\t\tHow would you like to update the player's data?\n");
    printf("\t\t\t1. Update by Jersey Number\n");
    printf("\t\t\t2. Update by Player Name\n");
    printf("\t\t\tEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) 
	{
        int UpdateJersey;
        printf("\t\t\tEnter the Jersey Number of the player you want to update: ");
        scanf("%d", &UpdateJersey);

        int i, found = 0;
        for (i = 0; i < numPlayers; i++)
		 {
            if ((*players)[i].JerseyNumber == UpdateJersey) 
			{
                printf("\t\t\tPlayer found:\n");
                printf("\t\t\tJersey Number: %d  Player Name: %s  Runs: %d Wickets: %d Matches Played: %d\n",
                       (*players)[i].JerseyNumber, (*players)[i].PlayerName, (*players)[i].Runs, (*players)[i].Wickets, (*players)[i].MatchesPlayed);
                
                printf("\t\t\tEnter new Runs: ");
                scanf("%d", &(*players)[i].Runs);
                printf("\t\t\tEnter new Wickets: ");
                scanf("%d",&(*players)[i].Wickets);
                printf("\t\t\tEnter new Matches Played: ");
                scanf("%d", &(*players)[i].MatchesPlayed);

                printf("\t\t\tPlayer data updated successfully.\n");
                found = 1;
                break;
            }
        }
        if (!found)
		 {
            printf("\t\t\tPlayer with Jersey Number %d not found.\n", UpdateJersey);
        }
    } else if (choice == 2)
	 {
        char UpdateName[100];
        printf("\t\t\tEnter the name of the player you want to update: ");
        scanf("%s", UpdateName);

        int i, found = 0;
        for (i = 0; i < numPlayers; i++)
		 {
            if (strcmp((*players)[i].PlayerName, UpdateName) == 0)
			 {
                printf("\t\t\tPlayer found:\n");
                printf("\t\t\tJersey Number: %d  Player Name: %s  Runs: %d Wickets: %d Matches Played: %d\n",
                       (*players)[i].JerseyNumber, (*players)[i].PlayerName, (*players)[i].Runs, (*players)[i].Wickets, (*players)[i].MatchesPlayed);
                
                printf("\t\t\tEnter new Runs: ");
                scanf("%d", &(*players)[i].Runs);
                printf("\t\t\tEnter new Wickets: ");
                scanf("%d", &(*players)[i].Wickets);
                printf("\t\t\tEnter new Matches Played: ");
                scanf("%d", &(*players)[i].MatchesPlayed);

                printf("\t\t\tPlayer data updated successfully.\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\t\t\tPlayer with name '%s' not found.\n", UpdateName);
        }
    } else {
        printf("\t\t\tInvalid choice.\n");
    }
}

void DisplayTop3Players(struct Player** players, int numPlayers) 
{
    if (numPlayers == 0)
	 {
        printf("\t\t\tPlayer database is empty. Cannot display top players.\n");
        return;
    }

   struct Player temp;
    for (int i = 0; i < numPlayers-1 ; i++)
	 {
        for (int j = 0; j < numPlayers -1- i; j++)
		 {
            if ((*players)[j].Runs < (*players)[j + 1].Runs) 
			{
                 temp = (*players)[j];
                (*players)[j] = (*players)[j + 1];
                (*players)[j + 1] = temp;
            }
        }
    }

    printf("\n");
    printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
    printf("\t\t\t| Jersey Number |      Player Name    |    Runs    | Wickets | Matches Played |\n");
    printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
    
    for (int i = 0; i < 3 && i < numPlayers; i++)
	 {
        printf("\t\t\t| %-13d | %-19s | %-10d | %-7d | %-15d |\n",
               (*players)[i].JerseyNumber, (*players)[i].PlayerName, (*players)[i].Runs, (*players)[i].Wickets, (*players)[i].MatchesPlayed);
    }
    
    printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
}

void Massenger(struct Player** players, int numPlayers)
 {
    if (numPlayers == 0) {
        printf("\t\t\tPlayer database is empty. Cannot send a message.\n");
        return;
    }

    int choice;
    printf("\t\t\tHow would you like to send the message?\n");
    printf("\t\t\t1. Send by Jersey Number\n");
    printf("\t\t\t2. Send by Player Name\n");
    printf("\t\t\tEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
	 {
        int SearchJersey;
        printf("\t\t\tEnter the Jersey Number of the player you want to send a message to: ");
        scanf("%d", &SearchJersey);

        int i, found = 0;
        for (i = 0; i < numPlayers; i++) 
		{
            if ((*players)[i].JerseyNumber == SearchJersey)
			 {
                printf("\t\t\tEnter your message for %s: ", (*players)[i].PlayerName);
                char message[500];
                scanf(" %[^\n]s", message); // This scanf reads until newline
                printf("\t\t\tMessage sent to %s: %s\n", (*players)[i].PlayerName, message);
                found = 1;
                printf("\n");
			    printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
			    printf("\t\t\t| Jersey Number |      Player Name    |    Runs    | Wickets | Matches Played |\n");
			    printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
                printf("\t\t\t| %-13d | %-19s | %-10d | %-7d | %-15d |\n",
                (*players)[i].JerseyNumber, (*players)[i].PlayerName, (*players)[i].Runs, (*players)[i].Wickets, (*players)[i].MatchesPlayed);
                printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
                 printf("\t\t\tMessage sent to %s: %s\n", (*players)[i].PlayerName, message);      
                break;
            }
               
            
        }
        if (!found) {
            printf("\t\t\tPlayer with Jersey Number %d not found.\n", SearchJersey);
        }
    } else if (choice == 2)
	 {
        char SearchName[100];
        printf("\t\t\tEnter the name of the player you want to send a message to: ");
        scanf("%s", SearchName);

        int i, found = 0;
        for (i = 0; i < numPlayers; i++)
		 {
            if (strcmp((*players)[i].PlayerName, SearchName) == 0)
			 {
                printf("\t\t\tEnter your message for %s: ", (*players)[i].PlayerName);
                char message[500];
                scanf(" %[^\n]s", message); // This scanf reads until newline
                printf("\t\t\tMessage sent to %s: %s\n", (*players)[i].PlayerName, message);
                found = 1;
                printf("\n");
			    printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
			    printf("\t\t\t| Jersey Number |      Player Name    |    Runs    | Wickets | Matches Played |\n");
			    printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
                printf("\t\t\t| %-13d | %-19s | %-10d | %-7d | %-15d |\n",
                (*players)[i].JerseyNumber, (*players)[i].PlayerName, (*players)[i].Runs, (*players)[i].Wickets, (*players)[i].MatchesPlayed);
                printf("\t\t\t+---------------+---------------------+------------+---------+-----------------+\n");
                 printf("\t\t\tMessage sent to %s: %s\n", (*players)[i].PlayerName, message);     
                break;
            }
        }
        if (!found) 
		{
            printf("\t\t\tPlayer with name '%s' not found.\n", SearchName);
        }
    } else {
        printf("\t\t\tInvalid choice.\n");
    }
}
