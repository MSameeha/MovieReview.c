#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
struct Osc_Nom
{
  char *movie;
  float rating;
};
struct Osc_Nom Movies[15];
void swap(float* a, float* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void swap_str(char *str1, char *str2) 
{ 
  char *temp = str1; 
  str1 = str2; 
  str2 = temp; 
}    
int partition (int low, int high)
{
    int pivot = Movies[high].rating;  
    int i = (low - 1); 
    char *temp;
    for (int j = low; j <= high-1; j++)
    {
        if (Movies[j].rating < pivot)
        {
            i++;    // increment index of smaller element
            swap(&Movies[i].rating, &Movies[j].rating);
            temp = Movies[i].movie;
            Movies[i].movie = Movies[j].movie;
            Movies[j].movie = temp;
        }
    }
    swap(&Movies[i+1].rating, &Movies[high].rating);
    temp = Movies[i+1].movie;
    Movies[i+1].movie = Movies[high].movie;
    Movies[high].movie = temp;
    return (i + 1);
}
void quick_sort(int low, int high)
{
  if(low < high){
    int pi = partition(low, high);
    quick_sort(low, pi-1);
    quick_sort(pi+1, high); 
  }
}
void review(int x)
{
    x++;
  switch(x)
  {
    case 1: printf("The two men building a Ford car fast enough to beat Ferrari at Le Mans 66 & all the hell the corporation put them through");
            break;
    case 2: printf("The slow decline of Frank Sheeran, a hitman associate of Jimmy Hoffa.");
            break;
    case 3: printf("The premise of this high concept comedy finds director Waititi -- of Kiwi comedies and Thor: Ragnarok -- playing the imaginary friend version of Hitler that a little Nazi boydreams up in the waning days of WWII.");
            break;
    case 4: printf("It is much more than 'Man dresses as a clown, starts killing people'.The critical divide on Joker was swift. Is it a masterpiece? Derivative ?Dangerous? (To that last one: Probably not).");
            break;
    case 5: printf("The March sisters growing up in Massachusetts and their hopes and dreams.");
            break;
    case 6: printf("The drawn-out breakup of a couple torn between bi-coastal cities. ");
            break;
    case 7: printf("Two men on a mission to deliver a letter across No Man's Land during WWI.");
            break;
    case 8: printf("Quentin Tarantino rewrites the history of 1969 in Los Angeles, focusing on an over-the-hill actor and his stunt double buddy.");
            break;
    case 9: printf("A family of con artists infiltrates a rich family's home in modern-day South Korea. And then everything gets really crazy.");
            break;
  }
}
void url(int x)
{
    x++;
  switch(x)
  {
    case 1: system("start https://www.imdb.com/title/tt1950186/");
            break;
    case 2: system("start https://www.imdb.com/title/tt1302006/");
            break;
    case 3: system("start https://www.imdb.com/title/tt2584384/");
            break;
    case 4: system("start https://www.imdb.com/title/tt7286456/");
            break;
    case 5: system("start https://www.imdb.com/title/tt3281548/");
            break;
    case 6: system("start https://www.imdb.com/title/tt7653254/");
            break;
    case 7: system("start https://www.imdb.com/title/tt8579674/");
            break;
    case 8: system("start https://www.imdb.com/title/tt7131622/");
            break;
    case 9: system("start https://www.imdb.com/title/tt6751668/");
            break;  
  }
}
int main()
{
    int i = 0, ctr = 0, ma = -1;
    char ans;
    // corresponding array of structers 5 integers for movie ratings
      Movies[i++].movie = "Ford v Ferrari";
      Movies[i++].movie = "The Irishman";
      Movies[i++].movie = "Jojo Rabbit";
      Movies[i++].movie = "Joker";
      Movies[i++].movie = "Little Women";
      Movies[i++].movie = "Marriage Story";
      Movies[i++].movie = "1917";
      Movies[i++].movie = "Once Upon a Time in Hollywood";
      Movies[i++].movie = "Parasite";
    char *best;
    int call_review;
    printf("**Oscar Season is here!**\n\n");
    printf("Time to rate this year's best picture nominees:\n\n");

    for (int j = 0; j < i; j++)
    {
        printf("Did you see %s? Y or N\n", Movies[j].movie);
        scanf(" %c", &ans);
        if ((toupper(ans)) == 'Y')
        {
            printf("What is your rating on a scale of 1-10:\n");
            scanf(" %f", &Movies[j].rating);
            ma = (ma > Movies[j].rating)? ma : Movies[j].rating;
            if(Movies[j].rating == ma)
            {
                best = Movies[j].movie;
                call_review = j;
            }
            ctr++;
            // this will be used to print movies you've seen
        }
        else 
        {
           Movies[j].rating = -1;
           printf("Why you should watch it :- \n");
           review(j);
           printf("\n");
        }
    }
    quick_sort(0, i-1);  
    // now to printing the movies user saw in order with rating
    if(ctr)
    {
    printf("\n\n*Your movie ratings for the Oscar contenders*\n");
    for (int j = 0; j < i; j++)
    {
        if(Movies[j].rating != -1)
        {
            printf("%s is rated a %.0f\n", Movies[j].movie, Movies[j].rating);
        }
    }
    printf("\nAnd the winner for the best movie is......\n** %s **",best);
    printf("\n");
    review(call_review);
    printf("\nWant to visit IMDb review page? (Y or N)\n");
    scanf(" %c",&ans);
    if((toupper(ans)) =='Y')
        url(call_review);
    }
    else
    {
      printf("Go watch some movies!!");
    }
   
    return 0;
}
