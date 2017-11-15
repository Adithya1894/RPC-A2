/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "print.h"

bool_t
xdr_a2_echo (XDR *xdrs, a2_echo *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->input, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_a2_sort (XDR *xdrs, a2_sort *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (1 +  100  + 100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->count))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->list, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->sorted_list, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->count);
			{
				register int *genp;

				for (i = 0, genp = objp->list;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			{
				register int *genp;

				for (i = 0, genp = objp->sorted_list;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (1 +  100  + 100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->count))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->list, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->sorted_list, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			objp->count = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->list;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			{
				register int *genp;

				for (i = 0, genp = objp->sorted_list;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->count))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->list, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->sorted_list, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_a2_path (XDR *xdrs, a2_path *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->pwd, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_a2_file_check (XDR *xdrs, a2_file_check *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->files, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_a2_matrix_mul (XDR *xdrs, a2_matrix_mul *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (4 +  100  + 100  + 100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->first, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->second, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->row_first))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->col_first))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->row_second))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->col_second))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->multiplied, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->first;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			{
				register int *genp;

				for (i = 0, genp = objp->second;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			IXDR_PUT_LONG(buf, objp->row_first);
			IXDR_PUT_LONG(buf, objp->col_first);
			IXDR_PUT_LONG(buf, objp->row_second);
			IXDR_PUT_LONG(buf, objp->col_second);
			{
				register int *genp;

				for (i = 0, genp = objp->multiplied;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (4 +  100  + 100  + 100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->first, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->second, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->row_first))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->col_first))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->row_second))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->col_second))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->multiplied, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->first;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			{
				register int *genp;

				for (i = 0, genp = objp->second;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			objp->row_first = IXDR_GET_LONG(buf);
			objp->col_first = IXDR_GET_LONG(buf);
			objp->row_second = IXDR_GET_LONG(buf);
			objp->col_second = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->multiplied;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->first, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->second, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->row_first))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->col_first))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->row_second))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->col_second))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->multiplied, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}
