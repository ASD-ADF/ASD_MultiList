# ASD_MultiList
Example for Multi-Linked List in Cpp

# Multi-Linked List

## Pengenalan Multi-linked List
selama ini kalian sudah belajar mengimplementasikan 3 tipe linked list:
* single list
* double list
* circular list (single dan double)
sekarang, kita akan belajar bagaimana menghubungkan beberapa linked list sehingga membentuk suatu relasi yang dinamakan multi-linked list

secara umum, multi-linked list merepresentasikan hubungan/relasi data parent-child. bentuk lain yang bisa direpresentasikan multilinked list adalah representasi Tree dan Graph. Bentuk linked list parent dan child adalah sama seperti bentuk list sebelumnya, untuk menghubungkan kedua list, hanya diperlukan modifikasi di sebagian kodenya. Yang perlu diperhatikan di multi linked list adalah pada saat delete parent, node parent harus dipastikan tidak memiliki child
sebagai dasar dari representasi database, linked list juga dapat merepresentasikan hubungan 1-1, 1-n dan n-m

Seluruh contoh hanya diberikan InsertFirst dengan Parent adalah single-circular infotype integer dan Child adalah double infotype string

### Bentuk I (relasi 1-N)
multi-linked list bentuk I digunakan untuk merepresentasikan dan menjamin hubungan 1-n
contoh relasi : Mahasiswa (child) - Kelas (parent)
bentuk relasi : pointer parent di element child
pro : 
* menjamin hubungan 1-n
con :
* perlu prosedur untuk menghubungkan dan memutus relasi (mudah)
* perlu prosedur mencari child dari suatu parent
* proses pengecekan sebelum menghapus parent susah


### Bentuk II (relasi 1-N dan M-N)
multi-linked list bentuk II digunakan untuk merepresentasikan hubungan 1-n dan juga m-n namun tidak menjamin kedua hubungan
contoh relasi : Pegawai (parent) - Daftar Anak (child)
bentuk relasi : list child di elemen parent
pro : 
* menghubungkan dan memutus relasi lebih mudah
con : 
* tidak menjamin hubungan 1-n dan m-n
* perlu prosedur untuk menacari suatu child
* jika hubungan m-n, proses edit child susah


### Bentuk III (relasi M-N)
multi-linked list bentuk III digunakan untuk merepresentasikan dan menjamin hubungan m-n
contoh relasi : Dosen (parent) - Mahasiswa (child)  --> bisa dibalik
bentuk relasi : list relasi
pro : 
* menjamin hubungan m-n
con : 
* perlu list tambahan (list relasi)


### Bentuk IV (relasi 1-1)
multi-linked list bentuk IV digunakan untuk merepresentasikan dan menjamin hubungan 1-1
contoh relasi : Orang (parent) - Passport (child)
bentuk relasi : pointer parent di elemen child dan pointer child di elemen parent