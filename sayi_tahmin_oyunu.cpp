#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int tahmin,pc=0,oyuncu=0,hak=10,i,kontrol,sayi,karar;
  int kucuktahmin=100,buyuktahmin=1000,eskitahmin;
  srand(time(0));

  yeniden:
  printf("**SAYI TUTMA OYUNUNA HOSGELDINIZ**\n");
  printf("Aklinizdan bir sayi tutunuz.\n\n");

  for(i=0; i<hak ; i++)
  {
    tahmin = kucuktahmin + rand()%(buyuktahmin-kucuktahmin);
    printf("%d.Tahmin edilen sayi:%d\nSecenek giriniz->dogru:1 kucuk:2 buyuk:3\n",i+1,tahmin);
    scanf("%d",&kontrol);

    if(kontrol == 1)
      {
        pc++;
        printf("Bilgisayar oyunu kazandi.\n");
        printf("Skor->bilgisayar:%d oyuncu:%d\n",pc,oyuncu);
        printf("Devam etmek istiyor musunuz? evet(1)/hayir(0)");
        scanf("%d",&karar);
          if(karar)
            goto yeniden;
          else
          {
          printf("Oyun sonlandirildi.");
          return 0;
          }
      }

      else if(kucuktahmin == buyuktahmin ||  tahmin == kucuktahmin || tahmin == buyuktahmin) // hata kontolu
      {
        printf("HATA! cevaplarinizda uyumsuzluk oldugu icin oyun sonlandirilmistir");
        return 0;
      }

      else if(kontrol == 2)
        {
          kucuktahmin = tahmin;
          continue;
        }

      else if(kontrol == 3)
        {
          buyuktahmin = tahmin;
          continue;
        }
      eskitahmin = tahmin; // hata kontolu

  }
  printf("Bilgisayarin tahmin hakki kalmadi.Tutmus oldugunuz sayiyi giriniz");
  scanf("%d",&sayi);
  if(sayi<kucuktahmin || sayi > buyuktahmin)
  {
    printf("vermis oldugunuz hatali cevaplardan dolayi oyun sonlandirilmistir.");
    return 0;
  }

  oyuncu++;
  printf("tebrikler kazandiniz.");
  printf("skor->bilgisayar:%d oyuncu:%d\n",pc,oyuncu);
  printf("devam etmek istiyor musunuz? evet(1)/hayir(0)");
  scanf("%d",&karar);
    if(karar)
      goto yeniden;
    else
    {
    printf("oyun sonlandirildi.");
    return 0;
    }




  return 0;
}
