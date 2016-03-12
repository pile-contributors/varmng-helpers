/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
  file         testhelpers.h
  date         December 2015
  author       Nicu Tofan

  Helper header that gets included in all test files.

*//*

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Please read COPYING and README files in root folder
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include <string.h>

/*  INCLUDES    ============================================================ */
//
//
//
//
/*  DEFINITIONS    --------------------------------------------------------- */

#define EXPECT_NULL(__p__) EXPECT_TRUE(__p__ == NULL)
#define EXPECT_NNULL(__p__) EXPECT_FALSE(__p__ == NULL)
#define EXPECT_OK(__x__) EXPECT_EQ(__x__, FUNC_OK)


/*  DEFINITIONS    ========================================================= */
//
//
//
//
/*  DATA    ---------------------------------------------------------------- */

#include <QPixmap>
#include <QPainter>
#include <QSize>
#include <QStandardItemModel>

/*  DATA    ================================================================ */
//
//
//
//
/*  FUNCTIONS    ----------------------------------------------------------- */


/* ------------------------------------------------------------------------- */
int randInInterval (int first, int last)
{
    return qrand() % ((last + 1) - first) + first;
}
/* ========================================================================= */

/*  FUNCTIONS    =========================================================== */
//
//
//
//
/* ------------------------------------------------------------------------- */
/* ========================================================================= */


