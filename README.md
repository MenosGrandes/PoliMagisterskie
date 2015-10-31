# PoliMagisterskie
## Errory
___
1. W swietle kule i plane przyjmuja tylko kolor szary.
2. Bardzo zle zoptymalizowana funkcja `Vector2Bf Sampler::single()` zajmuje baaaardzo duzo czasu. Tak naprawde to random w srodku zajmuje duzo czasu.
3. Jak eksportuje do OBJ to zaznaczac "FLIP YZ-axis", inaczej dziwnie wychodzi.
4. Kamera jest prawdziwe PINHOLE, czyli wychodzi lustrzane odbicie, poprawic.
</br>
## TODO
___
1. Metody anty aliasingu MultiJittered oraz Adaptacyjna do zrobienia,
2. zrobic dodatkowa klase od koloru tylko nie zawierajaca przezroczystosci tylko RBB,
3. sprobowac znalezc zastepstwo dla random :
	- http://www.sitmo.com/article/parallel-random-number-generator-in-c/,
    - https://en.wikipedia.org/wiki/Xorshift,
	- http://www.java-gaming.org/index.php?topic=27609.0

