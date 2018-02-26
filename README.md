# ASD_MultiList
Example for Multi-Linked List in Cpp

# Multi-Linked List

## Pengenalan Multi-linked List
selama ini kalian sudah belajar mengimplementasikan 3 tipe linked list:
* single list
* double list
* circular list (single dan double)

sekarang, kita akan belajar bagaimana menghubungkan beberapa linked list sehingga membentuk suatu relasi yang dinamakan multi-linked list

secara umum, multi-linked list merepresentasikan hubungan/relasi data parent-child. <br>
Bentuk lain yang bisa direpresentasikan multilinked list adalah representasi Tree dan Graph.  <br>
Bentuk linked list parent dan child adalah sama seperti bentuk list sebelumnya, untuk menghubungkan kedua list, hanya diperlukan modifikasi di sebagian kodenya.  <br>
Yang perlu diperhatikan di multi linked list adalah pada saat delete parent, node parent harus dipastikan tidak memiliki child <br>
Sebagai dasar dari representasi database, linked list juga dapat merepresentasikan hubungan 1-1, 1-n dan n-m<br>

Seluruh contoh hanya diberikan InsertFirst dengan Parent adalah single-circular infotype integer dan Child adalah double infotype string<br>

### Bentuk I (relasi 1-N)
![01](https://user-images.githubusercontent.com/13241336/36650938-af7d7db4-1ad8-11e8-8a4d-43d83672f50f.png)<br>
multi-linked list bentuk I digunakan untuk merepresentasikan dan menjamin hubungan 1-n <br>
contoh relasi : Mahasiswa (child) - Kelas (parent)<br>
bentuk relasi : pointer parent di element child<br>
pro : <br>
* menjamin hubungan 1-n

con :<br>
* perlu prosedur untuk menghubungkan dan memutus relasi (mudah)
* perlu prosedur mencari child dari suatu parent
* proses pengecekan sebelum menghapus parent susah


### Bentuk II (relasi 1-N dan M-N)
![02](https://user-images.githubusercontent.com/13241336/36650940-b11585f4-1ad8-11e8-9d76-7453248717b0.png)<br>
multi-linked list bentuk II digunakan untuk merepresentasikan hubungan 1-n dan juga m-n namun tidak menjamin kedua hubungan<br>
contoh relasi : Pegawai (parent) - Daftar Anak (child)<br>
bentuk relasi : list child di elemen parent<br>
pro : <br>
* menghubungkan dan memutus relasi lebih mudah

con : <br>
* tidak menjamin hubungan 1-n dan m-n
* perlu prosedur untuk menacari suatu child
* jika hubungan m-n, proses edit child susah


### Bentuk III (relasi M-N)
![03](https://user-images.githubusercontent.com/13241336/36650941-b240fd3c-1ad8-11e8-98ac-3b67ff175467.png)<br>
multi-linked list bentuk III digunakan untuk merepresentasikan dan menjamin hubungan m-n<br>
contoh relasi : Dosen (parent) - Mahasiswa (child)  --> bisa dibalik<br>
bentuk relasi : terdapat list ketiga sebagai list relasi<br>
pro : <br>
* menjamin hubungan m-n

con : <br>
* perlu list tambahan (list relasi)

### Bentuk III-B (relasi M-N)
![03b](https://user-images.githubusercontent.com/13241336/36650943-b360956a-1ad8-11e8-93ae-8ad52dce284b.png)<br>
multi-linked list bentuk III digunakan untuk merepresentasikan dan menjamin hubungan m-n<br>
Perbedaan bentuk multi-linked list bentuk IIIB dengan sebelumnya adalah bahwa list relasi merupakan child list dari elemen parent<br>
contoh relasi : Dosen (parent) - Mahasiswa (child)  --> bisa dibalik<br>
bentuk relasi : terdapat list ketiga sebagai list relasi yang berada di dalam List parent<br>
pro : <br>
* menjamin hubungan m-n

con : <br>
* perlu list tambahan (list relasi)


### Bentuk IV (relasi 1-1)
multi-linked list bentuk IV digunakan untuk merepresentasikan dan menjamin hubungan 1-1<br>
contoh relasi : Orang (parent) - Passport (child)<br>
bentuk relasi : pointer parent di elemen child dan pointer child di elemen parent<br>
