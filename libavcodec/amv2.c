/*
 * Copyright (c) 2019 Tom Needham
 *
 * This file is part of FFmpeg.
 * 
 * AMV2 Decoder
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "libavutil/intreadwrite.h"

#include "avcodec.h"
#include "internal.h"

typedef struct AMV2Context {
    AVFrame* frame;
} AMV2Context;

static av_cold int amv2_init(AVCodecContext *avctx) {
    AMV2Context *ctx = avctx->priv_data;

    av_log(avctx, AV_LOG_DEBUG, "In amv2_init \n");
    return 0;
}

static int amv2_decode_frame(AVCodecContext *avctx,
                        void *data, int *got_frame,
                        AVPacket *avpkt) {
    AMV2Context *ctx = avctx->priv_data;

    av_log(avctx, AV_LOG_DEBUG, "In amv2_decode_frame \n");
    return 0;
}

static av_cold int amv2_close(AVCodecContext *avctx) {
    AMV2Context *s = avctx->priv_data;

    av_log(avctx, AV_LOG_DEBUG, "In amv2_close \n");
    av_frame_free(&s->frame);
    return 0;
}

static void amv2_flush(AVCodecContext *avctx) {
    AMV2Context *ctx = avctx->priv_data;

    av_log(avctx, AV_LOG_DEBUG, "In amv2_flush \n");
}

AVCodec ff_amv2_decoder = {
    .name           = "amv2",
    .long_name      = NULL_IF_CONFIG_SMALL("AmaRecTV AMV2"),
    .type           = AVMEDIA_TYPE_VIDEO,
    .id             = AV_CODEC_ID_AMV2,
    .init           = amv2_init,
    .decode         = amv2_decode_frame,
    .close          = amv2_close,
    .flush          = amv2_flush,
    .priv_data_size = sizeof(AMV2Context),
    .caps_internal  = FF_CODEC_CAP_INIT_THREADSAFE |
                      FF_CODEC_CAP_INIT_CLEANUP,
};