/* Copyright (C)
* 2015 - John Melton, G0ORX/N6LYT
* 2024,2025 - Heiko Amft, DL1BZ (Project deskHPSDR)
*
*   This source code has been forked and was adapted from piHPSDR by DL1YCF to deskHPSDR in October 2024
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
*/

#ifndef _SLIDERS_H
#define _SLIDERS_H

// include these since we are using RECEIVER and TRANSMITTER
#include "receiver.h"
#include "transmitter.h"
#include "actions.h"

extern void att_type_changed(void);
extern void update_c25_att(void);

extern int sliders_active_receiver_changed(void *data);
extern void update_slider_local_mic_input(int src);
extern void update_slider_local_mic_button(void);
extern void update_slider_tune_drive_scale(gboolean show_widget);
extern void update_slider_autogain_btn(void);
extern void update_slider_bbcompr_scale(gboolean show_widget);
extern void update_slider_bbcompr_button(gboolean show_widget);
extern void update_slider_lev_button(gboolean show_widget);
extern void update_slider_lev_scale(gboolean show_widget);
extern void update_slider_preamp_button(gboolean show_widget);
extern void update_slider_preamp_scale(gboolean show_widget);
extern void sliders_hide_row(int row);
extern void sliders_show_row(int row);

extern void set_agc_gain(int rx, double value);
extern void set_af_gain(int rx, double value);
extern void set_rf_gain(int rx, double value);
extern void set_mic_gain(double value);
extern void set_linein_gain(double value);
extern void set_drive(double drive);
extern void show_filter_low(int rx, int value);
extern void show_filter_high(int rx, int value);
extern void show_filter_width(int rx, int value);
extern void show_filter_shift(int rx, int value);
extern void set_attenuation_value(double attenuation);
extern GtkWidget *sliders_init(int my_width, int my_height);

extern void set_squelch(RECEIVER *rx);

extern void show_diversity_gain(void);
extern void show_diversity_phase(void);

void show_popup_slider(enum ACTION action, int rx, double min, double max, double delta, double value,
                       const char *title);

#endif
