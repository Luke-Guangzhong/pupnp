#ifndef UPNPACTIONCOMPLETE_H
#define UPNPACTIONCOMPLETE_H

/*!
 * \file
 *
 * \brief Header file for UpnpActionComplete methods.
 *
 * Do not edit this file, it is automatically generated. Please look at
 * generator.c.
 *
 * \author Marcelo Roberto Jimenez
 */
#include <stdlib.h> /* for size_t */

#include "UpnpGlobal.h" /* for UPNP_EXPORT_SPEC */

#include "UpnpString.h"
#include "ixml.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*!
 * UpnpActionComplete
 */
typedef struct s_UpnpActionComplete UpnpActionComplete;

/*! Constructor */
UPNP_EXPORT_SPEC UpnpActionComplete *UpnpActionComplete_new(void);
/*! Destructor */
UPNP_EXPORT_SPEC void UpnpActionComplete_delete(UpnpActionComplete *p);
/*! Copy Constructor */
UPNP_EXPORT_SPEC UpnpActionComplete *UpnpActionComplete_dup(
	const UpnpActionComplete *p);
/*! Assignment operator */
UPNP_EXPORT_SPEC int UpnpActionComplete_assign(
	UpnpActionComplete *p, const UpnpActionComplete *q);

/*! UpnpActionComplete_get_ErrCode */
UPNP_EXPORT_SPEC int UpnpActionComplete_get_ErrCode(
	const UpnpActionComplete *p);
/*! UpnpActionComplete_set_ErrCode */
UPNP_EXPORT_SPEC int UpnpActionComplete_set_ErrCode(
	UpnpActionComplete *p, int n);

/*! UpnpActionComplete_get_CtrlUrl */
UPNP_EXPORT_SPEC const UpnpString *UpnpActionComplete_get_CtrlUrl(
	const UpnpActionComplete *p);
/*! UpnpActionComplete_set_CtrlUrl */
UPNP_EXPORT_SPEC int UpnpActionComplete_set_CtrlUrl(
	UpnpActionComplete *p, const UpnpString *s);
/*! UpnpActionComplete_get_CtrlUrl_Length */
UPNP_EXPORT_SPEC size_t UpnpActionComplete_get_CtrlUrl_Length(
	const UpnpActionComplete *p);
/*! UpnpActionComplete_get_CtrlUrl_cstr */
UPNP_EXPORT_SPEC const char *UpnpActionComplete_get_CtrlUrl_cstr(
	const UpnpActionComplete *p);
/*! UpnpActionComplete_strcpy_CtrlUrl */
UPNP_EXPORT_SPEC int UpnpActionComplete_strcpy_CtrlUrl(
	UpnpActionComplete *p, const char *s);
/*! UpnpActionComplete_strncpy_CtrlUrl */
UPNP_EXPORT_SPEC int UpnpActionComplete_strncpy_CtrlUrl(
	UpnpActionComplete *p, const char *s, size_t n);
/*! UpnpActionComplete_clear_CtrlUrl */
UPNP_EXPORT_SPEC void UpnpActionComplete_clear_CtrlUrl(UpnpActionComplete *p);

/*! UpnpActionComplete_get_ActionRequest */
UPNP_EXPORT_SPEC IXML_Document *UpnpActionComplete_get_ActionRequest(
	const UpnpActionComplete *p);
/*! UpnpActionComplete_set_ActionRequest */
UPNP_EXPORT_SPEC int UpnpActionComplete_set_ActionRequest(
	UpnpActionComplete *p, IXML_Document *n);

/*! UpnpActionComplete_get_ActionResult */
UPNP_EXPORT_SPEC IXML_Document *UpnpActionComplete_get_ActionResult(
	const UpnpActionComplete *p);
/*! UpnpActionComplete_set_ActionResult */
UPNP_EXPORT_SPEC int UpnpActionComplete_set_ActionResult(
	UpnpActionComplete *p, IXML_Document *n);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* UPNPACTIONCOMPLETE_H */
