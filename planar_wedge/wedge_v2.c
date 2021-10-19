//This code is written to simulate a flow inside a wedge shaped 
//triangular region.
//Author : anvesh
// Method to compile code : qcc -O2 wedge_v1.c -L$BASILISK/gl -lglutils -lfb_osmesa -lGLU -lOSMesa -lm
//
//Status :
// Domain is 1x1 box where we insert an embedded region.  
// Date : 18-oct-2021.
// libraries used- 
// Version - 2


#include "embed.h"
#include "navier-stokes/centered.h"
#include "vtk.h"
#include "view.h" 


char name_vtk[100];
int maxlevel =10;
double Uplate;
double Reynolds = 0.2;       // Reynolds number
face vector muv[];		//viscosity. 
int main()
{
	L0=1;
	Uplate= 1.;
	origin (0, -L0);  // Origin is at thetop left corner. (middle ) 
	N=128; 
	mu= muv;
	display_control (Reynolds, 1, 1000);       // control the reynolds and maxlevel in bview2D
	display_control (maxlevel, 6, 12);
	run(); 


}
event properties (i++)
{
	foreach_face()
	 muv.x[] = Uplate*L0/Reynolds;
}

event adapt (t=0) {
	scalar s[];
	foreach()
		s[] = sqrt( x*x + y*y)-sqrt(0.5);
	boundary ({s});
	adapt_wavelet ({s}, (double[]){1e-2},10 , 13);
}
vertex scalar phi[];
event init (t = 0)
{
//	refine (sqrt( x*x + y*y)  <  0.4  && level < maxlevel);

	foreach()
		u.x[] = 0.001 ;



     foreach_vertex()
             phi[] = -(y + x);
        boundary ({phi} );
        fractions (phi, cs, fs);

}
// Setting the boundary conditions
u.n[left] = dirichlet(0.0);
u.t[left] = dirichlet(Uplate);


// outflow bc according to http://basilisk.fr/src/test/swirl.c
u.n[bottom] = neumann(0.);
p[bottom] = dirichlet(0.);
pf[bottom] = dirichlet(0.);

// noslip bc on the inclined wall

u.n[embed] = dirichlet(0.);
u.t[embed] = dirichlet(0.);

//u.n[embed] = (y+x) < 0.0 ? neumann(0.) : dirichlet(0.);
//u.t[embed] = (y+x) < 0.0 ? neumann(0.) : dirichlet(0.);



event logfile (i++)
        fprintf (stderr, "%d %g\n", i, t);

char name[80];
// Post processing results  
event movies (i += 1  ; t <= 2)
{ 
	
/*	clear();
	  draw_vof ("phi");
	  cells();
//	  filled();
//	  isoline();
	  box();
	  save ("phi.mp4");
	  
	  save ("image.png");
*/

/*  sprintf (name, "snapshot-%g", t);
  scalar pid[];
  foreach()
    pid[] = fmod(pid()*(npe() + 37), npe());
  boundary ({pid});
  dump (name);
*/

/*	  char name[80];
	sprintf (name, "snapshot-%d.gfs", i);
	scalar pid[];
	foreach()
	    pid[] = tid();
	output_gfs (file = name);  */

scalar phi0[];
/*	foreach()
		phi0[]=phi[];

	foreach()
                sprintf (name_vtk, "data-%g.vtk", t);
                FILE * fpvtk = fopen (name_vtk, "w");
                output_vtk ({u.x,u.y,p,phi0},N,fpvtk,1);   */

  scalar un[], ut[];
  foreach() {
    double theta = atan2(x, y), r = sqrt(x*x + y*y);
    if (cs[] > 0.) {
      ut[] =  sin(theta)*u.x[] - cos(theta)*u.y[];
      un[] =  sin(theta)*u.y[] + cos(theta)*u.x[];
    }
    else
      ut[]=un[] = nodata;
  }
    sprintf (name_vtk, "data-%g.vtk", t);
    FILE * fpvtk = fopen (name_vtk, "w");
    output_vtk ({u.x,u.y,ut,un,p,phi0},N,fpvtk,1);

}

event profile (i++)
{
  scalar un[], ut[];
  foreach() {
    double theta = atan2(x, -y), r = sqrt(x*x + y*y);
    if (cs[] > 0.) {
      ut[] =  sin(theta)*u.x[] - cos(theta)*u.y[];
      un[] =  sin(theta)*u.y[] + cos(theta)*u.x[];
    }
    else
      ut[]=un[] = nodata;
  }

  draw_vof ("cs", "fs", filled = -1, fc = {1,1,1});
  //squares ("ut", spread = -1);
  cells();
  squares ("ut", linear = true);
  save ("ut.png");

  draw_vof ("cs", "fs", filled = -1, fc = {1,1,1});
  //squares ("un", spread = -1);
  cells();
  squares ("un", linear = true);
  save ("un.png");

  draw_vof ("cs", "fs", filled = -1, fc = {1,1,1});
  squares ("u.x", linear = true);
  cells();
  save ("ux.png");

  draw_vof ("cs", "fs", filled = -1, fc = {1,1,1});
  squares ("u.y", linear = true);
  cells();
  save ("uy.png");

}


// Using adaptive grid based on velocity
event adapt (i++) {
        adapt_wavelet ({cs,u}, (double[]){1e-2,3e-2,3e-2}, 6, 9); 
}

