#ifndef __CURL_CURLBUILD_H
#define __CURL_CURLBUILD_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2013, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

/* ================================================================ */
/*               NOTES FOR CONFIGURE CAPABLE SYSTEMS                */
/* ================================================================ */

/*
 * NOTE 1:
 * -------
 *
 * See file include/curl/curlbuild.h.in, run configure, and forget
 * that this file exists it is only used for non-configure systems.
 * But you can keep reading if you want ;-)
 *
 */

/* ================================================================ */
/*                 NOTES FOR NON-CONFIGURE SYSTEMS                  */
/* ================================================================ */

/*
 * NOTE 1:
 * -------
 *
 * Nothing in this file is intended to be modified or adjusted by the
 * curl library user nor by the curl library builder.
 *
 * If you think that something actually needs to be changed, adjusted
 * or fixed in this file, then, report it on the libcurl development
 * mailing list: http://cool.haxx.se/mailman/listinfo/curl-library/
 *
 * Try to keep one section per platform, compiler and architecture,
 * otherwise, if an existing section is reused for a different one and
 * later on the original is adjusted, probably the piggybacking one can
 * be adversely changed.
 *
 * In order to differentiate between platforms/compilers/architectures
 * use only compiler built in predefined preprocessor symbols.
 *
 * This header file shall only export symbols which are 'curl' or 'CURL'
 * prefixed, otherwise public name space would be polluted.
 *
 * NOTE 2:
 * -------
 *
 * For any given platform/compiler curl_off_t must be typedef'ed to a
 * 64-bit wide signed integral data type. The width of this data type
 * must remain constant and independent of any possible large file
 * support settings.
 *
 * As an exception to the above, curl_off_t shall be typedef'ed to a
 * 32-bit wide signed integral data type if there is no 64-bit type.
 *
 * As a general rule, curl_off_t shall not be mapped to off_t. This
 * rule shall only be violated if off_t is the only 64-bit data type
 * available and the size of off_t is independent of large file support
 * settings. Keep your build on the safe side avoiding an off_t gating.
 * If you have a 64-bit off_t then take for sure that another 64-bit
 * data type exists, dig deeper and you will find it.
 *
 * NOTE 3:
 * -------
 *
 * Right now you might be staring at file include/curl/curlbuild.h.dist or
 * at file include/curl/curlbuild.h, this is due to the following reason:
 * file include/curl/curlbuild.h.dist is renamed to include/curl/curlbuild.h
 * when the libcurl source code distribution archive file is created.
 *
 * File include/curl/curlbuild.h.dist is not included in the distribution
 * archive. File include/curl/curlbuild.h is not present in the git tree.
 *
 * The distributed include/curl/curlbuild.h file is only intended to be used
 * on systems which can not run the also distributed configure script.
 *
 * On systems capable of running the configure script, the configure process
 * will overwrite the distributed include/curl/curlbuild.h file with one that
 * is suitable and specific to the library being configured and built, which
 * is generated from the include/curl/curlbuild.h.in template file.
 *
 * If you check out from git on a non-configure platform, you must run the
 * appropriate buildconf* script to set up curlbuild.h and other local files.
 *
 */

/* ================================================================ */
/*  DEFINITION OF THESE SYMBOLS SHALL NOT TAKE PLACE ANYWHERE ELSE  */
/* ================================================================ */

#ifdef WIN32
    #include "curlbuild_win.h"
#else
    #if __x86_64__ || __ppc64__ || __x86_64 || __amd64__  || __amd64
        #include "curlbuild_linux_x64.h"
    #else
        #include "curlbuild_linux_x86.h"
    #endif
#endif

#endif /* __CURL_CURLBUILD_H */
