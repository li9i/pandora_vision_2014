/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2014, P.A.N.D.O.R.A. Team.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the P.A.N.D.O.R.A. Team nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Miltiadis-Alexios Papadopoulos
 *********************************************************************/

#ifndef PANDORA_VISION_QRCODE_QRCODE_DETECTOR_H 
#define PANDORA_VISION_QRCODE_QRCODE_DETECTOR_H 

#include <iostream>
#include <opencv2/opencv.hpp>
#include <zbar.h>

namespace pandora_vision {

  struct QrCode
  {
    cv::Point qrcode_center;
    std::string qrcode_desc;
  };

  class QrCodeDetector
  {
    private:

      //!< Debug images publisher flag
      bool debug_publish;

      //!< Input frame
      cv::Mat input_frame;

      //!< Grayscale frame, processed for QrCode detection
      cv::Mat gray_frame;

      //!< Frame for debug purposes
      cv::Mat debug_frame;

      //!< QrCode scanner
      zbar::ImageScanner scanner;

      //!< List of detected qrcodes
      std::vector<QrCode> qrcode_list;

      /**
        @brief Creates view for debugging purposes.
        @param image [zbar::Image&] The image
        @return void
       **/
      void debug_show(const zbar::Image&);


    public:

      int gaussiansharpenblur;

      double gaussiansharpenweight;

      QrCodeDetector();

      /**
        @brief Detects qrcodes and stores them in a vector.
        @param frame [cv::Mat] The image in which the QRs are detected
        @return void
       **/
      void detect_qrcode(cv::Mat input_frame);

      void set_debug (bool flag)
      {
        debug_publish = flag;
      };

      cv::Mat get_debug_frame()
      {
        return debug_frame;
      };

      std::vector<QrCode> get_detected_qr()
      {
        return qrcode_list;
      };
  };
}// namespace pandora_vision
#endif  // PANDORA_VISION_QRCODE_QRCODE_DETECTOR_H
