/*!
 * \file
 *
 * \brief Source file for SSDPResultData methods.
 *
 * Do not edit this file, it is automatically generated. Please look at
 * generator.c.
 *
 * \author Marcelo Roberto Jimenez
 */
#include "config.h" // IWYU pragma: keep

#include <stdlib.h> /* for calloc(), free() */		   // IWYU pragma: keep
#include <string.h> /* for strlen(), strdup(), memset() */ // IWYU pragma: keep

#include "SSDPResultData.h"

struct s_SSDPResultData
{
	UpnpDiscovery *m_Param;
	void *m_Cookie;
	Upnp_FunPtr m_CtrlptCallback;
};

SSDPResultData *SSDPResultData_new(void)
{
	struct s_SSDPResultData *p = calloc(1, sizeof(struct s_SSDPResultData));

	if (!p)
		return 0;

	p->m_Param = UpnpDiscovery_new();
	/*p->m_Cookie = 0;*/
	/*p->m_CtrlptCallback = 0;*/

	return (SSDPResultData *)p;
}

void SSDPResultData_delete(SSDPResultData *q)
{
	struct s_SSDPResultData *p = (struct s_SSDPResultData *)q;

	if (!p)
		return;

	p->m_CtrlptCallback = 0;
	p->m_Cookie = 0;
	UpnpDiscovery_delete(p->m_Param);
	p->m_Param = 0;

	free(p);
}

int SSDPResultData_assign(SSDPResultData *p, const SSDPResultData *q)
{
	int ok = 1;

	if (p != q) {
		ok = ok &&
		     SSDPResultData_set_Param(p, SSDPResultData_get_Param(q));
		ok = ok &&
		     SSDPResultData_set_Cookie(p, SSDPResultData_get_Cookie(q));
		ok = ok && SSDPResultData_set_CtrlptCallback(
				   p, SSDPResultData_get_CtrlptCallback(q));
	}

	return ok;
}

SSDPResultData *SSDPResultData_dup(const SSDPResultData *q)
{
	SSDPResultData *p = SSDPResultData_new();

	if (!p)
		return 0;

	SSDPResultData_assign(p, q);

	return p;
}

const UpnpDiscovery *SSDPResultData_get_Param(const SSDPResultData *p)
{
	return p->m_Param;
}

int SSDPResultData_set_Param(SSDPResultData *p, const UpnpDiscovery *s)
{
	UpnpDiscovery *q = UpnpDiscovery_dup(s);
	if (!q)
		return 0;
	UpnpDiscovery_delete(p->m_Param);
	p->m_Param = q;

	return 1;
}

void *SSDPResultData_get_Cookie(const SSDPResultData *p) { return p->m_Cookie; }

int SSDPResultData_set_Cookie(SSDPResultData *p, void *n)
{
	p->m_Cookie = n;

	return 1;
}

Upnp_FunPtr SSDPResultData_get_CtrlptCallback(const SSDPResultData *p)
{
	return p->m_CtrlptCallback;
}

int SSDPResultData_set_CtrlptCallback(SSDPResultData *p, Upnp_FunPtr n)
{
	p->m_CtrlptCallback = n;

	return 1;
}
