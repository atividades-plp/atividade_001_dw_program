#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef char *charSq[28];

//struct storing the data required for each sentence
typedef struct
{

charSq content;
int score;

} sequence;

//It is the vector which stores the symbols to create sentences
char *symbols[] = {" ", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"
"M", "N", "O", "P", "Q", "R", "S", 
"T", "U","V", "W","X", "Y", "Z"};

//It is the target phrase
char *targPhrase[] = {"M", "E", "T", "H", "I", "N", "K", "S", " ", "I",
"T", " ", "I", "S", " ", "L", "I", "K", "E", " ", "A", " ", "W", "E", "A",
"S", "E", "L"
};

//function which role is to create an initial random sentence
sequence createSequence()
{
  int randNum;
  sequence seq;

  for (int i = 0; i < 28; i++)
    {
      randNum = rand() % 28;
      seq.content[i] = symbols[randNum];
    }
  return seq;
};


//generator function of sequence's copies
sequence * genCopies(sequence seqce)
{
  static sequence seqCopies[100];
  
  for (int i = 0; i < 100; i++)
    {
      for (int e = 0; e < 28; e++)
        {
          seqCopies[i].content[e] = seqce.content[e];
        }
    }
  return seqCopies;
}

//function which use is to return, based on certain percentual rate, the occurence or not of an event*/
bool sampling(int prob)
{
  int sample = rand() % 100;

  if (sample > prob - 1)
    return false;
  else
    return true;
}

//mutation function at a rate of five percent*/
sequence * mutCopies(sequence seq_copies[], int mutRate)
{
  for (int i = 0; i < 100; i++)
    {
      for (int e = 0; e < 28; e++)
        {
          if (sampling(mutRate) == true)
          {
            int randNum = rand() % 42;
            seq_copies[i].content[e] = symbols[randNum];
          }
        }
    }
  return seq_copies;
}

//function which compares each sequence with the target phrase and returns the score*/
sequence scoring(sequence mut_copies[])
{
  sequence seq = mut_copies[0];
  for (int i = 0; i < 100; i++)
    {
      mut_copies[i].score = 0;
      for (int e = 0; e < 28; e++)
        {
          if (mut_copies[i].content[e] == targPhrase[e])
          {
            mut_copies[i].score++;
          }
          }
        }
  for (int i = 0; i < 100; i++)
    {
      if (mut_copies[i].score > seq.score)
        seq = mut_copies[i];
    }
  return seq;
    }

int main(void) {
  
  sequence seqnc = createSequence();
  seqnc.score = 0;
  int counter = 0;
  int score = 0;
  sequence aux_seqnc;
  srand((unsigned int) time(NULL));

  //This iteration will occur until a sentence equal to the target one come up
  while (score < 28)
    {
      aux_seqnc = scoring(mutCopies(genCopies(seqnc), 5));
      if (aux_seqnc.score > seqnc.score)
        seqnc = aux_seqnc;
      counter++;
      printf("GENERATION %d (SCORE %d): ", counter, seqnc.score);
      for (int i = 0; i < 28; i++)
    {
      printf("%s", seqnc.content[i]);
    }
      printf("\n\n");
      score = seqnc.score;
      }
  
  return 0;
    }
