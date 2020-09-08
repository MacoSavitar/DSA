L1Item<T> *pDlt;
    if (_pHead) {
        if (i==0) {
            pDlt=_pHead;
            _pHead=_pHead->pNext;
            return 0;
        }
        else {
            L1Item<T> *pCur=_pHead;
            //pDlt=_pHead;
            for (int j=0;j<i-1;j++) {
                pCur = pCur->pNext;
            }
            pDlt=pCur->pNext;
            pCur->pNext=pDlt->pNext;

        }
        delete pDlt;
        _size-=1;
        return 0;
    }
    else return -1;