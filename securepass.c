#include<ctype.h>
#include<stdio.h>
#include<string.h>

void display_strength(int score);
int calculate_score(size_t length, int uppercase, int lowercase, int digits, int specialcharacter, int repetitions, int sequences, int alphabet_sequences);
void display_suggestions(size_t length, int uppercase, int lowercase, int digits, int specialcharacter, int repetitions, int sequences, int alphabet_sequences);
int count_repetitions(const char pass[]);
int count_sequences(const char pass[]);
int count_alphabet_sequences(const char pass[]);

int main(void)
{
    printf("Welcome to SecurePass!\n");
   char pass[256];

printf("Enter a fictional test password: ");

if (fgets(pass, sizeof(pass), stdin) == NULL)
{
    printf("Error reading input.\n");
    return 1;
}

size_t length = strlen(pass);

if (length > 0 && pass[length - 1] == '\n')
{
    pass[length - 1] = '\0';
    length--;
}
else if (length == sizeof(pass) - 1)
{
    printf("Input too long. Maximum 254 characters.\n");
    return 1;
}

    printf("Password analysis\n");

    int uppercase = 0;
    int lowercase = 0;
    int specialcharacter = 0;
    int digits = 0;

    printf("Password length: %zu\n", length);

    for(size_t i =0; i < length; i++)
    {
        if(isupper(pass[i]))

        {
             uppercase++;
        }
        else if(islower(pass[i]))
        {
            lowercase++;
        }
        else if(isdigit(pass[i]))
        {
                digits++;
        }
        else if(ispunct(pass[i]))
        {
                specialcharacter++;
        }

    }
    printf("Uppercase: %i\n", uppercase);
    printf("Lowercase: %i\n", lowercase);
    printf("Digits: %i\n", digits);
    printf("Special character: %i\n",  specialcharacter);
     int repetitions = count_repetitions(pass);
    printf("Adjacent repetitions: %i\n", repetitions);
    int sequences = count_sequences(pass);
    printf("Digit sequences detected: %i\n", sequences);
    int alphabet_sequences = count_alphabet_sequences(pass);
    printf("Alphabetical sequences detected: %i\n", alphabet_sequences);


    int score = calculate_score(length, uppercase, lowercase, digits, specialcharacter, repetitions, sequences, alphabet_sequences);
    printf("Password Score: %i\n", score);
    display_strength(score);

    display_suggestions(length, uppercase, lowercase, digits, specialcharacter, repetitions, sequences, alphabet_sequences);
    return 0;
}


    // Display the password strength classification
    void display_strength(int score)
{
     if(score < 40)
    {
        printf("Password checklist rating: Weak\n");
    }
    else if(score < 80)
    {
        printf("Password checklist rating: Moderate\n");
    }
    else
    {
        printf("Password checklist rating: High\n");
    }
}

    //Function to calculate score
int calculate_score(size_t length, int uppercase, int lowercase, int digits, int specialcharacter, int repetitions, int sequences, int alphabet_sequences)
{
    int score = 0;

    if(length >= 8)
    {
        score += 20;
    }
    if(length >= 12)
    {
        score += 20;
    }
    if(uppercase > 0)
    {
        score += 15;
    }
    if(lowercase > 0)
    {
        score += 15;
    }
    if(digits > 0)
    {
        score += 15;
    }
    if(specialcharacter > 0)
    {
        score += 15;
    }
    int penalty = (repetitions*5) + (sequences * 10) + (alphabet_sequences * 10);
    score = score - penalty;

    if(score < 0)
    {
        score = 0;
    }
    return score;
}

//Display suggestions
void display_suggestions(size_t length, int uppercase, int lowercase, int digits, int specialcharacter, int repetitions, int sequences, int alphabet_sequences)
{
     printf("\nSecurity Suggestions: \n");
       if(length < 12)
    {
        printf("Consider using at least 12 characters\n");
    }
    if(uppercase == 0)
    {
        printf("Consider using uppercase\n");
    }
    if(lowercase == 0)
    {
        printf("Consider using lowercase\n");
    }
    if(digits == 0)
    {
        printf("Consider using digits\n");
    }
    if(specialcharacter == 0)
    {
        printf("Consider using special character\n");
    }
    if(length >= 12 && uppercase > 0 && lowercase > 0 &&
    digits > 0 && specialcharacter > 0)
    {
        printf("All basic checks passed!\n");
    }
    if(repetitions > 0)
    {
        printf("- Repeated adjacent characters detected.\n");
    }
    if(sequences > 0)
    {
        printf("- Predictable numerical sequence detected.\n");
    }
    if(alphabet_sequences > 0)
    {
        printf("- Predictable alphabetical sequence detected.\n");
    }
}

// detect repetitions
int count_repetitions(const char pass[])
{
    int repetitions = 0;
    size_t length = strlen(pass);

    for(size_t i =1; i < length; i++)
    {
        if(pass[i] == pass[i-1])
        {
        repetitions++;
        }
    }
    return repetitions;
}

//detecting patterns
int count_sequences(const char pass[])
{
    int sequences = 0;
    int consecutive = 1;
    size_t length = strlen(pass);
    int direction = 0;
    for(size_t i = 1; i < length; i++)

    {
   int difference = pass[i] - pass[i - 1];

if (isdigit(pass[i]) && isdigit(pass[i - 1]) &&
    (difference == 1 || difference == -1))
{
    if (direction == difference)
    {
        consecutive++;
    }
    else
    {
        direction = difference;
        consecutive = 2;
    }
}
else
{
    direction = 0;
    consecutive = 1;
}

if (consecutive == 4)
{
    sequences++;
}
    }
    return sequences;
}

int count_alphabet_sequences(const char pass[])
{
    int sequences = 0;
    int consecutive = 1;
    int direction = 0;
    size_t length = strlen(pass);

    for (size_t i = 1; i < length; i++)
    {
        int current = tolower(pass[i]);
        int previous = tolower(pass[i - 1]);

        int difference = current - previous;

        if (isalpha(pass[i]) && isalpha(pass[i - 1]) &&
            (difference == 1 || difference == -1))
        {
            if (direction == difference)
            {
                consecutive++;
            }
            else
            {
                direction = difference;
                consecutive = 2;
            }
        }
        else
        {
            direction = 0;
            consecutive = 1;
        }

        if (consecutive == 4)
        {
            sequences++;
        }
    }
    return sequences;
}


