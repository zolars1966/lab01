# Лабораторная работа №1

## 1. Определения

- *Исполняемый файл* (исполняемый код) — файл, содержащий программу в виде набора элементарных инструкций, которая после загрузки в память может быть выполнена на определенном физическом устройстве (процессоре) под управлением опредленной операционной системы.
- *Ассемблер* — язык программирования низкого уровня, в котором каждая инструкция физического устройства представлена в текстовом виде.
- Программа написанная на языке высокого уровня называется
*исходным кодом*.
- *Виртуальная машина* — это средство описания семантики языка
программирования.
- *Стандарт языка программирования* — документ, описывающий язык программирования максимально подробно и, по возможности, наиболее формально.
- *Транслятор* — техническое средство, осуществляющее перевод текста программы с одного языка на другой. Изначально выделялись следующие виды трансляторов.
	- *Компилятор*. Транслятор, переводящий программу в машинный код для последующего исполнения (С++).
	- *Интерпретатор*. Транслятор, читающий и исполняющий программу по одной команде (Lisp).
	- *Псевдокомпилятор* — транслятор, переводящий программу в промежуточное представление (байт-код), который состоит из набора инструкций близких по смыслу к машинному коду*
	- *Компилирующий интрепретатор* — транслятор, переводящий текст программы во внутреннем представление непосредственно после запуска. В процессе работы программа интерпретируется уже в этом представление (Python).
	- *REPL-интерпретатор*. Программное средство, работающее в цикле чтения-вычисления-печати (Read-Eval-Print Loop). Интерпретатор в режиме диалога считывает законченную конструкцию языка, транслирует ее, исполняет и выводит результат (IDLE shell Python).
- *Единица трансляции* — минимальный фрагмент программы, который может быть транслирован независимо от остального кода.
- *Препроцессинг* (предобработка) — начальный этап трансляции программы.
- *Сборка* — заключительный этап трансляции, результатом которого является исполняемый файл.

## 3. Скриншот с трансляцией программы

<img width="446" height="129" alt="1" src="https://github.com/user-attachments/assets/db1dd3bf-8334-4c8c-8fbd-27343f857491" />

## 4. Раздельная трансляция C++

<img width="577" height="167" alt="Screenshot 2026-09-17 at 01 56 42" src="https://github.com/user-attachments/assets/a5b3556f-8738-45c1-a39c-9b2857dba0bd" />
<img width="578" height="167" alt="Screenshot 2026-09-17 at 01 58 18" src="https://github.com/user-attachments/assets/8fead6c7-34d2-475b-9235-b891c222fe06" />

## 5. Аналогично пункту 4 на Java

<img width="380" height="132" alt="Screenshot 2026-09-17 at 02 22 26" src="https://github.com/user-attachments/assets/529fbd47-596b-4125-83c8-717d7e8643d6" />
<img width="350" height="119" alt="Screenshot 2026-09-17 at 02 23 08" src="https://github.com/user-attachments/assets/b656177b-2646-458a-a121-caab660a6502" />
<img width="573" height="257" alt="Screenshot 2026-09-17 at 02 26 33" src="https://github.com/user-attachments/assets/36d406b2-7eda-4b76-a823-e6ad82316b9e" />

## 6. Аналогично пункту 4 на Python

<img width="357" height="73" alt="Screenshot 2026-09-17 at 02 06 11" src="https://github.com/user-attachments/assets/b2dffb43-85c1-4687-839d-fb2f85a7a0f5" />
<img width="577" height="205" alt="Screenshot 2026-09-17 at 02 06 40" src="https://github.com/user-attachments/assets/d91c81bd-2abf-4e5a-9984-28d48154de00" />
<img width="579" height="156" alt="Screenshot 2026-09-17 at 02 07 16" src="https://github.com/user-attachments/assets/ce503ded-da5b-48f4-9dbc-03f6e16df62b" />

## 7. Makefile

<img width="470" height="140" alt="Screenshot 2026-09-17 at 02 46 25" src="https://github.com/user-attachments/assets/2e1ff081-e9a8-49de-a88e-1e4a8286cd20" />
<img width="508" height="223" alt="Screenshot 2026-09-17 at 02 48 08" src="https://github.com/user-attachments/assets/602d6483-fd2c-4df1-9543-10b3c8b2203d" />
<img width="486" height="105" alt="Screenshot 2026-09-17 at 02 48 56" src="https://github.com/user-attachments/assets/4adea12d-e077-44b3-a2f6-e405e97cf6a2" />

Утилита `make` автоматизирует процесс сборки, используя файл инструкций `Makefile`. Работа `make` основана на сравнении временных меток (timestamps) файлов. 

`Makefile` состоит из правил. Каждое правило имеет вид:
```Makefile
цель: зависимости
    команда
```

Когда мы запускаем `make`, утилита ищет первую цель (в нашем случае `all`, которая зависит от `app`). Чтобы собрать `app`, ей нужны объектные файлы (`main.o`, `hello.o` и т.д.). 

Для каждого объектного файла `make` проверяет: если исходный `.cpp` файл был изменен позже, чем существующий `.o` файл (или `.o` файл вообще отсутствует), `make` выполняет команду компиляции для этого файла. Если `.o` файл новее исходника, компиляция пропускается.

После того как все зависимости (`*.o`) готовы, `make` проверяет саму цель `app`. Если хотя бы один объектный файл был пересобран (или если сам файл `app` был удален), `make` выполняет команду линковки, чтобы создать новый исполняемый файл. Это называется инкрементальной сборкой и позволяет значительно экономить время при работе над большими проектами.

## 8. Сравнение стандартов C++

### 1. Использование вектора

