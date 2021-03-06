/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "print.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
morampudi_a2_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		a2_echo echo_1_arg;
		a2_sort sort_1_arg;
		a2_file_check file_check_1_arg;
		a2_matrix_mul matrix_mul_1_arg;
	} argument;
	union {
		a2_echo echo_1_res;
		a2_sort sort_1_res;
		a2_path path_1_res;
		a2_file_check file_check_1_res;
		a2_matrix_mul matrix_mul_1_res;
	} result;
	bool_t retval;
	xdrproc_t _xdr_argument, _xdr_result;
	bool_t (*local)(char *, void *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case Echo:
		_xdr_argument = (xdrproc_t) xdr_a2_echo;
		_xdr_result = (xdrproc_t) xdr_a2_echo;
		local = (bool_t (*) (char *, void *,  struct svc_req *))echo_1_svc;
		break;

	case Sort:
		_xdr_argument = (xdrproc_t) xdr_a2_sort;
		_xdr_result = (xdrproc_t) xdr_a2_sort;
		local = (bool_t (*) (char *, void *,  struct svc_req *))sort_1_svc;
		break;

	case Path:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_a2_path;
		local = (bool_t (*) (char *, void *,  struct svc_req *))path_1_svc;
		break;

	case File_Check:
		_xdr_argument = (xdrproc_t) xdr_a2_file_check;
		_xdr_result = (xdrproc_t) xdr_a2_file_check;
		local = (bool_t (*) (char *, void *,  struct svc_req *))file_check_1_svc;
		break;

	case Matrix_mul:
		_xdr_argument = (xdrproc_t) xdr_a2_matrix_mul;
		_xdr_result = (xdrproc_t) xdr_a2_matrix_mul;
		local = (bool_t (*) (char *, void *,  struct svc_req *))matrix_mul_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	retval = (bool_t) (*local)((char *)&argument, (void *)&result, rqstp);
	if (retval > 0 && !svc_sendreply(transp, (xdrproc_t) _xdr_result, (char *)&result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	if (!morampudi_a2_1_freeresult (transp, _xdr_result, (caddr_t) &result))
		fprintf (stderr, "%s", "unable to free results");

	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (Morampudi_a2, a2Vers);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, Morampudi_a2, a2Vers, morampudi_a2_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (Morampudi_a2, a2Vers, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, Morampudi_a2, a2Vers, morampudi_a2_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (Morampudi_a2, a2Vers, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
