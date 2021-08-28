 /**************************************************************************
  2  *   pe1.c                                    Version 20190817.235856      *
  3  *                                                                         *
  4  *   Project Euler                                                         *
  5  *   Copyright (C) 2015-2019   Template by Ruben Carlo Benante             *
  6  *   Author: Your name here                                                *
  7  ***************************************************************************
  8  *   This program is free software; you can redistribute it and/or modify  *
  9  *   it under the terms of the GNU General Public License as published by  *
 10  *   the Free Software Foundation; either version 3 of the License, or     *
 11  *   (at your option) any later version.                                   *
 12  *                                                                         *
 13  *   This program is distributed in the hope that it will be useful,       *
 14  *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 15  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 16  *   GNU General Public License for more details.                          *
 17  *                                                                         *
 18  *   You should have received a copy of the GNU General Public License     *
 19  *   along with this program; if not, write to the                         *
 20  *   Free Software Foundation, Inc.,                                       *
 21  *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 22  ***************************************************************************
 23  *   To contact the author, please write to:                               *
 24  *   Ruben Carlo Benante                                                   *
 25  *   Email: rcb@beco.cc                                                    *
 26  *   Webpage: http://www.beco.cc                                           *
 27  *   Phone: +55 (81) 3184-7555                                             *
 28  **************************************************************************/

  /* ---------------------------------------------------------------------- */
  /* includes */
  //#include "projecteuler.h"
  //#include "myeulerlib.h"

  /* ---------------------------------------------------------------------- */
  /* defines */
  /* Project Euler Exercise Number */
  /* #define PEN pe ## 1 */
  #define SPEN "pe" "1"

  /* ---------------------------------------------------------------------- */
  /* prototypes */
  void pe1(void); /* Proj. Euler problem #1 */

  /* ---------------------------------------------------------------------- */
  /* main function */
  /* Do not change the main function. Use the void pe1(void) and
 48  * others you create here or in the myeulerlib.c and myeulerlib.h files
 49  */
  int main(void)
  {
      printf("Project Euler 20190817.233439, %s\n", SPEN);
      help(); /* optional help message at start */
      GRABsignals(); /* grab interruption signals */
      pe1(); /* Proj. Euler problem #1 */
      LEGOsignals(); /* restore interruption signals */
      //return EXIT_SUCCESS;
  }

  /* ---------------------------------------------------------------------- */
  /* Proj. Euler problem #1 */
  /* Problem description:
 63  *
 64  */

  void pe1(void)
  {
      /* local variables */
      long r=0; /* answer */



      /* Put this command inside a loop to get previews when pressing CTRL-C */
      /* ctrlc_printf("%s: Trying now %u\n", __FUNCTION__, r); */

      /* Use to count minutes running: */
      /* if(minutes() >= 2) break; */
      #include <stdio.h>
  #include <stdlib.h>

  int main(int argc, char *argv[])
 {
      //Find the sum of all the multiples of 3 or 5 below 1000
    int sum = 0;

    for (int x = 0; x < 1000; x++)

    {
      if (x % 5 == 0 || x % 3 == 0)
        sum += x;
    }
  r = sum;
    printf("%d", sum);
  }




      printf("%s: %lu\n", __FUNCTION__, r); /* answer */
     return;
 }

 /* ---------------------------------------------------------------------- */
 /* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
 /* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
