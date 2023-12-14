# include <stdio.h>
void RemoveReduandantZeros(char Input[], int NewSize, char*ReturnBuffer){
    for (int IndexTwo = 0; IndexTwo < NewSize; ++IndexTwo) {
        ReturnBuffer[IndexTwo] = Input[IndexTwo];
    }
}
int LengthBeforeReduandant(char Input[], int InputSize){
    int ReduandantCounter = 0;
    char CurChar;
    for (int Index = InputSize - 1; Index > 0; --Index) {
        CurChar = Input[Index];
        if (CurChar == 49){
            break;
        }
        ++ReduandantCounter;
    }
    int NonReduandant = InputSize - ReduandantCounter;
    return NonReduandant;
}
void EqualLengthArrays(char FirstNumber[],int FirstLenght, char SecondNumber[],int SecondLenght,int LargerSize, char *ReturnFirst, char *ReturnSecond){
    char CurBool;
    for (int ForIndex = 0; ForIndex < LargerSize; ++ForIndex) {
        if (FirstLenght <= ForIndex){
            ReturnFirst[ForIndex] = 48;
        } else{
            ReturnFirst[ForIndex] = FirstNumber[ForIndex];
        }
        if (SecondLenght <= ForIndex){
            ReturnSecond[ForIndex] = 48;
        } else{
            ReturnSecond[ForIndex] = SecondNumber[ForIndex];
        }
    }
}
char GetHigherVector(char FirstNumber[],int FirstLength,char SecondNumber[], int SecondLength){
    int LongestNum = FirstLength;
    if (SecondLength > FirstLength){
        LongestNum = SecondLength;
    }
    char FirstNumLong[LongestNum];
    char SecondNumLong[LongestNum];
    EqualLengthArrays(FirstNumber,FirstLength,SecondNumber,SecondLength,LongestNum,FirstNumLong,SecondNumLong);
    char CurFirst;
    char CurSecond;
    for (int ForReverseIndex = LongestNum - 1; ForReverseIndex >= 0; --ForReverseIndex) {

        CurFirst = FirstNumLong[ForReverseIndex];
        CurSecond = SecondNumLong[ForReverseIndex];
        if (CurFirst != CurSecond){
            if (CurFirst == 49){
                return 49;
            } else{
                return 48;
            }
        }
    }
    return 49;
}



void PrintArray(char Input[], int ArraySize){
    char CurChar;
    if (ArraySize < 60){
        for (int SpaceLeft = 60 - ArraySize; SpaceLeft >= 0; --SpaceLeft) {
            printf(" ");
        }
    }
    for (int Index = ArraySize - 1; Index >= 0; --Index) {
        CurChar = Input[Index];
        printf("%c",CurChar);
        // no fail protection
    }
    printf("\n");
}



