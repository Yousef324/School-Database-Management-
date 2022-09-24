#define FIRSTBIGGER 1
#define SECONDBIGGER -1
#define EQUAL 0

void print_array_char(char *str)
{
    int i = 0;

    for(i=0; str[i]!=0; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}


void print_string(char *str)
{
    int i = 0;

    for(i=0; str[i]!= 0; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}




void string_LowerCase(char *str)
{
    int i = 0;

    for(i = 0; str[i]!=0; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}




void string_UpperCase(char *str)
{
    int i = 0;

    for(i = 0; str[i]!=0; i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
    }

}





int string_length(char *str)
{
    int i = 0;
    for(i = 0; str[i]; i++);
    return i;
}





void string_reverse(char *str)
{
    int i = 0, j, temp = 0;
    j = string_length(str) -1;

    for(i = 0; i<=j; i++)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
}



void string_reverse2(char *str, int f, int l)
{
    int i = 0, j = 0, temp = 0;
    i = f;
    j = l;

    for(; i<=j; i++,j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}


int string_compare(char *str1, char *str2)
{
    int i = 0;

    for(i = 0; (str1[i]!=0 || str2[i]!=0); i++)
    {
        if(str1[i] != str2[i])
        {
            return 0;
        }
    }

    return 1;
}




int string_compare_2(char *str1, char *str2)
{
    int i = 0;

    for(i = 0; (str1[i]!=0 || str2[i]!=0); i++)
    {
        if(str1[i]>str2[i])
        {
            return FIRSTBIGGER;
        }
        else if(str2[i]>str1[i])
        {
            return SECONDBIGGER;
        }
    }

    return EQUAL;
}



int string_compareNotCaseSensetive(char *str1, char *str2)
{
    int i = 0;


    for(i = 0; (str1[i]!=0 || str2[i] != 0); i++)
    {
        if((str1[i] == str2[i]) || (str1[i] == str2[i] + 'A' - 'a')  || (str1[i] == str2[i] - 'A' + 'a'))
        {

        }
        else
        {
            return 0;
        }
    }

    return 1;

}



void copy_string(char*source, char*dest, int MaxSize)
{
    int i = 0;
    for(i = 0; (source[i]!= 0 && i<MaxSize-1); i++)
    {
        dest[i] = source[i];
    }
    dest[i] = 0;
}





void scan_string(char *str, int MaxSize)
{
    //printf("Maximum Size for string: %d\n", MaxSize-1);

    int i = 0;
    scanf(" %c", &str[i]);
    for(;(str[i]!='\n' && i<MaxSize-1);)
    {
        i++;
        scanf("%c", &str[i]);

    }

    str[i] = 0;
}


void string_FindLongestWord(char *str, char *word)
{

    int i = 0, count = 0, max = 0, index = 0, j = 0;

    for(i = 0; str[i]!=0; i++)
    {
        if(str[i] == ' ')
        {
            if(count >= max)
            {
                max = count;
                index = i;
            }

            count = 0;
        }

        else
        {
            count++;
        }
    }

    if(count >= max)
    {
        max = count;
        index = i;
    }

    i = index - max;

    for(; i<index; i++)
    {
        word[j] = str[i];
        j++;
    }
    word[j] = 0;
}




void reverse_WordsInSentence (char *str)
{
    int f = 0, l = string_length(str) - 1, i;

    string_reverse2(str,f,l);

    for(i = 0; str[i]!=0; i++)
    {
        if(str[i] == ' ')
        {
            l = i-1;
            string_reverse2(str,f,l);
            f = i+1;
        }
    }
    string_reverse2(str,f,string_length(str)-1);
}



void IntToString(int number, char *str)
{
    int rem = 0, i = 0, flag = 0;

    if(number == 0)
    {
        str[0] = '0';
        str[1] = 0;
    }

    else
    {
        if(number < 0)
        {
            number = number * (-1);
            flag = 1;
        }

        while(number>0)
        {
            rem = number % 10;
            str[i] = rem + '0';
            number = number / 10;
            i++;
        }

        if(flag == 1)
        {
            str[i] = '-';
            i++;
        }
        str[i] = 0;
        string_reverse2(str,0,i-1);

    }

}




int StringToint(char *str)
{
    int i = 0, num = 0, flag = 0;

    if(str[i]== '-')
    {
        flag = 1;
        i++;
    }
    for(; str[i]!=0; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            num = num*10 + (str[i] - '0');
        }

    }
    if(flag == 1)
    {
        num = num * (-1);
    }
    return num;
}







void ArrayofPointers_StringPrint(char **arr, int size)
{
    int i, j;

    for(i = 0; i<size; i++)
    {
        printf("%s\n", arr[i]);
    }

    /*
    for(i = 0; i<size; i++)
    {
        print_string(arr[i]);
    }
    */


    /*
    for(i = 0; i<size; i++)
    {
        for(j = 0; arr[i][j]!=0; j++)
        {
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    */
}




int ArrayOfPointers_LinearSearchStrings(char**arr, int size, char*element)
{
    int i;

    for(i = 0; i<size; i++)
    {
        if(string_compare(arr[i], element) == 1)
        {
            return i;
        }
    }

    return -1;
}




int ArrayOfPointers_BinarySearch(char**arr, int size, char*element)
{
    int first, middle, last;
    first = 0;
    last = size-1;

    while(first<=last)
    {
        middle = (first + last)/2;

        if(string_compare_2(arr[middle],element) == EQUAL)
        {
            return middle;
        }

        else if(string_compare_2(arr[middle],element) == FIRSTBIGGER)
        {
            last = middle - 1;
        }

        else
        {
            first = middle + 1;
        }

    }

    return -1;
}




/*

void ArrayOfPointers_BubbleSortStrings(char**arr, int size)
{
    int j = 0, i = 0, sortedFlag;

    for(i = 0; i<size; i++)
    {
        sortedFlag = 1;
        for(j = 0; j<size-1-i; j++)
        {
            if(string_compare_2(arr[j],arr[j+1]) == FIRSTBIGGER)
            {
                swap_pointers(&arr[j], &arr[j+1]);
                sortedFlag = 0;
            }
        }

        if(sortedFlag == 1)
        {
            break;
        }
    }
}
*/

int *ArrayOfPointers_CountChar(char **arr,int size, char element, int *count)
{

    int i = 0, j = 0;
    static int index[2] = {-1,-1};

    for(i = 0; i<size; i++)
    {
        for(j = 0; arr[i][j]!=0; j++)
        {
            if(arr[i][j] == element)
            {
                (*count)++;
                if((*count) == 1)
                {
                    index[0] = i;
                    index[1] = j;
                }
            }
        }
    }


    return index;
}


void print_page_2darraystrings(char arr[][100], int line)
{
    int i,j;
    for(i = 0; i<line; i++)
    {
        print_string(arr[i]);
    }
}


int ArrayOfStrings_FindCountChar(char arr[][100], int line, char element)
{
    int i , j , c=0;

    for(i = 0; i<line; i++)
    {
        for(j = 0; arr[i][j]!='\0'; j++)
        {
            if(arr[i][j] == element)
            {
                c++;
                printf("'%c' : %d found in line %d in index %d\n" , element,c ,i, j);
            }

        }
    }

    return c;

}












