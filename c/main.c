#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef char *string[28];

// struct storing the data required for each sentence
typedef struct
{
	string content;
	int score;
} sequence;

// It is the vector which stores the symbols to create sentences
char *alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
					"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};

// It is the target phrase
char *text[] = {"M", "E", "T", "H", "I", "N", "K", "S", " ", "I",
				"T", " ", "I", "S", " ", "L", "I", "K", "E", " ", "A", " ", "W", "E", "A",
				"S", "E", "L"};

// function which role is to create an initial random sentence
sequence createSequence()
{
	int random_number;
	sequence tmp_sequence;

	for (int i = 0; i < 28; i++)
	{
		random_number = rand() % 28;
		tmp_sequence.content[i] = alphabet[random_number];
	}
	return tmp_sequence;
};

// generator function of sequence's copies
sequence *generate_copies(sequence seqce)
{
	static sequence copies[100];

	for (int i = 0; i < 100; i++)
	{
		for (int e = 0; e < 28; e++)
			copies[i].content[e] = seqce.content[e];
	}
	return copies;
}

// function which use is to return, based on certain percentual rate, the occurence or not of an event*/
bool sampling(int prob)
{
	int sample = rand() % 100;

	if (sample > prob - 1)
		return false;
	else
		return true;
}

// mutation function at a rate of five percent*/
sequence *get_copies(sequence seq_copies[], int mutRate)
{
	for (int i = 0; i < 100; i++)
	{
		for (int e = 0; e < 28; e++)
		{
			if (sampling(mutRate) == true)
			{
				int randNum = rand() % 42;
				seq_copies[i].content[e] = alphabet[randNum];
			}
		}
	}
	return seq_copies;
}

// function which compares each sequence with the target phrase and returns the score*/
sequence get_score(sequence mut_copies[])
{
	sequence seq = mut_copies[0];
	for (int i = 0; i < 100; i++)
	{
		mut_copies[i].score = 0;
		for (int e = 0; e < 28; e++)
		{
			if (mut_copies[i].content[e] == text[e])
				mut_copies[i].score++;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (mut_copies[i].score > seq.score)
			seq = mut_copies[i];
	}
	return seq;
}

int main(void)
{

	sequence current_text = createSequence();
	current_text.score = 0;
	int counter = 0;
	int score = 0;
	sequence auxText;
	srand((unsigned int)time(NULL));

	// This iteration will occur until a sentence equal to the target one come up
	while (score < 28)
	{
		auxText = get_score(get_copies(generate_copies(current_text), 5));
		if (auxText.score > current_text.score)
			current_text = auxText;
		printf("GENERATION %d (SCORE %d): ", counter, current_text.score);
		counter++;
		for (int i = 0; i < 28; i++)
			printf("%s", current_text.content[i]);
		printf("\n");
		score = current_text.score;
	}

	return 0;
}
