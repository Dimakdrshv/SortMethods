# SortMethods
Описание методов сортировки коллекций на языке программирования С++

ПУЗЫРЬКОВАЯ СОРТИРОВКА И ЕЁ УЛУЧШЕНИЯ

Сортировка - это некий алгоритм упорядочивания элементов коллекции определенного типа данных.

Сортировка пузырьком

Сортировка пузырьком — один из самых известных алгоритмов сортировки. Здесь нужно последовательно сравнивать значения соседних элементов и менять числа местами, если предыдущее оказывается больше последующего. Таким образом элементы с большими значениями оказываются в конце списка, а с меньшими остаются в начале.
Этот алгоритм считается учебным и почти не применяется на практике из-за низкой эффективности: он медленно работает на тестах, в которых маленькие элементы (их называют «черепахами») стоят в конце массива. Однако на нём основаны многие другие методы, например, шейкерная сортировка и сортировка расчёской.


![Пузырек](https://github.com/user-attachments/assets/55496a4f-a37a-4327-a00a-f36770dbe195)


Сортировка перемешиванием (шейкерная сортировка)

Шейкерная сортировка отличается от пузырьковой тем, что она двунаправленная: алгоритм перемещается не строго слева направо, а сначала слева направо, затем справа налево.


![Шейкер](https://github.com/user-attachments/assets/fbd8a935-3b0b-4996-b547-79df4f8f1164)


Сортировка расчёской

Сортировка расчёской — улучшение сортировки пузырьком. Её идея состоит в том, чтобы «устранить» элементы с небольшими значения в конце массива, которые замедляют работу алгоритма. Если при пузырьковой и шейкерной сортировках при переборе массива сравниваются соседние элементы, то при «расчёсывании» сначала берётся достаточно большое расстояние между сравниваемыми значениями, а потом оно сужается вплоть до минимального.
Первоначальный разрыв нужно выбирать не случайным образом, а с учётом специальной величины — фактора уменьшения, оптимальное значение которого равно 1,247. Сначала расстояние между элементами будет равняться размеру массива, поделённому на 1,247; на каждом последующем шаге расстояние будет снова делиться на фактор уменьшения — и так до окончания работы алгоритма.


![Расческа](https://github.com/user-attachments/assets/764e549a-5d4a-4901-9128-bfc526630ea5)


ПРОСТЫЕ СОРТИРОВКИ

Сортировка вставками

При сортировке вставками массив постепенно перебирается слева направо. При этом каждый последующий элемент размещается так, чтобы он оказался между ближайшими элементами с минимальным и максимальным значением.


![Вставочки](https://github.com/user-attachments/assets/bc2523fb-a093-4940-b8b5-c83160e3ee63)


Сортировка выбором

Сначала нужно рассмотреть подмножество массива и найти в нём максимум (или минимум). Затем выбранное значение меняют местами со значением первого неотсортированного элемента. Этот шаг нужно повторять до тех пор, пока в массиве не закончатся неотсортированные подмассивы.


![Выборка](https://github.com/user-attachments/assets/158c3856-8a30-4b47-8d33-ba50c7a451ec)


ЭФФЕКТИВНЫЕ СОРТИРОВКИ

Быстрая сортировка

Этот алгоритм состоит из трёх шагов. Сначала из массива нужно выбрать один элемент — его обычно называют опорным. Затем другие элементы в массиве перераспределяют так, чтобы элементы меньше опорного оказались до него, а большие или равные — после. А дальше рекурсивно применяют первые два шага к подмассивам справа и слева от опорного значения.


![Быстрая](https://github.com/user-attachments/assets/921ed2a0-876f-4595-a2ed-733eceb059ea)


![QuickSort](https://github.com/user-attachments/assets/56d9cce1-7e2c-4d55-afc4-b1328f62a776)


Сортировка слиянием

Сортировка слиянием пригодится для таких структур данных, в которых доступ к элементам осуществляется последовательно (например, для потоков). Здесь массив разбивается на две примерно равные части и каждая из них сортируется по отдельности. Затем два отсортированных подмассива сливаются в один.


![Слияние](https://github.com/user-attachments/assets/c75b7980-54be-48ff-8859-5b5e76d966f3)


Пирамидальная сортировка

При этой сортировке сначала строится пирамида из элементов исходного массива. Пирамида (или двоичная куча) — это способ представления элементов, при котором от каждого узла может отходить не больше двух ответвлений. А значение в родительском узле должно быть больше значений в его двух дочерних узлах.
Пирамидальная сортировка похожа на сортировку выбором, где мы сначала ищем максимальный элемент, а затем помещаем его в конец. Дальше нужно рекурсивно повторять ту же операцию для оставшихся элементов. 


![Кучная](https://github.com/user-attachments/assets/26ced8af-c9f7-4853-9ed7-06fdb1905b50)
