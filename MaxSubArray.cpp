bool isOddNumber(int data) {
    return (data & 1) == 1;
}

void OddEvenSort(int *pData, unsigned int length) {
	if (pData == NULL || length == 0)
		return;
	else {
		int *pBegin = pData;
		int *pEnd = pData + length - 1;
		while (pBegin < pEnd) {
			if (isOddNumber(*pBegin))
				++pBegin;
			else if (isOddNumber(*pBegin))
				pEnd--;
			else
				swap(*pBegin, *pEnd);
		}
	}
}