void BinaryBoolAddition(char FirstNumber[], int FirstLength, char SecondNumber[], int SecondLength, char *ReturnBuffer){
    //TODO add EqualLengthArrays
    char CurFirst;
    char CurSecond;
    int NumOfTrues = 0;
    int maxlen = FirstLength + 1;
    char ResultBool = 48;
    for (int ForIterator = 0; ForIterator <= maxlen - 1; ++ForIterator) {
        if (ForIterator == maxlen - 1){
            CurSecond = 48;
            CurFirst = 48;  //TODO move to right after end of for, and remove else
        } else{
            CurFirst = FirstNumber[ForIterator];
            if (CurFirst == 49){
                ++NumOfTrues;
            }
            if (ForIterator >= SecondLength){
                CurSecond = 48;
            } else{
                CurSecond = SecondNumber[ForIterator];
                if (CurSecond == 49){
                    ++NumOfTrues;
                }
            }
        }
        if (NumOfTrues == 0){
            ResultBool = 48;
            NumOfTrues = 0;
        }
        if (NumOfTrues == 1){
            ResultBool = 49;
            NumOfTrues = 0;
        }
        if (NumOfTrues == 2){
            ResultBool = 48;
            NumOfTrues = 1;
        }
        if (NumOfTrues == 3){
            ResultBool = 49;
            NumOfTrues = 1;
        }
        ReturnBuffer[ForIterator] = ResultBool;
    }
}
void InversePlusOne(char Input[], int InputSize, char *ReturnBuffer){
    char InverseArray[InputSize];
    char CurBool;
    char Error = 48;
    for (int ForIndex = InputSize - 1; ForIndex >= 0; --ForIndex) {
        CurBool = Input[ForIndex];
        if  (CurBool == 48){
            InverseArray[ForIndex] = 49;
            continue;
        }
        if (CurBool == 49){
            InverseArray[ForIndex] = 48;
            continue;
        }
        Error = 49;
        InverseArray[ForIndex] = 88;
        printf("ERROR 005");
    }
    if (Error == 49){
    }
    char OneArray[1] = {49};
    char ReturnThis[InputSize + 1];
    BinaryBoolAddition(InverseArray,InputSize,OneArray,1,ReturnThis);
    for (int ForIndex2 = 0; ForIndex2 < InputSize + 1; ++ForIndex2) {
        ReturnBuffer[ForIndex2] = ReturnThis[ForIndex2];
    }
}
void BinaryBoolSubtraction(char FirstNumber[], int FirstLength, char SecondNumber[], int SecondLength, char *ReturnBuffer){
    //TODO add negatives
    //If it is negative it will return the overflow + 1 relative to num is bits in SecondNumber
    int LargerLenght = FirstLength;
    if (FirstLength < SecondLength){
        LargerLenght = SecondLength;
    }
    char FirstNumTwo[LargerLenght];
    char SecondNumTwo[LargerLenght];
    EqualLengthArrays(FirstNumber,FirstLength,SecondNumber,SecondLength,LargerLenght,FirstNumTwo,SecondNumTwo);
    int LargerLenPlusOne = LargerLenght + 1;

    char SecondNumInversePlusOne[LargerLenPlusOne];
    InversePlusOne(SecondNumTwo,LargerLenght,SecondNumInversePlusOne);
    char ResultArray[LargerLenght + 2];
    BinaryBoolAddition(FirstNumTwo,LargerLenght,SecondNumInversePlusOne,LargerLenght + 1,ResultArray);

    int NonOverflow = (LengthBeforeReduandant(ResultArray, LargerLenPlusOne)) - 1;

    for (int ReturnIndex = 0; ReturnIndex < LargerLenght + 2 ; ++ReturnIndex) {
        if (ReturnIndex >= NonOverflow){
            ReturnBuffer[ReturnIndex] = 48;
        } else{
            ReturnBuffer[ReturnIndex] = ResultArray[ReturnIndex];
        }
    }

}
void BinaryBoolMultiplication(char FirstNumber[], int FirstLength, char SecondNumber[], int SecondLength, char *ReturnBuffer){
    //Reapeted Addition
    int MaxPreLength = FirstLength;
    if (FirstLength < SecondLength){
        MaxPreLength = SecondLength;
    }
    char FirstNumberLong[MaxPreLength];
    char SecondNumberLong[MaxPreLength];
    EqualLengthArrays(FirstNumber, FirstLength, SecondNumber, SecondLength, MaxPreLength, FirstNumberLong, SecondNumberLong);
    //TODO Figure out what is wrong so I don't have to use EqualLengthArrays

    // Works when secondnum is lower
    int MaxDigits = MaxPreLength + SecondLength;
    char CurFirst;
    char CurSecond;
    char WorkingArray[MaxDigits];
    char WorkingArrayop[MaxDigits];
    for (int InitalizeIndex = 0; InitalizeIndex < MaxDigits; ++InitalizeIndex) {
        WorkingArray[InitalizeIndex] = 48;
        WorkingArrayop[InitalizeIndex] = 48;

    }
    int AddThisSize = 999;
    for (int ForIndex = 0; ForIndex < MaxPreLength /*s*/; ++ForIndex) {
        CurSecond = SecondNumberLong[ForIndex];
        AddThisSize = MaxPreLength + ForIndex;
        char Addthis[AddThisSize];
        if (CurSecond == 49) {
            for (int ZeroIndex = 0; ZeroIndex < ForIndex; ++ZeroIndex) {
                Addthis[ZeroIndex] = 48;
            }
            for (int FirstIndex = 0; FirstIndex < MaxPreLength; ++FirstIndex) {
                CurFirst = FirstNumberLong[FirstIndex];
                Addthis[ForIndex + FirstIndex] = CurFirst;
            }
            for (int OpIndex = 0; OpIndex < MaxDigits; ++OpIndex) {
                WorkingArrayop[OpIndex] = WorkingArray[OpIndex];
            }
            // working array starts as 0
            BinaryBoolAddition(WorkingArrayop, MaxDigits, Addthis, MaxPreLength/*s*/     + ForIndex, WorkingArray);

            // i belive it is now malfunctioning because seconnum digit is higher
        }
    }
    for (int ReturnIndex = 0; ReturnIndex < MaxDigits; ++ReturnIndex) {
        ReturnBuffer[ReturnIndex] = WorkingArray[ReturnIndex];
    }

}
void BinaryBoolDivision(char FirstNumber[], int FirstLength, char SecondNumber[], int SecondLength, char *ReturnBuffer, char *RemainderBuffer){
    // FirstNumber/Secondnumber
    // FirstNumber must be higher than SecondNumber
    // repeaditly subtract SecondNumber from FirstNumber until SecondNumber > FirstNumber
    char SubtractionCount[FirstLength];
    char SubtractionCountOp[FirstLength];
    char WorkingNum[FirstLength];
    char WorkingNumOp[FirstLength];
    char ReaminderNum[FirstLength];
    char OneArray[1] = {49};
    char HigherArrayBool = 48;
    for (int InitalizeIndex = 0; InitalizeIndex < FirstLength; ++InitalizeIndex) {
        SubtractionCount[InitalizeIndex] = 48;
        WorkingNum[InitalizeIndex] = FirstNumber[InitalizeIndex];
    }
    while (1 == 1){
    //    printf("\nITERTAITON");
  //      PrintArray(WorkingNum,FirstLength);
        for (int OperatorIndex = 0; OperatorIndex < FirstLength; ++OperatorIndex){
            SubtractionCountOp[OperatorIndex] = SubtractionCount[OperatorIndex];
            WorkingNumOp[OperatorIndex] = WorkingNum[OperatorIndex];        //TODO test if I don't need these
        }
        BinaryBoolAddition(SubtractionCountOp,FirstLength,OneArray,1,SubtractionCount);
        BinaryBoolSubtraction(WorkingNumOp,FirstLength,SecondNumber,SecondLength,WorkingNum);

        HigherArrayBool = GetHigherVector(WorkingNum,FirstLength,SecondNumber,SecondLength);
        PrintArray(WorkingNum,FirstLength);
        if (HigherArrayBool == 48){
            for (int ReturnIndex = 0; ReturnIndex < FirstLength; ++ReturnIndex){
                ReturnBuffer[ReturnIndex] = SubtractionCount[ReturnIndex];          //Might remove redundant zeros here
                RemainderBuffer[ReturnIndex] = WorkingNum[ReturnIndex];
            }
            break;
        }
    }
}

