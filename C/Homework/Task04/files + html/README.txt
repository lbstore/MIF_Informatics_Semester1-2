Programa parse'ina VU naujienu tiklapi.
Yra autorizacijos 3 lygiai: guest, basic, admin
guest: tik iveda HTML faila ir ji israso.
basic: visas kitas isskyrus password perrasymas
admin: tik password perrasymas

Programos viduje yra preprocesoriaus macro "Override" kuris, jei galioja, leidzia perrasyti password

Basic komandos:

importHtml - iveda .html faila nuskaitymui(butina .html galune), ir issaugo duomenis (isvalo esamus)
clean - isvalo esamus
edit - rankinis elementu keitimas,ivedimas.
resume - darbo tesimas, su binariniu failu
export - issaugo dabartinius duomenis binarinio failu formatu
exit - bagti darba

Password max 20 simboliu.
panaudotas encryption password saugojimo faile.
Istrynus naudoti "Override" marcro kompiliuojant.
Password pereina hash ir patikrina ar sutampa su faile esanciu, pati programa jo nezino.

Kadangi duomenys saugojami laisvu formatu, nera rusiavimo.

Realizuoti 2 duomenu tipai: singly linked list, dynamic array.
vienpusis sarasas naudojamas tik html nuskaitymui, ir poto perrasomas i dinamini masyva.
Motyvas: Nezinia kiek bus elementu html faile, o poto su masyvu dirbti yra tiesiog zymiai patogiau.

Naudojamas extra failas, kuris saugo elementu kieki ir html pavadinima. Jo gali ir nebuti, taciau butinas norint testi darba su binariniu failu.

Taip pat yra vedamas log file.