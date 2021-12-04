# 2021-OSProje
## 2021 Güz Dönemi SAU Bilgisayar Mühendisliği İşletim Sistemleri Projesi
__*Bir dizi yerleşik işlevin (buit-in functions) yürütülmesini ve diğer proseslerin çalıştırılmasını sağlayan temel bir robust kabuk(shell).*__
<br>
*__MAX__ 80 Karakter ve 10 Argüman ile çalışmaktadır.*
## Grup Üyeleri
|Şube|Öğrenci No|Ad Soyad                |
|----|----------|------------------------|
|1C  |B181210036 |Mert Şenyıldız         |
|1B  |B181210089 |Fatih Abidin Silan     |
|1C  |B181210060 |Yasin Ağa              |
|1B  |G191210401 |Aslı Sakarya           |
|1C  |B181210075 |Abdulvahit Müjdat Camlı|
## Dosya ve Dizinler
* [__bin__](https://github.com/MertSenyildiz/2021-OSProje/tree/master/bin) : *Derlenmiş Programın bulunduğu dizin*
  + [bash](https://github.com/MertSenyildiz/2021-OSProje/tree/master/bin/bash) : *Kabuk çalıştırabilir dosya*
* [__include__](https://github.com/MertSenyildiz/2021-OSProje/tree/master/include) : *Library headerları'nın bulunduğu dizin*
  + [bash.h](https://github.com/MertSenyildiz/2021-OSProje/tree/master/include/bash.h) : *Kabuk library header dosyası*
* [__lib__](https://github.com/MertSenyildiz/2021-OSProje/tree/master/lib) : *Derlenmiş library nesnelerinin bulunduğu dizin*
  + [bash.o](https://github.com/MertSenyildiz/2021-OSProje/tree/master/lib/bash.o) : *Kabuk derlenmiş library dosyası*
* [__src__](https://github.com/MertSenyildiz/2021-OSProje/tree/master/src) : *Kaynak kodlarının bulunduğu dizin*
  + [program.c](https://github.com/MertSenyildiz/2021-OSProje/tree/master/src/program.c) : *Kabuk program kaynak kodları dosyası*
  + [bash.c](https://github.com/MertSenyildiz/2021-OSProje/tree/master/src/bash.c) : *Kabuk library kaynak kodları dosyası*
* [__makefile__](https://github.com/MertSenyildiz/2021-OSProje/tree/master/makefile) : *Proje makefile*
## Derleme Talimatları
*Proje derleyici olarak __gcc__ kullanmaktadır.*
* __MAKEFILE__ kullanarak derleme
```bash
  make 
```
* Alternatif yöntem
 ```bash
  gcc -I ./include -c ./src/bash.c -o ./lib/bash.o
  gcc -I ./include -o ./bin/bash -s ./src/program.c ./lib/bash.o
 ```
 ## Çalıştırma Talimatları
 *Kabuk başarılı bir şekilde derlendikten sonra*
 ```bash
  ./bin/bash
```
## Geliştirme Sırasında Karşılaşılan Zorluklar
## Proje Geliştirilirken Kullanılan Kaynaklar

  
