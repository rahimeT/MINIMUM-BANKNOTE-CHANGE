#define buton5 2
#define buton10 3
#define buton20 4
#define buton50 5
#define buton100 6
#define bitis 7
#define butonK 8
#define butonY 9
#define butonKu 10
#define butonC 11
#define enter A5
#define ledK 12
#define ledY 13

int Tsabun=50,sabun=5,hizmet_adet1=30,hizmet_fiyat1=15;  //köpükleme bilgileri
int Tsu=100,su=10,hizmet_adet2=50,hizmet_fiyat2=10;   //yıkama bilgileri
int Thava=100,hava=20,hizmet_adet3=100,hizmet_fiyat3=5; //kurulama bilgileri
int Tcila=100,cila=10,hizmet_adet4=5,hizmet_fiyat4=50;  //cilalama bilgileri
int banknot5=2,banknot10=5,banknot20=2,banknot50=2,banknot100=2;  //banknot bilgileri

int kasa=banknot5*5+banknot10*10+banknot20*20+banknot50*50+banknot100*100;

int beslik=0,onluk=0,yirmilik=0,ellilik=0,yuzluk=0;
int kopukleme=0,yikama=0,kurulama=0,cilalama=0,islemler=0;
int b5=0,b10=0,b20=0,b50=0,b100=0;
long randomNumber,r;
int x=0,y=0,z=0,t=0;
int total,temp=0,temp2=0, temp3=0;
int eklenenPara,kasa2=kasa,paraustu=0;

