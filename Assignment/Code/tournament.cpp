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
	// while (Pre->pNext)
	// {
	// 	Pre = Pre->pNext;
	// }
}
void removeTail(ringsignList *&pList, int value)
{
	ringsignList *Pre, *Cur, *pDlt, *pPreDlt;
	Pre = NULL;
	pPreDlt = NULL;
	pDlt = NULL;
	if (pList != NULL && pList->nRingsign == value)
		pDlt = pList;
	Cur = pList;
	while (Cur)
	{
		if (Cur->nRingsign == value)
		{
			pDlt = Cur;
			if (Pre != NULL)
			{
				pPreDlt = Pre;
			}
		}
		Pre = Cur;
		Cur = Cur->pNext;
	}
	if (pDlt != NULL)
	{
		if (pPreDlt != NULL)
			pPreDlt->pNext = pDlt->pNext;
		if (pDlt == pList)
			pList = pList->pNext;
		delete pDlt;
	}
}
void removeZero(ringsignList *&pList)
{
	bool isFirst = true;
	ringsignList *p = pList;
	while (p)
	{
		if (p->nRingsign != 0)
		{
			isFirst = false;
		}
		else if (isFirst)
		{
			ringsignList *pDlt = pList;
			pList = pList->pNext;
		}
		p = p->pNext;
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
			if (!((Legolas && (isStrider || isGimli)) || (Gandalf && (isUrukhai || isRingrwaiths || isGimli))))
			{
				if (theKnight.level > levelO)
				{
					if (isSaruman)
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
					if (!Isidur)
					{
						//Gollum
						if (isGollum)
						{

							removeTail(pList, (pEvent->nEventCode) % 10);
							//reverseList(pList);
						}
						//Luitz
						if (isLuitz)
						{
							for (int i = 0; i < 3; i++)
							{
								if (pList)
								{
									ringsignList *pDlt = pList;
									pList = pList->pNext;
									delete pDlt;
								}
								else
								{
									theKnightDead = true;
									break;
								}
							}
						}
						//Saruman
						if (isSaruman)
						{
							int key = pEvent->nEventCode % 10;
							ringsignList *p = pList;
							int count = 0;
							while (p)
							{
								if (p->nRingsign == key)
								{
									count += 1;
								}
								p = p->pNext;
							}
							for (int i = 0; i < count; i++)
							{
								removeTail(pList, key);
							}
							if (pList == NULL)
								theKnightDead = true;
						}
					}
					theKnight.HP -= baseDamage * levelO;
					if (theKnight.HP <= 0)
						theKnightDead = true;
				}
			}
		}
		//S3
		if (pEvent->nEventCode == 7)
		{
			removeZero(pList);
			if (pList == NULL)
			{
				pList = new ringsignList;
				pList->nRingsign = 0;
				pList->pNext = NULL;
			}

			reverseList(pList);
			ringsignList *p = pList;
			p->nRingsign += 1;
			while (p != NULL)
			{
				if (p->nRingsign == 10)
				{
					p->nRingsign = 0;
					if (p->pNext != NULL)
					{
						p->pNext->nRingsign += 1;
					}
					else
					{
						ringsignList *pNew = new ringsignList;
						pNew->nRingsign = 1;
						pNew->pNext = NULL;
						p->pNext = pNew;
					}
				}
				p = p->pNext;
			}

			reverseList(pList);
		}
		//S4
		if (pEvent->nEventCode == 8)
		{
			if (theKnight.HP < maxHP)
			{
				theKnight.HP = maxHP;
				if (!(Isidur || Legolas))
				{
					ringsignList *pCur = pList, *pPre;
					if (pCur->pNext == NULL)
					{
						delete pCur;
						return NULL;
					}
					while (pCur->pNext != NULL)
					{
						pPre = pCur;
						pCur = pCur->pNext;
					}
					pPre->pNext = NULL;
					delete pCur;
				}
			}
		}
		if (pList == NULL)
		{
			theKnightDead = true;
		}

		pEvent = pEvent->pNext;
	}
	/*
	//check run again
	cout << "Combat run again!" << endl;
	*/
	// ringsignList *p = pList;
	// cout << "List: ";
	// while (p)
	// {
	// 	cout << p->nRingsign << " ";
	// 	p = p->pNext;
	// }
	// cout << endl;
	if (theKnightDead)
		return NULL;
	return pList;
}

int checkPalindrome(ringsignList *pRingsign)
{
	if (pRingsign == NULL)
		return 0;
	if (pRingsign->pNext == NULL)
		return 1;
	ringsignList *p = pRingsign;
	int count = 0, ECCode = 0;
	bool isFirst = true, check = true;
	while (p)
	{
		ECCode = ECCode * 10 + p->nRingsign;
		if (p->nRingsign == 0 && isFirst)
			count += 1;
		else
			isFirst = false;
		p = p->pNext;
	}
	removeZero(p);
	for (int i = 0; i < count; i++)
	{
		if (ECCode % 10 == 0)
		{
			ECCode /= 10;
		}
		else
			return 0;
	}
	//cout << ECCode << " " << count << endl;
	int temp, sum=0, i, j;
	for (i = ECCode; ECCode != 0; ECCode = ECCode / 10)
	{
		j = ECCode % 10;
		sum = sum * 10 + j;
	}
	if (i == sum)
		return 1;
	else
		return 0;
}
