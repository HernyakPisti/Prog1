// BHAX BogoMIPS
// Copyright (C) 2019
// Norbert Batfai, batfai.norbert@inf.unideb.hu
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// Version history
//
// This program is based on 
// 
// - Linus Torvalds's original code (https://mirrors.edge.kernel.org/pub/linux/kernel/v1.0/linux-1.0.tar.gz init/main.c)
// - and Jeff Tranter's standalone version (archive.debian.org/debian/pool/main/s/sysutils/sysutils_1.3.8.5.1.tar.gz). 
//
// See also UDPROG
//

#include <time.h> //clock függvényhez szükséges
#include <stdio.h>

void
delay (unsigned long long loops)
{
  for (unsigned long long i = 0; i < loops; i++); //egyszerű számolás 1-sével a loops_per_sec-ig
}

int
main (void)
{
  unsigned long long loops_per_sec = 1;
  unsigned long long ticks;

  printf ("Calibrating delay loop..");
  fflush (stdout);

  while ((loops_per_sec <<= 1)) //loops_per_secet 2-es számrendszerben való számolása: elsőnek 00...001 aztán 00...010, 00...100,..., 01...000 végül 10...000 (2 hatványok)
    {
      ticks = clock ();		//letároljuk az aktuális rendszeridőt
      delay (loops_per_sec);	//delay függvény meghívása a loops_per_sec-et adva neki
      ticks = clock () - ticks;	//a kivonás után megkapjuk a tiszta rendszeridőt ami szükséges volt a loops_per_sec-ig tartó elszámolásig azaz a delay függvény hány ticks-nyi hosszú volt
	printf("%llu \t %llu \n",loops_per_sec, ticks); //az aktuális loops_per_sec és ticks kiiratása
      if (ticks >= CLOCKS_PER_SEC) //CLOCKS_PER_SEC értéke 1 000 000, 
	{
	  loops_per_sec = (loops_per_sec / ticks) * CLOCKS_PER_SEC;

	  printf ("ok - %llu.%02llu BogoMIPS\n", loops_per_sec / 500000, //a CLOCKS_PER_SEC eléréséhez milyen érték tartozna ha nem 2 hatványokban számoltunk
		  (loops_per_sec / 5000) % 100);	//egészre kerekítés

	  return 0;
	}
    }

  printf ("failed\n");
  return -1;
}
