#ifndef _1X3_ACTION_H
#define _1X3_ACTION_H


#include "../include/umethod.h"
#include "../include/dirs.h"
#include "../generic_ks/imp_actions/imp_action_types.h"
#define FERM_ACTION HISQ

    /* Specify paths in orientation in which they appear in the
       forward part of the x component of dslash().  Rotations and
       reflections will be automatically included. Be careful
       about signs of coefficients.  See long comment at bottom
       of quark_stuff.c. */


#define Clink		(0.4)	// single link coeff in first smearing
#define Cstaple		(-0.1)	// staple coeff in first smearing
//#define Clink		(10.0)	// single link coeff in first smearing
//#define Cstaple		(0.0)	// staple coeff in first smearing

// Smearing for first level
#define QUARK_ACTION_DESCRIPTION_1 "\"1 link\""

#define MAX_LENGTH 3	// Maximum length of path in any path table
#define MAX_BASIC_PATHS 2  // Max. no. of basic paths in any path table
#define NUM_BASIC_PATHS_1 1
#define MAX_NUM_1 8
#ifdef IMP_QUARK_ACTION_DEFINE_PATH_TABLES
    static int path_ind_1[NUM_BASIC_PATHS_1][MAX_LENGTH] = {
    { XUP, NODIR, NODIR },	/* One Link */
    };
    static int quark_action_npaths_1 = NUM_BASIC_PATHS_1 ;
    static int path_length_in_1[NUM_BASIC_PATHS_1] = {1};
    static Real path_coeff_1[NUM_BASIC_PATHS_1] = {
       1.0,        /* one link */
    };
#endif

//#define UNITARIZATION_METHOD UNITARIZE_NONE
//#define UNITARIZATION_METHOD UNITARIZE_ROOT
//#define UNITARIZATION_METHOD UNITARIZE_RATIONAL
#define UNITARIZATION_METHOD UNITARIZE_ANALYTIC

// Smearing for second level
#define QUARK_ACTION_DESCRIPTION_2 "\"1 link plus 3-staple\""
#ifdef IMP_QUARK_ACTION_DEFINE_PATH_TABLES
#define NUM_BASIC_PATHS_2 2
#define MAX_NUM_2 56
    static int path_ind_2[NUM_BASIC_PATHS_2][MAX_LENGTH] = {
    { XUP, NODIR, NODIR },	/* One Link */
    { YUP, XUP, YDOWN },	/* 3-staple */
    };
    static int path_length_in_2[NUM_BASIC_PATHS_2] = {1,3};
    static int quark_action_npaths_2 = NUM_BASIC_PATHS_2 ;
    static Real path_coeff_2[NUM_BASIC_PATHS_2] = {
       Clink,        /* one link */
       Cstaple,        /* 3-staple */
    };
#define INDEX_ONELINK 0
#define INDEX_NAIK 1
    static Real onelink_mass_renorm_fact = (1.0/8.0)*(-27.0/40.0);
    static Real naik_mass_renorm_fact = (-1.0/24.0)*(-27.0/40.0);
#endif

//FOR THE MOMENT, we keep the old stuff around.  It will be superceded by
//two new sets of variables

#define QUARK_ACTION_DESCRIPTION "\"Link plus Staple\""
#ifdef IMP_QUARK_ACTION_DEFINE_PATH_TABLES
#define NUM_BASIC_PATHS 2
#define MAX_NUM 56
    static int path_ind[NUM_BASIC_PATHS][MAX_LENGTH] = {
    { XUP,   NODIR, NODIR },	/* One Link */
    { YUP,   XUP,   YDOWN },	/* Staple */
    };
    static int path_length_in[NUM_BASIC_PATHS] = {1,3};
    static int quark_action_npaths = NUM_BASIC_PATHS ;
    static Real path_coeff[NUM_BASIC_PATHS] = {
	Clink,
	Cstaple
    };
#endif


#endif // _1X3_ACTION_H