```c++
#include <vector>
#include <iostream>
int main() {
    std::vector<int> v(5);
    for (int i=0; i<5; i++)
        std::cout << v[i] << ' ';
    return 0;
}
```

<img width="572" height="85" alt="Screenshot 2026-09-17 at 03 39 12" src="https://github.com/user-attachments/assets/e1362404-2197-4406-b918-c6133a5efc66" />

Компилируется без предупреждений во всех стандартах

### 2. Цикл по коллекции

```c++
#include <vector>
#include <iostream>
int main() {
    std::vector<int> v(5);
    // Новый цикл
    for (int x : v)
        std::cout << x << ' ';
    return 0;
}
```

<img width="580" height="120" alt="Screenshot 2026-09-17 at 09 01 14" src="https://github.com/user-attachments/assets/babb2e46-559a-46df-adc9-5bae709fd4ff" />

В стандартах до `c++11` выдает предупреждение, начиная с `с++11` компилируется безукоризненно.

### 3. Ключевое слово auto

```c++
#include <vector>
#include <iostream>
int main() {
    std::vector<int> v(5);
    // Используем auto
    for (auto x : v)
        std::cout << x << ' ';
    return 0;
}
```

<img width="575" height="181" alt="Screenshot 2026-09-17 at 09 10 09" src="https://github.com/user-attachments/assets/c7458b3b-0453-4348-a580-c4294dbb9440" />

В стандартах до `c++11` выдает предупреждение, начиная с `с++11` компилируется безукоризненно.

### 4. Инициализация списком

```c++
#include <vector>
#include <iostream>
int main() {
    // Инициализация списком
    std::vector<int> v = {1,2,3,4,5};
    for (int i=0; i<5; i++)
        std::cout << v[i] << ' ';
    return 0;
}
```

<img width="575" height="156" alt="Screenshot 2026-09-17 at 09 17 18" src="https://github.com/user-attachments/assets/eb7ceab5-5c39-40f9-a7ac-1ab07c4ebc13" />

В стандартах до `c++11` выдает *ошибку*, начиная с `с++11` компилируется безукоризненно.

### 5. Двоичные литералы

```c++
#include <vector>
#include <iostream>
int main() {
    // Добавлен двоичный литерал 0b1100 (это 12 в десятичной)
    std::vector<int> v = {1,2,3,4,5,0b1100};
    for (int i=0; i<5; i++)
        std::cout << v[i] << ' ';
    return 0;
}
```

<img width="578" height="110" alt="Screenshot 2026-09-17 at 09 23 47" src="https://github.com/user-attachments/assets/cad078fb-95c5-475a-878c-845706fbce74" />

Нигде не выдает ошибки о двоичных литералах, только об инициализации списка.

### 6. Определение типа по конструктору

```c++
#include <vector>
#include <iostream>
int main() {
    // Вывод типа шаблона из конструктора (Class Template Argument Deduction)
    std::vector v = {1,2,3,4,5};
    for (int i=0; i<5; i++)
        std::cout << v[i] << ' ';
    return 0;
}
```

<img width="569" height="293" alt="Screenshot 2026-09-17 at 09 29 01" src="https://github.com/user-attachments/assets/117ea69f-a80a-401f-a768-bccb3cd20c4b" />

До стандарта `c++17` выдает ошибки

## 9. Уровни оптимизации

Уровень `01` дал почти в два более короткий код, чем `O0`. 

### Нулевой уровень (нет оптимизации):

```assembly
	stur	wzr, [x29, #-4]
	str	wzr, [sp, #4]
	adrp	x0, __ZNSt3__13cinE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__13cinE@GOTPAGEOFF]
	add	x1, sp, #8
	bl	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEErsERi
	str	wzr, [sp]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp]
	subs	w8, w8, #123
	b.ge	LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w9, [sp, #8]
	ldr	w8, [sp, #4]
	add	w8, w8, w9
	str	w8, [sp, #4]
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp]
	add	w8, w8, #1
	str	w8, [sp]
	b	LBB0_1
LBB0_4:
	ldr	w1, [sp, #4]
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
```

### Первый и второй уровни:

```assembly
Lloh0:
	adrp	x0, __ZNSt3__13cinE@GOTPAGE
Lloh1:
	ldr	x0, [x0, __ZNSt3__13cinE@GOTPAGEOFF]
	sub	x1, x29, #4
	bl	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEErsERi
	ldur	w8, [x29, #-4]
	mov	w9, #123                        ; =0x7b
	mul	w1, w8, w9
Lloh2:
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
Lloh3:
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.loh AdrpLdrGot	Lloh2, Lloh3
	.loh AdrpLdrGot	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
```

Наглядно видно, что компилятор увидел в цикле повторяющееся сложение одного и того же `x` 123 раза и сжал его до простого умножения.

Результаты работ уровней `O1` и `O2` в данном примере друг от друга не отличаются.

## 10. Дизасемблирование из Java байт-кода

Байт-код цикла:

```
zolars@Arsenys-MacBook-Air 10 % javac Task10.java 
zolars@Arsenys-MacBook-Air 10 % javap -c Task10 
Compiled from "Task10.java"
public class Task10 {
  public Task10();

...

      25: istore_1
      26: iconst_0
      27: istore        4
      29: iload         4
      31: bipush        123
      33: if_icmpge     46
      36: iload_2
      37: iload_1
      38: iadd
      39: istore_2
      40: iinc          4, 1
      43: goto          29
      ...
```


## 11. Другие оптимизации компилятора

Компилятор может также удалять неиспользованные "мертвые" участки кода, выносить вычисления за цикл (например, сумму ариф. прогрессии считать по формуле, а не в цикле, как написал глупенький программист), перевод рекурсии в цикл и многое другое
