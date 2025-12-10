# **Devlog Pathfinding — Elbert Joan**

## *1. Overview*

Project ini merupakan eksplorasi mendalam terhadap berbagai algoritma pathfinding yang diimplementasikan secara manual menggunakan bahasa C. Fokus utama bukan hanya menghasilkan output yang benar, tetapi memahami logika, proses, dan alur berpikir di balik tiap algoritma.


Dokumentasi ini berisi rangkuman progres harian, eksperimen, serta pemahaman yang diperoleh selama mempelajari pathfinding. Tujuannya adalah membangun fondasi yang kuat tentang bagaimana algoritma pencarian jalur bekerja di dalam grid maze.

---

## *2. Progress*

### **25 November 2025 — Eksplorasi Awal**

Pada hari pertama, fokus saya adalah memahami konsep dasar pathfinding dan mengenal berbagai algoritma pencarian jalur. Saya juga memastikan algoritma mana saja yang diperbolehkan dan mana yang tidak (A* dan Dijkstra termasuk yang tidak boleh digunakan pada tugas ini).

Setelah itu, saya mulai langsung membuat prototipe awal—sebuah pendekatan sederhana yang awalnya terinspirasi dari flood fill. Setelah dilakukan beberapa penyesuaian, pendekatan ini ternyata berperilaku sangat mirip dengan DFS (Depth First Search).

Tahap yang dikerjakan:

- Menyusun struktur dasar program  
- Membuat maze awal dan mendefinisikan simbol:
  - `E` = Path (ruang kosong yang bisa dilalui)
  - `$` = Target
  - `#` = Wall
  - `*` = Traceback (jalur yang ditemukan)
- Mengimplementasikan pergerakan menggunakan rekursi  
- Melakukan uji coba untuk melihat bagaimana karakter bergerak di dalam maze  

Catatan singkat mengenai DFS:  
DFS menelusuri suatu cabang sedalam mungkin sebelum kembali (backtrack) untuk mencoba cabang lain.  
Kelebihan: simpel.  
Kekurangan: sering tersesat, tidak mencari jalur optimal.

Pada tahap ini, algoritma masih “belum cerdas”—DFS hanya mencari jalur apa pun yang memungkinkan. Bahkan salah satu percobaan membutuhkan waktu hingga hampir 100 detik.

---

### **28 November 2025 — Analisis Perubahan Movement pada DFS**

Fokus hari ini adalah menguji bagaimana perubahan urutan movement mempengaruhi hasil DFS.  
Saya menyadari terdapat total 24 kombinasi arah (permutasi movement), dan setiap kombinasi bisa menghasilkan jalur yang berbeda.

Hasil eksperimen (di folder `OutputDFS`) menunjukkan:

- DFS tidak dirancang untuk mencari jalur terpendek  
- Perubahan kecil pada urutan arah dapat mengubah hasil pencarian secara signifikan  
- DFS hanya mencari “jalur pertama yang ditemukan”  

Kesimpulan: meskipun DFS mudah diimplementasikan, algoritma ini kurang cocok untuk pathfinding yang membutuhkan efisiensi atau optimalitas.

---


### **30 November 2025 — Implementasi BFS**

Setelah mengamati keterbatasan DFS dan keunggulan A*, saya mulai mengimplementasikan BFS (Breadth-First Search).

BFS menelusuri grid secara melebar (layer by layer), bukan mendalam seperti DFS.

Mekanisme BFS :
- Periksa semua tetangga dekat dulu
- Baru lanjut ke tingkat berikutnya
- Dijamin menemukan jalur terpendek (shortest path) jika bobot sama
  
Keunggulan BFS:

- Menjamin menemukan jalur terpendek pada grid tanpa bobot  
- Perilaku stabil dan konsisten  
- Struktur algoritma lebih sederhana dibanding A*  

Hasil percobaan menunjukkan BFS sangat cocok untuk kasus maze klasik yang tidak memiliki bobot.
Algoritma.
Dapat disimpulkan kalau BFS merupakan algoritma search klasik yang sering digunakan sebagai komponen dalam sistem Artificial Intelligence

---

## *3. Kesimpulan*

Periode 25–30 November memberikan pemahaman menyeluruh mengenai cara kerja algoritma pathfinding:

- **DFS**  
  Simpel dan mudah diterapkan, namun tidak mencari jalur optimal.

- **BFS**  
  Memberikan jalur terpendek pada grid tanpa bobot dan sesuai dengan syarat tugas.

Selain itu, eksperimen membuktikan bahwa perubahan kecil pada prioritas arah movement dapat menghasilkan jalur yang berbeda secara drastis—terutama pada DFS.

Proses ini membantu membangun pemahaman mendalam tentang bagaimana algoritma pathfinding bekerja, bagaimana menilai kelemahan dan kelebihannya, serta bagaimana merancang solusi yang lebih pintar.
