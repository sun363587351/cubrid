/*
 * Copyright (C) 2008 Search Solution Corporation. All rights reserved by Search Solution. 
 *
 *   This program is free software; you can redistribute it and/or modify 
 *   it under the terms of the GNU General Public License as published by 
 *   the Free Software Foundation; version 2 of the License. 
 *
 *  This program is distributed in the hope that it will be useful, 
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 *  GNU General Public License for more details. 
 *
 *  You should have received a copy of the GNU General Public License 
 *  along with this program; if not, write to the Free Software 
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
 *
 */


/*
 * cas_log.h -
 */

#ifndef	_CAS_LOG_H_
#define	_CAS_LOG_H_

#ident "$Id$"

extern void cas_log_init (T_TIMEVAL * start_time);
extern void cas_log_open (char *br_name, int as_index);
extern void cas_log_reset (char *br_name, int as_index);
#ifdef CAS_ERROR_LOG
extern void cas_error_log (int err_code, char *err_msg, int client_ip_addr);
#endif
extern int cas_access_log (T_TIMEVAL * start_time, int as_index,
			   int client_ip_addr);
extern void cas_log_end (T_TIMEVAL * start_time, char *br_name, int as_index,
			 int sql_log_time, char *sql_log2_filename,
			 int sql_log_max_size, int close_flag);
extern void cas_log_write (unsigned int seq_num, char print_new_line,
			   const char *fmt, ...);
extern void cas_log_write2 (const char *fmt, ...);
extern void cas_log_write_query_string (char *query, char print_new_line);

extern char *cas_log_query_plan_file (int id);
extern char *cas_log_query_histo_file (int id);
extern int cas_log_query_info_init (int id);
extern void cas_log_query_info_next (void);
extern void cas_log_query_info_end (void);

extern void cas_log_error_handler_begin (void);
extern void cas_log_error_handler_end (void);
extern void cas_log_error_handler_clear (void);
extern char *cas_log_error_handler_asprint (char *buf, size_t bufsz, bool clear);
#endif /* _CAS_LOG_H_ */
