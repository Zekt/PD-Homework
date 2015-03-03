#include<iostream>

using namespace std;

int main()
{
	int input,m,n,num;
	//input是輸入，m,n為題目中的m,n，num為跟input比較用的數
	bool found;
	//紀錄是否找到答案，若為1代表找到
	cin >> input;
	//第一次輸入
	while(input != 0)
	{//當輸入數字不為0時重複執行，為0就跳出
		if(input > 0)
		{//當輸入為正數
			m = 1,found = 0;
			//初始化，每次輸入時m為2開始，先設為1第一次進入迴圈會變2
			while(m < input)
			{//當m小於input時不斷增加m
				m = m+1;
				n = 1;
				num = m;
				//m不斷增加，對於每個m枚舉n，從2開始,num紀錄m的n次方，從m的2次方開始，分別設為1跟m，原因皆同上面的m
				while(num < input)
				{//num紀錄當下的m的n次方，只有在小於input時繼續執行
					num = num*m;
					n = n+1;
					//每次將num乘上m倍，n加1，則任何時候num等於m的n次方
					if(num == input)
					{//當num與input相等時
						cout << m << " " << n << "\n";
						found = 1;
						//輸出並紀錄已找到答案
					}
				}
				if(found == 1)
					m = input;
				//如果找到答案將m設為input讓while中條件不成立以跳出迴圈(不要打我)
			}
			if(found == 0)
				cout << "-1\n";
			//沒找到輸出-1
		}
		if(input < 0)
			cout << "Please input a positive integer!\n";
		//輸入為負數時噴錯
		cin >> input;
		//迴圈結束時要輸入給下一次迴圈用
	}

	return 0;
}
