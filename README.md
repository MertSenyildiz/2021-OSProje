# 2021-OSProje
## 2021 Güz Dönemi SAU Bilgisayar Mühendisliği İşletim Sistemleri Projesi
__*Bir dizi yerleşik işlevin (buit-in functions) yürütülmesini ve diğer proseslerin çalıştırılmasını sağlayan temel bir robust kabuk(shell).*__
<br>
*__MAX__ 80 Karakter ve 10 Argüman ile çalışmaktadır.*
<br>
|Distro|Shell                                                                                                           |Built-in cd|Built-in exit|Built-in showpid|
|------|----------------------------------------------------------------------------------------------------------------|-----------|-------------|----------------|
|Fedora|![Fedora](https://user-images.githubusercontent.com/63149243/145039032-be00fdc2-7245-4696-836c-49b718c1fba2.png)|![Fedora](https://user-images.githubusercontent.com/63149243/145039034-b86daab8-9f11-4f9e-b69a-5c45c3d1db66.png)|![Fedora](https://user-images.githubusercontent.com/63149243/145039037-44c0f245-d00f-4e58-bc02-a1a5f4a34ae9.png)|![Fedora](https://user-images.githubusercontent.com/63149243/145646022-0ae70b5e-bd4a-4764-816d-3dbb2a9ae7d6.png)|
|Ubuntu|![Ubuntu](https://user-images.githubusercontent.com/62845685/145042391-2b2b9804-55e7-4d9e-9107-3d7b626e5b6d.png)|![Ubuntu](https://user-images.githubusercontent.com/62845685/145042396-d49f425f-75ee-4ffc-85e4-d402e49d9647.png)|![Ubuntu](https://user-images.githubusercontent.com/62845685/145042397-728faf6b-d36d-4a34-94c1-22c00459e181.png)|![Ubuntu](https://user-images.githubusercontent.com/62845685/145681088-4bcd8d9a-7c89-437d-b8eb-d1fac933b832.png)|
|Pop!_OS|![Pop!_OS](https://user-images.githubusercontent.com/63149243/145647919-1d1bc37d-b770-4438-a38d-31c15d774e8b.png)|![Pop!_OS](https://user-images.githubusercontent.com/63149243/145647910-2537e8df-e7bd-4632-b372-459a8460a514.png)|![Pop!_OS](https://user-images.githubusercontent.com/63149243/145647913-abdde28d-c1e5-4703-b6b5-2101f946f2f6.png)|![Pop!_OS](https://user-images.githubusercontent.com/63149243/145647915-e4f05540-b2ff-4061-bd57-3c1ff1bc494f.png)|

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
> __Built-in showpid fonksiyonunun zombi process bırakmakdan gerçeklenmesi proje'nin geliştrilimesi sırasında karşılaşılan en büyük zorluktu.__
> <br>
> *Problem*:
> <br>
> Kabuk tarafından oluşturulmuş en az 5 aktif yavru proses PID’sinin ekrana yazdırılması.
> <br>
> *Çözüm*:
> 1. __&__ sembolü eklenen tüm komutlar'ı arkaplanda çalıştıracak *runBackground* fonksiyonu yazıldı.
> 2. Arkaplanda çalışacak processlerin çıkış yaptığında veya yok edildiğinde zombi'ye dönüşmemeleri için *runBackground* fonkisyonu içerisinde __SIGCHLD__ sinyali yakalandı ve parent process tarafından beklenmesi sağlandı.
> 3. Kabuk ilk açıldığında *runBackground* fonksiyonu ile arkaplanda 5 yavru process oluşturuldu.
> 4. Bu processlerin PID'leri bir diziye eklendi.
> 5. Daha sonrasında açılan tüm processlerin PID'leri de bu diziye dahil edildi.
> 6. Showpid fonksiyonunda bu dizideki processlerin durumları kontrol edildi ve aktif olarak çalışmakta olan processler ekrana yazdırıldı.
## Proje Geliştirilirken Kullanılan Kaynaklar
> https://man7.org/linux/man-pages/man2/sigaction.2.html
> <br>
> https://linux.die.net/man/2/waitpid
> <br>
> https://www.cplusplus.com/reference/cstring/strtok/
> <br>
> https://www.qnx.com/developers/docs/6.5.0SP1.update/com.qnx.doc.neutrino_lib_ref/e/execvp.html
> <br>
> https://man7.org/linux/man-pages/man2/chdir.2.html
> <br>
> https://www.cplusplus.com/reference/cstring/memset/

