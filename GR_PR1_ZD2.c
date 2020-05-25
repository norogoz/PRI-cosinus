#include<stdio.h>
#include<math.h>

// Grzegorz Norbert Rogoziński, grupa 1I5, projekt 1, zadanie 2.
// Program służący do wyznaczenia możliwie dokładnego przybliżenia wartości funkcji cosinus
// na podstawie wzoru Maclaurina przy danym x (kąt) i e (rząd dokładności);

double simplify (double x)		// Funkcja redukująca x o wielokrotność 2pi
{
	int am;
	am=(int)(x/(2*M_PI));
	x=(double)(x-am*2*M_PI);
	return x;
}

double cosx(double x, double e)
{
	if((x<-20.0)||(x>20.0)) x=simplify(x);		// Uproszczenie zbyt dużych x
	
	int n=2;
	double a1, sum, an;
	a1=an=sum=1.0;
	
	do
	{
		an=((-a1)*(pow(x,2)))/((2*n-3)*(2*n-2));		// Obliczanie kolejnych wyrazów szeregu i sumowanie ich,
		sum+=an;										// gdzie an - aktualny wyraz, a1 - wyraz poprzedni
		a1=an;
		n++;
	}while(fabs(an)>e);
	
	return sum;
} //cosx

int main()
{
	puts("Projekt nr 1, zadanie 2. \nGrzegorz Norbert Rogozinski, grupa 1I5.\nProgram obliczajacy wartosc funkcji cosinus przy danym argumencie x i dokladnosci e.");
	
	double x, e;
	double value;
	char prompt;
	int i;
	
	do		// Zapętlenie programu dopóki użytkownik go nie zakończy
	{		
		puts("\nPodaj wartosci x i e. \nPodanie wartosci e mniejszej od 1e-15 nie zwieksza dokladnosci obliczen.");
		
		do		// Pętle wczytujące wartość x i rząd dokładności tak długo, aż wpisane dane będą poprawne
		{
			printf("x=");
			
			i=scanf("%lf", &x);
			while((getchar())!='\n');
			
			if(i!=1) puts("Bledna wartosc x.");
			else if(x>1e9) puts("Podaj mniejsza wartosc");		// Ograniczenie przyjmowanych wartosci do przedzialu <-1e9; 1e9>
			else if(x<-1e9) puts("Podaj wieksza wartosc");
		}while(i!=1||x<-1e9||x>1e9);
		
		do
		{
			printf("e=10^-");
			
			i=scanf("%lf", &e);
			while((getchar())!='\n');
			
			if(i!=1) puts("Bledna wartosc e.");
			else if(e>1e9) puts("Podaj mniejsza wartosc");		// Ograniczenie przyjmowanych wartosci do przedzialu <0; 1e9>
			else if(e<0) puts("Podaj wartosc wieksza od 0");
		}while(i!=1||e<0||e>1e9);
		
		e=pow(10, -e);
		
		value=cosx(x,e);		// Przypisanie i wypisanie wyniku obliczen
		printf("cos(x)=%1.17lf\n", value);
		
		if(value==cosx(x,e/100)) puts("Jest to najdokladniejsza wartosc funkcji, jaka potrafie obliczyc dla tego x.\n");		// Badanie zbieżności rozwinięcia
		else puts("Zmniejsz e, aby zwiekszyc dokladnosc.\n");																 
		
		puts("Jeszcze raz?\nt - tak\ndowolny inny znak - zakoncz");					
		
		scanf("%c", &prompt);									
		
	}while((prompt=='T')||(prompt=='t'));
	
	return 0;
}