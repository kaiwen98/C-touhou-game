#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "action.h"
#include "thirst.h"
#include "hunger.h"

bool action();

bool parseAndExecute(char *input)
{
  char *verb = strtok(input, " \n");
  char *noun = strtok(NULL, " \n");
  if (verb != NULL)
  {
    if (strcmp(verb, "quit") == 0)
    {
      return false;
    }
    else if (strcmp(verb, "ask") == 0)
    {
      bool result = executeAsk(noun);
      // you die lol
      if (result == false)
      {
        return result;
      }
      action();
    }
    else if (strcmp(verb, "intro") == 0)
    {
      printf("\n\nIntro");
      printf("\n\nYou are a proud asexual man/woman. Which is why living in Gensokyo is almost impossible");
      printf("\n\nSome of the inhabitants don't get it when you say no. They are Youkai, they aren't used to being rejected.");
      printf("\n\nBut you didn't expect things to turn out like this...");
      printf("\n\nYou don't know what the Youkai did to you, but your head hurts. You don't remember your name...");
      printf("\n\nSomething is covering your eyes. Even if you forced them open, an endless void of darkness greeted you. Your hands were tied behind your back, the restraints are biting into your skin. You're sitting on something and based off your posture, you guess it's a chair. You hear footsteps...\n");
      printf("\n\nMysterious girl: \"Ah, you're finally awake.\"");
      printf("\n\nThere was one problem, you don't recognize the woman's voice.");
      printf("\n\nMysterious girl: \"I have told you many times, but it seems you wouldn't listen, making me resort to this. This is all your fault, you understand don't you?\"\n\n");
      printf("\n\nYou struggled to shake your head. You couldn't shake your head, something kept it in place, and your mouth was gagged.\n");
      printf("\n\nMysterious girl: \"Ara ara, I'm so so sorry...\"");
      printf("\n\nThe damn thing was removed from your mouth. You could speak, but what should you say?");
      printf("\n\nAs your stomach growled and your throat was parched with thirst, you realized your starving, and that you're thirsty");
      printf("\n\nYou didn't feel like chit chatting. Sating your current needs was the goal.");
      printf("\n\nYou only had the energy to utter a single word at a time. As your mouth hung open, before closing");
      printf("\n\nMemories from your time at Ms Keine, flooded your mind, when asking questions one should use 5W1H. You don't know why they appeared, but they seemed useful.");
      printf("\n\nAnd considering that you're blindfolded, you guess that whoever they are, really wants you to guess their identity.");
      printf("\n\nSo what to ask?");
      printf("\n\nfood or water?");
      printf("\n\nYour mind were only swarmed with thoughts on them.");
      printf("\n");
    }
    else
    {
      printf("I don't know how to '%s'.\n", verb);
      action();
    }
  }
  return true;
}

// Return false, die.
bool action()
{
  increaseHunger();
  increaseThirst();
  if (checkHungerDead() || checkThirstDead())
  {
    if (checkHungerDead())
    {
      printf("\n\nDo you know what happens to during starvation? Your cells cannibalize themselves. So your body eats itself. You have been eaten, none other by yourself. Blame your horrible caretaker. Or is it your fault for not knowing to speak up?");
      printf("\n\nGame Over");
      printf("\n\nPress any key and enter to exit, all the best for your next try, you damned soul.");
      getchar();
      return false;
    }
    else if (checkThirstDead())
    {
      printf("\n\nDo you know what happens when you die from thirst? Your kidney fails. And when your kidney fails, good things don't happen. Blame your horrible caretaker. Or is it your fault for not knowing to speak up?");
      printf("\n\nGame Over");
      printf("\n\nPress any key and enter to exit, all the best for your next try, you damned soul.");
      getchar();
      return false;
    }
  }
  printf("\n\n");
  printHunger();
  printf("\n\n");
  printThirst();
  printf("\n\n");
}