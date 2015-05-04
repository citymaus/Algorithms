char* ReverseAllWords(char in_text[])
{
    int textlength = sizeof(in_text)/sizeof(char);
    int lindex = 0;
    int rindex = textlength - 1;
    if (rindex > 1)
    {
        //reverse complete phrase
        in_text = ReverseString(in_text, 0, rindex);

        //reverse each word in resultant reversed phrase
        for (rindex = 0; rindex <= textlength; rindex++)
        {
            if (rindex == textlength || in_text[rindex] == ' ')
            {
                in_text = ReverseString(in_text, lindex, rindex - 1);
                lindex = rindex + 1;
            }
        }
    }
    return in_text;
}

char* ReverseString(char intext[], int lindex, int rindex)
{
    char tempc;
    while (lindex < rindex)
    {
        tempc = intext[lindex];
        intext[lindex++] = intext[rindex];
        intext[rindex--] = tempc;
    }
    return intext;
}