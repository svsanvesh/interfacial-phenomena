size_t datasize = 13*sizeof (double);
static int defaults (const int i, const double t, Event * _ev);
static int defaults_expr0 (int * ip, double * tp, Event * _ev);
static int cleanup (const int i, const double t, Event * _ev);
static int cleanup_expr0 (int * ip, double * tp, Event * _ev);
static int defaults_0 (const int i, const double t, Event * _ev);
static int defaults_0_expr0 (int * ip, double * tp, Event * _ev);
static int default_display (const int i, const double t, Event * _ev);
static int default_display_expr0 (int * ip, double * tp, Event * _ev);
static int init (const int i, const double t, Event * _ev);
static int init_expr0 (int * ip, double * tp, Event * _ev);
static int set_dtmax (const int i, const double t, Event * _ev);
static int set_dtmax_expr0 (int * ip, double * tp, Event * _ev);
static int stability (const int i, const double t, Event * _ev);
static int stability_expr0 (int * ip, double * tp, Event * _ev);
static int vof (const int i, const double t, Event * _ev);
static int vof_expr0 (int * ip, double * tp, Event * _ev);
static int tracer_advection (const int i, const double t, Event * _ev);
static int tracer_advection_expr0 (int * ip, double * tp, Event * _ev);
static int tracer_diffusion (const int i, const double t, Event * _ev);
static int tracer_diffusion_expr0 (int * ip, double * tp, Event * _ev);
static int properties (const int i, const double t, Event * _ev);
static int properties_expr0 (int * ip, double * tp, Event * _ev);
static int advection_term (const int i, const double t, Event * _ev);
static int advection_term_expr0 (int * ip, double * tp, Event * _ev);
static int viscous_term (const int i, const double t, Event * _ev);
static int viscous_term_expr0 (int * ip, double * tp, Event * _ev);
static int acceleration (const int i, const double t, Event * _ev);
static int acceleration_expr0 (int * ip, double * tp, Event * _ev);
static int projection (const int i, const double t, Event * _ev);
static int projection_expr0 (int * ip, double * tp, Event * _ev);
static int end_timestep (const int i, const double t, Event * _ev);
static int end_timestep_expr0 (int * ip, double * tp, Event * _ev);
static int adapt (const int i, const double t, Event * _ev);
static int adapt_expr0 (int * ip, double * tp, Event * _ev);
static int defaults_1 (const int i, const double t, Event * _ev);
static int defaults_1_expr0 (int * ip, double * tp, Event * _ev);
static int stability_0 (const int i, const double t, Event * _ev);
static int stability_0_expr0 (int * ip, double * tp, Event * _ev);
static int vof_0 (const int i, const double t, Event * _ev);
static int vof_0_expr0 (int * ip, double * tp, Event * _ev);
static int defaults_2 (const int i, const double t, Event * _ev);
static int defaults_2_expr0 (int * ip, double * tp, Event * _ev);
static int tracer_advection_0 (const int i, const double t, Event * _ev);
static int tracer_advection_0_expr0 (int * ip, double * tp, Event * _ev);
static int properties_0 (const int i, const double t, Event * _ev);
static int properties_0_expr0 (int * ip, double * tp, Event * _ev);
static int defaults_3 (const int i, const double t, Event * _ev);
static int defaults_3_expr0 (int * ip, double * tp, Event * _ev);
static int acceleration_0 (const int i, const double t, Event * _ev);
static int acceleration_0_expr0 (int * ip, double * tp, Event * _ev);
static int stability_1 (const int i, const double t, Event * _ev);
static int stability_1_expr0 (int * ip, double * tp, Event * _ev);
static int acceleration_1 (const int i, const double t, Event * _ev);
static int acceleration_1_expr0 (int * ip, double * tp, Event * _ev);
static int init_0 (const int i, const double t, Event * _ev);
static int init_0_expr0 (int * ip, double * tp, Event * _ev);
static int adapt_0 (const int i, const double t, Event * _ev);
static int adapt_0_expr0 (int * ip, double * tp, Event * _ev);
static int end (const int i, const double t, Event * _ev);
static int end_expr0 (int * ip, double * tp, Event * _ev);
static int gfsview (const int i, const double t, Event * _ev);
static int gfsview_expr0 (int * ip, double * tp, Event * _ev);
static int interface (const int i, const double t, Event * _ev);
static int interface_expr0 (int * ip, double * tp, Event * _ev);
static int loginterface (const int i, const double t, Event * _ev);
static int loginterface_expr0 (int * ip, double * tp, Event * _ev);
static int profiles (const int i, const double t, Event * _ev);
static int profiles_expr0 (int * ip, double * tp, Event * _ev);
static int profiles_expr1 (int * ip, double * tp, Event * _ev);
static int profiles_expr2 (int * ip, double * tp, Event * _ev);
static int vortmovie (const int i, const double t, Event * _ev);
static int vortmovie_expr0 (int * ip, double * tp, Event * _ev);
static void _set_boundary0 (void);
static void _set_boundary1 (void);
static void _set_boundary2 (void);
static void _set_boundary3 (void);
static void _set_boundary4 (void);
static void _set_boundary5 (void);
static void _set_boundary6 (void);
static void _set_boundary7 (void);
void _init_solver (void) {
  void init_solver();
  init_solver();
  Events = (Event *) pmalloc (sizeof (Event), __func__, __FILE__, __LINE__);
  Events[0].last = 1;
  event_register ((Event){ 0, 1, defaults, {defaults_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/run.h", 42, "defaults"});
  event_register ((Event){ 0, 1, defaults_0, {defaults_0_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 126, "defaults"});
  event_register ((Event){ 0, 1, defaults_1, {defaults_1_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/vof.h", 107, "defaults"});
  event_register ((Event){ 0, 1, defaults_2, {defaults_2_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/two-phase.h", 25, "defaults"});
  event_register ((Event){ 0, 1, defaults_3, {defaults_3_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/iforce.h", 30, "defaults"});
  event_register ((Event){ 0, 1, default_display, {default_display_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 179, "default_display"});
  event_register ((Event){ 0, 1, init, {init_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 188, "init"});
  event_register ((Event){ 0, 1, init_0, {init_0_expr0}, ((int *)0), ((double *)0),
    "test.c", 115, "init"});
  event_register ((Event){ 0, 1, end, {end_expr0}, ((int *)0), ((double *)0),
    "test.c", 182, "end"});
  event_register ((Event){ 0, 1, gfsview, {gfsview_expr0}, ((int *)0), ((double *)0),
    "test.c", 198, "gfsview"});
  event_register ((Event){ 0, 1, interface, {interface_expr0}, ((int *)0), ((double *)0),
    "test.c", 253, "interface"});
  event_register ((Event){ 0, 1, loginterface, {loginterface_expr0}, ((int *)0), ((double *)0),
    "test.c", 262, "loginterface"});
  event_register ((Event){ 0, 3, profiles, {profiles_expr0, profiles_expr1, profiles_expr2}, ((int *)0), ((double *)0),
    "test.c", 270, "profiles"});
  event_register ((Event){ 0, 1, vortmovie, {vortmovie_expr0}, ((int *)0), ((double *)0),
    "test.c", 309, "vortmovie"});
  event_register ((Event){ 0, 1, cleanup, {cleanup_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/run.h", 50, "cleanup"});
  event_register ((Event){ 0, 1, set_dtmax, {set_dtmax_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 216, "set_dtmax"});
  event_register ((Event){ 0, 1, stability, {stability_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 218, "stability"});
  event_register ((Event){ 0, 1, stability_0, {stability_0_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/vof.h", 125, "stability"});
  event_register ((Event){ 0, 1, stability_1, {stability_1_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/tension.h", 36, "stability"});
  event_register ((Event){ 0, 1, vof, {vof_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 228, "vof"});
  event_register ((Event){ 0, 1, vof_0, {vof_0_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/vof.h", 371, "vof"});
  event_register ((Event){ 0, 1, tracer_advection, {tracer_advection_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 229, "tracer_advection"});
  event_register ((Event){ 0, 1, tracer_advection_0, {tracer_advection_0_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/two-phase.h", 64, "tracer_advection"});
  event_register ((Event){ 0, 1, tracer_diffusion, {tracer_diffusion_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 230, "tracer_diffusion"});
  event_register ((Event){ 0, 1, properties, {properties_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 237, "properties"});
  event_register ((Event){ 0, 1, properties_0, {properties_0_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/two-phase.h", 95, "properties"});
  event_register ((Event){ 0, 1, advection_term, {advection_term_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 314, "advection_term"});
  event_register ((Event){ 0, 1, viscous_term, {viscous_term_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 344, "viscous_term"});
  event_register ((Event){ 0, 1, acceleration, {acceleration_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 380, "acceleration"});
  event_register ((Event){ 0, 1, acceleration_0, {acceleration_0_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/iforce.h", 44, "acceleration"});
  event_register ((Event){ 0, 1, acceleration_1, {acceleration_1_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/tension.h", 70, "acceleration"});
  event_register ((Event){ 0, 1, projection, {projection_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 423, "projection"});
  event_register ((Event){ 0, 1, end_timestep, {end_timestep_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 438, "end_timestep"});
  event_register ((Event){ 0, 1, adapt, {adapt_expr0}, ((int *)0), ((double *)0),
    "/opt/basilisk/src/navier-stokes/centered.h", 448, "adapt"});
  event_register ((Event){ 0, 1, adapt_0, {adapt_0_expr0}, ((int *)0), ((double *)0),
    "test.c", 139, "adapt"});
  _attribute = (_Attributes *) pcalloc (datasize/sizeof(double), sizeof (_Attributes), __func__, __FILE__, __LINE__);
  all = (scalar *) pmalloc (sizeof (scalar)*14,__func__, __FILE__, __LINE__);
  for (int i = 0; i < 13; i++)
    all[i].i = i;
  all[13].i = -1;
  set_fpe();
  quadtree_methods();
  init_scalar ((scalar){12}, "sf");
  init_scalar ((scalar){11}, "rhov");
  init_face_vector ((vector){{9},{10}}, "alphav");
  init_scalar ((scalar){8}, "f");
  init_face_vector ((vector){{6},{7}}, "uf");
  init_scalar ((scalar){5}, "pf");
  init_vector ((vector){{3},{4}}, "g");
  init_vector ((vector){{1},{2}}, "u");
  init_scalar ((scalar){0}, "p");
  init_const_scalar ((scalar){_NVARMAX+5}, "zeroc",  0.);
  init_const_scalar ((scalar){_NVARMAX+4}, "unity",  1.);
  init_const_vector ((vector){{_NVARMAX+2},{_NVARMAX+3}}, "unityf", (double []) {1.,1.,1.});
  init_const_vector ((vector){{_NVARMAX+0},{_NVARMAX+1}}, "zerof", (double []) {0.,0.,0.});
  _set_boundary0();
  _set_boundary1();
  _set_boundary2();
  _set_boundary3();
  _set_boundary4();
  _set_boundary5();
  _set_boundary6();
  _set_boundary7();
}