void setup() { 

  Serial.begin(9600);  
  pinMode(buton5, INPUT);  
  pinMode(buton10,INPUT);
  pinMode(buton20,INPUT);
  pinMode(buton50,INPUT);
  pinMode(buton100,INPUT);
  pinMode(butonK, INPUT);  
  pinMode(butonY,INPUT);
  pinMode(butonKu,INPUT);
  pinMode(butonC,INPUT);
  pinMode(bitis,INPUT);
  pinMode(ledK,OUTPUT);
  pinMode(ledY,OUTPUT);
 
  Serial.print("Mevcut para:");
  Serial.println(kasa);
  Serial.println("Banknotlarınızı yükleyiniz... \n");
  digitalWrite(ledK,LOW);
  digitalWrite(ledY,LOW);
  
randomSeed(analogRead(A0));
for(int i=1;i<5;i++){
  r= random(5);
  }
randomNumber=r;
}  
void loop() {  
int butonD5 = digitalRead(buton5);  
int butonD10=digitalRead(buton10);
int butonD20=digitalRead(buton20);
int butonD50=digitalRead(buton50);
int butonD100=digitalRead(buton100);
int bitisD=digitalRead(bitis);
int butonIk=digitalRead(butonK);
int butonIy=digitalRead(butonY);
int butonIKu=digitalRead(butonKu);
int butonIc=digitalRead(butonC);
int bitisI=analogRead(enter);


if ((butonD5 == HIGH)) {  //BEŞLİK PARA ARTIRMA
 beslik+=1;
 banknot5+=beslik;   // banknot5 e atama yapıldı
 Serial.print("Toplam 5lira adedi: ");
   Serial.println(beslik); 
   while(butonD5==HIGH){
  delay(10);  
  butonD5 = digitalRead(buton5);
}
 delay(10);
}  

  if (butonD10 == HIGH) { //ONLUK PARA ARTIRMA
 onluk+=1;
 banknot10+=onluk;
 
 Serial.print("Toplam 10lira adedi: ");
   Serial.println(onluk);
   while(butonD10==HIGH){
  delay(10);  
  butonD10 = digitalRead(buton10);
}
delay(10);
}  

 if (butonD20 == HIGH) { //YİRMİLİK PARA ARTTIRMA
 yirmilik+=1;
 banknot20+=yirmilik;
 
 Serial.print("Toplam 20lira adedi: ");
   Serial.println(yirmilik);
   while(butonD20==HIGH){
  delay(10);  
  butonD20 = digitalRead(buton20);
}
delay(10);
}  


 if (butonD50 == HIGH) { //ELLİLİK PARA ARTTIRMA
 ellilik+=1;
 banknot50+=ellilik;
 
 Serial.print("Toplam 50lira adedi: ");
   Serial.println(ellilik);
   while(butonD50==HIGH){ 
  delay(10);  
  butonD50 = digitalRead(buton50);
}
delay(10);
} 


 if (butonD100 == HIGH) { //YÜZLÜK PARA ARTTIRMA
 yuzluk+=1;
 banknot100+=yuzluk;
 
 Serial.print("Toplam 100lira adedi: ");
   Serial.println(yuzluk);
   while(butonD100==HIGH){
  delay(10);  
  butonD100 = digitalRead(buton100);
}
delay(10);
}


if(bitisD==HIGH){  //TOPLAM PARA HESABI
 total=beslik*5+onluk*10+yirmilik*20+ellilik*50+yuzluk*100;

Serial.print(total);
Serial.println("lira para attiniz \n\n");
  eklenenPara=total;
while(bitisD==HIGH){
  delay(10);  
  bitisD = digitalRead(bitis);
  }

}


//-----İşlem seçimleri-------

   if(butonIk==HIGH ){
 kopukleme++;
 
   while(butonIk==HIGH){
  delay(10);  
  butonIk = digitalRead(butonK);
}
delay(10);
 Serial.print(kopukleme);
 Serial.print("kez kopukleme (köpükleme fiyatı):");
 Serial.println(hizmet_fiyat1);
  }

     if(butonIy==HIGH ){
yikama++;
   while(butonIy==HIGH){
  delay(10);  
  butonIy = digitalRead(butonY);
}
delay(10);
 Serial.print(yikama);
 Serial.print("kez yıkama (yıkama fiyatı):");
 Serial.println(hizmet_fiyat2);
  }

  if(butonIKu==HIGH ){
kurulama++;
   while(butonIKu==HIGH){
  delay(10);  
  butonIKu= digitalRead(butonKu);
}
delay(10);
 Serial.print(kurulama);
 Serial.print("kez kurulama (kurulama fiyatı):");
  Serial.println(hizmet_fiyat3);
  }
  if(butonIc==HIGH ){
cilalama++;
   while(butonIc==HIGH){
  delay(10);  
  butonIc = digitalRead(butonC);
}
delay(10);
 Serial.print(cilalama);
 Serial.print("kez cilalama (cilalama fiyatı):");
  Serial.println(hizmet_fiyat4);
  }

  

  if(bitisI>1000 &&temp==0){

 kasa+=total;
   temp++; // bitiş butonunu reset butonu olarak kullanmak için gereken tutucu
if(kopukleme!=0){
Serial.print(kopukleme);
  Serial.println("kez kopukleme işlemi yapılacaktır");
  delay(2000);}

while(Tsabun>0 && (kopukleme*sabun)>0 && hizmet_adet1>0 && total>0){
  Tsabun-=sabun;
  kopukleme--;
  x++;
  hizmet_adet1--;
  total-=hizmet_fiyat1;
  
  } 
  if(Tsabun<sabun){
    Serial.println("Yetersiz ürün!! (Sabun ekleyiniz)");
    }
    if(x>0){
  Serial.print(x);
  Serial.println(" kez köpüklendi.");
  Serial.print("\nkalan paranız: ");
  Serial.println(total);}
  kasa-=x*hizmet_fiyat1;
 
if(yikama>0){
  Serial.print(yikama);
Serial.println(" kez yıkama işlemi yapılacaktır ");
delay(2000); }

while(Tsu>0 && (yikama*su)>0 && hizmet_adet2>0 && total>0 ){
  Tsu-=su;
  yikama--;
  y++;
  hizmet_adet2--;
  total-=hizmet_fiyat2;
  }
  if(Tsu<su){
    Serial.println("Yetersiz ürün!!");
    }
    if(y){
  Serial.print(y);
  Serial.println(" kez yıkandı.");
  Serial.print("\nkalan paranız: ");
  Serial.println(total);
   kasa-=y*hizmet_fiyat2;
  
    }
if(kurulama!=0){  
Serial.print(kurulama);
  Serial.println(" kez kurulama işlemi yapılacaktır ");
  delay(2000);}

while(Thava>0 && (kurulama*hava)>0 && hizmet_adet3>0 && total>0){
  Thava-=hava;
  kurulama--;
  z++;
  hizmet_adet3--;
  total-=hizmet_fiyat3;
  }
  if(Thava<=hava){
    Serial.println("Yetersiz ürün!!");
    }
    if(z>0){
  Serial.print(z);
  Serial.println("kez kurulandı.");
  Serial.print("\nkalan paranız: ");
  Serial.println(total);
   kasa-=z*hizmet_fiyat3;
 
    }


if(cilalama!=0){
  Serial.print(cilalama);
Serial.println(" kez cilalama işlemi yapılacaktır");
delay(2000);
}

while(Tcila>0 && total-50>=0 && (cilalama*cila)>0 && hizmet_adet4>0 ){
  Tcila-=cila;
  cilalama--;
  t++;
  hizmet_adet4--;
  total-=hizmet_fiyat4;
  }if(Tcila<=cila){
    Serial.println("Yetersiz ürün!!");
    }
    if(hizmet_adet4<=0){
      Serial.println("\nHİZMET ADET AŞIMI\n");
      }
      if(t>0){
  Serial.print(t);
  Serial.println(" kez cilalandı.");
  Serial.print("\nkalan paranız: ");
  Serial.println(total);
   kasa-=t*hizmet_fiyat4;
  
      }
if(total!=0){ 
  
  Serial.println("\nPARA ÜSTÜNÜZ HAZIRLANIYOR... :D");
  
  }else{
    Serial.println("PARA ÜSTÜNÜZ BULUNMAMAKTADIR...\n\n");
    }
 
while(total>0){
   
    b100=total/100;
    total=total-(b100*100);
      b50=total/50;
      total=total-(b50*50);
     b20=total/20;
      total=total-(b20*20);
      b10=total/10;
      total=total-(b10*10);
      b5=total/5;
      total=total-(b5*5);
  }
  if(kasa<total){
    Serial.println("PARA ÜSTÜ İÇİN YETERSİZ BAKİYE");
    }
if(b100!=0){
  if(banknot100<=b100){
    
   Serial.println("100lük banknot bulunmamaktadır.");
      b50+=(b100*100)/50;
    }else {
      Serial.print(b100);
    Serial.println(" adet 100lük banknot");
    banknot100-=b100;
    kasa-=(b100*100);
     
      }
}if(b50!=0){
 if(banknot50<=b50){
  Serial.println("50 lik banknot bulunmamaktadır.");
  if((b50*50)%20!=0){
    int i=(b50*50)/20;
    b10+=((b50*50)-(i*20))/10;
    b20+=i;
    }else{
      b20+=(b50*50)/20;
      }
 }else{
    Serial.print(b50);
    Serial.println(" adet 50lik banknot");
   banknot50-=b50;
   
    kasa-=(b50*50);
   
    }
   }
  if(b20!=0){
   if(banknot20<b20){
    Serial.println("20lik banknot bulunmamaktadır.");
    
    int j=(b20*20)/10;
    b5+=((b20*20)-(j*10))/5;
    b10+=j;
   }else
    {
      
    Serial.print(b20);
    Serial.println(" adet 20lik banknot");}
    banknot20-=b20;
    kasa-=(b20*20);
    }
   if(b10!=0){
    if(banknot10<b10){
      Serial.println("10luk banknot bulunmamaktadır.");
      b5+=((b20*20)+(b10*10))/5; 
      }else{
          Serial.print(b10);
    Serial.println(" adet 10luk banknot");
    banknot10-=b10;
    kasa-=(b10*10);
        }
    }
   if(b5!=0){
    if(banknot5<b5){
      Serial.println("5lik banknot bulunmamaktadır.");
      
      }else{ 
        Serial.print(b5);
    Serial.println(" adet 5lik banknot");
    banknot5-=b5;
    kasa-=(b5*5);
        }
    
    }
   
   while(bitisI>1000){
  delay(10);  
  bitisI = analogRead(enter);
}delay(10);

 }

    if(bitisI>1000 && temp!=0){  // Çoklu kişi işlemi için işlem yenileme
      
beslik=0,onluk=0,yirmilik=0,ellilik=0,yuzluk=0;
kopukleme=0;
yikama=0;
kurulama=0;
cilalama=0;
x=0,y=0,z=0,t=0; 
temp=0;
 Serial.println("\n");
randomSeed(analogRead(A0));
for(int i=1;i<5;i++){
  r= random(5);
  }
randomNumber=r;
         while(bitisI>1000){
  delay(10);  
  bitisI = analogRead(enter);
}delay(10);
    }

//LED YAKMA

if(randomNumber==2 && eklenenPara!=0 &&temp!=0 ){
  randomNumber=5;
  digitalWrite(ledK,HIGH);
  digitalWrite(ledY,LOW);
  Serial.println("\n\n PARA SIKIŞMA DURUMU !!");
Serial.print("!! PARA İADESİ :  ");
Serial.println(eklenenPara);
beslik=0,onluk=0,yirmilik=0,ellilik=0,yuzluk=0;
kopukleme=0;
yikama=0;
kurulama=0;
cilalama=0;
x=0,y=0,z=0,t=0; 

Serial.println("\nSeçimler resetlendi");

randomSeed(analogRead(A0));
for(int i=1;i<5;i++){
  r= random(5);
  }
randomNumber=r;
  temp=0;

}if(randomNumber!=2 && randomNumber!=5 && eklenenPara !=0 &&temp!=0 )
{
  digitalWrite(ledY,HIGH);
  digitalWrite(ledK,LOW);
  }
}
