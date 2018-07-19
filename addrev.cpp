#include <stdio.h>

int rev( int num ) {
	int reved = num % 10, k = 10;
	num = num / 10;

	while ( num != 0 ) {
		reved = ( reved * k ) + ( num % 10 );
		num = num / 10;
	}

	return reved;
}

int main()
{
    int n,a,b;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);

        a=rev(a);
        b=rev(b);

        int sum = a+b;

        sum = rev(sum);

        printf("%d\n",sum);

    }


}
