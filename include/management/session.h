// SPDX-License-Identifier: GPL-2.0-or-later
/*
 *   Copyright (C) 2018 Samsung Electronics Co., Ltd.
 *
 *   linux-cifsd-devel@lists.sourceforge.net
 */

#ifndef __MANAGEMENT_TCONNECTION_H__
#define __MANAGEMENT_TCONNECTION_H__

#include <glib.h>

struct smbd_user;

struct smbd_session {
	unsigned long long	id;

	struct smbd_user	*user;

	GRWLock			update_lock;
	GList			*tree_conns;
	int			ref_counter;
};

struct smbd_tree_conn;

int sm_check_sessions_capacity(unsigned long long id);

int sm_handle_tree_connect(unsigned long long id,
			   struct smbd_user *user,
			   struct smbd_tree_conn *tree_conn);
int sm_handle_tree_disconnect(unsigned long long sess_id,
			      unsigned long long tree_conn_id);

void sm_destroy(void);
int sm_init(void);

#endif /* __MANAGEMENT_TCONNECTION_H__ */
