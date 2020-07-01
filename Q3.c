/* CS261- Assignment 1A - Question 3
   Name: Linshengyi Sun Partner: Samantha Rodarte
   Date: 6/29/2020
   Solution description: Convert the string into the camelcase format, print it out.
*/

#include <stdio.h>
#include <stdlib.h>

char toUpperCase(char ch)
{
  // Convert ch to upper case, assuming it is in lower case currently
  if(ch >= 'a' && ch <= 'z')
    ch = ch - 32;
  return ch;
}

char toLowerCase(char ch)
{
  if(ch >= 'A' && ch <='Z')
    ch = ch + 32;
  // Convert ch to lower case, assuming it is in upper case currently                          
  return ch;
}

int stringLength(char s[])
{

  int length = 0;
  while (s[length] != '\0')
  {
    length++;
  }

  return length;
   // Return the length of the string
}

int is_all_letter(char* word)
{
	int length = stringLength(word);
  //int true_or_false = 0;
  int letter_num = 0;
  int i = 0;
  while(i != length)
  {
		if((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))
    {
      letter_num = letter_num + 1;
		}
    ++i;
	}
  if((letter_num + 1) == length) // + 1 is to include '\n'
    return 0;
  else
    return 1;
  
}

int is_all_symbol(char* word)
{
  int length = stringLength(word);
  int symbol_num = 0;
  int i = 0;
  while(i != length)
  {
		if(!(word[i] >= 65 && word[i] <= 90) && !(word[i] >= 97 && word[i] <= 122)) 
    {
      symbol_num = symbol_num + 1;
		}
    ++i;
	}
  
  if(symbol_num == length) // No "+1" since '\0' is non-letter.
    return 0;
  else
    return 1;
}

int is_symbol_in_between(char* word)
{
  int length = stringLength(word);
  int true_or_false = 0;
  for(int i = 1; i < length - 2; i++)
  {
    if(!(word[i] >= 65 && word[i] <= 90) && !(word[i] >= 97 && word[i] <= 122))
    {
      true_or_false = 1;
      break;
    }
  }
  return true_or_false;
}
void convert_to_underscore_and_lowercase(char* word) 
{
	int length = stringLength(word);
	//int j,k,t;
  int i = 0;
  while(i != length)
  {
		if (!(word[i] >= 65 && word[i] <= 90) && !(word[i] >= 97 && word[i] <= 122)) 
    {
			word[i] = '_';
		}
		else
    {
      word[i] = toLowerCase(word[i]);
    }
    ++i;
	}
}
void convert_to_letter_group_underscore(char* word)
{
  int length = stringLength(word);
  //int new_word_length = length;
  char new_word[100];
  int i = 0;
  int new_i = 0;
  while(i != length)
  {
    if((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))
    {
      new_word[new_i] = word[i];
      new_i++;
      if(word[i+1] == '_' && new_i != length - 1)
      {
        new_word[new_i] = '_';
        new_i++;
      }
      
    }
    ++i;
  }
  //int new_word_length = stringLength(new_word);
  //new_word[new_word_length-1] = '\0';
  /*
  if(new_word[new_i] == '_' &&new_word[new_i+1] == '\0')
  {
    new_word[new_i] = '\0';
  }
  
  //printf("New word length: %d \n", new_word_length);
  */
  printf("After first converting: %s \n", new_word);
  


}
void camelCase(char* word)
{
	// Convert to camelCase
	
	//Check if the string is valid
	if(is_all_letter(word) == 0 || is_all_symbol(word) == 0 || is_symbol_in_between(word) == 0)
  {
		printf("Invalid string. \n");
    exit(1);
	}
  else
	/*Convert all non letter character to underscores;
    convert all letter character to lowercase. */
	{
    convert_to_underscore_and_lowercase(word);

    //convert the string to the format of lettergroup + underscore + lettergroup
    convert_to_letter_group_underscore(word);

	  //Start to convert it to the final version
	  int t, length = stringLength(word);
    int i = 0;
	  for(int i = t = 0; i<length;++i)
	  {
      if(word[i] == '_')
		  {
        word[i+1] = toUpperCase(word[i+1]);
			  word[i] = '\0';
		  }
      else
		  {
			  word[t++] = word[i];
		  }
    }
	  //Adjust the word
	  word[0] = toLowerCase(word[0]);
    int j = length - 1;
    while(j >= t)
    {
      word[j] = '\0';
      j--;
    }
  }
}

int main()
{

	// Read the string from the keyboard
  char s[100];
	printf("Please enter a string.\n");
  fgets(s,100,stdin);

	// Call camelCase
	camelCase(s);
  
	
	// Print the new string
  printf("After converting: %s \n ", s);
	
	
	return 0;
}