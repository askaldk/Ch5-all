#include<stdio.h>
#include<stdlib.h>
#define issues 5
#define ratings 10

void recordResponse(int i, int response);
void highestRatings();
void lowestRatings();
float averageRating(int issue);
void displayResults();

int responses[issues][ratings];
const char *topics[issues] = { "Global Warming","The Economy","War",
"Health Care","Education" };

int main()
{
	int response;
	int i;
	
	do {
		printf("Please rate the following topics on a scale from 1 - 10"
			"\n 1 = least important, 10 = most important\n");
		for (i = 0; i < issues; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("? ");
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordResponse(i, response);
		}

		printf("Enter 1 to stop. Enter 0 to rate the issues again.  ");
		scanf_s("%d", &response);
	} while (response != 1);

	displayResults();
	system("pause");
	return 0;
}

void recordResponse(int i, int rating)
{
	responses[i ][rating - 1]++;
}

void highestRatings()
{
	
	int highRating = 0;
	int highTopic = 0;
	int i;
	int j;

	for (i = 0; i < issues; i++)
	{
		int topicRating = 0;

		for (j = 0; j < ratings; j++)
		{
			topicRating += responses[i][j] * (j + 1);
		}
		if (highRating < topicRating)
		{
			highRating = topicRating;
			highTopic = i;
		}
	}
	printf("The higest rated topic was ");
	printf("%s", topics[highTopic]);
	printf(" with a total rating of %d\n", highRating);
}

void lowestRatings()
{

	int lowRating = 0;
	int lowTopic = 0;
	int i;
	int j;

	for (i = 0; i < issues; i++)
	{
		int topicRating = 0;

		for (j = 0; j < ratings; j++)
		{
			topicRating += responses[i][j] * (j + 1);
		}
		if (i == 0)
		{
			lowRating = topicRating;
		}
		if (lowRating > topicRating)
		{
			lowRating = topicRating;
			lowTopic = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lowTopic]);
	printf(" with a total rating of %d\n", lowRating);
}

float averageRating(int issue)
{
	float total = 0;
	int counter = 0;
	int j;

	for (j = 0; j < ratings; j++)
	{
		if (responses[issue][j] != 0)
		{
			total += responses[issue][j] * (j + 1);
			counter += responses[issue][j];
		}
	}
	return total / counter;
}

void displayResults()
{
	int i;
	int j;
	printf("%20s", "Topic");
	for (i = 1; i <= ratings; i++)
	{
		printf("%4d", i);
	}
	printf("%20s", "Average Rating\n");

	for (i = 0; i < issues; i++)
	{
		printf("%20s", topics[i]);

		for (j = 0; j < ratings; j++)
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f", averageRating(i));
		printf("\n");
	}
	highestRatings();
	lowestRatings();
}
