Devlog Pathfinding — Elbert Joan
1. Overview

Project ini merupakan eksplorasi mendalam terhadap berbagai algoritma pathfinding yang diimplementasikan secara manual menggunakan bahasa C. Fokus utama bukan hanya menghasilkan output yang benar, tetapi memahami logika, proses, dan alur berpikir di balik tiap algoritma.

Seperti yang ditekankan oleh ko David:
“Progress lebih penting daripada hasil akhir.”

Dokumentasi ini berisi rangkuman progres harian, eksperimen, serta pemahaman yang diperoleh selama mempelajari pathfinding. Tujuannya adalah membangun fondasi yang kuat tentang bagaimana algoritma pencarian jalur bekerja di dalam grid maze.

2. Progress
25 November 2025 — Eksplorasi Awal

Pada hari pertama, fokus saya adalah memahami konsep dasar pathfinding dan mengenal berbagai algoritma pencarian jalur. Saya juga memastikan algoritma mana saja yang diperbolehkan dan mana yang tidak (A* dan Dijkstra termasuk yang tidak boleh digunakan pada tugas ini).

Setelah itu, saya mulai langsung membuat prototipe awal—sebuah pendekatan sederhana yang awalnya terinspirasi dari flood fill. Setelah dilakukan beberapa penyesuaian, pendekatan ini ternyata berperilaku sangat mirip dengan DFS (Depth First Search).

Tahap yang dikerjakan:

Menyusun struktur dasar program

Membuat maze awal dan mendefinisikan simbol:

E = Path (ruang kosong yang bisa dilalui)

$ = Target

# = Wall

* = Traceback (jalur yang ditemukan)

Mengimplementasikan pergerakan  menggunakan rekursi

Melakukan uji coba untuk melihat bagaimana karakter bergerak di dalam maze

Catatan singkat mengenai DFS:
DFS menelusuri suatu cabang sedalam mungkin sebelum kembali (backtrack) untuk mencoba cabang lain.
Kelebihan: simpel.
Kekurangan: sering tersesat, tidak mencari jalur optimal.

Pada tahap ini, algoritma masih “belum cerdas”—DFS hanya mencari jalur apa pun yang memungkinkan. Bahkan salah satu percobaan membutuhkan waktu hingga hampir 100 detik.

28 November 2025 — Analisis Perubahan Movement pada DFS

Fokus hari ini adalah menguji bagaimana perubahan urutan movement mempengaruhi hasil DFS.
Terdapat total 24 kombinasi arah (permutasi movement), dan setiap kombinasi menghasilkan jalur yang berbeda.

Dari eksperimen (terdokumentasi dalam folder OutputDFS):

DFS tidak dirancang untuk mencari jalur terpendek

Perubahan kecil pada urutan arah sangat mempengaruhi jalur hasil pencarian

DFS hanya mencari “jalur pertama yang ditemukan”

Kesimpulan: meskipun DFS mudah diimplementasikan, algoritma ini tidak ideal untuk pathfinding yang memerlukan efisiensi atau optimalitas.

29 November 2025 — Eksperimen dengan A*

Walaupun A* tidak diperbolehkan dalam konteks tugas, saya memutuskan untuk tetap mempelajarinya agar memahami perbedaan kualitas algoritma.

A* menggunakan heuristik (contohnya Manhattan distance) untuk mengestimasi jarak ke target, sehingga mampu memilih jalur yang lebih menjanjikan. Implementasi awal A* langsung menunjukkan perbedaan drastis dibanding DFS: lebih cepat, lebih terarah, dan jalurnya lebih optimal.

Eksperimen ini memberikan pemahaman yang sangat berharga mengenai bagaimana algoritma “cerdas” bekerja.

30 November 2025 — Implementasi BFS

Setelah memahami kelebihan dan kekurangan DFS serta mengenal efisiensi A*, saya mulai mengimplementasikan BFS (Breadth-First Search).

BFS bekerja dengan menelusuri grid “secara melebar”, bukan mendalam seperti DFS.

Keunggulan utama BFS:

Dijamin menemukan jalur terpendek pada grid tanpa bobot

Stabil dan sangat cocok untuk kasus-kasus maze sederhana

Lebih mudah dipahami dibanding A*

Hasil percobaan BFS menunjukkan pencarian jalur yang optimal dan konsisten—tepat sesuai dengan karakteristiknya.

3. Kesimpulan

Periode 25–30 November memberikan pemahaman menyeluruh terhadap perilaku beberapa algoritma pathfinding:

DFS
Mudah diimplementasikan namun tidak mencari jalur optimal.

BFS
Cocok untuk kasus grid tanpa bobot, memberikan jalur terpendek, dan diperbolehkan dalam tugas.

A*
Sangat efisien dan terarah berkat heuristik, namun tidak diperbolehkan dalam konteks tugas.

Selain itu, eksperimen menunjukkan bahwa perubahan kecil pada prioritas movement dapat menghasilkan rute yang sepenuhnya berbeda, terutama pada DFS.

Proses ini memberikan pemahaman mendalam mengenai bagaimana algoritma pathfinding bekerja, bagaimana membuatnya lebih cerdas, dan bagaimana memilih metode yang tepat untuk konteks tertentu.