void StringToBoolArray(char Input[], int InputSize, char *ReturnBuffer){
    //TODO add invalid character checker
    int ReverseIndex = 0;
    for (int ForIndex = InputSize - 1; ForIndex >= 0; --ForIndex) {
        ReturnBuffer[ReverseIndex] = Input[ForIndex];
        ReverseIndex++;
    }
}

int main(){//=============================================================================================================================================================================================

    char FirstNumberString[] =  "11111000011100111100011010";
    char SecondNumberString[] = "10111000011";             //currently FirstNumber must be bigger than SecondNumber

    int FirstNumberSize = sizeof(FirstNumberString) - 1;//=================================================================================================================================================
    int SecondNumberSize = sizeof(SecondNumberString) - 1;
    char FirstNumbers[FirstNumberSize];
    StringToBoolArray(FirstNumberString,FirstNumberSize,FirstNumbers);
    char SecondNumbers[SecondNumberSize];
    StringToBoolArray(SecondNumberString,SecondNumberSize,SecondNumbers);
    PrintArray(FirstNumbers,FirstNumberSize);
    PrintArray(SecondNumbers,SecondNumberSize);
    int LargerLenght = FirstNumberSize;
    if (FirstNumberSize < SecondNumberSize){
        LargerLenght = SecondNumberSize;
    }
    printf("=============================================================\n");//=====================================================================================================================

    char WorkingNum[128] = "11101100011010101110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";\
    char WorkingNumOp[128];
    char One[1] = {49};
    for (int InitIndex = 0; InitIndex < 128; ++InitIndex) {
  //      WorkingNum[InitIndex] = 48;
        WorkingNumOp[InitIndex] = 48;
    }
    while (1 == 1){
        for (int InitIndex = 0; InitIndex < 128; ++InitIndex) {
            WorkingNumOp[InitIndex] = WorkingNum[InitIndex];
        }
        BinaryBoolAddition(WorkingNumOp,128,One,1,WorkingNum);
        PrintArray(WorkingNum,128);
        if (WorkingNum[127] == 49){
            printf("127 is true");
            break;
        }
    }
    return 200; //==========================================================================================================================================================================================
}