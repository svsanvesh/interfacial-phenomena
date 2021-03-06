//This is a simualtion to visualize the flow field near a moving contact line. 
//The geometry of the problem is a sqaure domain of size L=5*l_c ; where l_c = 3. (ALL LENGTHS IN mm)
//it is a 25x25 square with interface in the middle, horizontally. 
//Author- Anvesh 
//Date - 15-Nov-2021
//Comments: 
//Status : working 
//
//
//Libraries used - 

//#include "navier-stokes/conserving.h"
#include "navier-stokes/centered.h"
#include "vtk.h"
#include "adapt_wavelet_leave_interface.h"
#include "contact.h"
#include "tension.h"
/*
#define mu(f)  (1./(clamp(f,0,1)*(1./mu1 - 1./mu2) + 1./mu2) )  // this code is incorperated from http://basilisk.fr/src/examples/bubble.c .
#define rho(f)  (1./(clamp(f,0,1)*(1./rho1 - 1./rho2) + 1./rho2))
*/
#include "two-phase.h"



//double Reynolds = 2.0;       // Reynolds number
int maxlevel = 9;              // Maximum mesh refinement
//face vector muv[];             // viscosity
char name_vtk[100];		// vtk file name decleration.
double U0;
double H0;


	#define grav  9.81 // gravitational acceleration
        #define rhoL 1000 //density of water
        #define muL 0.001 //viscosity of water
        #define surf  0.072  // surface tension air-water
        #define rhoG 1 //density of air
        #define muG  0.0000181 // viscosity of air
	#define lc 2.7e-3// capillary length 
double h0;

vector h[];  //HEIGHT FUNCTION 
double theta0 ;
//make sure that the boundary conditions for the face-centered velocity field are consistent with the centered velocity field (this affects the advection term).
uf.n[left]   = 0.;
uf.n[right]  = 0.;
uf.n[top]    = 0.;
uf.n[bottom] = 0.;
int main() 
{	
        L0 = 0.025;            // Size of the square box
	h0=lc/tan(theta0); 
//        H0 = 1.;            // Height of the channel
//	dt=0.1;
        U0 = -0.001 ;             // Velocity of the left plate
        origin (0, -L0/2);  // Origin is at the bottom centre of the box
      //  mu = muv;           // constant viscosity. Exact value given below

	if (t <0.0005)
		N = 1024;
	else 
		N = 128;
	stokes = true;
        f.sigma = surf;
        f.height = h;
	display_control (maxlevel, 6, 15);

	theta0 = 160*pi/180.0; 
	h.t[left] = contact_angle (theta0); // Left contact angle near the moving wall 
	h.t[right] = contact_angle (pi/2);  // right contact angle of 90 degrees. 
	
	//The viscosity and desinties of the two fluids is specified here. 
	rho2 = rhoL;   // fluid 2 is given by f = 0.
	mu2 = muL;    
	rho1 = rhoG;   // fluid 1 is given by f =1. 
	mu1 = muG;
	
	/*
	const face vector muc[] = {.1,.1};
	mu = muc;
	*/
        run();

}

event adapt (i++) {

                scalar impose_refine[], f1[];
                foreach(){
                  f1[] = f[];
                  if(x<0.0015 && y<0.001 && y> -0.0001)
                          impose_refine[] = noise();
                  else
                          impose_refine[] = 0;
          }
          boundary({impose_refine});
          boundary({f1});
          adapt_wavelet({f1}, (double[]){1e-2}, maxlevel ,7 );

        }

event init (t = 0)
{
	// the interface shape is given here. 
//	fraction (f , -y );
/*	foreach()
	       	f =(scalar *)(-y - exp(-x) - 0.005) ;
  foreach()
             u.x[] =  0.0001;
*/   
//Here the approximate static meniscus shape is given as an initial condition.  
//the top fluid has f = 0 and is gas and the bottom fluid is f =1 and is liquid. 
//refer: http://basilisk.fr/src/two-phase.h

	fraction (f,  0.0020+ y+0.0027/(tan(theta0)*exp(x/0.0027)));

	boundary ({f});
}



// gravity is given in the vertically down direction.(-9.81)
event acceleration (i++)
{
        face vector av = a;
        foreach_face(x)
                av.y[] = -9.81;
}


// Setting the boundary conditions
u.n[left] = dirichlet(0.);
u.t[left] = dirichlet(-0.001);


u.n[right] = dirichlet(0.);
u.t[right] = dirichlet(0.);



u.n[top] = dirichlet(0.);
u.t[top] = dirichlet(0.);

u.n[bottom] = dirichlet(0.);
u.t[bottom] = dirichlet(0.0);



// Printing out standard text outputs on the screen
event logfile (i++)
        fprintf (stderr, "%d %g\n", i, t);




char name[80];
// Produce vorticity animation
event movies (i += 10000    ; t <= 250)
{
        sprintf (name, "dump4-%d", i);
	dump (name);
	foreach()
                sprintf (name_vtk, "data4-%d.vtk", i);
                FILE * fpvtk = fopen (name_vtk, "w");
                output_vtk ({u.x,u.y,mu.x,mu.y,rho,p,f},N,fpvtk,1);
		 scalar omega[];


}
event videos (i += 100    ; t <= 1)
{

        output_ppm (f, file = "f4.mp4",8192,
                        min = 0, max = 1.0, linear = true);


}
/*dd
// normal adapt wavelet based on f. 
event adapt (i++)

{
        adapt_wavelet ((scalar*){f}, (double[]){0.1}, 15,maxlevel); // here maxlevel is given as the bottom limit. 
}

// Using adaptive grid based on interface position
event adapt(i++){
 adapt_wavelet_leave_interface((scalar *){u},{f},(double[]){0.0 ,0.0, 0.01}, maxlevel);
}
*/

