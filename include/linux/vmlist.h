/*
  Linked list of VMA structs
  (C) 2018 Swapnil Haria <swapnilh@cs.wisc.edu>
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  linux/include/linux/vmlist.h

*/

#ifndef	_LINUX_VMLIST_H
#define	_LINUX_VMLIST_H

#include <linux/kernel.h>
#include <linux/stddef.h>

struct vmlist_node {
    struct vm_area_struct *vma;
    struct vmlist_node *prev;
    struct vmlist_node *next;
} __attribute__((aligned(sizeof(long))));
    /* The alignment might seem pointless, but allegedly CRIS needs it */

struct vmlist_root {
	struct vmlist_node *vmlist_node;
};

#define VMLIST_ROOT	(struct vmlist_root) { NULL, }
#define VMLIST_EMPTY_ROOT(root)  (READ_ONCE((root)->vmlist_node) == NULL)
extern void vmlist_insert(struct vm_area_struct *, struct vmlist_root *);

#endif	/* _LINUX_VMLIST_H */
