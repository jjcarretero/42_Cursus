/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 22:18:04 by jcarrete          #+#    #+#             */
/*   Updated: 2020/11/14 21:46:51 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define NO_EVENT_MASK				0L
# define KEY_PRESS_MASK				1L
# define KEY_RELEASE_MASK			2L
# define BUTTON_PRESS_MASK			4L
# define BUTTON_RELEASE_MASK		8L
# define ENTER_WINDOW_MASK			16L
# define LEAVE_WINDOW_MASK			32L
# define POINTER_MOTION_MASK		64L
# define POINTER_MOTION_HINT_MASK	128L
# define BUTTON1_MOTION_MASK		256L
# define BUTTON2_MOTION_MASK		512L
# define BUTTON3_MOTION_MASK		1024L
# define BUTTON4_MOTION_MASK		2048L
# define BUTTON5_MOTION_MASK		4096L
# define BUTTON_MOTION_MASK			8192L
# define KEYMAP_STATE_MASK			16384L
# define EXPOSURE_MASK				32768L
# define VISIBILITY_CHANGE_MASK		65536L
# define STRUCTURE_NOTIFY_MASK		131072L
# define RESIZE_REDIRECT_MASK		262144L
# define SUBSTRUCTURE_NOTIFY_MASK	524288L
# define SUBSTRUCTURE_REDIRECT_MASK	1048576L
# define FOCUS_CHANGE_MASK			2097152L
# define PROPERTY_CHANGE_MASK		4194304L
# define COLORMAP_CHANGE_MASK		8388608L
# define OWNER_GRAB_BUTTON_MASK		16777216L

# define KEY_PRESS					2
# define KEY_RELEASE				3
# define BUTTON_PRESS				4
# define BUTTON_RELEASE				5
# define MOTION_NOTIFY				6
# define ENTER_NOTIFY				7
# define LEAVE_NOTIFY				8
# define FOCUS_IN					9
# define FOCUS_OUT					10
# define KEYMAP_NOTIFY				11
# define EXPOSE						12
# define GRAPHICS_EXPOSE			13
# define NO_EXPOSE					14
# define VISIBILITY_NOTIFY			15
# define CREATE_NOTIFY				16
# define DESTROY_NOTIFY				17
# define UNMAP_NOTIFY				18
# define MAP_NOTIFY					19
# define MAP_REQUEST				20
# define REPARENT_NOTIFY			21
# define CONFIGURE_NOTIFY			22
# define CONFIGURE_REQUEST			23
# define GRAVITY_NOTIFY				24
# define RESIZE_REQUEST				25
# define CIRCULATE_NOTIFY			26
# define CIRCULATE_REQUEST			27
# define PROPERTY_NOTIFY			28
# define SELECTION_CLEAR			29
# define SELECTION_REQUEST			30
# define SELECTION_NOTIFY			31
# define COLORMAP_NOTIFY			32
# define CLIENT_MESSAGE				33
# define MAPPING_NOTIFY				34
# define GENERIC_EVENT				35
# define LAST_EVENT					36

#endif
