//我真的把這份交出去了，看不懂這個版本請按History，請不要衝動的把這份交出跟我同歸於盡...
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int input,limit,m,n,num;
	//input為輸入數字，limit為枚舉m之上限，
	//m,n為題目中m,n，num用於與input比較
	bool found;
	//found為一旗標，紀錄是否已找到答案
	while(cin >> input && input)
	//將cin放入控制敘述中以重複輸入，
	//並同時判斷input是否為0，若為0跳出迴圈
	{
		if(input > 0)
		//當input為正數，枚舉m,n判斷m的n次方是否與input相等
		{
			limit = sqrt(input);
			found = 0;
			//初始化，因為若有答案m不大於input開根號，
			//故只需枚舉到sqrt(input)
			for(m = 2;m <= limit && !found;++m)
			//枚舉m從2到limit，若找到答案時跳出迴圈
			{
				num = m;
				//num初始化為m，如此第一次進入迴圈將從num = m*m開始判斷
				//以符合任何時候num等於m的n次方
				for(n = 2;input % num == 0;++n)
				//對於每個m，枚舉次方n從2開始直到input不能被num(m的n次方)整除
				{
					num *= m;
					if(num == input)
					{
						found = 1;
						cout << m << " " << n << endl;
						break;
					}
					//對於每個m的n次方，將num乘上m，如此任意時刻num等於m的n次方，
					//當num與input相等時將found設為1，輸出答案並跳出內部迴圈
				}
			}
			if(!found)
				cout << "-1\n";
			//若沒有符合題意之答案輸出-1
		}
		else
			cout << "Please input a positive integer!\n";
		//當答案為負數輸出警告訊息並繼續輸入
	}
	return 0;
}
