# include <stdio.h>
void RemoveReduandantZeros(char Input[], int NewSize, char*ReturnBuffer){
    //This rebuilds an array but shorter
    //Purpose of this is to remove any zeros that are after the largest digit with a 1
    for (int IndexTwo = 0; IndexTwo < NewSize; ++IndexTwo) {
        ReturnBuffer[IndexTwo] = Input[IndexTwo];
    }
}
int LengthBeforeReduandant(char Input[], int InputSize){
    // This finds where the last 1 is in an array
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
    //This adds zeros at the end of an array to to make both arrays of equal length
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
char GetHigherNumber(char FirstNumber[], int FirstLength, char SecondNumber[], int SecondLength){
    //Returns true if FirstNumber >= SecondNumber
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
void StringToBoolArray(char Input[], int InputSize, char *ReturnBuffer){
    int ReverseIndex = 0;
    for (int ForIndex = InputSize - 1; ForIndex >= 0; --ForIndex) {
        ReturnBuffer[ReverseIndex] = Input[ForIndex];
        ReverseIndex++;
    }
}


void BinaryBoolAddition(char FirstNumber[], int FirstLength, char SecondNumber[], int SecondLength, char *ReturnBuffer){
    char CurFirst;
    char CurSecond;
    int NumOfTrues = 0;
    int maxlen = FirstLength + 1;
    char ResultBool = 48;
    for (int ForIterator = 0; ForIterator <= maxlen - 1; ++ForIterator) {
        if (ForIterator == maxlen - 1){
            CurSecond = 48;
            CurFirst = 48;
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
    //This works by fliping all values of SecondNum, adding one, then removing the largest digit

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
            BinaryBoolAddition(WorkingArrayop, MaxDigits, Addthis, MaxPreLength/*s*/     + ForIndex, WorkingArray);
        }
    }
    for (int ReturnIndex = 0; ReturnIndex < MaxDigits; ++ReturnIndex) {
        ReturnBuffer[ReturnIndex] = WorkingArray[ReturnIndex];
    }

}
void BinaryBoolDivision(char FirstNumber[], int FirstLength, char SecondNumber[], int SecondLength, char *ReturnBuffer, char *RemainderBuffer){
    // FirstNumber/Secondnumber
    // Repeted subtraction SecondNumber from FirstNumber until SecondNumber > FirstNumber
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
        for (int OperatorIndex = 0; OperatorIndex < FirstLength; ++OperatorIndex){
            SubtractionCountOp[OperatorIndex] = SubtractionCount[OperatorIndex];
            WorkingNumOp[OperatorIndex] = WorkingNum[OperatorIndex];
        }
        BinaryBoolAddition(SubtractionCountOp,FirstLength,OneArray,1,SubtractionCount);
        BinaryBoolSubtraction(WorkingNumOp,FirstLength,SecondNumber,SecondLength,WorkingNum);

        HigherArrayBool = GetHigherNumber(WorkingNum, FirstLength, SecondNumber, SecondLength);
        if (HigherArrayBool == 48){
            for (int ReturnIndex = 0; ReturnIndex < FirstLength; ++ReturnIndex){
                ReturnBuffer[ReturnIndex] = SubtractionCount[ReturnIndex];
                RemainderBuffer[ReturnIndex] = WorkingNum[ReturnIndex];
            }
            break;
        }
    }
    // TODO THIS
    // Could be faster by using a method similar to long division
}

int main(){//=============================================================================================================================================================================================

    char FirstNumberString[] =  "1000";
    char SecondNumberString[] = "11";             //currently FirstNumber must be bigger than SecondNumber

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
    char AdditionResult[FirstNumberSize + 1];
    BinaryBoolAddition(FirstNumbers, FirstNumberSize, SecondNumbers, SecondNumberSize, AdditionResult);
    int NonRedundatLenght = LengthBeforeReduandant(AdditionResult, FirstNumberSize + 1);
    char NoRedundantZerosAdd[NonRedundatLenght];
    RemoveReduandantZeros(AdditionResult, NonRedundatLenght, NoRedundantZerosAdd);
    PrintArray(NoRedundantZerosAdd, NonRedundatLenght);

    char SubtractionResult[FirstNumberSize];
    BinaryBoolSubtraction(FirstNumbers, FirstNumberSize, SecondNumbers, SecondNumberSize, SubtractionResult);
    NonRedundatLenght = LengthBeforeReduandant(SubtractionResult, FirstNumberSize);
 //   char NoRedundantZerosSub[NonRedundatLenght];
 //   RemoveReduandantZeros(SubtractionResult, NonRedundatLenght, NoRedundantZerosSub);
    PrintArray(SubtractionResult, NonRedundatLenght);

    char MultiplicationResult[FirstNumberSize + SecondNumberSize];
    BinaryBoolMultiplication(FirstNumbers, FirstNumberSize, SecondNumbers, SecondNumberSize, MultiplicationResult);
    NonRedundatLenght = LengthBeforeReduandant(MultiplicationResult, FirstNumberSize + SecondNumberSize);
 //   char NoRedundantZerosMult[NonRedundatLenght];
 //   RemoveReduandantZeros(MultiplicationResult, NonRedundatLenght, NoRedundantZerosMult);
    PrintArray(MultiplicationResult, NonRedundatLenght);

    char DivisionResult[FirstNumberSize];
    char DivisionRemainder[FirstNumberSize];
    BinaryBoolDivision(FirstNumbers, FirstNumberSize, SecondNumbers, SecondNumberSize, DivisionResult,DivisionRemainder);
    NonRedundatLenght = LengthBeforeReduandant(DivisionResult, FirstNumberSize);
    int NonRedundatLenght2 = LengthBeforeReduandant(DivisionRemainder, FirstNumberSize);
  //  char NoRedundantZerosDiv[FirstNumberSize];
  //  char NoRedundantZerosRem[FirstNumberSize];
  //  RemoveReduandantZeros(DivisionResult, NonRedundatLenght, NoRedundantZerosDiv);
  //  RemoveReduandantZeros(DivisionResult, NonRedundatLenght, NoRedundantZerosRem);
    PrintArray(DivisionResult, NonRedundatLenght);
    PrintArray(DivisionRemainder, NonRedundatLenght2);

    return 0; //============================================================================================================================================================================================
}