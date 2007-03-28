/***************************************************************************
 *            scsi-read-track-information.h
 *
 *  Fri Oct 27 07:17:16 2006
 *  Copyright  2006  algernon
 *  <algernon@localhost.localdomain>
 ****************************************************************************/

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#include <glib.h>

#include "scsi-base.h"

#ifndef _SCSI_READ_TRACK_INFORMATION_H
#define _SCSI_READ_TRACK_INFORMATION_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
BRASERO_SCSI_DATA_MODE_1			= 0x01,
BRASERO_SCSI_DATA_MODE_2_XA			= 0x02,
BRASERO_SCSI_DATA_BLOCK_TYPE			= 0x0F
} BraseroScsiDataMode;

#if G_BYTE_ORDER == G_LITTLE_ENDIAN

struct _BraseroScsiTrackInfo {
	uchar len			[2];

	uchar track_num_low;
	uchar session_num_low;

	uchar reserved0;

	uchar track_mode		:4;
	uchar copy			:1;
	uchar damage			:1;
	uchar layer_jmp_rcd_status	:2;

	uchar data_mode			:4;
	/* the 4 next bits indicate the track status */
	uchar fixed_packet		:1;
	uchar packet			:1;
	uchar blank			:1;
	uchar reserved_track		:1;

	uchar next_wrt_address_valid	:1;
	uchar last_recorded_blk_valid	:1;
	uchar reserved1			:6;

	uchar start_lba			[4];
	uchar next_wrt_address		[4];
	uchar free_blocks		[4];
	uchar packet_size		[4];
	uchar track_size		[4];
	uchar last_recorded_blk		[4];

	uchar track_num_high;
	uchar session_num_high;

	uchar reserved2			[2];

	uchar rd_compat_lba		[4];
	uchar next_layer_jmp		[4];
	uchar last_layer_jmp		[4];
};

#else

struct _BraseroScsiTrackInfo {
	uchar len			[2];

	uchar track_num_low;
	uchar session_num_low;

	uchar reserved0;

	uchar layer_jmp_rcd_status	:2;
	uchar damage			:1;
	uchar copy			:1;
	uchar track_mode		:4;

	/* the 4 next bits indicate the track status */
	uchar reserved_track		:1;
	uchar blank			:1;
	uchar packet			:1;
	uchar fixed_packet		:1;
	uchar data_mode			:4;

	uchar reserved1			:6;
	uchar last_recorded_blk_valid	:1;
	uchar next_wrt_address_valid	:1;

	uchar start_lba			[4];
	uchar next_wrt_address		[4];
	uchar free_blocks		[4];
	uchar packet_size		[4];
	uchar track_size		[4];
	uchar last_recorded_blk		[4];

	uchar track_num_high;
	uchar session_num_high;

	uchar reserved2			[2];

	uchar rd_compat_lba		[4];
	uchar next_layer_jmp		[4];
	uchar last_layer_jmp		[4];
};

#endif

typedef struct _BraseroScsiTrackInfo BraseroScsiTrackInfo;

#define BRASERO_SCSI_TRACK_NUM(track)		(((track).track_num_high << 8) + (track).track_num_low)
#define BRASERO_SCSI_SESSION_NUM(track)		(((track).session_num_high << 8) + (track).session_num_low)
#define BRASERO_SCSI_TRACK_NUM_PTR(track)	(((track)->track_num_high << 8) + (track)->track_num_low)
#define BRASERO_SCSI_SESSION_NUM_PTR(track)	(((track)->session_num_high << 8) + (track)->session_num_low)

#ifdef __cplusplus
}
#endif

#endif /* _SCSI_READ_TRACK_INFORMATION_H */

 
