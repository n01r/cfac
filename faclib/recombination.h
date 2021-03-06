/*
 *   FAC - Flexible Atomic Code
 *   Copyright (C) 2001-2015 Ming Feng Gu
 *   Portions Copyright (C) 2010-2015 Evgeny Stambulchik
 * 
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 * 
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 * 
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _RECOMBINATION_H_
#define _RECOMBINATION_H_

#include <stdio.h>

#define MAX_COMPLEX 512
typedef struct _REC_COMPLEX_ {
  int n;
  ARRAY *rg;
  int s0;
  int s1;
} REC_COMPLEX;

int InitRecombination(void);
int ReinitRecombination(int m);
int FreeRecPk(void);
int FreeRecQk(void);
int FreeRecAngZ(void);
int SetAICut(double c);
int SetRRTEGrid(int n, double emin, double emax);
int SetRRTEGridDetail(int n, double *x);
int SetPEGrid(int n, double emin, double emax, double eth);
int SetPEGridDetail(int n, double *x);
int SetPEGridLimits(double min, double max, int type);
int SetUsrPEGridType(int type);
int SetUsrPEGrid(int n, double emin, double emax, double eth);
int SetUsrPEGridDetail(int n, double *x);
int AddRecPW(int n, int step);
int SetRecQkMode(int m, double tol);
int SetRecPWOptions(int kl_interp, int max_kl);
int SetRecPWLimits(int m1, int m2);
int SetRecSpectator(int n_frozen, int n_spec);
int ConstructRecGroupName(char *rgn, char *gn, int n);
int RecStates(int n, int k, int *kg, char *fn);
int RecStatesFrozen(int n, int k, int *kg, char *fn);
int RRRadialMultipoleTable(double *qr, int k0, int k1, int m);
int RRRadialQkTable(double *qr, int k0, int k1, int m);
int RRRadialMultipole(double *rqc, double te, int k0, int k1, int m);
int RRRadialQk(double *rqc, double te, int k0, int k1, int m);
void RRRadialQkFromFit(int np, double *p, int n, double *x, double *logx, 
		       double *y, double *dy, int ndy, void *extra);
void RRRadialQkHydrogenicParams(int np, double *p, double z, int n, int klb);
int BoundFreeMultipole(FILE *fp, int rec, int f, int m);
int BoundFreeOS(double *rqu, double *p, 
		double *eb, int rec, int f, int m, int iuta);
int PrepRREGrids(double eth, double emax0);
int SaveRRMultipole(int nlow, int *low, int nup, int *up, char *fn, int m);
int SaveRecRR(int nlow, int *low, int nup, int *up, char *fn, int m);
int SaveAI(int nlow, int *low, int nup, int *up, char *fn, 
	   double eref, int msub);
int AIRadial1E(double *pk, int kb, int kappaf);
int AIRadialPk(double **pk, int k0, int k1, int kb, int kappaf, int k);
int AutoionizeRate(double *rate, double *e, int rec, int f, int msub);

#endif
