#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif
void reverseList(ringsignList *&pList)
{
    ringsignList *Cur = pList, *Pre = NULL, *Next = NULL;
    while (Cur)
    {
        Next = Cur->pNext;
        Cur->pNext = Pre;
        Pre = Cur;
        Cur = Next;
    }
    pList = Pre;
    while (Pre->pNext)
    {
        Pre = Pre->pNext;
    }
}
ringsignList *insertTail(ringsignList *pList, ringsignList *pNew)
{
    ringsignList *Tail = pList;
    while (Tail->pNext != NULL)
    {
        Tail = Tail->pNext;
    }
    Tail->pNext = pNew;
    return pList;
}

ringsignList *combat(knight &theKnight, eventList *pEvent)
{
    ringsignList *pList = new ringsignList;
    //fighting for honor and love here
    bool Isidur = false, Legolas = false, Gandalf = false;
    if (theKnight.HP == 777)
        Isidur = true;
    if (theKnight.HP == 888)
        Legolas = true;
    if (theKnight.HP == 999)
        Gandalf = true;
    //check run
    //cout << "Combat run!" << endl;
    //Gan gia tri dau cho pList
    pList->nRingsign = theKnight.nInitRingsign;
    pList->pNext = NULL;
    //Init variable
    int numEvent = 0;
    int maxHP = theKnight.HP;
    bool theKnightDead = false;
    while (pEvent)
    {
        if (theKnightDead == true)
            break;
        numEvent += 1;
        //Check loop while
        //cout << "Loop while in combat run: " << numEvent << endl;
        //S1
        if (pEvent->nEventCode == 0)
        {
            break;
        }
        //S2
        if ((pEvent->nEventCode >= 10 && pEvent->nEventCode <= 69) || (pEvent->nEventCode >= 90 && pEvent->nEventCode <= 99))
        {
            bool isUrukhai = false, isRingrwaiths = false, isStrider = false, isGollum = false, isLuitz = false, isGimli = false, isSaruman = false;
            int b = numEvent % 10;
            int levelO = numEvent > 6 ? (b > 5 ? b : 5) : b;

            int baseDamage = 0;
            //Uruk-hai
            if (pEvent->nEventCode >= 10 && pEvent->nEventCode <= 19)
            {
                baseDamage = 10;
                isUrukhai = true;
            }
            //Ringrwaiths
            if (pEvent->nEventCode >= 20 && pEvent->nEventCode <= 29)
            {
                baseDamage = 18;
                isRingrwaiths = true;
            }
            //Strider
            if (pEvent->nEventCode >= 30 && pEvent->nEventCode <= 39)
            {
                baseDamage = 45;
                isStrider = true;
            }
            //Gollum
            if (pEvent->nEventCode >= 40 && pEvent->nEventCode <= 49)
            {
                baseDamage = 82;
                isGollum = true;
            }
            //Luitz
            if (pEvent->nEventCode >= 50 && pEvent->nEventCode <= 59)
            {
                baseDamage = 75;
                isLuitz = true;
            }
            //Gimli
            if (pEvent->nEventCode >= 60 && pEvent->nEventCode <= 69)
            {
                baseDamage = 90;
                isGimli = true;
            }
            //Saruman
            if (pEvent->nEventCode >= 90 && pEvent->nEventCode <= 99)
            {
                baseDamage = 1;
                isSaruman = true;
            }
            //Win
                if (theKnight.level > levelO)
                {
                    if (pEvent->nEventCode >= 90 && pEvent->nEventCode <= 99)
                    {
                        reverseList(pList);
                    }
                    else
                    {
                        ringsignList *pNew = new ringsignList;
                        pNew->nRingsign = (pEvent->nEventCode) % 10;
                        pNew->pNext = NULL;
                        pList = insertTail(pList, pNew);
                    }
                }
                //Lose
                if (theKnight.level < levelO)
                {
                    theKnight.HP -= baseDamage * levelO;
                    if (theKnight.HP <= 0)
                        theKnightDead = true;
                }
            }
        }
    }
    if (pList == NULL)
    {
        theKnightDead = true;
    }

    pEvent = pEvent->pNext;
    /*
	//check run again
	cout << "Combat run again!" << endl;
	*/
    ringsignList *p = pList;
    cout << "List: ";
    while (p)
    {
        cout << p->nRingsign << " ";
        p = p->pNext;
    }
    cout << endl;
    if (theKnightDead)
        return NULL;
    return pList;
}

int checkPalindrome(ringsignList *pRingsign)
{
    return 0;
}
